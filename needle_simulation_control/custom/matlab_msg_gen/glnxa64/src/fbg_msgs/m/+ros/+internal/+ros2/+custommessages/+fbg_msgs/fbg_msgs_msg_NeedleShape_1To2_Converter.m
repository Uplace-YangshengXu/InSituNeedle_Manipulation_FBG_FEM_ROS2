function ros2msg = fbg_msgs_msg_NeedleShape_1To2_Converter(message,ros2msg)
%fbg_msgs_msg_NeedleShape_1To2_Converter passes data of ROS message to ROS 2 message.
% Copyright 2019 The MathWorks, Inc.
ros2msg.needle_total_length = message.NeedleTotalLength;
end