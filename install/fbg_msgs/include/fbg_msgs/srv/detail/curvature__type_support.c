// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from fbg_msgs:srv/Curvature.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "fbg_msgs/srv/detail/curvature__rosidl_typesupport_introspection_c.h"
#include "fbg_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "fbg_msgs/srv/detail/curvature__functions.h"
#include "fbg_msgs/srv/detail/curvature__struct.h"


// Include directives for member types
// Member `fbg_reading`
#include "fbg_msgs/msg/fbg_reading.h"
// Member `fbg_reading`
#include "fbg_msgs/msg/detail/fbg_reading__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Curvature_Request__rosidl_typesupport_introspection_c__Curvature_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fbg_msgs__srv__Curvature_Request__init(message_memory);
}

void Curvature_Request__rosidl_typesupport_introspection_c__Curvature_Request_fini_function(void * message_memory)
{
  fbg_msgs__srv__Curvature_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Curvature_Request__rosidl_typesupport_introspection_c__Curvature_Request_message_member_array[1] = {
  {
    "fbg_reading",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs__srv__Curvature_Request, fbg_reading),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Curvature_Request__rosidl_typesupport_introspection_c__Curvature_Request_message_members = {
  "fbg_msgs__srv",  // message namespace
  "Curvature_Request",  // message name
  1,  // number of fields
  sizeof(fbg_msgs__srv__Curvature_Request),
  Curvature_Request__rosidl_typesupport_introspection_c__Curvature_Request_message_member_array,  // message members
  Curvature_Request__rosidl_typesupport_introspection_c__Curvature_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  Curvature_Request__rosidl_typesupport_introspection_c__Curvature_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Curvature_Request__rosidl_typesupport_introspection_c__Curvature_Request_message_type_support_handle = {
  0,
  &Curvature_Request__rosidl_typesupport_introspection_c__Curvature_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fbg_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fbg_msgs, srv, Curvature_Request)() {
  Curvature_Request__rosidl_typesupport_introspection_c__Curvature_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fbg_msgs, msg, FbgReading)();
  if (!Curvature_Request__rosidl_typesupport_introspection_c__Curvature_Request_message_type_support_handle.typesupport_identifier) {
    Curvature_Request__rosidl_typesupport_introspection_c__Curvature_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Curvature_Request__rosidl_typesupport_introspection_c__Curvature_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "fbg_msgs/srv/detail/curvature__rosidl_typesupport_introspection_c.h"
// already included above
// #include "fbg_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "fbg_msgs/srv/detail/curvature__functions.h"
// already included above
// #include "fbg_msgs/srv/detail/curvature__struct.h"


// Include directives for member types
// Member `curvature`
#include "fbg_msgs/msg/curvature.h"
// Member `curvature`
#include "fbg_msgs/msg/detail/curvature__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Curvature_Response__rosidl_typesupport_introspection_c__Curvature_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fbg_msgs__srv__Curvature_Response__init(message_memory);
}

void Curvature_Response__rosidl_typesupport_introspection_c__Curvature_Response_fini_function(void * message_memory)
{
  fbg_msgs__srv__Curvature_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Curvature_Response__rosidl_typesupport_introspection_c__Curvature_Response_message_member_array[1] = {
  {
    "curvature",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs__srv__Curvature_Response, curvature),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Curvature_Response__rosidl_typesupport_introspection_c__Curvature_Response_message_members = {
  "fbg_msgs__srv",  // message namespace
  "Curvature_Response",  // message name
  1,  // number of fields
  sizeof(fbg_msgs__srv__Curvature_Response),
  Curvature_Response__rosidl_typesupport_introspection_c__Curvature_Response_message_member_array,  // message members
  Curvature_Response__rosidl_typesupport_introspection_c__Curvature_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  Curvature_Response__rosidl_typesupport_introspection_c__Curvature_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Curvature_Response__rosidl_typesupport_introspection_c__Curvature_Response_message_type_support_handle = {
  0,
  &Curvature_Response__rosidl_typesupport_introspection_c__Curvature_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fbg_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fbg_msgs, srv, Curvature_Response)() {
  Curvature_Response__rosidl_typesupport_introspection_c__Curvature_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fbg_msgs, msg, Curvature)();
  if (!Curvature_Response__rosidl_typesupport_introspection_c__Curvature_Response_message_type_support_handle.typesupport_identifier) {
    Curvature_Response__rosidl_typesupport_introspection_c__Curvature_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Curvature_Response__rosidl_typesupport_introspection_c__Curvature_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "fbg_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "fbg_msgs/srv/detail/curvature__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers fbg_msgs__srv__detail__curvature__rosidl_typesupport_introspection_c__Curvature_service_members = {
  "fbg_msgs__srv",  // service namespace
  "Curvature",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // fbg_msgs__srv__detail__curvature__rosidl_typesupport_introspection_c__Curvature_Request_message_type_support_handle,
  NULL  // response message
  // fbg_msgs__srv__detail__curvature__rosidl_typesupport_introspection_c__Curvature_Response_message_type_support_handle
};

static rosidl_service_type_support_t fbg_msgs__srv__detail__curvature__rosidl_typesupport_introspection_c__Curvature_service_type_support_handle = {
  0,
  &fbg_msgs__srv__detail__curvature__rosidl_typesupport_introspection_c__Curvature_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fbg_msgs, srv, Curvature_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fbg_msgs, srv, Curvature_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fbg_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fbg_msgs, srv, Curvature)() {
  if (!fbg_msgs__srv__detail__curvature__rosidl_typesupport_introspection_c__Curvature_service_type_support_handle.typesupport_identifier) {
    fbg_msgs__srv__detail__curvature__rosidl_typesupport_introspection_c__Curvature_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)fbg_msgs__srv__detail__curvature__rosidl_typesupport_introspection_c__Curvature_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fbg_msgs, srv, Curvature_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fbg_msgs, srv, Curvature_Response)()->data;
  }

  return &fbg_msgs__srv__detail__curvature__rosidl_typesupport_introspection_c__Curvature_service_type_support_handle;
}
