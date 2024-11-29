// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from isaacsim_msgs:msg/Env.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "isaacsim_msgs/msg/detail/env__rosidl_typesupport_introspection_c.h"
#include "isaacsim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "isaacsim_msgs/msg/detail/env__functions.h"
#include "isaacsim_msgs/msg/detail/env__struct.h"


// Include directives for member types
// Member `robots`
// Member `environments`
// Member `robot_positions`
// Member `robot_rotations`
// Member `environment_positions`
// Member `environment_rotations`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__Env_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  isaacsim_msgs__msg__Env__init(message_memory);
}

void isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__Env_fini_function(void * message_memory)
{
  isaacsim_msgs__msg__Env__fini(message_memory);
}

size_t isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__size_function__Env__robots(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_const_function__Env__robots(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_function__Env__robots(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__fetch_function__Env__robots(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_const_function__Env__robots(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__assign_function__Env__robots(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_function__Env__robots(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__resize_function__Env__robots(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__size_function__Env__environments(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_const_function__Env__environments(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_function__Env__environments(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__fetch_function__Env__environments(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_const_function__Env__environments(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__assign_function__Env__environments(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_function__Env__environments(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__resize_function__Env__environments(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__size_function__Env__robot_positions(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_const_function__Env__robot_positions(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_function__Env__robot_positions(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__fetch_function__Env__robot_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_const_function__Env__robot_positions(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__assign_function__Env__robot_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_function__Env__robot_positions(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__resize_function__Env__robot_positions(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__size_function__Env__robot_rotations(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_const_function__Env__robot_rotations(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_function__Env__robot_rotations(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__fetch_function__Env__robot_rotations(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_const_function__Env__robot_rotations(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__assign_function__Env__robot_rotations(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_function__Env__robot_rotations(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__resize_function__Env__robot_rotations(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__size_function__Env__environment_positions(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_const_function__Env__environment_positions(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_function__Env__environment_positions(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__fetch_function__Env__environment_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_const_function__Env__environment_positions(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__assign_function__Env__environment_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_function__Env__environment_positions(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__resize_function__Env__environment_positions(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__size_function__Env__environment_rotations(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_const_function__Env__environment_rotations(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_function__Env__environment_rotations(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__fetch_function__Env__environment_rotations(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_const_function__Env__environment_rotations(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__assign_function__Env__environment_rotations(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_function__Env__environment_rotations(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__resize_function__Env__environment_rotations(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__Env_message_member_array[6] = {
  {
    "robots",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaacsim_msgs__msg__Env, robots),  // bytes offset in struct
    NULL,  // default value
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__size_function__Env__robots,  // size() function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_const_function__Env__robots,  // get_const(index) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_function__Env__robots,  // get(index) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__fetch_function__Env__robots,  // fetch(index, &value) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__assign_function__Env__robots,  // assign(index, value) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__resize_function__Env__robots  // resize(index) function pointer
  },
  {
    "environments",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaacsim_msgs__msg__Env, environments),  // bytes offset in struct
    NULL,  // default value
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__size_function__Env__environments,  // size() function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_const_function__Env__environments,  // get_const(index) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_function__Env__environments,  // get(index) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__fetch_function__Env__environments,  // fetch(index, &value) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__assign_function__Env__environments,  // assign(index, value) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__resize_function__Env__environments  // resize(index) function pointer
  },
  {
    "robot_positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaacsim_msgs__msg__Env, robot_positions),  // bytes offset in struct
    NULL,  // default value
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__size_function__Env__robot_positions,  // size() function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_const_function__Env__robot_positions,  // get_const(index) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_function__Env__robot_positions,  // get(index) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__fetch_function__Env__robot_positions,  // fetch(index, &value) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__assign_function__Env__robot_positions,  // assign(index, value) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__resize_function__Env__robot_positions  // resize(index) function pointer
  },
  {
    "robot_rotations",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaacsim_msgs__msg__Env, robot_rotations),  // bytes offset in struct
    NULL,  // default value
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__size_function__Env__robot_rotations,  // size() function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_const_function__Env__robot_rotations,  // get_const(index) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_function__Env__robot_rotations,  // get(index) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__fetch_function__Env__robot_rotations,  // fetch(index, &value) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__assign_function__Env__robot_rotations,  // assign(index, value) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__resize_function__Env__robot_rotations  // resize(index) function pointer
  },
  {
    "environment_positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaacsim_msgs__msg__Env, environment_positions),  // bytes offset in struct
    NULL,  // default value
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__size_function__Env__environment_positions,  // size() function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_const_function__Env__environment_positions,  // get_const(index) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_function__Env__environment_positions,  // get(index) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__fetch_function__Env__environment_positions,  // fetch(index, &value) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__assign_function__Env__environment_positions,  // assign(index, value) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__resize_function__Env__environment_positions  // resize(index) function pointer
  },
  {
    "environment_rotations",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaacsim_msgs__msg__Env, environment_rotations),  // bytes offset in struct
    NULL,  // default value
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__size_function__Env__environment_rotations,  // size() function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_const_function__Env__environment_rotations,  // get_const(index) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__get_function__Env__environment_rotations,  // get(index) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__fetch_function__Env__environment_rotations,  // fetch(index, &value) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__assign_function__Env__environment_rotations,  // assign(index, value) function pointer
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__resize_function__Env__environment_rotations  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__Env_message_members = {
  "isaacsim_msgs__msg",  // message namespace
  "Env",  // message name
  6,  // number of fields
  sizeof(isaacsim_msgs__msg__Env),
  isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__Env_message_member_array,  // message members
  isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__Env_init_function,  // function to initialize message memory (memory has to be allocated)
  isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__Env_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__Env_message_type_support_handle = {
  0,
  &isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__Env_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_isaacsim_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaacsim_msgs, msg, Env)() {
  if (!isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__Env_message_type_support_handle.typesupport_identifier) {
    isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__Env_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &isaacsim_msgs__msg__Env__rosidl_typesupport_introspection_c__Env_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
