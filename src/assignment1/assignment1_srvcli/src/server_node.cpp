#include <assignment1_srvcli/server.hpp>

int main( int argc, char** argv){

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<assignment1::service>("srv"));
    rclcpp::shutdown();

    return 0;
}