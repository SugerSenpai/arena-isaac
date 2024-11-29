// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from isaacsim_msgs:msg/Env.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__MSG__DETAIL__ENV__BUILDER_HPP_
#define ISAACSIM_MSGS__MSG__DETAIL__ENV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "isaacsim_msgs/msg/detail/env__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace isaacsim_msgs
{

namespace msg
{

namespace builder
{

class Init_Env_environment_rotations
{
public:
  explicit Init_Env_environment_rotations(::isaacsim_msgs::msg::Env & msg)
  : msg_(msg)
  {}
  ::isaacsim_msgs::msg::Env environment_rotations(::isaacsim_msgs::msg::Env::_environment_rotations_type arg)
  {
    msg_.environment_rotations = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaacsim_msgs::msg::Env msg_;
};

class Init_Env_environment_positions
{
public:
  explicit Init_Env_environment_positions(::isaacsim_msgs::msg::Env & msg)
  : msg_(msg)
  {}
  Init_Env_environment_rotations environment_positions(::isaacsim_msgs::msg::Env::_environment_positions_type arg)
  {
    msg_.environment_positions = std::move(arg);
    return Init_Env_environment_rotations(msg_);
  }

private:
  ::isaacsim_msgs::msg::Env msg_;
};

class Init_Env_robot_rotations
{
public:
  explicit Init_Env_robot_rotations(::isaacsim_msgs::msg::Env & msg)
  : msg_(msg)
  {}
  Init_Env_environment_positions robot_rotations(::isaacsim_msgs::msg::Env::_robot_rotations_type arg)
  {
    msg_.robot_rotations = std::move(arg);
    return Init_Env_environment_positions(msg_);
  }

private:
  ::isaacsim_msgs::msg::Env msg_;
};

class Init_Env_robot_positions
{
public:
  explicit Init_Env_robot_positions(::isaacsim_msgs::msg::Env & msg)
  : msg_(msg)
  {}
  Init_Env_robot_rotations robot_positions(::isaacsim_msgs::msg::Env::_robot_positions_type arg)
  {
    msg_.robot_positions = std::move(arg);
    return Init_Env_robot_rotations(msg_);
  }

private:
  ::isaacsim_msgs::msg::Env msg_;
};

class Init_Env_environments
{
public:
  explicit Init_Env_environments(::isaacsim_msgs::msg::Env & msg)
  : msg_(msg)
  {}
  Init_Env_robot_positions environments(::isaacsim_msgs::msg::Env::_environments_type arg)
  {
    msg_.environments = std::move(arg);
    return Init_Env_robot_positions(msg_);
  }

private:
  ::isaacsim_msgs::msg::Env msg_;
};

class Init_Env_robots
{
public:
  Init_Env_robots()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Env_environments robots(::isaacsim_msgs::msg::Env::_robots_type arg)
  {
    msg_.robots = std::move(arg);
    return Init_Env_environments(msg_);
  }

private:
  ::isaacsim_msgs::msg::Env msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaacsim_msgs::msg::Env>()
{
  return isaacsim_msgs::msg::builder::Init_Env_robots();
}

}  // namespace isaacsim_msgs

#endif  // ISAACSIM_MSGS__MSG__DETAIL__ENV__BUILDER_HPP_
