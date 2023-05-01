function Hs = form_H_2d(x, y, k)
% Given a 3x3n list of x, y, and slopes k, form a series of corresponding SE(2)
% elements. x, y and k are n-vectors

n_points = numel(x);
Hs = zeros(3, 3*n_points);
thetas = gradient_radian_conversion(k, 'g2r');
for i = 1:n_points    
    R = [cos(thetas(i)), -sin(thetas(i));
     sin(thetas(i)), cos(thetas(i))];
    Hs(:, 3*i - 2:3*i) = [R, [x(i); y(i)]; 0, 0, 1];
end
end