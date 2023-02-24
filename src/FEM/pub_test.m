node_1 = ros2node("/node_1");

pub = ros2publisher(node_1,"/foo","assignment1_msgs/Command"); % create publisher

msg = ros2message("assignment1_msgs/Command"); % create message structure
msg.name = char("name");

while 1
    send(pub,msg) % send message
    pause(0.1)
end