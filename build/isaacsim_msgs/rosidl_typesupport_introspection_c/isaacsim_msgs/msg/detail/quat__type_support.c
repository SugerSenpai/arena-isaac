// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from isaacsim_msgs:msg/Quat.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "isaacsim_msgs/msg/detail/quat__rosidl_typesupport_introspection_c.h"
#include "isaacsim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "isaacsim_msgs/msg/detail/quat__functions.h"
#include "isaacsim_msgs/msg/detail/quat__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void isaacsim_msgs__msg__Quat__rosidl_typesupport_introspection_c__Quat_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  isaacsim_msgs__msg__Quat__init(message_memory);
}

void isaacsim_msgs__msg__Quat__rosidl_typesupport_introspection_c__Quat_fini_function(void * message_memory)
{
  isaacsim_msgs__msg__Quat__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember isaacsim_msgs__msg__Quat__rosidl_typesupport_introspection_c__Quat_message_member_array[4] = {
  {
    "w",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaacsim_msgs__msg__Quat, w),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaacsim_msgs__msg__Quat, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaacsim_msgs__msg__Quat, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaacsim_msgs__msg__Quat, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers isaacsim_msgs__msg__Quat__rosidl_typesupport_introspection_c__Quat_message_members = {
  "isaacsim_msgs__msg",  // message namespace
  "Quat",  // message name
  4,  // number of fields
  sizeof(isaacsim_msgs__msg__Quat),
  isaacsim_msgs__msg__Quat__rosidl_typesupport_introspection_c__Quat_message_member_array,  // message members
  isaacsim_msgs__msg__Quat__rosidl_typesupport_introspection_c__Quat_init_function,  // function to initialize message memory (memory has to be allocated)
  isaacsim_msgs__msg__Quat__rosidl_typesupport_introspection_c__Quat_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t isaacsim_msgs__msg__Quat__rosidl_typesupport_introspection_c__Quat_message_type_support_handle = {
  0,
  &isaacsim_msgs__msg__Quat__rosidl_typesupport_introspection_c__Quat_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_isaacsim_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaacsim_msgs, msg, Quat)() {
  if (!isaacsim_msgs__msg__Quat__rosidl_typesupport_introspection_c__Quat_message_type_support_handle.typesupport_identifier) {
    isaacsim_msgs__msg__Quat__rosidl_typesupport_introspection_c__Quat_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &isaacsim_msgs__msg__Quat__rosidl_typesupport_introspection_c__Quat_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
