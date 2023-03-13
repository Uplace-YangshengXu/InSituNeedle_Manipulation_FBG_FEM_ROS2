function [dis, slp] = extract_from_2d(d)
% Extract 2D displacement and slope information from the DOF array
dis = d(1:2:end);
slp = d(2:2:end);
end