// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from fbg_msgs:msg/NeedleShape.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "fbg_msgs/msg/detail/needle_shape__struct.hpp"
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

void NeedleShape_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) fbg_msgs::msg::NeedleShape(_init);
}

void NeedleShape_fini_function(void * message_memory)
{
  auto typed_message = static_cast<fbg_msgs::msg::NeedleShape *>(message_memory);
  typed_message->~NeedleShape();
}

size_t size_function__NeedleShape__active_area_location(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__NeedleShape__active_area_location(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__NeedleShape__active_area_location(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__NeedleShape__active_area_location(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__NeedleShape__needle_x_axis(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__NeedleShape__needle_x_axis(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__NeedleShape__needle_x_axis(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__NeedleShape__needle_x_axis(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__NeedleShape__needle_y_axis(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__NeedleShape__needle_y_axis(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__NeedleShape__needle_y_axis(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__NeedleShape__needle_y_axis(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__NeedleShape__needle_z_axis(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__NeedleShape__needle_z_axis(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__NeedleShape__needle_z_axis(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__NeedleShape__needle_z_axis(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__NeedleShape__needle_slope(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__NeedleShape__needle_slope(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__NeedleShape__needle_slope(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__NeedleShape__needle_slope(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember NeedleShape_message_member_array[6] = {
  {
    "needle_total_length",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs::msg::NeedleShape, needle_total_length),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "active_area_location",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs::msg::NeedleShape, active_area_location),  // bytes offset in struct
    nullptr,  // default value
    size_function__NeedleShape__active_area_location,  // size() function pointer
    get_const_function__NeedleShape__active_area_location,  // get_const(index) function pointer
    get_function__NeedleShape__active_area_location,  // get(index) function pointer
    resize_function__NeedleShape__active_area_location  // resize(index) function pointer
  },
  {
    "needle_x_axis",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs::msg::NeedleShape, needle_x_axis),  // bytes offset in struct
    nullptr,  // default value
    size_function__NeedleShape__needle_x_axis,  // size() function pointer
    get_const_function__NeedleShape__needle_x_axis,  // get_const(index) function pointer
    get_function__NeedleShape__needle_x_axis,  // get(index) function pointer
    resize_function__NeedleShape__needle_x_axis  // resize(index) function pointer
  },
  {
    "needle_y_axis",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs::msg::NeedleShape, needle_y_axis),  // bytes offset in struct
    nullptr,  // default value
    size_function__NeedleShape__needle_y_axis,  // size() function pointer
    get_const_function__NeedleShape__needle_y_axis,  // get_const(index) function pointer
    get_function__NeedleShape__needle_y_axis,  // get(index) function pointer
    resize_function__NeedleShape__needle_y_axis  // resize(index) function pointer
  },
  {
    "needle_z_axis",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs::msg::NeedleShape, needle_z_axis),  // bytes offset in struct
    nullptr,  // default value
    size_function__NeedleShape__needle_z_axis,  // size() function pointer
    get_const_function__NeedleShape__needle_z_axis,  // get_const(index) function pointer
    get_function__NeedleShape__needle_z_axis,  // get(index) function pointer
    resize_function__NeedleShape__needle_z_axis  // resize(index) function pointer
  },
  {
    "needle_slope",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs::msg::NeedleShape, needle_slope),  // bytes offset in struct
    nullptr,  // default value
    size_function__NeedleShape__needle_slope,  // size() function pointer
    get_const_function__NeedleShape__needle_slope,  // get_const(index) function pointer
    get_function__NeedleShape__needle_slope,  // get(index) function pointer
    resize_function__NeedleShape__needle_slope  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers NeedleShape_message_members = {
  "fbg_msgs::msg",  // message namespace
  "NeedleShape",  // message name
  6,  // number of fields
  sizeof(fbg_msgs::msg::NeedleShape),
  NeedleShape_message_member_array,  // message members
  NeedleShape_init_function,  // function to initialize message memory (memory has to be allocated)
  NeedleShape_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t NeedleShape_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &NeedleShape_message_members,
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
get_message_type_support_handle<fbg_msgs::msg::NeedleShape>()
{
  return &::fbg_msgs::msg::rosidl_typesupport_introspection_cpp::NeedleShape_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, fbg_msgs, msg, NeedleShape)() {
  return &::fbg_msgs::msg::rosidl_typesupport_introspection_cpp::NeedleShape_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
