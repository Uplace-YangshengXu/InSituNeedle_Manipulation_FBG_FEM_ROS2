// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from fbg_msgs:msg/FbgReading.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "fbg_msgs/msg/detail/fbg_reading__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace fbg_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void FbgReading_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) fbg_msgs::msg::FbgReading(_init);
}

void FbgReading_fini_function(void * message_memory)
{
  auto typed_message = static_cast<fbg_msgs::msg::FbgReading *>(message_memory);
  typed_message->~FbgReading();
}

size_t size_function__FbgReading__signal_reading(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__FbgReading__signal_reading(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__FbgReading__signal_reading(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__FbgReading__signal_reading(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember FbgReading_message_member_array[1] = {
  {
    "signal_reading",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs::msg::FbgReading, signal_reading),  // bytes offset in struct
    nullptr,  // default value
    size_function__FbgReading__signal_reading,  // size() function pointer
    get_const_function__FbgReading__signal_reading,  // get_const(index) function pointer
    get_function__FbgReading__signal_reading,  // get(index) function pointer
    resize_function__FbgReading__signal_reading  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers FbgReading_message_members = {
  "fbg_msgs::msg",  // message namespace
  "FbgReading",  // message name
  1,  // number of fields
  sizeof(fbg_msgs::msg::FbgReading),
  FbgReading_message_member_array,  // message members
  FbgReading_init_function,  // function to initialize message memory (memory has to be allocated)
  FbgReading_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t FbgReading_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FbgReading_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace fbg_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<fbg_msgs::msg::FbgReading>()
{
  return &::fbg_msgs::msg::rosidl_typesupport_introspection_cpp::FbgReading_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, fbg_msgs, msg, FbgReading)() {
  return &::fbg_msgs::msg::rosidl_typesupport_introspection_cpp::FbgReading_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
