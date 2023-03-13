function d = assem_dof_2d(u, k)
% Re-assemble the 2D DOF from u and k arrays
d = reshape([u, k]', [], 1);
end