// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fbg_msgs:msg/FbgReading.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__MSG__DETAIL__FBG_READING__BUILDER_HPP_
#define FBG_MSGS__MSG__DETAIL__FBG_READING__BUILDER_HPP_

#include "fbg_msgs/msg/detail/fbg_reading__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace fbg_msgs
{

namespace msg
{

namespace builder
{

class Init_FbgReading_total_reading_num
{
public:
  explicit Init_FbgReading_total_reading_num(::fbg_msgs::msg::FbgReading & msg)
  : msg_(msg)
  {}
  ::fbg_msgs::msg::FbgReading total_reading_num(::fbg_msgs::msg::FbgReading::_total_reading_num_type arg)
  {
    msg_.total_reading_num = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fbg_msgs::msg::FbgReading msg_;
};

class Init_FbgReading_signal_each_ch
{
public:
  explicit Init_FbgReading_signal_each_ch(::fbg_msgs::msg::FbgReading & msg)
  : msg_(msg)
  {}
  Init_FbgReading_total_reading_num signal_each_ch(::fbg_msgs::msg::FbgReading::_signal_each_ch_type arg)
  {
    msg_.signal_each_ch = std::move(arg);
    return Init_FbgReading_total_reading_num(msg_);
  }

private:
  ::fbg_msgs::msg::FbgReading msg_;
};

class Init_FbgReading_signal_reading
{
public:
  Init_FbgReading_signal_reading()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FbgReading_signal_each_ch signal_reading(::fbg_msgs::msg::FbgReading::_signal_reading_type arg)
  {
    msg_.signal_reading = std::move(arg);
    return Init_FbgReading_signal_each_ch(msg_);
  }

private:
  ::fbg_msgs::msg::FbgReading msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::fbg_msgs::msg::FbgReading>()
{
  return fbg_msgs::msg::builder::Init_FbgReading_signal_reading();
}

}  // namespace fbg_msgs

#endif  // FBG_MSGS__MSG__DETAIL__FBG_READING__BUILDER_HPP_
