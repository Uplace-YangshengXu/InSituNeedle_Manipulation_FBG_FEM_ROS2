// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fbg_msgs:srv/FindNorm.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__SRV__DETAIL__FIND_NORM__STRUCT_H_
#define FBG_MSGS__SRV__DETAIL__FIND_NORM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/FindNorm in the package fbg_msgs.
typedef struct fbg_msgs__srv__FindNorm_Request
{
  double input;
} fbg_msgs__srv__FindNorm_Request;

// Struct for a sequence of fbg_msgs__srv__FindNorm_Request.
typedef struct fbg_msgs__srv__FindNorm_Request__Sequence
{
  fbg_msgs__srv__FindNorm_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fbg_msgs__srv__FindNorm_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/FindNorm in the package fbg_msgs.
typedef struct fbg_msgs__srv__FindNorm_Response
{
  double norm;
} fbg_msgs__srv__FindNorm_Response;

// Struct for a sequence of fbg_msgs__srv__FindNorm_Response.
typedef struct fbg_msgs__srv__FindNorm_Response__Sequence
{
  fbg_msgs__srv__FindNorm_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fbg_msgs__srv__FindNorm_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FBG_MSGS__SRV__DETAIL__FIND_NORM__STRUCT_H_
