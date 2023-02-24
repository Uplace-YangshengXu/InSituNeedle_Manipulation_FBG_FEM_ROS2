#include <rclcpp/rclcpp.hpp>
#include <assignment1_msgs/msg/command.hpp>

namespace assignment1{

    class subscriber : public rclcpp::Node{
        private:
            rclcpp::Subscription<assignment1_msgs::msg::Command>::SharedPtr assignment1_subscriber;
        
        public:
            subscriber(const std::string& name);
            void callback(const assignment1_msgs::msg::Command command);

    };
}