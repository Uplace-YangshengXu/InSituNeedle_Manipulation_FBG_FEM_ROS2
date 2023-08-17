function [Mus, Alphas, Gammas, Tis] = lookup_properties(x, PropertyTable)
% Create arrays of properties for each element based on element midpoint
% coordinate
x_mid = mean([x(1:end-1), x(2:end)], 2);
Mus = zeros(size(x_mid));
Alphas = zeros(size(x_mid));
Gammas = zeros(size(x_mid));
Tis = zeros(size(x_mid));

for i = 1:numel(PropertyTable.Interval)
    bools = (x_mid >= PropertyTable.Interval{i}(1)) & (x_mid < PropertyTable.Interval{i}(2));
    Mus = Mus + bools*PropertyTable.Mu(i);
    Alphas = Alphas + bools*PropertyTable.Alpha(i);
    Gammas = Gammas + bools*PropertyTable.Gamma(i);
    Tis = Tis + bools*PropertyTable.Ti(i);
end
Alphas(abs(Alphas) < 1) = -1;
end
