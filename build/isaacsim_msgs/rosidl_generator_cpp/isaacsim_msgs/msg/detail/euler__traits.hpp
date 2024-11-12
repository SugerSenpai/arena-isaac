// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from isaacsim_msgs:msg/Euler.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__MSG__DETAIL__EULER__TRAITS_HPP_
#define ISAACSIM_MSGS__MSG__DETAIL__EULER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "isaacsim_msgs/msg/detail/euler__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace isaacsim_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Euler & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Euler & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Euler & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace isaacsim_msgs

namespace rosidl_generator_traits
{

[[deprecated("use isaacsim_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const isaacsim_msgs::msg::Euler & msg,
  std::ostream & out, size_t indentation = 0)
{
  isaacsim_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use isaacsim_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const isaacsim_msgs::msg::Euler & msg)
{
  return isaacsim_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<isaacsim_msgs::msg::Euler>()
{
  return "isaacsim_msgs::msg::Euler";
}

template<>
inline const char * name<isaacsim_msgs::msg::Euler>()
{
  return "isaacsim_msgs/msg/Euler";
}

template<>
struct has_fixed_size<isaacsim_msgs::msg::Euler>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<isaacsim_msgs::msg::Euler>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<isaacsim_msgs::msg::Euler>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ISAACSIM_MSGS__MSG__DETAIL__EULER__TRAITS_HPP_
