cmake_minimum_required(VERSION 3.8)
project(assignment1_subpub)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(assignment1_msgs REQUIRED)
find_package(rclcpp REQUIRED)

include_directories(include)
add_library(subpub SHARED src/publisher.cpp src/subscriber.cpp)# build a lib<week02>.so based on multiple source flies
ament_target_dependencies(subpub rclcpp assignment1_msgs) # dependencies 

add_executable(pub src/publisher_node.cpp)
target_link_libraries(pub subpub)
ament_target_dependencies(pub rclcpp)

add_executable(sub src/subscriber_node.cpp)
target_link_libraries(sub subpub)
ament_target_dependencies(sub rclcpp)

install( DIRECTORY include/ DESTINATION include)
install( TARGETS subpub LIBRARY DESTINATION lib)
install( TARGETS pub sub DESTINATION lib/${PROJECT_NAME}) 

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
