#include <rclcpp/rclcpp.hpp>
//#include <assignment1_msgs/srv/find_norm.hpp>
#include <example_interfaces/srv/add_two_ints.hpp>

namespace assignment1{
    class service : public rclcpp::Node{
        private:
            rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr assignment1_service;
        
        public:
            service(const std::string& name);
            void callback(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
                        std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response );    

    };
} // namespace
