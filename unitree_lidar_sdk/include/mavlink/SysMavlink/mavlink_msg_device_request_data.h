#pragma once
// MESSAGE DEVICE_REQUEST_DATA PACKING

#define MAVLINK_MSG_ID_DEVICE_REQUEST_DATA 11


typedef struct __mavlink_device_request_data_t {
 uint8_t request_type; /*<  Type of the needed data*/
} mavlink_device_request_data_t;

#define MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_LEN 1
#define MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_MIN_LEN 1
#define MAVLINK_MSG_ID_11_LEN 1
#define MAVLINK_MSG_ID_11_MIN_LEN 1

#define MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_CRC 106
#define MAVLINK_MSG_ID_11_CRC 106



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DEVICE_REQUEST_DATA { \
    11, \
    "DEVICE_REQUEST_DATA", \
    1, \
    {  { "request_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_device_request_data_t, request_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DEVICE_REQUEST_DATA { \
    "DEVICE_REQUEST_DATA", \
    1, \
    {  { "request_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_device_request_data_t, request_type) }, \
         } \
}
#endif

/**
 * @brief Pack a device_request_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param request_type  Type of the needed data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_device_request_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t request_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_LEN];
    _mav_put_uint8_t(buf, 0, request_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_LEN);
#else
    mavlink_device_request_data_t packet;
    packet.request_type = request_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DEVICE_REQUEST_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_MIN_LEN, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_LEN, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_CRC);
}

/**
 * @brief Pack a device_request_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param request_type  Type of the needed data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_device_request_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t request_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_LEN];
    _mav_put_uint8_t(buf, 0, request_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_LEN);
#else
    mavlink_device_request_data_t packet;
    packet.request_type = request_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DEVICE_REQUEST_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_MIN_LEN, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_LEN, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_CRC);
}

/**
 * @brief Encode a device_request_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param device_request_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_device_request_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_device_request_data_t* device_request_data)
{
    return mavlink_msg_device_request_data_pack(system_id, component_id, msg, device_request_data->request_type);
}

/**
 * @brief Encode a device_request_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param device_request_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_device_request_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_device_request_data_t* device_request_data)
{
    return mavlink_msg_device_request_data_pack_chan(system_id, component_id, chan, msg, device_request_data->request_type);
}

/**
 * @brief Send a device_request_data message
 * @param chan MAVLink channel to send the message
 *
 * @param request_type  Type of the needed data
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_device_request_data_send(mavlink_channel_t chan, uint8_t request_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_LEN];
    _mav_put_uint8_t(buf, 0, request_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA, buf, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_MIN_LEN, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_LEN, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_CRC);
#else
    mavlink_device_request_data_t packet;
    packet.request_type = request_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA, (const char *)&packet, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_MIN_LEN, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_LEN, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_CRC);
#endif
}

/**
 * @brief Send a device_request_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_device_request_data_send_struct(mavlink_channel_t chan, const mavlink_device_request_data_t* device_request_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_device_request_data_send(chan, device_request_data->request_type);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA, (const char *)device_request_data, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_MIN_LEN, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_LEN, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_device_request_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t request_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, request_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA, buf, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_MIN_LEN, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_LEN, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_CRC);
#else
    mavlink_device_request_data_t *packet = (mavlink_device_request_data_t *)msgbuf;
    packet->request_type = request_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA, (const char *)packet, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_MIN_LEN, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_LEN, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE DEVICE_REQUEST_DATA UNPACKING


/**
 * @brief Get field request_type from device_request_data message
 *
 * @return  Type of the needed data
 */
static inline uint8_t mavlink_msg_device_request_data_get_request_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a device_request_data message into a struct
 *
 * @param msg The message to decode
 * @param device_request_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_device_request_data_decode(const mavlink_message_t* msg, mavlink_device_request_data_t* device_request_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    device_request_data->request_type = mavlink_msg_device_request_data_get_request_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_LEN? msg->len : MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_LEN;
        memset(device_request_data, 0, MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_LEN);
    memcpy(device_request_data, _MAV_PAYLOAD(msg), len);
#endif
}
