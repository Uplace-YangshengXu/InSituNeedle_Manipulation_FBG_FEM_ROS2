function [x_new, y_new, k_new] = planar_needle_FEM(L, Mu, Alpha, Interval, ...
    x_pre, y_pre, k_pre, ...
    dbx, dby, dbk, ...
    curvatures, AA_lcn)

% Flexible needle and soft tissue interaction simulation. Needle bending is
% based on beam bending with Ogden1 hyperelastic material model with
% unconstrainted incomparessibility condition. Needle insertion is based on
% nodel slope information.
% Based mainly on ogden_unconstrained_true_one_step.m

% Inputs: 
% L: total length of the needle
% Mu: cell array of material parameters Mu
% Alpha: cell array of material parameters Alpha
% Interval: cell array of material layers
% x_pre, y_pre, k_pre: arrays of initial/previous nodal x, y, and k
% dbx, dby, dbk: changes in needle base position and slope
% curvatures: FBG meassured curvatrues in one plane (XY)
% AA_lcn: AA position with respect to needle tip

% Outputs:
% x_new, y_new, k_new: arrays of solution nodal x, y, and k

% Yanzhou Wang
% Nov 27 2022

%% Initialization - this part can be moved to test file
% Constants
FEM_params;

MuT = Mu*10^-6; % Pa, but in mm^2; 1Pa = 1e-6 N/mm^2; 1kPa = 1e-3 N/mm^2
AlphaT = Alpha; % need abs(alpha) > 1
GammaT = zeros(size(MuT));
PropertyTable = table(Interval, MuT, AlphaT, GammaT);

% FEM-specific constants
Nel = L; % Total umber of elements, using 1mm elements
Nen = 4; % Number of element DOF
DOF = 1:(2*Nel + 2);
nDOF = length(DOF);
h = L/Nel; % Finite element size
EBC_idx = [1; 2]; % Displacement and slope of first element left node is prescribed
freeDOF = DOF;
freeDOF(EBC_idx) = [];

d = assem_d_k(y_pre, k_pre); % initial guess of the solution, based on previous simulation step

% Construction of LM
LM = zeros(Nen, Nel);
for e = 1:Nel
    LM(1, e) = 2*e - 1;
    LM(2, e) = 2*e - 0;
    LM(3, e) = 2*e + 1;
    LM(4, e) = 2*e + 2;
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
max_inner_iter = 5; % maximum number of iterations for Newton's method
max_outer_iter = 5; % maximum number of iteratinos for load stepping
outer_iter = 0;
tol = 1e-5;
converged = 0;
load_ratio = 1;
EBC_delta_des = [dby; dbk]; % desired amount of BC change
EBC_delta_cur = zeros(2, 1); % current amount of BC change
EBC_delta_converged = zeros(2, 1); % previously-converged BC change

%% FEM Main with load stepping
while converged == 0 && (outer_iter < max_outer_iter)
    outer_iter = outer_iter + 1;
    inner_iter = 0;
    converged = 0;
    EBC_delta_cur = EBC_delta_converged + load_ratio*EBC_delta_des;
    while inner_iter < max_inner_iter
        % main FEM
        K = zeros(nDOF, nDOF);
        F = zeros(nDOF, 1);
        P = zeros(nDOF, 1);
        % Apply EBC
        d(EBC_idx) = [EBC_delta_cur(1) + y_pre(1); 
                      EBC_delta_cur(2) + k_pre(1)]; % EBCs include the change in base y and slope; if no change, the output is the same as the previous simulation step

        % Loop over each element    
        for e = 1:Nel
            % Get local nodal values from global d
            d_i_local = d(2*e - 1:2*e + 2);
            [ke, pe] = compute_element_matrix(d_i_local, ti, E, I, PropertyTable, e, h, x_pre(e), x_pre(e + 1), AA_er, AA_crv);
            % Global assembly process
            % Using vectors instead of FOR loops
            K(LM(1:4, e), LM(1:4, e)) = K(LM(1:4, e), LM(1:4, e)) + ke;
            P(LM(1:4, e)) = P(LM(1:4, e)) + pe;
        end

        % Newton's method
        % Use only free DOF from the list of DOF to compute d
        % delta_d = invChol_mex(K(freeDOF, freeDOF))*(F(freeDOF, 1)-P(freeDOF, 1));
        delta_d = pinv(K(freeDOF, freeDOF))*(F(freeDOF, 1)-P(freeDOF, 1));
        if(norm(F(freeDOF, 1) - P(freeDOF, 1)) <= tol)
            converged = 1;
            break;
        end
        d(freeDOF, 1) = d(freeDOF, 1) + delta_d;
        inner_iter = inner_iter + 1;
    end
    if converged ~= 1
        load_ratio = 0.5*load_ratio;
        EBC_delta_cur = zeros(2, 1);
        disp("No convergence. Decreasing load step\n");
    else
        EBC_delta_converged = EBC_delta_cur;
    end
end

%% Outputs
dy_bend = extract_dist_from_d(d); % y coordinate due to bending
dy_insert = zeros(size(dy_bend)); 

dx_bend = zeros(size(dy_bend));
dx_bend(1) = x_pre(1) + dbx; % offset needle base x by the amount of change
dx_insert = zeros(size(dy_bend));

k_new = extract_slop_from_d(d); % slopes

ddy_bending = diff(dy_bend);
for i = 2:(Nel + 1)
    dx_bend(i) = dx_bend(i - 1) + sqrt(h^2 - ddy_bending(i - 1)^2); % x coordinate due to bending
    dx_insert(i) = sqrt(dbx^2/(1 + k_new(i)^2)); % x coordinate change due to insertion
    dy_insert(i) = k_new(i)*dx_insert(i); % y coordinate change due to insertion
end

x_new = dx_bend; 
y_new = dy_bend + dy_insert;
end

%% Defined helper functions
% Look up material properties at given location
function [MuT_e, AlphaT_e, GammaT_e] = lookup_property(PropertyTable, x_begin, x_end)
x_mid = (x_begin + x_end)/2; % Find the midpoint location of the element in global coordinate
for i = 1:numel(PropertyTable.Interval)
    cur_interval = PropertyTable.Interval{i};
    if (x_mid >= cur_interval(1)) && (x_mid < cur_interval(2))
        MuT_e = PropertyTable.MuT(i);
        AlphaT_e = PropertyTable.AlphaT(i);
        GammaT_e = PropertyTable.GammaT(i);
        return;
    else
        MuT_e = 0;
        AlphaT_e = -1;
        GammaT_e = 0;
    end
end
end

% Compute element stiffness matrix and internal force vector
function [ke, pe] = compute_element_matrix(d_i_local, ti, E, I, PropertyTable,e, h, x_begin, x_end, AA_er,AA_crv)
% Find properties
[MuT_e, AlphaT_e, GammaT_e] = lookup_property(PropertyTable, x_begin, x_end);
% Calculate integrals
% _beam will stay the same
pe_beam = calc_pe_beam(d_i_local, h, E, I);
ke_beam = calc_ke_beam(h, E, I);
% _cont will depend on external force formulation
pe_cont = calc_pe_cont(d_i_local, h, ti, MuT_e, AlphaT_e, GammaT_e);
ke_cont = calc_ke_cont(d_i_local, h, ti, MuT_e, AlphaT_e, GammaT_e);

pe = pe_beam + pe_cont;
% repalce the curvature with fbg measured value
FBG_idx_r = find(e == AA_er);
if FBG_idx_r % if input curvature is [] then FBG_idx_r is also []
    pe(2) = AA_crv(FBG_idx_r)*E*I;
end
ke = ke_beam + ke_cont;
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


function pe_cont = calc_pe_cont(d_i_local, h, ti, MuT_e, AlphaT_e, GammaT_e)
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
    pe_cont = pe_cont + ...
        wg(i)*(...
        N(i, :)*2*MuT_e*(((ti - abs(u(i)))/ti)^(AlphaT_e - 1) + 1/2*((ti - abs(u(i)))/ti)^(-AlphaT_e/2 - 1))*...
        u(i)*(1 - GammaT_e*sin(atan(u_zeta(i)*(2/h)))^2)*(h/2)...
        );
end
pe_cont = pe_cont'; % transpose to get the right dimension
end

function ke_cont = calc_ke_cont(d_i_local, h, ti, MuT_e, AlphaT_e, GammaT_e)
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
    ke_cont = ke_cont + ...
        wg(i)*(...
        N(i, :)'*2*MuT_e*((AlphaT_e - 1)*((ti - abs(u(i)))/ti)^(AlphaT_e - 2)*(-1/ti*sign(u(i))*N(i, :)) + ...
        1/2*(-AlphaT_e/2 - 1)*((ti - abs(u(i)))/ti)^(-AlphaT_e/2 - 2)*(-1/ti*sign(u(i))*N(i, :)))*u(i)* ...
        (1 - GammaT_e*sin(atan(u_zeta(i)*(2/h)))^2)*(h/2) + ...
        ...
        N(i, :)'*2*MuT_e*(((ti - abs(u(i)))/ti)^(AlphaT_e - 1) + 1/2*((ti - abs(u(i)))/ti)^(-AlphaT_e/2 - 1))*N(i, :)*...
        (1 - GammaT_e*sin(atan(u_zeta(i)*(2/h)))^2)*(h/2) + ...
        ...
        N(i, :)'*2*MuT_e*(((ti - abs(u(i)))/ti)^(AlphaT_e - 1) + 1/2*((ti - abs(u(i)))/ti)^(-AlphaT_e/2 - 1))*u(i)*...
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