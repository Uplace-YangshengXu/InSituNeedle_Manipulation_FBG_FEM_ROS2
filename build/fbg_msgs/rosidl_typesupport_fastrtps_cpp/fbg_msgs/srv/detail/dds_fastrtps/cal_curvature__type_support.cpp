// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from fbg_msgs:srv/CalCurvature.idl
// generated code does not contain a copyright notice
#include "fbg_msgs/srv/detail/cal_curvature__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fbg_msgs/srv/detail/cal_curvature__struct.hpp"

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

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fbg_msgs
cdr_serialize(
  const fbg_msgs::srv::CalCurvature_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: command
  cdr << ros_message.command;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fbg_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  fbg_msgs::srv::CalCurvature_Request & ros_message)
{
  // Member: command
  cdr >> ros_message.command;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fbg_msgs
get_serialized_size(
  const fbg_msgs::srv::CalCurvature_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: command
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.command.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fbg_msgs
max_serialized_size_CalCurvature_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: command
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

static bool _CalCurvature_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const fbg_msgs::srv::CalCurvature_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _CalCurvature_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<fbg_msgs::srv::CalCurvature_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _CalCurvature_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const fbg_msgs::srv::CalCurvature_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _CalCurvature_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_CalCurvature_Request(full_bounded, 0);
}

static message_type_support_callbacks_t _CalCurvature_Request__callbacks = {
  "fbg_msgs::srv",
  "CalCurvature_Request",
  _CalCurvature_Request__cdr_serialize,
  _CalCurvature_Request__cdr_deserialize,
  _CalCurvature_Request__get_serialized_size,
  _CalCurvature_Request__max_serialized_size
};

static rosidl_message_type_support_t _CalCurvature_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_CalCurvature_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace fbg_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_fbg_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<fbg_msgs::srv::CalCurvature_Request>()
{
  return &fbg_msgs::srv::typesupport_fastrtps_cpp::_CalCurvature_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fbg_msgs, srv, CalCurvature_Request)() {
  return &fbg_msgs::srv::typesupport_fastrtps_cpp::_CalCurvature_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace fbg_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const fbg_msgs::msg::Curvature &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  fbg_msgs::msg::Curvature &);
size_t get_serialized_size(
  const fbg_msgs::msg::Curvature &,
  size_t current_alignment);
size_t
max_serialized_size_Curvature(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace fbg_msgs


namespace fbg_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fbg_msgs
cdr_serialize(
  const fbg_msgs::srv::CalCurvature_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: curvature
  fbg_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.curvature,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fbg_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  fbg_msgs::srv::CalCurvature_Response & ros_message)
{
  // Member: curvature
  fbg_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.curvature);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fbg_msgs
get_serialized_size(
  const fbg_msgs::srv::CalCurvature_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: curvature

  current_alignment +=
    fbg_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.curvature, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fbg_msgs
max_serialized_size_CalCurvature_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: curvature
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        fbg_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Curvature(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _CalCurvature_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const fbg_msgs::srv::CalCurvature_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _CalCurvature_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<fbg_msgs::srv::CalCurvature_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _CalCurvature_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const fbg_msgs::srv::CalCurvature_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _CalCurvature_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_CalCurvature_Response(full_bounded, 0);
}

static message_type_support_callbacks_t _CalCurvature_Response__callbacks = {
  "fbg_msgs::srv",
  "CalCurvature_Response",
  _CalCurvature_Response__cdr_serialize,
  _CalCurvature_Response__cdr_deserialize,
  _CalCurvature_Response__get_serialized_size,
  _CalCurvature_Response__max_serialized_size
};

static rosidl_message_type_support_t _CalCurvature_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_CalCurvature_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace fbg_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_fbg_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<fbg_msgs::srv::CalCurvature_Response>()
{
  return &fbg_msgs::srv::typesupport_fastrtps_cpp::_CalCurvature_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fbg_msgs, srv, CalCurvature_Response)() {
  return &fbg_msgs::srv::typesupport_fastrtps_cpp::_CalCurvature_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace fbg_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _CalCurvature__callbacks = {
  "fbg_msgs::srv",
  "CalCurvature",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fbg_msgs, srv, CalCurvature_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fbg_msgs, srv, CalCurvature_Response)(),
};

static rosidl_service_type_support_t _CalCurvature__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_CalCurvature__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace fbg_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_fbg_msgs
const rosidl_service_type_support_t *
get_service_type_support_handle<fbg_msgs::srv::CalCurvature>()
{
  return &fbg_msgs::srv::typesupport_fastrtps_cpp::_CalCurvature__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fbg_msgs, srv, CalCurvature)() {
  return &fbg_msgs::srv::typesupport_fastrtps_cpp::_CalCurvature__handle;
}

#ifdef __cplusplus
}
#endif
