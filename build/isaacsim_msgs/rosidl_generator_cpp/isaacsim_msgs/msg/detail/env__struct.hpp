// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from isaacsim_msgs:msg/Env.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__MSG__DETAIL__ENV__STRUCT_HPP_
#define ISAACSIM_MSGS__MSG__DETAIL__ENV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__isaacsim_msgs__msg__Env __attribute__((deprecated))
#else
# define DEPRECATED__isaacsim_msgs__msg__Env __declspec(deprecated)
#endif

namespace isaacsim_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Env_
{
  using Type = Env_<ContainerAllocator>;

  explicit Env_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Env_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _robots_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _robots_type robots;
  using _environments_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _environments_type environments;
  using _robot_positions_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _robot_positions_type robot_positions;
  using _robot_rotations_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _robot_rotations_type robot_rotations;
  using _environment_positions_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _environment_positions_type environment_positions;
  using _environment_rotations_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _environment_rotations_type environment_rotations;

  // setters for named parameter idiom
  Type & set__robots(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->robots = _arg;
    return *this;
  }
  Type & set__environments(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->environments = _arg;
    return *this;
  }
  Type & set__robot_positions(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->robot_positions = _arg;
    return *this;
  }
  Type & set__robot_rotations(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->robot_rotations = _arg;
    return *this;
  }
  Type & set__environment_positions(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->environment_positions = _arg;
    return *this;
  }
  Type & set__environment_rotations(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->environment_rotations = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaacsim_msgs::msg::Env_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaacsim_msgs::msg::Env_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaacsim_msgs::msg::Env_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaacsim_msgs::msg::Env_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaacsim_msgs::msg::Env_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaacsim_msgs::msg::Env_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaacsim_msgs::msg::Env_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaacsim_msgs::msg::Env_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaacsim_msgs::msg::Env_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaacsim_msgs::msg::Env_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaacsim_msgs__msg__Env
    std::shared_ptr<isaacsim_msgs::msg::Env_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaacsim_msgs__msg__Env
    std::shared_ptr<isaacsim_msgs::msg::Env_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Env_ & other) const
  {
    if (this->robots != other.robots) {
      return false;
    }
    if (this->environments != other.environments) {
      return false;
    }
    if (this->robot_positions != other.robot_positions) {
      return false;
    }
    if (this->robot_rotations != other.robot_rotations) {
      return false;
    }
    if (this->environment_positions != other.environment_positions) {
      return false;
    }
    if (this->environment_rotations != other.environment_rotations) {
      return false;
    }
    return true;
  }
  bool operator!=(const Env_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Env_

// alias to use template instance with default allocator
using Env =
  isaacsim_msgs::msg::Env_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace isaacsim_msgs

#endif  // ISAACSIM_MSGS__MSG__DETAIL__ENV__STRUCT_HPP_
