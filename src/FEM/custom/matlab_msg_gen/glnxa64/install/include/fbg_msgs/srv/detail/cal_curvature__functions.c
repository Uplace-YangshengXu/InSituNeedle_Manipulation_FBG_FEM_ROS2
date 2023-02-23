// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fbg_msgs:srv/CalCurvature.idl
// generated code does not contain a copyright notice
#include "fbg_msgs/srv/detail/cal_curvature__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Include directives for member types
// Member `command`
#include "rosidl_runtime_c/string_functions.h"

bool
fbg_msgs__srv__CalCurvature_Request__init(fbg_msgs__srv__CalCurvature_Request * msg)
{
  if (!msg) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__init(&msg->command)) {
    fbg_msgs__srv__CalCurvature_Request__fini(msg);
    return false;
  }
  return true;
}

void
fbg_msgs__srv__CalCurvature_Request__fini(fbg_msgs__srv__CalCurvature_Request * msg)
{
  if (!msg) {
    return;
  }
  // command
  rosidl_runtime_c__String__fini(&msg->command);
}

fbg_msgs__srv__CalCurvature_Request *
fbg_msgs__srv__CalCurvature_Request__create()
{
  fbg_msgs__srv__CalCurvature_Request * msg = (fbg_msgs__srv__CalCurvature_Request *)malloc(sizeof(fbg_msgs__srv__CalCurvature_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fbg_msgs__srv__CalCurvature_Request));
  bool success = fbg_msgs__srv__CalCurvature_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
fbg_msgs__srv__CalCurvature_Request__destroy(fbg_msgs__srv__CalCurvature_Request * msg)
{
  if (msg) {
    fbg_msgs__srv__CalCurvature_Request__fini(msg);
  }
  free(msg);
}


bool
fbg_msgs__srv__CalCurvature_Request__Sequence__init(fbg_msgs__srv__CalCurvature_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  fbg_msgs__srv__CalCurvature_Request * data = NULL;
  if (size) {
    data = (fbg_msgs__srv__CalCurvature_Request *)calloc(size, sizeof(fbg_msgs__srv__CalCurvature_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fbg_msgs__srv__CalCurvature_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fbg_msgs__srv__CalCurvature_Request__fini(&data[i - 1]);
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
fbg_msgs__srv__CalCurvature_Request__Sequence__fini(fbg_msgs__srv__CalCurvature_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      fbg_msgs__srv__CalCurvature_Request__fini(&array->data[i]);
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

fbg_msgs__srv__CalCurvature_Request__Sequence *
fbg_msgs__srv__CalCurvature_Request__Sequence__create(size_t size)
{
  fbg_msgs__srv__CalCurvature_Request__Sequence * array = (fbg_msgs__srv__CalCurvature_Request__Sequence *)malloc(sizeof(fbg_msgs__srv__CalCurvature_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = fbg_msgs__srv__CalCurvature_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
fbg_msgs__srv__CalCurvature_Request__Sequence__destroy(fbg_msgs__srv__CalCurvature_Request__Sequence * array)
{
  if (array) {
    fbg_msgs__srv__CalCurvature_Request__Sequence__fini(array);
  }
  free(array);
}


// Include directives for member types
// Member `curvature`
#include "fbg_msgs/msg/detail/curvature__functions.h"

bool
fbg_msgs__srv__CalCurvature_Response__init(fbg_msgs__srv__CalCurvature_Response * msg)
{
  if (!msg) {
    return false;
  }
  // curvature
  if (!fbg_msgs__msg__Curvature__init(&msg->curvature)) {
    fbg_msgs__srv__CalCurvature_Response__fini(msg);
    return false;
  }
  return true;
}

void
fbg_msgs__srv__CalCurvature_Response__fini(fbg_msgs__srv__CalCurvature_Response * msg)
{
  if (!msg) {
    return;
  }
  // curvature
  fbg_msgs__msg__Curvature__fini(&msg->curvature);
}

fbg_msgs__srv__CalCurvature_Response *
fbg_msgs__srv__CalCurvature_Response__create()
{
  fbg_msgs__srv__CalCurvature_Response * msg = (fbg_msgs__srv__CalCurvature_Response *)malloc(sizeof(fbg_msgs__srv__CalCurvature_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fbg_msgs__srv__CalCurvature_Response));
  bool success = fbg_msgs__srv__CalCurvature_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
fbg_msgs__srv__CalCurvature_Response__destroy(fbg_msgs__srv__CalCurvature_Response * msg)
{
  if (msg) {
    fbg_msgs__srv__CalCurvature_Response__fini(msg);
  }
  free(msg);
}


bool
fbg_msgs__srv__CalCurvature_Response__Sequence__init(fbg_msgs__srv__CalCurvature_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  fbg_msgs__srv__CalCurvature_Response * data = NULL;
  if (size) {
    data = (fbg_msgs__srv__CalCurvature_Response *)calloc(size, sizeof(fbg_msgs__srv__CalCurvature_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fbg_msgs__srv__CalCurvature_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fbg_msgs__srv__CalCurvature_Response__fini(&data[i - 1]);
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
fbg_msgs__srv__CalCurvature_Response__Sequence__fini(fbg_msgs__srv__CalCurvature_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      fbg_msgs__srv__CalCurvature_Response__fini(&array->data[i]);
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

fbg_msgs__srv__CalCurvature_Response__Sequence *
fbg_msgs__srv__CalCurvature_Response__Sequence__create(size_t size)
{
  fbg_msgs__srv__CalCurvature_Response__Sequence * array = (fbg_msgs__srv__CalCurvature_Response__Sequence *)malloc(sizeof(fbg_msgs__srv__CalCurvature_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = fbg_msgs__srv__CalCurvature_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
fbg_msgs__srv__CalCurvature_Response__Sequence__destroy(fbg_msgs__srv__CalCurvature_Response__Sequence * array)
{
  if (array) {
    fbg_msgs__srv__CalCurvature_Response__Sequence__fini(array);
  }
  free(array);
}
