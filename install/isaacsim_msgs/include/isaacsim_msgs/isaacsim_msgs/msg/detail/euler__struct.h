// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from isaacsim_msgs:msg/Euler.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__MSG__DETAIL__EULER__STRUCT_H_
#define ISAACSIM_MSGS__MSG__DETAIL__EULER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Euler in the package isaacsim_msgs.
typedef struct isaacsim_msgs__msg__Euler
{
  float x;
  float y;
  float z;
} isaacsim_msgs__msg__Euler;

// Struct for a sequence of isaacsim_msgs__msg__Euler.
typedef struct isaacsim_msgs__msg__Euler__Sequence
{
  isaacsim_msgs__msg__Euler * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaacsim_msgs__msg__Euler__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ISAACSIM_MSGS__MSG__DETAIL__EULER__STRUCT_H_
