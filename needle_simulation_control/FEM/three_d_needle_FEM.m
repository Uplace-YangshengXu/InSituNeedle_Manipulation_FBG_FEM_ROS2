function [x_new, y_new, z_new, ty_new, tz_new] = three_d_needle_FEM(L, Mu, Alpha, Interval, ...
          x_pre, y_pre, z_pre, ty_pre, tz_pre, ...
          dbx, dby, dbz, dty, dtz, ...
          curvatures_xy, curvatures_xz, AA_lcn)

% Flexible needle and soft tissue interaction simulation. Needle bending is
% based on Euler-Bernoulli beam theory. Tissue compression is modeled as
% unconfined uniaxial compression with Ogden1 incompressible hyperelastic
% material model. Needle insertion is based on nodal slope information.

% Inputs:
% TODO: curvatures, AA_lcn

%% Initialization
% Constants
FEM_params;
MuT = Mu*10^-6; % Pa, but in mm^2; 1Pa = 1e-6 N/mm^2; 1kPa = 1e-3 N/mm^2
AlphaT = Alpha; % need abs(alpha) > 1
GammaT = zeros(size(MuT));
PropertyTable = table(Interval, MuT, AlphaT, GammaT);
[MuTs, AlphaTs, GammaTs] = lookup_properties(x_pre, PropertyTable);

% FEM-specific constants
Nel = L; % total number of elements
Nodal_DOF = 4;
Nen = 2*Nodal_DOF; % number of element DOF
DOF = 1:((L+1)*Nodal_DOF);
nDOF = length(DOF);
h = L/Nel; % mesh size
EBC_idx = 1:4; % essential boundary conditions
freeDOF = DOF;
freeDOF(EBC_idx) = [];

% using DOF sequence: [wy1; wz1; ty1; tz1; wy2; wz2; ty2; tz2; ...]
d = assem_dof_3d(y_pre, z_pre, ty_pre, tz_pre); % initial guess of solution, based on previous simulation step

% Construction of LM
LM = zeros(Nen, Nel);
for e = 1:Nel
    LM(:, e) = (4*e - 3):(4*e + 4);
end

% Curvature inputs from FBG
AA_crv_xy = 1e-3*curvatures_xy';
AA_crv_xz = 1e-3*curvatures_xz';
AA_er = [];
if ~isempty(AA_lcn) % if curvature is empty then AA_er is []
    AA_er = round(AA_lcn./h) + 1; % elements where the left-moment is fixed
    AA_crv_xy = AA_crv_xy(AA_er >= 0); % curvatures that have negative element indices are skipped
    AA_crv_xz = AA_crv_xz(AA_er >= 0);
    AA_er = AA_er(AA_er >= 0); % elements that have negative indices are skipped
end

% Load-stepping functionality
outer_iter = 0;
converged = 0;
load_ratio = 1;
EBC_delta_des = [dby; dbz; dty; dtz]; % desired amount of BC change
EBC_delta_converged = zeros(Nodal_DOF, 1); % previously-converged BC change

%% FEM Main
while converged == 0 && (outer_iter < max_outer_iter)
    outer_iter = outer_iter + 1;
    inner_iter = 0;
    converged = 0;
    EBC_delta_cur = EBC_delta_converged + load_ratio*EBC_delta_des; % current amount of BC change
    while inner_iter < max_inner_iter
        K = zeros(nDOF, nDOF);
        F = zeros(nDOF, 1);
        P = zeros(nDOF, 1);
        % Apply EBC
        d(EBC_idx) = EBC_delta_cur + [y_pre(1); z_pre(1); ty_pre(1); tz_pre(1)]; 
        for e = 1:Nel
            % get local nodal values from global d
            d_i_local = d((4*e - 3):(4*e + 4));
            % get corresponding material properties for current element
            [ke, pe] = compute_element_matrix(d_i_local, ti, E, I, ...
                e, h, MuTs(e), AlphaTs(e), GammaTs(e), ...
                AA_er, AA_crv_xy, AA_crv_xz);
            % global assembly process
            K(LM(1:Nen, e), LM(1:Nen, e)) = K(LM(1:Nen, e), LM(1:Nen, e)) + ke;
            P(LM(1:Nen, e)) = P(LM(1:Nen, e)) + pe;
        end
        % Newton's method
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
        EBC_delta_cur = zeros(Nodal_DOF, 1);
        fprintf("No convergence. Decreasing load step\n");
    else
        EBC_delta_converged = EBC_delta_cur;
    end
end % end outer iteration

%% Outputs
% get changes in xy and xz planes
[wy_bend, wz_bend, ty_new, tz_new] = extract_from_3d(d);
wx_bend = zeros(size(wy_bend));
wx_bend(1) = x_pre(1) + dbx;

dwy_bend = diff(wy_bend);
dwz_bend = diff(wz_bend);

wx_insert = zeros(size(wx_bend));
wy_insert = zeros(size(wy_bend));
wz_insert = zeros(size(wz_bend));

for i = 2:(Nel + 1)
    wx_bend(i) = wx_bend(i - 1) + sqrt(h^2 - dwy_bend(i - 1)^2 - dwz_bend(i - 1)^2); % x coordinate due to bending
    % calculate deltas for consistent element length
    delta = [sqrt(dbx^2/(1 + tz_new(i)^2 + ty_new(i)^2)), ...
               sqrt(dbx^2/(1 + tz_new(i - 1)^2 + ty_new(i - 1)^2))];
    wx_insert(i) = delta(1) - delta(2);
    wy_insert(i) = tz_new(i)*delta(1) - tz_new(i - 1)*delta(2);
    wz_insert(i) = -(ty_new(i)*delta(1) - ty_new(i - 1)*delta(2));
end

x_new = wx_bend + wx_insert;
y_new = wy_bend + wy_insert;
z_new = wz_bend + wz_insert;

%% DEBUG
x_diff = diff(x_new); y_diff = diff(y_new); z_diff = diff(z_new);
h_pre = sqrt(x_diff.^2 + y_diff.^2 + z_diff.^2);
if ~all(abs(h_pre - h) < 1e-5)
    warning('Element size wrong\n')
end
end

%% Helper functions
function [ke, pe] = compute_element_matrix(d_i_local, ti, E, I, ...
    e, h, MuT_e, AlphaT_e, GammaT_e, AA_er, AA_crv_xy, AA_crv_xz)
% Calculate integrals
% _beam will stay the same
% pe_beam = calc_pe_beam(d_i_local, h, E, I);
ke_beam = calc_ke_beam(h, E, I);
pe_beam = ke_beam*d_i_local; % same effect, less calculation

% _cont wil depend on external force formulation
pe_cont = calc_pe_cont(d_i_local, h, ti, MuT_e, AlphaT_e, GammaT_e);
ke_cont = calc_ke_cont(d_i_local, h, ti, MuT_e, AlphaT_e, GammaT_e);

% complete element stiffness and force
pe = pe_beam + pe_cont;
% replace the curvature with fbg measured value
FBG_idx_r = find(e == AA_er);
if FBG_idx_r % if input curvature is [] then FBG_idx_r is also []
    pe(3) = AA_crv_xy(FBG_idx_r)*E*I;
    pe(4) = AA_crv_xz(FBG_idx_r)*E*I;
end
ke = ke_beam + ke_cont;
end

function K = add_corners(K, M2)
% add a 2x2 matrix M2 to the corners of a matrix K
K(1, 1) = M2(1, 1);
K(1, end) = M2(1, end);
K(end, 1) = M2(end, 1);
K(end, end) = M2(end, end);
end

%% Integration subroutines
function pe_beam = calc_pe_beam(d_i_local, h, E, I)
pe_beam = calc_ke_beam(h, E, I)*d_i_local;
end

function ke_beam = calc_ke_beam(h, E, I)
% Element stiffness matrix for 3D beam bending
ke_beam = E*I/h^3*...
    [12, 0, 0, 6*h, -12, 0, 0, 6*h;
    0, 12, -6*h, 0, 0, -12, -6*h, 0;
    0, -6*h, 4*h^2, 0, 0, 6*h, 2*h^2, 0;
    6*h, 0, 0, 4*h^2, -6*h, 0, 0, 2*h^2;
    -12, 0, 0, -6*h, 12, 0, 0, -6*h;
    0, -12, 6*h, 0, 0, 12, 6*h, 0;
    0, -6*h, 2*h^2, 0, 0, 6*h, 4*h^2, 0;
    6*h, 0, 0, 2*h^2, -6*h, 0, 0, 4*h^2];
end

function pe_cont = calc_pe_cont(d_i_local, h, ti, MuT_e, AlphaT_e, GammaT_e)
% Element internal force vector from tissue contact
ig = [-1/sqrt(3); 1/sqrt(3)]; % Gauss integration points
wg = [1; 1]; % Gauss weights
d_i_local_y = d_i_local([1, 4, 5, 8]);
d_i_local_z = d_i_local([2, 3, 6, 7]);
Ny = [shapeY(ig(1), h); shapeY(ig(2), h)]; % Shape function at each gauss point
Nz = [shapeZ(ig(1), h); shapeZ(ig(2), h)];
Ny_zeta = [dshapeY(ig(1), h); dshapeY(ig(2), h)]; % Shape function derivative at each gauss point
Nz_zeta = [dshapeZ(ig(1), h); dshapeZ(ig(2), h)];
wy = [Ny(1, :)*d_i_local_y; Ny(2, :)*d_i_local_y]; % Displacements at each gauss points
wz = [Nz(1, :)*d_i_local_z; Nz(2, :)*d_i_local_z];
wy_zeta = [Ny_zeta(1, :)*d_i_local_y; Ny_zeta(2, :)*d_i_local_y];% Displacements derivative at each gauss points
wz_zeta = [Nz_zeta(1, :)*d_i_local_z; Nz_zeta(2, :)*d_i_local_z];

% Sum over all gauss points
pe_cont_y = zeros(1, 4);
pe_cont_z = zeros(1, 4);
for i = 1:length(ig)
    stretch_y = (ti - abs(wy(i)))/ti;
    stretch_z = (ti - abs(wz(i)))/ti;
    if stretch_y < 0
        stretch_y = 0.1;
    end
    if stretch_z < 0
        stretch_z = 0.1;
    end
    pe_cont_y = pe_cont_y + ...
        wg(i)*(...
        Ny(i, :)*2*MuT_e*((stretch_y)^(AlphaT_e - 1) + 1/2*(stretch_y)^(-AlphaT_e/2 - 1))*...
        wy(i)*(1 - GammaT_e*sin(atan(wy_zeta(i)*(2/h)))^2)*(h/2)...
        );
    pe_cont_z = pe_cont_z + ...
        wg(i)*(...
        Nz(i, :)*2*MuT_e*((stretch_z)^(AlphaT_e - 1) + 1/2*(stretch_z)^(-AlphaT_e/2 - 1))*...
        wz(i)*(1 - GammaT_e*sin(atan(wz_zeta(i)*(2/h)))^2)*(h/2)...
        );
end
pe_cont = [pe_cont_y(1); pe_cont_z(1); pe_cont_z(2); pe_cont_y(2);...
    pe_cont_y(3); pe_cont_z(3); pe_cont_z(4); pe_cont_y(4)];
end

function ke_cont = calc_ke_cont(d_i_local, h, ti, MuT_e, AlphaT_e, GammaT_e)
% Element internal force vector from tissue contact
ig = [-1/sqrt(3); 1/sqrt(3)]; % Gauss integration points
wg = [1; 1]; % Gauss weights
d_i_local_y = d_i_local([1, 4, 5, 8]);
d_i_local_z = d_i_local([2, 3, 6, 7]);
Ny = [shapeY(ig(1), h); shapeY(ig(2), h)]; % Shape function at each gauss point
Nz = [shapeZ(ig(1), h); shapeZ(ig(2), h)];
Ny_zeta = [dshapeY(ig(1), h); dshapeY(ig(2), h)]; % Shape function derivative at each gauss point
Nz_zeta = [dshapeZ(ig(1), h); dshapeZ(ig(2), h)];
wy = [Ny(1, :)*d_i_local_y; Ny(2, :)*d_i_local_y]; % Displacements at each gauss points
wz = [Nz(1, :)*d_i_local_z; Nz(2, :)*d_i_local_z];
wy_zeta = [Ny_zeta(1, :)*d_i_local_y; Ny_zeta(2, :)*d_i_local_y];% Displacements derivative at each gauss points
wz_zeta = [Nz_zeta(1, :)*d_i_local_z; Nz_zeta(2, :)*d_i_local_z];

% Sum over all gauss points
ke_cont_y = zeros(4, 4);
ke_cont_z = zeros(4, 4);
for i = 1:length(ig)
    stretch_y = (ti - abs(wy(i)))/ti;
    stretch_z = (ti - abs(wz(i)))/ti;
    if stretch_y < 0
        stretch_y = 0.1;
    end
    if stretch_z < 0
        stretch_z = 0.1;
    end
    ke_cont_y = ke_cont_y + ...
        wg(i)*(...
        Ny(i, :)'*2*MuT_e*((AlphaT_e - 1)*(stretch_y)^(AlphaT_e - 2)*(-1/ti*sign(wy(i))*Ny(i, :)) + ...
        1/2*(-AlphaT_e/2 - 1)*(stretch_y)^(-AlphaT_e/2 - 2)*(-1/ti*sign(wy(i))*Ny(i, :)))*wy(i)* ...
        (1 - GammaT_e*sin(atan(wy_zeta(i)*(2/h)))^2)*(h/2) + ...
        ...
        Ny(i, :)'*2*MuT_e*((stretch_y)^(AlphaT_e - 1) + 1/2*(stretch_y)^(-AlphaT_e/2 - 1))*Ny(i, :)*...
        (1 - GammaT_e*sin(atan(wy_zeta(i)*(2/h)))^2)*(h/2) + ...
        ...
        Ny(i, :)'*2*MuT_e*((stretch_y)^(AlphaT_e - 1) + 1/2*(stretch_y)^(-AlphaT_e/2 - 1))*wy(i)*...
        -GammaT_e*((2*wy_zeta(i)*(2/h))/((wy_zeta(i)*(2/h))^2 + 1)^2*Ny(i, :)*(2/h) - (2*(wy_zeta(i)*(2/h))^3)/((wy_zeta(i)*(2/h))^2 + 1)^2*Ny(i, :)*(2/h))*(h/2)...
        );
    ke_cont_z = ke_cont_z + ...
        wg(i)*(...
        Nz(i, :)'*2*MuT_e*((AlphaT_e - 1)*(stretch_z)^(AlphaT_e - 2)*(-1/ti*sign(wz(i))*Nz(i, :)) + ...
        1/2*(-AlphaT_e/2 - 1)*(stretch_z)^(-AlphaT_e/2 - 2)*(-1/ti*sign(wz(i))*Nz(i, :)))*wz(i)* ...
        (1 - GammaT_e*sin(atan(wz_zeta(i)*(2/h)))^2)*(h/2) + ...
        ...
        Nz(i, :)'*2*MuT_e*((stretch_z)^(AlphaT_e - 1) + 1/2*(stretch_z)^(-AlphaT_e/2 - 1))*Nz(i, :)*...
        (1 - GammaT_e*sin(atan(wz_zeta(i)*(2/h)))^2)*(h/2) + ...
        ...
        Nz(i, :)'*2*MuT_e*((stretch_z)^(AlphaT_e - 1) + 1/2*(stretch_z)^(-AlphaT_e/2 - 1))*wz(i)*...
        -GammaT_e*((2*wz_zeta(i)*(2/h))/((wz_zeta(i)*(2/h))^2 + 1)^2*Nz(i, :)*(2/h) - (2*(wz_zeta(i)*(2/h))^3)/((wz_zeta(i)*(2/h))^2 + 1)^2*Nz(i, :)*(2/h))*(h/2)...
        );
end
ke_cont = zeros(8:8);
% assemble ke_cont
ke_cont(1:4, 1:4) = add_corners(ke_cont(1:4, 1:4), ke_cont_y(1:2, 1:2));
ke_cont(2:3, 2:3) = ke_cont_z(1:2, 1:2);
ke_cont(1:4, 5:8) = add_corners(ke_cont(1:4, 5:8), ke_cont_y(1:2, 3:4));
ke_cont(2:3, 6:7) = ke_cont_z(1:2, 3:4);
ke_cont(5:8, 1:4) = add_corners(ke_cont(5:8, 1:4), ke_cont_y(3:4, 1:2));
ke_cont(6:7, 2:3) = ke_cont_z(3:4, 1:2);
ke_cont(5:8, 5:8) = add_corners(ke_cont(5:8, 5:8), ke_cont_y(3:4, 3:4));
ke_cont(6:7, 6:7) = ke_cont_z(3:4, 3:4);
end

%% Shape functions in XY and XZ planes
function Ny = shapeY(zeta, h)
% Shape functions N(zeta) in xy
Ny = [(zeta -1)^2*(zeta + 2)/4, ...
    h*(zeta - 1)^2*(zeta + 1)/8, ...
    (zeta + 1)^2*(zeta + 2)/4, ...
    h*(zeta - 1)*(zeta + 1)^2/8];
end

function Nz = shapeZ(zeta, h)
% Shape functions N(zeta) in xz
Nz = [(zeta -1)^2*(zeta + 2)/4, ...
    -h*(zeta - 1)^2*(zeta + 1)/8, ...
    (zeta + 1)^2*(zeta + 2)/4, ...
    -h*(zeta - 1)*(zeta + 1)^2/8];
end

function Ny_zeta = dshapeY(zeta, h)
% Shape functions N_zeta(zeta) in xy
Ny_zeta = [3*(zeta - 1)*(zeta + 1)/4, ...
    h*(zeta - 1)*(3*zeta + 1)/8, ...
    3*(zeta + 1)*(1 - zeta)/4, ...
    h*(zeta + 1)*(3*zeta - 1)/8];
end

function Nz_zeta = dshapeZ(zeta, h)
% Shape functions N_zeta(zeta) in xz
Nz_zeta = [3*(zeta - 1)*(zeta + 1)/4, ...
    -h*(zeta - 1)*(3*zeta + 1)/8, ...
    3*(zeta + 1)*(1 - zeta)/4, ...
    -h*(zeta + 1)*(3*zeta - 1)/8];
end


function Ny_zeta_zeta = ddshapeY(zeta, h)
% Shape functions N_zeta_zeta(zeta) in xy
Ny_zeta_zeta = [3*zeta/2, ...
    (3*zeta - 1)*h/4, ...
    -3/2*zeta, ...
    (3*zeta + 1)*h/4];
end

function Nz_zeta_zeta = ddshapeZ(zeta, h)
% Shape functions N_zeta_zeta(zeta) in xz
Nz_zeta_zeta = [3*zeta/2, ...
    -(3*zeta - 1)*h/4, ...
    -3/2*zeta, ...
    -(3*zeta + 1)*h/4];
end