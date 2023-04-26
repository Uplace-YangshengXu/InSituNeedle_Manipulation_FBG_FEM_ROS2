% this script is to get data for temp compensation
% 
clear;
clc;

addpath ../
% collect n data set for each curve
FBG_data_point = 1;
% trial num
val_repetitions = 20;
trial_start_num = 1;
% number of channle and activate area
channels = 3;
AAs = 4;
fbg_sensor_num = 10; % 4 + 4 + 2


filename = '/temp_fbg_data10.xls';

calPath = cd;

if exist("subscriber",'var')
        delete(subscriber)
    end
% create a matlab subscriber to get curvature reading
subscriber = MatlabRosPubSub('sub','matlab_fbg_subscriber','/sm130','fbg_msgs/FbgReading');

clc;
cal_data = [];
% read base line
for h = 1:FBG_data_point
    if exist('subscriber','var')
        [msg_received,status,statustext] = subscriber.getSubMsg(10);
        % 10 * 1
        cal_data = [cal_data;msg_received.signal_reading(1:fbg_sensor_num)'];
    end
end
  
for k = trial_start_num:val_repetitions+trial_start_num-1
    disp('Press Enter when ready to collect data');
    pause;
    
    disp('reading, hold on...')
    for h = 1:FBG_data_point
        if exist('subscriber','var')
            [msg_received,status,statustext] = subscriber.getSubMsg(10);
            % 10 * 1
            cal_data = [cal_data;msg_received.signal_reading(1:fbg_sensor_num)'];
        end
    end

    absfileName = strcat(calPath,filename);
    sheetName = 'Temp_vari_data';
    writematrix(cal_data,absfileName,'sheet',sheetName);

end

