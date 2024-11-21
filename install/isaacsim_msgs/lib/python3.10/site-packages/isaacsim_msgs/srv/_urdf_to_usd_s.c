// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from isaacsim_msgs:srv/UrdfToUsd.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "isaacsim_msgs/srv/detail/urdf_to_usd__struct.h"
#include "isaacsim_msgs/srv/detail/urdf_to_usd__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool isaacsim_msgs__srv__urdf_to_usd__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[49];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("isaacsim_msgs.srv._urdf_to_usd.UrdfToUsd_Request", full_classname_dest, 48) == 0);
  }
  isaacsim_msgs__srv__UrdfToUsd_Request * ros_message = _ros_message;
  {  // using_arena_robot
    PyObject * field = PyObject_GetAttrString(_pymsg, "using_arena_robot");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->using_arena_robot = (Py_True == field);
    Py_DECREF(field);
  }
  {  // urdf_path
    PyObject * field = PyObject_GetAttrString(_pymsg, "urdf_path");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->urdf_path, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // robot_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "robot_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->robot_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // number_robot
    PyObject * field = PyObject_GetAttrString(_pymsg, "number_robot");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->number_robot = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * isaacsim_msgs__srv__urdf_to_usd__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of UrdfToUsd_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("isaacsim_msgs.srv._urdf_to_usd");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "UrdfToUsd_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  isaacsim_msgs__srv__UrdfToUsd_Request * ros_message = (isaacsim_msgs__srv__UrdfToUsd_Request *)raw_ros_message;
  {  // using_arena_robot
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->using_arena_robot ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "using_arena_robot", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // urdf_path
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->urdf_path.data,
      strlen(ros_message->urdf_path.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "urdf_path", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // robot_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->robot_name.data,
      strlen(ros_message->robot_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "robot_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // number_robot
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->number_robot);
    {
      int rc = PyObject_SetAttrString(_pymessage, "number_robot", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "isaacsim_msgs/srv/detail/urdf_to_usd__struct.h"
// already included above
// #include "isaacsim_msgs/srv/detail/urdf_to_usd__functions.h"

// already included above
// #include "rosidl_runtime_c/string.h"
// already included above
// #include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool isaacsim_msgs__srv__urdf_to_usd__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[50];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("isaacsim_msgs.srv._urdf_to_usd.UrdfToUsd_Response", full_classname_dest, 49) == 0);
  }
  isaacsim_msgs__srv__UrdfToUsd_Response * ros_message = _ros_message;
  {  // usd_path
    PyObject * field = PyObject_GetAttrString(_pymsg, "usd_path");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->usd_path, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // prim_path
    PyObject * field = PyObject_GetAttrString(_pymsg, "prim_path");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->prim_path, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * isaacsim_msgs__srv__urdf_to_usd__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of UrdfToUsd_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("isaacsim_msgs.srv._urdf_to_usd");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "UrdfToUsd_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  isaacsim_msgs__srv__UrdfToUsd_Response * ros_message = (isaacsim_msgs__srv__UrdfToUsd_Response *)raw_ros_message;
  {  // usd_path
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->usd_path.data,
      strlen(ros_message->usd_path.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "usd_path", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // prim_path
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->prim_path.data,
      strlen(ros_message->prim_path.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "prim_path", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
