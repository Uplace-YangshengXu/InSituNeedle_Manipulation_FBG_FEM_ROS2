function [dcontrol,desired]  = numerical_jacobian_3d_control(xd, Kp, ic, L, Mu, Alpha, Interval,...
    x_pre,y_pre,z_pre,ty_pre,tz_pre,...
    curvatures_xy,curvatures_xz, AA_lcn,thre,desired)
%% FEM and FBG Parameters
S.L = L;
S.Mu = Mu;
S.Alpha = Alpha;
S.function = @three_d_needle_FEM;
S.Interval = Interval;
S.AA_lcn = AA_lcn;

S.x = x_pre; % previous x along the needle
S.y = y_pre; % previous y along the needle 
S.z = z_pre; % previous k along the needle
S.ty = ty_pre;
S.tz = tz_pre;

S.curvatures_xy = curvatures_xy;
S.curvatures_xz = curvatures_xz;

S.thre = thre; % threshold for trajectory progression
S.desired = desired;
%% Control and ODE Parameters
% Requires needle tip position and orientation as feedback

% Since we have something like dx = J du and y = x, where the actual
% base manipulation is the time integration of du, the idea behind the

% For actual control implementation with constant time steps, the control
% is simply u = du*dt

S.xd = xd; % desired tip position and orientation
S.Kp = Kp; % proportional gain -> too large can result in non-converging FEM
%tspan = [0, 1]; % simulation time span

%% get realtime control outputs
% input
S.state = ic(1:5); % current state
S.control = ic(6:10); % current control

% output
[dcontrol,desired] = sys_control(S);

%% Auxiliary Functions

% Control inputs based on feedback linearization and computed torque law
function [dcontrol,desired] = sys_control(S)
state = S.state;
control = S.control;
jac = numerical_jacobian(@(control) input_output_fem(control, S), [control(1),control(2),control(3),control(4),control(5)],length(state));
jac = real(jac);

desired = find_desired(state,S);

dcontrol = -inv(jac)*S.Kp*(state - S.xd(:,desired));
dcontrol = real(dcontrol);
end

% Numerical jacobian based on FEM simulation
%function [y,ds,ks,xs] = input_output_fem(u, S)
function output = input_output_fem(control, S)
[x_new, y_new, z_new, ty_new, tz_new]= S.function(S.L,S.Mu, S.Alpha,S.Interval,...
    S.x,S.y,S.z,S.ty,S.tz,...
    control(1),control(2),control(3),control(4),control(5),...
    S.curvatures_xy,S.curvatures_xz,[]);
output = [x_new(end);y_new(end);z_new(end);ty_new(end);tz_new(end)];

end

function desired = find_desired(state,S)

for i = 1:size(S.xd,2)
    dis(i) = norm(S.xd(:,i) - state);    
end

% dis = vecnorm(S.xd - state);
process = (dis>S.thre);
process(1:S.desired-1) = zeros(1,S.desired-1);
desired = find(process>0,1);
if size(desired,2) == 0
    desired = size(dis,2);
end

end

end