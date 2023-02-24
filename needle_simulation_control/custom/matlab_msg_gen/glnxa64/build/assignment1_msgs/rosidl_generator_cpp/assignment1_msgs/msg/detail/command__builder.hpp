// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from assignment1_msgs:msg/Command.idl
// generated code does not contain a copyright notice

#ifndef ASSIGNMENT1_MSGS__MSG__DETAIL__COMMAND__BUILDER_HPP_
#define ASSIGNMENT1_MSGS__MSG__DETAIL__COMMAND__BUILDER_HPP_

#include "assignment1_msgs/msg/detail/command__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace assignment1_msgs
{

namespace msg
{

namespace builder
{

class Init_Command_name
{
public:
  Init_Command_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::assignment1_msgs::msg::Command name(::assignment1_msgs::msg::Command::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::assignment1_msgs::msg::Command msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::assignment1_msgs::msg::Command>()
{
  return assignment1_msgs::msg::builder::Init_Command_name();
}

}  // namespace assignment1_msgs

#endif  // ASSIGNMENT1_MSGS__MSG__DETAIL__COMMAND__BUILDER_HPP_
