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


ServoService::ServoService() : Node("minion_servo_server")
  {
    //publisher_ = this->create_publisher<sensor_msgs::msg::Range>("ultrasonic_range", 10);
    this->declare_parameter<int>("servo_pin", 23);
    
    this->get_parameter("servo_pin", this->_servo_pin);
    RCLCPP_INFO(this->get_logger(), "Using server pin %i", this->_servo_pin);
    servo=new Servo(_servo_pin);

    rclcpp::Service<SetServo>::SharedPtr service = this->create_service<SetServo>("set_degree", std::bind(&ServoService::set_servo,this, std::placeholders::_1, std::placeholders::_2));

  }

void ServoService::set_servo(const std::shared_ptr<SetServo::Request> request,
          std::shared_ptr<SetServo::Response>      response)
{
  response->ok = true;
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld",       request->degree);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%d]", (long int)response->ok);
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ServoService>());
  rclcpp::shutdown();
  return 0;
}
