// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fbg_msgs:msg/FbgReading.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__MSG__DETAIL__FBG_READING__STRUCT_H_
#define FBG_MSGS__MSG__DETAIL__FBG_READING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'signal_reading'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/FbgReading in the package fbg_msgs.
typedef struct fbg_msgs__msg__FbgReading
{
  rosidl_runtime_c__double__Sequence signal_reading;
} fbg_msgs__msg__FbgReading;

// Struct for a sequence of fbg_msgs__msg__FbgReading.
typedef struct fbg_msgs__msg__FbgReading__Sequence
{
  fbg_msgs__msg__FbgReading * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fbg_msgs__msg__FbgReading__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FBG_MSGS__MSG__DETAIL__FBG_READING__STRUCT_H_
