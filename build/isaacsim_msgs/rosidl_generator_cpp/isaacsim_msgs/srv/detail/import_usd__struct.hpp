// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from isaacsim_msgs:srv/ImportUsd.idl
// generated code does not contain a copyright notice

#ifndef ISAACSIM_MSGS__SRV__DETAIL__IMPORT_USD__STRUCT_HPP_
#define ISAACSIM_MSGS__SRV__DETAIL__IMPORT_USD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__isaacsim_msgs__srv__ImportUsd_Request __attribute__((deprecated))
#else
# define DEPRECATED__isaacsim_msgs__srv__ImportUsd_Request __declspec(deprecated)
#endif

namespace isaacsim_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ImportUsd_Request_
{
  using Type = ImportUsd_Request_<ContainerAllocator>;

  explicit ImportUsd_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      std::fill<typename std::array<float, 3>::iterator, float>(this->position.begin(), this->position.end(), 0.0f);
      this->orientation[0] = 1.0f;
      this->orientation[1] = 0.0f;
      this->orientation[2] = 0.0f;
      this->orientation[3] = 0.0f;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->name = "";
      this->usd_path = "";
      this->prim_path = "";
      this->control = false;
      std::fill<typename std::array<float, 3>::iterator, float>(this->position.begin(), this->position.end(), 0.0f);
      std::fill<typename std::array<float, 4>::iterator, float>(this->orientation.begin(), this->orientation.end(), 0.0f);
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->usd_path = "";
      this->prim_path = "";
      this->control = false;
    }
  }

  explicit ImportUsd_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    usd_path(_alloc),
    prim_path(_alloc),
    position(_alloc),
    orientation(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      std::fill<typename std::array<float, 3>::iterator, float>(this->position.begin(), this->position.end(), 0.0f);
      this->orientation[0] = 1.0f;
      this->orientation[1] = 0.0f;
      this->orientation[2] = 0.0f;
      this->orientation[3] = 0.0f;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->name = "";
      this->usd_path = "";
      this->prim_path = "";
      this->control = false;
      std::fill<typename std::array<float, 3>::iterator, float>(this->position.begin(), this->position.end(), 0.0f);
      std::fill<typename std::array<float, 4>::iterator, float>(this->orientation.begin(), this->orientation.end(), 0.0f);
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->usd_path = "";
      this->prim_path = "";
      this->control = false;
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _usd_path_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _usd_path_type usd_path;
  using _prim_path_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _prim_path_type prim_path;
  using _control_type =
    bool;
  _control_type control;
  using _position_type =
    std::array<float, 3>;
  _position_type position;
  using _orientation_type =
    std::array<float, 4>;
  _orientation_type orientation;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__usd_path(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->usd_path = _arg;
    return *this;
  }
  Type & set__prim_path(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->prim_path = _arg;
    return *this;
  }
  Type & set__control(
    const bool & _arg)
  {
    this->control = _arg;
    return *this;
  }
  Type & set__position(
    const std::array<float, 3> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__orientation(
    const std::array<float, 4> & _arg)
  {
    this->orientation = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaacsim_msgs::srv::ImportUsd_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaacsim_msgs::srv::ImportUsd_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaacsim_msgs::srv::ImportUsd_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaacsim_msgs::srv::ImportUsd_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaacsim_msgs::srv::ImportUsd_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaacsim_msgs::srv::ImportUsd_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaacsim_msgs::srv::ImportUsd_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaacsim_msgs::srv::ImportUsd_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaacsim_msgs::srv::ImportUsd_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaacsim_msgs::srv::ImportUsd_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaacsim_msgs__srv__ImportUsd_Request
    std::shared_ptr<isaacsim_msgs::srv::ImportUsd_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaacsim_msgs__srv__ImportUsd_Request
    std::shared_ptr<isaacsim_msgs::srv::ImportUsd_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImportUsd_Request_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->usd_path != other.usd_path) {
      return false;
    }
    if (this->prim_path != other.prim_path) {
      return false;
    }
    if (this->control != other.control) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->orientation != other.orientation) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImportUsd_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImportUsd_Request_

// alias to use template instance with default allocator
using ImportUsd_Request =
  isaacsim_msgs::srv::ImportUsd_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace isaacsim_msgs


#ifndef _WIN32
# define DEPRECATED__isaacsim_msgs__srv__ImportUsd_Response __attribute__((deprecated))
#else
# define DEPRECATED__isaacsim_msgs__srv__ImportUsd_Response __declspec(deprecated)
#endif

namespace isaacsim_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ImportUsd_Response_
{
  using Type = ImportUsd_Response_<ContainerAllocator>;

  explicit ImportUsd_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ret = false;
    }
  }

  explicit ImportUsd_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ret = false;
    }
  }

  // field types and members
  using _ret_type =
    bool;
  _ret_type ret;

  // setters for named parameter idiom
  Type & set__ret(
    const bool & _arg)
  {
    this->ret = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaacsim_msgs::srv::ImportUsd_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaacsim_msgs::srv::ImportUsd_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaacsim_msgs::srv::ImportUsd_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaacsim_msgs::srv::ImportUsd_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaacsim_msgs::srv::ImportUsd_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaacsim_msgs::srv::ImportUsd_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaacsim_msgs::srv::ImportUsd_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaacsim_msgs::srv::ImportUsd_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaacsim_msgs::srv::ImportUsd_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaacsim_msgs::srv::ImportUsd_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaacsim_msgs__srv__ImportUsd_Response
    std::shared_ptr<isaacsim_msgs::srv::ImportUsd_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaacsim_msgs__srv__ImportUsd_Response
    std::shared_ptr<isaacsim_msgs::srv::ImportUsd_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImportUsd_Response_ & other) const
  {
    if (this->ret != other.ret) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImportUsd_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImportUsd_Response_

// alias to use template instance with default allocator
using ImportUsd_Response =
  isaacsim_msgs::srv::ImportUsd_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace isaacsim_msgs

namespace isaacsim_msgs
{

namespace srv
{

struct ImportUsd
{
  using Request = isaacsim_msgs::srv::ImportUsd_Request;
  using Response = isaacsim_msgs::srv::ImportUsd_Response;
};

}  // namespace srv

}  // namespace isaacsim_msgs

#endif  // ISAACSIM_MSGS__SRV__DETAIL__IMPORT_USD__STRUCT_HPP_
