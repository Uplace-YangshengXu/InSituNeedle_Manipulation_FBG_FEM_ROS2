#include <rclcpp/rclcpp.hpp>
#include <assignment1_msgs/msg/command.hpp>

namespace assignment1{

    class publisher : public rclcpp::Node{

        private:
            rclcpp::Publisher<assignment1_msgs::msg::Command>::SharedPtr assignment1_publisher;

        public:

            publisher( const std::string& name);
            void publish( const std::string& name);

    };

}