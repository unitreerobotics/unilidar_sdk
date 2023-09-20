# How To Parse Cloud and IMU data from MavLink messages

## MavLink Usage

If you need to directly parse data from the serial port to obtain point cloud and IMU data, you need to parse the serial data byte-by-byte according to the MavLink protocol to obtain a complete message frame.

For specific guidance, you can refer to the official examples provided by MavLink.
- https://mavlink.io/en/getting_started/

## Parsing IMU Data
The format of the IMU MavLink data structure is defined in the following file: 
- `mavlink/SysMavlink/mavlink_msg_ret_imu_attitude_data_packet.h`

The IMU data structure is defined as:
```c
typedef struct __mavlink_ret_imu_attitude_data_packet_t {
 float quaternion[4]; /*<  Quaternion Array.*/
 float angular_velocity[3]; /*<  Three-axis angular velocity values.*/
 float linear_acceleration[3]; /*<  Three-axis acceleration values.*/
 uint16_t packet_id; /*<  Data packet ID.*/
} mavlink_ret_imu_attitude_data_packet_t;
```

Where:
- `quaternion[4]` represents the quaternion of the IMU.
- `angular_velocity[3]` represents the angular velocity of the IMU along the xyz axes.
- `linear_acceleration[3]` represents the linear acceleration of the IMU along the xyz axes.
- `packet_id` is the ID of this frame of the message, which can be used to determine the continuity of message transmission.


## Parsing Cloud Data

The message format definition related to point cloud parsing includes two files: 
- `mavlink_msg_ret_lidar_auxiliary_data_packet.h`
- `mavlink_msg_ret_lidar_distance_data_packet.h`

Among them, 
- the former contains information about the reflectance of a laser beam, 
- while the latter contains information about the range and angle of a laser beam. 
- They are matched with each other based on whether their `packet_id` is equal.

The data structure of auxiliary data is defined as:
```cpp
typedef struct __mavlink_ret_lidar_auxiliary_data_packet_t {
 uint32_t lidar_sync_delay_time; /*<  Delay time of upper computer communication(us).*/
 uint32_t time_stamp_s_step; /*<  LiDAR operational timestamp in seconds.*/
 uint32_t time_stamp_us_step; /*<  LiDAR operational timestamp in microsecond .*/
 uint32_t sys_rotation_period; /*<  LiDAR low-speed motor rotation period in microsecond .*/
 uint32_t com_rotation_period; /*<  LiDAR high-speed motor rotation period in microsecond .*/
 float com_horizontal_angle_start; /*<  The first data in the current data packet is the horizontal angle,Distance data applicable to RET_LIDAR_DISTANCE_DATA_PACKET data packet and reflectivity data of RET_LIDAR_AUXILIARY_DATA_PACKET data packet.*/
 float com_horizontal_angle_step; /*<  Angle interval between two adjacent data in the horizontal direction.*/
 float sys_vertical_angle_start; /*<  The vertical angle of the first data in the current data packet.*/
 float sys_vertical_angle_span; /*<  The angular span between adjacent data in the vertical direction of the current data packet.*/
 float apd_temperature; /*<  APD temperature value*/
 float dirty_index; /*<  Protective cover dirt detection index*/
 float imu_temperature; /*<  IMU temperature value*/
 float up_optical_q; /*<  Up optical communication quality.*/
 float down_optical_q; /*<  Downlink optical communication quality.*/
 float apd_voltage; /*<  APD voltage value.*/
 float imu_angle_x_offset; /*<  IMU x-axis installation angle error.*/
 float imu_angle_y_offset; /*<  IMU y-axis installation angle error.*/
 float imu_angle_z_offset; /*<  IMU z-axis installation angle error.*/
 float b_axis_dist; /*<  Laser calibration b distance compensation.*/
 float theta_angle; /*<  Laser calibration theta angle compensation.*/
 float ksi_angle; /*<  Laser calibration ksi angle compensation.*/
 uint16_t packet_id; /*<  Data packet ID.*/
 uint16_t payload_size; /*<  Data packet payload size.*/
 uint8_t lidar_work_status; /*<  LiDAR operational state indicator.*/
 uint8_t reflect_data[120]; /*<  reflectivity data*/
} mavlink_ret_lidar_auxiliary_data_packet_t;
```

The data structure of distance data is defined as:
```cpp
typedef struct __mavlink_ret_lidar_distance_data_packet_t {
 uint16_t packet_id; /*<  Data packet ID.*/
 uint16_t packet_cnt; /*<  Data packet count.*/
 uint16_t payload_size; /*<  Data packet payload size.*/
 uint8_t point_data[240]; /*<  Data packet distance data.*/
} mavlink_ret_lidar_distance_data_packet_t;
```

Among them, 
- The array, `reflect_data[120]`, stores the reflection intensity of 120 points accordingly.
- The array, `point_data[240]`, stores the distance information of 120 points on a laser beam:
  - Each point's distance is represented in `uint16_t` format and occupies two bytes. 
  - For example, `point_data[0]` and `point_data[1]` represent the distance of the first point, where `point_data[0]` holds the lower byte, and `point_data[1]` holds the higher byte.
  - If the distance of a point equals 0, that point is invalid and should be jumped.

Assuming that we have parsed a frame of `mavlink_ret_lidar_auxiliary_data_packet_t` data and a matching frame of `mavlink_ret_lidar_distance_data_packet_t` message, we can obtain the point cloud's XYZ coordinates by parsing these two frames. Here is a C++ function example for reference:

```c
/**
 * @file parse_range_auxiliary_data_to_cloud.h
 * @date 2023-07-27
 */

#pragma once
#include "mavlink/SysMavlink/mavlink.h"
#include <vector>
#include <array>

/**
 * @brief Parse A Range And An Auxiliary Data To A Point Cloud
 * 
 * @param auxiliaryData 
 * @param rangeData 
 * @param scanCloud Array elements are x, y, z, intensity respectively
 * @return true 
 * @return false 
 */
bool parseRangeAuxiliaryDataToCloud(
  const mavlink_ret_lidar_auxiliary_data_packet_t &auxiliaryData, 
  const mavlink_ret_lidar_distance_data_packet_t &rangeData,
  std::vector<std::array<float, 4>> &scanCloud
  ){
  
  // check packet id match
  if (auxiliaryData.packet_id != rangeData.packet_id){
    return false;
  }

  // parse data
  float rotate_yaw_bias = 0;
  float range_scale = 0.001;
  float z_bias = 0.0445;
  int points_num_of_scan = 120;
  float bias_laser_beam_ = auxiliaryData.b_axis_dist / 1000;

  float sin_theta = sin(auxiliaryData.theta_angle);
  float cos_theta = cos(auxiliaryData.theta_angle);
  float sin_ksi = sin(auxiliaryData.ksi_angle);
  float cos_ksi = cos(auxiliaryData.ksi_angle);

  float pitch_cur = auxiliaryData.sys_vertical_angle_start * M_PI / 180.0;
  float pitch_step = auxiliaryData.sys_vertical_angle_span * M_PI / 180.0;
  float yaw_cur = (auxiliaryData.com_horizontal_angle_start + rotate_yaw_bias) * M_PI / 180.0;
  float yaw_step = auxiliaryData.com_horizontal_angle_step / points_num_of_scan * M_PI / 180.0;

  uint16_t range;
  float range_float;

  std::array<float, 4> point;
  for (int i = 0, j = 0; j < points_num_of_scan; 
        i += 2, j += 1, 
        pitch_cur += pitch_step, yaw_cur += yaw_step)
  {
    // Calculate point range in float type
    range = (rangeData.point_data[i + 1] << 8);
    range = range | rangeData.point_data[i];
    if (range == 0){  
      continue;
    }
    range_float = range_scale * range;

    // Transform this point to XYZ coordinate
    float&& sin_alpha = sin(pitch_cur);
    float&& cos_alpha = cos(pitch_cur);
    float&& sin_beta = sin(yaw_cur);
    float&& cos_beta = cos(yaw_cur);

    float&& A = (-cos_theta * sin_ksi + sin_theta * sin_alpha * cos_ksi) * range_float + bias_laser_beam_;
    float&& B = cos_alpha * cos_ksi * range_float;
  
    point[0] = cos_beta * A - sin_beta * B;     // x
    point[1] = sin_beta * A + cos_beta * B;     // y
    point[2] = (sin_theta * sin_ksi + cos_theta * sin_alpha * cos_ksi) * range_float + z_bias;  // z
    point[3] = auxiliaryData.reflect_data[j];
    scanCloud.push_back(point);
  }

  return true;
}
```