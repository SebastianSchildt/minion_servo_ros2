cmake_minimum_required(VERSION 3.12)
project(minion_servo)


# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(common_interfaces REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)

find_package(Boost COMPONENTS thread chrono REQUIRED)

find_package(rosidl_default_generators REQUIRED)

#need to be ${PROJECT_NAME} as per https://github.com/ros2/rosidl/issues/441
rosidl_generate_interfaces( ${PROJECT_NAME}   "srv/SetServo.srv" DEPENDENCIES builtin_interfaces   )

ament_export_dependencies(rosidl_default_runtime)


set(SERVO_SOURCES
   src/servo_service.cpp
   src/servo.cpp
)

add_executable(minion_servo_service  ${SERVO_SOURCES})

#minion_servo is target name for interface, so add _service here
rosidl_target_interfaces(minion_servo_service  ${PROJECT_NAME} "rosidl_typesupport_cpp")

target_include_directories(minion_servo_service PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries (minion_servo_service   ${Boost_LIBRARIES} -lpigpiod_if2 -lpthread)
target_link_libraries(minion_servo_service  crypt rt)

ament_target_dependencies(minion_servo_service rclcpp)

install(TARGETS
  minion_servo_service
  DESTINATION lib/${PROJECT_NAME})

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)



ament_package()
