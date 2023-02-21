// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fbg_msgs:msg/FbgReading.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__MSG__DETAIL__FBG_READING__TRAITS_HPP_
#define FBG_MSGS__MSG__DETAIL__FBG_READING__TRAITS_HPP_

#include "fbg_msgs/msg/detail/fbg_reading__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const fbg_msgs::msg::FbgReading & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: signal_reading
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.signal_reading.size() == 0) {
      out << "signal_reading: []\n";
    } else {
      out << "signal_reading:\n";
      for (auto item : msg.signal_reading) {
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

inline std::string to_yaml(const fbg_msgs::msg::FbgReading & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

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
