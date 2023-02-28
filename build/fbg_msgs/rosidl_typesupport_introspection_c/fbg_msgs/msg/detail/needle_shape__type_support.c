// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from fbg_msgs:msg/NeedleShape.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "fbg_msgs/msg/detail/needle_shape__rosidl_typesupport_introspection_c.h"
#include "fbg_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "fbg_msgs/msg/detail/needle_shape__functions.h"
#include "fbg_msgs/msg/detail/needle_shape__struct.h"


// Include directives for member types
// Member `active_area_location`
// Member `needle_x_axis`
// Member `needle_y_axis`
// Member `needle_z_axis`
// Member `needle_slope`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void NeedleShape__rosidl_typesupport_introspection_c__NeedleShape_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fbg_msgs__msg__NeedleShape__init(message_memory);
}

void NeedleShape__rosidl_typesupport_introspection_c__NeedleShape_fini_function(void * message_memory)
{
  fbg_msgs__msg__NeedleShape__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember NeedleShape__rosidl_typesupport_introspection_c__NeedleShape_message_member_array[6] = {
  {
    "needle_total_length",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs__msg__NeedleShape, needle_total_length),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "active_area_location",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs__msg__NeedleShape, active_area_location),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "needle_x_axis",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs__msg__NeedleShape, needle_x_axis),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "needle_y_axis",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs__msg__NeedleShape, needle_y_axis),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "needle_z_axis",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs__msg__NeedleShape, needle_z_axis),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "needle_slope",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fbg_msgs__msg__NeedleShape, needle_slope),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers NeedleShape__rosidl_typesupport_introspection_c__NeedleShape_message_members = {
  "fbg_msgs__msg",  // message namespace
  "NeedleShape",  // message name
  6,  // number of fields
  sizeof(fbg_msgs__msg__NeedleShape),
  NeedleShape__rosidl_typesupport_introspection_c__NeedleShape_message_member_array,  // message members
  NeedleShape__rosidl_typesupport_introspection_c__NeedleShape_init_function,  // function to initialize message memory (memory has to be allocated)
  NeedleShape__rosidl_typesupport_introspection_c__NeedleShape_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t NeedleShape__rosidl_typesupport_introspection_c__NeedleShape_message_type_support_handle = {
  0,
  &NeedleShape__rosidl_typesupport_introspection_c__NeedleShape_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fbg_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fbg_msgs, msg, NeedleShape)() {
  if (!NeedleShape__rosidl_typesupport_introspection_c__NeedleShape_message_type_support_handle.typesupport_identifier) {
    NeedleShape__rosidl_typesupport_introspection_c__NeedleShape_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &NeedleShape__rosidl_typesupport_introspection_c__NeedleShape_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
