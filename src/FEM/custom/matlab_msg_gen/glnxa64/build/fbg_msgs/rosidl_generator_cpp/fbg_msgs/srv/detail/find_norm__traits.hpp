// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fbg_msgs:srv/FindNorm.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__SRV__DETAIL__FIND_NORM__TRAITS_HPP_
#define FBG_MSGS__SRV__DETAIL__FIND_NORM__TRAITS_HPP_

#include "fbg_msgs/srv/detail/find_norm__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fbg_msgs::srv::FindNorm_Request>()
{
  return "fbg_msgs::srv::FindNorm_Request";
}

template<>
inline const char * name<fbg_msgs::srv::FindNorm_Request>()
{
  return "fbg_msgs/srv/FindNorm_Request";
}

template<>
struct has_fixed_size<fbg_msgs::srv::FindNorm_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<fbg_msgs::srv::FindNorm_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<fbg_msgs::srv::FindNorm_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fbg_msgs::srv::FindNorm_Response>()
{
  return "fbg_msgs::srv::FindNorm_Response";
}

template<>
inline const char * name<fbg_msgs::srv::FindNorm_Response>()
{
  return "fbg_msgs/srv/FindNorm_Response";
}

template<>
struct has_fixed_size<fbg_msgs::srv::FindNorm_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<fbg_msgs::srv::FindNorm_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<fbg_msgs::srv::FindNorm_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fbg_msgs::srv::FindNorm>()
{
  return "fbg_msgs::srv::FindNorm";
}

template<>
inline const char * name<fbg_msgs::srv::FindNorm>()
{
  return "fbg_msgs/srv/FindNorm";
}

template<>
struct has_fixed_size<fbg_msgs::srv::FindNorm>
  : std::integral_constant<
    bool,
    has_fixed_size<fbg_msgs::srv::FindNorm_Request>::value &&
    has_fixed_size<fbg_msgs::srv::FindNorm_Response>::value
  >
{
};

template<>
struct has_bounded_size<fbg_msgs::srv::FindNorm>
  : std::integral_constant<
    bool,
    has_bounded_size<fbg_msgs::srv::FindNorm_Request>::value &&
    has_bounded_size<fbg_msgs::srv::FindNorm_Response>::value
  >
{
};

template<>
struct is_service<fbg_msgs::srv::FindNorm>
  : std::true_type
{
};

template<>
struct is_service_request<fbg_msgs::srv::FindNorm_Request>
  : std::true_type
{
};

template<>
struct is_service_response<fbg_msgs::srv::FindNorm_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // FBG_MSGS__SRV__DETAIL__FIND_NORM__TRAITS_HPP_
