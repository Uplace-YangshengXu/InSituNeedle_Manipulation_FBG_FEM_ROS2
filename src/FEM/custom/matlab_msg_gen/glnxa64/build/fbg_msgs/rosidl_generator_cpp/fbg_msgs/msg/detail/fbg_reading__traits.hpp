// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fbg_msgs:msg/FbgReading.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__MSG__DETAIL__FBG_READING__TRAITS_HPP_
#define FBG_MSGS__MSG__DETAIL__FBG_READING__TRAITS_HPP_

#include "fbg_msgs/msg/detail/fbg_reading__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fbg_msgs::msg::FbgReading>()
{
  return "fbg_msgs::msg::FbgReading";
}

template<>
inline const char * name<fbg_msgs::msg::FbgReading>()
{
  return "fbg_msgs/msg/FbgReading";
}

template<>
struct has_fixed_size<fbg_msgs::msg::FbgReading>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<fbg_msgs::msg::FbgReading>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<fbg_msgs::msg::FbgReading>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FBG_MSGS__MSG__DETAIL__FBG_READING__TRAITS_HPP_
