// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from turtle_patrol_interface:srv/Patrol.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_PATROL_INTERFACE__SRV__DETAIL__PATROL__STRUCT_HPP_
#define TURTLE_PATROL_INTERFACE__SRV__DETAIL__PATROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__turtle_patrol_interface__srv__Patrol_Request __attribute__((deprecated))
#else
# define DEPRECATED__turtle_patrol_interface__srv__Patrol_Request __declspec(deprecated)
#endif

namespace turtle_patrol_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Patrol_Request_
{
  using Type = Patrol_Request_<ContainerAllocator>;

  explicit Patrol_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vel = 0.0f;
      this->omega = 0.0f;
    }
  }

  explicit Patrol_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vel = 0.0f;
      this->omega = 0.0f;
    }
  }

  // field types and members
  using _vel_type =
    float;
  _vel_type vel;
  using _omega_type =
    float;
  _omega_type omega;

  // setters for named parameter idiom
  Type & set__vel(
    const float & _arg)
  {
    this->vel = _arg;
    return *this;
  }
  Type & set__omega(
    const float & _arg)
  {
    this->omega = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtle_patrol_interface::srv::Patrol_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtle_patrol_interface::srv::Patrol_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtle_patrol_interface::srv::Patrol_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtle_patrol_interface::srv::Patrol_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtle_patrol_interface::srv::Patrol_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtle_patrol_interface::srv::Patrol_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtle_patrol_interface::srv::Patrol_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtle_patrol_interface::srv::Patrol_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtle_patrol_interface::srv::Patrol_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtle_patrol_interface::srv::Patrol_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtle_patrol_interface__srv__Patrol_Request
    std::shared_ptr<turtle_patrol_interface::srv::Patrol_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtle_patrol_interface__srv__Patrol_Request
    std::shared_ptr<turtle_patrol_interface::srv::Patrol_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Patrol_Request_ & other) const
  {
    if (this->vel != other.vel) {
      return false;
    }
    if (this->omega != other.omega) {
      return false;
    }
    return true;
  }
  bool operator!=(const Patrol_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Patrol_Request_

// alias to use template instance with default allocator
using Patrol_Request =
  turtle_patrol_interface::srv::Patrol_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace turtle_patrol_interface


// Include directives for member types
// Member 'cmd'
#include "geometry_msgs/msg/detail/twist__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__turtle_patrol_interface__srv__Patrol_Response __attribute__((deprecated))
#else
# define DEPRECATED__turtle_patrol_interface__srv__Patrol_Response __declspec(deprecated)
#endif

namespace turtle_patrol_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Patrol_Response_
{
  using Type = Patrol_Response_<ContainerAllocator>;

  explicit Patrol_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cmd(_init)
  {
    (void)_init;
  }

  explicit Patrol_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cmd(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _cmd_type =
    geometry_msgs::msg::Twist_<ContainerAllocator>;
  _cmd_type cmd;

  // setters for named parameter idiom
  Type & set__cmd(
    const geometry_msgs::msg::Twist_<ContainerAllocator> & _arg)
  {
    this->cmd = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtle_patrol_interface::srv::Patrol_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtle_patrol_interface::srv::Patrol_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtle_patrol_interface::srv::Patrol_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtle_patrol_interface::srv::Patrol_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtle_patrol_interface::srv::Patrol_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtle_patrol_interface::srv::Patrol_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtle_patrol_interface::srv::Patrol_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtle_patrol_interface::srv::Patrol_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtle_patrol_interface::srv::Patrol_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtle_patrol_interface::srv::Patrol_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtle_patrol_interface__srv__Patrol_Response
    std::shared_ptr<turtle_patrol_interface::srv::Patrol_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtle_patrol_interface__srv__Patrol_Response
    std::shared_ptr<turtle_patrol_interface::srv::Patrol_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Patrol_Response_ & other) const
  {
    if (this->cmd != other.cmd) {
      return false;
    }
    return true;
  }
  bool operator!=(const Patrol_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Patrol_Response_

// alias to use template instance with default allocator
using Patrol_Response =
  turtle_patrol_interface::srv::Patrol_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace turtle_patrol_interface

namespace turtle_patrol_interface
{

namespace srv
{

struct Patrol
{
  using Request = turtle_patrol_interface::srv::Patrol_Request;
  using Response = turtle_patrol_interface::srv::Patrol_Response;
};

}  // namespace srv

}  // namespace turtle_patrol_interface

#endif  // TURTLE_PATROL_INTERFACE__SRV__DETAIL__PATROL__STRUCT_HPP_
