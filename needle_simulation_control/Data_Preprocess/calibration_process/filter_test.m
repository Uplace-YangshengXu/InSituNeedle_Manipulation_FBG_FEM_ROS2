% this script is used to visulize the data collected during calibration
% created in 05/2/2023 by YangshengXu

close all;
clear;
%AA_selection = [1,5,9]; % AA1: 1,5
AA_selection = [2,6,10]; % AA2: 2,6
%AA_selection = [3,7];  % AA3: 3,7
%AA_selection = [4,8];   % AA4: 4,8

addpath ./current_cali_data/
addpath ./prev_cali_data/


% namefile = {'calibration7-9_090.xls','calibration10-12_090.xls'};
% num_trial = {7:9,10:12};
% namefile = {'calibration_ch3_090.xls'}; %collected at 17/03/2023

% namefile = {'calibration_ch3_090_processed.xls'};
% num_trial = {1:3};
% curvature = [0 0.5 1.6 2 2.5 3.2];


% %namefile = {'validation7-9_090.xls','validation10-12_090.xls'}; % data used to validate the calibration matrix
% %namefile = {'validation_ch3_090.xls'}; % data get from ch3 needle, collected at 17/03/2023
namefile = {'validation_ch3_090_processed.xls'};
num_trial = {1:3};
curvature = [0,0.25,0.8,1.0,1.25,3.125]; % constant curvature curve

fig1 = figure(1);
fig2 = figure(2);
fig3 = figure(3);
fig4 = figure(4);

% add for ch3
fig5 = figure(5);
fig6 = figure(6);


ax = axes('Parent',fig1);
ax2 = axes('Parent',fig2);
ax3 = axes('Parent',fig3);
ax4 = axes('Parent',fig4);
ax5 = axes('Parent',fig5);
ax6 = axes('Parent',fig6);

set([ax,ax2,ax3,ax4,ax5,ax6],'FontSize',20,'LineWidth',3)
hold([ax,ax2,ax3,ax4,ax5,ax6],"on")
xlabel([ax,ax2,ax3,ax4,ax5,ax6],'timestamp')
ylabel([ax,ax2,ax3,ax4,ax5,ax6],'wavelength')

ax_plot = animatedline(ax,'Color','r','LineWidth',3);
ax2_plot = animatedline(ax2,'Color','g','LineWidth',3);
ax3_plot = animatedline(ax3,'Color','b','LineWidth',3);
ax4_plot = animatedline(ax4,'Color','k','LineWidth',3);
ax5_plot = animatedline(ax5,'Color','c','LineWidth',3);
ax6_plot = animatedline(ax6,'Color','y','LineWidth',3);

legend(ax,'CH1_0deg')
legend(ax2,'CH1_90deg')
legend(ax3,'CH2_0deg')
legend(ax4,'CH2_90deg')
legend(ax5,'CH3_0deg')
legend(ax6,'CH3_90deg')

% collect all the data
trial_0d = []; % only consider the data with 0deg
trial_90d = [];

for i = 1:size(curvature,2) % for all curves
    curve = num2str(curvature(i));
    % temp compensation
    for num_file = 1: size(num_trial,2)
        disp(namefile{num_file})
        for tri = num_trial{num_file}
            sheet_name = strcat('trial',num2str(tri),'_',curve,'mm');
            
            data_0 = readmatrix(namefile{num_file},'Sheet',strcat(sheet_name,'_0deg'));
            trial_0d = [trial_0d ; data_0]; % dim: 1*numAA*numCH
            data_90 = readmatrix(namefile{num_file},'Sheet',strcat(sheet_name,'_90deg'));
            trial_90d = [trial_90d ; data_90];
        end
    end
end

% get the dimension of data
[row_0d,col_0d] = size(trial_0d);
[row_90d,col_90d] = size(trial_90d);
% the same

timestamp = 1;

while(timestamp <= row_0d)
    cal_data_0d = trial_0d(timestamp,:);
    cal_data_90d = trial_90d(timestamp,:);
%     in form of ch1AA1 ch1AA2 ch1AA3 ...
    addpoints(ax_plot,timestamp,cal_data_0d(AA_selection(1)))
    addpoints(ax2_plot,timestamp,cal_data_90d(AA_selection(1)))
    addpoints(ax3_plot,timestamp,cal_data_0d(AA_selection(2)))
    addpoints(ax4_plot,timestamp,cal_data_90d(AA_selection(2)))
    addpoints(ax5_plot,timestamp,cal_data_0d(AA_selection(3)))
    addpoints(ax6_plot,timestamp,cal_data_90d(AA_selection(3)))
%      
    timestamp = timestamp + 1;
end