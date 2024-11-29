// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from isaacsim_msgs:msg/Env.idl
// generated code does not contain a copyright notice
#include "isaacsim_msgs/msg/detail/env__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `robots`
// Member `environments`
// Member `robot_positions`
// Member `robot_rotations`
// Member `environment_positions`
// Member `environment_rotations`
#include "rosidl_runtime_c/string_functions.h"

bool
isaacsim_msgs__msg__Env__init(isaacsim_msgs__msg__Env * msg)
{
  if (!msg) {
    return false;
  }
  // robots
  if (!rosidl_runtime_c__String__Sequence__init(&msg->robots, 0)) {
    isaacsim_msgs__msg__Env__fini(msg);
    return false;
  }
  // environments
  if (!rosidl_runtime_c__String__Sequence__init(&msg->environments, 0)) {
    isaacsim_msgs__msg__Env__fini(msg);
    return false;
  }
  // robot_positions
  if (!rosidl_runtime_c__String__Sequence__init(&msg->robot_positions, 0)) {
    isaacsim_msgs__msg__Env__fini(msg);
    return false;
  }
  // robot_rotations
  if (!rosidl_runtime_c__String__Sequence__init(&msg->robot_rotations, 0)) {
    isaacsim_msgs__msg__Env__fini(msg);
    return false;
  }
  // environment_positions
  if (!rosidl_runtime_c__String__Sequence__init(&msg->environment_positions, 0)) {
    isaacsim_msgs__msg__Env__fini(msg);
    return false;
  }
  // environment_rotations
  if (!rosidl_runtime_c__String__Sequence__init(&msg->environment_rotations, 0)) {
    isaacsim_msgs__msg__Env__fini(msg);
    return false;
  }
  return true;
}

void
isaacsim_msgs__msg__Env__fini(isaacsim_msgs__msg__Env * msg)
{
  if (!msg) {
    return;
  }
  // robots
  rosidl_runtime_c__String__Sequence__fini(&msg->robots);
  // environments
  rosidl_runtime_c__String__Sequence__fini(&msg->environments);
  // robot_positions
  rosidl_runtime_c__String__Sequence__fini(&msg->robot_positions);
  // robot_rotations
  rosidl_runtime_c__String__Sequence__fini(&msg->robot_rotations);
  // environment_positions
  rosidl_runtime_c__String__Sequence__fini(&msg->environment_positions);
  // environment_rotations
  rosidl_runtime_c__String__Sequence__fini(&msg->environment_rotations);
}

bool
isaacsim_msgs__msg__Env__are_equal(const isaacsim_msgs__msg__Env * lhs, const isaacsim_msgs__msg__Env * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robots
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->robots), &(rhs->robots)))
  {
    return false;
  }
  // environments
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->environments), &(rhs->environments)))
  {
    return false;
  }
  // robot_positions
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->robot_positions), &(rhs->robot_positions)))
  {
    return false;
  }
  // robot_rotations
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->robot_rotations), &(rhs->robot_rotations)))
  {
    return false;
  }
  // environment_positions
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->environment_positions), &(rhs->environment_positions)))
  {
    return false;
  }
  // environment_rotations
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->environment_rotations), &(rhs->environment_rotations)))
  {
    return false;
  }
  return true;
}

bool
isaacsim_msgs__msg__Env__copy(
  const isaacsim_msgs__msg__Env * input,
  isaacsim_msgs__msg__Env * output)
{
  if (!input || !output) {
    return false;
  }
  // robots
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->robots), &(output->robots)))
  {
    return false;
  }
  // environments
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->environments), &(output->environments)))
  {
    return false;
  }
  // robot_positions
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->robot_positions), &(output->robot_positions)))
  {
    return false;
  }
  // robot_rotations
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->robot_rotations), &(output->robot_rotations)))
  {
    return false;
  }
  // environment_positions
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->environment_positions), &(output->environment_positions)))
  {
    return false;
  }
  // environment_rotations
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->environment_rotations), &(output->environment_rotations)))
  {
    return false;
  }
  return true;
}

isaacsim_msgs__msg__Env *
isaacsim_msgs__msg__Env__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaacsim_msgs__msg__Env * msg = (isaacsim_msgs__msg__Env *)allocator.allocate(sizeof(isaacsim_msgs__msg__Env), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(isaacsim_msgs__msg__Env));
  bool success = isaacsim_msgs__msg__Env__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
isaacsim_msgs__msg__Env__destroy(isaacsim_msgs__msg__Env * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    isaacsim_msgs__msg__Env__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
isaacsim_msgs__msg__Env__Sequence__init(isaacsim_msgs__msg__Env__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaacsim_msgs__msg__Env * data = NULL;

  if (size) {
    data = (isaacsim_msgs__msg__Env *)allocator.zero_allocate(size, sizeof(isaacsim_msgs__msg__Env), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = isaacsim_msgs__msg__Env__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        isaacsim_msgs__msg__Env__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
isaacsim_msgs__msg__Env__Sequence__fini(isaacsim_msgs__msg__Env__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      isaacsim_msgs__msg__Env__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

isaacsim_msgs__msg__Env__Sequence *
isaacsim_msgs__msg__Env__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaacsim_msgs__msg__Env__Sequence * array = (isaacsim_msgs__msg__Env__Sequence *)allocator.allocate(sizeof(isaacsim_msgs__msg__Env__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = isaacsim_msgs__msg__Env__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
isaacsim_msgs__msg__Env__Sequence__destroy(isaacsim_msgs__msg__Env__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    isaacsim_msgs__msg__Env__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
isaacsim_msgs__msg__Env__Sequence__are_equal(const isaacsim_msgs__msg__Env__Sequence * lhs, const isaacsim_msgs__msg__Env__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!isaacsim_msgs__msg__Env__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
isaacsim_msgs__msg__Env__Sequence__copy(
  const isaacsim_msgs__msg__Env__Sequence * input,
  isaacsim_msgs__msg__Env__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(isaacsim_msgs__msg__Env);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    isaacsim_msgs__msg__Env * data =
      (isaacsim_msgs__msg__Env *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!isaacsim_msgs__msg__Env__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          isaacsim_msgs__msg__Env__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!isaacsim_msgs__msg__Env__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
