% create at 20/03/2023 by yangsheng xu
% this script provides a demo to test the Temperature Compensation
% principle using AA1 and AA2 of three Channel needle
clear;
clc;

addpath ../calibration_process
addpath ./temp_demo_data/

load Cal_mat_2CH_2AA_alldata_A12.mat % H12 CS
load Cal_mat_2CH_2AA_alldata_A13.mat % H13 CS
load Cal_mat_2CH_2AA_alldata_A23.mat % H23 CS
load Cal_mat_3CH_2AA_alldata.mat % H
load temp_comp_ratios.mat % ratio_AA1 ratio_AA2



A_index = {[1,5,9],[2,6,10]}; %3ch 2aa
A12_index = {[1,5],[2,6]};
A13_index = {[1,9],[2,10]};
A23_index = {[5,9],[6,10]};
E1 = [0 1 0; 0 0 1]; % for A23
E2 = [1 0 0; 0 0 1]; % for A13
E3 = [1 0 0; 0 1 0]; % for A12
% ratios = ones(3,2);
ratios = [ratio_AA1 ratio_AA2]
%ratios = [[1;1;1] ratio_AA2];

%namefile = 'temp_fbg_data2.xls'; % Apr 24 2023, using hot water steam, straight needle
%namefile = 'temp_fbg_data3.xls'; % Apr 24 2023, using hot water steam, bent needle
% namefile = 'temp_fbg_data4.xls'; % Apr 24 2023, using incubator, 98.5F, straight needle
% namefile = 'temp_fbg_data5.xls'; % Apr 24 2023, using heat gun, straight needle
% namefile = 'temp_fbg_data6.xls'; % Apr 25 2023, using incubator, 101.0F, 2.0 needle
% namefile = 'temp_fbg_data7.xls'; % Apr 25 2023, using incubator, 101.0F, straight needle
% namefile = 'temp_fbg_data8.xls'; % Apr 25 2023, using incubator, 101.0F, 1.25 needle, decrease
% namefile = 'temp_fbg_data9.xls'; % Apr 25 2023, using incubator, 118.0F, 1.25 needle, decrease
% namefile = 'temp_fbg_datatest.xls'; % Apr 25 2023,free to 0.0 needle
% namefile = 'temp_fbg_data10.xls'; % Apr 25 2023, using incubator, 118.0F, free to 0.8 & 1.25 needle, decrease
% C0 -> 1; C1 -> 2; C2 -> 3; C3 -> 4;


namefile = 'tem_comp_Tvar_C0_prev.xls'; % Jun 19 2023, using incubator
%namefile = 'tem_comp_ground_truth.xls'
sheet_name = 'Temp_vari_data';
ref_data = readmatrix('tem_comp_Tvar_C0.xls','Sheet',sheet_name);
ref = ref_data(1,:);

% data file format
% 1st unbent data
% 2nd bend data with room temp
% 3rd-end bend data with various temp

data = readmatrix(namefile,'Sheet',sheet_name);
[r,c ] = size(data); % row and col



f = figure();
ax1 = subplot(2,2,1); grid on; % for AA1 cur_xy
ax2 = subplot(2,2,2); grid on; % for AA1 cur_xz
ax3 = subplot(2,2,3); grid on; % for AA2 cur_xy
ax4 = subplot(2,2,4); grid on; % for AA2 cur_xz
hold([ax1,ax2,ax3,ax4],'on')
xlabel([ax1,ax2,ax3,ax4],'timestamp')
ylabel([ax1,ax2,ax3,ax4],'curvature (m^-1)')
title(ax1,"AA1 curv xy")
title(ax2,'AA1 curv xz')
title(ax3,'AA2 curv xy')
title(ax4,'AA2 curv xz')

% plotting for TC method 1
ani_plot1 = animatedline(ax1,'Marker','o','Color','r');
ani_plot2 = animatedline(ax2,'Marker','o','Color','r');
ani_plot3 = animatedline(ax3,'Marker','o','Color','r');
ani_plot4 = animatedline(ax4,'Marker','o','Color','r');

% plotting for TC method 2
ani_plot12 = animatedline(ax1,'Marker','*','Color','g');
ani_plot22 = animatedline(ax2,'Marker','*','Color','g');
ani_plot32 = animatedline(ax3,'Marker','*','Color','g');
ani_plot42 = animatedline(ax4,'Marker','*','Color','g');

% plotting for NTC from A
ani_plot13 = animatedline(ax1,'Marker','+','Color','b');
ani_plot23 = animatedline(ax2,'Marker','+','Color','b');
ani_plot33 = animatedline(ax3,'Marker','+','Color','b');
ani_plot43 = animatedline(ax4,'Marker','+','Color','b');

% plotting for NTC from A12
% ani_plot14 = animatedline(ax,'Marker','+','Color','k');
% ani_plot24 = animatedline(ax2,'Marker','+','Color','k');
% ani_plot34 = animatedline(ax3,'Marker','+','Color','k');
% ani_plot44 = animatedline(ax4,'Marker','+','Color','k');

% plotting for NTC from A13
% ani_plot15 = animatedline(ax,'Marker','+','Color','c');
% ani_plot25 = animatedline(ax2,'Marker','+','Color','c');
% ani_plot35 = animatedline(ax3,'Marker','+','Color','c');
% ani_plot45 = animatedline(ax4,'Marker','+','Color','c');

% plotting for NTC from A23
% ani_plot16 = animatedline(ax,'Marker','+','Color','y');
% ani_plot26 = animatedline(ax2,'Marker','+','Color','y');
% ani_plot36 = animatedline(ax3,'Marker','+','Color','y');
% ani_plot46 = animatedline(ax4,'Marker','+','Color','y');

% legend(ax,'Method 1 TC','Method 2 TC','Without TC from A','Without TC from A12','Without TC from A13','Without TC from A23')
% legend(ax2,'Method 1 TC','Method 2 TC','Without TC from A','Without TC from A12','Without TC from A13','Without TC from A23')
% legend(ax3,'Method 1 TC','Method 2 TC','Without TC from A','Without TC from A12','Without TC from A13','Without TC from A23')
% legend(ax4,'Method 1 TC','Method 2 TC','Without TC from A','Without TC from A12','Without TC from A13','Without TC from A23')

legend(ax1, 'Method 1 TC', 'Method 2 TC', 'w/o TC')
legend(ax2, 'Method 1 TC', 'Method 2 TC', 'w/o TC')
legend(ax3, 'Method 1 TC', 'Method 2 TC', 'w/o TC')
legend(ax4, 'Method 1 TC', 'Method 2 TC', 'w/o TC')

%% data process
for j = 1:r
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
    
        cur_m1 = [];
        cur_m2 = [];
        cur_NTC_A = [];
        cur_NTC_A12 = [];
        cur_NTC_A13 = [];
        cur_NTC_A23 = [];
        alpha_m1 = [];
        alpha_m2 = [];
    
        % temperature compensation process
        % convert to 2*n
        KA = A*diff(A_index{i})'; % curvatures without temperature compensation
        
        K23 = A23*E1*diff(A_index{i})';
        K13 = A13*E2*diff(A_index{i})';
        K12 = A12*E3*diff(A_index{i})';

        % curvature without temperature compensation
        cur_NTC_A = KA;
        cur_NTC_A12 = K12;
        cur_NTC_A13 = K13;
        cur_NTC_A23 = K23;
    
        % Naieve pseudoinverse method
        A_aug = [A - A23*E1; A - A13*E2; A - A12*E3]*ratios(:,i); 
        K_aug = [KA - K23; KA - K13; KA - K12];
    
        calc_temp_wave_change = pinv(A_aug)*K_aug;
        %disp('calculated wavelengh shifts due to temperature variation')
        %calc_temp_wave_changes = calc_temp_wave_change * ratios;
        %disp(calc_temp_wave_changes);
        alpha_m1 = [alpha_m1,calc_temp_wave_change];
    
        % JK's diagonal average method
        b1 = KA - K23;
        b2 = KA - K13;
        b3 = KA - K12;
        
        x1 = (A - A23*E1)*ratios(:,i);
        x2 = (A - A13*E2)*ratios(:,i);
        x3 = (A - A12*E3)*ratios(:,i);
        
        temp_wave_change_calc = [b1 b2 b3]/[x1 x2 x3];
        temp_wave_avg = 0.5*(temp_wave_change_calc(1, 1) + temp_wave_change_calc(2, 2));
    
        alpha_m2 = [alpha_m2,temp_wave_avg];
    
        % get the compensated curvature
        cur_m1 = [cur_m1, A*(diff(A_index{i})' - alpha_m1 * ratios(:,i))]
        cur_m2 = [cur_m2, A*(diff(A_index{i})' - alpha_m2 * ratios(:,i))]

        % plotting 
        if i == 1
            % method 1
            addpoints(ani_plot1,j,cur_m1(1))
            addpoints(ani_plot2,j,cur_m1(2))
            % method 2
            addpoints(ani_plot12,j,cur_m2(1))
            addpoints(ani_plot22,j,cur_m2(2))

            % A
            addpoints(ani_plot13,j,cur_NTC_A(1))
            addpoints(ani_plot23,j,cur_NTC_A(2))
            % A12
            % addpoints(ani_plot14,j,cur_NTC_A12(1))
            % addpoints(ani_plot24,j,cur_NTC_A12(2))
            % A13
            % addpoints(ani_plot15,j,cur_NTC_A13(1))
            % addpoints(ani_plot25,j,cur_NTC_A13(2))
            % A23
            % addpoints(ani_plot16,j,cur_NTC_A23(1))
            % addpoints(ani_plot26,j,cur_NTC_A23(2))


        elseif i == 2
            addpoints(ani_plot3,j,cur_m1(1))
            addpoints(ani_plot4,j,cur_m1(2))
            addpoints(ani_plot32,j,cur_m2(1))
            addpoints(ani_plot42,j,cur_m2(2))

            % A
            addpoints(ani_plot33,j,cur_NTC_A(1))
            addpoints(ani_plot43,j,cur_NTC_A(2))
            % A12
            % addpoints(ani_plot34,j,cur_NTC_A12(1))
            % addpoints(ani_plot44,j,cur_NTC_A12(2))
            % A13
            % addpoints(ani_plot35,j,cur_NTC_A13(1))
            % addpoints(ani_plot45,j,cur_NTC_A13(2))
            % A23
            % addpoints(ani_plot36,j,cur_NTC_A23(1))
            % addpoints(ani_plot46,j,cur_NTC_A23(2))

        else

        end       
    end
end


