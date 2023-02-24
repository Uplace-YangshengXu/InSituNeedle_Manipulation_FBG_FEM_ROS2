// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from assignment1_msgs:msg/Command.idl
// generated code does not contain a copyright notice

#ifndef ASSIGNMENT1_MSGS__MSG__DETAIL__COMMAND__TRAITS_HPP_
#define ASSIGNMENT1_MSGS__MSG__DETAIL__COMMAND__TRAITS_HPP_

#include "assignment1_msgs/msg/detail/command__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<assignment1_msgs::msg::Command>()
{
  return "assignment1_msgs::msg::Command";
}

template<>
inline const char * name<assignment1_msgs::msg::Command>()
{
  return "assignment1_msgs/msg/Command";
}

template<>
struct has_fixed_size<assignment1_msgs::msg::Command>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<assignment1_msgs::msg::Command>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<assignment1_msgs::msg::Command>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ASSIGNMENT1_MSGS__MSG__DETAIL__COMMAND__TRAITS_HPP_
