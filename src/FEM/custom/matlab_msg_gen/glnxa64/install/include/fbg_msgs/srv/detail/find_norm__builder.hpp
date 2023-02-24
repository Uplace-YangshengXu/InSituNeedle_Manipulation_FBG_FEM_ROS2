// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fbg_msgs:srv/FindNorm.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__SRV__DETAIL__FIND_NORM__BUILDER_HPP_
#define FBG_MSGS__SRV__DETAIL__FIND_NORM__BUILDER_HPP_

#include "fbg_msgs/srv/detail/find_norm__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace fbg_msgs
{

namespace srv
{

namespace builder
{

class Init_FindNorm_Request_input
{
public:
  Init_FindNorm_Request_input()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fbg_msgs::srv::FindNorm_Request input(::fbg_msgs::srv::FindNorm_Request::_input_type arg)
  {
    msg_.input = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fbg_msgs::srv::FindNorm_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::fbg_msgs::srv::FindNorm_Request>()
{
  return fbg_msgs::srv::builder::Init_FindNorm_Request_input();
}

}  // namespace fbg_msgs


namespace fbg_msgs
{

namespace srv
{

namespace builder
{

class Init_FindNorm_Response_norm
{
public:
  Init_FindNorm_Response_norm()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fbg_msgs::srv::FindNorm_Response norm(::fbg_msgs::srv::FindNorm_Response::_norm_type arg)
  {
    msg_.norm = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fbg_msgs::srv::FindNorm_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::fbg_msgs::srv::FindNorm_Response>()
{
  return fbg_msgs::srv::builder::Init_FindNorm_Response_norm();
}

}  // namespace fbg_msgs

#endif  // FBG_MSGS__SRV__DETAIL__FIND_NORM__BUILDER_HPP_
