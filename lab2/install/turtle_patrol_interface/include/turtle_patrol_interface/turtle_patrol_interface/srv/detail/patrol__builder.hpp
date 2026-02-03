// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_patrol_interface:srv/Patrol.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_PATROL_INTERFACE__SRV__DETAIL__PATROL__BUILDER_HPP_
#define TURTLE_PATROL_INTERFACE__SRV__DETAIL__PATROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_patrol_interface/srv/detail/patrol__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_patrol_interface
{

namespace srv
{

namespace builder
{

class Init_Patrol_Request_omega
{
public:
  explicit Init_Patrol_Request_omega(::turtle_patrol_interface::srv::Patrol_Request & msg)
  : msg_(msg)
  {}
  ::turtle_patrol_interface::srv::Patrol_Request omega(::turtle_patrol_interface::srv::Patrol_Request::_omega_type arg)
  {
    msg_.omega = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_patrol_interface::srv::Patrol_Request msg_;
};

class Init_Patrol_Request_vel
{
public:
  Init_Patrol_Request_vel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Patrol_Request_omega vel(::turtle_patrol_interface::srv::Patrol_Request::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_Patrol_Request_omega(msg_);
  }

private:
  ::turtle_patrol_interface::srv::Patrol_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_patrol_interface::srv::Patrol_Request>()
{
  return turtle_patrol_interface::srv::builder::Init_Patrol_Request_vel();
}

}  // namespace turtle_patrol_interface


namespace turtle_patrol_interface
{

namespace srv
{

namespace builder
{

class Init_Patrol_Response_cmd
{
public:
  Init_Patrol_Response_cmd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtle_patrol_interface::srv::Patrol_Response cmd(::turtle_patrol_interface::srv::Patrol_Response::_cmd_type arg)
  {
    msg_.cmd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_patrol_interface::srv::Patrol_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_patrol_interface::srv::Patrol_Response>()
{
  return turtle_patrol_interface::srv::builder::Init_Patrol_Response_cmd();
}

}  // namespace turtle_patrol_interface

#endif  // TURTLE_PATROL_INTERFACE__SRV__DETAIL__PATROL__BUILDER_HPP_
