// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from fbg_msgs:srv/CalCurvature.idl
// generated code does not contain a copyright notice
#include "fbg_msgs/srv/detail/cal_curvature__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "fbg_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "fbg_msgs/srv/detail/cal_curvature__struct.h"
#include "fbg_msgs/srv/detail/cal_curvature__functions.h"
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

#include "rosidl_runtime_c/string.h"  // command
#include "rosidl_runtime_c/string_functions.h"  // command

// forward declare type support functions


using _CalCurvature_Request__ros_msg_type = fbg_msgs__srv__CalCurvature_Request;

static bool _CalCurvature_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _CalCurvature_Request__ros_msg_type * ros_message = static_cast<const _CalCurvature_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: command
  {
    const rosidl_runtime_c__String * str = &ros_message->command;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _CalCurvature_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _CalCurvature_Request__ros_msg_type * ros_message = static_cast<_CalCurvature_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: command
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->command.data) {
      rosidl_runtime_c__String__init(&ros_message->command);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->command,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'command'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_fbg_msgs
size_t get_serialized_size_fbg_msgs__srv__CalCurvature_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CalCurvature_Request__ros_msg_type * ros_message = static_cast<const _CalCurvature_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name command
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->command.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _CalCurvature_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_fbg_msgs__srv__CalCurvature_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_fbg_msgs
size_t max_serialized_size_fbg_msgs__srv__CalCurvature_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: command
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _CalCurvature_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_fbg_msgs__srv__CalCurvature_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_CalCurvature_Request = {
  "fbg_msgs::srv",
  "CalCurvature_Request",
  _CalCurvature_Request__cdr_serialize,
  _CalCurvature_Request__cdr_deserialize,
  _CalCurvature_Request__get_serialized_size,
  _CalCurvature_Request__max_serialized_size
};

static rosidl_message_type_support_t _CalCurvature_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CalCurvature_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fbg_msgs, srv, CalCurvature_Request)() {
  return &_CalCurvature_Request__type_support;
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
// #include "fbg_msgs/srv/detail/cal_curvature__struct.h"
// already included above
// #include "fbg_msgs/srv/detail/cal_curvature__functions.h"
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

#include "fbg_msgs/msg/detail/curvature__functions.h"  // curvature

// forward declare type support functions
size_t get_serialized_size_fbg_msgs__msg__Curvature(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_fbg_msgs__msg__Curvature(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fbg_msgs, msg, Curvature)();


using _CalCurvature_Response__ros_msg_type = fbg_msgs__srv__CalCurvature_Response;

static bool _CalCurvature_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _CalCurvature_Response__ros_msg_type * ros_message = static_cast<const _CalCurvature_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: curvature
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, fbg_msgs, msg, Curvature
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->curvature, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _CalCurvature_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _CalCurvature_Response__ros_msg_type * ros_message = static_cast<_CalCurvature_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: curvature
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, fbg_msgs, msg, Curvature
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->curvature))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_fbg_msgs
size_t get_serialized_size_fbg_msgs__srv__CalCurvature_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CalCurvature_Response__ros_msg_type * ros_message = static_cast<const _CalCurvature_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name curvature

  current_alignment += get_serialized_size_fbg_msgs__msg__Curvature(
    &(ros_message->curvature), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _CalCurvature_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_fbg_msgs__srv__CalCurvature_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_fbg_msgs
size_t max_serialized_size_fbg_msgs__srv__CalCurvature_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: curvature
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_fbg_msgs__msg__Curvature(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _CalCurvature_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_fbg_msgs__srv__CalCurvature_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_CalCurvature_Response = {
  "fbg_msgs::srv",
  "CalCurvature_Response",
  _CalCurvature_Response__cdr_serialize,
  _CalCurvature_Response__cdr_deserialize,
  _CalCurvature_Response__get_serialized_size,
  _CalCurvature_Response__max_serialized_size
};

static rosidl_message_type_support_t _CalCurvature_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CalCurvature_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fbg_msgs, srv, CalCurvature_Response)() {
  return &_CalCurvature_Response__type_support;
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
#include "fbg_msgs/srv/cal_curvature.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t CalCurvature__callbacks = {
  "fbg_msgs::srv",
  "CalCurvature",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fbg_msgs, srv, CalCurvature_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fbg_msgs, srv, CalCurvature_Response)(),
};

static rosidl_service_type_support_t CalCurvature__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &CalCurvature__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fbg_msgs, srv, CalCurvature)() {
  return &CalCurvature__handle;
}

#if defined(__cplusplus)
}
#endif
