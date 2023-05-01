function output = apply_transformations_2d(input, tf_mat)
% Apply transformation defined by tf_mat to a set of input vectors
% input: 3xn "points" as [x; y; k]
% output: transformed 3xn "points" as [x; y; k]

if isempty(input)
    output = [];
else
    H_in = form_H_2d(input(1, :), input(2, :), input(3, :));
    H_out = tf_mat*H_in;
    [out_x, out_y, out_k] = unform_H_2d(H_out);
    output = [out_x; out_y; out_k];
end