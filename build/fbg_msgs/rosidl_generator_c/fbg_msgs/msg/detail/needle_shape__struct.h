// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fbg_msgs:msg/NeedleShape.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__MSG__DETAIL__NEEDLE_SHAPE__STRUCT_H_
#define FBG_MSGS__MSG__DETAIL__NEEDLE_SHAPE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'active_area_location'
// Member 'needle_x_axis'
// Member 'needle_y_axis'
// Member 'needle_z_axis'
// Member 'needle_slope'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/NeedleShape in the package fbg_msgs.
typedef struct fbg_msgs__msg__NeedleShape
{
  uint8_t needle_total_length;
  rosidl_runtime_c__double__Sequence active_area_location;
  rosidl_runtime_c__double__Sequence needle_x_axis;
  rosidl_runtime_c__double__Sequence needle_y_axis;
  rosidl_runtime_c__double__Sequence needle_z_axis;
  rosidl_runtime_c__double__Sequence needle_slope;
} fbg_msgs__msg__NeedleShape;

// Struct for a sequence of fbg_msgs__msg__NeedleShape.
typedef struct fbg_msgs__msg__NeedleShape__Sequence
{
  fbg_msgs__msg__NeedleShape * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fbg_msgs__msg__NeedleShape__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FBG_MSGS__MSG__DETAIL__NEEDLE_SHAPE__STRUCT_H_
