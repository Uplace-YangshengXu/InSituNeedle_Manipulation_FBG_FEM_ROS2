// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from assignment1_msgs:srv/FindNorm.idl
// generated code does not contain a copyright notice
#include "assignment1_msgs/srv/detail/find_norm__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool
assignment1_msgs__srv__FindNorm_Request__init(assignment1_msgs__srv__FindNorm_Request * msg)
{
  if (!msg) {
    return false;
  }
  // input
  return true;
}

void
assignment1_msgs__srv__FindNorm_Request__fini(assignment1_msgs__srv__FindNorm_Request * msg)
{
  if (!msg) {
    return;
  }
  // input
}

assignment1_msgs__srv__FindNorm_Request *
assignment1_msgs__srv__FindNorm_Request__create()
{
  assignment1_msgs__srv__FindNorm_Request * msg = (assignment1_msgs__srv__FindNorm_Request *)malloc(sizeof(assignment1_msgs__srv__FindNorm_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(assignment1_msgs__srv__FindNorm_Request));
  bool success = assignment1_msgs__srv__FindNorm_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
assignment1_msgs__srv__FindNorm_Request__destroy(assignment1_msgs__srv__FindNorm_Request * msg)
{
  if (msg) {
    assignment1_msgs__srv__FindNorm_Request__fini(msg);
  }
  free(msg);
}


bool
assignment1_msgs__srv__FindNorm_Request__Sequence__init(assignment1_msgs__srv__FindNorm_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  assignment1_msgs__srv__FindNorm_Request * data = NULL;
  if (size) {
    data = (assignment1_msgs__srv__FindNorm_Request *)calloc(size, sizeof(assignment1_msgs__srv__FindNorm_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = assignment1_msgs__srv__FindNorm_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        assignment1_msgs__srv__FindNorm_Request__fini(&data[i - 1]);
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
assignment1_msgs__srv__FindNorm_Request__Sequence__fini(assignment1_msgs__srv__FindNorm_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      assignment1_msgs__srv__FindNorm_Request__fini(&array->data[i]);
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

assignment1_msgs__srv__FindNorm_Request__Sequence *
assignment1_msgs__srv__FindNorm_Request__Sequence__create(size_t size)
{
  assignment1_msgs__srv__FindNorm_Request__Sequence * array = (assignment1_msgs__srv__FindNorm_Request__Sequence *)malloc(sizeof(assignment1_msgs__srv__FindNorm_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = assignment1_msgs__srv__FindNorm_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
assignment1_msgs__srv__FindNorm_Request__Sequence__destroy(assignment1_msgs__srv__FindNorm_Request__Sequence * array)
{
  if (array) {
    assignment1_msgs__srv__FindNorm_Request__Sequence__fini(array);
  }
  free(array);
}


bool
assignment1_msgs__srv__FindNorm_Response__init(assignment1_msgs__srv__FindNorm_Response * msg)
{
  if (!msg) {
    return false;
  }
  // norm
  return true;
}

void
assignment1_msgs__srv__FindNorm_Response__fini(assignment1_msgs__srv__FindNorm_Response * msg)
{
  if (!msg) {
    return;
  }
  // norm
}

assignment1_msgs__srv__FindNorm_Response *
assignment1_msgs__srv__FindNorm_Response__create()
{
  assignment1_msgs__srv__FindNorm_Response * msg = (assignment1_msgs__srv__FindNorm_Response *)malloc(sizeof(assignment1_msgs__srv__FindNorm_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(assignment1_msgs__srv__FindNorm_Response));
  bool success = assignment1_msgs__srv__FindNorm_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
assignment1_msgs__srv__FindNorm_Response__destroy(assignment1_msgs__srv__FindNorm_Response * msg)
{
  if (msg) {
    assignment1_msgs__srv__FindNorm_Response__fini(msg);
  }
  free(msg);
}


bool
assignment1_msgs__srv__FindNorm_Response__Sequence__init(assignment1_msgs__srv__FindNorm_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  assignment1_msgs__srv__FindNorm_Response * data = NULL;
  if (size) {
    data = (assignment1_msgs__srv__FindNorm_Response *)calloc(size, sizeof(assignment1_msgs__srv__FindNorm_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = assignment1_msgs__srv__FindNorm_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        assignment1_msgs__srv__FindNorm_Response__fini(&data[i - 1]);
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
assignment1_msgs__srv__FindNorm_Response__Sequence__fini(assignment1_msgs__srv__FindNorm_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      assignment1_msgs__srv__FindNorm_Response__fini(&array->data[i]);
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

assignment1_msgs__srv__FindNorm_Response__Sequence *
assignment1_msgs__srv__FindNorm_Response__Sequence__create(size_t size)
{
  assignment1_msgs__srv__FindNorm_Response__Sequence * array = (assignment1_msgs__srv__FindNorm_Response__Sequence *)malloc(sizeof(assignment1_msgs__srv__FindNorm_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = assignment1_msgs__srv__FindNorm_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
assignment1_msgs__srv__FindNorm_Response__Sequence__destroy(assignment1_msgs__srv__FindNorm_Response__Sequence * array)
{
  if (array) {
    assignment1_msgs__srv__FindNorm_Response__Sequence__fini(array);
  }
  free(array);
}
