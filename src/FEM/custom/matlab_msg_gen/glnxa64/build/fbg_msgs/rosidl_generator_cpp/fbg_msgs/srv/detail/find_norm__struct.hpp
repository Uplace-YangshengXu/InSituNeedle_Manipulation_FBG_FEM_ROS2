// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fbg_msgs:srv/FindNorm.idl
// generated code does not contain a copyright notice

#ifndef FBG_MSGS__SRV__DETAIL__FIND_NORM__STRUCT_HPP_
#define FBG_MSGS__SRV__DETAIL__FIND_NORM__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__fbg_msgs__srv__FindNorm_Request __attribute__((deprecated))
#else
# define DEPRECATED__fbg_msgs__srv__FindNorm_Request __declspec(deprecated)
#endif

namespace fbg_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FindNorm_Request_
{
  using Type = FindNorm_Request_<ContainerAllocator>;

  explicit FindNorm_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->input = 0.0;
    }
  }

  explicit FindNorm_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->input = 0.0;
    }
  }

  // field types and members
  using _input_type =
    double;
  _input_type input;

  // setters for named parameter idiom
  Type & set__input(
    const double & _arg)
  {
    this->input = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fbg_msgs::srv::FindNorm_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const fbg_msgs::srv::FindNorm_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fbg_msgs::srv::FindNorm_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fbg_msgs::srv::FindNorm_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fbg_msgs::srv::FindNorm_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fbg_msgs::srv::FindNorm_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fbg_msgs::srv::FindNorm_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fbg_msgs::srv::FindNorm_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fbg_msgs::srv::FindNorm_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fbg_msgs::srv::FindNorm_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fbg_msgs__srv__FindNorm_Request
    std::shared_ptr<fbg_msgs::srv::FindNorm_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fbg_msgs__srv__FindNorm_Request
    std::shared_ptr<fbg_msgs::srv::FindNorm_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindNorm_Request_ & other) const
  {
    if (this->input != other.input) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindNorm_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindNorm_Request_

// alias to use template instance with default allocator
using FindNorm_Request =
  fbg_msgs::srv::FindNorm_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace fbg_msgs


#ifndef _WIN32
# define DEPRECATED__fbg_msgs__srv__FindNorm_Response __attribute__((deprecated))
#else
# define DEPRECATED__fbg_msgs__srv__FindNorm_Response __declspec(deprecated)
#endif

namespace fbg_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FindNorm_Response_
{
  using Type = FindNorm_Response_<ContainerAllocator>;

  explicit FindNorm_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->norm = 0.0;
    }
  }

  explicit FindNorm_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->norm = 0.0;
    }
  }

  // field types and members
  using _norm_type =
    double;
  _norm_type norm;

  // setters for named parameter idiom
  Type & set__norm(
    const double & _arg)
  {
    this->norm = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fbg_msgs::srv::FindNorm_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const fbg_msgs::srv::FindNorm_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fbg_msgs::srv::FindNorm_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fbg_msgs::srv::FindNorm_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fbg_msgs::srv::FindNorm_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fbg_msgs::srv::FindNorm_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fbg_msgs::srv::FindNorm_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fbg_msgs::srv::FindNorm_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fbg_msgs::srv::FindNorm_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fbg_msgs::srv::FindNorm_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fbg_msgs__srv__FindNorm_Response
    std::shared_ptr<fbg_msgs::srv::FindNorm_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fbg_msgs__srv__FindNorm_Response
    std::shared_ptr<fbg_msgs::srv::FindNorm_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindNorm_Response_ & other) const
  {
    if (this->norm != other.norm) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindNorm_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindNorm_Response_

// alias to use template instance with default allocator
using FindNorm_Response =
  fbg_msgs::srv::FindNorm_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace fbg_msgs

namespace fbg_msgs
{

namespace srv
{

struct FindNorm
{
  using Request = fbg_msgs::srv::FindNorm_Request;
  using Response = fbg_msgs::srv::FindNorm_Response;
};

}  // namespace srv

}  // namespace fbg_msgs

#endif  // FBG_MSGS__SRV__DETAIL__FIND_NORM__STRUCT_HPP_
