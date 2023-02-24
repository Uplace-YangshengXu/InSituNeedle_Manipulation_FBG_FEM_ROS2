#include <assignment1_subpub/subscriber.hpp>

namespace assignment1{
    
    subscriber::subscriber(const std::string& name):
    Node(name){
        assignment1_subscriber = create_subscription<assignment1_msgs::msg::Command>("foo",
                                10,
                                std::bind(&subscriber::callback,this,std::placeholders::_1));

    }
    void subscriber::callback(const assignment1_msgs::msg::Command command){
        std::cout << command.name << std::endl;
        std::cout << "connected" <<std::endl;

    }
} 
