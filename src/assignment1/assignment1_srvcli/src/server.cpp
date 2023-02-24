#include <assignment1_srvcli/server.hpp>

namespace assignment1{

    service::service(const std::string& name):
        Node(name){
        assignment1_service = create_service<example_interfaces::srv::AddTwoInts>("test",
                                std::bind(&service::callback,this,std::placeholders::_1,std::placeholders::_2));
        }

    void service::callback(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
                            std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response){
        
        //response-> norm = sqrt(pow(request->vector.x,2)+pow(request->vector.y,2)+pow(request->vector.z,2));
        response -> sum = request-> a;
        std::cout << request->a << std::endl;
        std::cout << "service: received" <<std::endl;
        std::cout << "service: done" << std:: endl;
        }
  
}