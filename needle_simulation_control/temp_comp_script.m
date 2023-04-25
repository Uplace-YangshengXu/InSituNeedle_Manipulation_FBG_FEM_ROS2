clear;
%% Some constants to play with
wave_change_ratios = [1; 2; 3]; % just a random temperature-wavelength change ratio obtained by experiment
bend_change_ratios = @bend_wave_ratios; % some bend-wavelength change ratio obtained by geometry
ratios_noise = 0.3; % some unknown magnitude difference from experimental values
calibration_noise_mag = 0.2; % noise coming into calibration signals
A = rand(2, 3); % assumed calibration matrix
single_plane = false; % if calibration and bending is performed on the same plane

%% Calibration; No temperature variation
n = 50;
del_wave_calibration = zeros(3, n);
K_calibration = zeros(2, n);
th = 2*pi*(rand() - 0.5); % calibration on the same plane
for i = 1:n
    if ~single_plane
        th = 2*pi*(rand() - 0.5); % calibration on different planes
    end
    del_wave_calibration(:, i) = bend_change_ratios(th)*rand() + calibration_noise_mag*rand(3, 1); % generate signals due to bending
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

ratios_actual = wave_change_ratios + ratios_noise; % actual temperature-wavelength change ratio during measurements
temp_change = rand();
disp('random temperature change in degrees')
disp(temp_change);

temp_wave_changes = ratios_actual*temp_change; % wavelength changes due to temperature changes
if ~single_plane
    th = 2*pi*(rand() - 0.5); % bending on a random plane
end
bend_wave_change = bend_change_ratios(th)*rand(); % wavelength changes due to bending
disp('random wavelength shifts due to temperature variation')
disp(temp_wave_changes);

del_actual = bend_wave_change + temp_wave_changes; % total change in wavelength (bending + temperature)
K_actual = A*del_actual; % curvatures without temperature compensation

% Temperature compensation routine
K1 = A1*E1*del_actual;
K2 = A2*E2*del_actual;
K3 = A3*E3*del_actual;

% Naieve pseudoinverse method
A_aug = [A - A1*E1; A - A2*E2; A - A3*E3]*wave_change_ratios;
K_aug = [K_actual - K1; K_actual - K2; K_actual - K3];
calc_temp_change = pinv(A_aug)*K_aug;
disp('calculated temperature change in degrees')
disp(calc_temp_change)
disp('calculated wavelengh shifts due to temperature variation')
calc_temp_wave_changes = calc_temp_change * wave_change_ratios;
disp(calc_temp_wave_changes);

% JK's diagonal average method
b1 = K_actual - K1;
b2 = K_actual - K2;
b3 = K_actual - K3;

x1 = (A - A1*E1)*wave_change_ratios;
x2 = (A - A2*E2)*wave_change_ratios;
x3 = (A - A3*E3)*wave_change_ratios;

temp_wave_change_calc = [b1 b2 b3]/[x1 x2 x3];
temp_wave_avg = 0.5*(temp_wave_change_calc(1, 1) + temp_wave_change_calc(2, 2));
disp('JK calculated wavelength shifts')
calc_temp_wave_changes_JK = temp_wave_avg*wave_change_ratios;
disp(calc_temp_wave_changes_JK)

%% Bending-Wavelength ratio
function ratios = bend_wave_ratios(theta)
ratios = [sin(theta); -sin(pi/3 + theta); sin(pi/3 - theta)]; % geometric argument
% ratios = [2; 2.5; -1]; % random ratio
end