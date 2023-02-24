function [data, info] = command
%Command gives an empty data for assignment1_msgs/Command
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'assignment1_msgs/Command';
[data.name, info.name] = ros.internal.ros2.messages.ros2.char('string',1,NaN,0);
info.MessageType = 'assignment1_msgs/Command';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,1);
info.MatPath{1} = 'name';
