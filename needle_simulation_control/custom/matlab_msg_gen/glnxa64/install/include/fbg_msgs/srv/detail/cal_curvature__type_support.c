// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from fbg_msgs:srv/CalCurvature.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "fbg_msgs/srv/detail/cal_curvature__rosidl_typesupport_introspection_c.h"
#include "fbg_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "fbg_msgs/srv/detail/cal_curvature__functions.h"
#include "fbg_msgs/srv/detail/cal_curvature__struct.h"


// Include directives for member types
// Member `command`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void CalCurvature_Request__rosidl_typesupport_introspection_c__CalCurvature_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fbg_msgs__srv__CalCurvature_Request__init(message_memory);
}

void CalCurvature_Request__rosidl_typesupport_introspection_c__CalCurvature_Request_fini_function(void * message_memory)
{
  fbg_msgs__srv__CalCurvature_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember CalCurvature_Request__rosidl_typesupport_introspection_c__CalCurvature_Request_message_member_array[1] = {
  {
    "command",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs__srv__CalCurvature_Request, command),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers CalCurvature_Request__rosidl_typesupport_introspection_c__CalCurvature_Request_message_members = {
  "fbg_msgs__srv",  // message namespace
  "CalCurvature_Request",  // message name
  1,  // number of fields
  sizeof(fbg_msgs__srv__CalCurvature_Request),
  CalCurvature_Request__rosidl_typesupport_introspection_c__CalCurvature_Request_message_member_array,  // message members
  CalCurvature_Request__rosidl_typesupport_introspection_c__CalCurvature_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  CalCurvature_Request__rosidl_typesupport_introspection_c__CalCurvature_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t CalCurvature_Request__rosidl_typesupport_introspection_c__CalCurvature_Request_message_type_support_handle = {
  0,
  &CalCurvature_Request__rosidl_typesupport_introspection_c__CalCurvature_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fbg_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fbg_msgs, srv, CalCurvature_Request)() {
  if (!CalCurvature_Request__rosidl_typesupport_introspection_c__CalCurvature_Request_message_type_support_handle.typesupport_identifier) {
    CalCurvature_Request__rosidl_typesupport_introspection_c__CalCurvature_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &CalCurvature_Request__rosidl_typesupport_introspection_c__CalCurvature_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "fbg_msgs/srv/detail/cal_curvature__rosidl_typesupport_introspection_c.h"
// already included above
// #include "fbg_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "fbg_msgs/srv/detail/cal_curvature__functions.h"
// already included above
// #include "fbg_msgs/srv/detail/cal_curvature__struct.h"


// Include directives for member types
// Member `curvature`
#include "fbg_msgs/msg/curvature.h"
// Member `curvature`
#include "fbg_msgs/msg/detail/curvature__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void CalCurvature_Response__rosidl_typesupport_introspection_c__CalCurvature_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fbg_msgs__srv__CalCurvature_Response__init(message_memory);
}

void CalCurvature_Response__rosidl_typesupport_introspection_c__CalCurvature_Response_fini_function(void * message_memory)
{
  fbg_msgs__srv__CalCurvature_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember CalCurvature_Response__rosidl_typesupport_introspection_c__CalCurvature_Response_message_member_array[1] = {
  {
    "curvature",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs__srv__CalCurvature_Response, curvature),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers CalCurvature_Response__rosidl_typesupport_introspection_c__CalCurvature_Response_message_members = {
  "fbg_msgs__srv",  // message namespace
  "CalCurvature_Response",  // message name
  1,  // number of fields
  sizeof(fbg_msgs__srv__CalCurvature_Response),
  CalCurvature_Response__rosidl_typesupport_introspection_c__CalCurvature_Response_message_member_array,  // message members
  CalCurvature_Response__rosidl_typesupport_introspection_c__CalCurvature_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  CalCurvature_Response__rosidl_typesupport_introspection_c__CalCurvature_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t CalCurvature_Response__rosidl_typesupport_introspection_c__CalCurvature_Response_message_type_support_handle = {
  0,
  &CalCurvature_Response__rosidl_typesupport_introspection_c__CalCurvature_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fbg_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fbg_msgs, srv, CalCurvature_Response)() {
  CalCurvature_Response__rosidl_typesupport_introspection_c__CalCurvature_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fbg_msgs, msg, Curvature)();
  if (!CalCurvature_Response__rosidl_typesupport_introspection_c__CalCurvature_Response_message_type_support_handle.typesupport_identifier) {
    CalCurvature_Response__rosidl_typesupport_introspection_c__CalCurvature_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &CalCurvature_Response__rosidl_typesupport_introspection_c__CalCurvature_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "fbg_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "fbg_msgs/srv/detail/cal_curvature__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers fbg_msgs__srv__detail__cal_curvature__rosidl_typesupport_introspection_c__CalCurvature_service_members = {
  "fbg_msgs__srv",  // service namespace
  "CalCurvature",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // fbg_msgs__srv__detail__cal_curvature__rosidl_typesupport_introspection_c__CalCurvature_Request_message_type_support_handle,
  NULL  // response message
  // fbg_msgs__srv__detail__cal_curvature__rosidl_typesupport_introspection_c__CalCurvature_Response_message_type_support_handle
};

static rosidl_service_type_support_t fbg_msgs__srv__detail__cal_curvature__rosidl_typesupport_introspection_c__CalCurvature_service_type_support_handle = {
  0,
  &fbg_msgs__srv__detail__cal_curvature__rosidl_typesupport_introspection_c__CalCurvature_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fbg_msgs, srv, CalCurvature_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fbg_msgs, srv, CalCurvature_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fbg_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fbg_msgs, srv, CalCurvature)() {
  if (!fbg_msgs__srv__detail__cal_curvature__rosidl_typesupport_introspection_c__CalCurvature_service_type_support_handle.typesupport_identifier) {
    fbg_msgs__srv__detail__cal_curvature__rosidl_typesupport_introspection_c__CalCurvature_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)fbg_msgs__srv__detail__cal_curvature__rosidl_typesupport_introspection_c__CalCurvature_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fbg_msgs, srv, CalCurvature_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fbg_msgs, srv, CalCurvature_Response)()->data;
  }

  return &fbg_msgs__srv__detail__cal_curvature__rosidl_typesupport_introspection_c__CalCurvature_service_type_support_handle;
}
