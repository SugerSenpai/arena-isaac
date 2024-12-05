// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from isaacsim_msgs:srv/ImportYaml.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__SRV__DETAIL__IMPORT_YAML__BUILDER_HPP_
#define ISAACSIM_MSGS__SRV__DETAIL__IMPORT_YAML__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "isaacsim_msgs/srv/detail/import_yaml__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace isaacsim_msgs
{

namespace srv
{

namespace builder
{

class Init_ImportYaml_Request_yaml_path
{
public:
  Init_ImportYaml_Request_yaml_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::isaacsim_msgs::srv::ImportYaml_Request yaml_path(::isaacsim_msgs::srv::ImportYaml_Request::_yaml_path_type arg)
  {
    msg_.yaml_path = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaacsim_msgs::srv::ImportYaml_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaacsim_msgs::srv::ImportYaml_Request>()
{
  return isaacsim_msgs::srv::builder::Init_ImportYaml_Request_yaml_path();
}

}  // namespace isaacsim_msgs


namespace isaacsim_msgs
{

namespace srv
{

namespace builder
{

class Init_ImportYaml_Response_ret
{
public:
  Init_ImportYaml_Response_ret()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::isaacsim_msgs::srv::ImportYaml_Response ret(::isaacsim_msgs::srv::ImportYaml_Response::_ret_type arg)
  {
    msg_.ret = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaacsim_msgs::srv::ImportYaml_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaacsim_msgs::srv::ImportYaml_Response>()
{
  return isaacsim_msgs::srv::builder::Init_ImportYaml_Response_ret();
}

}  // namespace isaacsim_msgs

#endif  // ISAACSIM_MSGS__SRV__DETAIL__IMPORT_YAML__BUILDER_HPP_
