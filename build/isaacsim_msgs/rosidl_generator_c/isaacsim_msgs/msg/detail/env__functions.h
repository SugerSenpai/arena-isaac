// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from isaacsim_msgs:msg/Env.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__MSG__DETAIL__ENV__FUNCTIONS_H_
#define ISAACSIM_MSGS__MSG__DETAIL__ENV__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "isaacsim_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "isaacsim_msgs/msg/detail/env__struct.h"

/// Initialize msg/Env message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * isaacsim_msgs__msg__Env
 * )) before or use
 * isaacsim_msgs__msg__Env__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_isaacsim_msgs
bool
isaacsim_msgs__msg__Env__init(isaacsim_msgs__msg__Env * msg);

/// Finalize msg/Env message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_isaacsim_msgs
void
isaacsim_msgs__msg__Env__fini(isaacsim_msgs__msg__Env * msg);

/// Create msg/Env message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * isaacsim_msgs__msg__Env__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_isaacsim_msgs
isaacsim_msgs__msg__Env *
isaacsim_msgs__msg__Env__create();

/// Destroy msg/Env message.
/**
 * It calls
 * isaacsim_msgs__msg__Env__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_isaacsim_msgs
void
isaacsim_msgs__msg__Env__destroy(isaacsim_msgs__msg__Env * msg);

/// Check for msg/Env message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_isaacsim_msgs
bool
isaacsim_msgs__msg__Env__are_equal(const isaacsim_msgs__msg__Env * lhs, const isaacsim_msgs__msg__Env * rhs);

/// Copy a msg/Env message.
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
ROSIDL_GENERATOR_C_PUBLIC_isaacsim_msgs
bool
isaacsim_msgs__msg__Env__copy(
  const isaacsim_msgs__msg__Env * input,
  isaacsim_msgs__msg__Env * output);

/// Initialize array of msg/Env messages.
/**
 * It allocates the memory for the number of elements and calls
 * isaacsim_msgs__msg__Env__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_isaacsim_msgs
bool
isaacsim_msgs__msg__Env__Sequence__init(isaacsim_msgs__msg__Env__Sequence * array, size_t size);

/// Finalize array of msg/Env messages.
/**
 * It calls
 * isaacsim_msgs__msg__Env__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_isaacsim_msgs
void
isaacsim_msgs__msg__Env__Sequence__fini(isaacsim_msgs__msg__Env__Sequence * array);

/// Create array of msg/Env messages.
/**
 * It allocates the memory for the array and calls
 * isaacsim_msgs__msg__Env__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_isaacsim_msgs
isaacsim_msgs__msg__Env__Sequence *
isaacsim_msgs__msg__Env__Sequence__create(size_t size);

/// Destroy array of msg/Env messages.
/**
 * It calls
 * isaacsim_msgs__msg__Env__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_isaacsim_msgs
void
isaacsim_msgs__msg__Env__Sequence__destroy(isaacsim_msgs__msg__Env__Sequence * array);

/// Check for msg/Env message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_isaacsim_msgs
bool
isaacsim_msgs__msg__Env__Sequence__are_equal(const isaacsim_msgs__msg__Env__Sequence * lhs, const isaacsim_msgs__msg__Env__Sequence * rhs);

/// Copy an array of msg/Env messages.
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
ROSIDL_GENERATOR_C_PUBLIC_isaacsim_msgs
bool
isaacsim_msgs__msg__Env__Sequence__copy(
  const isaacsim_msgs__msg__Env__Sequence * input,
  isaacsim_msgs__msg__Env__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ISAACSIM_MSGS__MSG__DETAIL__ENV__FUNCTIONS_H_
