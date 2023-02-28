// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for fbg_msgs/NeedleShape
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
#include "fbg_msgs/msg/needle_shape.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class FBG_MSGS_EXPORT ros2_fbg_msgs_msg_NeedleShape_common : public MATLABROS2MsgInterface<fbg_msgs::msg::NeedleShape> {
  public:
    virtual ~ros2_fbg_msgs_msg_NeedleShape_common(){}
    virtual void copy_from_struct(fbg_msgs::msg::NeedleShape* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const fbg_msgs::msg::NeedleShape* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_fbg_msgs_msg_NeedleShape_common::copy_from_struct(fbg_msgs::msg::NeedleShape* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //needle_total_length
        const matlab::data::TypedArray<uint8_t> needle_total_length_arr = arr["needle_total_length"];
        msg->needle_total_length = needle_total_length_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'needle_total_length' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'needle_total_length' is wrong type; expected a uint8.");
    }
    try {
        //active_area_location
        const matlab::data::TypedArray<double> active_area_location_arr = arr["active_area_location"];
        size_t nelem = active_area_location_arr.getNumberOfElements();
        	msg->active_area_location.resize(nelem);
        	std::copy(active_area_location_arr.begin(), active_area_location_arr.begin()+nelem, msg->active_area_location.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'active_area_location' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'active_area_location' is wrong type; expected a double.");
    }
    try {
        //needle_x_axis
        const matlab::data::TypedArray<double> needle_x_axis_arr = arr["needle_x_axis"];
        size_t nelem = needle_x_axis_arr.getNumberOfElements();
        	msg->needle_x_axis.resize(nelem);
        	std::copy(needle_x_axis_arr.begin(), needle_x_axis_arr.begin()+nelem, msg->needle_x_axis.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'needle_x_axis' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'needle_x_axis' is wrong type; expected a double.");
    }
    try {
        //needle_y_axis
        const matlab::data::TypedArray<double> needle_y_axis_arr = arr["needle_y_axis"];
        size_t nelem = needle_y_axis_arr.getNumberOfElements();
        	msg->needle_y_axis.resize(nelem);
        	std::copy(needle_y_axis_arr.begin(), needle_y_axis_arr.begin()+nelem, msg->needle_y_axis.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'needle_y_axis' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'needle_y_axis' is wrong type; expected a double.");
    }
    try {
        //needle_z_axis
        const matlab::data::TypedArray<double> needle_z_axis_arr = arr["needle_z_axis"];
        size_t nelem = needle_z_axis_arr.getNumberOfElements();
        	msg->needle_z_axis.resize(nelem);
        	std::copy(needle_z_axis_arr.begin(), needle_z_axis_arr.begin()+nelem, msg->needle_z_axis.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'needle_z_axis' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'needle_z_axis' is wrong type; expected a double.");
    }
    try {
        //needle_slope
        const matlab::data::TypedArray<double> needle_slope_arr = arr["needle_slope"];
        size_t nelem = needle_slope_arr.getNumberOfElements();
        	msg->needle_slope.resize(nelem);
        	std::copy(needle_slope_arr.begin(), needle_slope_arr.begin()+nelem, msg->needle_slope.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'needle_slope' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'needle_slope' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_fbg_msgs_msg_NeedleShape_common::get_arr(MDFactory_T& factory, const fbg_msgs::msg::NeedleShape* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","needle_total_length","active_area_location","needle_x_axis","needle_y_axis","needle_z_axis","needle_slope"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("fbg_msgs/NeedleShape");
    // needle_total_length
    auto currentElement_needle_total_length = (msg + ctr)->needle_total_length;
    outArray[ctr]["needle_total_length"] = factory.createScalar(currentElement_needle_total_length);
    // active_area_location
    auto currentElement_active_area_location = (msg + ctr)->active_area_location;
    outArray[ctr]["active_area_location"] = factory.createArray<fbg_msgs::msg::NeedleShape::_active_area_location_type::const_iterator, double>({currentElement_active_area_location.size(), 1}, currentElement_active_area_location.begin(), currentElement_active_area_location.end());
    // needle_x_axis
    auto currentElement_needle_x_axis = (msg + ctr)->needle_x_axis;
    outArray[ctr]["needle_x_axis"] = factory.createArray<fbg_msgs::msg::NeedleShape::_needle_x_axis_type::const_iterator, double>({currentElement_needle_x_axis.size(), 1}, currentElement_needle_x_axis.begin(), currentElement_needle_x_axis.end());
    // needle_y_axis
    auto currentElement_needle_y_axis = (msg + ctr)->needle_y_axis;
    outArray[ctr]["needle_y_axis"] = factory.createArray<fbg_msgs::msg::NeedleShape::_needle_y_axis_type::const_iterator, double>({currentElement_needle_y_axis.size(), 1}, currentElement_needle_y_axis.begin(), currentElement_needle_y_axis.end());
    // needle_z_axis
    auto currentElement_needle_z_axis = (msg + ctr)->needle_z_axis;
    outArray[ctr]["needle_z_axis"] = factory.createArray<fbg_msgs::msg::NeedleShape::_needle_z_axis_type::const_iterator, double>({currentElement_needle_z_axis.size(), 1}, currentElement_needle_z_axis.begin(), currentElement_needle_z_axis.end());
    // needle_slope
    auto currentElement_needle_slope = (msg + ctr)->needle_slope;
    outArray[ctr]["needle_slope"] = factory.createArray<fbg_msgs::msg::NeedleShape::_needle_slope_type::const_iterator, double>({currentElement_needle_slope.size(), 1}, currentElement_needle_slope.begin(), currentElement_needle_slope.end());
    }
    return std::move(outArray);
  } 
class FBG_MSGS_EXPORT ros2_fbg_msgs_NeedleShape_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_fbg_msgs_NeedleShape_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_fbg_msgs_NeedleShape_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<fbg_msgs::msg::NeedleShape,ros2_fbg_msgs_msg_NeedleShape_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_fbg_msgs_NeedleShape_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<fbg_msgs::msg::NeedleShape,ros2_fbg_msgs_msg_NeedleShape_common>>();
  }
  std::shared_ptr<void> ros2_fbg_msgs_NeedleShape_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<fbg_msgs::msg::NeedleShape>();
    ros2_fbg_msgs_msg_NeedleShape_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_fbg_msgs_NeedleShape_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_fbg_msgs_msg_NeedleShape_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (fbg_msgs::msg::NeedleShape*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_fbg_msgs_msg_NeedleShape_common, MATLABROS2MsgInterface<fbg_msgs::msg::NeedleShape>)
CLASS_LOADER_REGISTER_CLASS(ros2_fbg_msgs_NeedleShape_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER