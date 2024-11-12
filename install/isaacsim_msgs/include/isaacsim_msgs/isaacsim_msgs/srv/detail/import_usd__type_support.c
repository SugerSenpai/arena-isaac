// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from isaacsim_msgs:srv/ImportUsd.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "isaacsim_msgs/srv/detail/import_usd__rosidl_typesupport_introspection_c.h"
#include "isaacsim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "isaacsim_msgs/srv/detail/import_usd__functions.h"
#include "isaacsim_msgs/srv/detail/import_usd__struct.h"


// Include directives for member types
// Member `usd_path`
// Member `prim_path`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void isaacsim_msgs__srv__ImportUsd_Request__rosidl_typesupport_introspection_c__ImportUsd_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  isaacsim_msgs__srv__ImportUsd_Request__init(message_memory);
}

void isaacsim_msgs__srv__ImportUsd_Request__rosidl_typesupport_introspection_c__ImportUsd_Request_fini_function(void * message_memory)
{
  isaacsim_msgs__srv__ImportUsd_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember isaacsim_msgs__srv__ImportUsd_Request__rosidl_typesupport_introspection_c__ImportUsd_Request_message_member_array[2] = {
  {
    "usd_path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaacsim_msgs__srv__ImportUsd_Request, usd_path),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "prim_path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaacsim_msgs__srv__ImportUsd_Request, prim_path),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers isaacsim_msgs__srv__ImportUsd_Request__rosidl_typesupport_introspection_c__ImportUsd_Request_message_members = {
  "isaacsim_msgs__srv",  // message namespace
  "ImportUsd_Request",  // message name
  2,  // number of fields
  sizeof(isaacsim_msgs__srv__ImportUsd_Request),
  isaacsim_msgs__srv__ImportUsd_Request__rosidl_typesupport_introspection_c__ImportUsd_Request_message_member_array,  // message members
  isaacsim_msgs__srv__ImportUsd_Request__rosidl_typesupport_introspection_c__ImportUsd_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  isaacsim_msgs__srv__ImportUsd_Request__rosidl_typesupport_introspection_c__ImportUsd_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t isaacsim_msgs__srv__ImportUsd_Request__rosidl_typesupport_introspection_c__ImportUsd_Request_message_type_support_handle = {
  0,
  &isaacsim_msgs__srv__ImportUsd_Request__rosidl_typesupport_introspection_c__ImportUsd_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_isaacsim_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaacsim_msgs, srv, ImportUsd_Request)() {
  if (!isaacsim_msgs__srv__ImportUsd_Request__rosidl_typesupport_introspection_c__ImportUsd_Request_message_type_support_handle.typesupport_identifier) {
    isaacsim_msgs__srv__ImportUsd_Request__rosidl_typesupport_introspection_c__ImportUsd_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &isaacsim_msgs__srv__ImportUsd_Request__rosidl_typesupport_introspection_c__ImportUsd_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "isaacsim_msgs/srv/detail/import_usd__rosidl_typesupport_introspection_c.h"
// already included above
// #include "isaacsim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "isaacsim_msgs/srv/detail/import_usd__functions.h"
// already included above
// #include "isaacsim_msgs/srv/detail/import_usd__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void isaacsim_msgs__srv__ImportUsd_Response__rosidl_typesupport_introspection_c__ImportUsd_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  isaacsim_msgs__srv__ImportUsd_Response__init(message_memory);
}

void isaacsim_msgs__srv__ImportUsd_Response__rosidl_typesupport_introspection_c__ImportUsd_Response_fini_function(void * message_memory)
{
  isaacsim_msgs__srv__ImportUsd_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember isaacsim_msgs__srv__ImportUsd_Response__rosidl_typesupport_introspection_c__ImportUsd_Response_message_member_array[1] = {
  {
    "ret",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaacsim_msgs__srv__ImportUsd_Response, ret),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers isaacsim_msgs__srv__ImportUsd_Response__rosidl_typesupport_introspection_c__ImportUsd_Response_message_members = {
  "isaacsim_msgs__srv",  // message namespace
  "ImportUsd_Response",  // message name
  1,  // number of fields
  sizeof(isaacsim_msgs__srv__ImportUsd_Response),
  isaacsim_msgs__srv__ImportUsd_Response__rosidl_typesupport_introspection_c__ImportUsd_Response_message_member_array,  // message members
  isaacsim_msgs__srv__ImportUsd_Response__rosidl_typesupport_introspection_c__ImportUsd_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  isaacsim_msgs__srv__ImportUsd_Response__rosidl_typesupport_introspection_c__ImportUsd_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t isaacsim_msgs__srv__ImportUsd_Response__rosidl_typesupport_introspection_c__ImportUsd_Response_message_type_support_handle = {
  0,
  &isaacsim_msgs__srv__ImportUsd_Response__rosidl_typesupport_introspection_c__ImportUsd_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_isaacsim_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaacsim_msgs, srv, ImportUsd_Response)() {
  if (!isaacsim_msgs__srv__ImportUsd_Response__rosidl_typesupport_introspection_c__ImportUsd_Response_message_type_support_handle.typesupport_identifier) {
    isaacsim_msgs__srv__ImportUsd_Response__rosidl_typesupport_introspection_c__ImportUsd_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &isaacsim_msgs__srv__ImportUsd_Response__rosidl_typesupport_introspection_c__ImportUsd_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "isaacsim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "isaacsim_msgs/srv/detail/import_usd__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers isaacsim_msgs__srv__detail__import_usd__rosidl_typesupport_introspection_c__ImportUsd_service_members = {
  "isaacsim_msgs__srv",  // service namespace
  "ImportUsd",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // isaacsim_msgs__srv__detail__import_usd__rosidl_typesupport_introspection_c__ImportUsd_Request_message_type_support_handle,
  NULL  // response message
  // isaacsim_msgs__srv__detail__import_usd__rosidl_typesupport_introspection_c__ImportUsd_Response_message_type_support_handle
};

static rosidl_service_type_support_t isaacsim_msgs__srv__detail__import_usd__rosidl_typesupport_introspection_c__ImportUsd_service_type_support_handle = {
  0,
  &isaacsim_msgs__srv__detail__import_usd__rosidl_typesupport_introspection_c__ImportUsd_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaacsim_msgs, srv, ImportUsd_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaacsim_msgs, srv, ImportUsd_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_isaacsim_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaacsim_msgs, srv, ImportUsd)() {
  if (!isaacsim_msgs__srv__detail__import_usd__rosidl_typesupport_introspection_c__ImportUsd_service_type_support_handle.typesupport_identifier) {
    isaacsim_msgs__srv__detail__import_usd__rosidl_typesupport_introspection_c__ImportUsd_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)isaacsim_msgs__srv__detail__import_usd__rosidl_typesupport_introspection_c__ImportUsd_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaacsim_msgs, srv, ImportUsd_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaacsim_msgs, srv, ImportUsd_Response)()->data;
  }

  return &isaacsim_msgs__srv__detail__import_usd__rosidl_typesupport_introspection_c__ImportUsd_service_type_support_handle;
}
