// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from isaacsim_msgs:msg/Euler.idl
// generated code does not contain a copyright notice
#include "isaacsim_msgs/msg/detail/euler__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
isaacsim_msgs__msg__Euler__init(isaacsim_msgs__msg__Euler * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  return true;
}

void
isaacsim_msgs__msg__Euler__fini(isaacsim_msgs__msg__Euler * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
}

bool
isaacsim_msgs__msg__Euler__are_equal(const isaacsim_msgs__msg__Euler * lhs, const isaacsim_msgs__msg__Euler * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  return true;
}

bool
isaacsim_msgs__msg__Euler__copy(
  const isaacsim_msgs__msg__Euler * input,
  isaacsim_msgs__msg__Euler * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  return true;
}

isaacsim_msgs__msg__Euler *
isaacsim_msgs__msg__Euler__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaacsim_msgs__msg__Euler * msg = (isaacsim_msgs__msg__Euler *)allocator.allocate(sizeof(isaacsim_msgs__msg__Euler), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(isaacsim_msgs__msg__Euler));
  bool success = isaacsim_msgs__msg__Euler__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
isaacsim_msgs__msg__Euler__destroy(isaacsim_msgs__msg__Euler * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    isaacsim_msgs__msg__Euler__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
isaacsim_msgs__msg__Euler__Sequence__init(isaacsim_msgs__msg__Euler__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaacsim_msgs__msg__Euler * data = NULL;

  if (size) {
    data = (isaacsim_msgs__msg__Euler *)allocator.zero_allocate(size, sizeof(isaacsim_msgs__msg__Euler), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = isaacsim_msgs__msg__Euler__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        isaacsim_msgs__msg__Euler__fini(&data[i - 1]);
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
isaacsim_msgs__msg__Euler__Sequence__fini(isaacsim_msgs__msg__Euler__Sequence * array)
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
      isaacsim_msgs__msg__Euler__fini(&array->data[i]);
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

isaacsim_msgs__msg__Euler__Sequence *
isaacsim_msgs__msg__Euler__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaacsim_msgs__msg__Euler__Sequence * array = (isaacsim_msgs__msg__Euler__Sequence *)allocator.allocate(sizeof(isaacsim_msgs__msg__Euler__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = isaacsim_msgs__msg__Euler__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
isaacsim_msgs__msg__Euler__Sequence__destroy(isaacsim_msgs__msg__Euler__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    isaacsim_msgs__msg__Euler__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
isaacsim_msgs__msg__Euler__Sequence__are_equal(const isaacsim_msgs__msg__Euler__Sequence * lhs, const isaacsim_msgs__msg__Euler__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!isaacsim_msgs__msg__Euler__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
isaacsim_msgs__msg__Euler__Sequence__copy(
  const isaacsim_msgs__msg__Euler__Sequence * input,
  isaacsim_msgs__msg__Euler__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(isaacsim_msgs__msg__Euler);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    isaacsim_msgs__msg__Euler * data =
      (isaacsim_msgs__msg__Euler *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!isaacsim_msgs__msg__Euler__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          isaacsim_msgs__msg__Euler__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!isaacsim_msgs__msg__Euler__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
