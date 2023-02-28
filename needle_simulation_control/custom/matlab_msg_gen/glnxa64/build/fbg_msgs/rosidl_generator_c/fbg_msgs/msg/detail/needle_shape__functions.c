// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fbg_msgs:msg/NeedleShape.idl
// generated code does not contain a copyright notice
#include "fbg_msgs/msg/detail/needle_shape__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `active_area_location`
// Member `needle_x_axis`
// Member `needle_y_axis`
// Member `needle_z_axis`
// Member `needle_slope`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
fbg_msgs__msg__NeedleShape__init(fbg_msgs__msg__NeedleShape * msg)
{
  if (!msg) {
    return false;
  }
  // needle_total_length
  // active_area_location
  if (!rosidl_runtime_c__double__Sequence__init(&msg->active_area_location, 0)) {
    fbg_msgs__msg__NeedleShape__fini(msg);
    return false;
  }
  // needle_x_axis
  if (!rosidl_runtime_c__double__Sequence__init(&msg->needle_x_axis, 0)) {
    fbg_msgs__msg__NeedleShape__fini(msg);
    return false;
  }
  // needle_y_axis
  if (!rosidl_runtime_c__double__Sequence__init(&msg->needle_y_axis, 0)) {
    fbg_msgs__msg__NeedleShape__fini(msg);
    return false;
  }
  // needle_z_axis
  if (!rosidl_runtime_c__double__Sequence__init(&msg->needle_z_axis, 0)) {
    fbg_msgs__msg__NeedleShape__fini(msg);
    return false;
  }
  // needle_slope
  if (!rosidl_runtime_c__double__Sequence__init(&msg->needle_slope, 0)) {
    fbg_msgs__msg__NeedleShape__fini(msg);
    return false;
  }
  return true;
}

void
fbg_msgs__msg__NeedleShape__fini(fbg_msgs__msg__NeedleShape * msg)
{
  if (!msg) {
    return;
  }
  // needle_total_length
  // active_area_location
  rosidl_runtime_c__double__Sequence__fini(&msg->active_area_location);
  // needle_x_axis
  rosidl_runtime_c__double__Sequence__fini(&msg->needle_x_axis);
  // needle_y_axis
  rosidl_runtime_c__double__Sequence__fini(&msg->needle_y_axis);
  // needle_z_axis
  rosidl_runtime_c__double__Sequence__fini(&msg->needle_z_axis);
  // needle_slope
  rosidl_runtime_c__double__Sequence__fini(&msg->needle_slope);
}

fbg_msgs__msg__NeedleShape *
fbg_msgs__msg__NeedleShape__create()
{
  fbg_msgs__msg__NeedleShape * msg = (fbg_msgs__msg__NeedleShape *)malloc(sizeof(fbg_msgs__msg__NeedleShape));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fbg_msgs__msg__NeedleShape));
  bool success = fbg_msgs__msg__NeedleShape__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
fbg_msgs__msg__NeedleShape__destroy(fbg_msgs__msg__NeedleShape * msg)
{
  if (msg) {
    fbg_msgs__msg__NeedleShape__fini(msg);
  }
  free(msg);
}


bool
fbg_msgs__msg__NeedleShape__Sequence__init(fbg_msgs__msg__NeedleShape__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  fbg_msgs__msg__NeedleShape * data = NULL;
  if (size) {
    data = (fbg_msgs__msg__NeedleShape *)calloc(size, sizeof(fbg_msgs__msg__NeedleShape));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fbg_msgs__msg__NeedleShape__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fbg_msgs__msg__NeedleShape__fini(&data[i - 1]);
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
fbg_msgs__msg__NeedleShape__Sequence__fini(fbg_msgs__msg__NeedleShape__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      fbg_msgs__msg__NeedleShape__fini(&array->data[i]);
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

fbg_msgs__msg__NeedleShape__Sequence *
fbg_msgs__msg__NeedleShape__Sequence__create(size_t size)
{
  fbg_msgs__msg__NeedleShape__Sequence * array = (fbg_msgs__msg__NeedleShape__Sequence *)malloc(sizeof(fbg_msgs__msg__NeedleShape__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = fbg_msgs__msg__NeedleShape__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
fbg_msgs__msg__NeedleShape__Sequence__destroy(fbg_msgs__msg__NeedleShape__Sequence * array)
{
  if (array) {
    fbg_msgs__msg__NeedleShape__Sequence__fini(array);
  }
  free(array);
}
