// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fbg_msgs:msg/Curvature.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__MSG__DETAIL__CURVATURE__TRAITS_HPP_
#define FBG_MSGS__MSG__DETAIL__CURVATURE__TRAITS_HPP_

#include "fbg_msgs/msg/detail/curvature__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const fbg_msgs::msg::Curvature & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: curvature_xy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.curvature_xy.size() == 0) {
      out << "curvature_xy: []\n";
    } else {
      out << "curvature_xy:\n";
      for (auto item : msg.curvature_xy) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: curvature_xz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.curvature_xz.size() == 0) {
      out << "curvature_xz: []\n";
    } else {
      out << "curvature_xz:\n";
      for (auto item : msg.curvature_xz) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const fbg_msgs::msg::Curvature & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

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
