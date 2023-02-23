% modified by yangsheng xu at 13/02/2023
% final version of test demo, nearly solve all the issues

% created by yangsheng xu at 22/01/2023
% this script reconstruct the needle base on FEM and FBG reading
% and implement a control test which alway keep the needle straigt

%% dependency initialization
% for FBG
% addpath ../FBG/sm130_interrogator_matlab/ % matlab method to get fbg data
addpath ../FBG/sm130_interrogator_python/ % python method to get fbg data
addpath ../FBG/rawdata_process/ % method to transfer rawdata to curvatures
addpath ../FBG/rawdata_process/LScalibration % calibration matrix is here
% for FEM
addpath ../FEM/helper_funcs/invChol/
addpath ../FEM/helper_funcs/
addpath ../FEM

% for log file
addpath ../FBG/Log

% for memmap
memmapfile_name = 'communicate.dat';
filename = fullfile(tempdir,memmapfile_name);
% if exist(filename,'file')
%     delete(filename);
% end

% Constants
FEM_params;

% for motor control
addpath ./Galil_MATLAB_API/ % galil control api


%% switches
FBG_switch = 1; %switch off fbg with 0
Motor_switch = 1; %switch off motor with 0

%% interrogator and GMC params
% close all pnet connection (matlab method only)
% close_pnet;

NumChannel = 3; % number of channels
NumAA = 4; % number of active areas
interrogator_ip = '192.168.1.11';
interrogator_port = 1852;
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

AA_lcn = [100;135;170]; % position of AA on needle, measured from needle base.
% only the AA mentioned in AA_lcn will be used in FEM, in this test, we omit the last AA

%% control parameters
Kp = diag([1 1 1]);
dt = 0.1; % scale the control
ini_tip_state = [x_pre(end);y_pre(end);k_pre(end)];
ini_control = [0;0;0];

%% initialization

interrogator = []; % this is the object of interrogator
g = []; % object of Galil motor controller

% Read interrogator data for FBG initialization
RefData = zeros(1,NumChannel * NumAA);

if FBG_switch == 1
    disp("Make sure the needle is in a stright line, press ANYKEY to get ref data.");
    pause();

    % matlab method
    % run ini_interrogator.m
    % read the reference data
    %interrogator = ini_interrogator('IPaddress',interrogator_ip,'Port',interrogator_port,'ReadTimeout',0.1);
    %RefData = mean(Read_interrogator(20,NumChannel,NumAA,interrogator),1);
    
    % python method
    interrogator = get_interrogator(interrogator_ip,interrogator_port);
    RefData = mean(Read_interrogator_python(20,3,4,interrogator),1); % take mean of 20 data set
    
    % save to log file
    % disp("Save the ref data to log file.")
    %curr_time = datestr(now,26);
    %record_fbg_ref(NumChannel,NumAA,RefData,curr_time);

end

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
curvatures = data_process(RefData,RefData,NumChannel,NumAA);
curvatures_xy = curvatures(:,1);
curvatures_xz = curvatures(:,2);
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
    fwrite(fid,curvatures,'double');
    fclose(fid);
end

% get output size
sz_x_new = size(x_new);
sz_y_new = size(y_new);
sz_k_new = size(k_new);
sz_curvatures = size(curvatures);

m = memmapfile(filename, 'Writable',true, 'Format', ...
    {'double', sz_x_new, 'x_new';
    'double', sz_y_new, 'y_new';
    'double', sz_k_new, 'k_new';
    'double', sz_curvatures, 'curvatures';
    });

% story initialize data
m.Data.x_new(1:sz_x_new(1), 1) = x_new;
m.Data.y_new(1:sz_y_new(1), 1) = y_new;
m.Data.k_new(1:sz_k_new(1), 1) = k_new;
m.Data.curvatures(1:sz_curvatures(1),1:sz_curvatures(2)) = curvatures;

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
    [x_new, y_new, k_new] = FBG_FEM_realtime(L, Mu, Alpha, Interval, ...
    x_pre, y_pre, k_pre, ...
    dbx, dby, dbk, ...
    NumChannel, NumAA, interrogator, RefData,  AA_lcn, FBG_switch);
    % update states
    x_pre = x_new;
    y_pre = y_new;
    k_pre = k_new;
    % get new desire tip states
    xd = [x_new(end);y_new(end);0]; % desired tip state for next 

    while (1)
        tic

        ic = [x_pre(end);y_pre(end);k_pre(end);0;0;0];
        dcontrol = numerical_jacobian_pos_ori_control(xd, Kp, ic, L, Mu, Alpha, Interval,...
        x_pre,y_pre,k_pre,...
        NumChannel, NumAA, interrogator, RefData, AA_lcn,FBG_switch);
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
        [x_new, y_new, k_new] = FBG_FEM_realtime(L, Mu, Alpha, Interval, ...
            x_pre, y_pre, k_pre, ...
            dbx, dby, dbk, ...
            NumChannel, NumAA, interrogator, RefData,  AA_lcn, FBG_switch);
        x_pre = x_new;
        y_pre = y_new;
        k_pre = k_new;

        if FBG_switch == 1
            % get curvature
            % RawData = Read_interrogator(1,NumChannel,NumAA,interrogator);
            RawData = Read_interrogator_python(1,NumChannel,NumAA,interrogator);
            curvatures = data_process(RawData,RefData,NumChannel,NumAA);
            disp(curvatures(1,2));
        end
        error = norm([x_new(end);y_new(end);k_new(end)] - xd);
        %disp(error);

        % story data for plotting
        m.Data.x_new(1:sz_x_new(1), 1) = x_new;
        m.Data.y_new(1:sz_y_new(1), 1) = y_new;
        m.Data.k_new(1:sz_k_new(1), 1) = k_new;
        m.Data.curvatures(1:sz_curvatures(1),1:sz_curvatures(2)) = curvatures;
        toc
        % break critria
        if error <= 0.05
            % story data for plotting
            m.Data.x_new(1:sz_x_new(1), 1) = x_new;
            m.Data.y_new(1:sz_y_new(1), 1) = y_new;
            m.Data.k_new(1:sz_k_new(1), 1) = k_new;
            m.Data.curvatures(1:sz_curvatures(1),1:sz_curvatures(2)) = curvatures;
            break;
        end

    end
end
