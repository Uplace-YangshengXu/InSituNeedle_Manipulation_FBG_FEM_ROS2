function [data, info] = needleShape
%NeedleShape gives an empty data for fbg_msgs/NeedleShape
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'fbg_msgs/NeedleShape';
[data.needle_total_length, info.needle_total_length] = ros.internal.ros2.messages.ros2.default_type('uint8',1,0);
[data.active_area_location, info.active_area_location] = ros.internal.ros2.messages.ros2.default_type('double',NaN,0);
[data.needle_x_axis, info.needle_x_axis] = ros.internal.ros2.messages.ros2.default_type('double',NaN,0);
[data.needle_y_axis, info.needle_y_axis] = ros.internal.ros2.messages.ros2.default_type('double',NaN,0);
[data.needle_z_axis, info.needle_z_axis] = ros.internal.ros2.messages.ros2.default_type('double',NaN,0);
[data.needle_slope, info.needle_slope] = ros.internal.ros2.messages.ros2.default_type('double',NaN,0);
info.MessageType = 'fbg_msgs/NeedleShape';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,6);
info.MatPath{1} = 'needle_total_length';
info.MatPath{2} = 'active_area_location';
info.MatPath{3} = 'needle_x_axis';
info.MatPath{4} = 'needle_y_axis';
info.MatPath{5} = 'needle_z_axis';
info.MatPath{6} = 'needle_slope';
