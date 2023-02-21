// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fbg_msgs:msg/FbgReading.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__MSG__DETAIL__FBG_READING__STRUCT_HPP_
#define FBG_MSGS__MSG__DETAIL__FBG_READING__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__fbg_msgs__msg__FbgReading __attribute__((deprecated))
#else
# define DEPRECATED__fbg_msgs__msg__FbgReading __declspec(deprecated)
#endif

namespace fbg_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FbgReading_
{
  using Type = FbgReading_<ContainerAllocator>;

  explicit FbgReading_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 4>::iterator, uint8_t>(this->signal_each_ch.begin(), this->signal_each_ch.end(), 0);
      this->total_reading_num = 0;
    }
  }

  explicit FbgReading_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : signal_each_ch(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 4>::iterator, uint8_t>(this->signal_each_ch.begin(), this->signal_each_ch.end(), 0);
      this->total_reading_num = 0;
    }
  }

  // field types and members
  using _signal_reading_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _signal_reading_type signal_reading;
  using _signal_each_ch_type =
    std::array<uint8_t, 4>;
  _signal_each_ch_type signal_each_ch;
  using _total_reading_num_type =
    uint8_t;
  _total_reading_num_type total_reading_num;

  // setters for named parameter idiom
  Type & set__signal_reading(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->signal_reading = _arg;
    return *this;
  }
  Type & set__signal_each_ch(
    const std::array<uint8_t, 4> & _arg)
  {
    this->signal_each_ch = _arg;
    return *this;
  }
  Type & set__total_reading_num(
    const uint8_t & _arg)
  {
    this->total_reading_num = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fbg_msgs::msg::FbgReading_<ContainerAllocator> *;
  using ConstRawPtr =
    const fbg_msgs::msg::FbgReading_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fbg_msgs::msg::FbgReading_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fbg_msgs::msg::FbgReading_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fbg_msgs::msg::FbgReading_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fbg_msgs::msg::FbgReading_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fbg_msgs::msg::FbgReading_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fbg_msgs::msg::FbgReading_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fbg_msgs::msg::FbgReading_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fbg_msgs::msg::FbgReading_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fbg_msgs__msg__FbgReading
    std::shared_ptr<fbg_msgs::msg::FbgReading_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fbg_msgs__msg__FbgReading
    std::shared_ptr<fbg_msgs::msg::FbgReading_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FbgReading_ & other) const
  {
    if (this->signal_reading != other.signal_reading) {
      return false;
    }
    if (this->signal_each_ch != other.signal_each_ch) {
      return false;
    }
    if (this->total_reading_num != other.total_reading_num) {
      return false;
    }
    return true;
  }
  bool operator!=(const FbgReading_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FbgReading_

// alias to use template instance with default allocator
using FbgReading =
  fbg_msgs::msg::FbgReading_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace fbg_msgs

#endif  // FBG_MSGS__MSG__DETAIL__FBG_READING__STRUCT_HPP_
