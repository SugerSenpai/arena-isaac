// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from isaacsim_msgs:srv/ImportUsd.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__SRV__DETAIL__IMPORT_USD__TRAITS_HPP_
#define ISAACSIM_MSGS__SRV__DETAIL__IMPORT_USD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "isaacsim_msgs/srv/detail/import_usd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace isaacsim_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ImportUsd_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: usd_path
  {
    out << "usd_path: ";
    rosidl_generator_traits::value_to_yaml(msg.usd_path, out);
    out << ", ";
  }

  // member: prim_path
  {
    out << "prim_path: ";
    rosidl_generator_traits::value_to_yaml(msg.prim_path, out);
    out << ", ";
  }

  // member: control
  {
    out << "control: ";
    rosidl_generator_traits::value_to_yaml(msg.control, out);
    out << ", ";
  }

  // member: position
  {
    if (msg.position.size() == 0) {
      out << "position: []";
    } else {
      out << "position: [";
      size_t pending_items = msg.position.size();
      for (auto item : msg.position) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: orientation
  {
    if (msg.orientation.size() == 0) {
      out << "orientation: []";
    } else {
      out << "orientation: [";
      size_t pending_items = msg.orientation.size();
      for (auto item : msg.orientation) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ImportUsd_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: usd_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "usd_path: ";
    rosidl_generator_traits::value_to_yaml(msg.usd_path, out);
    out << "\n";
  }

  // member: prim_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "prim_path: ";
    rosidl_generator_traits::value_to_yaml(msg.prim_path, out);
    out << "\n";
  }

  // member: control
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "control: ";
    rosidl_generator_traits::value_to_yaml(msg.control, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.position.size() == 0) {
      out << "position: []\n";
    } else {
      out << "position:\n";
      for (auto item : msg.position) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: orientation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.orientation.size() == 0) {
      out << "orientation: []\n";
    } else {
      out << "orientation:\n";
      for (auto item : msg.orientation) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ImportUsd_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace isaacsim_msgs

namespace rosidl_generator_traits
{

[[deprecated("use isaacsim_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const isaacsim_msgs::srv::ImportUsd_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  isaacsim_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use isaacsim_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const isaacsim_msgs::srv::ImportUsd_Request & msg)
{
  return isaacsim_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<isaacsim_msgs::srv::ImportUsd_Request>()
{
  return "isaacsim_msgs::srv::ImportUsd_Request";
}

template<>
inline const char * name<isaacsim_msgs::srv::ImportUsd_Request>()
{
  return "isaacsim_msgs/srv/ImportUsd_Request";
}

template<>
struct has_fixed_size<isaacsim_msgs::srv::ImportUsd_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<isaacsim_msgs::srv::ImportUsd_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<isaacsim_msgs::srv::ImportUsd_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace isaacsim_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ImportUsd_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: ret
  {
    out << "ret: ";
    rosidl_generator_traits::value_to_yaml(msg.ret, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ImportUsd_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ret
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ret: ";
    rosidl_generator_traits::value_to_yaml(msg.ret, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ImportUsd_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace isaacsim_msgs

namespace rosidl_generator_traits
{

[[deprecated("use isaacsim_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const isaacsim_msgs::srv::ImportUsd_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  isaacsim_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use isaacsim_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const isaacsim_msgs::srv::ImportUsd_Response & msg)
{
  return isaacsim_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<isaacsim_msgs::srv::ImportUsd_Response>()
{
  return "isaacsim_msgs::srv::ImportUsd_Response";
}

template<>
inline const char * name<isaacsim_msgs::srv::ImportUsd_Response>()
{
  return "isaacsim_msgs/srv/ImportUsd_Response";
}

template<>
struct has_fixed_size<isaacsim_msgs::srv::ImportUsd_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<isaacsim_msgs::srv::ImportUsd_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<isaacsim_msgs::srv::ImportUsd_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<isaacsim_msgs::srv::ImportUsd>()
{
  return "isaacsim_msgs::srv::ImportUsd";
}

template<>
inline const char * name<isaacsim_msgs::srv::ImportUsd>()
{
  return "isaacsim_msgs/srv/ImportUsd";
}

template<>
struct has_fixed_size<isaacsim_msgs::srv::ImportUsd>
  : std::integral_constant<
    bool,
    has_fixed_size<isaacsim_msgs::srv::ImportUsd_Request>::value &&
    has_fixed_size<isaacsim_msgs::srv::ImportUsd_Response>::value
  >
{
};

template<>
struct has_bounded_size<isaacsim_msgs::srv::ImportUsd>
  : std::integral_constant<
    bool,
    has_bounded_size<isaacsim_msgs::srv::ImportUsd_Request>::value &&
    has_bounded_size<isaacsim_msgs::srv::ImportUsd_Response>::value
  >
{
};

template<>
struct is_service<isaacsim_msgs::srv::ImportUsd>
  : std::true_type
{
};

template<>
struct is_service_request<isaacsim_msgs::srv::ImportUsd_Request>
  : std::true_type
{
};

template<>
struct is_service_response<isaacsim_msgs::srv::ImportUsd_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ISAACSIM_MSGS__SRV__DETAIL__IMPORT_USD__TRAITS_HPP_
