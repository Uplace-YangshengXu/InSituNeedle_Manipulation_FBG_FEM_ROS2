// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from fbg_msgs:msg/NeedleShape.idl
// generated code does not contain a copyright notice
#include "fbg_msgs/msg/detail/needle_shape__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fbg_msgs/msg/detail/needle_shape__struct.hpp"

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
  const fbg_msgs::msg::NeedleShape & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: needle_total_length
  cdr << ros_message.needle_total_length;
  // Member: active_area_location
  {
    cdr << ros_message.active_area_location;
  }
  // Member: needle_x_axis
  {
    cdr << ros_message.needle_x_axis;
  }
  // Member: needle_y_axis
  {
    cdr << ros_message.needle_y_axis;
  }
  // Member: needle_z_axis
  {
    cdr << ros_message.needle_z_axis;
  }
  // Member: needle_slope
  {
    cdr << ros_message.needle_slope;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fbg_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  fbg_msgs::msg::NeedleShape & ros_message)
{
  // Member: needle_total_length
  cdr >> ros_message.needle_total_length;

  // Member: active_area_location
  {
    cdr >> ros_message.active_area_location;
  }

  // Member: needle_x_axis
  {
    cdr >> ros_message.needle_x_axis;
  }

  // Member: needle_y_axis
  {
    cdr >> ros_message.needle_y_axis;
  }

  // Member: needle_z_axis
  {
    cdr >> ros_message.needle_z_axis;
  }

  // Member: needle_slope
  {
    cdr >> ros_message.needle_slope;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fbg_msgs
get_serialized_size(
  const fbg_msgs::msg::NeedleShape & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: needle_total_length
  {
    size_t item_size = sizeof(ros_message.needle_total_length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: active_area_location
  {
    size_t array_size = ros_message.active_area_location.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.active_area_location[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: needle_x_axis
  {
    size_t array_size = ros_message.needle_x_axis.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.needle_x_axis[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: needle_y_axis
  {
    size_t array_size = ros_message.needle_y_axis.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.needle_y_axis[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: needle_z_axis
  {
    size_t array_size = ros_message.needle_z_axis.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.needle_z_axis[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: needle_slope
  {
    size_t array_size = ros_message.needle_slope.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.needle_slope[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fbg_msgs
max_serialized_size_NeedleShape(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: needle_total_length
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: active_area_location
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: needle_x_axis
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: needle_y_axis
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: needle_z_axis
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: needle_slope
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

static bool _NeedleShape__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const fbg_msgs::msg::NeedleShape *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _NeedleShape__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<fbg_msgs::msg::NeedleShape *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _NeedleShape__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const fbg_msgs::msg::NeedleShape *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _NeedleShape__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_NeedleShape(full_bounded, 0);
}

static message_type_support_callbacks_t _NeedleShape__callbacks = {
  "fbg_msgs::msg",
  "NeedleShape",
  _NeedleShape__cdr_serialize,
  _NeedleShape__cdr_deserialize,
  _NeedleShape__get_serialized_size,
  _NeedleShape__max_serialized_size
};

static rosidl_message_type_support_t _NeedleShape__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_NeedleShape__callbacks,
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
get_message_type_support_handle<fbg_msgs::msg::NeedleShape>()
{
  return &fbg_msgs::msg::typesupport_fastrtps_cpp::_NeedleShape__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fbg_msgs, msg, NeedleShape)() {
  return &fbg_msgs::msg::typesupport_fastrtps_cpp::_NeedleShape__handle;
}

#ifdef __cplusplus
}
#endif
