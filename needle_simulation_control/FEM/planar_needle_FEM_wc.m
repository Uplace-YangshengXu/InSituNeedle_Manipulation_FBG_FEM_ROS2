function [x_new, y_new, k_new, Constraints_new] = planar_needle_FEM_wc(L, Mu, Alpha, Interval, ...
    x_pre, y_pre, k_pre, Constraints_pre, ...
    dbx, dby, dbk, ...
    curvatures, AA_lcn)

% Flexible needle and soft tissue interaction simulation. Needle bending is
% based on Euler-Bernoulli beam theory. Tissue compression is modeled as
% unconfined uniaxial compression with Ogden1 incompressible hyperelastic
% material model. Needle insertion is based on nodal slope information.
% This version resolves needle bending in the constraint space, and
% includes dynamic constraint addition and deletion.

% Inputs:
% L: total length of the needle
% Mu: cell array of material parameters Mu
% Alpha: cell array of material parameters Alpha
% Interval: cell array of material layers
% x_pre, y_pre, k_pre: arrays of initial/previous nodal x, y, and k
% Constraints_pre: constraint points [x, y, k]; can be empty
% dbx, dby, dbk: changes in needle base position and slope
% curvatures: FBG meassured curvatrues in one plane (XY)
% AA_lcn: AA position with respect to needle tip

% Outputs:
% x_new, y_new, k_new: arrays of solution nodal x, y, and k
% Constraints_new: new set of constraint points

% Yanzhou Wang
% Apr 30 2023

%% Initialization
% Constants
FEM_params;

MuT = Mu*10^-6; % Pa, but in mm^2; 1Pa = 1e-6 N/mm^2; 1kPa = 1e-3 N/mm^2
AlphaT = Alpha; % need abs(alpha) > 1
GammaT = zeros(size(MuT));
PropertyTable = table(Interval, MuT, AlphaT, GammaT);

% Place first constraint
if isempty(Constraints_pre) && x_pre(end) >= Interval{1}(1)
    Constraints_pre = [x_pre(end); y_pre(end); k_pre(end)];
end

[S2C, C2S] = produce_constraint_tf_2d(Constraints_pre);
needle_C = apply_transformations_2d([x_pre'; y_pre'; k_pre'], S2C);
x_pre = needle_C(1, :)'; y_pre = needle_C(2, :)'; k_pre = needle_C(3, :)';
Constraints = apply_transformations_2d(Constraints_pre, S2C); % NOTE: first column should always be zeros

[MuTs, AlphaTs, GammaTs] = lookup_properties(x_pre, PropertyTable);
% Lambdas = lookup_compressions(x_pre, y_pre, ti, Interval, Constraints, constraint_interval);
Constraints_list = lookup_constraints(x_pre, y_pre, k_pre, Interval, Constraints);

% FEM-specific constants
Nel = L; % Total umber of elements, using 1mm elements
Nen = 4; % Number of element DOF
DOF = 1:(2*Nel + 2);
nDOF = length(DOF);
h = L/Nel; % Finite element size
EBC_idx = [1; 2]; % Displacement and slope of first element left node is prescribed
freeDOF = DOF;
freeDOF(EBC_idx) = [];

d = assem_dof_2d(y_pre, k_pre); % initial guess of the solution, based on previous simulation step

% Construction of LM
LM = zeros(Nen, Nel);
for e = 1:Nel
    LM(:, e) = (2*e - 1) : (2*e + 2);
end

% curvature inputs from FBG
AA_crv = 1e-3 * curvatures'; % curvature at AAs in mm-1
AA_er = [];
if ~isempty(AA_crv) % if curvatrue is empty then AA_er is []
    AA_er = round(AA_lcn./h) + 1; % elements where the left-moment is fixed
    AA_crv = AA_crv(AA_er >= 0); % curvature that have negative element indices are skipped
    AA_er = AA_er(AA_er>=0); % elements that have negativce indices are skiped
end

% Load-stepping functionality
outer_iter = 1;
converged = 0;
load_ratio = 1;
EBC_delta_des = [dby; dbk]; % desired amount of BC change
EBC_delta_cur = zeros(2, 1); % current amount of BC change
EBC_delta_converged = zeros(2, 1); % previously-converged BC change

%% FEM Main with load stepping
while converged == 0 && (outer_iter <= max_outer_iter)
    outer_iter = outer_iter + 1;
    inner_iter = 1;
    converged = 0;
    EBC_delta_cur = EBC_delta_converged + load_ratio*EBC_delta_des;
    while inner_iter <= max_inner_iter
        % main FEM
        K = zeros(nDOF, nDOF);
        F = zeros(nDOF, 1);
        P = zeros(nDOF, 1);
        % Apply EBC
        d(EBC_idx) = EBC_delta_cur + [y_pre(1); k_pre(1)]; % EBCs include the change in base y and slope; if no change, the output is the same as the previous simulation step
        % Loop over each element
        for e = 1:Nel
            d_i_local = d(2*e - 1:2*e + 2); % Get local nodal values from global d
            Constraint_i_y = Constraints_list(2, e); % Get current constraint y
            d_i_local = d_i_local - ...
                Constraint_i_y*[1; 0; 1; 0]; % Change relative to nodal constraint

            [ke, pe] = compute_element_matrix(d_i_local, ti, E, I, e, h, ...
                MuTs(e), AlphaTs(e), GammaTs(e), Constraint_i_y, AA_er, AA_crv);

            % Global assembly process
            % Using vectors instead of FOR loops
            K(LM(1:4, e), LM(1:4, e)) = K(LM(1:4, e), LM(1:4, e)) + ke;
            P(LM(1:4, e)) = P(LM(1:4, e)) + pe;
        end

        % Newton's method
        % Use only free DOF from the list of DOF to compute d
        delta_d = invChol_mex(K(freeDOF, freeDOF))*(F(freeDOF, 1)-P(freeDOF, 1));
        % delta_d = pinv(K(freeDOF, freeDOF))*(F(freeDOF, 1)-P(freeDOF, 1));
        err = norm(F(freeDOF, 1) - P(freeDOF, 1));
        if(err <= tol)
            converged = 1;
            break;
        end
        d(freeDOF, 1) = d(freeDOF, 1) + delta_d;
        inner_iter = inner_iter + 1;
    end % end inner iteration
    if converged ~= 1
        load_ratio = 0.5*load_ratio;
        EBC_delta_cur = zeros(2, 1);
        %         fprintf("No convergence. Decreasing load step\n");
    else
        EBC_delta_converged = EBC_delta_cur;
    end
end % end outer iteration

if converged ~= 1
    warning("Exited FEM without convergence")
end

%% Outputs
[dy_bend, k_new_C] = extract_from_2d(d); % y coordinate and slope due to bending
dx_bend = zeros(size(dy_bend));
dx_bend(1) = x_pre(1) + dbx;
ddy_bend = diff(dy_bend);

dx_insert = zeros(size(dx_bend));
dy_insert = zeros(size(dy_bend));

for i = 2:(Nel + 1)
    dx_bend(i) = dx_bend(i - 1) + sqrt(h^2 - ddy_bend(i - 1)^2);
end

x_new_C = dx_bend + dx_insert;
y_new_C = dy_bend + dy_insert;
Constraints_new_C = update_constraints(x_new_C, y_new_C, k_new_C, ...
    Interval, Constraints, constraint_interval, bevel);

% Convert back to {S}
needle_S = apply_transformations_2d([x_new_C'; y_new_C'; k_new_C'], C2S);
x_new = needle_S(1, :)'; y_new = needle_S(2, :)'; k_new = needle_S(3, :)';

if ~isempty(Constraints_new_C)
    Constraints_new = apply_transformations_2d(Constraints_new_C, C2S);
else
    Constraints_new = [];
end

%% Constant element size check
x_diff = diff(x_new); y_diff = diff(y_new);
h_pre = sqrt(x_diff.^2 + y_diff.^2);
if ~all(abs(h_pre - h) < 1e-2)
    warning('Element size wrong\n')
end

end

%% Defined helper functions
% Compute element stiffness matrix and internal force vector
function [ke, pe] = compute_element_matrix(d_i_local, ti, E, I, ...
    e, h, MuT_e, AlphaT_e, GammaT_e, C_e_y, AA_er,AA_crv)
% Calculate integrals
% _beam will stay the same
pe_beam = calc_pe_beam(d_i_local, h, E, I);
ke_beam = calc_ke_beam(h, E, I);
% _cont will depend on external force formulation
pe_cont = calc_pe_cont(d_i_local, h, ti, MuT_e, AlphaT_e, GammaT_e, C_e_y);
ke_cont = calc_ke_cont(d_i_local, h, ti, MuT_e, AlphaT_e, GammaT_e, C_e_y);

pe = pe_beam + pe_cont;
% repalce the curvature with fbg measured value
FBG_idx_r = find(e == AA_er);
if FBG_idx_r % if input curvature is [] then FBG_idx_r is also []
    pe(2) = AA_crv(FBG_idx_r)*E*I;
end
ke = ke_beam + ke_cont;
end

% Update constraint points list
function Constraints = update_constraints(x, y, k, ...
    Interval, Constraints, constraint_interval, bevel)
tip_x = x(end);
if (tip_x > Interval{1}(1) && tip_x < Interval{end}(end) && isempty(Constraints)) || ...
        (tip_x > Interval{1}(1) && tip_x < Interval{end}(end) && tip_x > Constraints(1, end) + constraint_interval)
    if isempty(Constraints) % create the first constraint
        next_constraint = ...
            [tip_x; y(end) + bevel; k(end)]; 
    else % create a new constraint
        next_constraint = ...
            [tip_x; 0.2*y(end) + 0.8*Constraints(2, end) + bevel; k(end)]; % this is to avoid the sudden release of needle tip force
    end
    Constraints = [Constraints, next_constraint]; 
elseif tip_x > Interval{1}(1) && tip_x < Constraints(1, end)
    Constraints(:, end) = []; % remove end constraint

elseif tip_x < Interval{1}(1)
    Constraints = []; % remove all constraints
end
end


%% Integration subroutines
function pe_beam = calc_pe_beam(d_i_local, h, E, I)
% Element internal force vector of the beam
pe_beam = calc_ke_beam(h, E, I)*d_i_local;
end

function ke_beam = calc_ke_beam(h, E, I)
% Element stiffness from beam bending
ke_beam = E*I/h^3*[12,   6*h,    -12,    6*h;
    6*h,  4*h^2,  -6*h,   2*h^2;
    -12,  -6*h,   12,     -6*h;
    6*h,  2*h^2,  -6*h,   4*h^2];
end

function pe_cont = calc_pe_cont(d_i_local, h, ti, MuT_e, AlphaT_e, GammaT_e, C_e_y)
% Element internal force vector from tissue contact
ig = [-1/sqrt(3); 1/sqrt(3)]; % Gauss integration points
wg = [1; 1]; % Gauss weights
N = [shape(ig(1), h); shape(ig(2), h)]; % Shape function at each gauss point
N_zeta = [dshape(ig(1), h); dshape(ig(2), h)]; % Shape function derivative at each gauss point
u = [N(1, :)*d_i_local; N(2, :)*d_i_local]; % Displacements at each gauss points
u_zeta = [N_zeta(1, :)*d_i_local; N_zeta(2, :)*d_i_local];% Displacements derivative at each gauss points

% Sum over all gauss points
pe_cont = zeros(1, 4);
for i = 1:length(ig)
    stretch = (ti - abs(C_e_y))/ti;
    if stretch < 0 % happens when control makes abs(u) larger than ti
        stretch = 0.1; % manually assign a large compression ratio
    end
    pe_cont = pe_cont + ...
        wg(i)*(...
        N(i, :)*2*MuT_e*((stretch)^(AlphaT_e - 1) + 1/2*(stretch)^(-AlphaT_e/2 - 1))*...
        u(i)*(1 - GammaT_e*sin(atan(u_zeta(i)*(2/h)))^2)*(h/2)...
        );
end
pe_cont = pe_cont'; % transpose to get the right dimension
end

function ke_cont = calc_ke_cont(d_i_local, h, ti, MuT_e, AlphaT_e, GammaT_e, C_e_y)
% Element stiffness from tissue contact
ig = [-1/sqrt(3); 1/sqrt(3)]; % Gauss integration points
wg = [1; 1]; % Gauss weights
N = [shape(ig(1), h); shape(ig(2), h)]; % Shape function at each gauss point
N_zeta = [dshape(ig(1), h); dshape(ig(2), h)]; % Shape function derivative at each gauss point
u = [N(1, :)*d_i_local; N(2, :)*d_i_local]; % Displacements at each gauss points
u_zeta = [N_zeta(1, :)*d_i_local; N_zeta(2, :)*d_i_local];% Displacements derivative at each gauss points

% Sum over all gauss points
ke_cont = zeros(4, 4);
for i = 1:length(ig)
    stretch = (ti - abs(C_e_y))/ti;
    if stretch < 0 % happens when control makes abs(u) larger than ti
        stretch = 0.1; % manually assign a large compression ratio
    end
    ke_cont = ke_cont + ...
        wg(i)*(...
        N(i, :)'*2*MuT_e*((AlphaT_e - 1)*(stretch)^(AlphaT_e - 2)*(-1/ti*sign(u(i))*N(i, :)) + ...
        1/2*(-AlphaT_e/2 - 1)*(stretch)^(-AlphaT_e/2 - 2)*(-1/ti*sign(u(i))*N(i, :)))*u(i)* ...
        (1 - GammaT_e*sin(atan(u_zeta(i)*(2/h)))^2)*(h/2) + ...
        ...
        N(i, :)'*2*MuT_e*((stretch)^(AlphaT_e - 1) + 1/2*(stretch)^(-AlphaT_e/2 - 1))*N(i, :)*...
        (1 - GammaT_e*sin(atan(u_zeta(i)*(2/h)))^2)*(h/2) + ...
        ...
        N(i, :)'*2*MuT_e*((stretch)^(AlphaT_e - 1) + 1/2*(stretch)^(-AlphaT_e/2 - 1))*u(i)*...
        -GammaT_e*((2*u_zeta(i)*(2/h))/((u_zeta(i)*(2/h))^2 + 1)^2*N(i, :)*(2/h) - (2*(u_zeta(i)*(2/h))^3)/((u_zeta(i)*(2/h))^2 + 1)^2*N(i, :)*(2/h))*(h/2)...
        );
end
end

%% Shape functions
function N = shape(zeta, h)
% Shape functions N(zeta)
N = [(zeta -1)^2*(zeta + 2)/4, ...
    h*(zeta - 1)^2*(zeta + 1)/8, ...
    (zeta + 1)^2*(zeta + 2)/4, ...
    h*(zeta - 1)*(zeta + 1)^2/8];
end

function N_zeta = dshape(zeta, h)
% Shape functions N_zeta(zeta)
N_zeta = [3*(zeta - 1)*(zeta + 1)/4, ...
    h*(zeta - 1)*(3*zeta + 1)/8, ...
    3*(zeta + 1)*(1 - zeta)/4, ...
    h*(zeta + 1)*(3*zeta - 1)/8];
end

function N_zeta_zeta = ddshape(zeta, h)
% Shape functions N_zeta_zeta(zeta)
N_zeta_zeta = [3*zeta/2, ...
    (3*zeta - 1)*h/4, ...
    -3/2*zeta, ...
    (3*zeta + 1)*h/4];
end