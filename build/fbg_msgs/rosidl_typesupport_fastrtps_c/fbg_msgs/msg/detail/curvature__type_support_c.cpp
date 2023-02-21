// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from fbg_msgs:msg/Curvature.idl
// generated code does not contain a copyright notice
#include "fbg_msgs/msg/detail/curvature__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "fbg_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "fbg_msgs/msg/detail/curvature__struct.h"
#include "fbg_msgs/msg/detail/curvature__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // curvature_xy, curvature_xz
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // curvature_xy, curvature_xz

// forward declare type support functions


using _Curvature__ros_msg_type = fbg_msgs__msg__Curvature;

static bool _Curvature__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Curvature__ros_msg_type * ros_message = static_cast<const _Curvature__ros_msg_type *>(untyped_ros_message);
  // Field name: curvature_xy
  {
    size_t size = ros_message->curvature_xy.size;
    auto array_ptr = ros_message->curvature_xy.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: curvature_xz
  {
    size_t size = ros_message->curvature_xz.size;
    auto array_ptr = ros_message->curvature_xz.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _Curvature__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Curvature__ros_msg_type * ros_message = static_cast<_Curvature__ros_msg_type *>(untyped_ros_message);
  // Field name: curvature_xy
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->curvature_xy.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->curvature_xy);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->curvature_xy, size)) {
      fprintf(stderr, "failed to create array for field 'curvature_xy'");
      return false;
    }
    auto array_ptr = ros_message->curvature_xy.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: curvature_xz
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->curvature_xz.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->curvature_xz);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->curvature_xz, size)) {
      fprintf(stderr, "failed to create array for field 'curvature_xz'");
      return false;
    }
    auto array_ptr = ros_message->curvature_xz.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_fbg_msgs
size_t get_serialized_size_fbg_msgs__msg__Curvature(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Curvature__ros_msg_type * ros_message = static_cast<const _Curvature__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name curvature_xy
  {
    size_t array_size = ros_message->curvature_xy.size;
    auto array_ptr = ros_message->curvature_xy.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name curvature_xz
  {
    size_t array_size = ros_message->curvature_xz.size;
    auto array_ptr = ros_message->curvature_xz.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Curvature__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_fbg_msgs__msg__Curvature(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_fbg_msgs
size_t max_serialized_size_fbg_msgs__msg__Curvature(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: curvature_xy
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: curvature_xz
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

static size_t _Curvature__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_fbg_msgs__msg__Curvature(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Curvature = {
  "fbg_msgs::msg",
  "Curvature",
  _Curvature__cdr_serialize,
  _Curvature__cdr_deserialize,
  _Curvature__get_serialized_size,
  _Curvature__max_serialized_size
};

static rosidl_message_type_support_t _Curvature__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Curvature,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fbg_msgs, msg, Curvature)() {
  return &_Curvature__type_support;
}

#if defined(__cplusplus)
}
#endif
