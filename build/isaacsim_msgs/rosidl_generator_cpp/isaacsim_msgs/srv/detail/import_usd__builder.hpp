// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from isaacsim_msgs:srv/ImportUsd.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__SRV__DETAIL__IMPORT_USD__BUILDER_HPP_
#define ISAACSIM_MSGS__SRV__DETAIL__IMPORT_USD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "isaacsim_msgs/srv/detail/import_usd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace isaacsim_msgs
{

namespace srv
{

namespace builder
{

<<<<<<< HEAD
=======
class Init_ImportUsd_Request_orientation
{
public:
  explicit Init_ImportUsd_Request_orientation(::isaacsim_msgs::srv::ImportUsd_Request & msg)
  : msg_(msg)
  {}
  ::isaacsim_msgs::srv::ImportUsd_Request orientation(::isaacsim_msgs::srv::ImportUsd_Request::_orientation_type arg)
  {
    msg_.orientation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaacsim_msgs::srv::ImportUsd_Request msg_;
};

class Init_ImportUsd_Request_position
{
public:
  explicit Init_ImportUsd_Request_position(::isaacsim_msgs::srv::ImportUsd_Request & msg)
  : msg_(msg)
  {}
  Init_ImportUsd_Request_orientation position(::isaacsim_msgs::srv::ImportUsd_Request::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_ImportUsd_Request_orientation(msg_);
  }

private:
  ::isaacsim_msgs::srv::ImportUsd_Request msg_;
};

>>>>>>> an
class Init_ImportUsd_Request_control
{
public:
  explicit Init_ImportUsd_Request_control(::isaacsim_msgs::srv::ImportUsd_Request & msg)
  : msg_(msg)
  {}
<<<<<<< HEAD
  ::isaacsim_msgs::srv::ImportUsd_Request control(::isaacsim_msgs::srv::ImportUsd_Request::_control_type arg)
  {
    msg_.control = std::move(arg);
    return std::move(msg_);
=======
  Init_ImportUsd_Request_position control(::isaacsim_msgs::srv::ImportUsd_Request::_control_type arg)
  {
    msg_.control = std::move(arg);
    return Init_ImportUsd_Request_position(msg_);
>>>>>>> an
  }

private:
  ::isaacsim_msgs::srv::ImportUsd_Request msg_;
};

class Init_ImportUsd_Request_prim_path
{
public:
  explicit Init_ImportUsd_Request_prim_path(::isaacsim_msgs::srv::ImportUsd_Request & msg)
  : msg_(msg)
  {}
  Init_ImportUsd_Request_control prim_path(::isaacsim_msgs::srv::ImportUsd_Request::_prim_path_type arg)
  {
    msg_.prim_path = std::move(arg);
    return Init_ImportUsd_Request_control(msg_);
  }

private:
  ::isaacsim_msgs::srv::ImportUsd_Request msg_;
};

class Init_ImportUsd_Request_usd_path
{
public:
  explicit Init_ImportUsd_Request_usd_path(::isaacsim_msgs::srv::ImportUsd_Request & msg)
  : msg_(msg)
  {}
  Init_ImportUsd_Request_prim_path usd_path(::isaacsim_msgs::srv::ImportUsd_Request::_usd_path_type arg)
  {
    msg_.usd_path = std::move(arg);
    return Init_ImportUsd_Request_prim_path(msg_);
  }

private:
  ::isaacsim_msgs::srv::ImportUsd_Request msg_;
};

class Init_ImportUsd_Request_name
{
public:
  Init_ImportUsd_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImportUsd_Request_usd_path name(::isaacsim_msgs::srv::ImportUsd_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_ImportUsd_Request_usd_path(msg_);
  }

private:
  ::isaacsim_msgs::srv::ImportUsd_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaacsim_msgs::srv::ImportUsd_Request>()
{
  return isaacsim_msgs::srv::builder::Init_ImportUsd_Request_name();
}

}  // namespace isaacsim_msgs


namespace isaacsim_msgs
{

namespace srv
{

namespace builder
{

class Init_ImportUsd_Response_ret
{
public:
  Init_ImportUsd_Response_ret()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::isaacsim_msgs::srv::ImportUsd_Response ret(::isaacsim_msgs::srv::ImportUsd_Response::_ret_type arg)
  {
    msg_.ret = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaacsim_msgs::srv::ImportUsd_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaacsim_msgs::srv::ImportUsd_Response>()
{
  return isaacsim_msgs::srv::builder::Init_ImportUsd_Response_ret();
}

}  // namespace isaacsim_msgs

#endif  // ISAACSIM_MSGS__SRV__DETAIL__IMPORT_USD__BUILDER_HPP_
