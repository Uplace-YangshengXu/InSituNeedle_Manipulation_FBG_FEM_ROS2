// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fbg_msgs:srv/CalCurvature.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__SRV__DETAIL__CAL_CURVATURE__TRAITS_HPP_
#define FBG_MSGS__SRV__DETAIL__CAL_CURVATURE__TRAITS_HPP_

#include "fbg_msgs/srv/detail/cal_curvature__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const fbg_msgs::srv::CalCurvature_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command: ";
    value_to_yaml(msg.command, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const fbg_msgs::srv::CalCurvature_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

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

inline void to_yaml(
  const fbg_msgs::srv::CalCurvature_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: curvature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "curvature:\n";
    to_yaml(msg.curvature, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const fbg_msgs::srv::CalCurvature_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

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
