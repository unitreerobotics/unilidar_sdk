/**********************************************************************
 Copyright (c) 2020-2023, Unitree Robotics.Co.Ltd. All rights reserved.
***********************************************************************/

#pragma once

#define BOOST_BIND_NO_PLACEHOLDERS

#include <memory>
#include "iostream"
#include <string>
#include <stdio.h>
#include <iterator>
#include <algorithm>
#include <chrono>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>

#include "sensor_msgs/msg/point_cloud2.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "std_msgs/msg/header.hpp"

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/time.hpp"

#include "unitree_lidar_sdk_pcl.h"

using std::placeholders::_1;

class UnitreeLidarSDKNode : public rclcpp::Node
{
public:

  explicit UnitreeLidarSDKNode(const rclcpp::NodeOptions &options = rclcpp::NodeOptions());

  ~UnitreeLidarSDKNode(){};

  void timer_callback();

protected:

  // ROS
  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pub_cloud_;
  rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr pub_imu_;
  rclcpp::TimerBase::SharedPtr timer_;

  // Unitree Lidar Reader
  UnitreeLidarReader* lsdk_;

  // Config params
  std::string port_; 

  double rotate_yaw_bias_;
  double range_scale_;
  double range_bias_;
  double range_max_;
  double range_min_;

  std::string cloud_frame_;
  std::string cloud_topic_;
  int cloud_scan_num_;

  std::string imu_frame_;
  std::string imu_topic_;
};

///////////////////////////////////////////////////////////////////

UnitreeLidarSDKNode::UnitreeLidarSDKNode(const rclcpp::NodeOptions& options) 
  : Node("unitre_lidar_sdk_node", options) 
{      
  // load config parameters
  declare_parameter<std::string>("port", "/dev/ttyUSB0");
  
  declare_parameter<double>("rotate_yaw_bias", 0);
  declare_parameter<double>("range_scale", 0.001);
  declare_parameter<double>("range_bias", 0);
  declare_parameter<double>("range_max", 50);
  declare_parameter<double>("range_min", 0);

  declare_parameter<std::string>("cloud_frame", "unilidar_lidar");
  declare_parameter<std::string>("cloud_topic", "unilidar/cloud");
  declare_parameter<int>("cloud_scan_num", 18);
  
  declare_parameter<std::string>("imu_frame", "unilidar_imu");
  declare_parameter<std::string>("imu_topic", "unilidar/imu");
  

  port_ = get_parameter("port").as_string();

  rotate_yaw_bias_ = get_parameter("rotate_yaw_bias").as_double();
  range_scale_ = get_parameter("range_scale").as_double();
  range_bias_ = get_parameter("range_bias").as_double();
  range_max_ = get_parameter("range_max").as_double();
  range_min_ = get_parameter("range_min").as_double();
  
  cloud_frame_ = get_parameter("cloud_frame").as_string();
  cloud_topic_ = get_parameter("cloud_topic").as_string();
  cloud_scan_num_ = get_parameter("cloud_scan_num").as_int();
  
  imu_frame_ = get_parameter("imu_frame").as_string();
  imu_topic_ = get_parameter("imu_topic").as_string();

  // std::cout << "port_ = " << port_ 
  //           << ", cloud_topic_ = " << cloud_topic_
  //           << ", cloud_scan_num_ = " << cloud_scan_num_
  //           << std::endl;

  // Initialize UnitreeLidarReader
  lsdk_ = createUnitreeLidarReader();
  lsdk_->initialize(cloud_scan_num_, port_, 2000000, rotate_yaw_bias_, 
        range_scale_, range_bias_, range_max_, range_min_);

  // ROS2
  pub_cloud_ = this->create_publisher<sensor_msgs::msg::PointCloud2>(cloud_topic_, 10);
  pub_imu_ = this->create_publisher<sensor_msgs::msg::Imu>(imu_topic_, 10);
  timer_ = this->create_wall_timer(std::chrono::milliseconds(1), std::bind(&UnitreeLidarSDKNode::timer_callback, this));
}

void UnitreeLidarSDKNode::timer_callback()
{
  MessageType result = lsdk_->runParse();
  static pcl::PointCloud<PointType>::Ptr cloudOut(new pcl::PointCloud<PointType>());

  // RCLCPP_INFO(this->get_logger(), "result = %d", result);

  if (result == IMU)
  {
    auto &imu = lsdk_->getIMU();

    rclcpp::Time timestamp(
        static_cast<int32_t>(imu.stamp),
        static_cast<uint32_t>((imu.stamp - static_cast<int32_t>(imu.stamp) ) * 1e9));

    sensor_msgs::msg::Imu imuMsg;
    imuMsg.header.frame_id = imu_frame_;
    imuMsg.header.stamp = timestamp;

    imuMsg.orientation.x = imu.quaternion[0];
    imuMsg.orientation.y = imu.quaternion[1];
    imuMsg.orientation.z = imu.quaternion[2];
    imuMsg.orientation.w = imu.quaternion[3];

    imuMsg.angular_velocity.x = imu.angular_velocity[0];
    imuMsg.angular_velocity.y = imu.angular_velocity[1];
    imuMsg.angular_velocity.z = imu.angular_velocity[2];

    imuMsg.linear_acceleration.x = imu.linear_acceleration[0];
    imuMsg.linear_acceleration.y = imu.linear_acceleration[1];
    imuMsg.linear_acceleration.z = imu.linear_acceleration[2];

    pub_imu_->publish(imuMsg);
  }
  else if (result == POINTCLOUD)
  {
    // RCLCPP_INFO(this->get_logger(), "POINTCLOUD");
    auto &cloud = lsdk_->getCloud();
    transformUnitreeCloudToPCL(cloud, cloudOut);

    rclcpp::Time timestamp(
        static_cast<int32_t>(cloud.stamp),
        static_cast<uint32_t>((cloud.stamp - static_cast<int32_t>(cloud.stamp) ) * 1e9));

    sensor_msgs::msg::PointCloud2 cloud_msg;
    pcl::toROSMsg(*cloudOut, cloud_msg);
    cloud_msg.header.frame_id = cloud_frame_;
    cloud_msg.header.stamp = timestamp;

    pub_cloud_->publish(cloud_msg);
  }
}