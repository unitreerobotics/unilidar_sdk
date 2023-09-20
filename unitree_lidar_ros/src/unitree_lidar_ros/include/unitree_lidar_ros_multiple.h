/**********************************************************************
 Copyright (c) 2020-2023, Unitree Robotics.Co.Ltd. All rights reserved.
***********************************************************************/

#pragma once

// ROS
#include <ros/ros.h>
#include <ros/package.h>
#include <std_msgs/Header.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Float32MultiArray.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/NavSatFix.h>
#include <nav_msgs/Odometry.h>
#include <nav_msgs/Path.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <tf/LinearMath/Quaternion.h>
#include <tf/transform_listener.h>
#include <tf/transform_datatypes.h>
#include <tf/transform_broadcaster.h>

// PCL
#include <pcl_conversions/pcl_conversions.h>

// Eigen
#include <Eigen/Core>
#include <Eigen/Geometry>

#include "unitree_lidar_sdk_pcl.h"

/**
 * @brief Publish a pointcloud
 * 
 * @param thisPub 
 * @param thisCloud 
 * @param thisStamp 
 * @param thisFrame 
 * @return sensor_msgs::PointCloud2 
 */
inline sensor_msgs::PointCloud2 publishCloud(
  ros::Publisher *thisPub, 
  pcl::PointCloud<PointType>::Ptr thisCloud, 
  ros::Time thisStamp, 
  std::string thisFrame)
{
  sensor_msgs::PointCloud2 tempCloud;
  pcl::toROSMsg(*thisCloud, tempCloud);
  tempCloud.header.stamp = thisStamp;
  tempCloud.header.frame_id = thisFrame;
  if (thisPub->getNumSubscribers() != 0)
    thisPub->publish(tempCloud);
  return tempCloud;
}

/**
 * @brief Unitree Lidar SDK Node
 */
class UnitreeLidarSDKNodeMultiple{
protected:

  // ROS
  ros::NodeHandle nh_;
  ros::Publisher pub_pointcloud_raw_;
  ros::Publisher pub_imu_;
  tf::TransformBroadcaster tfbc1_;

  // Unitree Lidar Reader
  UnitreeLidarReader* lsdk_;
  UnitreeLidarReader* lsdk2_;

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

  int initialize_type_;
  int local_port_;
  std::string local_ip_;
  int lidar_port_;
  std::string lidar_ip_;

public:

  UnitreeLidarSDKNodeMultiple(ros::NodeHandle nh){
    
    // Load config parameters
    nh.param("/unitree_lidar_ros_node/initialize_type", initialize_type_, 1);

    nh.param("/unitree_lidar_ros_node/port", port_, std::string("/dev/ttyUSB0"));
    
    nh.param("/unitree_lidar_ros_node/lidar_port", lidar_port_, 6101);
    nh.param("/unitree_lidar_ros_node/lidar_ip", lidar_ip_, std::string("10.10.10.10"));

    nh.param("/unitree_lidar_ros_node/local_port", local_port_, 6201);
    nh.param("/unitree_lidar_ros_node/local_ip", local_ip_, std::string("10.10.10.100"));

    nh.param("/unitree_lidar_ros_node/rotate_yaw_bias", rotate_yaw_bias_, 0.0);
    nh.param("/unitree_lidar_ros_node/range_scale", range_scale_, 0.001);
    nh.param("/unitree_lidar_ros_node/range_bias", range_bias_, 0.0);
    nh.param("/unitree_lidar_ros_node/range_max", range_max_, 50.0);
    nh.param("/unitree_lidar_ros_node/range_min", range_min_, 0.0);
    
    nh.param("/unitree_lidar_ros_node/cloud_frame", cloud_frame_, std::string("unilidar_lidar"));
    nh.param("/unitree_lidar_ros_node/cloud_topic", cloud_topic_, std::string("unilidar/cloud"));
    nh.param("/unitree_lidar_ros_node/cloud_scan_num", cloud_scan_num_, 18);
    nh.param("/unitree_lidar_ros_node/imu_frame", imu_frame_, std::string("unilidar_imu"));
    nh.param("/unitree_lidar_ros_node/imu_topic", imu_topic_, std::string("unilidar/imu"));

    // Initialize UnitreeLidarReader
    lsdk_ = createUnitreeLidarReader();
    lsdk2_ = createUnitreeLidarReader();

    if (initialize_type_ == 1){
      lsdk_->initialize(cloud_scan_num_, port_, 2000000, rotate_yaw_bias_, 
        range_scale_, range_bias_, range_max_, range_min_);
    }
    else if (initialize_type_ == 2){
      lsdk_->initializeUDP(cloud_scan_num_, lidar_port_, lidar_ip_, local_port_, local_ip_, 
        rotate_yaw_bias_, range_scale_, range_bias_, range_max_, range_min_);
      lsdk2_->initializeUDP(cloud_scan_num_, lidar_port_+1, lidar_ip_, local_port_+1, local_ip_, 
        rotate_yaw_bias_, range_scale_, range_bias_, range_max_, range_min_);
    }

    lsdk_->setLidarWorkingMode(NORMAL);
    sleep(1);
    lsdk2_->setLidarWorkingMode(NORMAL);
    sleep(1);

    // ROS
    nh_ = nh;
    pub_pointcloud_raw_ = nh.advertise<sensor_msgs::PointCloud2> (cloud_topic_, 100);
    pub_imu_ = nh.advertise<sensor_msgs::Imu> (imu_topic_, 1000);
  }

  ~UnitreeLidarSDKNodeMultiple(){
  }

  /**
   * @brief Run once
   */
  bool run(){
    MessageType result = lsdk_->runParse();
     pcl::PointCloud<PointType>::Ptr cloudOut( new pcl::PointCloud<PointType>() );

    if (result == IMU){
      auto & imu = lsdk_->getIMU();
      sensor_msgs::Imu imuMsg;
      imuMsg.header.frame_id = imu_frame_;
      imuMsg.header.stamp = ros::Time::now().fromSec(imu.stamp);

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

      pub_imu_.publish(imuMsg);
  
      return true;
    }
    else if (result == POINTCLOUD){
      auto &cloud = lsdk_->getCloud();
      transformUnitreeCloudToPCL(cloud, cloudOut);
      publishCloud(&pub_pointcloud_raw_, cloudOut, ros::Time::now().fromSec(cloud.stamp), cloud_frame_);
      
      return true;
    }else{
      return false;
    }

  }

  bool run2(){
    MessageType result = lsdk2_->runParse();
    pcl::PointCloud<PointType>::Ptr cloudOut( new pcl::PointCloud<PointType>() );

    if (result == IMU){
      auto & imu = lsdk2_->getIMU();
      sensor_msgs::Imu imuMsg;
      imuMsg.header.frame_id = imu_frame_;
      imuMsg.header.stamp = ros::Time::now().fromSec(imu.stamp);

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

      pub_imu_.publish(imuMsg);
  
      return true;
    }
    else if (result == POINTCLOUD){
      auto &cloud = lsdk2_->getCloud();
      transformUnitreeCloudToPCL(cloud, cloudOut);
      publishCloud(&pub_pointcloud_raw_, cloudOut, ros::Time::now().fromSec(cloud.stamp), cloud_frame_);
      
      return true;
    }else{
      return false;
    }

  }
  
};