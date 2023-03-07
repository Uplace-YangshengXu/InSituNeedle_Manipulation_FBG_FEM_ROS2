// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from fbg_msgs:msg/Curvature.idl
// generated code does not contain a copyright notice
#include "fbg_msgs/msg/detail/curvature__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fbg_msgs/msg/detail/curvature__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace fbg_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fbg_msgs
cdr_serialize(
  const fbg_msgs::msg::Curvature & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: curvature_xy
  {
    cdr << ros_message.curvature_xy;
  }
  // Member: curvature_xz
  {
    cdr << ros_message.curvature_xz;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fbg_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  fbg_msgs::msg::Curvature & ros_message)
{
  // Member: curvature_xy
  {
    cdr >> ros_message.curvature_xy;
  }

  // Member: curvature_xz
  {
    cdr >> ros_message.curvature_xz;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fbg_msgs
get_serialized_size(
  const fbg_msgs::msg::Curvature & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: curvature_xy
  {
    size_t array_size = ros_message.curvature_xy.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.curvature_xy[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: curvature_xz
  {
    size_t array_size = ros_message.curvature_xz.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.curvature_xz[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fbg_msgs
max_serialized_size_Curvature(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: curvature_xy
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: curvature_xz
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _Curvature__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const fbg_msgs::msg::Curvature *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Curvature__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<fbg_msgs::msg::Curvature *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Curvature__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const fbg_msgs::msg::Curvature *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Curvature__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Curvature(full_bounded, 0);
}

static message_type_support_callbacks_t _Curvature__callbacks = {
  "fbg_msgs::msg",
  "Curvature",
  _Curvature__cdr_serialize,
  _Curvature__cdr_deserialize,
  _Curvature__get_serialized_size,
  _Curvature__max_serialized_size
};

static rosidl_message_type_support_t _Curvature__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Curvature__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace fbg_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_fbg_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<fbg_msgs::msg::Curvature>()
{
  return &fbg_msgs::msg::typesupport_fastrtps_cpp::_Curvature__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fbg_msgs, msg, Curvature)() {
  return &fbg_msgs::msg::typesupport_fastrtps_cpp::_Curvature__handle;
}

#ifdef __cplusplus
}
#endif
