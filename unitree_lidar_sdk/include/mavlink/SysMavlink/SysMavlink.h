/** @file
 *  @brief MAVLink comm protocol generated from SysMavlink.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_SYSMAVLINK_H
#define MAVLINK_SYSMAVLINK_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_SYSMAVLINK.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_HASH
#define MAVLINK_THIS_XML_HASH 2384190490983077020

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{11, 106, 1, 1, 0, 0, 0}, {12, 204, 1, 1, 0, 0, 0}, {13, 62, 38, 38, 0, 0, 0}, {14, 84, 1, 1, 0, 0, 0}, {15, 236, 56, 56, 0, 0, 0}, {16, 74, 246, 246, 0, 0, 0}, {17, 99, 209, 209, 0, 0, 0}, {18, 12, 5, 5, 0, 0, 0}, {19, 110, 42, 42, 0, 0, 0}, {121, 228, 1, 1, 0, 0, 0}, {122, 151, 20, 20, 0, 0, 0}, {123, 10, 61, 61, 0, 0, 0}, {124, 68, 44, 44, 0, 0, 0}, {125, 149, 36, 36, 0, 0, 0}, {126, 25, 1, 1, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_SYSMAVLINK

// ENUM DEFINITIONS


/** @brief  */
#ifndef HAVE_ENUM_DEVICE_REQUEST_ANSWER_TYPE
#define HAVE_ENUM_DEVICE_REQUEST_ANSWER_TYPE
typedef enum DEVICE_REQUEST_ANSWER_TYPE
{
   PC2COM_OK=1, /* PC return ok to com board | */
   COM2PC_OK=2, /* Com board return ok to PC | */
   COM2SYS_OK=3, /* Com board return ok to sys board | */
   SYS2COM_OK=4, /* Sys board return ok to com board | */
   PC2SYS_OK=5, /* PC return ok to sys board | */
   SYS2PC_OK=6, /* Sys board return ok to PC | */
   DEVICE_REQUEST_ANSWER_TYPE_ENUM_END=7, /*  | */
} DEVICE_REQUEST_ANSWER_TYPE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_LIDAR_WORKING_MODE
#define HAVE_ENUM_LIDAR_WORKING_MODE
typedef enum LIDAR_WORKING_MODE
{
   NORMAL_MODE=1, /* Configure the LiDAR to operate in normal mode. | */
   STANDBY_MODE=2, /* Configure the LiDAR to enter standby mode. | */
   RAW_MODE=3, /* Configure the LiDAR to operate in raw mode. | */
   LIDAR_WORKING_MODE_ENUM_END=4, /*  | */
} LIDAR_WORKING_MODE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_LIDAR_WORKING_INTERNAL_MODE
#define HAVE_ENUM_LIDAR_WORKING_INTERNAL_MODE
typedef enum LIDAR_WORKING_INTERNAL_MODE
{
   INTERNAL_NORMAL_MODE=1, /* Configure the LiDAR to operate in normal mode. | */
   INTERNAL_RAW_MODE=2, /* Configure the LiDAR to operate in raw mode. | */
   INTERNAL_STANDBY_MODE=3, /* Configure the LiDAR to enter standby mode. | */
   INTERNAL_COM_MOTOR_STOP_MODE=4, /* Configure the LiDAR to enter 2D mode. | */
   INTERNAL_APD_DEBUG_MODE=5, /* Configure the LiDAR to enter APD test mode. | */
   INTERNAL_STRENGTH_DEBUG_MODE=6, /* Configure the LiDAR to strength test mode. | */
   INTERNAL_DISTANCE_DEBUG_MODE=7, /* Configure the LiDAR to distance test mode. | */
   INTERNAL_POINT_DEGUB_MODE=8, /* Configure the LiDAR to point test mode. | */
   INTERNAL_CONTINUE_POINT_DEGUB_MODE=9, /* Configure the LiDAR to continue point test mode. | */
   INTERNAL_LASER_TEST_MODE=10, /* Configure the LiDAR to laser 100KHZ test mode. | */
   INTERNAL_IMU_QUATERNION_MODE=11, /* Configure the LiDAR to IMU quaternion dispay mode. | */
   INTERNAL_IMU_ACC_GYRO_MODE=12, /* Configure the LiDAR to IMU riginion data test mode. | */
   LIDAR_WORKING_INTERNAL_MODE_ENUM_END=13, /*  | */
} LIDAR_WORKING_INTERNAL_MODE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_LIDAR_WORKING_STATUS
#define HAVE_ENUM_LIDAR_WORKING_STATUS
typedef enum LIDAR_WORKING_STATUS
{
   WORK_MODE_STA=1, /* Status of lidar work mode 0:Nomal mode 1:Raw mode | */
   LED_RING_LOST_RATE_STA=2, /* Status of led ring data lost status 0: lost rate ok 1:lost rate error | */
   POINT_LOST_RATE_STA=4, /* Status of point cloud lost rate 0: lost rate ok 1:lost rate error | */
   LED_RING_COMMAND_STA=8, /* Status of lidar command mode 0:LED command mode 1:other function work mode | */
   IMU_WORK_STA=16, /* Status of IMU 0: IMU work ok 1: IMU work error | */
   SYS_ENCODER_STA=32, /* Status of SYS encoder 0:encoder ok 1:encoder error | */
   COM_ENCODER_STA=64, /* Status of COM encoder 0:encoder ok 1:encoder error | */
   LIDAR_DATA_AVAILABLE=128, /* Status of lidar data available 0:Available 1:Not Available | */
   LIDAR_WORKING_STATUS_ENUM_END=129, /*  | */
} LIDAR_WORKING_STATUS;
#endif

/** @brief  */
#ifndef HAVE_ENUM_DEVICE_REQUEST_INTERNAL_DATA_TYPE
#define HAVE_ENUM_DEVICE_REQUEST_INTERNAL_DATA_TYPE
typedef enum DEVICE_REQUEST_INTERNAL_DATA_TYPE
{
   INTERNAL_DATA_REQUEST_CLOCK_SYNC=1, /* Request for device state | */
   INTERNAL_CMD_LIDAR_VERSION=2, /* Request get firmware version | */
   INTERNAL_DATA_REQUEST_COM_FLASH_PARAMETER=3, /* Request for com flash paramteter | */
   INTERNAL_DATA_REQUEST_SYS_FLASH_PARAMETER=4, /* Request for sys flash paramteter | */
   DEVICE_REQUEST_INTERNAL_DATA_TYPE_ENUM_END=5, /*  | */
} DEVICE_REQUEST_INTERNAL_DATA_TYPE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_DEVICE_REQUEST_DATA_TYPE
#define HAVE_ENUM_DEVICE_REQUEST_DATA_TYPE
typedef enum DEVICE_REQUEST_DATA_TYPE
{
   DATA_REQUEST_CLOCK_SYNC=1, /* Request for device state | */
   CMD_LIDAR_VERSION=2, /* Request get firmware version | */
   DEVICE_REQUEST_DATA_TYPE_ENUM_END=3, /*  | */
} DEVICE_REQUEST_DATA_TYPE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_DEVICE_COMMAND_TYPE
#define HAVE_ENUM_DEVICE_COMMAND_TYPE
typedef enum DEVICE_COMMAND_TYPE
{
   CMD_LIDAR_SAVE_FLASH=1, /* Save lidar configuration to Flash memory | */
   CMD_LIDAR_REBOOT=2, /* Reboot lidar | */
   DEVICE_COMMAND_TYPE_ENUM_END=3, /*  | */
} DEVICE_COMMAND_TYPE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_SYNC_TIME_TYPE
#define HAVE_ENUM_SYNC_TIME_TYPE
typedef enum SYNC_TIME_TYPE
{
   CMD_SYNC_TIME_REQUEST=1, /* Lidar sync time request start | */
   CMD_SYNC_TIME_RESPONSE=2, /* Lidar sync time request response | */
   SYNC_TIME_TYPE_ENUM_END=3, /*  | */
} SYNC_TIME_TYPE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_LED_DISPLAY_MODE_SELECT
#define HAVE_ENUM_LED_DISPLAY_MODE_SELECT
typedef enum LED_DISPLAY_MODE_SELECT
{
   LED_RING_COMMAND_MODE=1, /* Command display mode. | */
   LED_RING_FUN_FORWARD_SLOW_MODE=2, /* Function mode forward at slow. | */
   LED_RING_FUN_FORWARD_FAST_MODE=3, /* Function mode forward at fast. | */
   LED_RING_FUN_REVERSE_SLOW_MODE=4, /* Function mode reverse at slow. | */
   LED_RING_FUN_REVERSE_FAST_MODE=5, /* Function mode reverse at fast. | */
   LED_RING_FUN_TRIPLE_FLIP_MODE=6, /* Function mode triple flip. | */
   LED_RING_FUN_TRIPLE_BREATHING_MODE=7, /* Function mode triple breathing. | */
   LED_RING_FUN_SIXSTAGE_BREATHING_MODE=8, /* Function mode six-stage breathing. | */
   LED_DISPLAY_MODE_SELECT_ENUM_END=9, /*  | */
} LED_DISPLAY_MODE_SELECT;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 34
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 34
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_device_request_data.h"
#include "./mavlink_msg_device_command.h"
#include "./mavlink_msg_ret_lidar_version.h"
#include "./mavlink_msg_config_lidar_working_mode.h"
#include "./mavlink_msg_config_led_ring_table_packet.h"
#include "./mavlink_msg_ret_lidar_distance_data_packet.h"
#include "./mavlink_msg_ret_lidar_auxiliary_data_packet.h"
#include "./mavlink_msg_ret_lidar_time_sync_data.h"
#include "./mavlink_msg_ret_imu_attitude_data_packet.h"

// base include


#undef MAVLINK_THIS_XML_HASH
#define MAVLINK_THIS_XML_HASH 2384190490983077020

#if MAVLINK_THIS_XML_HASH == MAVLINK_PRIMARY_XML_HASH
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_DEVICE_REQUEST_DATA, MAVLINK_MESSAGE_INFO_DEVICE_COMMAND, MAVLINK_MESSAGE_INFO_RET_LIDAR_VERSION, MAVLINK_MESSAGE_INFO_CONFIG_LIDAR_WORKING_MODE, MAVLINK_MESSAGE_INFO_CONFIG_LED_RING_TABLE_PACKET, MAVLINK_MESSAGE_INFO_RET_LIDAR_DISTANCE_DATA_PACKET, MAVLINK_MESSAGE_INFO_RET_LIDAR_AUXILIARY_DATA_PACKET, MAVLINK_MESSAGE_INFO_RET_LIDAR_TIME_SYNC_DATA, MAVLINK_MESSAGE_INFO_RET_IMU_ATTITUDE_DATA_PACKET, MAVLINK_MESSAGE_INFO_DEVICE_REQUEST_ANSWER, MAVLINK_MESSAGE_INFO_DEVICE_DEBUG_MODE_PARAMS, MAVLINK_MESSAGE_INFO_SET_COM_NECESSARY_MEASURE_PARAMETER, MAVLINK_MESSAGE_INFO_SET_SYS_NECESSARY_MEASURE_PARAMETER, MAVLINK_MESSAGE_INFO_RET_TDC_POINT_DEBUG_PACKET, MAVLINK_MESSAGE_INFO_DEVICE_REQUEST_INTERNAL_DATA}
# define MAVLINK_MESSAGE_NAMES {{ "CONFIG_LED_RING_TABLE_PACKET", 15 }, { "CONFIG_LIDAR_WORKING_MODE", 14 }, { "DEVICE_COMMAND", 12 }, { "DEVICE_DEBUG_MODE_PARAMS", 122 }, { "DEVICE_REQUEST_ANSWER", 121 }, { "DEVICE_REQUEST_DATA", 11 }, { "DEVICE_REQUEST_INTERNAL_DATA", 126 }, { "RET_IMU_ATTITUDE_DATA_PACKET", 19 }, { "RET_LIDAR_AUXILIARY_DATA_PACKET", 17 }, { "RET_LIDAR_DISTANCE_DATA_PACKET", 16 }, { "RET_LIDAR_TIME_SYNC_DATA", 18 }, { "RET_LIDAR_VERSION", 13 }, { "RET_TDC_POINT_DEBUG_PACKET", 125 }, { "SET_COM_NECESSARY_MEASURE_PARAMETER", 123 }, { "SET_SYS_NECESSARY_MEASURE_PARAMETER", 124 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_SYSMAVLINK_H
