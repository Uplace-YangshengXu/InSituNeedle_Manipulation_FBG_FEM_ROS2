// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from fbg_msgs:msg/Curvature.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "fbg_msgs/msg/detail/curvature__rosidl_typesupport_introspection_c.h"
#include "fbg_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "fbg_msgs/msg/detail/curvature__functions.h"
#include "fbg_msgs/msg/detail/curvature__struct.h"


// Include directives for member types
// Member `curvature_xy`
// Member `curvature_xz`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Curvature__rosidl_typesupport_introspection_c__Curvature_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fbg_msgs__msg__Curvature__init(message_memory);
}

void Curvature__rosidl_typesupport_introspection_c__Curvature_fini_function(void * message_memory)
{
  fbg_msgs__msg__Curvature__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Curvature__rosidl_typesupport_introspection_c__Curvature_message_member_array[2] = {
  {
    "curvature_xy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs__msg__Curvature, curvature_xy),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "curvature_xz",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs__msg__Curvature, curvature_xz),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Curvature__rosidl_typesupport_introspection_c__Curvature_message_members = {
  "fbg_msgs__msg",  // message namespace
  "Curvature",  // message name
  2,  // number of fields
  sizeof(fbg_msgs__msg__Curvature),
  Curvature__rosidl_typesupport_introspection_c__Curvature_message_member_array,  // message members
  Curvature__rosidl_typesupport_introspection_c__Curvature_init_function,  // function to initialize message memory (memory has to be allocated)
  Curvature__rosidl_typesupport_introspection_c__Curvature_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Curvature__rosidl_typesupport_introspection_c__Curvature_message_type_support_handle = {
  0,
  &Curvature__rosidl_typesupport_introspection_c__Curvature_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fbg_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fbg_msgs, msg, Curvature)() {
  if (!Curvature__rosidl_typesupport_introspection_c__Curvature_message_type_support_handle.typesupport_identifier) {
    Curvature__rosidl_typesupport_introspection_c__Curvature_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Curvature__rosidl_typesupport_introspection_c__Curvature_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
