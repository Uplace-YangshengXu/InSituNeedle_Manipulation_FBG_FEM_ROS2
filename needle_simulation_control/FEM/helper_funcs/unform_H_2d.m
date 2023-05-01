function [x, y, k] = unform_H_2d(Hs)
% Given a list of SE(2) elements, form a series of corresponding x, y and
% slopes k. x, y, and k are 1xn

n_points = size(Hs, 2)/3;
x = zeros(1, n_points);
y = zeros(1, n_points);
theta = zeros(1, n_points);
for i = 1:n_points
    H = Hs(1:3, 3*i - 2:3*i);
    t = H(1:2, 3);
    R = H(1:2, 1:2);
    x(i) = t(1);
    y(i) = t(2);
    theta(i) = atan2(R(2, 1), R(1, 1)); 
end
k = gradient_radian_conversion(theta, 'r2g');