// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from isaacsim_msgs:srv/UrdfToUsd.idl
// generated code does not contain a copyright notice
#include "isaacsim_msgs/srv/detail/urdf_to_usd__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "isaacsim_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "isaacsim_msgs/srv/detail/urdf_to_usd__struct.h"
#include "isaacsim_msgs/srv/detail/urdf_to_usd__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // robot_name, urdf_path
#include "rosidl_runtime_c/string_functions.h"  // robot_name, urdf_path

// forward declare type support functions


using _UrdfToUsd_Request__ros_msg_type = isaacsim_msgs__srv__UrdfToUsd_Request;

static bool _UrdfToUsd_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _UrdfToUsd_Request__ros_msg_type * ros_message = static_cast<const _UrdfToUsd_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: using_arena_robot
  {
    cdr << (ros_message->using_arena_robot ? true : false);
  }

  // Field name: urdf_path
  {
    const rosidl_runtime_c__String * str = &ros_message->urdf_path;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: robot_name
  {
    const rosidl_runtime_c__String * str = &ros_message->robot_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: number_robot
  {
    cdr << ros_message->number_robot;
  }

  return true;
}

static bool _UrdfToUsd_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _UrdfToUsd_Request__ros_msg_type * ros_message = static_cast<_UrdfToUsd_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: using_arena_robot
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->using_arena_robot = tmp ? true : false;
  }

  // Field name: urdf_path
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->urdf_path.data) {
      rosidl_runtime_c__String__init(&ros_message->urdf_path);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->urdf_path,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'urdf_path'\n");
      return false;
    }
  }

  // Field name: robot_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->robot_name.data) {
      rosidl_runtime_c__String__init(&ros_message->robot_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->robot_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'robot_name'\n");
      return false;
    }
  }

  // Field name: number_robot
  {
    cdr >> ros_message->number_robot;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_isaacsim_msgs
size_t get_serialized_size_isaacsim_msgs__srv__UrdfToUsd_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _UrdfToUsd_Request__ros_msg_type * ros_message = static_cast<const _UrdfToUsd_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name using_arena_robot
  {
    size_t item_size = sizeof(ros_message->using_arena_robot);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name urdf_path
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->urdf_path.size + 1);
  // field.name robot_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->robot_name.size + 1);
  // field.name number_robot
  {
    size_t item_size = sizeof(ros_message->number_robot);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _UrdfToUsd_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_isaacsim_msgs__srv__UrdfToUsd_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_isaacsim_msgs
size_t max_serialized_size_isaacsim_msgs__srv__UrdfToUsd_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: using_arena_robot
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: urdf_path
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: robot_name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: number_robot
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = isaacsim_msgs__srv__UrdfToUsd_Request;
    is_plain =
      (
      offsetof(DataType, number_robot) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _UrdfToUsd_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_isaacsim_msgs__srv__UrdfToUsd_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_UrdfToUsd_Request = {
  "isaacsim_msgs::srv",
  "UrdfToUsd_Request",
  _UrdfToUsd_Request__cdr_serialize,
  _UrdfToUsd_Request__cdr_deserialize,
  _UrdfToUsd_Request__get_serialized_size,
  _UrdfToUsd_Request__max_serialized_size
};

static rosidl_message_type_support_t _UrdfToUsd_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_UrdfToUsd_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, isaacsim_msgs, srv, UrdfToUsd_Request)() {
  return &_UrdfToUsd_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "isaacsim_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "isaacsim_msgs/srv/detail/urdf_to_usd__struct.h"
// already included above
// #include "isaacsim_msgs/srv/detail/urdf_to_usd__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/string.h"  // prim_path, usd_path
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // prim_path, usd_path

// forward declare type support functions


using _UrdfToUsd_Response__ros_msg_type = isaacsim_msgs__srv__UrdfToUsd_Response;

static bool _UrdfToUsd_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _UrdfToUsd_Response__ros_msg_type * ros_message = static_cast<const _UrdfToUsd_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: usd_path
  {
    const rosidl_runtime_c__String * str = &ros_message->usd_path;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: prim_path
  {
    const rosidl_runtime_c__String * str = &ros_message->prim_path;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _UrdfToUsd_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _UrdfToUsd_Response__ros_msg_type * ros_message = static_cast<_UrdfToUsd_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: usd_path
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->usd_path.data) {
      rosidl_runtime_c__String__init(&ros_message->usd_path);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->usd_path,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'usd_path'\n");
      return false;
    }
  }

  // Field name: prim_path
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->prim_path.data) {
      rosidl_runtime_c__String__init(&ros_message->prim_path);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->prim_path,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'prim_path'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_isaacsim_msgs
size_t get_serialized_size_isaacsim_msgs__srv__UrdfToUsd_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _UrdfToUsd_Response__ros_msg_type * ros_message = static_cast<const _UrdfToUsd_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name usd_path
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->usd_path.size + 1);
  // field.name prim_path
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->prim_path.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _UrdfToUsd_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_isaacsim_msgs__srv__UrdfToUsd_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_isaacsim_msgs
size_t max_serialized_size_isaacsim_msgs__srv__UrdfToUsd_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: usd_path
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: prim_path
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = isaacsim_msgs__srv__UrdfToUsd_Response;
    is_plain =
      (
      offsetof(DataType, prim_path) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _UrdfToUsd_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_isaacsim_msgs__srv__UrdfToUsd_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_UrdfToUsd_Response = {
  "isaacsim_msgs::srv",
  "UrdfToUsd_Response",
  _UrdfToUsd_Response__cdr_serialize,
  _UrdfToUsd_Response__cdr_deserialize,
  _UrdfToUsd_Response__get_serialized_size,
  _UrdfToUsd_Response__max_serialized_size
};

static rosidl_message_type_support_t _UrdfToUsd_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_UrdfToUsd_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, isaacsim_msgs, srv, UrdfToUsd_Response)() {
  return &_UrdfToUsd_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "isaacsim_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "isaacsim_msgs/srv/urdf_to_usd.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t UrdfToUsd__callbacks = {
  "isaacsim_msgs::srv",
  "UrdfToUsd",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, isaacsim_msgs, srv, UrdfToUsd_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, isaacsim_msgs, srv, UrdfToUsd_Response)(),
};

static rosidl_service_type_support_t UrdfToUsd__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &UrdfToUsd__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, isaacsim_msgs, srv, UrdfToUsd)() {
  return &UrdfToUsd__handle;
}

#if defined(__cplusplus)
}
#endif
