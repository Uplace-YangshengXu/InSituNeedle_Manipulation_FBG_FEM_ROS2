% Needle constants
E = 200*1000; % 200GPa but in mm^2
OD = 1.27;
I = pi/4*(OD/2)^4; % in mm^4

% Tissue constants
ti = 25; % initial length of the tissue

% Load-stepping
max_inner_iter = 50; % maximum number of iterations for Newton's method
max_outer_iter = 5; % maximum number of iteratinos for load stepping
tol = 1e-3;

% Constraint interval
constraint_interval = 0.1;

% Bevel slope. Experimental. Keep bevel value as zero
bevel = 0;