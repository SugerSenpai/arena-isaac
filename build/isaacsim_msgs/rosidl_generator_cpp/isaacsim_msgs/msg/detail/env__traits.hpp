// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from isaacsim_msgs:msg/Env.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__MSG__DETAIL__ENV__TRAITS_HPP_
#define ISAACSIM_MSGS__MSG__DETAIL__ENV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "isaacsim_msgs/msg/detail/env__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace isaacsim_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Env & msg,
  std::ostream & out)
{
  out << "{";
  // member: robots
  {
    if (msg.robots.size() == 0) {
      out << "robots: []";
    } else {
      out << "robots: [";
      size_t pending_items = msg.robots.size();
      for (auto item : msg.robots) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: environments
  {
    if (msg.environments.size() == 0) {
      out << "environments: []";
    } else {
      out << "environments: [";
      size_t pending_items = msg.environments.size();
      for (auto item : msg.environments) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: robot_positions
  {
    if (msg.robot_positions.size() == 0) {
      out << "robot_positions: []";
    } else {
      out << "robot_positions: [";
      size_t pending_items = msg.robot_positions.size();
      for (auto item : msg.robot_positions) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: robot_rotations
  {
    if (msg.robot_rotations.size() == 0) {
      out << "robot_rotations: []";
    } else {
      out << "robot_rotations: [";
      size_t pending_items = msg.robot_rotations.size();
      for (auto item : msg.robot_rotations) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: environment_positions
  {
    if (msg.environment_positions.size() == 0) {
      out << "environment_positions: []";
    } else {
      out << "environment_positions: [";
      size_t pending_items = msg.environment_positions.size();
      for (auto item : msg.environment_positions) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: environment_rotations
  {
    if (msg.environment_rotations.size() == 0) {
      out << "environment_rotations: []";
    } else {
      out << "environment_rotations: [";
      size_t pending_items = msg.environment_rotations.size();
      for (auto item : msg.environment_rotations) {
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
  const Env & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robots
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.robots.size() == 0) {
      out << "robots: []\n";
    } else {
      out << "robots:\n";
      for (auto item : msg.robots) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: environments
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.environments.size() == 0) {
      out << "environments: []\n";
    } else {
      out << "environments:\n";
      for (auto item : msg.environments) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: robot_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.robot_positions.size() == 0) {
      out << "robot_positions: []\n";
    } else {
      out << "robot_positions:\n";
      for (auto item : msg.robot_positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: robot_rotations
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.robot_rotations.size() == 0) {
      out << "robot_rotations: []\n";
    } else {
      out << "robot_rotations:\n";
      for (auto item : msg.robot_rotations) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: environment_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.environment_positions.size() == 0) {
      out << "environment_positions: []\n";
    } else {
      out << "environment_positions:\n";
      for (auto item : msg.environment_positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: environment_rotations
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.environment_rotations.size() == 0) {
      out << "environment_rotations: []\n";
    } else {
      out << "environment_rotations:\n";
      for (auto item : msg.environment_rotations) {
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

inline std::string to_yaml(const Env & msg, bool use_flow_style = false)
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
  const isaacsim_msgs::msg::Env & msg,
  std::ostream & out, size_t indentation = 0)
{
  isaacsim_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use isaacsim_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const isaacsim_msgs::msg::Env & msg)
{
  return isaacsim_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<isaacsim_msgs::msg::Env>()
{
  return "isaacsim_msgs::msg::Env";
}

template<>
inline const char * name<isaacsim_msgs::msg::Env>()
{
  return "isaacsim_msgs/msg/Env";
}

template<>
struct has_fixed_size<isaacsim_msgs::msg::Env>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<isaacsim_msgs::msg::Env>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<isaacsim_msgs::msg::Env>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ISAACSIM_MSGS__MSG__DETAIL__ENV__TRAITS_HPP_
