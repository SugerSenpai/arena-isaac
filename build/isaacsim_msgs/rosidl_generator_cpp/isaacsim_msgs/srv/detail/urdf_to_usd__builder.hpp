// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from isaacsim_msgs:srv/UrdfToUsd.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__SRV__DETAIL__URDF_TO_USD__BUILDER_HPP_
#define ISAACSIM_MSGS__SRV__DETAIL__URDF_TO_USD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "isaacsim_msgs/srv/detail/urdf_to_usd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace isaacsim_msgs
{

namespace srv
{

namespace builder
{

class Init_UrdfToUsd_Request_number_robot
{
public:
  explicit Init_UrdfToUsd_Request_number_robot(::isaacsim_msgs::srv::UrdfToUsd_Request & msg)
  : msg_(msg)
  {}
  ::isaacsim_msgs::srv::UrdfToUsd_Request number_robot(::isaacsim_msgs::srv::UrdfToUsd_Request::_number_robot_type arg)
  {
    msg_.number_robot = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaacsim_msgs::srv::UrdfToUsd_Request msg_;
};

class Init_UrdfToUsd_Request_robot_name
{
public:
  explicit Init_UrdfToUsd_Request_robot_name(::isaacsim_msgs::srv::UrdfToUsd_Request & msg)
  : msg_(msg)
  {}
  Init_UrdfToUsd_Request_number_robot robot_name(::isaacsim_msgs::srv::UrdfToUsd_Request::_robot_name_type arg)
  {
    msg_.robot_name = std::move(arg);
    return Init_UrdfToUsd_Request_number_robot(msg_);
  }

private:
  ::isaacsim_msgs::srv::UrdfToUsd_Request msg_;
};

class Init_UrdfToUsd_Request_urdf_path
{
public:
  explicit Init_UrdfToUsd_Request_urdf_path(::isaacsim_msgs::srv::UrdfToUsd_Request & msg)
  : msg_(msg)
  {}
  Init_UrdfToUsd_Request_robot_name urdf_path(::isaacsim_msgs::srv::UrdfToUsd_Request::_urdf_path_type arg)
  {
    msg_.urdf_path = std::move(arg);
    return Init_UrdfToUsd_Request_robot_name(msg_);
  }

private:
  ::isaacsim_msgs::srv::UrdfToUsd_Request msg_;
};

class Init_UrdfToUsd_Request_using_arena_robot
{
public:
  Init_UrdfToUsd_Request_using_arena_robot()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UrdfToUsd_Request_urdf_path using_arena_robot(::isaacsim_msgs::srv::UrdfToUsd_Request::_using_arena_robot_type arg)
  {
    msg_.using_arena_robot = std::move(arg);
    return Init_UrdfToUsd_Request_urdf_path(msg_);
  }

private:
  ::isaacsim_msgs::srv::UrdfToUsd_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaacsim_msgs::srv::UrdfToUsd_Request>()
{
  return isaacsim_msgs::srv::builder::Init_UrdfToUsd_Request_using_arena_robot();
}

}  // namespace isaacsim_msgs


namespace isaacsim_msgs
{

namespace srv
{

namespace builder
{

class Init_UrdfToUsd_Response_prim_path
{
public:
  explicit Init_UrdfToUsd_Response_prim_path(::isaacsim_msgs::srv::UrdfToUsd_Response & msg)
  : msg_(msg)
  {}
  ::isaacsim_msgs::srv::UrdfToUsd_Response prim_path(::isaacsim_msgs::srv::UrdfToUsd_Response::_prim_path_type arg)
  {
    msg_.prim_path = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaacsim_msgs::srv::UrdfToUsd_Response msg_;
};

class Init_UrdfToUsd_Response_usd_path
{
public:
  Init_UrdfToUsd_Response_usd_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UrdfToUsd_Response_prim_path usd_path(::isaacsim_msgs::srv::UrdfToUsd_Response::_usd_path_type arg)
  {
    msg_.usd_path = std::move(arg);
    return Init_UrdfToUsd_Response_prim_path(msg_);
  }

private:
  ::isaacsim_msgs::srv::UrdfToUsd_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaacsim_msgs::srv::UrdfToUsd_Response>()
{
  return isaacsim_msgs::srv::builder::Init_UrdfToUsd_Response_usd_path();
}

}  // namespace isaacsim_msgs

#endif  // ISAACSIM_MSGS__SRV__DETAIL__URDF_TO_USD__BUILDER_HPP_
