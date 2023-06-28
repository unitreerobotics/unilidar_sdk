#pragma once
// MESSAGE RET_LIDAR_VERSION PACKING

#define MAVLINK_MSG_ID_RET_LIDAR_VERSION 13


typedef struct __mavlink_ret_lidar_version_t {
 uint8_t sys_soft_version[13]; /*<  SYS board soft version.*/
 uint8_t com_soft_version[13]; /*<  COM board soft version.*/
 uint8_t sys_hard_version[6]; /*<  SYS board hard version.*/
 uint8_t com_hard_version[6]; /*<  COM board hard version.*/
} mavlink_ret_lidar_version_t;

#define MAVLINK_MSG_ID_RET_LIDAR_VERSION_LEN 38
#define MAVLINK_MSG_ID_RET_LIDAR_VERSION_MIN_LEN 38
#define MAVLINK_MSG_ID_13_LEN 38
#define MAVLINK_MSG_ID_13_MIN_LEN 38

#define MAVLINK_MSG_ID_RET_LIDAR_VERSION_CRC 62
#define MAVLINK_MSG_ID_13_CRC 62

#define MAVLINK_MSG_RET_LIDAR_VERSION_FIELD_SYS_SOFT_VERSION_LEN 13
#define MAVLINK_MSG_RET_LIDAR_VERSION_FIELD_COM_SOFT_VERSION_LEN 13
#define MAVLINK_MSG_RET_LIDAR_VERSION_FIELD_SYS_HARD_VERSION_LEN 6
#define MAVLINK_MSG_RET_LIDAR_VERSION_FIELD_COM_HARD_VERSION_LEN 6

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RET_LIDAR_VERSION { \
    13, \
    "RET_LIDAR_VERSION", \
    4, \
    {  { "sys_soft_version", NULL, MAVLINK_TYPE_UINT8_T, 13, 0, offsetof(mavlink_ret_lidar_version_t, sys_soft_version) }, \
         { "com_soft_version", NULL, MAVLINK_TYPE_UINT8_T, 13, 13, offsetof(mavlink_ret_lidar_version_t, com_soft_version) }, \
         { "sys_hard_version", NULL, MAVLINK_TYPE_UINT8_T, 6, 26, offsetof(mavlink_ret_lidar_version_t, sys_hard_version) }, \
         { "com_hard_version", NULL, MAVLINK_TYPE_UINT8_T, 6, 32, offsetof(mavlink_ret_lidar_version_t, com_hard_version) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RET_LIDAR_VERSION { \
    "RET_LIDAR_VERSION", \
    4, \
    {  { "sys_soft_version", NULL, MAVLINK_TYPE_UINT8_T, 13, 0, offsetof(mavlink_ret_lidar_version_t, sys_soft_version) }, \
         { "com_soft_version", NULL, MAVLINK_TYPE_UINT8_T, 13, 13, offsetof(mavlink_ret_lidar_version_t, com_soft_version) }, \
         { "sys_hard_version", NULL, MAVLINK_TYPE_UINT8_T, 6, 26, offsetof(mavlink_ret_lidar_version_t, sys_hard_version) }, \
         { "com_hard_version", NULL, MAVLINK_TYPE_UINT8_T, 6, 32, offsetof(mavlink_ret_lidar_version_t, com_hard_version) }, \
         } \
}
#endif

/**
 * @brief Pack a ret_lidar_version message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param sys_soft_version  SYS board soft version.
 * @param com_soft_version  COM board soft version.
 * @param sys_hard_version  SYS board hard version.
 * @param com_hard_version  COM board hard version.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ret_lidar_version_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const uint8_t *sys_soft_version, const uint8_t *com_soft_version, const uint8_t *sys_hard_version, const uint8_t *com_hard_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RET_LIDAR_VERSION_LEN];

    _mav_put_uint8_t_array(buf, 0, sys_soft_version, 13);
    _mav_put_uint8_t_array(buf, 13, com_soft_version, 13);
    _mav_put_uint8_t_array(buf, 26, sys_hard_version, 6);
    _mav_put_uint8_t_array(buf, 32, com_hard_version, 6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RET_LIDAR_VERSION_LEN);
#else
    mavlink_ret_lidar_version_t packet;

    mav_array_memcpy(packet.sys_soft_version, sys_soft_version, sizeof(uint8_t)*13);
    mav_array_memcpy(packet.com_soft_version, com_soft_version, sizeof(uint8_t)*13);
    mav_array_memcpy(packet.sys_hard_version, sys_hard_version, sizeof(uint8_t)*6);
    mav_array_memcpy(packet.com_hard_version, com_hard_version, sizeof(uint8_t)*6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RET_LIDAR_VERSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RET_LIDAR_VERSION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RET_LIDAR_VERSION_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_VERSION_LEN, MAVLINK_MSG_ID_RET_LIDAR_VERSION_CRC);
}

/**
 * @brief Pack a ret_lidar_version message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sys_soft_version  SYS board soft version.
 * @param com_soft_version  COM board soft version.
 * @param sys_hard_version  SYS board hard version.
 * @param com_hard_version  COM board hard version.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ret_lidar_version_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const uint8_t *sys_soft_version,const uint8_t *com_soft_version,const uint8_t *sys_hard_version,const uint8_t *com_hard_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RET_LIDAR_VERSION_LEN];

    _mav_put_uint8_t_array(buf, 0, sys_soft_version, 13);
    _mav_put_uint8_t_array(buf, 13, com_soft_version, 13);
    _mav_put_uint8_t_array(buf, 26, sys_hard_version, 6);
    _mav_put_uint8_t_array(buf, 32, com_hard_version, 6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RET_LIDAR_VERSION_LEN);
#else
    mavlink_ret_lidar_version_t packet;

    mav_array_memcpy(packet.sys_soft_version, sys_soft_version, sizeof(uint8_t)*13);
    mav_array_memcpy(packet.com_soft_version, com_soft_version, sizeof(uint8_t)*13);
    mav_array_memcpy(packet.sys_hard_version, sys_hard_version, sizeof(uint8_t)*6);
    mav_array_memcpy(packet.com_hard_version, com_hard_version, sizeof(uint8_t)*6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RET_LIDAR_VERSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RET_LIDAR_VERSION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RET_LIDAR_VERSION_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_VERSION_LEN, MAVLINK_MSG_ID_RET_LIDAR_VERSION_CRC);
}

/**
 * @brief Encode a ret_lidar_version struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ret_lidar_version C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ret_lidar_version_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ret_lidar_version_t* ret_lidar_version)
{
    return mavlink_msg_ret_lidar_version_pack(system_id, component_id, msg, ret_lidar_version->sys_soft_version, ret_lidar_version->com_soft_version, ret_lidar_version->sys_hard_version, ret_lidar_version->com_hard_version);
}

/**
 * @brief Encode a ret_lidar_version struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ret_lidar_version C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ret_lidar_version_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ret_lidar_version_t* ret_lidar_version)
{
    return mavlink_msg_ret_lidar_version_pack_chan(system_id, component_id, chan, msg, ret_lidar_version->sys_soft_version, ret_lidar_version->com_soft_version, ret_lidar_version->sys_hard_version, ret_lidar_version->com_hard_version);
}

/**
 * @brief Send a ret_lidar_version message
 * @param chan MAVLink channel to send the message
 *
 * @param sys_soft_version  SYS board soft version.
 * @param com_soft_version  COM board soft version.
 * @param sys_hard_version  SYS board hard version.
 * @param com_hard_version  COM board hard version.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ret_lidar_version_send(mavlink_channel_t chan, const uint8_t *sys_soft_version, const uint8_t *com_soft_version, const uint8_t *sys_hard_version, const uint8_t *com_hard_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RET_LIDAR_VERSION_LEN];

    _mav_put_uint8_t_array(buf, 0, sys_soft_version, 13);
    _mav_put_uint8_t_array(buf, 13, com_soft_version, 13);
    _mav_put_uint8_t_array(buf, 26, sys_hard_version, 6);
    _mav_put_uint8_t_array(buf, 32, com_hard_version, 6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_VERSION, buf, MAVLINK_MSG_ID_RET_LIDAR_VERSION_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_VERSION_LEN, MAVLINK_MSG_ID_RET_LIDAR_VERSION_CRC);
#else
    mavlink_ret_lidar_version_t packet;

    mav_array_memcpy(packet.sys_soft_version, sys_soft_version, sizeof(uint8_t)*13);
    mav_array_memcpy(packet.com_soft_version, com_soft_version, sizeof(uint8_t)*13);
    mav_array_memcpy(packet.sys_hard_version, sys_hard_version, sizeof(uint8_t)*6);
    mav_array_memcpy(packet.com_hard_version, com_hard_version, sizeof(uint8_t)*6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_VERSION, (const char *)&packet, MAVLINK_MSG_ID_RET_LIDAR_VERSION_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_VERSION_LEN, MAVLINK_MSG_ID_RET_LIDAR_VERSION_CRC);
#endif
}

/**
 * @brief Send a ret_lidar_version message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ret_lidar_version_send_struct(mavlink_channel_t chan, const mavlink_ret_lidar_version_t* ret_lidar_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ret_lidar_version_send(chan, ret_lidar_version->sys_soft_version, ret_lidar_version->com_soft_version, ret_lidar_version->sys_hard_version, ret_lidar_version->com_hard_version);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_VERSION, (const char *)ret_lidar_version, MAVLINK_MSG_ID_RET_LIDAR_VERSION_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_VERSION_LEN, MAVLINK_MSG_ID_RET_LIDAR_VERSION_CRC);
#endif
}

#if MAVLINK_MSG_ID_RET_LIDAR_VERSION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ret_lidar_version_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint8_t *sys_soft_version, const uint8_t *com_soft_version, const uint8_t *sys_hard_version, const uint8_t *com_hard_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_uint8_t_array(buf, 0, sys_soft_version, 13);
    _mav_put_uint8_t_array(buf, 13, com_soft_version, 13);
    _mav_put_uint8_t_array(buf, 26, sys_hard_version, 6);
    _mav_put_uint8_t_array(buf, 32, com_hard_version, 6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_VERSION, buf, MAVLINK_MSG_ID_RET_LIDAR_VERSION_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_VERSION_LEN, MAVLINK_MSG_ID_RET_LIDAR_VERSION_CRC);
#else
    mavlink_ret_lidar_version_t *packet = (mavlink_ret_lidar_version_t *)msgbuf;

    mav_array_memcpy(packet->sys_soft_version, sys_soft_version, sizeof(uint8_t)*13);
    mav_array_memcpy(packet->com_soft_version, com_soft_version, sizeof(uint8_t)*13);
    mav_array_memcpy(packet->sys_hard_version, sys_hard_version, sizeof(uint8_t)*6);
    mav_array_memcpy(packet->com_hard_version, com_hard_version, sizeof(uint8_t)*6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RET_LIDAR_VERSION, (const char *)packet, MAVLINK_MSG_ID_RET_LIDAR_VERSION_MIN_LEN, MAVLINK_MSG_ID_RET_LIDAR_VERSION_LEN, MAVLINK_MSG_ID_RET_LIDAR_VERSION_CRC);
#endif
}
#endif

#endif

// MESSAGE RET_LIDAR_VERSION UNPACKING


/**
 * @brief Get field sys_soft_version from ret_lidar_version message
 *
 * @return  SYS board soft version.
 */
static inline uint16_t mavlink_msg_ret_lidar_version_get_sys_soft_version(const mavlink_message_t* msg, uint8_t *sys_soft_version)
{
    return _MAV_RETURN_uint8_t_array(msg, sys_soft_version, 13,  0);
}

/**
 * @brief Get field com_soft_version from ret_lidar_version message
 *
 * @return  COM board soft version.
 */
static inline uint16_t mavlink_msg_ret_lidar_version_get_com_soft_version(const mavlink_message_t* msg, uint8_t *com_soft_version)
{
    return _MAV_RETURN_uint8_t_array(msg, com_soft_version, 13,  13);
}

/**
 * @brief Get field sys_hard_version from ret_lidar_version message
 *
 * @return  SYS board hard version.
 */
static inline uint16_t mavlink_msg_ret_lidar_version_get_sys_hard_version(const mavlink_message_t* msg, uint8_t *sys_hard_version)
{
    return _MAV_RETURN_uint8_t_array(msg, sys_hard_version, 6,  26);
}

/**
 * @brief Get field com_hard_version from ret_lidar_version message
 *
 * @return  COM board hard version.
 */
static inline uint16_t mavlink_msg_ret_lidar_version_get_com_hard_version(const mavlink_message_t* msg, uint8_t *com_hard_version)
{
    return _MAV_RETURN_uint8_t_array(msg, com_hard_version, 6,  32);
}

/**
 * @brief Decode a ret_lidar_version message into a struct
 *
 * @param msg The message to decode
 * @param ret_lidar_version C-struct to decode the message contents into
 */
static inline void mavlink_msg_ret_lidar_version_decode(const mavlink_message_t* msg, mavlink_ret_lidar_version_t* ret_lidar_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ret_lidar_version_get_sys_soft_version(msg, ret_lidar_version->sys_soft_version);
    mavlink_msg_ret_lidar_version_get_com_soft_version(msg, ret_lidar_version->com_soft_version);
    mavlink_msg_ret_lidar_version_get_sys_hard_version(msg, ret_lidar_version->sys_hard_version);
    mavlink_msg_ret_lidar_version_get_com_hard_version(msg, ret_lidar_version->com_hard_version);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RET_LIDAR_VERSION_LEN? msg->len : MAVLINK_MSG_ID_RET_LIDAR_VERSION_LEN;
        memset(ret_lidar_version, 0, MAVLINK_MSG_ID_RET_LIDAR_VERSION_LEN);
    memcpy(ret_lidar_version, _MAV_PAYLOAD(msg), len);
#endif
}
