clear;
clc;
%% Some constants to play with
gt_temp_ratios = [0.2; 0.5; 1]; % ground truth temperature-wavelength change ratio
gt_bend_ratios = @bend_wave_ratios; % ground truth bend-wavelength change ratio obtained by geometry
A = randn(2, 3); % assumed grount truth calibration matrix
single_plane = false; % if calibration and bending is performed on the same plane
temp_ratios_uncert_mag = 0.0; % uncertainty in temperature variation ratios
bend_ratios_uncert_mag = 0.0; % uncertainty in bending signal ratios
sensor_noise_mag = 0; % signal noise in general

%% Calibration; No temperature variation
n = 500;
del_wave_calibration = zeros(3, n);
K_calibration = zeros(2, n);
th = 2*pi*(randn() - 0.5); % calibration on the same plane
for i = 1:n
    if ~single_plane
%         th = 2*pi*(randn() - 0.5); % calibration on different planes
        th = pi/2*mod(i, 2); % bending in two planes
    end
    del_wave_calibration(:, i) = (gt_bend_ratios(th) + bend_ratios_uncert_mag*randn(3, 1))*randn() + sensor_noise_mag*randn(3, 1); % generate signals due to bending
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
temp_change = 20; % ground truth temperature variation
gt_temp_wave_change = gt_temp_ratios*temp_change; % ground truth wavelength changes due to temperature changes
disp('ground truth wavelength shifts due to temperature variation')
disp(gt_temp_wave_change);

if ~single_plane
    th = 2*pi*(randn() - 0.5); % bending on a randnom plane
end

wave_change_ratios_exp = gt_temp_ratios + temp_ratios_uncert_mag*randn(3, 1); % experiment temperature-wavelength change ratio
bend_change_ratios_exp = gt_bend_ratios(th) + bend_ratios_uncert_mag*randn(3, 1); % experiment bending-wavelength change ratio

temp_wave_change_exp = wave_change_ratios_exp*temp_change; % experiment wavelength changes due to temperature variation
bend_wave_change_exp = bend_change_ratios_exp*randn(); % experiment wavelength changes due to bending

del_wave_exp = bend_wave_change_exp + temp_wave_change_exp + sensor_noise_mag*randn(3, 1); % total change in wavelength during experiment (bending + temperature)
K_exp = A*del_wave_exp; % curvatures without temperature compensation

% Temperature compensation routine
K1 = A1*E1*del_wave_exp;
K2 = A2*E2*del_wave_exp;
K3 = A3*E3*del_wave_exp;

% Naieve pseudoinverse method
A_aug = [A - A1*E1; A - A2*E2; A - A3*E3];
K_aug = [K_exp - K1; K_exp - K2; K_exp - K3];
calc_temp_change = pinv(A_aug*wave_change_ratios_exp)*K_aug;

disp('calculated wavelengh shifts due to temperature variation')
calc_temp_wave_changes = calc_temp_change * wave_change_ratios_exp;
disp(calc_temp_wave_changes);

% Reduced-Naieve pseudoinverse mthod
A_aug_reduced = (A1*E1 - A2*E2);
K_aug_reduced = K1 - K2;
calc_temp_change_reduced = pinv(A_aug_reduced*wave_change_ratios_exp)*K_aug_reduced;

disp('reduced calculated wavelengh shifts due to temperature variation')
calc_temp_wave_changes_reduced = calc_temp_change_reduced * wave_change_ratios_exp;
disp(calc_temp_wave_changes_reduced);


% JK's diagonal average method
b1 = K_exp - K1;
b2 = K_exp - K2;
b3 = K_exp - K3;

x1 = (A - A1*E1)*wave_change_ratios_exp;
x2 = (A - A2*E2)*wave_change_ratios_exp;
x3 = (A - A3*E3)*wave_change_ratios_exp;

temp_wave_change_mat = [b1 b2 b3]/[x1 x2 x3];
temp_wave_avg = 0.5*(temp_wave_change_mat(1, 1) + temp_wave_change_mat(2, 2));
disp('JK calculated wavelength shifts')
calc_temp_wave_changes_JK = temp_wave_avg*wave_change_ratios_exp;
disp(calc_temp_wave_changes_JK)

%% Bending-Wavelength ratio
function ratios = bend_wave_ratios(theta)
ratios = [sin(theta); -sin(pi/3 + theta); sin(pi/3 - theta)]; % geometric argument
% ratios = [2; 2.5; -1]; % randnom ratio
% ratios = randn(3, 1);
end