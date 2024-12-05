// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from isaacsim_msgs:srv/ImportUrdf.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__SRV__DETAIL__IMPORT_URDF__BUILDER_HPP_
#define ISAACSIM_MSGS__SRV__DETAIL__IMPORT_URDF__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "isaacsim_msgs/srv/detail/import_urdf__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace isaacsim_msgs
{

namespace srv
{

namespace builder
{

class Init_ImportUrdf_Request_control
{
public:
  explicit Init_ImportUrdf_Request_control(::isaacsim_msgs::srv::ImportUrdf_Request & msg)
  : msg_(msg)
  {}
  ::isaacsim_msgs::srv::ImportUrdf_Request control(::isaacsim_msgs::srv::ImportUrdf_Request::_control_type arg)
  {
    msg_.control = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaacsim_msgs::srv::ImportUrdf_Request msg_;
};

class Init_ImportUrdf_Request_prim_path
{
public:
  explicit Init_ImportUrdf_Request_prim_path(::isaacsim_msgs::srv::ImportUrdf_Request & msg)
  : msg_(msg)
  {}
  Init_ImportUrdf_Request_control prim_path(::isaacsim_msgs::srv::ImportUrdf_Request::_prim_path_type arg)
  {
    msg_.prim_path = std::move(arg);
    return Init_ImportUrdf_Request_control(msg_);
  }

private:
  ::isaacsim_msgs::srv::ImportUrdf_Request msg_;
};

class Init_ImportUrdf_Request_urdf_path
{
public:
  explicit Init_ImportUrdf_Request_urdf_path(::isaacsim_msgs::srv::ImportUrdf_Request & msg)
  : msg_(msg)
  {}
  Init_ImportUrdf_Request_prim_path urdf_path(::isaacsim_msgs::srv::ImportUrdf_Request::_urdf_path_type arg)
  {
    msg_.urdf_path = std::move(arg);
    return Init_ImportUrdf_Request_prim_path(msg_);
  }

private:
  ::isaacsim_msgs::srv::ImportUrdf_Request msg_;
};

class Init_ImportUrdf_Request_name
{
public:
  Init_ImportUrdf_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImportUrdf_Request_urdf_path name(::isaacsim_msgs::srv::ImportUrdf_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_ImportUrdf_Request_urdf_path(msg_);
  }

private:
  ::isaacsim_msgs::srv::ImportUrdf_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaacsim_msgs::srv::ImportUrdf_Request>()
{
  return isaacsim_msgs::srv::builder::Init_ImportUrdf_Request_name();
}

}  // namespace isaacsim_msgs


namespace isaacsim_msgs
{

namespace srv
{

namespace builder
{

class Init_ImportUrdf_Response_usd_path
{
public:
  Init_ImportUrdf_Response_usd_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::isaacsim_msgs::srv::ImportUrdf_Response usd_path(::isaacsim_msgs::srv::ImportUrdf_Response::_usd_path_type arg)
  {
    msg_.usd_path = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaacsim_msgs::srv::ImportUrdf_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaacsim_msgs::srv::ImportUrdf_Response>()
{
  return isaacsim_msgs::srv::builder::Init_ImportUrdf_Response_usd_path();
}

}  // namespace isaacsim_msgs

#endif  // ISAACSIM_MSGS__SRV__DETAIL__IMPORT_URDF__BUILDER_HPP_
