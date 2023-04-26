% matlab service and client
classdef MatlabRosSrvCli
    properties
    srv
    cli
    request
    end
    methods
        function obj = MatlabRosSrvCli(node_type,node_name,service_name,service_type)
            node = ros2node(node_name);
            if node_type == 'server'
               disp("only used for client"); 
            end

            if node_type == 'client'
                obj.cli = ros2svcclient(node,service_name,service_type);
                obj.request = ros2message(obj.cli);
                obj.request.name = "request";
            end
        end
        
        function curvature = getResponseMsg(obj)           
            response = call(obj.cli,obj.request);
            curvature = response.curvature;      
        end
        
        function delete(obj)
            delete(obj.srv)
            delete(obj.cli)
            delete(obj.cli)
        end
    end
end