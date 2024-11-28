// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from isaacsim_msgs:srv/UrdfToUsd.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__SRV__DETAIL__URDF_TO_USD__TRAITS_HPP_
#define ISAACSIM_MSGS__SRV__DETAIL__URDF_TO_USD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "isaacsim_msgs/srv/detail/urdf_to_usd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace isaacsim_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const UrdfToUsd_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: urdf_path
  {
    out << "urdf_path: ";
    rosidl_generator_traits::value_to_yaml(msg.urdf_path, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UrdfToUsd_Request & msg,
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

  // member: urdf_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "urdf_path: ";
    rosidl_generator_traits::value_to_yaml(msg.urdf_path, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UrdfToUsd_Request & msg, bool use_flow_style = false)
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
  const isaacsim_msgs::srv::UrdfToUsd_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  isaacsim_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use isaacsim_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const isaacsim_msgs::srv::UrdfToUsd_Request & msg)
{
  return isaacsim_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<isaacsim_msgs::srv::UrdfToUsd_Request>()
{
  return "isaacsim_msgs::srv::UrdfToUsd_Request";
}

template<>
inline const char * name<isaacsim_msgs::srv::UrdfToUsd_Request>()
{
  return "isaacsim_msgs/srv/UrdfToUsd_Request";
}

template<>
struct has_fixed_size<isaacsim_msgs::srv::UrdfToUsd_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<isaacsim_msgs::srv::UrdfToUsd_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<isaacsim_msgs::srv::UrdfToUsd_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace isaacsim_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const UrdfToUsd_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: usd_path
  {
    out << "usd_path: ";
    rosidl_generator_traits::value_to_yaml(msg.usd_path, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UrdfToUsd_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: usd_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "usd_path: ";
    rosidl_generator_traits::value_to_yaml(msg.usd_path, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UrdfToUsd_Response & msg, bool use_flow_style = false)
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
  const isaacsim_msgs::srv::UrdfToUsd_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  isaacsim_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use isaacsim_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const isaacsim_msgs::srv::UrdfToUsd_Response & msg)
{
  return isaacsim_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<isaacsim_msgs::srv::UrdfToUsd_Response>()
{
  return "isaacsim_msgs::srv::UrdfToUsd_Response";
}

template<>
inline const char * name<isaacsim_msgs::srv::UrdfToUsd_Response>()
{
  return "isaacsim_msgs/srv/UrdfToUsd_Response";
}

template<>
struct has_fixed_size<isaacsim_msgs::srv::UrdfToUsd_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<isaacsim_msgs::srv::UrdfToUsd_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<isaacsim_msgs::srv::UrdfToUsd_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<isaacsim_msgs::srv::UrdfToUsd>()
{
  return "isaacsim_msgs::srv::UrdfToUsd";
}

template<>
inline const char * name<isaacsim_msgs::srv::UrdfToUsd>()
{
  return "isaacsim_msgs/srv/UrdfToUsd";
}

template<>
struct has_fixed_size<isaacsim_msgs::srv::UrdfToUsd>
  : std::integral_constant<
    bool,
    has_fixed_size<isaacsim_msgs::srv::UrdfToUsd_Request>::value &&
    has_fixed_size<isaacsim_msgs::srv::UrdfToUsd_Response>::value
  >
{
};

template<>
struct has_bounded_size<isaacsim_msgs::srv::UrdfToUsd>
  : std::integral_constant<
    bool,
    has_bounded_size<isaacsim_msgs::srv::UrdfToUsd_Request>::value &&
    has_bounded_size<isaacsim_msgs::srv::UrdfToUsd_Response>::value
  >
{
};

template<>
struct is_service<isaacsim_msgs::srv::UrdfToUsd>
  : std::true_type
{
};

template<>
struct is_service_request<isaacsim_msgs::srv::UrdfToUsd_Request>
  : std::true_type
{
};

template<>
struct is_service_response<isaacsim_msgs::srv::UrdfToUsd_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ISAACSIM_MSGS__SRV__DETAIL__URDF_TO_USD__TRAITS_HPP_
