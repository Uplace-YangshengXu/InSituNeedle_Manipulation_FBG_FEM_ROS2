% modified in 3/3/2023 by yangsheng xu
% use ros2 subscriber to get fbg data

% modified in 15/01/2023 by yangshengxu
% this script collect fbg reading data for calibration
clear;
clc;

addpath ../
% collect n data set for each curve
FBG_data_point = 400;
% trial num
val_repetitions = 1;
trial_start_num = 9;
% number of channle and activate area
channels = 2;
AAs = 4;

% % curvature of slots on jig
% cal_curve = [0,0.5,1.6,2.0,2.5,3.2]';
% 
% slot_num = length(cal_curve);
% filename = '/calibration7-9_090.xls';

% % curvature of slots on jig
% 
% cal_curve = [0,0.25,0.8,1.0,1.25,3.125]';
% slot_num = length(cal_curve);
% filename = '/validation7-9_090.xls';

cal_curve = 3.2;
slot_num = length(cal_curve);
filename = 'trail9calino6deg0.xls';
cal_rot = 0;

% deg
%cal_rot = [0,90];

calPath = cd;

if exist("subscriber",'var')
        delete(subscriber)
    end
% create a matlab subscriber to get curvature reading
subscriber = MatlabRosPubSub('sub','matlab_fbg_subscriber','/sm130','fbg_msgs/FbgReading');
    
    
for k = trial_start_num:val_repetitions+trial_start_num-1
    for i = 1:slot_num
        for n = 1:length(cal_rot)
            clc;
            txt = strcat('slot no.',num2str(i),',  ',num2str(cal_rot(n)), ' deg, trial ',num2str(k));
            disp(txt);
            disp('Press Enter when ready to collect data');
            pause;
            clc;
            %cal_data = Read_interrogator(FBG_data_point,channels,AAs,interrogator);
            cal_data = [];
            disp('reading, hold on...')
            for h = 1:FBG_data_point
                if exist('subscriber','var')
                    [msg_received,status,statustext] = subscriber.getSubMsg(10);
                    %disp(size(msg_received.signal_reading))
                    % 10 * 1
                    cal_data = [cal_data;msg_received.signal_reading(1:channels*AAs)'];
                end
            end
            
            absfileName = strcat(calPath,filename);
            sheetName = strcat('trial',num2str(k),'_',num2str(cal_curve(i)),'mm','_',num2str(cal_rot(n)),'deg');
            writematrix(cal_data,absfileName,'sheet',sheetName);

        end
    end
end

% close_pnet();
