// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for fbg_msgs/Curvature
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
#include "fbg_msgs/msg/curvature.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class FBG_MSGS_EXPORT ros2_fbg_msgs_msg_Curvature_common : public MATLABROS2MsgInterface<fbg_msgs::msg::Curvature> {
  public:
    virtual ~ros2_fbg_msgs_msg_Curvature_common(){}
    virtual void copy_from_struct(fbg_msgs::msg::Curvature* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const fbg_msgs::msg::Curvature* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_fbg_msgs_msg_Curvature_common::copy_from_struct(fbg_msgs::msg::Curvature* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //curvature_xy
        const matlab::data::TypedArray<double> curvature_xy_arr = arr["curvature_xy"];
        size_t nelem = curvature_xy_arr.getNumberOfElements();
        	msg->curvature_xy.resize(nelem);
        	std::copy(curvature_xy_arr.begin(), curvature_xy_arr.begin()+nelem, msg->curvature_xy.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'curvature_xy' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'curvature_xy' is wrong type; expected a double.");
    }
    try {
        //curvature_xz
        const matlab::data::TypedArray<double> curvature_xz_arr = arr["curvature_xz"];
        size_t nelem = curvature_xz_arr.getNumberOfElements();
        	msg->curvature_xz.resize(nelem);
        	std::copy(curvature_xz_arr.begin(), curvature_xz_arr.begin()+nelem, msg->curvature_xz.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'curvature_xz' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'curvature_xz' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_fbg_msgs_msg_Curvature_common::get_arr(MDFactory_T& factory, const fbg_msgs::msg::Curvature* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","curvature_xy","curvature_xz"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("fbg_msgs/Curvature");
    // curvature_xy
    auto currentElement_curvature_xy = (msg + ctr)->curvature_xy;
    outArray[ctr]["curvature_xy"] = factory.createArray<fbg_msgs::msg::Curvature::_curvature_xy_type::const_iterator, double>({currentElement_curvature_xy.size(), 1}, currentElement_curvature_xy.begin(), currentElement_curvature_xy.end());
    // curvature_xz
    auto currentElement_curvature_xz = (msg + ctr)->curvature_xz;
    outArray[ctr]["curvature_xz"] = factory.createArray<fbg_msgs::msg::Curvature::_curvature_xz_type::const_iterator, double>({currentElement_curvature_xz.size(), 1}, currentElement_curvature_xz.begin(), currentElement_curvature_xz.end());
    }
    return std::move(outArray);
  } 
class FBG_MSGS_EXPORT ros2_fbg_msgs_Curvature_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_fbg_msgs_Curvature_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_fbg_msgs_Curvature_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<fbg_msgs::msg::Curvature,ros2_fbg_msgs_msg_Curvature_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_fbg_msgs_Curvature_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<fbg_msgs::msg::Curvature,ros2_fbg_msgs_msg_Curvature_common>>();
  }
  std::shared_ptr<void> ros2_fbg_msgs_Curvature_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<fbg_msgs::msg::Curvature>();
    ros2_fbg_msgs_msg_Curvature_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_fbg_msgs_Curvature_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_fbg_msgs_msg_Curvature_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (fbg_msgs::msg::Curvature*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_fbg_msgs_msg_Curvature_common, MATLABROS2MsgInterface<fbg_msgs::msg::Curvature>)
CLASS_LOADER_REGISTER_CLASS(ros2_fbg_msgs_Curvature_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER