// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fbg_msgs:msg/FbgReading.idl
// generated code does not contain a copyright notice
#include "fbg_msgs/msg/detail/fbg_reading__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `signal_reading`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
fbg_msgs__msg__FbgReading__init(fbg_msgs__msg__FbgReading * msg)
{
  if (!msg) {
    return false;
  }
  // signal_reading
  if (!rosidl_runtime_c__double__Sequence__init(&msg->signal_reading, 0)) {
    fbg_msgs__msg__FbgReading__fini(msg);
    return false;
  }
  // signal_each_ch
  // total_reading_num
  return true;
}

void
fbg_msgs__msg__FbgReading__fini(fbg_msgs__msg__FbgReading * msg)
{
  if (!msg) {
    return;
  }
  // signal_reading
  rosidl_runtime_c__double__Sequence__fini(&msg->signal_reading);
  // signal_each_ch
  // total_reading_num
}

bool
fbg_msgs__msg__FbgReading__are_equal(const fbg_msgs__msg__FbgReading * lhs, const fbg_msgs__msg__FbgReading * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // signal_reading
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->signal_reading), &(rhs->signal_reading)))
  {
    return false;
  }
  // signal_each_ch
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->signal_each_ch[i] != rhs->signal_each_ch[i]) {
      return false;
    }
  }
  // total_reading_num
  if (lhs->total_reading_num != rhs->total_reading_num) {
    return false;
  }
  return true;
}

bool
fbg_msgs__msg__FbgReading__copy(
  const fbg_msgs__msg__FbgReading * input,
  fbg_msgs__msg__FbgReading * output)
{
  if (!input || !output) {
    return false;
  }
  // signal_reading
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->signal_reading), &(output->signal_reading)))
  {
    return false;
  }
  // signal_each_ch
  for (size_t i = 0; i < 4; ++i) {
    output->signal_each_ch[i] = input->signal_each_ch[i];
  }
  // total_reading_num
  output->total_reading_num = input->total_reading_num;
  return true;
}

fbg_msgs__msg__FbgReading *
fbg_msgs__msg__FbgReading__create()
{
  fbg_msgs__msg__FbgReading * msg = (fbg_msgs__msg__FbgReading *)malloc(sizeof(fbg_msgs__msg__FbgReading));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fbg_msgs__msg__FbgReading));
  bool success = fbg_msgs__msg__FbgReading__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
fbg_msgs__msg__FbgReading__destroy(fbg_msgs__msg__FbgReading * msg)
{
  if (msg) {
    fbg_msgs__msg__FbgReading__fini(msg);
  }
  free(msg);
}


bool
fbg_msgs__msg__FbgReading__Sequence__init(fbg_msgs__msg__FbgReading__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  fbg_msgs__msg__FbgReading * data = NULL;
  if (size) {
    data = (fbg_msgs__msg__FbgReading *)calloc(size, sizeof(fbg_msgs__msg__FbgReading));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fbg_msgs__msg__FbgReading__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fbg_msgs__msg__FbgReading__fini(&data[i - 1]);
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
fbg_msgs__msg__FbgReading__Sequence__fini(fbg_msgs__msg__FbgReading__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      fbg_msgs__msg__FbgReading__fini(&array->data[i]);
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

fbg_msgs__msg__FbgReading__Sequence *
fbg_msgs__msg__FbgReading__Sequence__create(size_t size)
{
  fbg_msgs__msg__FbgReading__Sequence * array = (fbg_msgs__msg__FbgReading__Sequence *)malloc(sizeof(fbg_msgs__msg__FbgReading__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = fbg_msgs__msg__FbgReading__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
fbg_msgs__msg__FbgReading__Sequence__destroy(fbg_msgs__msg__FbgReading__Sequence * array)
{
  if (array) {
    fbg_msgs__msg__FbgReading__Sequence__fini(array);
  }
  free(array);
}

bool
fbg_msgs__msg__FbgReading__Sequence__are_equal(const fbg_msgs__msg__FbgReading__Sequence * lhs, const fbg_msgs__msg__FbgReading__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fbg_msgs__msg__FbgReading__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fbg_msgs__msg__FbgReading__Sequence__copy(
  const fbg_msgs__msg__FbgReading__Sequence * input,
  fbg_msgs__msg__FbgReading__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fbg_msgs__msg__FbgReading);
    fbg_msgs__msg__FbgReading * data =
      (fbg_msgs__msg__FbgReading *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fbg_msgs__msg__FbgReading__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          fbg_msgs__msg__FbgReading__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fbg_msgs__msg__FbgReading__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
