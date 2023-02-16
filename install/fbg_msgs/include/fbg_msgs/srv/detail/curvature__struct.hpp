// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fbg_msgs:srv/Curvature.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__SRV__DETAIL__CURVATURE__STRUCT_HPP_
#define FBG_MSGS__SRV__DETAIL__CURVATURE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'fbg_reading'
#include "fbg_msgs/msg/detail/fbg_reading__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fbg_msgs__srv__Curvature_Request __attribute__((deprecated))
#else
# define DEPRECATED__fbg_msgs__srv__Curvature_Request __declspec(deprecated)
#endif

namespace fbg_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Curvature_Request_
{
  using Type = Curvature_Request_<ContainerAllocator>;

  explicit Curvature_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : fbg_reading(_init)
  {
    (void)_init;
  }

  explicit Curvature_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : fbg_reading(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _fbg_reading_type =
    fbg_msgs::msg::FbgReading_<ContainerAllocator>;
  _fbg_reading_type fbg_reading;

  // setters for named parameter idiom
  Type & set__fbg_reading(
    const fbg_msgs::msg::FbgReading_<ContainerAllocator> & _arg)
  {
    this->fbg_reading = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fbg_msgs::srv::Curvature_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const fbg_msgs::srv::Curvature_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fbg_msgs::srv::Curvature_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fbg_msgs::srv::Curvature_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fbg_msgs::srv::Curvature_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fbg_msgs::srv::Curvature_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fbg_msgs::srv::Curvature_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fbg_msgs::srv::Curvature_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fbg_msgs::srv::Curvature_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fbg_msgs::srv::Curvature_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fbg_msgs__srv__Curvature_Request
    std::shared_ptr<fbg_msgs::srv::Curvature_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fbg_msgs__srv__Curvature_Request
    std::shared_ptr<fbg_msgs::srv::Curvature_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Curvature_Request_ & other) const
  {
    if (this->fbg_reading != other.fbg_reading) {
      return false;
    }
    return true;
  }
  bool operator!=(const Curvature_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Curvature_Request_

// alias to use template instance with default allocator
using Curvature_Request =
  fbg_msgs::srv::Curvature_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace fbg_msgs


// Include directives for member types
// Member 'curvature'
#include "fbg_msgs/msg/detail/curvature__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fbg_msgs__srv__Curvature_Response __attribute__((deprecated))
#else
# define DEPRECATED__fbg_msgs__srv__Curvature_Response __declspec(deprecated)
#endif

namespace fbg_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Curvature_Response_
{
  using Type = Curvature_Response_<ContainerAllocator>;

  explicit Curvature_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : curvature(_init)
  {
    (void)_init;
  }

  explicit Curvature_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : curvature(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _curvature_type =
    fbg_msgs::msg::Curvature_<ContainerAllocator>;
  _curvature_type curvature;

  // setters for named parameter idiom
  Type & set__curvature(
    const fbg_msgs::msg::Curvature_<ContainerAllocator> & _arg)
  {
    this->curvature = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fbg_msgs::srv::Curvature_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const fbg_msgs::srv::Curvature_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fbg_msgs::srv::Curvature_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fbg_msgs::srv::Curvature_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fbg_msgs::srv::Curvature_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fbg_msgs::srv::Curvature_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fbg_msgs::srv::Curvature_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fbg_msgs::srv::Curvature_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fbg_msgs::srv::Curvature_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fbg_msgs::srv::Curvature_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fbg_msgs__srv__Curvature_Response
    std::shared_ptr<fbg_msgs::srv::Curvature_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fbg_msgs__srv__Curvature_Response
    std::shared_ptr<fbg_msgs::srv::Curvature_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Curvature_Response_ & other) const
  {
    if (this->curvature != other.curvature) {
      return false;
    }
    return true;
  }
  bool operator!=(const Curvature_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Curvature_Response_

// alias to use template instance with default allocator
using Curvature_Response =
  fbg_msgs::srv::Curvature_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace fbg_msgs

namespace fbg_msgs
{

namespace srv
{

struct Curvature
{
  using Request = fbg_msgs::srv::Curvature_Request;
  using Response = fbg_msgs::srv::Curvature_Response;
};

}  // namespace srv

}  // namespace fbg_msgs

#endif  // FBG_MSGS__SRV__DETAIL__CURVATURE__STRUCT_HPP_
