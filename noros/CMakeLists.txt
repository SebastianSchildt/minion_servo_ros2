# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 3.12.1)
project (Servo)


find_package(Threads REQUIRED)
find_package(Boost COMPONENTS thread chrono REQUIRED)


set(SERVO_SOURCES
   ../src/main.cpp
   ../src/servo.cpp
)

add_executable (servo  ${SERVO_SOURCES} )
target_include_directories(servo PRIVATE ${CMAKE_SOURCE_DIR}/../include)
target_link_libraries (servo PRIVATE -lpigpiod_if2 -lpthread ${Boost_LIBRARIES} )
target_link_libraries(servo PRIVATE crypt rt)