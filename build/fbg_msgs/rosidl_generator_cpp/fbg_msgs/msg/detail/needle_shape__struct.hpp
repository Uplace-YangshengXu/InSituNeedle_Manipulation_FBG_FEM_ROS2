// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fbg_msgs:msg/NeedleShape.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__MSG__DETAIL__NEEDLE_SHAPE__STRUCT_HPP_
#define FBG_MSGS__MSG__DETAIL__NEEDLE_SHAPE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__fbg_msgs__msg__NeedleShape __attribute__((deprecated))
#else
# define DEPRECATED__fbg_msgs__msg__NeedleShape __declspec(deprecated)
#endif

namespace fbg_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NeedleShape_
{
  using Type = NeedleShape_<ContainerAllocator>;

  explicit NeedleShape_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->needle_total_length = 0;
    }
  }

  explicit NeedleShape_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->needle_total_length = 0;
    }
  }

  // field types and members
  using _needle_total_length_type =
    uint8_t;
  _needle_total_length_type needle_total_length;
  using _active_area_location_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _active_area_location_type active_area_location;
  using _needle_x_axis_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _needle_x_axis_type needle_x_axis;
  using _needle_y_axis_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _needle_y_axis_type needle_y_axis;
  using _needle_z_axis_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _needle_z_axis_type needle_z_axis;
  using _needle_slope_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _needle_slope_type needle_slope;

  // setters for named parameter idiom
  Type & set__needle_total_length(
    const uint8_t & _arg)
  {
    this->needle_total_length = _arg;
    return *this;
  }
  Type & set__active_area_location(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->active_area_location = _arg;
    return *this;
  }
  Type & set__needle_x_axis(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->needle_x_axis = _arg;
    return *this;
  }
  Type & set__needle_y_axis(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->needle_y_axis = _arg;
    return *this;
  }
  Type & set__needle_z_axis(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->needle_z_axis = _arg;
    return *this;
  }
  Type & set__needle_slope(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->needle_slope = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fbg_msgs::msg::NeedleShape_<ContainerAllocator> *;
  using ConstRawPtr =
    const fbg_msgs::msg::NeedleShape_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fbg_msgs::msg::NeedleShape_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fbg_msgs::msg::NeedleShape_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fbg_msgs::msg::NeedleShape_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fbg_msgs::msg::NeedleShape_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fbg_msgs::msg::NeedleShape_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fbg_msgs::msg::NeedleShape_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fbg_msgs::msg::NeedleShape_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fbg_msgs::msg::NeedleShape_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fbg_msgs__msg__NeedleShape
    std::shared_ptr<fbg_msgs::msg::NeedleShape_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fbg_msgs__msg__NeedleShape
    std::shared_ptr<fbg_msgs::msg::NeedleShape_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NeedleShape_ & other) const
  {
    if (this->needle_total_length != other.needle_total_length) {
      return false;
    }
    if (this->active_area_location != other.active_area_location) {
      return false;
    }
    if (this->needle_x_axis != other.needle_x_axis) {
      return false;
    }
    if (this->needle_y_axis != other.needle_y_axis) {
      return false;
    }
    if (this->needle_z_axis != other.needle_z_axis) {
      return false;
    }
    if (this->needle_slope != other.needle_slope) {
      return false;
    }
    return true;
  }
  bool operator!=(const NeedleShape_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NeedleShape_

// alias to use template instance with default allocator
using NeedleShape =
  fbg_msgs::msg::NeedleShape_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace fbg_msgs

#endif  // FBG_MSGS__MSG__DETAIL__NEEDLE_SHAPE__STRUCT_HPP_
