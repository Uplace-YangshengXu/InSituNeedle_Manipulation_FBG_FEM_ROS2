// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from assignment1_msgs:srv/FindNorm.idl
// generated code does not contain a copyright notice

#ifndef ASSIGNMENT1_MSGS__SRV__DETAIL__FIND_NORM__STRUCT_H_
#define ASSIGNMENT1_MSGS__SRV__DETAIL__FIND_NORM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/FindNorm in the package assignment1_msgs.
typedef struct assignment1_msgs__srv__FindNorm_Request
{
  double input;
} assignment1_msgs__srv__FindNorm_Request;

// Struct for a sequence of assignment1_msgs__srv__FindNorm_Request.
typedef struct assignment1_msgs__srv__FindNorm_Request__Sequence
{
  assignment1_msgs__srv__FindNorm_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} assignment1_msgs__srv__FindNorm_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/FindNorm in the package assignment1_msgs.
typedef struct assignment1_msgs__srv__FindNorm_Response
{
  double norm;
} assignment1_msgs__srv__FindNorm_Response;

// Struct for a sequence of assignment1_msgs__srv__FindNorm_Response.
typedef struct assignment1_msgs__srv__FindNorm_Response__Sequence
{
  assignment1_msgs__srv__FindNorm_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} assignment1_msgs__srv__FindNorm_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ASSIGNMENT1_MSGS__SRV__DETAIL__FIND_NORM__STRUCT_H_
