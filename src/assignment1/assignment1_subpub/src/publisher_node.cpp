#include <assignment1_subpub/publisher.hpp>

int main(int argc, char** argv){

    rclcpp::init(argc,argv);
    assignment1::publisher publisher("pub");
    rclcpp::Rate rate(1);

    while(rclcpp::ok()){
        
        publisher.publish("car");
        rate.sleep();
    }
    rclcpp::shutdown();
    return 0;

}