from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="minion_servo",
            executable="minion_servo_service",
            name="ultrasonic_servo",
            output="screen",
            emulate_tty=True,
            parameters=[
                {"servo_pin": 23},
                {"servo_service": "ultrasonic_servo"},
            ]
        ),
        Node(
            package="minion_servo",
            executable="minion_servo_service",
            name="cam_axis1_servo",
            output="screen",
            emulate_tty=True,
            parameters=[
                {"servo_pin": 11},
                {"servo_service": "cam_axis1_servo"},
            ]
        ),
        Node(
            package="minion_servo",
            executable="minion_servo_service",
            name="cam_axis2_servo",
            output="screen",
            emulate_tty=True,
            parameters=[
                {"servo_pin": 9},
                {"servo_service": "cam_axis2_servo"},
            ]
        ),
    ])