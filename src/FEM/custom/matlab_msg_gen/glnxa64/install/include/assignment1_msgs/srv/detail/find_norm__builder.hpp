// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from assignment1_msgs:srv/FindNorm.idl
// generated code does not contain a copyright notice

#ifndef ASSIGNMENT1_MSGS__SRV__DETAIL__FIND_NORM__BUILDER_HPP_
#define ASSIGNMENT1_MSGS__SRV__DETAIL__FIND_NORM__BUILDER_HPP_

#include "assignment1_msgs/srv/detail/find_norm__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace assignment1_msgs
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
  ::assignment1_msgs::srv::FindNorm_Request input(::assignment1_msgs::srv::FindNorm_Request::_input_type arg)
  {
    msg_.input = std::move(arg);
    return std::move(msg_);
  }

private:
  ::assignment1_msgs::srv::FindNorm_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::assignment1_msgs::srv::FindNorm_Request>()
{
  return assignment1_msgs::srv::builder::Init_FindNorm_Request_input();
}

}  // namespace assignment1_msgs


namespace assignment1_msgs
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
  ::assignment1_msgs::srv::FindNorm_Response norm(::assignment1_msgs::srv::FindNorm_Response::_norm_type arg)
  {
    msg_.norm = std::move(arg);
    return std::move(msg_);
  }

private:
  ::assignment1_msgs::srv::FindNorm_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::assignment1_msgs::srv::FindNorm_Response>()
{
  return assignment1_msgs::srv::builder::Init_FindNorm_Response_norm();
}

}  // namespace assignment1_msgs

#endif  // ASSIGNMENT1_MSGS__SRV__DETAIL__FIND_NORM__BUILDER_HPP_
