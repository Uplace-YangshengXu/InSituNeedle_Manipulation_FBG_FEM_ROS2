#include <rclcpp/rclcpp.hpp>
//#include <assignment1_msgs/srv/find_norm.hpp>
#include <example_interfaces/srv/add_two_ints.hpp>


namespace assignment1{
    class client : public rclcpp::Node{
        private:
            rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedPtr assignment1_client;
        public:
            client(const std::string& name);
            void call (int a, int b);
            void callback(const rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedFuture future);
    };
}