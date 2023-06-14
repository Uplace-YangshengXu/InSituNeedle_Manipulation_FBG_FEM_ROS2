% created by Jiarong Kang at 27/02/2023
% adpoted from needle_control_test, used for trajectory following
%% dependency initialization
clc
clear
close all
% for FEM
addpath ./FEM/helper_funcs/invChol/
addpath ./FEM/helper_funcs/
addpath ./FEM
addpath ./MatlabRos2_API
% Constants
FEM_params;

% for motor control
addpath ./Control/Galil_MATLAB_API/ % galil control api
addpath ./Control/

%% switches
FBG_switch = 1; %switch off fbg with 0
Motor_switch = 1; %switch off motor with 0

%% interrogator and GMC params

NumChannel = 3; % number of channels
NumAA = 4; % number of active areas

motor_controller_ip = '192.168.1.201';
motor_controller_port = 23;

%% FEM parameters and setup
% % for air

% Mu = [0 ; 0];
% Alpha = [1 ; 1];

Alpha_PSM = 8.74;
Alpha_PVC = -1;
Mu_PSM = 3.03e+03;
Mu_PVC = 1.2715e+04;
Mu = [Mu_PSM/2 ; Mu_PSM]; 
Alpha =[Alpha_PSM ; Alpha_PSM];
Constraints = [];


Interval = {[0, 13];[13,80]};

L = 163; % total length of needle (estimate)

%bx = -L-3.5; % initial base position
bx = -L;
by = 0; 
bk = 0;

% position of AA on needle, measured from needle base.
% only the AA mentioned in AA_lcn will be used in FEM, 
% in this test, we omit the last AA
% AA_lcn = [44;79;114]; 
AA_lcn = [44;79]; 


% initial guess for FEM
x_pre = linspace(bx,bx+L,L+1)';
y_pre = by*ones(size(x_pre));
k_pre = bk*ones(size(x_pre));

% desired traj
tip_traj = [];
global xd

start_x = -6;
start_y = -14.63;

inter_x = 0;
inter_y = -14.63;

final_x = 56;
final_y = -14.63;

xd = [start_x start_y 0; 
      inter_x inter_y 0;
      final_x final_y 0;
        10 -14.63 0;
        58 -17.63 -0.1]';
% xd = [[start_x start_y -0.167; 
%       inter_x inter_y -0.167;];
%       [linspace(inter_x,final_x,100)' linspace(inter_y,final_y,100)' linspace(-0.167,-0.167,100)']]';

% initialize the desired traj
desired = 1; 
desired_s = 1;
% stopping and updating threshold
thre = 0.01; 
%% control panel
fig = figure;
set(fig, 'WindowKeyPressFcn', @KeyPressCallback);
global ESC_PRESSED Arrived 
ESC_PRESSED = 0;
Arrived = 0;

%% control parameters

Kp = 3*diag([1 1 1]);
% scale the control
dt = 0.1;
% ini_tip_state = [x_pre(end);y_pre(end);k_pre(end)];
% ini_control = [0;0;0];

%% initialization for client

if FBG_switch == 1
    if exist("client",'var')
        delete(client)
    end
    client = MatlabRosSrvCli('client','/cli_node',"/cal_curv","fbg_msgs/CalCurvature");
    [connectionStatus,connectionStatustext] = waitForServer(client.cli);

end

%% initialization for motor
g = []; % object of Galil motor controller
Input_AbsPos_X = 0;
Input_AbsPos_Y = 0;
Input_AbsPos_Z = 0; % actually not use
Input_Rotation = 0;

if Motor_switch == 1
    % run ini_motor_controller.m
    g = ini_motor_controller(motor_controller_ip,motor_controller_port);
    
    % set home position
    %set_home_pos=strcat('DP ',num2str(0),',',num2str(0),',', num2str(0), ',', num2str(0));
    %galil_command(g, set_home_pos);


end


%% main part
% define the change of x/y/r of control point with 0, those are used for
% geometry transfer

last_x_control_point = 0;
last_y_control_point = 0;
last_r_control_point = 0;


%% using current curvatures to Cal initial guess of x,y,k_pre
curvatures_xy = [];
curvatures_xz = [];
% get current needle state from FBG data

if exist('client','var')
    msg_received = getResponseMsg(client);
    curvatures_xy = msg_received.curvature_xy;
    curvatures_xz = msg_received.curvature_xz;
end

% [x_new, y_new, k_new] = planar_needle_FEM(L, Mu, Alpha, Interval, ...
%         x_pre, y_pre, k_pre, ...
%         0, 0, 0, ...
%         curvatures_xz, AA_lcn);
[x_new, y_new, k_new,Constraints] = planar_needle_FEM_wc(L, Mu, Alpha, Interval, ...
        x_pre, y_pre, k_pre,Constraints, ...
        0, 0, 0, ...
        curvatures_xy, AA_lcn);

% update states
x_pre = x_new;
y_pre = y_new;
k_pre = k_new;

%% create publisher for needleshape

% needle data publisher
if exist("publisher",'var')
    delete(publisher)
end

publisher = MatlabRosPubSub('pub','matlab_needle_shape_publisher','/needle_shape','fbg_msgs/NeedleShape');
pub_msg = ros2message("fbg_msgs/NeedleShape"); % create message structure
pub_msg.needle_total_length = uint8(L);
pub_msg.active_area_location = AA_lcn;
pub_msg.needle_z_axis = ones(size(x_new));
pub_msg.needle_x_axis = x_pre;
pub_msg.needle_y_axis = y_pre;
pub_msg.needle_slope  = k_pre;
pub_msg.if_init_tip_traj = false;
publisher.sendPubMsg(pub_msg);    
arrived = 0;

tip_traj = [tip_traj [x_pre(end);y_pre(end);k_pre(end)]];

%% main loop
    while (~ESC_PRESSED && ishghandle(fig))
%         tic
        %% updated and the corresponding control
        dbx = 0;
        dby = 0;
        dbk = 0;
        
        if FBG_switch == 1
            msg_received = getResponseMsg(client);
            curvatures_xy = msg_received.curvature_xy;
            curvatures_xz = msg_received.curvature_xz;
        else
            curvatures_xy = [];
            curvatures_xz = [];
        end

%         [x_new, y_new, k_new] = planar_needle_FEM(L, Mu, Alpha, Interval, ...
%         x_pre, y_pre, k_pre, ...
%         dbx, dby, dbk, ...
%         curvatures_xz, AA_lcn);
        [x_new, y_new, k_new,Constraints] = planar_needle_FEM_wc(L, Mu, Alpha, Interval, ...
        x_pre, y_pre, k_pre,Constraints,...
        dbx, dby, dbk, ...
        curvatures_xy, AA_lcn);

        % update states
        x_pre = x_new;
        y_pre = y_new;
        k_pre = k_new;

        pub_msg.needle_x_axis = x_pre;
        pub_msg.needle_y_axis = y_pre;
        pub_msg.needle_slope  = k_pre;
        pub_msg.if_init_tip_traj = true;
        publisher.sendPubMsg(pub_msg);

        tip_traj = [tip_traj [x_pre(end);y_pre(end);k_pre(end)]];

        if Arrived == 0
        ic = [x_pre(end);y_pre(end);k_pre(end);0;0;0];

%         [dcontrol,desired] = numerical_jacobian_traj_following_control(xd, Kp, ic, L, Mu, Alpha, Interval,...
%         x_pre,y_pre,k_pre,...
%         [],AA_lcn,thre,desired);
        [dcontrol,desired] = numerical_jacobian_traj_following_control(xd, Kp, ic, L, Mu, Alpha, Interval,...
        x_pre,y_pre,k_pre,...
        [],AA_lcn,thre,desired,Constraints);

%%      Pasuing at each traj points 
        if desired ~= desired_s
            disp("Paused")
            Arrived = 1;
            dcontrol = dcontrol*0;
            desired_s = desired;
        end
%%
        %scaling the control using step_size for FEM convergence   
        step_size = 0.1;
        if norm(dcontrol*dt) > 0.3
            dcontrol = dcontrol * step_size;
        else
            dcontrol = dcontrol * step_size*5;
        end

        % get scaled base control
        dbx = dcontrol(1)*dt;
        dby = dcontrol(2)*dt;
        dbk = dcontrol(3)*dt;
%         dbx = 0;
%         dby = 0;
%         dbk = 0;

        %restricting the control for FEM convergence
%         dbx = sign(dbx)*min(0.1,norm(dbx));
%         dby = sign(dby)*min(0.05,norm(dby));
%         dbk = sign(dbk)*min(0.01,norm(dbk));

        %% Transform the control into motor control
        [dx,dy,dr,last_x_control_point,last_y_control_point,last_r_control_point] = robot_geometric(dbx,dby,dbk,last_x_control_point,last_y_control_point,last_r_control_point);
        Input_AbsPos_X = Input_AbsPos_X - round(dx*1000);
        Input_AbsPos_Y = Input_AbsPos_Y - round(dy*1000);
        Input_AbsPos_Z = 0; % act   ually not use
        Input_Rotation = Input_Rotation + round(dr*7031.25);
        % control motor
        if Motor_switch == 1
            % move motors
            give_pos=strcat('PA ',num2str(Input_AbsPos_X),',',num2str(Input_AbsPos_Y),',', num2str(Input_AbsPos_Z), ',', num2str(Input_Rotation));
            galil_command(g, give_pos);
            % assume the error during motor move is zero
        end

        %% calculate error
        if FBG_switch == 1
            msg_received = getResponseMsg(client);
            curvatures_xy = msg_received.curvature_xy;
            curvatures_xz = msg_received.curvature_xz;
        else
            curvatures_xy = [];
            curvatures_xz = [];
        end

%         [x_new, y_new, k_new] = planar_needle_FEM(L, Mu, Alpha, Interval, ...
%             x_pre, y_pre, k_pre, ...
%             dbx, dby, dbk, ...
%             curvatures_xz, AA_lcn);
        [x_new, y_new, k_new,Constraints] = planar_needle_FEM_wc(L, Mu, Alpha, Interval, ...
            x_pre, y_pre, k_pre,Constraints, ...
            dbx, dby, dbk, ...
            curvatures_xy, AA_lcn);

        x_pre = x_new;
        y_pre = y_new;
        k_pre = k_new;
       
        % publish again
        pub_msg.needle_x_axis = x_new;
        pub_msg.needle_y_axis = y_new;
        pub_msg.needle_slope  = k_new;
        pub_msg.if_init_tip_traj = true;
        publisher.sendPubMsg(pub_msg);
        tip_traj = [tip_traj [x_new(end);y_new(end);k_new(end)]];

        error = norm([x_new(end);y_new(end);k_new(end)] - xd(:,end));
        end
        %disp(error);
%         toc
        % break critria
        if error <= 0.01 && Arrived == 0
            disp("arrive at goal, stopped with error: " + error);
            Arrived = 1;
            desired = 1;
            desired_s = 1;
%             break;
        end
    drawnow;
    end
% save('tip_traj.mat','tip_traj')
close all

function KeyPressCallback(source, eventdata)
global xd Arrived
global ESC_PRESSED
key = eventdata.Key;
if strcmpi(key, 'upArrow')
    xd = input("Input next goal position or trajectory:");
    Arrived = 0;
elseif strcmpi(key, 'downArrow')
    Arrived = 0;
elseif strcmpi(key, 'leftArrow')
    Arrived = 1;
elseif strcmpi(key, 'rightArrow')
    Arrived = 0;
elseif strcmpi(key, 'escape')
    ESC_PRESSED = 1;
end
end

