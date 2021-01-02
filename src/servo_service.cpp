// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "servo_service.hpp"


using namespace std::chrono_literals;


ServoService::ServoService() : Node("minion_ultrasonic")
  {
    //publisher_ = this->create_publisher<sensor_msgs::msg::Range>("ultrasonic_range", 10);
    this->declare_parameter<int>("servo_pin", 23);
    
    this->get_parameter("servo_pin", this->_servo_pin);
    RCLCPP_INFO(this->get_logger(), "Using server pin %i", this->_servo_pin);

    servo=new Servo(_servo_pin);
  }


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ServoService>());
  rclcpp::shutdown();
  return 0;
}
