// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fbg_msgs:srv/CalCurvature.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__SRV__DETAIL__CAL_CURVATURE__BUILDER_HPP_
#define FBG_MSGS__SRV__DETAIL__CAL_CURVATURE__BUILDER_HPP_

#include "fbg_msgs/srv/detail/cal_curvature__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace fbg_msgs
{

namespace srv
{

namespace builder
{

class Init_CalCurvature_Request_command
{
public:
  Init_CalCurvature_Request_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fbg_msgs::srv::CalCurvature_Request command(::fbg_msgs::srv::CalCurvature_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fbg_msgs::srv::CalCurvature_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::fbg_msgs::srv::CalCurvature_Request>()
{
  return fbg_msgs::srv::builder::Init_CalCurvature_Request_command();
}

}  // namespace fbg_msgs


namespace fbg_msgs
{

namespace srv
{

namespace builder
{

class Init_CalCurvature_Response_curvature
{
public:
  Init_CalCurvature_Response_curvature()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fbg_msgs::srv::CalCurvature_Response curvature(::fbg_msgs::srv::CalCurvature_Response::_curvature_type arg)
  {
    msg_.curvature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fbg_msgs::srv::CalCurvature_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::fbg_msgs::srv::CalCurvature_Response>()
{
  return fbg_msgs::srv::builder::Init_CalCurvature_Response_curvature();
}

}  // namespace fbg_msgs

#endif  // FBG_MSGS__SRV__DETAIL__CAL_CURVATURE__BUILDER_HPP_
