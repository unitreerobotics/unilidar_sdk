import os
import subprocess

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
  # Run unitree lidar
  node1 = Node(
    package='unitree_lidar_ros2',
    executable='unitree_lidar_ros2_node',
    name='unitree_lidar_ros2_node',
    output='screen',
    parameters= [
              {'port': '/dev/ttyUSB0'},
              {'rotate_yaw_bias': 0.0},
              {'range_scale': 0.001},
              {'range_bias': 0.0},
              {'range_max': 50.0},
              {'range_min': 0.0},
              {'cloud_frame': "unilidar_lidar"},
              {'cloud_topic': "unilidar/cloud"},
              {'cloud_scan_num': 18},
              {'imu_frame': "unilidar_imu"},
              {'imu_topic': "unilidar/imu"}]
  )

  # # Run Rviz
  # package_path = subprocess.check_output(['ros2', 'pkg', 'prefix', 'unitree_lidar_ros2']).decode('utf-8').rstrip()
  # rviz_config_file = os.path.join(package_path, 'share', 'unitree_lidar_ros2', 'view.rviz')
  # print("rviz_config_file = " + rviz_config_file)
  # rviz_node = Node(
  #   package='rviz2',
  #   executable='rviz2',
  #   name='rviz2',
  #   arguments=['-d', rviz_config_file],
  #   output='log'
  # )
  # return LaunchDescription([node1, rviz_node])

  return LaunchDescription([node1])