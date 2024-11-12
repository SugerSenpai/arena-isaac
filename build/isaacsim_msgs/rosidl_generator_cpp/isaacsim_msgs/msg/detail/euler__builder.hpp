// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from isaacsim_msgs:msg/Euler.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__MSG__DETAIL__EULER__BUILDER_HPP_
#define ISAACSIM_MSGS__MSG__DETAIL__EULER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "isaacsim_msgs/msg/detail/euler__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace isaacsim_msgs
{

namespace msg
{

namespace builder
{

class Init_Euler_z
{
public:
  explicit Init_Euler_z(::isaacsim_msgs::msg::Euler & msg)
  : msg_(msg)
  {}
  ::isaacsim_msgs::msg::Euler z(::isaacsim_msgs::msg::Euler::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaacsim_msgs::msg::Euler msg_;
};

class Init_Euler_y
{
public:
  explicit Init_Euler_y(::isaacsim_msgs::msg::Euler & msg)
  : msg_(msg)
  {}
  Init_Euler_z y(::isaacsim_msgs::msg::Euler::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Euler_z(msg_);
  }

private:
  ::isaacsim_msgs::msg::Euler msg_;
};

class Init_Euler_x
{
public:
  Init_Euler_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Euler_y x(::isaacsim_msgs::msg::Euler::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Euler_y(msg_);
  }

private:
  ::isaacsim_msgs::msg::Euler msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaacsim_msgs::msg::Euler>()
{
  return isaacsim_msgs::msg::builder::Init_Euler_x();
}

}  // namespace isaacsim_msgs

#endif  // ISAACSIM_MSGS__MSG__DETAIL__EULER__BUILDER_HPP_
