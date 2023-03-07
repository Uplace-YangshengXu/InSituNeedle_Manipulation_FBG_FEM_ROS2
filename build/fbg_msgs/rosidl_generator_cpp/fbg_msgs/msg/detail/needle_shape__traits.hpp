// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fbg_msgs:msg/NeedleShape.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__MSG__DETAIL__NEEDLE_SHAPE__TRAITS_HPP_
#define FBG_MSGS__MSG__DETAIL__NEEDLE_SHAPE__TRAITS_HPP_

#include "fbg_msgs/msg/detail/needle_shape__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const fbg_msgs::msg::NeedleShape & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: needle_total_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "needle_total_length: ";
    value_to_yaml(msg.needle_total_length, out);
    out << "\n";
  }

  // member: active_area_location
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.active_area_location.size() == 0) {
      out << "active_area_location: []\n";
    } else {
      out << "active_area_location:\n";
      for (auto item : msg.active_area_location) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: needle_x_axis
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.needle_x_axis.size() == 0) {
      out << "needle_x_axis: []\n";
    } else {
      out << "needle_x_axis:\n";
      for (auto item : msg.needle_x_axis) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: needle_y_axis
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.needle_y_axis.size() == 0) {
      out << "needle_y_axis: []\n";
    } else {
      out << "needle_y_axis:\n";
      for (auto item : msg.needle_y_axis) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: needle_z_axis
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.needle_z_axis.size() == 0) {
      out << "needle_z_axis: []\n";
    } else {
      out << "needle_z_axis:\n";
      for (auto item : msg.needle_z_axis) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: needle_slope
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.needle_slope.size() == 0) {
      out << "needle_slope: []\n";
    } else {
      out << "needle_slope:\n";
      for (auto item : msg.needle_slope) {
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

inline std::string to_yaml(const fbg_msgs::msg::NeedleShape & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<fbg_msgs::msg::NeedleShape>()
{
  return "fbg_msgs::msg::NeedleShape";
}

template<>
inline const char * name<fbg_msgs::msg::NeedleShape>()
{
  return "fbg_msgs/msg/NeedleShape";
}

template<>
struct has_fixed_size<fbg_msgs::msg::NeedleShape>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<fbg_msgs::msg::NeedleShape>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<fbg_msgs::msg::NeedleShape>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FBG_MSGS__MSG__DETAIL__NEEDLE_SHAPE__TRAITS_HPP_
