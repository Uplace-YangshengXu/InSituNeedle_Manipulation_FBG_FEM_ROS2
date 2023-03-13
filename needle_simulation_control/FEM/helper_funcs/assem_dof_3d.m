function d = assem_dof_3d(wy, wz, ty, tz)
% Re-assemble the 3D DOF from wy, wz, ty, tz arrays
d = reshape([wy, wz, ty, tz]', [], 1);
end