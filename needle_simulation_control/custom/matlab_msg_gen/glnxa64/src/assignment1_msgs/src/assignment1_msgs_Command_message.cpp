// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for assignment1_msgs/Command
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4100)
#pragma warning(disable : 4265)
#pragma warning(disable : 4456)
#pragma warning(disable : 4458)
#pragma warning(disable : 4946)
#pragma warning(disable : 4244)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"
#endif //_MSC_VER
#include "rclcpp/rclcpp.hpp"
#include "assignment1_msgs/msg/command.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class ASSIGNMENT1_MSGS_EXPORT ros2_assignment1_msgs_msg_Command_common : public MATLABROS2MsgInterface<assignment1_msgs::msg::Command> {
  public:
    virtual ~ros2_assignment1_msgs_msg_Command_common(){}
    virtual void copy_from_struct(assignment1_msgs::msg::Command* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const assignment1_msgs::msg::Command* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_assignment1_msgs_msg_Command_common::copy_from_struct(assignment1_msgs::msg::Command* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //name
        const matlab::data::CharArray name_arr = arr["name"];
        msg->name = name_arr.toAscii();
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'name' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'name' is wrong type; expected a string.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_assignment1_msgs_msg_Command_common::get_arr(MDFactory_T& factory, const assignment1_msgs::msg::Command* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","name"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("assignment1_msgs/Command");
    // name
    auto currentElement_name = (msg + ctr)->name;
    outArray[ctr]["name"] = factory.createCharArray(currentElement_name);
    }
    return std::move(outArray);
  } 
class ASSIGNMENT1_MSGS_EXPORT ros2_assignment1_msgs_Command_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_assignment1_msgs_Command_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_assignment1_msgs_Command_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<assignment1_msgs::msg::Command,ros2_assignment1_msgs_msg_Command_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_assignment1_msgs_Command_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<assignment1_msgs::msg::Command,ros2_assignment1_msgs_msg_Command_common>>();
  }
  std::shared_ptr<void> ros2_assignment1_msgs_Command_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<assignment1_msgs::msg::Command>();
    ros2_assignment1_msgs_msg_Command_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_assignment1_msgs_Command_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_assignment1_msgs_msg_Command_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (assignment1_msgs::msg::Command*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_assignment1_msgs_msg_Command_common, MATLABROS2MsgInterface<assignment1_msgs::msg::Command>)
CLASS_LOADER_REGISTER_CLASS(ros2_assignment1_msgs_Command_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER