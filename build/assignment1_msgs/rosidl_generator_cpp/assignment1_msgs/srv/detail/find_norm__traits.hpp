// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from assignment1_msgs:srv/FindNorm.idl
// generated code does not contain a copyright notice

#ifndef ASSIGNMENT1_MSGS__SRV__DETAIL__FIND_NORM__TRAITS_HPP_
#define ASSIGNMENT1_MSGS__SRV__DETAIL__FIND_NORM__TRAITS_HPP_

#include "assignment1_msgs/srv/detail/find_norm__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const assignment1_msgs::srv::FindNorm_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: input
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "input: ";
    value_to_yaml(msg.input, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const assignment1_msgs::srv::FindNorm_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<assignment1_msgs::srv::FindNorm_Request>()
{
  return "assignment1_msgs::srv::FindNorm_Request";
}

template<>
inline const char * name<assignment1_msgs::srv::FindNorm_Request>()
{
  return "assignment1_msgs/srv/FindNorm_Request";
}

template<>
struct has_fixed_size<assignment1_msgs::srv::FindNorm_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<assignment1_msgs::srv::FindNorm_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<assignment1_msgs::srv::FindNorm_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const assignment1_msgs::srv::FindNorm_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: norm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "norm: ";
    value_to_yaml(msg.norm, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const assignment1_msgs::srv::FindNorm_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<assignment1_msgs::srv::FindNorm_Response>()
{
  return "assignment1_msgs::srv::FindNorm_Response";
}

template<>
inline const char * name<assignment1_msgs::srv::FindNorm_Response>()
{
  return "assignment1_msgs/srv/FindNorm_Response";
}

template<>
struct has_fixed_size<assignment1_msgs::srv::FindNorm_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<assignment1_msgs::srv::FindNorm_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<assignment1_msgs::srv::FindNorm_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<assignment1_msgs::srv::FindNorm>()
{
  return "assignment1_msgs::srv::FindNorm";
}

template<>
inline const char * name<assignment1_msgs::srv::FindNorm>()
{
  return "assignment1_msgs/srv/FindNorm";
}

template<>
struct has_fixed_size<assignment1_msgs::srv::FindNorm>
  : std::integral_constant<
    bool,
    has_fixed_size<assignment1_msgs::srv::FindNorm_Request>::value &&
    has_fixed_size<assignment1_msgs::srv::FindNorm_Response>::value
  >
{
};

template<>
struct has_bounded_size<assignment1_msgs::srv::FindNorm>
  : std::integral_constant<
    bool,
    has_bounded_size<assignment1_msgs::srv::FindNorm_Request>::value &&
    has_bounded_size<assignment1_msgs::srv::FindNorm_Response>::value
  >
{
};

template<>
struct is_service<assignment1_msgs::srv::FindNorm>
  : std::true_type
{
};

template<>
struct is_service_request<assignment1_msgs::srv::FindNorm_Request>
  : std::true_type
{
};

template<>
struct is_service_response<assignment1_msgs::srv::FindNorm_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ASSIGNMENT1_MSGS__SRV__DETAIL__FIND_NORM__TRAITS_HPP_
