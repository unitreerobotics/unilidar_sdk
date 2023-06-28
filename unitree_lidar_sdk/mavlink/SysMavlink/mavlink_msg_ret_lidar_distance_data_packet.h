#pragma once
// MESSAGE RET_LIDAR_DISTANCE_DATA_PACKET PACKING

#define MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET 16


typedef struct __mavlink_ret_lidar_distance_data_packet_t {
 uint16_t packet_id; /*<  Data packet ID.*/
 uint16_t packet_cnt; /*<  Data packet count.*/
 uint16_t payload_size; /*<  Data packet payload size.*/
 uint8_t point_data[240]; /*<  Data packet distance data.*/
} mavlink_ret_lidar_distance_data_packet_t;

#define MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_LEN 246
#define MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_MIN_LEN 246
#define MAVLINK_MSG_ID_16_LEN 246
#define MAVLINK_MSG_ID_16_MIN_LEN 246

#define MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_CRC 74
#define MAVLINK_MSG_ID_16_CRC 74

#define MAVLINK_MSG_RET_LIDAR_DISTANCE_DATA_PACKET_FIELD_POINT_DATA_LEN 240

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RET_LIDAR_DISTANCE_DATA_PACKET { \
    16, \
    "RET_LIDAR_DISTANCE_DATA_PACKET", \
    4, \
    {  { "packet_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_ret_lidar_distance_data_packet_t, packet_id) }, \
         { "packet_cnt", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_ret_lidar_distance_data_packet_t, packet_cnt) }, \
         { "payload_size", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_ret_lidar_distance_data_packet_t, payload_size) }, \
         { "point_data", NULL, MAVLINK_TYPE_UINT8_T, 240, 6, offsetof(mavlink_ret_lidar_distance_data_packet_t, point_data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RET_LIDAR_DISTANCE_DATA_PACKET { \
    "RET_LIDAR_DISTANCE_DATA_PACKET", \
    4, \
    {  { "packet_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_ret_lidar_distance_data_packet_t, packet_id) }, \
         { "packet_cnt", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_ret_lidar_distance_data_packet_t, packet_cnt) }, \
         { "payload_size", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_ret_lidar_distance_data_packet_t, payload_size) }, \
         { "point_data", NULL, MAVLINK_TYPE_UINT8_T, 240, 6, offsetof(mavlink_ret_lidar_distance_data_packet_t, point_data) }, \
         } \
}
#endif

/**
 * @brief Pack a ret_lidar_distance_data_packet message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param packet_id  Data packet ID.
 * @param packet_cnt  Data packet count.
 * @param payload_size  Data packet payload size.
 * @param point_data  Data packet distance data.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ret_lidar_distance_data_packet_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t packet_id, uint16_t packet_cnt, uint16_t payload_size, const uint8_t *point_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_LEN];
    _mav_put_uint16_t(buf, 0, packet_id);
    _mav_put_uint16_t(buf, 2, packet_cnt);
    _mav_put_uint16_t(buf, 4, payload_size);
    _mav_put_uint8_t_array(buf, 6, point_data, 240);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_LEN);
#else
    mavlink_ret_lidar_distance_data_packet_t packet;
    packet.packet_id = packet_id;
    packet.packet_cnt = packet_cnt;
    packet.payload_size = payload_size;
    mav_array_memcpy(packet.point_data, point_data, sizeof(uint8_t)*240);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_CRC);
}

/**
 * @brief Pack a ret_lidar_distance_data_packet message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param packet_id  Data packet ID.
 * @param packet_cnt  Data packet count.
 * @param payload_size  Data packet payload size.
 * @param point_data  Data packet distance data.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ret_lidar_distance_data_packet_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t packet_id,uint16_t packet_cnt,uint16_t payload_size,const uint8_t *point_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_LEN];
    _mav_put_uint16_t(buf, 0, packet_id);
    _mav_put_uint16_t(buf, 2, packet_cnt);
    _mav_put_uint16_t(buf, 4, payload_size);
    _mav_put_uint8_t_array(buf, 6, point_data, 240);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_LEN);
#else
    mavlink_ret_lidar_distance_data_packet_t packet;
    packet.packet_id = packet_id;
    packet.packet_cnt = packet_cnt;
    packet.payload_size = payload_size;
    mav_array_memcpy(packet.point_data, point_data, sizeof(uint8_t)*240);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_CRC);
}

/**
 * @brief Encode a ret_lidar_distance_data_packet struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ret_lidar_distance_data_packet C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ret_lidar_distance_data_packet_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ret_lidar_distance_data_packet_t* ret_lidar_distance_data_packet)
{
    return mavlink_msg_ret_lidar_distance_data_packet_pack(system_id, component_id, msg, ret_lidar_distance_data_packet->packet_id, ret_lidar_distance_data_packet->packet_cnt, ret_lidar_distance_data_packet->payload_size, ret_lidar_distance_data_packet->point_data);
}

/**
 * @brief Encode a ret_lidar_distance_data_packet struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ret_lidar_distance_data_packet C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ret_lidar_distance_data_packet_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ret_lidar_distance_data_packet_t* ret_lidar_distance_data_packet)
{
    return mavlink_msg_ret_lidar_distance_data_packet_pack_chan(system_id, component_id, chan, msg, ret_lidar_distance_data_packet->packet_id, ret_lidar_distance_data_packet->packet_cnt, ret_lidar_distance_data_packet->payload_size, ret_lidar_distance_data_packet->point_data);
}

/**
 * @brief Send a ret_lidar_distance_data_packet message
 * @param chan MAVLink channel to send the message
 *
 * @param packet_id  Data packet ID.
 * @param packet_cnt  Data packet count.
 * @param payload_size  Data packet payload size.
 * @param point_data  Data packet distance data.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ret_lidar_distance_data_packet_send(mavlink_channel_t chan, uint16_t packet_id, uint16_t packet_cnt, uint16_t payload_size, const uint8_t *point_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_LEN];
    _mav_put_uint16_t(buf, 0, packet_id);
    _mav_put_uint16_t(buf, 2, packet_cnt);
    _mav_put_uint16_t(buf, 4, payload_size);
    _mav_put_uint8_t_array(buf, 6, point_data, 240);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET, buf, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_CRC);
#else
    mavlink_ret_lidar_distance_data_packet_t packet;
    packet.packet_id = packet_id;
    packet.packet_cnt = packet_cnt;
    packet.payload_size = payload_size;
    mav_array_memcpy(packet.point_data, point_data, sizeof(uint8_t)*240);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET, (const char *)&packet, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_CRC);
#endif
}

/**
 * @brief Send a ret_lidar_distance_data_packet message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ret_lidar_distance_data_packet_send_struct(mavlink_channel_t chan, const mavlink_ret_lidar_distance_data_packet_t* ret_lidar_distance_data_packet)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ret_lidar_distance_data_packet_send(chan, ret_lidar_distance_data_packet->packet_id, ret_lidar_distance_data_packet->packet_cnt, ret_lidar_distance_data_packet->payload_size, ret_lidar_distance_data_packet->point_data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET, (const char *)ret_lidar_distance_data_packet, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_CRC);
#endif
}

#if MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ret_lidar_distance_data_packet_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t packet_id, uint16_t packet_cnt, uint16_t payload_size, const uint8_t *point_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, packet_id);
    _mav_put_uint16_t(buf, 2, packet_cnt);
    _mav_put_uint16_t(buf, 4, payload_size);
    _mav_put_uint8_t_array(buf, 6, point_data, 240);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET, buf, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_CRC);
#else
    mavlink_ret_lidar_distance_data_packet_t *packet = (mavlink_ret_lidar_distance_data_packet_t *)msgbuf;
    packet->packet_id = packet_id;
    packet->packet_cnt = packet_cnt;
    packet->payload_size = payload_size;
    mav_array_memcpy(packet->point_data, point_data, sizeof(uint8_t)*240);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET, (const char *)packet, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_LEN, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_CRC);
#endif
}
#endif

#endif

// MESSAGE RET_LIDAR_DISTANCE_DATA_PACKET UNPACKING


/**
 * @brief Get field packet_id from ret_lidar_distance_data_packet message
 *
 * @return  Data packet ID.
 */
static inline uint16_t mavlink_msg_ret_lidar_distance_data_packet_get_packet_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field packet_cnt from ret_lidar_distance_data_packet message
 *
 * @return  Data packet count.
 */
static inline uint16_t mavlink_msg_ret_lidar_distance_data_packet_get_packet_cnt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field payload_size from ret_lidar_distance_data_packet message
 *
 * @return  Data packet payload size.
 */
static inline uint16_t mavlink_msg_ret_lidar_distance_data_packet_get_payload_size(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field point_data from ret_lidar_distance_data_packet message
 *
 * @return  Data packet distance data.
 */
static inline uint16_t mavlink_msg_ret_lidar_distance_data_packet_get_point_data(const mavlink_message_t* msg, uint8_t *point_data)
{
    return _MAV_RETURN_uint8_t_array(msg, point_data, 240,  6);
}

/**
 * @brief Decode a ret_lidar_distance_data_packet message into a struct
 *
 * @param msg The message to decode
 * @param ret_lidar_distance_data_packet C-struct to decode the message contents into
 */
static inline void mavlink_msg_ret_lidar_distance_data_packet_decode(const mavlink_message_t* msg, mavlink_ret_lidar_distance_data_packet_t* ret_lidar_distance_data_packet)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ret_lidar_distance_data_packet->packet_id = mavlink_msg_ret_lidar_distance_data_packet_get_packet_id(msg);
    ret_lidar_distance_data_packet->packet_cnt = mavlink_msg_ret_lidar_distance_data_packet_get_packet_cnt(msg);
    ret_lidar_distance_data_packet->payload_size = mavlink_msg_ret_lidar_distance_data_packet_get_payload_size(msg);
    mavlink_msg_ret_lidar_distance_data_packet_get_point_data(msg, ret_lidar_distance_data_packet->point_data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_LEN? msg->len : MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_LEN;
        memset(ret_lidar_distance_data_packet, 0, MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_LEN);
    memcpy(ret_lidar_distance_data_packet, _MAV_PAYLOAD(msg), len);
#endif
}
