// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from isaacsim_msgs:msg/PrimPath.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__MSG__DETAIL__PRIM_PATH__BUILDER_HPP_
#define ISAACSIM_MSGS__MSG__DETAIL__PRIM_PATH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "isaacsim_msgs/msg/detail/prim_path__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace isaacsim_msgs
{

namespace msg
{

namespace builder
{

class Init_PrimPath_path
{
public:
  Init_PrimPath_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::isaacsim_msgs::msg::PrimPath path(::isaacsim_msgs::msg::PrimPath::_path_type arg)
  {
    msg_.path = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaacsim_msgs::msg::PrimPath msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaacsim_msgs::msg::PrimPath>()
{
  return isaacsim_msgs::msg::builder::Init_PrimPath_path();
}

}  // namespace isaacsim_msgs

#endif  // ISAACSIM_MSGS__MSG__DETAIL__PRIM_PATH__BUILDER_HPP_
