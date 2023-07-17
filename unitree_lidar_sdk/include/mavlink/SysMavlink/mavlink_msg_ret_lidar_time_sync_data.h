#pragma once
// MESSAGE RET_LIDAR_TIME_SYNC_DATA PACKING

#define MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA 18


typedef struct __mavlink_ret_lidar_time_sync_data_t {
 uint32_t lidar_sync_count; /*<  Time synchronization packet count.*/
 uint8_t lidar_sync_type; /*<  Time synchronization packet type.*/
} mavlink_ret_lidar_time_sync_data_t;

#define MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_LEN 5
#define MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_MIN_LEN 5
#define MAVLINK_MSG_ID_18_LEN 5
#define MAVLINK_MSG_ID_18_MIN_LEN 5

#define MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_CRC 12
#define MAVLINK_MSG_ID_18_CRC 12



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RET_LIDAR_TIME_SYNC_DATA { \
    18, \
    "RET_LIDAR_TIME_SYNC_DATA", \
    2, \
    {  { "lidar_sync_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_ret_lidar_time_sync_data_t, lidar_sync_type) }, \
         { "lidar_sync_count", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ret_lidar_time_sync_data_t, lidar_sync_count) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RET_LIDAR_TIME_SYNC_DATA { \
    "RET_LIDAR_TIME_SYNC_DATA", \
    2, \
    {  { "lidar_sync_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_ret_lidar_time_sync_data_t, lidar_sync_type) }, \
         { "lidar_sync_count", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ret_lidar_time_sync_data_t, lidar_sync_count) }, \
         } \
}
#endif

/**
 * @brief Pack a ret_lidar_time_sync_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param lidar_sync_type  Time synchronization packet type.
 * @param lidar_sync_count  Time synchronization packet count.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ret_lidar_time_sync_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t lidar_sync_type, uint32_t lidar_sync_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_LEN];
    _mav_put_uint32_t(buf, 0, lidar_sync_count);
    _mav_put_uint8_t(buf, 4, lidar_sync_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_LEN);
#else
    mavlink_ret_lidar_time_sync_data_t packet;
    packet.lidar_sync_count = lidar_sync_count;
    packet.lidar_sync_type = lidar_sync_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_LEN, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_CRC);
}

/**
 * @brief Pack a ret_lidar_time_sync_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lidar_sync_type  Time synchronization packet type.
 * @param lidar_sync_count  Time synchronization packet count.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ret_lidar_time_sync_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t lidar_sync_type,uint32_t lidar_sync_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_LEN];
    _mav_put_uint32_t(buf, 0, lidar_sync_count);
    _mav_put_uint8_t(buf, 4, lidar_sync_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_LEN);
#else
    mavlink_ret_lidar_time_sync_data_t packet;
    packet.lidar_sync_count = lidar_sync_count;
    packet.lidar_sync_type = lidar_sync_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_LEN, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_CRC);
}

/**
 * @brief Encode a ret_lidar_time_sync_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ret_lidar_time_sync_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ret_lidar_time_sync_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ret_lidar_time_sync_data_t* ret_lidar_time_sync_data)
{
    return mavlink_msg_ret_lidar_time_sync_data_pack(system_id, component_id, msg, ret_lidar_time_sync_data->lidar_sync_type, ret_lidar_time_sync_data->lidar_sync_count);
}

/**
 * @brief Encode a ret_lidar_time_sync_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ret_lidar_time_sync_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ret_lidar_time_sync_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ret_lidar_time_sync_data_t* ret_lidar_time_sync_data)
{
    return mavlink_msg_ret_lidar_time_sync_data_pack_chan(system_id, component_id, chan, msg, ret_lidar_time_sync_data->lidar_sync_type, ret_lidar_time_sync_data->lidar_sync_count);
}

/**
 * @brief Send a ret_lidar_time_sync_data message
 * @param chan MAVLink channel to send the message
 *
 * @param lidar_sync_type  Time synchronization packet type.
 * @param lidar_sync_count  Time synchronization packet count.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ret_lidar_time_sync_data_send(mavlink_channel_t chan, uint8_t lidar_sync_type, uint32_t lidar_sync_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_LEN];
    _mav_put_uint32_t(buf, 0, lidar_sync_count);
    _mav_put_uint8_t(buf, 4, lidar_sync_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA, buf, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_LEN, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_CRC);
#else
    mavlink_ret_lidar_time_sync_data_t packet;
    packet.lidar_sync_count = lidar_sync_count;
    packet.lidar_sync_type = lidar_sync_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA, (const char *)&packet, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_LEN, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_CRC);
#endif
}

/**
 * @brief Send a ret_lidar_time_sync_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ret_lidar_time_sync_data_send_struct(mavlink_channel_t chan, const mavlink_ret_lidar_time_sync_data_t* ret_lidar_time_sync_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ret_lidar_time_sync_data_send(chan, ret_lidar_time_sync_data->lidar_sync_type, ret_lidar_time_sync_data->lidar_sync_count);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA, (const char *)ret_lidar_time_sync_data, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_LEN, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ret_lidar_time_sync_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t lidar_sync_type, uint32_t lidar_sync_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, lidar_sync_count);
    _mav_put_uint8_t(buf, 4, lidar_sync_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA, buf, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_LEN, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_CRC);
#else
    mavlink_ret_lidar_time_sync_data_t *packet = (mavlink_ret_lidar_time_sync_data_t *)msgbuf;
    packet->lidar_sync_count = lidar_sync_count;
    packet->lidar_sync_type = lidar_sync_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA, (const char *)packet, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_LEN, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE RET_LIDAR_TIME_SYNC_DATA UNPACKING


/**
 * @brief Get field lidar_sync_type from ret_lidar_time_sync_data message
 *
 * @return  Time synchronization packet type.
 */
static inline uint8_t mavlink_msg_ret_lidar_time_sync_data_get_lidar_sync_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field lidar_sync_count from ret_lidar_time_sync_data message
 *
 * @return  Time synchronization packet count.
 */
static inline uint32_t mavlink_msg_ret_lidar_time_sync_data_get_lidar_sync_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a ret_lidar_time_sync_data message into a struct
 *
 * @param msg The message to decode
 * @param ret_lidar_time_sync_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_ret_lidar_time_sync_data_decode(const mavlink_message_t* msg, mavlink_ret_lidar_time_sync_data_t* ret_lidar_time_sync_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ret_lidar_time_sync_data->lidar_sync_count = mavlink_msg_ret_lidar_time_sync_data_get_lidar_sync_count(msg);
    ret_lidar_time_sync_data->lidar_sync_type = mavlink_msg_ret_lidar_time_sync_data_get_lidar_sync_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_LEN? msg->len : MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_LEN;
        memset(ret_lidar_time_sync_data, 0, MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_LEN);
    memcpy(ret_lidar_time_sync_data, _MAV_PAYLOAD(msg), len);
#endif
}
