/**********************************************************************
 Copyright (c) 2020-2023, Unitree Robotics.Co.Ltd. All rights reserved.
***********************************************************************/

#pragma once

#if defined(_WIN32) && !defined(__MINGW32__)
  typedef signed char int8_t;
  typedef unsigned char uint8_t;
  typedef short int16_t;  // NOLINT
  typedef unsigned short uint16_t;  // NOLINT
  typedef int int32_t;
  typedef unsigned int uint32_t;
  typedef __int64 int64_t;
  typedef unsigned __int64 uint64_t;
  // intptr_t and friends are defined in crtdefs.h through stdio.h.
#else
  #include <stdint.h>
#endif

#include <iostream>
#include <unistd.h>
#include <deque>
#include <vector>
#include <memory>
#include <math.h>

#include "unitree_lidar_sdk_config.h"

namespace unitree_lidar_sdk{

// const float DEGREE_TO_RADIAN = M_PI / 180.0;
// const float RADIAN_TO_DEGREE = 180.0 / M_PI;

const float PI_UNITEE = 3.14159265358979323846;
const float DEGREE_TO_RADIAN = PI_UNITEE / 180.0;
const float RADIAN_TO_DEGREE = 180.0 / PI_UNITEE;

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
  uint32_t ring;      // ring
}PointUnitree;

/**
 * @brief Cloud Type
 */
typedef struct{
  double stamp;       // cloud timestamp
  uint32_t id;        // sequence id
  uint32_t ringNum;
  std::vector<PointUnitree> points;  
}PointCloudUnitree;

/**
 * @brief Scan Type
 */
typedef struct{
  double stamp;       // cloud timestamp
  uint32_t id;        // sequence id
  uint32_t validPointsNum; // first validPointsNum points are valid
  PointUnitree points[120];  
}ScanUnitree;


/**
 * @brief IMU Type
 */
typedef struct{
  double stamp;                 // imu timestamp
  uint32_t id;             // sequence id
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
  NORMAL=1,   // Configure the LiDAR to operate in normal mode.
  STANDBY=2   // Configure the LiDAR to enter standby mode.
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
   * @return Return 0 if the serial port is opened successfully; 
   * return -1 if we failed to open the serial port.
   */
  virtual int initialize( 
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
   * @brief Initialize for UDP board
   */
  virtual int initializeUDP( 
      uint16_t cloud_scan_num = 18,
      unsigned short lidar_port = 5001,
      std::string lidar_ip = "10.10.10.10",
      unsigned short local_port = 5000, 
      std::string local_ip = "10.10.10.100",
      float rotate_yaw_bias = 0,
      float range_scale = 0.001, 
      float range_bias = 0,
      float range_max = 50,
      float range_min = 0
  ) = 0;

  /**
   * @brief Close UDP connection
   */
  virtual bool closeUDP() = 0;

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