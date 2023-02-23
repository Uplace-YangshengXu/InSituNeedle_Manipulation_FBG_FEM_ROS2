function [dx_c,dy_c,dr,Dx,Dy,Dk] = robot_geometric(dx,dy,dk,Dx,Dy,Dk)
% modified in 19/02/2023 dk is tan(theta) and dr is theta

% this script get the dx dy at robot control position 
% base on dy and dk at FEM base position 

% dx, displacement at x axis in mm
% dy, displacement at y axis in mm
% dk, rotation in tan(theta)
% Dx, cumulative change in x axis from beginning
% Dy, cumulative change in y axis
% Dk, cumulative change of rotation stage

% output
% dx_c,dy_c in mm
% dr in DEG
% Dx,Dy,Dk

D = 50.62; % in mm
alpha = atan(dk); % since dk is tan(theta) this line get the d_theta in rad
alpha_kb = Dk; % here Dk is the total change of rotation stage in rad
%last states
x1 = D*cos(alpha_kb);
y1 = D*sin(alpha_kb);
% get current base location and rotation in rad
Dx = Dx + dx;
Dy = Dy + dy;
Dk = Dk + alpha;
% update 
alpha_kb = Dk;
% get current states
x2 = D*cos(alpha_kb);
y2 = D*sin(alpha_kb);

% get base change
dx_c = x1 - x2 + dx;
dy_c = y1 - y2 + dy;

% get rotation in deg
dr = rad2deg(alpha);

end
