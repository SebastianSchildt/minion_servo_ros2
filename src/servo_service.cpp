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
    this->declare_parameter<int>("servo_pin", 23);
    this->declare_parameter<std::string>("servo_service", "/example_servo");

    
    this->get_parameter("servo_pin", this->_servo_pin);
    this->get_parameter("servo_service", this->_service_name);

    RCLCPP_INFO(this->get_logger(), "Using server pin %i", this->_servo_pin);
    servo=new Servo(_servo_pin);

    this->service = this->create_service<SetServo>(_service_name, std::bind(&ServoService::set_servo,this, std::placeholders::_1, std::placeholders::_2));

   
    RCLCPP_INFO(this->get_logger(), "Ready for action on service %s", _service_name.c_str() );
  }

void ServoService::set_servo(const std::shared_ptr<SetServo::Request> request,
          std::shared_ptr<SetServo::Response>      response)
{
  response->ok = true;
  this->servo->setDeg(request->degree);
  RCLCPP_DEBUG(this->get_logger(), "Setting servo to: %ld",  request->degree);
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ServoService>());
  rclcpp::shutdown();
  return 0;
}
