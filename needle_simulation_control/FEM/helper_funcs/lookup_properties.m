function [MuTs, AlphaTs, GammaTs] = lookup_properties(x, PropertyTable)
% Create arrays of properties for each element based on element midpoint
% coordinate
x_mid = mean([x(1:end-1), x(2:end)], 2);
MuTs = zeros(size(x_mid));
AlphaTs = zeros(size(x_mid));
GammaTs = zeros(size(x_mid));

for i = 1:numel(PropertyTable.Interval)
    bools = (x_mid >= PropertyTable.Interval{i}(1)) & (x_mid < PropertyTable.Interval{i}(2));
    MuTs = MuTs + bools*PropertyTable.MuT(i);
    AlphaTs = AlphaTs + bools*PropertyTable.AlphaT(i);
    GammaTs = GammaTs + bools*PropertyTable.GammaT(i);
end
AlphaTs(abs(AlphaTs) < 1) = -1;
end
