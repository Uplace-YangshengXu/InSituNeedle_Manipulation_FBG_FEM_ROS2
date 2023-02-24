node_2 = ros2node("/node_2");

sub = ros2subscriber(node_2,"/foo"); % create subscriber

disp(sub.LatestMessage) % message can be accessed in this way

while 1

[msg_received, status, statustext] = receive(sub,10) 
disp(msg_received)% but this way does not work
pause(0.1)

end