#pragma once
// MESSAGE RET_IMU_ATTITUDE_DATA_PACKET PACKING

#define MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET 19


typedef struct __mavlink_ret_imu_attitude_data_packet_t {
 float quaternion[4]; /*<  Quaternion Array.*/
 float angular_velocity[3]; /*<  Three-axis angular velocity values.*/
 float linear_acceleration[3]; /*<  Three-axis acceleration values.*/
 uint16_t packet_id; /*<  Data packet ID.*/
} mavlink_ret_imu_attitude_data_packet_t;

#define MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_LEN 42
#define MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_MIN_LEN 42
#define MAVLINK_MSG_ID_19_LEN 42
#define MAVLINK_MSG_ID_19_MIN_LEN 42

#define MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_CRC 110
#define MAVLINK_MSG_ID_19_CRC 110

#define MAVLINK_MSG_RET_IMU_ATTITUDE_DATA_PACKET_FIELD_QUATERNION_LEN 4
#define MAVLINK_MSG_RET_IMU_ATTITUDE_DATA_PACKET_FIELD_ANGULAR_VELOCITY_LEN 3
#define MAVLINK_MSG_RET_IMU_ATTITUDE_DATA_PACKET_FIELD_LINEAR_ACCELERATION_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RET_IMU_ATTITUDE_DATA_PACKET { \
    19, \
    "RET_IMU_ATTITUDE_DATA_PACKET", \
    4, \
    {  { "packet_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_ret_imu_attitude_data_packet_t, packet_id) }, \
         { "quaternion", NULL, MAVLINK_TYPE_FLOAT, 4, 0, offsetof(mavlink_ret_imu_attitude_data_packet_t, quaternion) }, \
         { "angular_velocity", NULL, MAVLINK_TYPE_FLOAT, 3, 16, offsetof(mavlink_ret_imu_attitude_data_packet_t, angular_velocity) }, \
         { "linear_acceleration", NULL, MAVLINK_TYPE_FLOAT, 3, 28, offsetof(mavlink_ret_imu_attitude_data_packet_t, linear_acceleration) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RET_IMU_ATTITUDE_DATA_PACKET { \
    "RET_IMU_ATTITUDE_DATA_PACKET", \
    4, \
    {  { "packet_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_ret_imu_attitude_data_packet_t, packet_id) }, \
         { "quaternion", NULL, MAVLINK_TYPE_FLOAT, 4, 0, offsetof(mavlink_ret_imu_attitude_data_packet_t, quaternion) }, \
         { "angular_velocity", NULL, MAVLINK_TYPE_FLOAT, 3, 16, offsetof(mavlink_ret_imu_attitude_data_packet_t, angular_velocity) }, \
         { "linear_acceleration", NULL, MAVLINK_TYPE_FLOAT, 3, 28, offsetof(mavlink_ret_imu_attitude_data_packet_t, linear_acceleration) }, \
         } \
}
#endif

/**
 * @brief Pack a ret_imu_attitude_data_packet message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param packet_id  Data packet ID.
 * @param quaternion  Quaternion Array.
 * @param angular_velocity  Three-axis angular velocity values.
 * @param linear_acceleration  Three-axis acceleration values.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ret_imu_attitude_data_packet_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t packet_id, const float *quaternion, const float *angular_velocity, const float *linear_acceleration)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_LEN];
    _mav_put_uint16_t(buf, 40, packet_id);
    _mav_put_float_array(buf, 0, quaternion, 4);
    _mav_put_float_array(buf, 16, angular_velocity, 3);
    _mav_put_float_array(buf, 28, linear_acceleration, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_LEN);
#else
    mavlink_ret_imu_attitude_data_packet_t packet;
    packet.packet_id = packet_id;
    mav_array_memcpy(packet.quaternion, quaternion, sizeof(float)*4);
    mav_array_memcpy(packet.angular_velocity, angular_velocity, sizeof(float)*3);
    mav_array_memcpy(packet.linear_acceleration, linear_acceleration, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_CRC);
}

/**
 * @brief Pack a ret_imu_attitude_data_packet message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param packet_id  Data packet ID.
 * @param quaternion  Quaternion Array.
 * @param angular_velocity  Three-axis angular velocity values.
 * @param linear_acceleration  Three-axis acceleration values.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ret_imu_attitude_data_packet_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t packet_id,const float *quaternion,const float *angular_velocity,const float *linear_acceleration)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_LEN];
    _mav_put_uint16_t(buf, 40, packet_id);
    _mav_put_float_array(buf, 0, quaternion, 4);
    _mav_put_float_array(buf, 16, angular_velocity, 3);
    _mav_put_float_array(buf, 28, linear_acceleration, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_LEN);
#else
    mavlink_ret_imu_attitude_data_packet_t packet;
    packet.packet_id = packet_id;
    mav_array_memcpy(packet.quaternion, quaternion, sizeof(float)*4);
    mav_array_memcpy(packet.angular_velocity, angular_velocity, sizeof(float)*3);
    mav_array_memcpy(packet.linear_acceleration, linear_acceleration, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_CRC);
}

/**
 * @brief Encode a ret_imu_attitude_data_packet struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ret_imu_attitude_data_packet C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ret_imu_attitude_data_packet_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ret_imu_attitude_data_packet_t* ret_imu_attitude_data_packet)
{
    return mavlink_msg_ret_imu_attitude_data_packet_pack(system_id, component_id, msg, ret_imu_attitude_data_packet->packet_id, ret_imu_attitude_data_packet->quaternion, ret_imu_attitude_data_packet->angular_velocity, ret_imu_attitude_data_packet->linear_acceleration);
}

/**
 * @brief Encode a ret_imu_attitude_data_packet struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ret_imu_attitude_data_packet C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ret_imu_attitude_data_packet_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ret_imu_attitude_data_packet_t* ret_imu_attitude_data_packet)
{
    return mavlink_msg_ret_imu_attitude_data_packet_pack_chan(system_id, component_id, chan, msg, ret_imu_attitude_data_packet->packet_id, ret_imu_attitude_data_packet->quaternion, ret_imu_attitude_data_packet->angular_velocity, ret_imu_attitude_data_packet->linear_acceleration);
}

/**
 * @brief Send a ret_imu_attitude_data_packet message
 * @param chan MAVLink channel to send the message
 *
 * @param packet_id  Data packet ID.
 * @param quaternion  Quaternion Array.
 * @param angular_velocity  Three-axis angular velocity values.
 * @param linear_acceleration  Three-axis acceleration values.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ret_imu_attitude_data_packet_send(mavlink_channel_t chan, uint16_t packet_id, const float *quaternion, const float *angular_velocity, const float *linear_acceleration)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_LEN];
    _mav_put_uint16_t(buf, 40, packet_id);
    _mav_put_float_array(buf, 0, quaternion, 4);
    _mav_put_float_array(buf, 16, angular_velocity, 3);
    _mav_put_float_array(buf, 28, linear_acceleration, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET, buf, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_CRC);
#else
    mavlink_ret_imu_attitude_data_packet_t packet;
    packet.packet_id = packet_id;
    mav_array_memcpy(packet.quaternion, quaternion, sizeof(float)*4);
    mav_array_memcpy(packet.angular_velocity, angular_velocity, sizeof(float)*3);
    mav_array_memcpy(packet.linear_acceleration, linear_acceleration, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET, (const char *)&packet, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_CRC);
#endif
}

/**
 * @brief Send a ret_imu_attitude_data_packet message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ret_imu_attitude_data_packet_send_struct(mavlink_channel_t chan, const mavlink_ret_imu_attitude_data_packet_t* ret_imu_attitude_data_packet)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ret_imu_attitude_data_packet_send(chan, ret_imu_attitude_data_packet->packet_id, ret_imu_attitude_data_packet->quaternion, ret_imu_attitude_data_packet->angular_velocity, ret_imu_attitude_data_packet->linear_acceleration);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET, (const char *)ret_imu_attitude_data_packet, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_CRC);
#endif
}

#if MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ret_imu_attitude_data_packet_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t packet_id, const float *quaternion, const float *angular_velocity, const float *linear_acceleration)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 40, packet_id);
    _mav_put_float_array(buf, 0, quaternion, 4);
    _mav_put_float_array(buf, 16, angular_velocity, 3);
    _mav_put_float_array(buf, 28, linear_acceleration, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET, buf, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_CRC);
#else
    mavlink_ret_imu_attitude_data_packet_t *packet = (mavlink_ret_imu_attitude_data_packet_t *)msgbuf;
    packet->packet_id = packet_id;
    mav_array_memcpy(packet->quaternion, quaternion, sizeof(float)*4);
    mav_array_memcpy(packet->angular_velocity, angular_velocity, sizeof(float)*3);
    mav_array_memcpy(packet->linear_acceleration, linear_acceleration, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET, (const char *)packet, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_CRC);
#endif
}
#endif

#endif

// MESSAGE RET_IMU_ATTITUDE_DATA_PACKET UNPACKING


/**
 * @brief Get field packet_id from ret_imu_attitude_data_packet message
 *
 * @return  Data packet ID.
 */
static inline uint16_t mavlink_msg_ret_imu_attitude_data_packet_get_packet_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  40);
}

/**
 * @brief Get field quaternion from ret_imu_attitude_data_packet message
 *
 * @return  Quaternion Array.
 */
static inline uint16_t mavlink_msg_ret_imu_attitude_data_packet_get_quaternion(const mavlink_message_t* msg, float *quaternion)
{
    return _MAV_RETURN_float_array(msg, quaternion, 4,  0);
}

/**
 * @brief Get field angular_velocity from ret_imu_attitude_data_packet message
 *
 * @return  Three-axis angular velocity values.
 */
static inline uint16_t mavlink_msg_ret_imu_attitude_data_packet_get_angular_velocity(const mavlink_message_t* msg, float *angular_velocity)
{
    return _MAV_RETURN_float_array(msg, angular_velocity, 3,  16);
}

/**
 * @brief Get field linear_acceleration from ret_imu_attitude_data_packet message
 *
 * @return  Three-axis acceleration values.
 */
static inline uint16_t mavlink_msg_ret_imu_attitude_data_packet_get_linear_acceleration(const mavlink_message_t* msg, float *linear_acceleration)
{
    return _MAV_RETURN_float_array(msg, linear_acceleration, 3,  28);
}

/**
 * @brief Decode a ret_imu_attitude_data_packet message into a struct
 *
 * @param msg The message to decode
 * @param ret_imu_attitude_data_packet C-struct to decode the message contents into
 */
static inline void mavlink_msg_ret_imu_attitude_data_packet_decode(const mavlink_message_t* msg, mavlink_ret_imu_attitude_data_packet_t* ret_imu_attitude_data_packet)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ret_imu_attitude_data_packet_get_quaternion(msg, ret_imu_attitude_data_packet->quaternion);
    mavlink_msg_ret_imu_attitude_data_packet_get_angular_velocity(msg, ret_imu_attitude_data_packet->angular_velocity);
    mavlink_msg_ret_imu_attitude_data_packet_get_linear_acceleration(msg, ret_imu_attitude_data_packet->linear_acceleration);
    ret_imu_attitude_data_packet->packet_id = mavlink_msg_ret_imu_attitude_data_packet_get_packet_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_LEN? msg->len : MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_LEN;
        memset(ret_imu_attitude_data_packet, 0, MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_LEN);
    memcpy(ret_imu_attitude_data_packet, _MAV_PAYLOAD(msg), len);
#endif
}
