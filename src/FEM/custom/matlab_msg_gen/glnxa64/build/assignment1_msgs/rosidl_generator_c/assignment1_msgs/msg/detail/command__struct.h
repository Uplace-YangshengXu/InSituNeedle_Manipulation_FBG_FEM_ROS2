// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from assignment1_msgs:msg/Command.idl
// generated code does not contain a copyright notice

#ifndef ASSIGNMENT1_MSGS__MSG__DETAIL__COMMAND__STRUCT_H_
#define ASSIGNMENT1_MSGS__MSG__DETAIL__COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/Command in the package assignment1_msgs.
typedef struct assignment1_msgs__msg__Command
{
  rosidl_runtime_c__String name;
} assignment1_msgs__msg__Command;

// Struct for a sequence of assignment1_msgs__msg__Command.
typedef struct assignment1_msgs__msg__Command__Sequence
{
  assignment1_msgs__msg__Command * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} assignment1_msgs__msg__Command__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ASSIGNMENT1_MSGS__MSG__DETAIL__COMMAND__STRUCT_H_
