/**********************************************************************
 Copyright (c) 2020-2023, Unitree Robotics.Co.Ltd. All rights reserved.
***********************************************************************/

#pragma once

#include <iostream>
#include <unistd.h>
#include <deque>
#include <vector>
#include <memory>
#include <math.h>

namespace unitree_lidar_sdk{

const float DEGREE_TO_RADIAN = M_PI / 180.0;
const float RADIAN_TO_DEGREE = 180.0 / M_PI;

/**
 * @brief Get the system timestamp in seconds.
 */
double get_system_timestamp();

/**
 * @brief Point Type
 */
typedef struct 
{
  float x;
  float y;
  float z;
  float intensity;
  float time;         // relative time of this point from cloud stamp
  std::uint16_t ring; // ring
}PointUnitree;

/**
 * @brief Cloud Type
 */
typedef struct{
  double stamp;       // cloud timestamp
  std::uint16_t id;   // sequence id
  std::uint16_t ringNum;
  std::vector<PointUnitree> points;  
}PointCloudUnitree;

/**
 * @brief IMU Type
 */
typedef struct{
  double stamp;                 // imu timestamp
  std::uint16_t id;             // sequence id
  float quaternion[4];          // quaternion: [x,y,z,w]
  float angular_velocity[3];    // three-axis angular velocity values.
  float linear_acceleration[3]; // three-axis acceleration values.
}IMUUnitree;

/**
 * @brief Returned message type after one parse
 */
enum MessageType{
  NONE = 0,         // No valid message
  IMU = 1,          // An IMU message
  POINTCLOUD = 2,   // A cached PointCloud message
  RANGE = 3,        // A Range message
  AUXILIARY = 4,    // An Auxiliary message
  VERSION = 5,      // A Version info
  TIMESYNC = 6      // A time sync info
};

/**
 * @brief Lidar Woking Mode
 */
enum LidarWorkingMode
{
  NORMAL=1,   /* Configure the LiDAR to operate in normal mode. | */
  STANDBY=2  /* Configure the LiDAR to enter standby mode. | */
};

/**
 * @brief LED display mode
 */
enum LEDDisplayMode
{
  FORWARD_SLOW=2,       /* Function mode forward at slow. | */
  FORWARD_FAST=3,       /* Function mode forward at fast. | */
  REVERSE_SLOW=4,       /* Function mode reverse at slow. | */
  REVERSE_FAST=5,       /* Function mode reverse at fast. | */
  TRIPLE_FLIP=6,        /* Function mode triple flip. | */
  TRIPLE_BREATHING=7,   /* Function mode triple breathing. | */
  SIXSTAGE_BREATHING=8  /* Function mode six-stage breathing. | */
};

/**
 * @brief Unitree Lidar Reader
 */
class UnitreeLidarReader{

public:

  /**
   * @brief Initialize 
   */
  virtual void initialize( 
      uint16_t cloud_scan_num = 18,
      std::string port = "/dev/ttyUSB0", 
      uint32_t baudrate = 2000000,
      float rotate_yaw_bias = 0,
      float range_scale = 0.001, 
      float range_bias = 0,
      float range_max = 50,
      float range_min = 0
  ) = 0;

  /**
   * @brief Try to parse a message from the serial buffer once.
   * @note This is the main entrance of this class
   * @return 
   *  NONE if no valid message parsed.
   *  IMU if a new imu message is parsed.
   *  POINTCLOUD if a new cloud is cached.
   */
  virtual MessageType runParse() = 0;

  /**
   * @brief Reset lidar
   */
  virtual void reset() = 0;

  /**
   * @brief Get point cloud data
   */
  virtual const PointCloudUnitree& getCloud() const = 0;

  /**
   * @brief Get IMU data
   */
  virtual const IMUUnitree& getIMU() const = 0;

  /**
   * @brief Get Version of lidar firmware
   */
  virtual std::string getVersionOfFirmware() const = 0;

  /**
   * @brief Get the Version of Lidar SDK 
   */
  virtual std::string getVersionOfSDK() const = 0;
  
  /**
   * @brief Get time delay of one-way data transmission in us.
   */
  virtual uint32_t getTimeDelay() const = 0;

  /**
   * @brief Get the removal percentage of points due to the dirt on the protection cover
   * @return the percentage of removed dirty points
   */
  virtual float getDirtyPercentage() const = 0;

  /**
   * @brief Set the Lidar Working Mode
   * @param mode 
   */
  virtual void setLidarWorkingMode(LidarWorkingMode mode) = 0;

  /**
   * @brief Set LED display mode with each LED light on/off
   * @param led_table 45 bytes represent the status of 360 LEDs bit by bit
   */
  virtual void setLEDDisplayMode(uint8_t led_table[45]) = 0;

  /**
   * @brief Ser LEF display mode with default pattern
   * @param mode 
   *  LED_RING_FUN_FORWARD_SLOW_MODE=2,  Function mode forward at slow.
   *  LED_RING_FUN_FORWARD_FAST_MODE=3,  Function mode forward at fast. 
   *  LED_RING_FUN_REVERSE_SLOW_MODE=4,  Function mode reverse at slow.
   *  LED_RING_FUN_REVERSE_FAST_MODE=5,  Function mode reverse at fast. 
   *  LED_RING_FUN_TRIPLE_FLIP_MODE=6,   Function mode triple flip.
   *  LED_RING_FUN_TRIPLE_BREATHING_MODE=7,  Function mode triple breathing.
   *  LED_RING_FUN_SIXSTAGE_BREATHING_MODE=8, Function mode six-stage breathing.
   */
  virtual void setLEDDisplayMode(LEDDisplayMode mode) = 0;

  /**
   * @brief Print configuration parameters
   */
  virtual void printConfig() = 0;
};


/**
 * @brief Create a Unitree Lidar Reader object
 * @return UnitreeLidarReader* 
 */
UnitreeLidarReader* createUnitreeLidarReader();

} // end of namespace unitree_lidar_sdk