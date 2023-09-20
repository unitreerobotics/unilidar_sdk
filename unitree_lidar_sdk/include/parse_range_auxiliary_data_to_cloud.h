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