// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from isaacsim_msgs:srv/ImportYaml.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__SRV__DETAIL__IMPORT_YAML__STRUCT_H_
#define ISAACSIM_MSGS__SRV__DETAIL__IMPORT_YAML__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'yaml_path'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ImportYaml in the package isaacsim_msgs.
typedef struct isaacsim_msgs__srv__ImportYaml_Request
{
  rosidl_runtime_c__String yaml_path;
} isaacsim_msgs__srv__ImportYaml_Request;

// Struct for a sequence of isaacsim_msgs__srv__ImportYaml_Request.
typedef struct isaacsim_msgs__srv__ImportYaml_Request__Sequence
{
  isaacsim_msgs__srv__ImportYaml_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaacsim_msgs__srv__ImportYaml_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ImportYaml in the package isaacsim_msgs.
typedef struct isaacsim_msgs__srv__ImportYaml_Response
{
  bool ret;
} isaacsim_msgs__srv__ImportYaml_Response;

// Struct for a sequence of isaacsim_msgs__srv__ImportYaml_Response.
typedef struct isaacsim_msgs__srv__ImportYaml_Response__Sequence
{
  isaacsim_msgs__srv__ImportYaml_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaacsim_msgs__srv__ImportYaml_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ISAACSIM_MSGS__SRV__DETAIL__IMPORT_YAML__STRUCT_H_
