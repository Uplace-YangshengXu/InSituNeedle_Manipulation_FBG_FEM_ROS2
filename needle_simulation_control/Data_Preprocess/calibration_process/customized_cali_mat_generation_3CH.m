% copy and modified from customized_cali_mat_generation.m at 19/03/2023
% this script is used for 3ch calibration matrix generation
% created by Yangsheng Xu at Mar. 12 2023
% this script is used to generate calibration matrix for FBG needle 0006

% the method used in this script is exactly the same as in
% Cal_mat_SeperateAA.m

% this script is highly customized, not suitable for auto calibration
% matrix generation

clear;
clc;

num_CH = 3; % 3 channels were used
num_AA = 4; 
trial_num = {1:3}; % each data file store 3 trials of measurement for 6 curves
calibration_filename = {'calibration_ch3_090_processed.xls'};
validation_filename = {'validation_ch3_090_processed.xls'};
cali_curve_curvature = [0,0.5,1.6,2.0,2.5,3.2];
vali_curve_curvature = [0,0.25,0.8,1.0,1.25,3.125];

% data selection
cali_ch1_deg0 = {[1:6],
            [1:6]};
cali_ch1_deg90 = {[1:6],
            [1:6]};
        
%  cali_ch2_deg0 = {[1:6],
%             [1:6]};
%  
%  cali_ch2_deg90 = {[1:6],
%             [1:6]};

% cali_ch3_deg0 = {[1:6],
%             [1:6]};

% cali_ch3_deg90 = {[1:6],
%             [1:6]};
        
 vali_ch1_deg0 = {[1:6],
            [1:6]};

 
 vali_ch1_deg90 = {[1:6],
            [1:6]};

 
%  vali_ch2_deg0 = {[1:6],
%             [1:6]};

%  
%  vali_ch2_deg90 = {[1:6],
%             [1:6]};

%  vali_ch3_deg0 = {[1:6],
%             [1:6]};

%  vali_ch3_deg90 = {[1;6],
%             [1:6]};



          
%output filename
cal_name = 'Cal_mat_3CH_2AA_alldata.mat';
H = {};
CS = 'A'; % condition for channel selection
%% construct meassured data matrix and expected data matrix


for i = 1:2 % only first two AA are used
    real_mat = [];
    measure_mat = [];
    channel_select = [];

    if CS == 'A'
        channel_select = [i,i+num_AA,i+num_AA+num_AA]; % for A
    end
    % or
    if CS == 'A12'
        channel_select = [i,i+num_AA]; % for A12
    end
    % or
    if CS == 'A13'
        channel_select = [i,i+num_AA+num_AA]; % for A13
    end
    % or
    if CS == 'A23'
        channel_select = [i+num_AA, i+num_AA+num_AA]; % for A23
    end

    % first cal,(deg 0 and 90)
    
    for curve_digi_index = cali_ch1_deg0{i}
        % for 0 deg
        curve_digi = cali_curve_curvature(curve_digi_index);
        curve_str = num2str(curve_digi);

        for num_file = 1:size(trial_num,2)
            
            for tri = trial_num{num_file}
                sheet_name = strcat('trial',num2str(tri),'_',curve_str,'mm');
                sheet_name_unbent = strcat('trial',num2str(tri),'_0mm');
                data_0_unbent = readmatrix(calibration_filename{num_file},'Sheet',strcat(sheet_name_unbent,'_0deg'));
                
                data_0 = readmatrix(calibration_filename{num_file},'Sheet',strcat(sheet_name,'_0deg'));
                
                % for 3CH only
                measure_mat = [measure_mat;mean(data_0(:,channel_select) - data_0_unbent(:,channel_select),1)];
                
                real_mat = [real_mat; curve_digi,0];
            end
        end
    end

    for curve_digi_index = cali_ch1_deg90{i}
        % for 90 deg
        curve_digi = cali_curve_curvature(curve_digi_index);
        curve_str = num2str(curve_digi);
        for num_file = 1:size(trial_num,2)
            
            for tri = trial_num{num_file}
                sheet_name = strcat('trial',num2str(tri),'_',curve_str,'mm');
                sheet_name_unbent = strcat('trial',num2str(tri),'_0mm');
                data_90_unbent = readmatrix(calibration_filename{num_file},'Sheet',strcat(sheet_name_unbent,'_90deg'));
                data_90 = readmatrix(calibration_filename{num_file},'Sheet',strcat(sheet_name,'_90deg'));
                % for 3CH only
                measure_mat = [measure_mat;mean(data_90(:,channel_select) - data_90_unbent(:,channel_select),1)];
                
                real_mat = [real_mat; 0,curve_digi];
            end
        end
    end

     % second val,(deg 0 and 90)
     for curve_digi_index = vali_ch1_deg0{i}
        % for 0 deg
        curve_digi = vali_curve_curvature(curve_digi_index);
        curve_str = num2str(curve_digi);

        for num_file = 1:size(trial_num,2)
            
            for tri = trial_num{num_file}
                sheet_name = strcat('trial',num2str(tri),'_',curve_str,'mm');
                sheet_name_unbent = strcat('trial',num2str(tri),'_0mm');
                data_0_unbent = readmatrix(validation_filename{num_file},'Sheet',strcat(sheet_name_unbent,'_0deg'));
                data_0 = readmatrix(validation_filename{num_file},'Sheet',strcat(sheet_name,'_0deg'));
                % for 3CH only
                measure_mat = [measure_mat;mean(data_0(:,channel_select) - data_0_unbent(:,channel_select),1)];
                real_mat = [real_mat; curve_digi,0];
            end
        end
    end

    for curve_digi_index = vali_ch1_deg90{i}
        % for 90 deg
        curve_digi = vali_curve_curvature(curve_digi_index);
        curve_str = num2str(curve_digi);
        for num_file = 1:size(trial_num,2)
            
            for tri = trial_num{num_file}
                sheet_name = strcat('trial',num2str(tri),'_',curve_str,'mm');
                sheet_name_unbent = strcat('trial',num2str(tri),'_0mm');
                data_90_unbent = readmatrix(validation_filename{num_file},'Sheet',strcat(sheet_name_unbent,'_90deg'));
                data_90 = readmatrix(validation_filename{num_file},'Sheet',strcat(sheet_name,'_90deg'));
                % for 3CH only
                measure_mat = [measure_mat;mean(data_90(:,channel_select) - data_90_unbent(:,channel_select),1)];              
                real_mat = [real_mat; 0,curve_digi];
            end
        end
    end
    
    % get calibration matrix for each AA
    H_sub = inv(transpose(measure_mat)*measure_mat)*transpose(measure_mat)*real_mat;
    predict = measure_mat * H_sub;
    H{i} = H_sub;
    error =  predict - real_mat;
    disp('mean error:');
    disp(mean(abs(error),1));
    disp('max error:');
    disp(max(abs(error)));
    figure(i)
    plot(error(:,1));
    hold on;
    plot(error(:,2));
    legend("xy plane","xz plane");
    grid on;
    hold off;


end

save(cal_name,"H");


        
    
