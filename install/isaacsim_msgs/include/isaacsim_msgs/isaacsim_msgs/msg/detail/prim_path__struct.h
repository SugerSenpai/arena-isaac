// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from isaacsim_msgs:msg/PrimPath.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__MSG__DETAIL__PRIM_PATH__STRUCT_H_
#define ISAACSIM_MSGS__MSG__DETAIL__PRIM_PATH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'path'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/PrimPath in the package isaacsim_msgs.
typedef struct isaacsim_msgs__msg__PrimPath
{
  rosidl_runtime_c__String path;
} isaacsim_msgs__msg__PrimPath;

// Struct for a sequence of isaacsim_msgs__msg__PrimPath.
typedef struct isaacsim_msgs__msg__PrimPath__Sequence
{
  isaacsim_msgs__msg__PrimPath * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaacsim_msgs__msg__PrimPath__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ISAACSIM_MSGS__MSG__DETAIL__PRIM_PATH__STRUCT_H_
