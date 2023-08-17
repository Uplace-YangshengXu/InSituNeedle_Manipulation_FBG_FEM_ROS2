function [dcontrol,desired] = numerical_jacobian_traj_following_control(xd, Kp, ic, L, Mu, Alpha, Interval, Ti,...
    x_pre,y_pre,k_pre,...
    curvatures,AA_lcn,thre,desired,Constraints)
% function [dcontrol,desired] = numerical_jacobian_traj_following_control(xd, Kp, ic, L, Mu, Alpha, Interval,...
%     x_pre,y_pre,k_pre,...
%     curvatures,AA_lcn,thre,desired)
%% FEM and FBG Parameters
% S.sb = sb;
% S.l = l;
S.L = L;
%S.ti = ti;
%S.Nel = Nel;
S.Mu = Mu;
S.Alpha = Alpha;
S.function = @planar_needle_FEM_wc;
% S.function = @planar_needle_FEM;
S.Constraints = Constraints;
S.Interval = Interval;
S.Ti = Ti;
S.AA_lcn = AA_lcn;

S.x = x_pre; % previous x along the needle
S.y = y_pre; % previous y along the needle 
S.k = k_pre; % previous k along the needle

S.thre = thre; % threshold for trajectory progression
S.desired = desired;
S.curvatures = curvatures;
% S.curvatures = []; % using pure FEM for CDiff

%% Control and ODE Parameters
% Requires needle tip position and orientation as feedback

% Since we have something like dx = J du and y = x, where the actual
% base manipulation is the time integration of du, the idea behind the

% For actual control implementation with constant time steps, the control
% is simply u = du*dt

S.xd = xd; % desired tip position and orientation
S.Kp = Kp; % proportional gain -> too large can result in non-converging FEM

%% get realtime control outputs
% input
S.state = ic(1:3); % current state
S.control = ic(4:6); % current control

% output
[dcontrol,desired] = sys_control(S);

%% Auxiliary Functions

% Control inputs based on feedback linearization and computed torque law
function [dcontrol,desired] = sys_control(S)
state = S.state;
control = S.control;
jac = numerical_jacobian(@(control) input_output_fem(control, S), [control(1),control(2),control(3)],length(state));
jac = real(jac);

desired = find_desired(state,S);

dcontrol = -inv(jac)*S.Kp*(state - S.xd(:,desired));
dcontrol = real(dcontrol);
end
% Numerical jacobian based on FEM simulation
%function [y,ds,ks,xs] = input_output_fem(u, S)
function output = input_output_fem(control, S)
[x_new, y_new, k_new,S.Constraints] = S.function(S.L,S.Mu, S.Alpha,S.Interval,S.Ti,...
    S.x,S.y,S.k,S.Constraints, ...
    control(1), control(2),control(3),...
    S.curvatures, S.AA_lcn);
% [x_new, y_new, k_new,] = S.function(S.L,S.Mu, S.Alpha,S.Interval,...
%     S.x,S.y,S.k, ...
%     control(1), control(2),control(3),...
%     S.curvatures, S.AA_lcn);
output = [x_new(end);y_new(end);k_new(end)];

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

