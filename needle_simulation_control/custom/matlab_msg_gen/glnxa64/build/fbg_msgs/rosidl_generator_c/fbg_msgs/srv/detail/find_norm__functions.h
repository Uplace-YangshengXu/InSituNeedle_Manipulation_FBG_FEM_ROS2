// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from fbg_msgs:srv/FindNorm.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__SRV__DETAIL__FIND_NORM__FUNCTIONS_H_
#define FBG_MSGS__SRV__DETAIL__FIND_NORM__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "fbg_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "fbg_msgs/srv/detail/find_norm__struct.h"

/// Initialize srv/FindNorm message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * fbg_msgs__srv__FindNorm_Request
 * )) before or use
 * fbg_msgs__srv__FindNorm_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
bool
fbg_msgs__srv__FindNorm_Request__init(fbg_msgs__srv__FindNorm_Request * msg);

/// Finalize srv/FindNorm message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
void
fbg_msgs__srv__FindNorm_Request__fini(fbg_msgs__srv__FindNorm_Request * msg);

/// Create srv/FindNorm message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * fbg_msgs__srv__FindNorm_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
fbg_msgs__srv__FindNorm_Request *
fbg_msgs__srv__FindNorm_Request__create();

/// Destroy srv/FindNorm message.
/**
 * It calls
 * fbg_msgs__srv__FindNorm_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
void
fbg_msgs__srv__FindNorm_Request__destroy(fbg_msgs__srv__FindNorm_Request * msg);


/// Initialize array of srv/FindNorm messages.
/**
 * It allocates the memory for the number of elements and calls
 * fbg_msgs__srv__FindNorm_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
bool
fbg_msgs__srv__FindNorm_Request__Sequence__init(fbg_msgs__srv__FindNorm_Request__Sequence * array, size_t size);

/// Finalize array of srv/FindNorm messages.
/**
 * It calls
 * fbg_msgs__srv__FindNorm_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
void
fbg_msgs__srv__FindNorm_Request__Sequence__fini(fbg_msgs__srv__FindNorm_Request__Sequence * array);

/// Create array of srv/FindNorm messages.
/**
 * It allocates the memory for the array and calls
 * fbg_msgs__srv__FindNorm_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
fbg_msgs__srv__FindNorm_Request__Sequence *
fbg_msgs__srv__FindNorm_Request__Sequence__create(size_t size);

/// Destroy array of srv/FindNorm messages.
/**
 * It calls
 * fbg_msgs__srv__FindNorm_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
void
fbg_msgs__srv__FindNorm_Request__Sequence__destroy(fbg_msgs__srv__FindNorm_Request__Sequence * array);

/// Initialize srv/FindNorm message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * fbg_msgs__srv__FindNorm_Response
 * )) before or use
 * fbg_msgs__srv__FindNorm_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
bool
fbg_msgs__srv__FindNorm_Response__init(fbg_msgs__srv__FindNorm_Response * msg);

/// Finalize srv/FindNorm message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
void
fbg_msgs__srv__FindNorm_Response__fini(fbg_msgs__srv__FindNorm_Response * msg);

/// Create srv/FindNorm message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * fbg_msgs__srv__FindNorm_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
fbg_msgs__srv__FindNorm_Response *
fbg_msgs__srv__FindNorm_Response__create();

/// Destroy srv/FindNorm message.
/**
 * It calls
 * fbg_msgs__srv__FindNorm_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
void
fbg_msgs__srv__FindNorm_Response__destroy(fbg_msgs__srv__FindNorm_Response * msg);


/// Initialize array of srv/FindNorm messages.
/**
 * It allocates the memory for the number of elements and calls
 * fbg_msgs__srv__FindNorm_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
bool
fbg_msgs__srv__FindNorm_Response__Sequence__init(fbg_msgs__srv__FindNorm_Response__Sequence * array, size_t size);

/// Finalize array of srv/FindNorm messages.
/**
 * It calls
 * fbg_msgs__srv__FindNorm_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
void
fbg_msgs__srv__FindNorm_Response__Sequence__fini(fbg_msgs__srv__FindNorm_Response__Sequence * array);

/// Create array of srv/FindNorm messages.
/**
 * It allocates the memory for the array and calls
 * fbg_msgs__srv__FindNorm_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
fbg_msgs__srv__FindNorm_Response__Sequence *
fbg_msgs__srv__FindNorm_Response__Sequence__create(size_t size);

/// Destroy array of srv/FindNorm messages.
/**
 * It calls
 * fbg_msgs__srv__FindNorm_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fbg_msgs
void
fbg_msgs__srv__FindNorm_Response__Sequence__destroy(fbg_msgs__srv__FindNorm_Response__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // FBG_MSGS__SRV__DETAIL__FIND_NORM__FUNCTIONS_H_
