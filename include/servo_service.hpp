#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/range.hpp"

#include "minion_servo/srv/set_servo.hpp"


#include "servo.hpp"

using SetServo = minion_servo::srv::SetServo;


class ServoService : public rclcpp::Node
{
public:
  ServoService();

private:
  Servo *servo;
  uint32_t _servo_pin;
  std::string _service_name;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<sensor_msgs::msg::Range>::SharedPtr publisher_;
  rclcpp::Service<SetServo>::SharedPtr service;
  void set_servo(const std::shared_ptr<SetServo::Request> request,  std::shared_ptr<SetServo::Response> response);
};
