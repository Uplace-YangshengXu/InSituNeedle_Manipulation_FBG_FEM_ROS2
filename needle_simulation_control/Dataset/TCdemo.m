% create at 20/03/2023 by yangsheng xu
% this script provides a demo to test the Temperature Compensation
% principle using AA1 and AA2 of three Channel needle

load Cal_mat_2CH_2AA_alldata_A12.mat % H12 CS
load Cal_mat_2CH_2AA_alldata_A13.mat % H13 CS
load Cal_mat_2CH_2AA_alldata_A23.mat % H23 CS
load Cal_mat_3CH_2AA_alldata.mat % H
A_index = {[1,5,9],[2,6,10]}; %3ch 2aa
A12_index = {[1,5],[2,6]};
A13_index = {[1,9],[2,10]};
A23_index = {[5,9],[6,10]};
E1 = [0 1 0; 0 0 1]; % for A23
E2 = [1 0 0; 0 0 1]; % for A13
E3 = [1 0 0; 0 1 0]; % for A12
ratio = [1;1;1]; % assume the temp effect is 1:1:1 for each channel

namefile = 'temp_fbg_data.xls';
sheet_name = 'Temp_vari_data';
% data file
% format
% 1st unbent data
% 2nd bend data with room temp
% 3rd-end bend data with various temp

data = readmatrix(namefile,'Sheet',sheet_name);
[r,c ] = size(data); % row and col
ref = data(1,:);
diff = data(2:end,:) - ref;

%% data process

for i = size(A_index,2)
    % active area number
    % get calibration matrix
    % and convert to 2*3
    A = H{i}';
    A12 = H12{i}';
    A13 = H13{i}';
    A23 = H23{i}';

    cur_m1 = [];
    cur_m2 = [];
    alpha_m1 = [];
    alpha_m2 = [];

    % temperature compensation process
    % and converting to 2 * n by converting data
    KA = A * diff(:,A_index{i})'; % curvatures without temperature compensation

    K23 = A23 * E1*diff(:,A_index{i})';
    K13 = A13 * E2*diff(:,A_index{i})';
    K12 = A12 * E3*diff(:,A_index{i})';

    % Naieve pseudoinverse method
    A_aug = [A - A23*E1; A - A13*E2; A - A12*E3]*ratios; 
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
    
    x1 = (A - A23*E1)*ratios;
    x2 = (A - A13*E2)*ratios;
    x3 = (A - A12*E3)*ratios;
    
    temp_wave_change_calc = [b1 b2 b3]/[x1 x2 x3];
    temp_wave_avg = 0.5*(temp_wave_change_calc(1, 1) + temp_wave_change_calc(2, 2));

    alpha_m2 = [alpha_m2,temp_wave_avg];

    % get the compensated curvature
    cur_m1 = [cur_m1, A*(diff(A_index{i}) - alpha_m1 * ratio')];
    cur_m2 = [cur_m2, A*(diff(A_index{i}) - alpha_m2 * ratio')];

    % plotting 
    figure(i)
    plot(cur_m1(1,:))
    hold on
    plot(cur_m2(1,:))
    legend("cur_xy_method1","cur_xy_method2")
    title("curv in xy plane")
    hold off

    figure(i+2)
    plot(cur_m1(2,:))
    hold on
    plot(cur_m2(2,:))
    legend("cur_xz_method1","cur_xz_method2")
    title("curv in xz plane")
    hold off


end


