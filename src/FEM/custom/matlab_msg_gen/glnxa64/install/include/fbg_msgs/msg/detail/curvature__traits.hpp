// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fbg_msgs:msg/Curvature.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__MSG__DETAIL__CURVATURE__TRAITS_HPP_
#define FBG_MSGS__MSG__DETAIL__CURVATURE__TRAITS_HPP_

#include "fbg_msgs/msg/detail/curvature__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fbg_msgs::msg::Curvature>()
{
  return "fbg_msgs::msg::Curvature";
}

template<>
inline const char * name<fbg_msgs::msg::Curvature>()
{
  return "fbg_msgs/msg/Curvature";
}

template<>
struct has_fixed_size<fbg_msgs::msg::Curvature>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<fbg_msgs::msg::Curvature>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<fbg_msgs::msg::Curvature>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FBG_MSGS__MSG__DETAIL__CURVATURE__TRAITS_HPP_
