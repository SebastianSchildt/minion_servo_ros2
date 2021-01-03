# minion_servo_ros2

A simple ROS2 module for servos using pigpio hw assisted PWM. It uses the [pigpiod](http://abyz.me.uk/rpi/pigpio/pigpiod.html) library. Before ROS2 nodes run succesfully you need to make sure that the `pgpiod` daemon is running.

Using pigpiod also implies **using BCM port numbers and ot wiringPi**, i.e. find the GPIO your servo is connected to at https://pinout.xyz/ and use the "GPIO/BCM" pin nimber



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

Or using launch file, preconfigured for  [Yahboom G1](https://www.yahboom.net/study/G1-T-PI)

```
ros2 launch minion_servo minion_servo_launch.py
```


Test it via

```
ros2 service call /set_degree minion_servo/srv/SetServo '{"degree": 20}'
```