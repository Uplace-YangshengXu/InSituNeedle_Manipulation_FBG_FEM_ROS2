// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for fbg_msgs/FbgReading
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
#include "fbg_msgs/msg/fbg_reading.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class FBG_MSGS_EXPORT ros2_fbg_msgs_msg_FbgReading_common : public MATLABROS2MsgInterface<fbg_msgs::msg::FbgReading> {
  public:
    virtual ~ros2_fbg_msgs_msg_FbgReading_common(){}
    virtual void copy_from_struct(fbg_msgs::msg::FbgReading* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const fbg_msgs::msg::FbgReading* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_fbg_msgs_msg_FbgReading_common::copy_from_struct(fbg_msgs::msg::FbgReading* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //signal_reading
        const matlab::data::TypedArray<double> signal_reading_arr = arr["signal_reading"];
        size_t nelem = signal_reading_arr.getNumberOfElements();
        	msg->signal_reading.resize(nelem);
        	std::copy(signal_reading_arr.begin(), signal_reading_arr.begin()+nelem, msg->signal_reading.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'signal_reading' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'signal_reading' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_fbg_msgs_msg_FbgReading_common::get_arr(MDFactory_T& factory, const fbg_msgs::msg::FbgReading* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","signal_reading"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("fbg_msgs/FbgReading");
    // signal_reading
    auto currentElement_signal_reading = (msg + ctr)->signal_reading;
    outArray[ctr]["signal_reading"] = factory.createArray<fbg_msgs::msg::FbgReading::_signal_reading_type::const_iterator, double>({currentElement_signal_reading.size(), 1}, currentElement_signal_reading.begin(), currentElement_signal_reading.end());
    }
    return std::move(outArray);
  } 
class FBG_MSGS_EXPORT ros2_fbg_msgs_FbgReading_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_fbg_msgs_FbgReading_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_fbg_msgs_FbgReading_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<fbg_msgs::msg::FbgReading,ros2_fbg_msgs_msg_FbgReading_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_fbg_msgs_FbgReading_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<fbg_msgs::msg::FbgReading,ros2_fbg_msgs_msg_FbgReading_common>>();
  }
  std::shared_ptr<void> ros2_fbg_msgs_FbgReading_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<fbg_msgs::msg::FbgReading>();
    ros2_fbg_msgs_msg_FbgReading_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_fbg_msgs_FbgReading_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_fbg_msgs_msg_FbgReading_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (fbg_msgs::msg::FbgReading*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_fbg_msgs_msg_FbgReading_common, MATLABROS2MsgInterface<fbg_msgs::msg::FbgReading>)
CLASS_LOADER_REGISTER_CLASS(ros2_fbg_msgs_FbgReading_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER