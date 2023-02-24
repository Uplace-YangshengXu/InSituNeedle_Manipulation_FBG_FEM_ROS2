// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from fbg_msgs:srv/FindNorm.idl
// generated code does not contain a copyright notice
#include "fbg_msgs/srv/detail/find_norm__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "fbg_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "fbg_msgs/srv/detail/find_norm__struct.h"
#include "fbg_msgs/srv/detail/find_norm__functions.h"
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


// forward declare type support functions


using _FindNorm_Request__ros_msg_type = fbg_msgs__srv__FindNorm_Request;

static bool _FindNorm_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _FindNorm_Request__ros_msg_type * ros_message = static_cast<const _FindNorm_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: input
  {
    cdr << ros_message->input;
  }

  return true;
}

static bool _FindNorm_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _FindNorm_Request__ros_msg_type * ros_message = static_cast<_FindNorm_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: input
  {
    cdr >> ros_message->input;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_fbg_msgs
size_t get_serialized_size_fbg_msgs__srv__FindNorm_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FindNorm_Request__ros_msg_type * ros_message = static_cast<const _FindNorm_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name input
  {
    size_t item_size = sizeof(ros_message->input);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _FindNorm_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_fbg_msgs__srv__FindNorm_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_fbg_msgs
size_t max_serialized_size_fbg_msgs__srv__FindNorm_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: input
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _FindNorm_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_fbg_msgs__srv__FindNorm_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_FindNorm_Request = {
  "fbg_msgs::srv",
  "FindNorm_Request",
  _FindNorm_Request__cdr_serialize,
  _FindNorm_Request__cdr_deserialize,
  _FindNorm_Request__get_serialized_size,
  _FindNorm_Request__max_serialized_size
};

static rosidl_message_type_support_t _FindNorm_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FindNorm_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fbg_msgs, srv, FindNorm_Request)() {
  return &_FindNorm_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "fbg_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "fbg_msgs/srv/detail/find_norm__struct.h"
// already included above
// #include "fbg_msgs/srv/detail/find_norm__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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


// forward declare type support functions


using _FindNorm_Response__ros_msg_type = fbg_msgs__srv__FindNorm_Response;

static bool _FindNorm_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _FindNorm_Response__ros_msg_type * ros_message = static_cast<const _FindNorm_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: norm
  {
    cdr << ros_message->norm;
  }

  return true;
}

static bool _FindNorm_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _FindNorm_Response__ros_msg_type * ros_message = static_cast<_FindNorm_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: norm
  {
    cdr >> ros_message->norm;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_fbg_msgs
size_t get_serialized_size_fbg_msgs__srv__FindNorm_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FindNorm_Response__ros_msg_type * ros_message = static_cast<const _FindNorm_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name norm
  {
    size_t item_size = sizeof(ros_message->norm);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _FindNorm_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_fbg_msgs__srv__FindNorm_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_fbg_msgs
size_t max_serialized_size_fbg_msgs__srv__FindNorm_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: norm
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _FindNorm_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_fbg_msgs__srv__FindNorm_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_FindNorm_Response = {
  "fbg_msgs::srv",
  "FindNorm_Response",
  _FindNorm_Response__cdr_serialize,
  _FindNorm_Response__cdr_deserialize,
  _FindNorm_Response__get_serialized_size,
  _FindNorm_Response__max_serialized_size
};

static rosidl_message_type_support_t _FindNorm_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FindNorm_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fbg_msgs, srv, FindNorm_Response)() {
  return &_FindNorm_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "fbg_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "fbg_msgs/srv/find_norm.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t FindNorm__callbacks = {
  "fbg_msgs::srv",
  "FindNorm",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fbg_msgs, srv, FindNorm_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fbg_msgs, srv, FindNorm_Response)(),
};

static rosidl_service_type_support_t FindNorm__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &FindNorm__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fbg_msgs, srv, FindNorm)() {
  return &FindNorm__handle;
}

#if defined(__cplusplus)
}
#endif
