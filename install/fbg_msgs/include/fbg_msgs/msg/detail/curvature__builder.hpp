// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fbg_msgs:msg/Curvature.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__MSG__DETAIL__CURVATURE__BUILDER_HPP_
#define FBG_MSGS__MSG__DETAIL__CURVATURE__BUILDER_HPP_

#include "fbg_msgs/msg/detail/curvature__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace fbg_msgs
{

namespace msg
{

namespace builder
{

class Init_Curvature_curvature_xz
{
public:
  explicit Init_Curvature_curvature_xz(::fbg_msgs::msg::Curvature & msg)
  : msg_(msg)
  {}
  ::fbg_msgs::msg::Curvature curvature_xz(::fbg_msgs::msg::Curvature::_curvature_xz_type arg)
  {
    msg_.curvature_xz = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fbg_msgs::msg::Curvature msg_;
};

class Init_Curvature_curvature_xy
{
public:
  Init_Curvature_curvature_xy()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Curvature_curvature_xz curvature_xy(::fbg_msgs::msg::Curvature::_curvature_xy_type arg)
  {
    msg_.curvature_xy = std::move(arg);
    return Init_Curvature_curvature_xz(msg_);
  }

private:
  ::fbg_msgs::msg::Curvature msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::fbg_msgs::msg::Curvature>()
{
  return fbg_msgs::msg::builder::Init_Curvature_curvature_xy();
}

}  // namespace fbg_msgs

#endif  // FBG_MSGS__MSG__DETAIL__CURVATURE__BUILDER_HPP_
