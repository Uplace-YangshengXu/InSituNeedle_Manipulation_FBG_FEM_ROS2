// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fbg_msgs:msg/Curvature.idl
// generated code does not contain a copyright notice
#include "fbg_msgs/msg/detail/curvature__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `curvature_xy`
// Member `curvature_xz`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
fbg_msgs__msg__Curvature__init(fbg_msgs__msg__Curvature * msg)
{
  if (!msg) {
    return false;
  }
  // curvature_xy
  if (!rosidl_runtime_c__double__Sequence__init(&msg->curvature_xy, 0)) {
    fbg_msgs__msg__Curvature__fini(msg);
    return false;
  }
  // curvature_xz
  if (!rosidl_runtime_c__double__Sequence__init(&msg->curvature_xz, 0)) {
    fbg_msgs__msg__Curvature__fini(msg);
    return false;
  }
  return true;
}

void
fbg_msgs__msg__Curvature__fini(fbg_msgs__msg__Curvature * msg)
{
  if (!msg) {
    return;
  }
  // curvature_xy
  rosidl_runtime_c__double__Sequence__fini(&msg->curvature_xy);
  // curvature_xz
  rosidl_runtime_c__double__Sequence__fini(&msg->curvature_xz);
}

fbg_msgs__msg__Curvature *
fbg_msgs__msg__Curvature__create()
{
  fbg_msgs__msg__Curvature * msg = (fbg_msgs__msg__Curvature *)malloc(sizeof(fbg_msgs__msg__Curvature));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fbg_msgs__msg__Curvature));
  bool success = fbg_msgs__msg__Curvature__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
fbg_msgs__msg__Curvature__destroy(fbg_msgs__msg__Curvature * msg)
{
  if (msg) {
    fbg_msgs__msg__Curvature__fini(msg);
  }
  free(msg);
}


bool
fbg_msgs__msg__Curvature__Sequence__init(fbg_msgs__msg__Curvature__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  fbg_msgs__msg__Curvature * data = NULL;
  if (size) {
    data = (fbg_msgs__msg__Curvature *)calloc(size, sizeof(fbg_msgs__msg__Curvature));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fbg_msgs__msg__Curvature__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fbg_msgs__msg__Curvature__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
fbg_msgs__msg__Curvature__Sequence__fini(fbg_msgs__msg__Curvature__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      fbg_msgs__msg__Curvature__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

fbg_msgs__msg__Curvature__Sequence *
fbg_msgs__msg__Curvature__Sequence__create(size_t size)
{
  fbg_msgs__msg__Curvature__Sequence * array = (fbg_msgs__msg__Curvature__Sequence *)malloc(sizeof(fbg_msgs__msg__Curvature__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = fbg_msgs__msg__Curvature__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
fbg_msgs__msg__Curvature__Sequence__destroy(fbg_msgs__msg__Curvature__Sequence * array)
{
  if (array) {
    fbg_msgs__msg__Curvature__Sequence__fini(array);
  }
  free(array);
}
