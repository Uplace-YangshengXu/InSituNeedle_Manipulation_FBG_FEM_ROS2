#include <assignment1_srvcli/client.hpp>

int main( int argc, char** argv){
    
    rclcpp::init( argc, argv);
    std::shared_ptr<assignment1::client> client = std::make_shared<assignment1::client>("cli");
    //geometry_msgs::msg::Vector3 v;
    //v.x = 1;
    //v.y = 2;
    //v.z = 3;
    int a = 1;
    int b = 1;
    client->call(a,b);
    rclcpp::spin(client);
    rclcpp::shutdown();

    return 0;
}