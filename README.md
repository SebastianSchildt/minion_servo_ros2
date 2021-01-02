# minion_servo_ros2

A simple ROS2 module for servos using pigpio hw assisted PWM.



Create ROS2 workspace, check this repo out int the `src` and do

```
rosdep install -i --from-path src --rosdistro foxy -y
colcon build --packages-select minion_servo
```

In an shell got to the workspace  do something like

```
 source /opt/ros/foxy/setup.bash
. install/setup.bash
```

Run with 

```
ros2 run  minion_servo  minion_servo 
```

Or using launch file

```
 ros2 launch minion_ultrasonic minion_ultrasonic_launch.py
```

Launch file can be used to set Pins (wiringPi numbers). Default config works for [Yahboom G1](https://www.yahboom.net/study/G1-T-PI) foward ultrasonic sensor.