// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fbg_msgs:msg/Curvature.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__MSG__DETAIL__CURVATURE__STRUCT_HPP_
#define FBG_MSGS__MSG__DETAIL__CURVATURE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__fbg_msgs__msg__Curvature __attribute__((deprecated))
#else
# define DEPRECATED__fbg_msgs__msg__Curvature __declspec(deprecated)
#endif

namespace fbg_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Curvature_
{
  using Type = Curvature_<ContainerAllocator>;

  explicit Curvature_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Curvature_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _curvature_xy_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _curvature_xy_type curvature_xy;
  using _curvature_xz_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _curvature_xz_type curvature_xz;

  // setters for named parameter idiom
  Type & set__curvature_xy(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->curvature_xy = _arg;
    return *this;
  }
  Type & set__curvature_xz(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->curvature_xz = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fbg_msgs::msg::Curvature_<ContainerAllocator> *;
  using ConstRawPtr =
    const fbg_msgs::msg::Curvature_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fbg_msgs::msg::Curvature_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fbg_msgs::msg::Curvature_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fbg_msgs::msg::Curvature_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fbg_msgs::msg::Curvature_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fbg_msgs::msg::Curvature_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fbg_msgs::msg::Curvature_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fbg_msgs::msg::Curvature_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fbg_msgs::msg::Curvature_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fbg_msgs__msg__Curvature
    std::shared_ptr<fbg_msgs::msg::Curvature_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fbg_msgs__msg__Curvature
    std::shared_ptr<fbg_msgs::msg::Curvature_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Curvature_ & other) const
  {
    if (this->curvature_xy != other.curvature_xy) {
      return false;
    }
    if (this->curvature_xz != other.curvature_xz) {
      return false;
    }
    return true;
  }
  bool operator!=(const Curvature_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Curvature_

// alias to use template instance with default allocator
using Curvature =
  fbg_msgs::msg::Curvature_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace fbg_msgs

#endif  // FBG_MSGS__MSG__DETAIL__CURVATURE__STRUCT_HPP_
