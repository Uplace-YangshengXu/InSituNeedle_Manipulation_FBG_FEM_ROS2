function K = add_corners(K, M2)
% Add a 2x2 matrix M2 to the corners of a matrix K; used when assembling
% independent ke's in xy and xz direction to the element stiffness matrix
% during bi-planar bending

K(1, 1) = M2(1, 1);
K(1, end) = M2(1, end);
K(end, 1) = M2(end, 1);
K(end, end) = M2(end, end);
end