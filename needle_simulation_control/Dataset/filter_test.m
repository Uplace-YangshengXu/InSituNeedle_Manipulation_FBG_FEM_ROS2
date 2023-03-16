% test the effect of Moving average filter
% created in 05/2/2023 by YangshengXu
close all;
clear;
AA_selection = [1,5]; % AA1: 1,5
%AA_selection = [2,6]; % AA2: 2,6
%AA_selection = [3,7];  % AA3: 3,7
%AA_selection = [4,8];   % AA4: 4,8

% 
% namefile = {'calibration7-9_090.xls','calibration10-12_090.xls'};
% num_trial = {7:9,10:12};
% curvature = [0 0.5 1.6 2 2.5 3.2];


namefile = {'validation7-9_090.xls','validation10-12_090.xls'}; % data used to validate the calibration matrix
num_trial = {7:9,10:12};
curvature = [0,0.25,0.8,1.0,1.25,3.125]; % constant curvature curve

fig1 = figure(1);
fig2 = figure(2);
fig3 = figure(3);
fig4 = figure(4);


ax = axes('Parent',fig1);
ax2 = axes('Parent',fig2);
ax3 = axes('Parent',fig3);
ax4 = axes('Parent',fig4);

set([ax,ax2,ax3,ax4],'FontSize',20,'LineWidth',3)
hold([ax,ax2,ax3,ax4],"on")
xlabel([ax,ax2,ax3,ax4],'timestamp')
ylabel([ax,ax2,ax3,ax4],'wavelength')

ax_plot = animatedline(ax,'Color','r','LineWidth',3);
ax2_plot = animatedline(ax2,'Color','g','LineWidth',3);
ax3_plot = animatedline(ax3,'Color','b','LineWidth',3);
ax4_plot = animatedline(ax4,'Color','k','LineWidth',3);

legend(ax,'CH1_0deg')
legend(ax2,'CH1_90deg')
legend(ax3,'CH2_0deg')
legend(ax4,'CH2_90deg')


% collect all the data
trial_0d = []; % only consider the data with 0deg
trial_90d = [];

for i = 1:size(curvature,2) % for all curves
    curve = num2str(curvature(i));
    % temp compensation
    for num_file = 1: size(num_trial,2)
        disp(namefile{num_file})
        for tri = num_trial{num_file}
            sheet_name = strcat('trial',num2str(tri),'_',curve,'mm')
            
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
% 
%      addpoints(AA1_ch2_plot,timestamp,cal_data(5))
%      addpoints(AA2_ch2_plot,timestamp,cal_data(6))
%      addpoints(AA3_ch2_plot,timestamp,cal_data(7))
%      addpoints(AA4_ch2_plot,timestamp,cal_data(8))
%     addpoints(AA1_ch3_plot,timestamp,cal_data(9))
%     addpoints(AA2_ch3_plot,timestamp,cal_data(10))
%     addpoints(AA3_ch3_plot,timestamp,cal_data(11))
%     addpoints(AA4_ch3_plot,timestamp,cal_data(12))
%      
    timestamp = timestamp + 1;
%     pause(0.01)
end