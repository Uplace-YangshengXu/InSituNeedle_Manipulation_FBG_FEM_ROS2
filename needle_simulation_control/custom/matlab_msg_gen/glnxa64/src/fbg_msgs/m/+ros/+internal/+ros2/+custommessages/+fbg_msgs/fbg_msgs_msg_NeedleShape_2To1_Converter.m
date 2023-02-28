function ros1msg = fbg_msgs_msg_NeedleShape_2To1_Converter(message,ros1msg)
%fbg_msgs_msg_NeedleShape_2To1_Converter passes data of ROS 2 message to ROS message.
% Copyright 2019 The MathWorks, Inc.    
ros1msg.NeedleTotalLength = message.needle_total_length;
end