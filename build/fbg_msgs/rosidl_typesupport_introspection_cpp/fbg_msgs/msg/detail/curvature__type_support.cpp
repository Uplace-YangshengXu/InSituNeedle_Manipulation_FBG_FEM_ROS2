// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from fbg_msgs:msg/Curvature.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "fbg_msgs/msg/detail/curvature__struct.hpp"
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

void Curvature_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) fbg_msgs::msg::Curvature(_init);
}

void Curvature_fini_function(void * message_memory)
{
  auto typed_message = static_cast<fbg_msgs::msg::Curvature *>(message_memory);
  typed_message->~Curvature();
}

size_t size_function__Curvature__curvature_xy(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Curvature__curvature_xy(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__Curvature__curvature_xy(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__Curvature__curvature_xy(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Curvature__curvature_xz(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Curvature__curvature_xz(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__Curvature__curvature_xz(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__Curvature__curvature_xz(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Curvature_message_member_array[2] = {
  {
    "curvature_xy",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs::msg::Curvature, curvature_xy),  // bytes offset in struct
    nullptr,  // default value
    size_function__Curvature__curvature_xy,  // size() function pointer
    get_const_function__Curvature__curvature_xy,  // get_const(index) function pointer
    get_function__Curvature__curvature_xy,  // get(index) function pointer
    resize_function__Curvature__curvature_xy  // resize(index) function pointer
  },
  {
    "curvature_xz",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs::msg::Curvature, curvature_xz),  // bytes offset in struct
    nullptr,  // default value
    size_function__Curvature__curvature_xz,  // size() function pointer
    get_const_function__Curvature__curvature_xz,  // get_const(index) function pointer
    get_function__Curvature__curvature_xz,  // get(index) function pointer
    resize_function__Curvature__curvature_xz  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Curvature_message_members = {
  "fbg_msgs::msg",  // message namespace
  "Curvature",  // message name
  2,  // number of fields
  sizeof(fbg_msgs::msg::Curvature),
  Curvature_message_member_array,  // message members
  Curvature_init_function,  // function to initialize message memory (memory has to be allocated)
  Curvature_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Curvature_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Curvature_message_members,
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
get_message_type_support_handle<fbg_msgs::msg::Curvature>()
{
  return &::fbg_msgs::msg::rosidl_typesupport_introspection_cpp::Curvature_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, fbg_msgs, msg, Curvature)() {
  return &::fbg_msgs::msg::rosidl_typesupport_introspection_cpp::Curvature_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
