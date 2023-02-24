function dcontrol = numerical_jacobian_pos_ori_control(xd, Kp, ic, L, Mu, Alpha, Interval,...
    x_pre,y_pre,k_pre,...
    curvatures, AA_lcn)
%% FEM and FBG Parameters
% S.sb = sb;
% S.l = l;
S.L = L;
%S.ti = ti;
%S.Nel = Nel;
S.Mu = Mu;
S.Alpha = Alpha;
%S.function = @FBG_FEM_realtime;
S.function = @planar_needle_FEM;
S.Interval = Interval;
%S.NumChannel = NumChannel;
%S.NumAA = NumAA; 
%S.interrogator = interrogator;
%S.RefData = RefData;
S.AA_lcn = AA_lcn;
%S.FBG_switch = FBG_switch; % switch for FBG
S.x = x_pre; % previous x along the needle
S.y = y_pre; % previous y along the needle 
S.k = k_pre; % previous k along the needle
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
S.state = ic(1:3); % current state
S.control = ic(4:6); % current control

% output
dcontrol = sys_control(S);

%% Auxiliary Functions

% Control inputs based on feedback linearization and computed torque law
function dcontrol = sys_control(S)
state = S.state;
control = S.control;
jac = numerical_jacobian(@(control) input_output_fem(control, S), [control(1),control(2),control(3)],length(state));
jac = real(jac);
dcontrol = -inv(jac)*S.Kp*(state - S.xd);
dcontrol = real(dcontrol);
end

% Numerical jacobian based on FEM simulation
%function [y,ds,ks,xs] = input_output_fem(u, S)
function output = input_output_fem(control, S)
[x_new, y_new, k_new] = S.function(S.L,S.Mu, S.Alpha,S.Interval,...
    S.x,S.y,S.k, ...
    control(1), control(2),control(3),...
    curvatures, AA_lcn);
output = [x_new(end);y_new(end);k_new(end)];

end

end