function ros1msg = assignment1_msgs_msg_Command_2To1_Converter(message,ros1msg)
%assignment1_msgs_msg_Command_2To1_Converter passes data of ROS 2 message to ROS message.
% Copyright 2019 The MathWorks, Inc.    
ros1msg.Name = message.name{1};
end