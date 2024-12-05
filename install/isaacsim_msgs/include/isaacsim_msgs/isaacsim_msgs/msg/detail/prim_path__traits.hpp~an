// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from isaacsim_msgs:msg/PrimPath.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__MSG__DETAIL__PRIM_PATH__TRAITS_HPP_
#define ISAACSIM_MSGS__MSG__DETAIL__PRIM_PATH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "isaacsim_msgs/msg/detail/prim_path__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace isaacsim_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const PrimPath & msg,
  std::ostream & out)
{
  out << "{";
  // member: path
  {
    out << "path: ";
    rosidl_generator_traits::value_to_yaml(msg.path, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PrimPath & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "path: ";
    rosidl_generator_traits::value_to_yaml(msg.path, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PrimPath & msg, bool use_flow_style = false)
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
  const isaacsim_msgs::msg::PrimPath & msg,
  std::ostream & out, size_t indentation = 0)
{
  isaacsim_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use isaacsim_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const isaacsim_msgs::msg::PrimPath & msg)
{
  return isaacsim_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<isaacsim_msgs::msg::PrimPath>()
{
  return "isaacsim_msgs::msg::PrimPath";
}

template<>
inline const char * name<isaacsim_msgs::msg::PrimPath>()
{
  return "isaacsim_msgs/msg/PrimPath";
}

template<>
struct has_fixed_size<isaacsim_msgs::msg::PrimPath>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<isaacsim_msgs::msg::PrimPath>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<isaacsim_msgs::msg::PrimPath>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ISAACSIM_MSGS__MSG__DETAIL__PRIM_PATH__TRAITS_HPP_
