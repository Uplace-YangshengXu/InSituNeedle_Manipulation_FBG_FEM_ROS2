function [data, info] = findNormRequest
%FindNorm gives an empty data for assignment1_msgs/FindNormRequest
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'assignment1_msgs/FindNormRequest';
[data.input, info.input] = ros.internal.ros2.messages.ros2.default_type('double',1,0);
info.MessageType = 'assignment1_msgs/FindNormRequest';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,1);
info.MatPath{1} = 'input';
