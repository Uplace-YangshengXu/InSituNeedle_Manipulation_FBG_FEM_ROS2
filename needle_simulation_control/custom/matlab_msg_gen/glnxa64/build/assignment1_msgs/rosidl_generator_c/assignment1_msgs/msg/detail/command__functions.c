// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from assignment1_msgs:msg/Command.idl
// generated code does not contain a copyright notice
#include "assignment1_msgs/msg/detail/command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

bool
assignment1_msgs__msg__Command__init(assignment1_msgs__msg__Command * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    assignment1_msgs__msg__Command__fini(msg);
    return false;
  }
  return true;
}

void
assignment1_msgs__msg__Command__fini(assignment1_msgs__msg__Command * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
}

assignment1_msgs__msg__Command *
assignment1_msgs__msg__Command__create()
{
  assignment1_msgs__msg__Command * msg = (assignment1_msgs__msg__Command *)malloc(sizeof(assignment1_msgs__msg__Command));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(assignment1_msgs__msg__Command));
  bool success = assignment1_msgs__msg__Command__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
assignment1_msgs__msg__Command__destroy(assignment1_msgs__msg__Command * msg)
{
  if (msg) {
    assignment1_msgs__msg__Command__fini(msg);
  }
  free(msg);
}


bool
assignment1_msgs__msg__Command__Sequence__init(assignment1_msgs__msg__Command__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  assignment1_msgs__msg__Command * data = NULL;
  if (size) {
    data = (assignment1_msgs__msg__Command *)calloc(size, sizeof(assignment1_msgs__msg__Command));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = assignment1_msgs__msg__Command__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        assignment1_msgs__msg__Command__fini(&data[i - 1]);
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
assignment1_msgs__msg__Command__Sequence__fini(assignment1_msgs__msg__Command__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      assignment1_msgs__msg__Command__fini(&array->data[i]);
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

assignment1_msgs__msg__Command__Sequence *
assignment1_msgs__msg__Command__Sequence__create(size_t size)
{
  assignment1_msgs__msg__Command__Sequence * array = (assignment1_msgs__msg__Command__Sequence *)malloc(sizeof(assignment1_msgs__msg__Command__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = assignment1_msgs__msg__Command__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
assignment1_msgs__msg__Command__Sequence__destroy(assignment1_msgs__msg__Command__Sequence * array)
{
  if (array) {
    assignment1_msgs__msg__Command__Sequence__fini(array);
  }
  free(array);
}
