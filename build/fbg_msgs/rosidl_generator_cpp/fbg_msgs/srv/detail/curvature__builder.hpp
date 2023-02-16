// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fbg_msgs:srv/Curvature.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__SRV__DETAIL__CURVATURE__BUILDER_HPP_
#define FBG_MSGS__SRV__DETAIL__CURVATURE__BUILDER_HPP_

#include "fbg_msgs/srv/detail/curvature__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace fbg_msgs
{

namespace srv
{

namespace builder
{

class Init_Curvature_Request_fbg_reading
{
public:
  Init_Curvature_Request_fbg_reading()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fbg_msgs::srv::Curvature_Request fbg_reading(::fbg_msgs::srv::Curvature_Request::_fbg_reading_type arg)
  {
    msg_.fbg_reading = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fbg_msgs::srv::Curvature_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::fbg_msgs::srv::Curvature_Request>()
{
  return fbg_msgs::srv::builder::Init_Curvature_Request_fbg_reading();
}

}  // namespace fbg_msgs


namespace fbg_msgs
{

namespace srv
{

namespace builder
{

class Init_Curvature_Response_curvature
{
public:
  Init_Curvature_Response_curvature()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fbg_msgs::srv::Curvature_Response curvature(::fbg_msgs::srv::Curvature_Response::_curvature_type arg)
  {
    msg_.curvature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fbg_msgs::srv::Curvature_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::fbg_msgs::srv::Curvature_Response>()
{
  return fbg_msgs::srv::builder::Init_Curvature_Response_curvature();
}

}  // namespace fbg_msgs

#endif  // FBG_MSGS__SRV__DETAIL__CURVATURE__BUILDER_HPP_
