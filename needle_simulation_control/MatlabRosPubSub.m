% matlab publisher

classdef MatlabRosPubSub
    properties
        pub
        sub
    end

    methods
        function obj = MatlabRosPubSub(node_type,node_name,topic_name,msg_type)
            node = ros2node(node_name);
            if node_type == 'pub'
                obj.pub = ros2publisher(node,topic_name,msg_type,'Depth',10);
            end

            if node_type == 'sub'
                obj.sub = ros2subscriber(node,topic_name);
            end
        end

        function [msg_received,status,statustext] = getSubMsg(obj,quality)
            [msg_received,status,statustext] = receive(obj.sub,quality);
        end

        function sendPubMsg(obj,msg)
            send(obj.pub,msg)
        end
    end
end