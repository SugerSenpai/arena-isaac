// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from isaacsim_msgs:srv/UrdfToUsd.idl
// generated code does not contain a copyright notice
#include "isaacsim_msgs/srv/detail/urdf_to_usd__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `name`
// Member `urdf_path`
#include "rosidl_runtime_c/string_functions.h"

bool
isaacsim_msgs__srv__UrdfToUsd_Request__init(isaacsim_msgs__srv__UrdfToUsd_Request * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    isaacsim_msgs__srv__UrdfToUsd_Request__fini(msg);
    return false;
  }
  // urdf_path
  if (!rosidl_runtime_c__String__init(&msg->urdf_path)) {
    isaacsim_msgs__srv__UrdfToUsd_Request__fini(msg);
    return false;
  }
  return true;
}

void
isaacsim_msgs__srv__UrdfToUsd_Request__fini(isaacsim_msgs__srv__UrdfToUsd_Request * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // urdf_path
  rosidl_runtime_c__String__fini(&msg->urdf_path);
}

bool
isaacsim_msgs__srv__UrdfToUsd_Request__are_equal(const isaacsim_msgs__srv__UrdfToUsd_Request * lhs, const isaacsim_msgs__srv__UrdfToUsd_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // urdf_path
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->urdf_path), &(rhs->urdf_path)))
  {
    return false;
  }
  return true;
}

bool
isaacsim_msgs__srv__UrdfToUsd_Request__copy(
  const isaacsim_msgs__srv__UrdfToUsd_Request * input,
  isaacsim_msgs__srv__UrdfToUsd_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // urdf_path
  if (!rosidl_runtime_c__String__copy(
      &(input->urdf_path), &(output->urdf_path)))
  {
    return false;
  }
  return true;
}

isaacsim_msgs__srv__UrdfToUsd_Request *
isaacsim_msgs__srv__UrdfToUsd_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaacsim_msgs__srv__UrdfToUsd_Request * msg = (isaacsim_msgs__srv__UrdfToUsd_Request *)allocator.allocate(sizeof(isaacsim_msgs__srv__UrdfToUsd_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(isaacsim_msgs__srv__UrdfToUsd_Request));
  bool success = isaacsim_msgs__srv__UrdfToUsd_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
isaacsim_msgs__srv__UrdfToUsd_Request__destroy(isaacsim_msgs__srv__UrdfToUsd_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    isaacsim_msgs__srv__UrdfToUsd_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
isaacsim_msgs__srv__UrdfToUsd_Request__Sequence__init(isaacsim_msgs__srv__UrdfToUsd_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaacsim_msgs__srv__UrdfToUsd_Request * data = NULL;

  if (size) {
    data = (isaacsim_msgs__srv__UrdfToUsd_Request *)allocator.zero_allocate(size, sizeof(isaacsim_msgs__srv__UrdfToUsd_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = isaacsim_msgs__srv__UrdfToUsd_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        isaacsim_msgs__srv__UrdfToUsd_Request__fini(&data[i - 1]);
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
isaacsim_msgs__srv__UrdfToUsd_Request__Sequence__fini(isaacsim_msgs__srv__UrdfToUsd_Request__Sequence * array)
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
      isaacsim_msgs__srv__UrdfToUsd_Request__fini(&array->data[i]);
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

isaacsim_msgs__srv__UrdfToUsd_Request__Sequence *
isaacsim_msgs__srv__UrdfToUsd_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaacsim_msgs__srv__UrdfToUsd_Request__Sequence * array = (isaacsim_msgs__srv__UrdfToUsd_Request__Sequence *)allocator.allocate(sizeof(isaacsim_msgs__srv__UrdfToUsd_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = isaacsim_msgs__srv__UrdfToUsd_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
isaacsim_msgs__srv__UrdfToUsd_Request__Sequence__destroy(isaacsim_msgs__srv__UrdfToUsd_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    isaacsim_msgs__srv__UrdfToUsd_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
isaacsim_msgs__srv__UrdfToUsd_Request__Sequence__are_equal(const isaacsim_msgs__srv__UrdfToUsd_Request__Sequence * lhs, const isaacsim_msgs__srv__UrdfToUsd_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!isaacsim_msgs__srv__UrdfToUsd_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
isaacsim_msgs__srv__UrdfToUsd_Request__Sequence__copy(
  const isaacsim_msgs__srv__UrdfToUsd_Request__Sequence * input,
  isaacsim_msgs__srv__UrdfToUsd_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(isaacsim_msgs__srv__UrdfToUsd_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    isaacsim_msgs__srv__UrdfToUsd_Request * data =
      (isaacsim_msgs__srv__UrdfToUsd_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!isaacsim_msgs__srv__UrdfToUsd_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          isaacsim_msgs__srv__UrdfToUsd_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!isaacsim_msgs__srv__UrdfToUsd_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `usd_path`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
isaacsim_msgs__srv__UrdfToUsd_Response__init(isaacsim_msgs__srv__UrdfToUsd_Response * msg)
{
  if (!msg) {
    return false;
  }
  // usd_path
  if (!rosidl_runtime_c__String__init(&msg->usd_path)) {
    isaacsim_msgs__srv__UrdfToUsd_Response__fini(msg);
    return false;
  }
  return true;
}

void
isaacsim_msgs__srv__UrdfToUsd_Response__fini(isaacsim_msgs__srv__UrdfToUsd_Response * msg)
{
  if (!msg) {
    return;
  }
  // usd_path
  rosidl_runtime_c__String__fini(&msg->usd_path);
}

bool
isaacsim_msgs__srv__UrdfToUsd_Response__are_equal(const isaacsim_msgs__srv__UrdfToUsd_Response * lhs, const isaacsim_msgs__srv__UrdfToUsd_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // usd_path
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->usd_path), &(rhs->usd_path)))
  {
    return false;
  }
  return true;
}

bool
isaacsim_msgs__srv__UrdfToUsd_Response__copy(
  const isaacsim_msgs__srv__UrdfToUsd_Response * input,
  isaacsim_msgs__srv__UrdfToUsd_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // usd_path
  if (!rosidl_runtime_c__String__copy(
      &(input->usd_path), &(output->usd_path)))
  {
    return false;
  }
  return true;
}

isaacsim_msgs__srv__UrdfToUsd_Response *
isaacsim_msgs__srv__UrdfToUsd_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaacsim_msgs__srv__UrdfToUsd_Response * msg = (isaacsim_msgs__srv__UrdfToUsd_Response *)allocator.allocate(sizeof(isaacsim_msgs__srv__UrdfToUsd_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(isaacsim_msgs__srv__UrdfToUsd_Response));
  bool success = isaacsim_msgs__srv__UrdfToUsd_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
isaacsim_msgs__srv__UrdfToUsd_Response__destroy(isaacsim_msgs__srv__UrdfToUsd_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    isaacsim_msgs__srv__UrdfToUsd_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
isaacsim_msgs__srv__UrdfToUsd_Response__Sequence__init(isaacsim_msgs__srv__UrdfToUsd_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaacsim_msgs__srv__UrdfToUsd_Response * data = NULL;

  if (size) {
    data = (isaacsim_msgs__srv__UrdfToUsd_Response *)allocator.zero_allocate(size, sizeof(isaacsim_msgs__srv__UrdfToUsd_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = isaacsim_msgs__srv__UrdfToUsd_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        isaacsim_msgs__srv__UrdfToUsd_Response__fini(&data[i - 1]);
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
isaacsim_msgs__srv__UrdfToUsd_Response__Sequence__fini(isaacsim_msgs__srv__UrdfToUsd_Response__Sequence * array)
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
      isaacsim_msgs__srv__UrdfToUsd_Response__fini(&array->data[i]);
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

isaacsim_msgs__srv__UrdfToUsd_Response__Sequence *
isaacsim_msgs__srv__UrdfToUsd_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaacsim_msgs__srv__UrdfToUsd_Response__Sequence * array = (isaacsim_msgs__srv__UrdfToUsd_Response__Sequence *)allocator.allocate(sizeof(isaacsim_msgs__srv__UrdfToUsd_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = isaacsim_msgs__srv__UrdfToUsd_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
isaacsim_msgs__srv__UrdfToUsd_Response__Sequence__destroy(isaacsim_msgs__srv__UrdfToUsd_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    isaacsim_msgs__srv__UrdfToUsd_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
isaacsim_msgs__srv__UrdfToUsd_Response__Sequence__are_equal(const isaacsim_msgs__srv__UrdfToUsd_Response__Sequence * lhs, const isaacsim_msgs__srv__UrdfToUsd_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!isaacsim_msgs__srv__UrdfToUsd_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
isaacsim_msgs__srv__UrdfToUsd_Response__Sequence__copy(
  const isaacsim_msgs__srv__UrdfToUsd_Response__Sequence * input,
  isaacsim_msgs__srv__UrdfToUsd_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(isaacsim_msgs__srv__UrdfToUsd_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    isaacsim_msgs__srv__UrdfToUsd_Response * data =
      (isaacsim_msgs__srv__UrdfToUsd_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!isaacsim_msgs__srv__UrdfToUsd_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          isaacsim_msgs__srv__UrdfToUsd_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!isaacsim_msgs__srv__UrdfToUsd_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
