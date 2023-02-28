// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from fbg_msgs:msg/NeedleShape.idl
// generated code does not contain a copyright notice
#include "fbg_msgs/msg/detail/needle_shape__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "fbg_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "fbg_msgs/msg/detail/needle_shape__struct.h"
#include "fbg_msgs/msg/detail/needle_shape__functions.h"
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

#include "rosidl_runtime_c/primitives_sequence.h"  // active_area_location, needle_slope, needle_x_axis, needle_y_axis, needle_z_axis
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // active_area_location, needle_slope, needle_x_axis, needle_y_axis, needle_z_axis

// forward declare type support functions


using _NeedleShape__ros_msg_type = fbg_msgs__msg__NeedleShape;

static bool _NeedleShape__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _NeedleShape__ros_msg_type * ros_message = static_cast<const _NeedleShape__ros_msg_type *>(untyped_ros_message);
  // Field name: needle_total_length
  {
    cdr << ros_message->needle_total_length;
  }

  // Field name: active_area_location
  {
    size_t size = ros_message->active_area_location.size;
    auto array_ptr = ros_message->active_area_location.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: needle_x_axis
  {
    size_t size = ros_message->needle_x_axis.size;
    auto array_ptr = ros_message->needle_x_axis.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: needle_y_axis
  {
    size_t size = ros_message->needle_y_axis.size;
    auto array_ptr = ros_message->needle_y_axis.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: needle_z_axis
  {
    size_t size = ros_message->needle_z_axis.size;
    auto array_ptr = ros_message->needle_z_axis.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: needle_slope
  {
    size_t size = ros_message->needle_slope.size;
    auto array_ptr = ros_message->needle_slope.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _NeedleShape__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _NeedleShape__ros_msg_type * ros_message = static_cast<_NeedleShape__ros_msg_type *>(untyped_ros_message);
  // Field name: needle_total_length
  {
    cdr >> ros_message->needle_total_length;
  }

  // Field name: active_area_location
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->active_area_location.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->active_area_location);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->active_area_location, size)) {
      fprintf(stderr, "failed to create array for field 'active_area_location'");
      return false;
    }
    auto array_ptr = ros_message->active_area_location.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: needle_x_axis
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->needle_x_axis.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->needle_x_axis);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->needle_x_axis, size)) {
      fprintf(stderr, "failed to create array for field 'needle_x_axis'");
      return false;
    }
    auto array_ptr = ros_message->needle_x_axis.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: needle_y_axis
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->needle_y_axis.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->needle_y_axis);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->needle_y_axis, size)) {
      fprintf(stderr, "failed to create array for field 'needle_y_axis'");
      return false;
    }
    auto array_ptr = ros_message->needle_y_axis.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: needle_z_axis
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->needle_z_axis.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->needle_z_axis);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->needle_z_axis, size)) {
      fprintf(stderr, "failed to create array for field 'needle_z_axis'");
      return false;
    }
    auto array_ptr = ros_message->needle_z_axis.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: needle_slope
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->needle_slope.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->needle_slope);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->needle_slope, size)) {
      fprintf(stderr, "failed to create array for field 'needle_slope'");
      return false;
    }
    auto array_ptr = ros_message->needle_slope.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_fbg_msgs
size_t get_serialized_size_fbg_msgs__msg__NeedleShape(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _NeedleShape__ros_msg_type * ros_message = static_cast<const _NeedleShape__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name needle_total_length
  {
    size_t item_size = sizeof(ros_message->needle_total_length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name active_area_location
  {
    size_t array_size = ros_message->active_area_location.size;
    auto array_ptr = ros_message->active_area_location.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name needle_x_axis
  {
    size_t array_size = ros_message->needle_x_axis.size;
    auto array_ptr = ros_message->needle_x_axis.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name needle_y_axis
  {
    size_t array_size = ros_message->needle_y_axis.size;
    auto array_ptr = ros_message->needle_y_axis.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name needle_z_axis
  {
    size_t array_size = ros_message->needle_z_axis.size;
    auto array_ptr = ros_message->needle_z_axis.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name needle_slope
  {
    size_t array_size = ros_message->needle_slope.size;
    auto array_ptr = ros_message->needle_slope.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _NeedleShape__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_fbg_msgs__msg__NeedleShape(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_fbg_msgs
size_t max_serialized_size_fbg_msgs__msg__NeedleShape(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: needle_total_length
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: active_area_location
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: needle_x_axis
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: needle_y_axis
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: needle_z_axis
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: needle_slope
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

static size_t _NeedleShape__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_fbg_msgs__msg__NeedleShape(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_NeedleShape = {
  "fbg_msgs::msg",
  "NeedleShape",
  _NeedleShape__cdr_serialize,
  _NeedleShape__cdr_deserialize,
  _NeedleShape__get_serialized_size,
  _NeedleShape__max_serialized_size
};

static rosidl_message_type_support_t _NeedleShape__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_NeedleShape,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fbg_msgs, msg, NeedleShape)() {
  return &_NeedleShape__type_support;
}

#if defined(__cplusplus)
}
#endif
