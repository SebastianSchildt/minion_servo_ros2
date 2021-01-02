#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/range.hpp"

#include "servo.hpp"


class ServoService : public rclcpp::Node
{
public:
  ServoService();

private:
  Servo *servo;
  uint32_t _servo_pin;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<sensor_msgs::msg::Range>::SharedPtr publisher_;
};
