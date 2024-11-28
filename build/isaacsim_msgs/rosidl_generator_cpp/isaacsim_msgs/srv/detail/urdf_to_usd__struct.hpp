// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from isaacsim_msgs:srv/UrdfToUsd.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__SRV__DETAIL__URDF_TO_USD__STRUCT_HPP_
#define ISAACSIM_MSGS__SRV__DETAIL__URDF_TO_USD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__isaacsim_msgs__srv__UrdfToUsd_Request __attribute__((deprecated))
#else
# define DEPRECATED__isaacsim_msgs__srv__UrdfToUsd_Request __declspec(deprecated)
#endif

namespace isaacsim_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct UrdfToUsd_Request_
{
  using Type = UrdfToUsd_Request_<ContainerAllocator>;

  explicit UrdfToUsd_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->urdf_path = "";
    }
  }

  explicit UrdfToUsd_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    urdf_path(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->urdf_path = "";
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _urdf_path_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _urdf_path_type urdf_path;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__urdf_path(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->urdf_path = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaacsim_msgs::srv::UrdfToUsd_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaacsim_msgs::srv::UrdfToUsd_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaacsim_msgs::srv::UrdfToUsd_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaacsim_msgs::srv::UrdfToUsd_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaacsim_msgs::srv::UrdfToUsd_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaacsim_msgs::srv::UrdfToUsd_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaacsim_msgs::srv::UrdfToUsd_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaacsim_msgs::srv::UrdfToUsd_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaacsim_msgs::srv::UrdfToUsd_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaacsim_msgs::srv::UrdfToUsd_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaacsim_msgs__srv__UrdfToUsd_Request
    std::shared_ptr<isaacsim_msgs::srv::UrdfToUsd_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaacsim_msgs__srv__UrdfToUsd_Request
    std::shared_ptr<isaacsim_msgs::srv::UrdfToUsd_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UrdfToUsd_Request_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->urdf_path != other.urdf_path) {
      return false;
    }
    return true;
  }
  bool operator!=(const UrdfToUsd_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UrdfToUsd_Request_

// alias to use template instance with default allocator
using UrdfToUsd_Request =
  isaacsim_msgs::srv::UrdfToUsd_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace isaacsim_msgs


#ifndef _WIN32
# define DEPRECATED__isaacsim_msgs__srv__UrdfToUsd_Response __attribute__((deprecated))
#else
# define DEPRECATED__isaacsim_msgs__srv__UrdfToUsd_Response __declspec(deprecated)
#endif

namespace isaacsim_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct UrdfToUsd_Response_
{
  using Type = UrdfToUsd_Response_<ContainerAllocator>;

  explicit UrdfToUsd_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->usd_path = "";
    }
  }

  explicit UrdfToUsd_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : usd_path(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->usd_path = "";
    }
  }

  // field types and members
  using _usd_path_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _usd_path_type usd_path;

  // setters for named parameter idiom
  Type & set__usd_path(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->usd_path = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaacsim_msgs::srv::UrdfToUsd_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaacsim_msgs::srv::UrdfToUsd_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaacsim_msgs::srv::UrdfToUsd_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaacsim_msgs::srv::UrdfToUsd_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaacsim_msgs::srv::UrdfToUsd_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaacsim_msgs::srv::UrdfToUsd_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaacsim_msgs::srv::UrdfToUsd_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaacsim_msgs::srv::UrdfToUsd_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaacsim_msgs::srv::UrdfToUsd_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaacsim_msgs::srv::UrdfToUsd_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaacsim_msgs__srv__UrdfToUsd_Response
    std::shared_ptr<isaacsim_msgs::srv::UrdfToUsd_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaacsim_msgs__srv__UrdfToUsd_Response
    std::shared_ptr<isaacsim_msgs::srv::UrdfToUsd_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UrdfToUsd_Response_ & other) const
  {
    if (this->usd_path != other.usd_path) {
      return false;
    }
    return true;
  }
  bool operator!=(const UrdfToUsd_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UrdfToUsd_Response_

// alias to use template instance with default allocator
using UrdfToUsd_Response =
  isaacsim_msgs::srv::UrdfToUsd_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace isaacsim_msgs

namespace isaacsim_msgs
{

namespace srv
{

struct UrdfToUsd
{
  using Request = isaacsim_msgs::srv::UrdfToUsd_Request;
  using Response = isaacsim_msgs::srv::UrdfToUsd_Response;
};

}  // namespace srv

}  // namespace isaacsim_msgs

#endif  // ISAACSIM_MSGS__SRV__DETAIL__URDF_TO_USD__STRUCT_HPP_
