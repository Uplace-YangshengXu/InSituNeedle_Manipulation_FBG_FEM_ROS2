// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fbg_msgs:msg/NeedleShape.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__MSG__DETAIL__NEEDLE_SHAPE__BUILDER_HPP_
#define FBG_MSGS__MSG__DETAIL__NEEDLE_SHAPE__BUILDER_HPP_

#include "fbg_msgs/msg/detail/needle_shape__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace fbg_msgs
{

namespace msg
{

namespace builder
{

class Init_NeedleShape_needle_slope
{
public:
  explicit Init_NeedleShape_needle_slope(::fbg_msgs::msg::NeedleShape & msg)
  : msg_(msg)
  {}
  ::fbg_msgs::msg::NeedleShape needle_slope(::fbg_msgs::msg::NeedleShape::_needle_slope_type arg)
  {
    msg_.needle_slope = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fbg_msgs::msg::NeedleShape msg_;
};

class Init_NeedleShape_needle_z_axis
{
public:
  explicit Init_NeedleShape_needle_z_axis(::fbg_msgs::msg::NeedleShape & msg)
  : msg_(msg)
  {}
  Init_NeedleShape_needle_slope needle_z_axis(::fbg_msgs::msg::NeedleShape::_needle_z_axis_type arg)
  {
    msg_.needle_z_axis = std::move(arg);
    return Init_NeedleShape_needle_slope(msg_);
  }

private:
  ::fbg_msgs::msg::NeedleShape msg_;
};

class Init_NeedleShape_needle_y_axis
{
public:
  explicit Init_NeedleShape_needle_y_axis(::fbg_msgs::msg::NeedleShape & msg)
  : msg_(msg)
  {}
  Init_NeedleShape_needle_z_axis needle_y_axis(::fbg_msgs::msg::NeedleShape::_needle_y_axis_type arg)
  {
    msg_.needle_y_axis = std::move(arg);
    return Init_NeedleShape_needle_z_axis(msg_);
  }

private:
  ::fbg_msgs::msg::NeedleShape msg_;
};

class Init_NeedleShape_needle_x_axis
{
public:
  explicit Init_NeedleShape_needle_x_axis(::fbg_msgs::msg::NeedleShape & msg)
  : msg_(msg)
  {}
  Init_NeedleShape_needle_y_axis needle_x_axis(::fbg_msgs::msg::NeedleShape::_needle_x_axis_type arg)
  {
    msg_.needle_x_axis = std::move(arg);
    return Init_NeedleShape_needle_y_axis(msg_);
  }

private:
  ::fbg_msgs::msg::NeedleShape msg_;
};

class Init_NeedleShape_active_area_location
{
public:
  explicit Init_NeedleShape_active_area_location(::fbg_msgs::msg::NeedleShape & msg)
  : msg_(msg)
  {}
  Init_NeedleShape_needle_x_axis active_area_location(::fbg_msgs::msg::NeedleShape::_active_area_location_type arg)
  {
    msg_.active_area_location = std::move(arg);
    return Init_NeedleShape_needle_x_axis(msg_);
  }

private:
  ::fbg_msgs::msg::NeedleShape msg_;
};

class Init_NeedleShape_needle_total_length
{
public:
  Init_NeedleShape_needle_total_length()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NeedleShape_active_area_location needle_total_length(::fbg_msgs::msg::NeedleShape::_needle_total_length_type arg)
  {
    msg_.needle_total_length = std::move(arg);
    return Init_NeedleShape_active_area_location(msg_);
  }

private:
  ::fbg_msgs::msg::NeedleShape msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::fbg_msgs::msg::NeedleShape>()
{
  return fbg_msgs::msg::builder::Init_NeedleShape_needle_total_length();
}

}  // namespace fbg_msgs

#endif  // FBG_MSGS__MSG__DETAIL__NEEDLE_SHAPE__BUILDER_HPP_
