function [wy, wz, ty, tz] = extract_from_3d(d)
% Extract 2D displacement and slope information from the DOF array
% Following convention [wy1; wz1; ty1; tz1; ...]
wy = d(1:4:end);
wz = d(2:4:end);
ty = d(3:4:end);
tz = d(4:4:end);
end