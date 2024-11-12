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

class Init_ImportUsd_Request_prim_path
{
public:
  explicit Init_ImportUsd_Request_prim_path(::isaacsim_msgs::srv::ImportUsd_Request & msg)
  : msg_(msg)
  {}
  ::isaacsim_msgs::srv::ImportUsd_Request prim_path(::isaacsim_msgs::srv::ImportUsd_Request::_prim_path_type arg)
  {
    msg_.prim_path = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaacsim_msgs::srv::ImportUsd_Request msg_;
};

class Init_ImportUsd_Request_usd_path
{
public:
  Init_ImportUsd_Request_usd_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImportUsd_Request_prim_path usd_path(::isaacsim_msgs::srv::ImportUsd_Request::_usd_path_type arg)
  {
    msg_.usd_path = std::move(arg);
    return Init_ImportUsd_Request_prim_path(msg_);
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
  return isaacsim_msgs::srv::builder::Init_ImportUsd_Request_usd_path();
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
