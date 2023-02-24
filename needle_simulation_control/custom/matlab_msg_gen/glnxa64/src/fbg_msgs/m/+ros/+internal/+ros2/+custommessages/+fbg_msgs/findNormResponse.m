function [data, info] = findNormResponse
%FindNorm gives an empty data for fbg_msgs/FindNormResponse
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'fbg_msgs/FindNormResponse';
[data.norm, info.norm] = ros.internal.ros2.messages.ros2.default_type('double',1,0);
info.MessageType = 'fbg_msgs/FindNormResponse';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,1);
info.MatPath{1} = 'norm';
