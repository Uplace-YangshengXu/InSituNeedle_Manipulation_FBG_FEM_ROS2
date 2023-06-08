% created by yangsheng xu at 6/06/2023
% this script compare two methods of temperature compensation
% use temp_fbg_data_comparation.xls
% curvature change temperature stay constant
% clear;
% clc;

addpath ../calibration_process/
load Cal_mat_2CH_2AA_alldata_A12.mat % H12 CS
load Cal_mat_2CH_2AA_alldata_A13.mat % H13 CS
load Cal_mat_2CH_2AA_alldata_A23.mat % H23 CS
load Cal_mat_3CH_2AA_alldata.mat % H
% run temp_ratio_formal.m to get ratio
load temp_comp_ratios.mat % ratio_AA1 ratio_AA2


A_index = {[1,5,9],[2,6,10]}; %3ch 2aa
A12_index = {[1,5],[2,6]};
A13_index = {[1,9],[2,10]};
A23_index = {[5,9],[6,10]};
E1 = [0 1 0; 0 0 1]; % for A23
E2 = [1 0 0; 0 0 1]; % for A13
E3 = [1 0 0; 0 1 0]; % for A12
ratios = [ratio_AA1 ratio_AA2];
%ratios = ones(3,2);
%ratios = [[1;1;1],[1.5;0.1;0.1]];

seq_cur = [0 0.25 0.8 1.0 1.25 3.125 0.5 1.6 2.0 2.5 3.2];
% caution::outlayer 0.5

namefile_grount_turth = 'temp_exp_formal_ground_truth.xls';
namefile = 'temp_exp_formal_T_100.xls';
%namefile = 'temp_exp_formal_ground_truth.xls';
sheet_name = 'Temp_vari_data';
data = readmatrix(namefile,'Sheet',sheet_name);
data_ground_truth = readmatrix(namefile_grount_turth,'Sheet',sheet_name);
[r,c ] = size(data); % row and col
% get ref
ref = data_ground_truth(1,:);

f = figure();
ax1 = subplot(2,2,1); grid on; % for AA1
ax2 = subplot(2,2,2); grid on; % for AA2
ax3 = subplot(2,2,3); grid on; % for curv at xy plane
ax4 = subplot(2,2,4); grid on; % for curv at xz plane
hold([ax1,ax2],'on')
xlabel([ax1,ax2,ax3,ax4],'real\_curvature,(1/m)')
ylabel([ax1,ax2],'wavelength compensation,(nm)')
ylabel([ax3,ax4],'pred\_curvature,(1/m)')
title(ax1,"AA1")
title(ax2,'AA2')
title(ax3,"pred\_cur\_xy")
title(ax4,"pred\_cur\_xz")

% for our TC method
ani_plot1 = animatedline(ax1,'Marker','o','Color','r');
ani_plot2 = animatedline(ax2,'Marker','o','Color','r');
% xy
ani_plot3 = animatedline(ax3,'Marker','o','Color','r'); % for AA1
ani_plot4 = animatedline(ax3,'Marker','o','Color','b'); % for AA2
% xz
ani_plot5 = animatedline(ax4,'Marker','o','Color','r'); % for AA1
ani_plot6 = animatedline(ax4,'Marker','o','Color','b'); % for AA2
% for compared method
ani_plot12 = animatedline(ax1,'Marker','*','Color','g');
ani_plot22 = animatedline(ax2,'Marker','*','Color','g');

ani_plot33 = animatedline(ax3,'Marker','*','Color','g'); % for AA1
ani_plot44 = animatedline(ax3,'Marker','*','Color','k'); % for AA2
ani_plot55 = animatedline(ax4,'Marker','*','Color','g'); % for AA1
ani_plot66 = animatedline(ax4,'Marker','*','Color','k'); % for AA2

choose_plot1 = {ani_plot1,ani_plot2};
choose_plot2 = {ani_plot12,ani_plot22};
choose_plot3 = {ani_plot3,ani_plot4};
choose_plot4 = {ani_plot33,ani_plot44};
choose_plot5 = {ani_plot5,ani_plot6};
choose_plot6 = {ani_plot55,ani_plot66};

legend(ax1, 'Method 1 TC', 'Method 2 TC')
legend(ax2, 'Method 1 TC', 'Method 2 TC')
legend(ax3, 'curv\_AA1\_m1', 'curv\_AA2\_m1', 'curv\_AA1\_m2','curv\_AA2\_m2')
legend(ax4, 'curv\_AA1\_m1', 'curv\_AA2\_m1', 'curv\_AA1\_m2','curv\_AA2\_m2')


%% data process
for j = [1,2,7,3,4,5,8,9,10,6,11]
    diff = data(j,:) - ref;
    % diff is one row of data
    
    for i = 1:size(A_index,2)
        % active area number
        % get calibration matrix
        % convert to 2*3 and 2*2
        A = H{i}';
        A12 = H12{i}';
        A13 = H13{i}';
        A23 = H23{i}';
        alpha_m1 = [];
    
        % temperature compensation process, method 1
        % convert to 2*n
        KA = A*diff(A_index{i})'; % curvatures without temperature compensation
        K23 = A23*E1*diff(A_index{i})';
        K13 = A13*E2*diff(A_index{i})';
        K12 = A12*E3*diff(A_index{i})';
    
        % Naieve pseudoinverse method
        A_aug = [A - A23*E1; A - A13*E2; A - A12*E3]*ratios(:,i); 
        K_aug = [KA - K23; KA - K13; KA - K12];
    
        calc_temp_wave_change = pinv(A_aug)*K_aug;
        %disp('calculated wavelengh shifts due to temperature variation')
        %calc_temp_wave_changes = calc_temp_wave_change * ratios;
        %disp(calc_temp_wave_changes);
        alpha_m1 = calc_temp_wave_change;
        cur_pred = A*(diff(A_index{i})' - alpha_m1 * ratios(:,i));

        addpoints(choose_plot1{i},seq_cur(j),alpha_m1);
        addpoints(choose_plot3{i},seq_cur(j),cur_pred(1));
        addpoints(choose_plot5{i},seq_cur(j),cur_pred(2));
        % temperature compensation process, method 2
        diff_mode = mean(diff(A_index{i}));
        cur_pred2 = A*(diff(A_index{i})' - diff_mode);
        addpoints(choose_plot2{i},seq_cur(j),diff_mode);
        addpoints(choose_plot4{i},seq_cur(j),cur_pred2(1));
        addpoints(choose_plot6{i},seq_cur(j),cur_pred2(2));
%         disp("-----")
%         disp(cur_pred)
%         disp(cur_pred2)

    end
end