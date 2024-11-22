// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from isaacsim_msgs:srv/UrdfToUsd.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__SRV__DETAIL__URDF_TO_USD__STRUCT_H_
#define ISAACSIM_MSGS__SRV__DETAIL__URDF_TO_USD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'urdf_path'
// Member 'robot_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/UrdfToUsd in the package isaacsim_msgs.
typedef struct isaacsim_msgs__srv__UrdfToUsd_Request
{
  bool using_arena_robot;
  rosidl_runtime_c__String urdf_path;
  rosidl_runtime_c__String robot_name;
  int64_t number_robot;
} isaacsim_msgs__srv__UrdfToUsd_Request;

// Struct for a sequence of isaacsim_msgs__srv__UrdfToUsd_Request.
typedef struct isaacsim_msgs__srv__UrdfToUsd_Request__Sequence
{
  isaacsim_msgs__srv__UrdfToUsd_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaacsim_msgs__srv__UrdfToUsd_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'usd_path'
// Member 'prim_path'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/UrdfToUsd in the package isaacsim_msgs.
typedef struct isaacsim_msgs__srv__UrdfToUsd_Response
{
  rosidl_runtime_c__String usd_path;
  rosidl_runtime_c__String prim_path;
} isaacsim_msgs__srv__UrdfToUsd_Response;

// Struct for a sequence of isaacsim_msgs__srv__UrdfToUsd_Response.
typedef struct isaacsim_msgs__srv__UrdfToUsd_Response__Sequence
{
  isaacsim_msgs__srv__UrdfToUsd_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaacsim_msgs__srv__UrdfToUsd_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ISAACSIM_MSGS__SRV__DETAIL__URDF_TO_USD__STRUCT_H_
