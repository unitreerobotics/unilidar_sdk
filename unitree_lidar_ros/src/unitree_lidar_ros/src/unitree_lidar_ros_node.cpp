/**********************************************************************
 Copyright (c) 2020-2023, Unitree Robotics.Co.Ltd. All rights reserved.
***********************************************************************/

#include "unitree_lidar_ros.h"

using namespace unitree_lidar_sdk;

int main(int argc, char **argv)
{
  // ROS
  ros::init(argc, argv, "unitree_lidar");
  ros::NodeHandle nh;
  
  UnitreeLidarSDKNode node(nh);
  ros::Rate rate(2000);
  
  while (nh.ok())
  {
    ros::spinOnce();
    node.run();
    rate.sleep();
  }

  return 0;
}