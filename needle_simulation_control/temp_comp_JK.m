clear;
%% Calibration; No temperature variation
A = rand(2, 3); % assumed calibration matrix
ratios = [1; 2; -1]; % just a random ratio

n = 10;
del_wave_calibration = zeros(3, n);
K_calibration = zeros(2, n);
% th = 2*pi*(rand()-0.5); % calibration on the same plane
for i = 1:n
    th = 2*pi*(rand()-0.5); % calibration on different planes
    del_wave_calibration(:, i) = [sin(th),-sin(pi/3+th),sin(pi/3-th)]'*rand(); % generate signals due to bending
    K_calibration(:, i) = A*del_wave_calibration(:, i); % curvtures due to bending only
end

del_calibration_1 = [del_wave_calibration(2, :); del_wave_calibration(3, :)];
del_calibration_2 = [del_wave_calibration(1, :); del_wave_calibration(3, :)];
del_calibration_3 = [del_wave_calibration(1, :); del_wave_calibration(2, :)];

E1 = [0 1 0; 0 0 1];
E2 = [1 0 0; 0 0 1];
E3 = [1 0 0; 0 1 0];

A1 = K_calibration*pinv(del_calibration_1);
A2 = K_calibration*pinv(del_calibration_2);
A3 = K_calibration*pinv(del_calibration_3);

% Can verify (A - Ai*Ei)*del_wave_calibration(:, j) is approx 0's

%% Temperature compensation during measurements
clc
disp('random wavelength shifts due to temperature variation')
% temp_wave_change = rand(3, 1); % wavelength changes due to temperature changes
temp_wave_change = rand()*ones(3,1); % wavelength changes due to temperature changes
th = 2*pi*(rand()-0.5); % bending on a random plane
bend_wave_change = [sin(th),-sin(pi/3+th),sin(pi/3-th)]'*rand(); % wavelength changes due to bending
disp(temp_wave_change);

del_actual = bend_wave_change + temp_wave_change; % total change in wavelength (bending + temperature)
K_actual = A*del_actual; % curvatures
K1 = A1*E1*del_actual;
K2 = A2*E2*del_actual;
K3 = A3*E3*del_actual;


A_aug = [A - A1*E1; A - A2*E2; A - A3*E3];
K_aug = [K_actual - K1; K_actual - K2; K_actual - K3];
calc_temp_wave_change = pinv(A_aug)*K_aug;
disp('calculated wavelengh shifts due to temperature variation')
disp(calc_temp_wave_change);