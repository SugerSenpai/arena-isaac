// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from isaacsim_msgs:msg/Quat.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__MSG__DETAIL__QUAT__BUILDER_HPP_
#define ISAACSIM_MSGS__MSG__DETAIL__QUAT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "isaacsim_msgs/msg/detail/quat__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace isaacsim_msgs
{

namespace msg
{

namespace builder
{

class Init_Quat_z
{
public:
  explicit Init_Quat_z(::isaacsim_msgs::msg::Quat & msg)
  : msg_(msg)
  {}
  ::isaacsim_msgs::msg::Quat z(::isaacsim_msgs::msg::Quat::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaacsim_msgs::msg::Quat msg_;
};

class Init_Quat_y
{
public:
  explicit Init_Quat_y(::isaacsim_msgs::msg::Quat & msg)
  : msg_(msg)
  {}
  Init_Quat_z y(::isaacsim_msgs::msg::Quat::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Quat_z(msg_);
  }

private:
  ::isaacsim_msgs::msg::Quat msg_;
};

class Init_Quat_x
{
public:
  explicit Init_Quat_x(::isaacsim_msgs::msg::Quat & msg)
  : msg_(msg)
  {}
  Init_Quat_y x(::isaacsim_msgs::msg::Quat::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Quat_y(msg_);
  }

private:
  ::isaacsim_msgs::msg::Quat msg_;
};

class Init_Quat_w
{
public:
  Init_Quat_w()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Quat_x w(::isaacsim_msgs::msg::Quat::_w_type arg)
  {
    msg_.w = std::move(arg);
    return Init_Quat_x(msg_);
  }

private:
  ::isaacsim_msgs::msg::Quat msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaacsim_msgs::msg::Quat>()
{
  return isaacsim_msgs::msg::builder::Init_Quat_w();
}

}  // namespace isaacsim_msgs

#endif  // ISAACSIM_MSGS__MSG__DETAIL__QUAT__BUILDER_HPP_
