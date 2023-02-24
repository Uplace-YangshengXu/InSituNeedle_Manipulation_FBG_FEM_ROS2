#include <assignment1_subpub/publisher.hpp>

namespace assignment1{

    publisher::publisher(const std::string& name):
    Node(name){
        assignment1_publisher = create_publisher<assignment1_msgs::msg::Command>("foo",10);

    }

    void publisher::publish( const std::string& name){
        
        assignment1_msgs::msg::Command command;
        command.name = name;
        //command.t = twist;
        assignment1_publisher->publish(command);

    }

}