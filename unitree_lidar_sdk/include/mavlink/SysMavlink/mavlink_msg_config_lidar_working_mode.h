#pragma once
// MESSAGE CONFIG_LIDAR_WORKING_MODE PACKING

#define MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE 14


typedef struct __mavlink_config_lidar_working_mode_t {
 uint8_t request_type; /*<  Types of operating modes for LiDAR.*/
} mavlink_config_lidar_working_mode_t;

#define MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_LEN 1
#define MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_MIN_LEN 1
#define MAVLINK_MSG_ID_14_LEN 1
#define MAVLINK_MSG_ID_14_MIN_LEN 1

#define MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_CRC 84
#define MAVLINK_MSG_ID_14_CRC 84



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CONFIG_LIDAR_WORKING_MODE { \
    14, \
    "CONFIG_LIDAR_WORKING_MODE", \
    1, \
    {  { "request_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_config_lidar_working_mode_t, request_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CONFIG_LIDAR_WORKING_MODE { \
    "CONFIG_LIDAR_WORKING_MODE", \
    1, \
    {  { "request_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_config_lidar_working_mode_t, request_type) }, \
         } \
}
#endif

/**
 * @brief Pack a config_lidar_working_mode message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param request_type  Types of operating modes for LiDAR.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_config_lidar_working_mode_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t request_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_LEN];
    _mav_put_uint8_t(buf, 0, request_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_LEN);
#else
    mavlink_config_lidar_working_mode_t packet;
    packet.request_type = request_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_MIN_LEN, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_LEN, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_CRC);
}

/**
 * @brief Pack a config_lidar_working_mode message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param request_type  Types of operating modes for LiDAR.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_config_lidar_working_mode_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t request_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_LEN];
    _mav_put_uint8_t(buf, 0, request_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_LEN);
#else
    mavlink_config_lidar_working_mode_t packet;
    packet.request_type = request_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_MIN_LEN, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_LEN, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_CRC);
}

/**
 * @brief Encode a config_lidar_working_mode struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param config_lidar_working_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_config_lidar_working_mode_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_config_lidar_working_mode_t* config_lidar_working_mode)
{
    return mavlink_msg_config_lidar_working_mode_pack(system_id, component_id, msg, config_lidar_working_mode->request_type);
}

/**
 * @brief Encode a config_lidar_working_mode struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param config_lidar_working_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_config_lidar_working_mode_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_config_lidar_working_mode_t* config_lidar_working_mode)
{
    return mavlink_msg_config_lidar_working_mode_pack_chan(system_id, component_id, chan, msg, config_lidar_working_mode->request_type);
}

/**
 * @brief Send a config_lidar_working_mode message
 * @param chan MAVLink channel to send the message
 *
 * @param request_type  Types of operating modes for LiDAR.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_config_lidar_working_mode_send(mavlink_channel_t chan, uint8_t request_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_LEN];
    _mav_put_uint8_t(buf, 0, request_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE, buf, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_MIN_LEN, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_LEN, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_CRC);
#else
    mavlink_config_lidar_working_mode_t packet;
    packet.request_type = request_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE, (const char *)&packet, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_MIN_LEN, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_LEN, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_CRC);
#endif
}

/**
 * @brief Send a config_lidar_working_mode message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_config_lidar_working_mode_send_struct(mavlink_channel_t chan, const mavlink_config_lidar_working_mode_t* config_lidar_working_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_config_lidar_working_mode_send(chan, config_lidar_working_mode->request_type);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE, (const char *)config_lidar_working_mode, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_MIN_LEN, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_LEN, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_CRC);
#endif
}

#if MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_config_lidar_working_mode_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t request_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, request_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE, buf, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_MIN_LEN, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_LEN, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_CRC);
#else
    mavlink_config_lidar_working_mode_t *packet = (mavlink_config_lidar_working_mode_t *)msgbuf;
    packet->request_type = request_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE, (const char *)packet, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_MIN_LEN, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_LEN, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_CRC);
#endif
}
#endif

#endif

// MESSAGE CONFIG_LIDAR_WORKING_MODE UNPACKING


/**
 * @brief Get field request_type from config_lidar_working_mode message
 *
 * @return  Types of operating modes for LiDAR.
 */
static inline uint8_t mavlink_msg_config_lidar_working_mode_get_request_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a config_lidar_working_mode message into a struct
 *
 * @param msg The message to decode
 * @param config_lidar_working_mode C-struct to decode the message contents into
 */
static inline void mavlink_msg_config_lidar_working_mode_decode(const mavlink_message_t* msg, mavlink_config_lidar_working_mode_t* config_lidar_working_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    config_lidar_working_mode->request_type = mavlink_msg_config_lidar_working_mode_get_request_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_LEN? msg->len : MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_LEN;
        memset(config_lidar_working_mode, 0, MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_LEN);
    memcpy(config_lidar_working_mode, _MAV_PAYLOAD(msg), len);
#endif
}
