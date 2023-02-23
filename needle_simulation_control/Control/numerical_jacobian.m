function J = numerical_jacobian(f, x, n_out)
eps = 1e-5;
eps_inv = 1/eps;

n_in = length(x);
J = zeros(n_out, n_in);

for i = 1:n_in
    xplus = x;
    xminus = x;
    xplus(i) = xplus(i) + eps;
    xminus(i) = xminus(i) - eps;
    J(:, i) = 0.5 * eps_inv * (feval(f, xplus) - feval(f, xminus));
end
end