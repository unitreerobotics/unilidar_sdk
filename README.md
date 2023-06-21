# Unilidar SDK

## Introduction
This repository is a SDK for [Unitree L1 LiDAR](https://www.unitree.com/LiDAR).

You can use the code interfaces in this repository to obtain point cloud data and IMU data measured in our lidar, as well as configure related parameters. 

We provide three commonly used interfaces for our LiDAR:
- if you prefer to use the original **C++ SDK** directly, you can refer to [README.md](./unitree_lidar_sdk/README.md); 
- if you want to use **ROS**, you can refer to [README.md](./unitree_lidar_ros/src/unitree_lidar_ros/README.md); 
- if you are developing with the latest **ROS2**, you can refer to [README.md](./unitree_lidar_ros2/src/unitree_lidar_ros2/README.md).


## Coordinate System Definition
The reference frame definition is illustrated in the following figure, which satisfies the right-hand coordinate system definition. 

The origin of the lidar frame, which is used to represent coordinates of each point in a pointcloud, is located at the center of the bottom mounting surface of the lidar. 
- Its +X axis is in the opposite direction of the outgoing cable. 
- Its +Y axis is in the the direction obtained by rotating the +X axis counterclockwise by 90 degrees. 
- And its +Z axis is vertically upward. 

The IMU frame's axes are aligned and parallel to the directions of the point cloud coordinate system. The XYZ coordinates of its origin in the lidar frame is [-0.007698, -0.014655, 0.00667] in meters.

You can also go to our [official website](https://www.unitree.com/download) for further technical details of our lidar.

<div style="text-align:center">
  <img src="./docs/lidar_frame_definition.jpg" width="800">
</div>