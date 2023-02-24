function [data, info] = fbgReading
%FbgReading gives an empty data for fbg_msgs/FbgReading
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'fbg_msgs/FbgReading';
[data.signal_reading, info.signal_reading] = ros.internal.ros2.messages.ros2.default_type('double',NaN,0);
info.MessageType = 'fbg_msgs/FbgReading';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,1);
info.MatPath{1} = 'signal_reading';
