// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from isaacsim_msgs:msg/Env.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__MSG__DETAIL__ENV__STRUCT_H_
#define ISAACSIM_MSGS__MSG__DETAIL__ENV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'robots'
// Member 'environments'
// Member 'robot_positions'
// Member 'robot_rotations'
// Member 'environment_positions'
// Member 'environment_rotations'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Env in the package isaacsim_msgs.
typedef struct isaacsim_msgs__msg__Env
{
  rosidl_runtime_c__String__Sequence robots;
  rosidl_runtime_c__String__Sequence environments;
  rosidl_runtime_c__String__Sequence robot_positions;
  rosidl_runtime_c__String__Sequence robot_rotations;
  rosidl_runtime_c__String__Sequence environment_positions;
  rosidl_runtime_c__String__Sequence environment_rotations;
} isaacsim_msgs__msg__Env;

// Struct for a sequence of isaacsim_msgs__msg__Env.
typedef struct isaacsim_msgs__msg__Env__Sequence
{
  isaacsim_msgs__msg__Env * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaacsim_msgs__msg__Env__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ISAACSIM_MSGS__MSG__DETAIL__ENV__STRUCT_H_
