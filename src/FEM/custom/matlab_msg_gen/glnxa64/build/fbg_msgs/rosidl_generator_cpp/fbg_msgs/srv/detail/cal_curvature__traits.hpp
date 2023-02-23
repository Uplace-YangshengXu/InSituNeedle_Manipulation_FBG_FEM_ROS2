// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fbg_msgs:srv/CalCurvature.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__SRV__DETAIL__CAL_CURVATURE__TRAITS_HPP_
#define FBG_MSGS__SRV__DETAIL__CAL_CURVATURE__TRAITS_HPP_

#include "fbg_msgs/srv/detail/cal_curvature__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fbg_msgs::srv::CalCurvature_Request>()
{
  return "fbg_msgs::srv::CalCurvature_Request";
}

template<>
inline const char * name<fbg_msgs::srv::CalCurvature_Request>()
{
  return "fbg_msgs/srv/CalCurvature_Request";
}

template<>
struct has_fixed_size<fbg_msgs::srv::CalCurvature_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<fbg_msgs::srv::CalCurvature_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<fbg_msgs::srv::CalCurvature_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'curvature'
#include "fbg_msgs/msg/detail/curvature__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fbg_msgs::srv::CalCurvature_Response>()
{
  return "fbg_msgs::srv::CalCurvature_Response";
}

template<>
inline const char * name<fbg_msgs::srv::CalCurvature_Response>()
{
  return "fbg_msgs/srv/CalCurvature_Response";
}

template<>
struct has_fixed_size<fbg_msgs::srv::CalCurvature_Response>
  : std::integral_constant<bool, has_fixed_size<fbg_msgs::msg::Curvature>::value> {};

template<>
struct has_bounded_size<fbg_msgs::srv::CalCurvature_Response>
  : std::integral_constant<bool, has_bounded_size<fbg_msgs::msg::Curvature>::value> {};

template<>
struct is_message<fbg_msgs::srv::CalCurvature_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fbg_msgs::srv::CalCurvature>()
{
  return "fbg_msgs::srv::CalCurvature";
}

template<>
inline const char * name<fbg_msgs::srv::CalCurvature>()
{
  return "fbg_msgs/srv/CalCurvature";
}

template<>
struct has_fixed_size<fbg_msgs::srv::CalCurvature>
  : std::integral_constant<
    bool,
    has_fixed_size<fbg_msgs::srv::CalCurvature_Request>::value &&
    has_fixed_size<fbg_msgs::srv::CalCurvature_Response>::value
  >
{
};

template<>
struct has_bounded_size<fbg_msgs::srv::CalCurvature>
  : std::integral_constant<
    bool,
    has_bounded_size<fbg_msgs::srv::CalCurvature_Request>::value &&
    has_bounded_size<fbg_msgs::srv::CalCurvature_Response>::value
  >
{
};

template<>
struct is_service<fbg_msgs::srv::CalCurvature>
  : std::true_type
{
};

template<>
struct is_service_request<fbg_msgs::srv::CalCurvature_Request>
  : std::true_type
{
};

template<>
struct is_service_response<fbg_msgs::srv::CalCurvature_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // FBG_MSGS__SRV__DETAIL__CAL_CURVATURE__TRAITS_HPP_
