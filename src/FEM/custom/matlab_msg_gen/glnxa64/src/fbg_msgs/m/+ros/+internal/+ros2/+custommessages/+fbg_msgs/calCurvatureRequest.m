function [data, info] = calCurvatureRequest
%CalCurvature gives an empty data for fbg_msgs/CalCurvatureRequest
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'fbg_msgs/CalCurvatureRequest';
[data.command, info.command] = ros.internal.ros2.messages.ros2.char('string',1,NaN,0);
info.MessageType = 'fbg_msgs/CalCurvatureRequest';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,1);
info.MatPath{1} = 'command';
