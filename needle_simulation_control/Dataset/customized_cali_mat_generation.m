% modified at 19/03/2023
% this script is used for 2ch or 3ch calibration matrix generation
% also this script keep the previous version of generate calibration matrix
% created by Yangsheng Xu at Mar. 12 2023
% this script is used to generate calibration matrix for FBG needle 0006
% base on data set calibration7-9_090.xls, calibration10-12_090.xls,
% validation7-9.xls and validation10-12.xls.

% the method used in this script is exactly the same as in
% Cal_mat_SeperateAA.m, but script use% namefile = {'calibration7-9_090.xls','calibration10-12_090.xls'};
% num_trial = {7:9,10:12};


% this script is highly customized, not suitable for auto calibration
% matrix generation

clear;
clc;

num_CH = 2; % only 2 channels were used
num_AA = 4;


% addpath ./prev
% trial_num = {7:9,10:12}; % each data file store 3 trials of measurement for 6 curves
% calibration_filename = {'calibration7-9_090.xls','calibration10-12_090.xls'};
% validation_filename = {'validation7-9_090.xls','validation10-12_090.xls'};
% % data selection
% cali_ch1_deg0 = {[1,3],
%             [1,2,3,5,6],
%             [1,2,3,4,6],
%             [1,2,6]};
% cali_ch1_deg90 = {[1:5],
%             [1:6],
%             [1:6],
%             [1,2,4,5,6]};
%              
%  vali_ch1_deg0 = {[1,6],
%             [1,3,4,5,6],
%             [1,3,4,6],
%             [1,3,4,6]};
%  
%  vali_ch1_deg90 = {[1,2,4,5],
%             [1:6],
%             [1:6],
%             [1,2,5,6]};




trial_num = {1:3};
calibration_filename = {'calibration_ch3_090_processed.xls'};
validation_filename = {'validation_ch3_090_processed.xls'};
cali_curve_curvature = [0,0.5,1.6,2.0,2.5,3.2];
vali_curve_curvature = [0,0.25,0.8,1.0,1.25,3.125];

% data selection
cali_ch1_deg0 = {[1:6],
            [1:6]};
cali_ch1_deg90 = {[1:6],
            [1:6]};

vali_ch1_deg0 = {[1:6],
            [1:6]};

vali_ch1_deg90 = {[1:6],
            [1:6]};
 

            

%output filename
cal_name = 'Cal_mat_2CH_2AA_alldata_A12.mat';
H12 = {};
CS = 'A12'; % condition for channel selection

%% construct meassured data matrix and expected data matrix

for i = 1:2 %use first two AA
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


    % first cal (ch1 and ch2),(deg 0 and 90)
    
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
                
                measure_mat = [measure_mat;mean(data_90(:,channel_select) - data_90_unbent(:,channel_select),1)];
                real_mat = [real_mat; 0,curve_digi];
            end
        end
    end

     % second val (ch1 and ch2),(deg 0 and 90)
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
                
                measure_mat = [measure_mat;mean(data_90(:,channel_select) - data_90_unbent(:,channel_select),1)];
                real_mat = [real_mat; 0,curve_digi];
            end
        end
    end
    
    % get calibration matrix for each AA
    H_sub = inv(transpose(measure_mat)*measure_mat)*transpose(measure_mat)*real_mat;
    predict = measure_mat * H_sub;
    error =  predict - real_mat;
    H{i} = H_sub;
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
    hold off


end

save(cal_name,"H12","CS");
        
    
