function [data, info] = calCurvatureResponse
%CalCurvature gives an empty data for fbg_msgs/CalCurvatureResponse
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'fbg_msgs/CalCurvatureResponse';
[data.curvature, info.curvature] = ros.internal.ros2.custommessages.fbg_msgs.curvature;
info.curvature.MLdataType = 'struct';
info.MessageType = 'fbg_msgs/CalCurvatureResponse';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,3);
info.MatPath{1} = 'curvature';
info.MatPath{2} = 'curvature.curvature_xy';
info.MatPath{3} = 'curvature.curvature_xz';
