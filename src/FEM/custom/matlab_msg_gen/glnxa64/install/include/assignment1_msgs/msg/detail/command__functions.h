// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from assignment1_msgs:msg/Command.idl
// generated code does not contain a copyright notice

#ifndef ASSIGNMENT1_MSGS__MSG__DETAIL__COMMAND__FUNCTIONS_H_
#define ASSIGNMENT1_MSGS__MSG__DETAIL__COMMAND__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "assignment1_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "assignment1_msgs/msg/detail/command__struct.h"

/// Initialize msg/Command message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * assignment1_msgs__msg__Command
 * )) before or use
 * assignment1_msgs__msg__Command__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_assignment1_msgs
bool
assignment1_msgs__msg__Command__init(assignment1_msgs__msg__Command * msg);

/// Finalize msg/Command message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_assignment1_msgs
void
assignment1_msgs__msg__Command__fini(assignment1_msgs__msg__Command * msg);

/// Create msg/Command message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * assignment1_msgs__msg__Command__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_assignment1_msgs
assignment1_msgs__msg__Command *
assignment1_msgs__msg__Command__create();

/// Destroy msg/Command message.
/**
 * It calls
 * assignment1_msgs__msg__Command__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_assignment1_msgs
void
assignment1_msgs__msg__Command__destroy(assignment1_msgs__msg__Command * msg);


/// Initialize array of msg/Command messages.
/**
 * It allocates the memory for the number of elements and calls
 * assignment1_msgs__msg__Command__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_assignment1_msgs
bool
assignment1_msgs__msg__Command__Sequence__init(assignment1_msgs__msg__Command__Sequence * array, size_t size);

/// Finalize array of msg/Command messages.
/**
 * It calls
 * assignment1_msgs__msg__Command__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_assignment1_msgs
void
assignment1_msgs__msg__Command__Sequence__fini(assignment1_msgs__msg__Command__Sequence * array);

/// Create array of msg/Command messages.
/**
 * It allocates the memory for the array and calls
 * assignment1_msgs__msg__Command__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_assignment1_msgs
assignment1_msgs__msg__Command__Sequence *
assignment1_msgs__msg__Command__Sequence__create(size_t size);

/// Destroy array of msg/Command messages.
/**
 * It calls
 * assignment1_msgs__msg__Command__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_assignment1_msgs
void
assignment1_msgs__msg__Command__Sequence__destroy(assignment1_msgs__msg__Command__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // ASSIGNMENT1_MSGS__MSG__DETAIL__COMMAND__FUNCTIONS_H_
