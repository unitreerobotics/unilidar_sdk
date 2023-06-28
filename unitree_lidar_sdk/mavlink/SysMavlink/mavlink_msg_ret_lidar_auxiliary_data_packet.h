#pragma once
// MESSAGE RET_LIDAR_AUXILIARY_DATA_PACKET PACKING

#define MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET 17


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

#define MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_LEN 209
#define MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_MIN_LEN 209
#define MAVLINK_MSG_ID_17_LEN 209
#define MAVLINK_MSG_ID_17_MIN_LEN 209

#define MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_CRC 99
#define MAVLINK_MSG_ID_17_CRC 99

#define MAVLINK_MSG_RET_LIDAR_AUXILIARY_DATA_PACKET_FIELD_REFLECT_DATA_LEN 120

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RET_LIDAR_AUXILIARY_DATA_PACKET { \
    17, \
    "RET_LIDAR_AUXILIARY_DATA_PACKET", \
    25, \
    {  { "lidar_work_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 88, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, lidar_work_status) }, \
         { "packet_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 84, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, packet_id) }, \
         { "payload_size", NULL, MAVLINK_TYPE_UINT16_T, 0, 86, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, payload_size) }, \
         { "lidar_sync_delay_time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, lidar_sync_delay_time) }, \
         { "time_stamp_s_step", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, time_stamp_s_step) }, \
         { "time_stamp_us_step", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, time_stamp_us_step) }, \
         { "sys_rotation_period", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, sys_rotation_period) }, \
         { "com_rotation_period", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, com_rotation_period) }, \
         { "com_horizontal_angle_start", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, com_horizontal_angle_start) }, \
         { "com_horizontal_angle_step", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, com_horizontal_angle_step) }, \
         { "sys_vertical_angle_start", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, sys_vertical_angle_start) }, \
         { "sys_vertical_angle_span", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, sys_vertical_angle_span) }, \
         { "apd_temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, apd_temperature) }, \
         { "dirty_index", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, dirty_index) }, \
         { "imu_temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, imu_temperature) }, \
         { "up_optical_q", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, up_optical_q) }, \
         { "down_optical_q", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, down_optical_q) }, \
         { "apd_voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, apd_voltage) }, \
         { "imu_angle_x_offset", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, imu_angle_x_offset) }, \
         { "imu_angle_y_offset", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, imu_angle_y_offset) }, \
         { "imu_angle_z_offset", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, imu_angle_z_offset) }, \
         { "b_axis_dist", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, b_axis_dist) }, \
         { "theta_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, theta_angle) }, \
         { "ksi_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, ksi_angle) }, \
         { "reflect_data", NULL, MAVLINK_TYPE_UINT8_T, 120, 89, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, reflect_data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RET_LIDAR_AUXILIARY_DATA_PACKET { \
    "RET_LIDAR_AUXILIARY_DATA_PACKET", \
    25, \
    {  { "lidar_work_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 88, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, lidar_work_status) }, \
         { "packet_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 84, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, packet_id) }, \
         { "payload_size", NULL, MAVLINK_TYPE_UINT16_T, 0, 86, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, payload_size) }, \
         { "lidar_sync_delay_time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, lidar_sync_delay_time) }, \
         { "time_stamp_s_step", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, time_stamp_s_step) }, \
         { "time_stamp_us_step", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, time_stamp_us_step) }, \
         { "sys_rotation_period", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, sys_rotation_period) }, \
         { "com_rotation_period", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, com_rotation_period) }, \
         { "com_horizontal_angle_start", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, com_horizontal_angle_start) }, \
         { "com_horizontal_angle_step", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, com_horizontal_angle_step) }, \
         { "sys_vertical_angle_start", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, sys_vertical_angle_start) }, \
         { "sys_vertical_angle_span", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, sys_vertical_angle_span) }, \
         { "apd_temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, apd_temperature) }, \
         { "dirty_index", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, dirty_index) }, \
         { "imu_temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, imu_temperature) }, \
         { "up_optical_q", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, up_optical_q) }, \
         { "down_optical_q", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, down_optical_q) }, \
         { "apd_voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, apd_voltage) }, \
         { "imu_angle_x_offset", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, imu_angle_x_offset) }, \
         { "imu_angle_y_offset", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, imu_angle_y_offset) }, \
         { "imu_angle_z_offset", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, imu_angle_z_offset) }, \
         { "b_axis_dist", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, b_axis_dist) }, \
         { "theta_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, theta_angle) }, \
         { "ksi_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, ksi_angle) }, \
         { "reflect_data", NULL, MAVLINK_TYPE_UINT8_T, 120, 89, offsetof(mavlink_ret_lidar_auxiliary_data_packet_t, reflect_data) }, \
         } \
}
#endif

/**
 * @brief Pack a ret_lidar_auxiliary_data_packet message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param lidar_work_status  LiDAR operational state indicator.
 * @param packet_id  Data packet ID.
 * @param payload_size  Data packet payload size.
 * @param lidar_sync_delay_time  Delay time of upper computer communication(us).
 * @param time_stamp_s_step  LiDAR operational timestamp in seconds.
 * @param time_stamp_us_step  LiDAR operational timestamp in microsecond .
 * @param sys_rotation_period  LiDAR low-speed motor rotation period in microsecond .
 * @param com_rotation_period  LiDAR high-speed motor rotation period in microsecond .
 * @param com_horizontal_angle_start  The first data in the current data packet is the horizontal angle,Distance data applicable to RET_LIDAR_DISTANCE_DATA_PACKET data packet and reflectivity data of RET_LIDAR_AUXILIARY_DATA_PACKET data packet.
 * @param com_horizontal_angle_step  Angle interval between two adjacent data in the horizontal direction.
 * @param sys_vertical_angle_start  The vertical angle of the first data in the current data packet.
 * @param sys_vertical_angle_span  The angular span between adjacent data in the vertical direction of the current data packet.
 * @param apd_temperature  APD temperature value
 * @param dirty_index  Protective cover dirt detection index
 * @param imu_temperature  IMU temperature value
 * @param up_optical_q  Up optical communication quality.
 * @param down_optical_q  Downlink optical communication quality.
 * @param apd_voltage  APD voltage value.
 * @param imu_angle_x_offset  IMU x-axis installation angle error.
 * @param imu_angle_y_offset  IMU y-axis installation angle error.
 * @param imu_angle_z_offset  IMU z-axis installation angle error.
 * @param b_axis_dist  Laser calibration b distance compensation.
 * @param theta_angle  Laser calibration theta angle compensation.
 * @param ksi_angle  Laser calibration ksi angle compensation.
 * @param reflect_data  reflectivity data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ret_lidar_auxiliary_data_packet_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t lidar_work_status, uint16_t packet_id, uint16_t payload_size, uint32_t lidar_sync_delay_time, uint32_t time_stamp_s_step, uint32_t time_stamp_us_step, uint32_t sys_rotation_period, uint32_t com_rotation_period, float com_horizontal_angle_start, float com_horizontal_angle_step, float sys_vertical_angle_start, float sys_vertical_angle_span, float apd_temperature, float dirty_index, float imu_temperature, float up_optical_q, float down_optical_q, float apd_voltage, float imu_angle_x_offset, float imu_angle_y_offset, float imu_angle_z_offset, float b_axis_dist, float theta_angle, float ksi_angle, const uint8_t *reflect_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_LEN];
    _mav_put_uint32_t(buf, 0, lidar_sync_delay_time);
    _mav_put_uint32_t(buf, 4, time_stamp_s_step);
    _mav_put_uint32_t(buf, 8, time_stamp_us_step);
    _mav_put_uint32_t(buf, 12, sys_rotation_period);
    _mav_put_uint32_t(buf, 16, com_rotation_period);
    _mav_put_float(buf, 20, com_horizontal_angle_start);
    _mav_put_float(buf, 24, com_horizontal_angle_step);
    _mav_put_float(buf, 28, sys_vertical_angle_start);
    _mav_put_float(buf, 32, sys_vertical_angle_span);
    _mav_put_float(buf, 36, apd_temperature);
    _mav_put_float(buf, 40, dirty_index);
    _mav_put_float(buf, 44, imu_temperature);
    _mav_put_float(buf, 48, up_optical_q);
    _mav_put_float(buf, 52, down_optical_q);
    _mav_put_float(buf, 56, apd_voltage);
    _mav_put_float(buf, 60, imu_angle_x_offset);
    _mav_put_float(buf, 64, imu_angle_y_offset);
    _mav_put_float(buf, 68, imu_angle_z_offset);
    _mav_put_float(buf, 72, b_axis_dist);
    _mav_put_float(buf, 76, theta_angle);
    _mav_put_float(buf, 80, ksi_angle);
    _mav_put_uint16_t(buf, 84, packet_id);
    _mav_put_uint16_t(buf, 86, payload_size);
    _mav_put_uint8_t(buf, 88, lidar_work_status);
    _mav_put_uint8_t_array(buf, 89, reflect_data, 120);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_LEN);
#else
    mavlink_ret_lidar_auxiliary_data_packet_t packet;
    packet.lidar_sync_delay_time = lidar_sync_delay_time;
    packet.time_stamp_s_step = time_stamp_s_step;
    packet.time_stamp_us_step = time_stamp_us_step;
    packet.sys_rotation_period = sys_rotation_period;
    packet.com_rotation_period = com_rotation_period;
    packet.com_horizontal_angle_start = com_horizontal_angle_start;
    packet.com_horizontal_angle_step = com_horizontal_angle_step;
    packet.sys_vertical_angle_start = sys_vertical_angle_start;
    packet.sys_vertical_angle_span = sys_vertical_angle_span;
    packet.apd_temperature = apd_temperature;
    packet.dirty_index = dirty_index;
    packet.imu_temperature = imu_temperature;
    packet.up_optical_q = up_optical_q;
    packet.down_optical_q = down_optical_q;
    packet.apd_voltage = apd_voltage;
    packet.imu_angle_x_offset = imu_angle_x_offset;
    packet.imu_angle_y_offset = imu_angle_y_offset;
    packet.imu_angle_z_offset = imu_angle_z_offset;
    packet.b_axis_dist = b_axis_dist;
    packet.theta_angle = theta_angle;
    packet.ksi_angle = ksi_angle;
    packet.packet_id = packet_id;
    packet.payload_size = payload_size;
    packet.lidar_work_status = lidar_work_status;
    mav_array_memcpy(packet.reflect_data, reflect_data, sizeof(uint8_t)*120);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_CRC);
}

/**
 * @brief Pack a ret_lidar_auxiliary_data_packet message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lidar_work_status  LiDAR operational state indicator.
 * @param packet_id  Data packet ID.
 * @param payload_size  Data packet payload size.
 * @param lidar_sync_delay_time  Delay time of upper computer communication(us).
 * @param time_stamp_s_step  LiDAR operational timestamp in seconds.
 * @param time_stamp_us_step  LiDAR operational timestamp in microsecond .
 * @param sys_rotation_period  LiDAR low-speed motor rotation period in microsecond .
 * @param com_rotation_period  LiDAR high-speed motor rotation period in microsecond .
 * @param com_horizontal_angle_start  The first data in the current data packet is the horizontal angle,Distance data applicable to RET_LIDAR_DISTANCE_DATA_PACKET data packet and reflectivity data of RET_LIDAR_AUXILIARY_DATA_PACKET data packet.
 * @param com_horizontal_angle_step  Angle interval between two adjacent data in the horizontal direction.
 * @param sys_vertical_angle_start  The vertical angle of the first data in the current data packet.
 * @param sys_vertical_angle_span  The angular span between adjacent data in the vertical direction of the current data packet.
 * @param apd_temperature  APD temperature value
 * @param dirty_index  Protective cover dirt detection index
 * @param imu_temperature  IMU temperature value
 * @param up_optical_q  Up optical communication quality.
 * @param down_optical_q  Downlink optical communication quality.
 * @param apd_voltage  APD voltage value.
 * @param imu_angle_x_offset  IMU x-axis installation angle error.
 * @param imu_angle_y_offset  IMU y-axis installation angle error.
 * @param imu_angle_z_offset  IMU z-axis installation angle error.
 * @param b_axis_dist  Laser calibration b distance compensation.
 * @param theta_angle  Laser calibration theta angle compensation.
 * @param ksi_angle  Laser calibration ksi angle compensation.
 * @param reflect_data  reflectivity data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ret_lidar_auxiliary_data_packet_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t lidar_work_status,uint16_t packet_id,uint16_t payload_size,uint32_t lidar_sync_delay_time,uint32_t time_stamp_s_step,uint32_t time_stamp_us_step,uint32_t sys_rotation_period,uint32_t com_rotation_period,float com_horizontal_angle_start,float com_horizontal_angle_step,float sys_vertical_angle_start,float sys_vertical_angle_span,float apd_temperature,float dirty_index,float imu_temperature,float up_optical_q,float down_optical_q,float apd_voltage,float imu_angle_x_offset,float imu_angle_y_offset,float imu_angle_z_offset,float b_axis_dist,float theta_angle,float ksi_angle,const uint8_t *reflect_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_LEN];
    _mav_put_uint32_t(buf, 0, lidar_sync_delay_time);
    _mav_put_uint32_t(buf, 4, time_stamp_s_step);
    _mav_put_uint32_t(buf, 8, time_stamp_us_step);
    _mav_put_uint32_t(buf, 12, sys_rotation_period);
    _mav_put_uint32_t(buf, 16, com_rotation_period);
    _mav_put_float(buf, 20, com_horizontal_angle_start);
    _mav_put_float(buf, 24, com_horizontal_angle_step);
    _mav_put_float(buf, 28, sys_vertical_angle_start);
    _mav_put_float(buf, 32, sys_vertical_angle_span);
    _mav_put_float(buf, 36, apd_temperature);
    _mav_put_float(buf, 40, dirty_index);
    _mav_put_float(buf, 44, imu_temperature);
    _mav_put_float(buf, 48, up_optical_q);
    _mav_put_float(buf, 52, down_optical_q);
    _mav_put_float(buf, 56, apd_voltage);
    _mav_put_float(buf, 60, imu_angle_x_offset);
    _mav_put_float(buf, 64, imu_angle_y_offset);
    _mav_put_float(buf, 68, imu_angle_z_offset);
    _mav_put_float(buf, 72, b_axis_dist);
    _mav_put_float(buf, 76, theta_angle);
    _mav_put_float(buf, 80, ksi_angle);
    _mav_put_uint16_t(buf, 84, packet_id);
    _mav_put_uint16_t(buf, 86, payload_size);
    _mav_put_uint8_t(buf, 88, lidar_work_status);
    _mav_put_uint8_t_array(buf, 89, reflect_data, 120);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_LEN);
#else
    mavlink_ret_lidar_auxiliary_data_packet_t packet;
    packet.lidar_sync_delay_time = lidar_sync_delay_time;
    packet.time_stamp_s_step = time_stamp_s_step;
    packet.time_stamp_us_step = time_stamp_us_step;
    packet.sys_rotation_period = sys_rotation_period;
    packet.com_rotation_period = com_rotation_period;
    packet.com_horizontal_angle_start = com_horizontal_angle_start;
    packet.com_horizontal_angle_step = com_horizontal_angle_step;
    packet.sys_vertical_angle_start = sys_vertical_angle_start;
    packet.sys_vertical_angle_span = sys_vertical_angle_span;
    packet.apd_temperature = apd_temperature;
    packet.dirty_index = dirty_index;
    packet.imu_temperature = imu_temperature;
    packet.up_optical_q = up_optical_q;
    packet.down_optical_q = down_optical_q;
    packet.apd_voltage = apd_voltage;
    packet.imu_angle_x_offset = imu_angle_x_offset;
    packet.imu_angle_y_offset = imu_angle_y_offset;
    packet.imu_angle_z_offset = imu_angle_z_offset;
    packet.b_axis_dist = b_axis_dist;
    packet.theta_angle = theta_angle;
    packet.ksi_angle = ksi_angle;
    packet.packet_id = packet_id;
    packet.payload_size = payload_size;
    packet.lidar_work_status = lidar_work_status;
    mav_array_memcpy(packet.reflect_data, reflect_data, sizeof(uint8_t)*120);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_CRC);
}

/**
 * @brief Encode a ret_lidar_auxiliary_data_packet struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ret_lidar_auxiliary_data_packet C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ret_lidar_auxiliary_data_packet_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ret_lidar_auxiliary_data_packet_t* ret_lidar_auxiliary_data_packet)
{
    return mavlink_msg_ret_lidar_auxiliary_data_packet_pack(system_id, component_id, msg, ret_lidar_auxiliary_data_packet->lidar_work_status, ret_lidar_auxiliary_data_packet->packet_id, ret_lidar_auxiliary_data_packet->payload_size, ret_lidar_auxiliary_data_packet->lidar_sync_delay_time, ret_lidar_auxiliary_data_packet->time_stamp_s_step, ret_lidar_auxiliary_data_packet->time_stamp_us_step, ret_lidar_auxiliary_data_packet->sys_rotation_period, ret_lidar_auxiliary_data_packet->com_rotation_period, ret_lidar_auxiliary_data_packet->com_horizontal_angle_start, ret_lidar_auxiliary_data_packet->com_horizontal_angle_step, ret_lidar_auxiliary_data_packet->sys_vertical_angle_start, ret_lidar_auxiliary_data_packet->sys_vertical_angle_span, ret_lidar_auxiliary_data_packet->apd_temperature, ret_lidar_auxiliary_data_packet->dirty_index, ret_lidar_auxiliary_data_packet->imu_temperature, ret_lidar_auxiliary_data_packet->up_optical_q, ret_lidar_auxiliary_data_packet->down_optical_q, ret_lidar_auxiliary_data_packet->apd_voltage, ret_lidar_auxiliary_data_packet->imu_angle_x_offset, ret_lidar_auxiliary_data_packet->imu_angle_y_offset, ret_lidar_auxiliary_data_packet->imu_angle_z_offset, ret_lidar_auxiliary_data_packet->b_axis_dist, ret_lidar_auxiliary_data_packet->theta_angle, ret_lidar_auxiliary_data_packet->ksi_angle, ret_lidar_auxiliary_data_packet->reflect_data);
}

/**
 * @brief Encode a ret_lidar_auxiliary_data_packet struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ret_lidar_auxiliary_data_packet C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ret_lidar_auxiliary_data_packet_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ret_lidar_auxiliary_data_packet_t* ret_lidar_auxiliary_data_packet)
{
    return mavlink_msg_ret_lidar_auxiliary_data_packet_pack_chan(system_id, component_id, chan, msg, ret_lidar_auxiliary_data_packet->lidar_work_status, ret_lidar_auxiliary_data_packet->packet_id, ret_lidar_auxiliary_data_packet->payload_size, ret_lidar_auxiliary_data_packet->lidar_sync_delay_time, ret_lidar_auxiliary_data_packet->time_stamp_s_step, ret_lidar_auxiliary_data_packet->time_stamp_us_step, ret_lidar_auxiliary_data_packet->sys_rotation_period, ret_lidar_auxiliary_data_packet->com_rotation_period, ret_lidar_auxiliary_data_packet->com_horizontal_angle_start, ret_lidar_auxiliary_data_packet->com_horizontal_angle_step, ret_lidar_auxiliary_data_packet->sys_vertical_angle_start, ret_lidar_auxiliary_data_packet->sys_vertical_angle_span, ret_lidar_auxiliary_data_packet->apd_temperature, ret_lidar_auxiliary_data_packet->dirty_index, ret_lidar_auxiliary_data_packet->imu_temperature, ret_lidar_auxiliary_data_packet->up_optical_q, ret_lidar_auxiliary_data_packet->down_optical_q, ret_lidar_auxiliary_data_packet->apd_voltage, ret_lidar_auxiliary_data_packet->imu_angle_x_offset, ret_lidar_auxiliary_data_packet->imu_angle_y_offset, ret_lidar_auxiliary_data_packet->imu_angle_z_offset, ret_lidar_auxiliary_data_packet->b_axis_dist, ret_lidar_auxiliary_data_packet->theta_angle, ret_lidar_auxiliary_data_packet->ksi_angle, ret_lidar_auxiliary_data_packet->reflect_data);
}

/**
 * @brief Send a ret_lidar_auxiliary_data_packet message
 * @param chan MAVLink channel to send the message
 *
 * @param lidar_work_status  LiDAR operational state indicator.
 * @param packet_id  Data packet ID.
 * @param payload_size  Data packet payload size.
 * @param lidar_sync_delay_time  Delay time of upper computer communication(us).
 * @param time_stamp_s_step  LiDAR operational timestamp in seconds.
 * @param time_stamp_us_step  LiDAR operational timestamp in microsecond .
 * @param sys_rotation_period  LiDAR low-speed motor rotation period in microsecond .
 * @param com_rotation_period  LiDAR high-speed motor rotation period in microsecond .
 * @param com_horizontal_angle_start  The first data in the current data packet is the horizontal angle,Distance data applicable to RET_LIDAR_DISTANCE_DATA_PACKET data packet and reflectivity data of RET_LIDAR_AUXILIARY_DATA_PACKET data packet.
 * @param com_horizontal_angle_step  Angle interval between two adjacent data in the horizontal direction.
 * @param sys_vertical_angle_start  The vertical angle of the first data in the current data packet.
 * @param sys_vertical_angle_span  The angular span between adjacent data in the vertical direction of the current data packet.
 * @param apd_temperature  APD temperature value
 * @param dirty_index  Protective cover dirt detection index
 * @param imu_temperature  IMU temperature value
 * @param up_optical_q  Up optical communication quality.
 * @param down_optical_q  Downlink optical communication quality.
 * @param apd_voltage  APD voltage value.
 * @param imu_angle_x_offset  IMU x-axis installation angle error.
 * @param imu_angle_y_offset  IMU y-axis installation angle error.
 * @param imu_angle_z_offset  IMU z-axis installation angle error.
 * @param b_axis_dist  Laser calibration b distance compensation.
 * @param theta_angle  Laser calibration theta angle compensation.
 * @param ksi_angle  Laser calibration ksi angle compensation.
 * @param reflect_data  reflectivity data
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ret_lidar_auxiliary_data_packet_send(mavlink_channel_t chan, uint8_t lidar_work_status, uint16_t packet_id, uint16_t payload_size, uint32_t lidar_sync_delay_time, uint32_t time_stamp_s_step, uint32_t time_stamp_us_step, uint32_t sys_rotation_period, uint32_t com_rotation_period, float com_horizontal_angle_start, float com_horizontal_angle_step, float sys_vertical_angle_start, float sys_vertical_angle_span, float apd_temperature, float dirty_index, float imu_temperature, float up_optical_q, float down_optical_q, float apd_voltage, float imu_angle_x_offset, float imu_angle_y_offset, float imu_angle_z_offset, float b_axis_dist, float theta_angle, float ksi_angle, const uint8_t *reflect_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_LEN];
    _mav_put_uint32_t(buf, 0, lidar_sync_delay_time);
    _mav_put_uint32_t(buf, 4, time_stamp_s_step);
    _mav_put_uint32_t(buf, 8, time_stamp_us_step);
    _mav_put_uint32_t(buf, 12, sys_rotation_period);
    _mav_put_uint32_t(buf, 16, com_rotation_period);
    _mav_put_float(buf, 20, com_horizontal_angle_start);
    _mav_put_float(buf, 24, com_horizontal_angle_step);
    _mav_put_float(buf, 28, sys_vertical_angle_start);
    _mav_put_float(buf, 32, sys_vertical_angle_span);
    _mav_put_float(buf, 36, apd_temperature);
    _mav_put_float(buf, 40, dirty_index);
    _mav_put_float(buf, 44, imu_temperature);
    _mav_put_float(buf, 48, up_optical_q);
    _mav_put_float(buf, 52, down_optical_q);
    _mav_put_float(buf, 56, apd_voltage);
    _mav_put_float(buf, 60, imu_angle_x_offset);
    _mav_put_float(buf, 64, imu_angle_y_offset);
    _mav_put_float(buf, 68, imu_angle_z_offset);
    _mav_put_float(buf, 72, b_axis_dist);
    _mav_put_float(buf, 76, theta_angle);
    _mav_put_float(buf, 80, ksi_angle);
    _mav_put_uint16_t(buf, 84, packet_id);
    _mav_put_uint16_t(buf, 86, payload_size);
    _mav_put_uint8_t(buf, 88, lidar_work_status);
    _mav_put_uint8_t_array(buf, 89, reflect_data, 120);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET, buf, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_CRC);
#else
    mavlink_ret_lidar_auxiliary_data_packet_t packet;
    packet.lidar_sync_delay_time = lidar_sync_delay_time;
    packet.time_stamp_s_step = time_stamp_s_step;
    packet.time_stamp_us_step = time_stamp_us_step;
    packet.sys_rotation_period = sys_rotation_period;
    packet.com_rotation_period = com_rotation_period;
    packet.com_horizontal_angle_start = com_horizontal_angle_start;
    packet.com_horizontal_angle_step = com_horizontal_angle_step;
    packet.sys_vertical_angle_start = sys_vertical_angle_start;
    packet.sys_vertical_angle_span = sys_vertical_angle_span;
    packet.apd_temperature = apd_temperature;
    packet.dirty_index = dirty_index;
    packet.imu_temperature = imu_temperature;
    packet.up_optical_q = up_optical_q;
    packet.down_optical_q = down_optical_q;
    packet.apd_voltage = apd_voltage;
    packet.imu_angle_x_offset = imu_angle_x_offset;
    packet.imu_angle_y_offset = imu_angle_y_offset;
    packet.imu_angle_z_offset = imu_angle_z_offset;
    packet.b_axis_dist = b_axis_dist;
    packet.theta_angle = theta_angle;
    packet.ksi_angle = ksi_angle;
    packet.packet_id = packet_id;
    packet.payload_size = payload_size;
    packet.lidar_work_status = lidar_work_status;
    mav_array_memcpy(packet.reflect_data, reflect_data, sizeof(uint8_t)*120);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET, (const char *)&packet, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_CRC);
#endif
}

/**
 * @brief Send a ret_lidar_auxiliary_data_packet message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ret_lidar_auxiliary_data_packet_send_struct(mavlink_channel_t chan, const mavlink_ret_lidar_auxiliary_data_packet_t* ret_lidar_auxiliary_data_packet)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ret_lidar_auxiliary_data_packet_send(chan, ret_lidar_auxiliary_data_packet->lidar_work_status, ret_lidar_auxiliary_data_packet->packet_id, ret_lidar_auxiliary_data_packet->payload_size, ret_lidar_auxiliary_data_packet->lidar_sync_delay_time, ret_lidar_auxiliary_data_packet->time_stamp_s_step, ret_lidar_auxiliary_data_packet->time_stamp_us_step, ret_lidar_auxiliary_data_packet->sys_rotation_period, ret_lidar_auxiliary_data_packet->com_rotation_period, ret_lidar_auxiliary_data_packet->com_horizontal_angle_start, ret_lidar_auxiliary_data_packet->com_horizontal_angle_step, ret_lidar_auxiliary_data_packet->sys_vertical_angle_start, ret_lidar_auxiliary_data_packet->sys_vertical_angle_span, ret_lidar_auxiliary_data_packet->apd_temperature, ret_lidar_auxiliary_data_packet->dirty_index, ret_lidar_auxiliary_data_packet->imu_temperature, ret_lidar_auxiliary_data_packet->up_optical_q, ret_lidar_auxiliary_data_packet->down_optical_q, ret_lidar_auxiliary_data_packet->apd_voltage, ret_lidar_auxiliary_data_packet->imu_angle_x_offset, ret_lidar_auxiliary_data_packet->imu_angle_y_offset, ret_lidar_auxiliary_data_packet->imu_angle_z_offset, ret_lidar_auxiliary_data_packet->b_axis_dist, ret_lidar_auxiliary_data_packet->theta_angle, ret_lidar_auxiliary_data_packet->ksi_angle, ret_lidar_auxiliary_data_packet->reflect_data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET, (const char *)ret_lidar_auxiliary_data_packet, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_CRC);
#endif
}

#if MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ret_lidar_auxiliary_data_packet_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t lidar_work_status, uint16_t packet_id, uint16_t payload_size, uint32_t lidar_sync_delay_time, uint32_t time_stamp_s_step, uint32_t time_stamp_us_step, uint32_t sys_rotation_period, uint32_t com_rotation_period, float com_horizontal_angle_start, float com_horizontal_angle_step, float sys_vertical_angle_start, float sys_vertical_angle_span, float apd_temperature, float dirty_index, float imu_temperature, float up_optical_q, float down_optical_q, float apd_voltage, float imu_angle_x_offset, float imu_angle_y_offset, float imu_angle_z_offset, float b_axis_dist, float theta_angle, float ksi_angle, const uint8_t *reflect_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, lidar_sync_delay_time);
    _mav_put_uint32_t(buf, 4, time_stamp_s_step);
    _mav_put_uint32_t(buf, 8, time_stamp_us_step);
    _mav_put_uint32_t(buf, 12, sys_rotation_period);
    _mav_put_uint32_t(buf, 16, com_rotation_period);
    _mav_put_float(buf, 20, com_horizontal_angle_start);
    _mav_put_float(buf, 24, com_horizontal_angle_step);
    _mav_put_float(buf, 28, sys_vertical_angle_start);
    _mav_put_float(buf, 32, sys_vertical_angle_span);
    _mav_put_float(buf, 36, apd_temperature);
    _mav_put_float(buf, 40, dirty_index);
    _mav_put_float(buf, 44, imu_temperature);
    _mav_put_float(buf, 48, up_optical_q);
    _mav_put_float(buf, 52, down_optical_q);
    _mav_put_float(buf, 56, apd_voltage);
    _mav_put_float(buf, 60, imu_angle_x_offset);
    _mav_put_float(buf, 64, imu_angle_y_offset);
    _mav_put_float(buf, 68, imu_angle_z_offset);
    _mav_put_float(buf, 72, b_axis_dist);
    _mav_put_float(buf, 76, theta_angle);
    _mav_put_float(buf, 80, ksi_angle);
    _mav_put_uint16_t(buf, 84, packet_id);
    _mav_put_uint16_t(buf, 86, payload_size);
    _mav_put_uint8_t(buf, 88, lidar_work_status);
    _mav_put_uint8_t_array(buf, 89, reflect_data, 120);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET, buf, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_CRC);
#else
    mavlink_ret_lidar_auxiliary_data_packet_t *packet = (mavlink_ret_lidar_auxiliary_data_packet_t *)msgbuf;
    packet->lidar_sync_delay_time = lidar_sync_delay_time;
    packet->time_stamp_s_step = time_stamp_s_step;
    packet->time_stamp_us_step = time_stamp_us_step;
    packet->sys_rotation_period = sys_rotation_period;
    packet->com_rotation_period = com_rotation_period;
    packet->com_horizontal_angle_start = com_horizontal_angle_start;
    packet->com_horizontal_angle_step = com_horizontal_angle_step;
    packet->sys_vertical_angle_start = sys_vertical_angle_start;
    packet->sys_vertical_angle_span = sys_vertical_angle_span;
    packet->apd_temperature = apd_temperature;
    packet->dirty_index = dirty_index;
    packet->imu_temperature = imu_temperature;
    packet->up_optical_q = up_optical_q;
    packet->down_optical_q = down_optical_q;
    packet->apd_voltage = apd_voltage;
    packet->imu_angle_x_offset = imu_angle_x_offset;
    packet->imu_angle_y_offset = imu_angle_y_offset;
    packet->imu_angle_z_offset = imu_angle_z_offset;
    packet->b_axis_dist = b_axis_dist;
    packet->theta_angle = theta_angle;
    packet->ksi_angle = ksi_angle;
    packet->packet_id = packet_id;
    packet->payload_size = payload_size;
    packet->lidar_work_status = lidar_work_status;
    mav_array_memcpy(packet->reflect_data, reflect_data, sizeof(uint8_t)*120);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET, (const char *)packet, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_CRC);
#endif
}
#endif

#endif

// MESSAGE RET_LIDAR_AUXILIARY_DATA_PACKET UNPACKING


/**
 * @brief Get field lidar_work_status from ret_lidar_auxiliary_data_packet message
 *
 * @return  LiDAR operational state indicator.
 */
static inline uint8_t mavlink_msg_ret_lidar_auxiliary_data_packet_get_lidar_work_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  88);
}

/**
 * @brief Get field packet_id from ret_lidar_auxiliary_data_packet message
 *
 * @return  Data packet ID.
 */
static inline uint16_t mavlink_msg_ret_lidar_auxiliary_data_packet_get_packet_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  84);
}

/**
 * @brief Get field payload_size from ret_lidar_auxiliary_data_packet message
 *
 * @return  Data packet payload size.
 */
static inline uint16_t mavlink_msg_ret_lidar_auxiliary_data_packet_get_payload_size(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  86);
}

/**
 * @brief Get field lidar_sync_delay_time from ret_lidar_auxiliary_data_packet message
 *
 * @return  Delay time of upper computer communication(us).
 */
static inline uint32_t mavlink_msg_ret_lidar_auxiliary_data_packet_get_lidar_sync_delay_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field time_stamp_s_step from ret_lidar_auxiliary_data_packet message
 *
 * @return  LiDAR operational timestamp in seconds.
 */
static inline uint32_t mavlink_msg_ret_lidar_auxiliary_data_packet_get_time_stamp_s_step(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field time_stamp_us_step from ret_lidar_auxiliary_data_packet message
 *
 * @return  LiDAR operational timestamp in microsecond .
 */
static inline uint32_t mavlink_msg_ret_lidar_auxiliary_data_packet_get_time_stamp_us_step(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field sys_rotation_period from ret_lidar_auxiliary_data_packet message
 *
 * @return  LiDAR low-speed motor rotation period in microsecond .
 */
static inline uint32_t mavlink_msg_ret_lidar_auxiliary_data_packet_get_sys_rotation_period(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field com_rotation_period from ret_lidar_auxiliary_data_packet message
 *
 * @return  LiDAR high-speed motor rotation period in microsecond .
 */
static inline uint32_t mavlink_msg_ret_lidar_auxiliary_data_packet_get_com_rotation_period(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field com_horizontal_angle_start from ret_lidar_auxiliary_data_packet message
 *
 * @return  The first data in the current data packet is the horizontal angle,Distance data applicable to RET_LIDAR_DISTANCE_DATA_PACKET data packet and reflectivity data of RET_LIDAR_AUXILIARY_DATA_PACKET data packet.
 */
static inline float mavlink_msg_ret_lidar_auxiliary_data_packet_get_com_horizontal_angle_start(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field com_horizontal_angle_step from ret_lidar_auxiliary_data_packet message
 *
 * @return  Angle interval between two adjacent data in the horizontal direction.
 */
static inline float mavlink_msg_ret_lidar_auxiliary_data_packet_get_com_horizontal_angle_step(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field sys_vertical_angle_start from ret_lidar_auxiliary_data_packet message
 *
 * @return  The vertical angle of the first data in the current data packet.
 */
static inline float mavlink_msg_ret_lidar_auxiliary_data_packet_get_sys_vertical_angle_start(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field sys_vertical_angle_span from ret_lidar_auxiliary_data_packet message
 *
 * @return  The angular span between adjacent data in the vertical direction of the current data packet.
 */
static inline float mavlink_msg_ret_lidar_auxiliary_data_packet_get_sys_vertical_angle_span(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field apd_temperature from ret_lidar_auxiliary_data_packet message
 *
 * @return  APD temperature value
 */
static inline float mavlink_msg_ret_lidar_auxiliary_data_packet_get_apd_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field dirty_index from ret_lidar_auxiliary_data_packet message
 *
 * @return  Protective cover dirt detection index
 */
static inline float mavlink_msg_ret_lidar_auxiliary_data_packet_get_dirty_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field imu_temperature from ret_lidar_auxiliary_data_packet message
 *
 * @return  IMU temperature value
 */
static inline float mavlink_msg_ret_lidar_auxiliary_data_packet_get_imu_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field up_optical_q from ret_lidar_auxiliary_data_packet message
 *
 * @return  Up optical communication quality.
 */
static inline float mavlink_msg_ret_lidar_auxiliary_data_packet_get_up_optical_q(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field down_optical_q from ret_lidar_auxiliary_data_packet message
 *
 * @return  Downlink optical communication quality.
 */
static inline float mavlink_msg_ret_lidar_auxiliary_data_packet_get_down_optical_q(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field apd_voltage from ret_lidar_auxiliary_data_packet message
 *
 * @return  APD voltage value.
 */
static inline float mavlink_msg_ret_lidar_auxiliary_data_packet_get_apd_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field imu_angle_x_offset from ret_lidar_auxiliary_data_packet message
 *
 * @return  IMU x-axis installation angle error.
 */
static inline float mavlink_msg_ret_lidar_auxiliary_data_packet_get_imu_angle_x_offset(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field imu_angle_y_offset from ret_lidar_auxiliary_data_packet message
 *
 * @return  IMU y-axis installation angle error.
 */
static inline float mavlink_msg_ret_lidar_auxiliary_data_packet_get_imu_angle_y_offset(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field imu_angle_z_offset from ret_lidar_auxiliary_data_packet message
 *
 * @return  IMU z-axis installation angle error.
 */
static inline float mavlink_msg_ret_lidar_auxiliary_data_packet_get_imu_angle_z_offset(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Get field b_axis_dist from ret_lidar_auxiliary_data_packet message
 *
 * @return  Laser calibration b distance compensation.
 */
static inline float mavlink_msg_ret_lidar_auxiliary_data_packet_get_b_axis_dist(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  72);
}

/**
 * @brief Get field theta_angle from ret_lidar_auxiliary_data_packet message
 *
 * @return  Laser calibration theta angle compensation.
 */
static inline float mavlink_msg_ret_lidar_auxiliary_data_packet_get_theta_angle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  76);
}

/**
 * @brief Get field ksi_angle from ret_lidar_auxiliary_data_packet message
 *
 * @return  Laser calibration ksi angle compensation.
 */
static inline float mavlink_msg_ret_lidar_auxiliary_data_packet_get_ksi_angle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  80);
}

/**
 * @brief Get field reflect_data from ret_lidar_auxiliary_data_packet message
 *
 * @return  reflectivity data
 */
static inline uint16_t mavlink_msg_ret_lidar_auxiliary_data_packet_get_reflect_data(const mavlink_message_t* msg, uint8_t *reflect_data)
{
    return _MAV_RETURN_uint8_t_array(msg, reflect_data, 120,  89);
}

/**
 * @brief Decode a ret_lidar_auxiliary_data_packet message into a struct
 *
 * @param msg The message to decode
 * @param ret_lidar_auxiliary_data_packet C-struct to decode the message contents into
 */
static inline void mavlink_msg_ret_lidar_auxiliary_data_packet_decode(const mavlink_message_t* msg, mavlink_ret_lidar_auxiliary_data_packet_t* ret_lidar_auxiliary_data_packet)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ret_lidar_auxiliary_data_packet->lidar_sync_delay_time = mavlink_msg_ret_lidar_auxiliary_data_packet_get_lidar_sync_delay_time(msg);
    ret_lidar_auxiliary_data_packet->time_stamp_s_step = mavlink_msg_ret_lidar_auxiliary_data_packet_get_time_stamp_s_step(msg);
    ret_lidar_auxiliary_data_packet->time_stamp_us_step = mavlink_msg_ret_lidar_auxiliary_data_packet_get_time_stamp_us_step(msg);
    ret_lidar_auxiliary_data_packet->sys_rotation_period = mavlink_msg_ret_lidar_auxiliary_data_packet_get_sys_rotation_period(msg);
    ret_lidar_auxiliary_data_packet->com_rotation_period = mavlink_msg_ret_lidar_auxiliary_data_packet_get_com_rotation_period(msg);
    ret_lidar_auxiliary_data_packet->com_horizontal_angle_start = mavlink_msg_ret_lidar_auxiliary_data_packet_get_com_horizontal_angle_start(msg);
    ret_lidar_auxiliary_data_packet->com_horizontal_angle_step = mavlink_msg_ret_lidar_auxiliary_data_packet_get_com_horizontal_angle_step(msg);
    ret_lidar_auxiliary_data_packet->sys_vertical_angle_start = mavlink_msg_ret_lidar_auxiliary_data_packet_get_sys_vertical_angle_start(msg);
    ret_lidar_auxiliary_data_packet->sys_vertical_angle_span = mavlink_msg_ret_lidar_auxiliary_data_packet_get_sys_vertical_angle_span(msg);
    ret_lidar_auxiliary_data_packet->apd_temperature = mavlink_msg_ret_lidar_auxiliary_data_packet_get_apd_temperature(msg);
    ret_lidar_auxiliary_data_packet->dirty_index = mavlink_msg_ret_lidar_auxiliary_data_packet_get_dirty_index(msg);
    ret_lidar_auxiliary_data_packet->imu_temperature = mavlink_msg_ret_lidar_auxiliary_data_packet_get_imu_temperature(msg);
    ret_lidar_auxiliary_data_packet->up_optical_q = mavlink_msg_ret_lidar_auxiliary_data_packet_get_up_optical_q(msg);
    ret_lidar_auxiliary_data_packet->down_optical_q = mavlink_msg_ret_lidar_auxiliary_data_packet_get_down_optical_q(msg);
    ret_lidar_auxiliary_data_packet->apd_voltage = mavlink_msg_ret_lidar_auxiliary_data_packet_get_apd_voltage(msg);
    ret_lidar_auxiliary_data_packet->imu_angle_x_offset = mavlink_msg_ret_lidar_auxiliary_data_packet_get_imu_angle_x_offset(msg);
    ret_lidar_auxiliary_data_packet->imu_angle_y_offset = mavlink_msg_ret_lidar_auxiliary_data_packet_get_imu_angle_y_offset(msg);
    ret_lidar_auxiliary_data_packet->imu_angle_z_offset = mavlink_msg_ret_lidar_auxiliary_data_packet_get_imu_angle_z_offset(msg);
    ret_lidar_auxiliary_data_packet->b_axis_dist = mavlink_msg_ret_lidar_auxiliary_data_packet_get_b_axis_dist(msg);
    ret_lidar_auxiliary_data_packet->theta_angle = mavlink_msg_ret_lidar_auxiliary_data_packet_get_theta_angle(msg);
    ret_lidar_auxiliary_data_packet->ksi_angle = mavlink_msg_ret_lidar_auxiliary_data_packet_get_ksi_angle(msg);
    ret_lidar_auxiliary_data_packet->packet_id = mavlink_msg_ret_lidar_auxiliary_data_packet_get_packet_id(msg);
    ret_lidar_auxiliary_data_packet->payload_size = mavlink_msg_ret_lidar_auxiliary_data_packet_get_payload_size(msg);
    ret_lidar_auxiliary_data_packet->lidar_work_status = mavlink_msg_ret_lidar_auxiliary_data_packet_get_lidar_work_status(msg);
    mavlink_msg_ret_lidar_auxiliary_data_packet_get_reflect_data(msg, ret_lidar_auxiliary_data_packet->reflect_data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_LEN? msg->len : MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_LEN;
        memset(ret_lidar_auxiliary_data_packet, 0, MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_LEN);
    memcpy(ret_lidar_auxiliary_data_packet, _MAV_PAYLOAD(msg), len);
#endif
}
