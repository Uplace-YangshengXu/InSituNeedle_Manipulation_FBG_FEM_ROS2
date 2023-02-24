#include <assignment1_srvcli/client.hpp>

namespace assignment1{

    client::client(const std::string& name):
        Node(name){
            assignment1_client = create_client<example_interfaces::srv::AddTwoInts>("test");
            std::cout<< "client: wait for service" << std::endl;
            assignment1_client -> wait_for_service();
            std::cout << "client: ready" << std::endl;
        }
    void client::call(int a, int b){
        auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
        request-> a = a;
        request-> b = b;
        std::cout << "client: sending" << std::endl;
        assignment1_client -> async_send_request( request, std::bind(&client::callback, this, std::placeholders::_1));
        std::cout << "client: sent" <<std::endl;
    }
    void client::callback(const rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedFuture future){
        std::cout << "client: callback" <<std::endl;
        auto response = future.get();
        std::cout << "The norm is" << response->sum << std::endl;
    }
}