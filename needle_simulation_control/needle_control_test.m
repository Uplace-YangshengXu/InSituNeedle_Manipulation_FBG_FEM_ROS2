% modified by Yangsheng Xu at 24/02/2023
% this main script is modified to be able to compatible with ros2
% resceive msg from ros2 publisher

% modified by yangsheng xu at 13/02/2023
% final version of test demo, nearly solve all the issues

% created by yangsheng xu at 22/01/2023
% this script reconstruct the needle base on FEM and FBG reading
% and implement a control test which alway keep the needle straigt


%% dependency initialization

% for FEM
addpath ./FEM/helper_funcs/invChol/
addpath ./FEM/helper_funcs/
addpath ./FEM

% for memmap % temperatory use
memmapfile_name = 'communicate.dat';
filename = fullfile(tempdir,memmapfile_name);


% Constants
FEM_params;

% for motor control
addpath ./Control/Galil_MATLAB_API/ % galil control api
addpath ./Control/

%% switches
FBG_switch = 1; %switch off fbg with 0
Motor_switch = 0; %switch off motor with 0

%% interrogator and GMC params

NumChannel = 3; % number of channels
NumAA = 4; % number of active areas

motor_controller_ip = '192.168.1.201';
motor_controller_port = 23;

%% FEM parameters and setup
Alpha_PSM = 8.74;
Alpha_PVC = -1;
Mu_PSM = 3.03e+03;
Mu_PVC = 1.2715e+04;
%Mu = Mu_PSM;
%Alpha = Alpha_PSM;

% for air
Mu = 0;
Alpha = 1;

Interval = {[0, 80]};

L = 200; % total length of needle

bx = 0; % initial base position
by = 0; % 
bk = 0; % assume the needle is horizontally straight

x_pre = linspace(bx,bx+L,L+1)';
y_pre = by*ones(size(x_pre));
k_pre = bk*ones(size(x_pre)); % used as x_pre, y_pre and k_pre in FEM

xd = []; % desired states
AA_lcn = [100;135];
%AA_lcn = [100;135;170]; % position of AA on needle, measured from needle base.
% only the AA mentioned in AA_lcn will be used in FEM, in this test, we omit the last AA

%% control parameters
Kp = diag([1 1 1]);
dt = 0.1; % scale the control
ini_tip_state = [x_pre(end);y_pre(end);k_pre(end)];
ini_control = [0;0;0];

%% initialization

if FBG_switch == 1
    if exist("subscriber")
        delete(subscriber)
    end
    % create a matlab subscriber to get curvature reading
    subscriber = MatlabRosPubSub('sub','matlab_curvature_subscriber','/pub_Curv','fbg_msgs/Curvature');
end

g = []; % object of Galil motor controller

if Motor_switch == 1
    % run ini_motor_controller.m
    g = ini_motor_controller(motor_controller_ip,motor_controller_port);
    % go to home position
    Input_AbsPos_X = 0;
    Input_AbsPos_Y = 0;
    Input_AbsPos_Z = 0; % actually not use
    Input_Rotation = 0;
end

% initialize variables for memmap
%curvatures = zeros(NumAA,2); %num_AA * 2
%curvatures = data_process(RefData,RefData,NumChannel,NumAA);
[msg_received,status,statustext] = subscriber.getSubMsg(10);
curvatures_xy = msg_received.curvature_xy;
curvatures_xz = msg_received.curvature_xz;

% get the new states by ini move
[x_new, y_new, k_new] = planar_needle_FEM(L, Mu, Alpha, Interval, ...
    x_pre, y_pre, k_pre, ...
    ini_control(1), ini_control(2), ini_control(3), ...
    curvatures_xz, AA_lcn);
% update the previous states
x_pre = x_new;
y_pre = y_new;
k_pre = k_new;

% check if exist this file
a = exist(filename, 'file');

if a == 0
    % if not exist, create one
    %plot needed parameters
    fid = fopen(filename,'w');
    fwrite(fid,x_new,'double');
    fwrite(fid,y_new,'double');
    fwrite(fid,k_new,'double');
    %fwrite(fid,curvatures,'double');
    fclose(fid);
end

% get output size
sz_x_new = size(x_new);
sz_y_new = size(y_new);
sz_k_new = size(k_new);
%sz_curvatures = size(curvatures);

m = memmapfile(filename, 'Writable',true, 'Format', ...
    {'double', sz_x_new, 'x_new';
    'double', sz_y_new, 'y_new';
    'double', sz_k_new, 'k_new';
    %'double', sz_curvatures, 'curvatures';
    });

% story initialize data
% m.Data.x_new(1:sz_x_new(1), 1) = x_new;
% m.Data.y_new(1:sz_y_new(1), 1) = y_new;
% m.Data.k_new(1:sz_k_new(1), 1) = k_new;
% m.Data.curvatures(1:sz_curvatures(1),1:sz_curvatures(2)) = curvatures;

% save params for plotting use
save("../plot_params.mat",'NumChannel','NumAA','FBG_switch','L','ti','Mu','Alpha','Interval','AA_lcn');

%% main part
% define the change of x/y/r of control point with 0, those are used for
% geometry transfer

last_x_control_point = 0;
last_y_control_point = 0;
last_r_control_point = 0;


% main loop
while(1)
    % no move, just shape sensing
    dbx = 0;
    dby = 0;
    dbk = 0;

    % get current needle state from FBG data
    [msg_received,status,statustext] = subscriber.getSubMsg(10);
    curvatures_xy = msg_received.curvature_xy;
    curvatures_xz = msg_received.curvature_xz

    [x_new, y_new, k_new] = planar_needle_FEM(L, Mu, Alpha, Interval, ...
    x_pre, y_pre, k_pre, ...
    dbx, dby, dbk, ...
    curvatures_xz, AA_lcn);

    % update states
    x_pre = x_new;
    y_pre = y_new;
    k_pre = k_new;
    % get new desire tip states
    xd = [x_new(end);y_new(end);0]; % desired tip state for next 

    while (1)
        if FBG_switch == 1
            [msg_received,status,statustext] = subscriber.getSubMsg(10);
            curvatures_xy = msg_received.curvature_xy;
            curvatures_xz = msg_received.curvature_xz;
        else
            curvatures_xy = [];
            curvatures_xz = [];
        end
        
        ic = [x_pre(end);y_pre(end);k_pre(end);0;0;0];
        dcontrol = numerical_jacobian_pos_ori_control(xd, Kp, ic, L, Mu, Alpha, Interval,...
        x_pre,y_pre,k_pre,...
        curvatures_xz, AA_lcn);

        % motor gain
        % cumulative record x/y/r at control point

        % get scaled base control
        dbx = dcontrol(1)*dt;
        dby = dcontrol(2)*dt;
        dbk = dcontrol(3)*dt;

        [dx,dy,dr,last_x_control_point,last_y_control_point,last_r_control_point] = robot_geometric(dbx,dby,dbk,last_x_control_point,last_y_control_point,last_r_control_point);
        % control motor
        if Motor_switch == 1
            % move motors
            % 
            Input_AbsPos_X = Input_AbsPos_X - round(dx*1000);
            Input_AbsPos_Y = Input_AbsPos_Y - round(dy*1000);
            Input_AbsPos_Z = 0; % actually not use
            Input_Rotation = Input_Rotation + round(dr*7031.25);
            give_pos=strcat('PA ',num2str(Input_AbsPos_X),',',num2str(Input_AbsPos_Y),',', num2str(Input_AbsPos_Z), ',', num2str(Input_Rotation));
            galil_command(g, give_pos);
            % assume the error during motor move is zero
        end
        % calculate error
        if FBG_switch == 1
            [msg_received,status,statustext] = subscriber.getSubMsg(10);
            curvatures_xy = msg_received.curvature_xy;
            curvatures_xz = msg_received.curvature_xz;
        else
            curvatures_xy = [];
            curvatures_xz = [];
        end

        [x_new, y_new, k_new] = planar_needle_FEM(L, Mu, Alpha, Interval, ...
            x_pre, y_pre, k_pre, ...
            dbx, dby, dbk, ...
            curvatures_xz, AA_lcn);
        x_pre = x_new;
        y_pre = y_new;
        k_pre = k_new;

        error = norm([x_new(end);y_new(end);k_new(end)] - xd)
        %disp(error);

        % story data for plotting
%         m.Data.x_new(1:sz_x_new(1), 1) = x_new;
%         m.Data.y_new(1:sz_y_new(1), 1) = y_new;
%         m.Data.k_new(1:sz_k_new(1), 1) = k_new;
%         m.Data.curvatures(1:sz_curvatures(1),1:sz_curvatures(2)) = curvatures;
        

        % break critria
        if error <= 0.05
            % story data for plotting
% %             m.Data.x_new(1:sz_x_new(1), 1) = x_new;
% %             m.Data.y_new(1:sz_y_new(1), 1) = y_new;
% %             m.Data.k_new(1:sz_k_new(1), 1) = k_new;
% %             m.Data.curvatures(1:sz_curvatures(1),1:sz_curvatures(2)) = curvatures;
            break;
        end

    end
end
