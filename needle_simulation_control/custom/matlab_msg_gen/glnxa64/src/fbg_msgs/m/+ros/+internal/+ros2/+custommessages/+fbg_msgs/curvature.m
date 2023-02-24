function [data, info] = curvature
%Curvature gives an empty data for fbg_msgs/Curvature
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'fbg_msgs/Curvature';
[data.curvature_xy, info.curvature_xy] = ros.internal.ros2.messages.ros2.default_type('double',NaN,0);
[data.curvature_xz, info.curvature_xz] = ros.internal.ros2.messages.ros2.default_type('double',NaN,0);
info.MessageType = 'fbg_msgs/Curvature';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,2);
info.MatPath{1} = 'curvature_xy';
info.MatPath{2} = 'curvature_xz';
