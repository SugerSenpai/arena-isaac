// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from isaacsim_msgs:msg/Quat.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__MSG__DETAIL__QUAT__STRUCT_H_
#define ISAACSIM_MSGS__MSG__DETAIL__QUAT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Quat in the package isaacsim_msgs.
typedef struct isaacsim_msgs__msg__Quat
{
  float w;
  float x;
  float y;
  float z;
} isaacsim_msgs__msg__Quat;

// Struct for a sequence of isaacsim_msgs__msg__Quat.
typedef struct isaacsim_msgs__msg__Quat__Sequence
{
  isaacsim_msgs__msg__Quat * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaacsim_msgs__msg__Quat__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ISAACSIM_MSGS__MSG__DETAIL__QUAT__STRUCT_H_
