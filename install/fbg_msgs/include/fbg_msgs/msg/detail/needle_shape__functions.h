// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from fbg_msgs:msg/NeedleShape.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__MSG__DETAIL__NEEDLE_SHAPE__FUNCTIONS_H_
#define FBG_MSGS__MSG__DETAIL__NEEDLE_SHAPE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "fbg_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "fbg_msgs/msg/detail/needle_shape__struct.h"

/// Initialize msg/NeedleShape message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * fbg_msgs__msg__NeedleShape
 * )) before or use
 * fbg_msgs__msg__NeedleShape__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
bool
fbg_msgs__msg__NeedleShape__init(fbg_msgs__msg__NeedleShape * msg);

/// Finalize msg/NeedleShape message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
void
fbg_msgs__msg__NeedleShape__fini(fbg_msgs__msg__NeedleShape * msg);

/// Create msg/NeedleShape message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * fbg_msgs__msg__NeedleShape__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
fbg_msgs__msg__NeedleShape *
fbg_msgs__msg__NeedleShape__create();

/// Destroy msg/NeedleShape message.
/**
 * It calls
 * fbg_msgs__msg__NeedleShape__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
void
fbg_msgs__msg__NeedleShape__destroy(fbg_msgs__msg__NeedleShape * msg);

/// Check for msg/NeedleShape message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
bool
fbg_msgs__msg__NeedleShape__are_equal(const fbg_msgs__msg__NeedleShape * lhs, const fbg_msgs__msg__NeedleShape * rhs);

/// Copy a msg/NeedleShape message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
bool
fbg_msgs__msg__NeedleShape__copy(
  const fbg_msgs__msg__NeedleShape * input,
  fbg_msgs__msg__NeedleShape * output);

/// Initialize array of msg/NeedleShape messages.
/**
 * It allocates the memory for the number of elements and calls
 * fbg_msgs__msg__NeedleShape__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
bool
fbg_msgs__msg__NeedleShape__Sequence__init(fbg_msgs__msg__NeedleShape__Sequence * array, size_t size);

/// Finalize array of msg/NeedleShape messages.
/**
 * It calls
 * fbg_msgs__msg__NeedleShape__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
void
fbg_msgs__msg__NeedleShape__Sequence__fini(fbg_msgs__msg__NeedleShape__Sequence * array);

/// Create array of msg/NeedleShape messages.
/**
 * It allocates the memory for the array and calls
 * fbg_msgs__msg__NeedleShape__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
fbg_msgs__msg__NeedleShape__Sequence *
fbg_msgs__msg__NeedleShape__Sequence__create(size_t size);

/// Destroy array of msg/NeedleShape messages.
/**
 * It calls
 * fbg_msgs__msg__NeedleShape__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
void
fbg_msgs__msg__NeedleShape__Sequence__destroy(fbg_msgs__msg__NeedleShape__Sequence * array);

/// Check for msg/NeedleShape message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
bool
fbg_msgs__msg__NeedleShape__Sequence__are_equal(const fbg_msgs__msg__NeedleShape__Sequence * lhs, const fbg_msgs__msg__NeedleShape__Sequence * rhs);

/// Copy an array of msg/NeedleShape messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
bool
fbg_msgs__msg__NeedleShape__Sequence__copy(
  const fbg_msgs__msg__NeedleShape__Sequence * input,
  fbg_msgs__msg__NeedleShape__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FBG_MSGS__MSG__DETAIL__NEEDLE_SHAPE__FUNCTIONS_H_
