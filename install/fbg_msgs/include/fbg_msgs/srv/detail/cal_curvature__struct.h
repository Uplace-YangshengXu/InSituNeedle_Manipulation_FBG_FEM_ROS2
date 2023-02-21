// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fbg_msgs:srv/CalCurvature.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__SRV__DETAIL__CAL_CURVATURE__STRUCT_H_
#define FBG_MSGS__SRV__DETAIL__CAL_CURVATURE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'fbg_reading'
#include "fbg_msgs/msg/detail/fbg_reading__struct.h"

// Struct defined in srv/CalCurvature in the package fbg_msgs.
typedef struct fbg_msgs__srv__CalCurvature_Request
{
  fbg_msgs__msg__FbgReading fbg_reading;
} fbg_msgs__srv__CalCurvature_Request;

// Struct for a sequence of fbg_msgs__srv__CalCurvature_Request.
typedef struct fbg_msgs__srv__CalCurvature_Request__Sequence
{
  fbg_msgs__srv__CalCurvature_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fbg_msgs__srv__CalCurvature_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'curvature'
#include "fbg_msgs/msg/detail/curvature__struct.h"

// Struct defined in srv/CalCurvature in the package fbg_msgs.
typedef struct fbg_msgs__srv__CalCurvature_Response
{
  fbg_msgs__msg__Curvature curvature;
} fbg_msgs__srv__CalCurvature_Response;

// Struct for a sequence of fbg_msgs__srv__CalCurvature_Response.
typedef struct fbg_msgs__srv__CalCurvature_Response__Sequence
{
  fbg_msgs__srv__CalCurvature_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fbg_msgs__srv__CalCurvature_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FBG_MSGS__SRV__DETAIL__CAL_CURVATURE__STRUCT_H_
