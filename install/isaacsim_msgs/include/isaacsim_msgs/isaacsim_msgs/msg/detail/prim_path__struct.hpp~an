// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from isaacsim_msgs:msg/PrimPath.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__MSG__DETAIL__PRIM_PATH__STRUCT_HPP_
#define ISAACSIM_MSGS__MSG__DETAIL__PRIM_PATH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__isaacsim_msgs__msg__PrimPath __attribute__((deprecated))
#else
# define DEPRECATED__isaacsim_msgs__msg__PrimPath __declspec(deprecated)
#endif

namespace isaacsim_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PrimPath_
{
  using Type = PrimPath_<ContainerAllocator>;

  explicit PrimPath_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->path = "";
    }
  }

  explicit PrimPath_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : path(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->path = "";
    }
  }

  // field types and members
  using _path_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _path_type path;

  // setters for named parameter idiom
  Type & set__path(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->path = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaacsim_msgs::msg::PrimPath_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaacsim_msgs::msg::PrimPath_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaacsim_msgs::msg::PrimPath_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaacsim_msgs::msg::PrimPath_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaacsim_msgs::msg::PrimPath_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaacsim_msgs::msg::PrimPath_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaacsim_msgs::msg::PrimPath_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaacsim_msgs::msg::PrimPath_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaacsim_msgs::msg::PrimPath_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaacsim_msgs::msg::PrimPath_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaacsim_msgs__msg__PrimPath
    std::shared_ptr<isaacsim_msgs::msg::PrimPath_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaacsim_msgs__msg__PrimPath
    std::shared_ptr<isaacsim_msgs::msg::PrimPath_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PrimPath_ & other) const
  {
    if (this->path != other.path) {
      return false;
    }
    return true;
  }
  bool operator!=(const PrimPath_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PrimPath_

// alias to use template instance with default allocator
using PrimPath =
  isaacsim_msgs::msg::PrimPath_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace isaacsim_msgs

#endif  // ISAACSIM_MSGS__MSG__DETAIL__PRIM_PATH__STRUCT_HPP_
