#pragma once
// MESSAGE CONFIG_LED_RING_TABLE_PACKET PACKING

#define MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET 15


typedef struct __mavlink_config_led_ring_table_packet_t {
 uint32_t led_rotation_period; /*<  Rotation period.*/
 uint32_t led_zero_point_offset; /*<  Zero offset unit in milliseconds.*/
 uint16_t packet_id; /*<  Data packet ID.*/
 uint8_t led_display_mode; /*<  LED display mode selection.*/
 uint8_t led_table[45]; /*<  LED display field data packet, 45 bytes represent the status of 360 LEDs bit by bit.*/
} mavlink_config_led_ring_table_packet_t;

#define MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_LEN 56
#define MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_MIN_LEN 56
#define MAVLINK_MSG_ID_15_LEN 56
#define MAVLINK_MSG_ID_15_MIN_LEN 56

#define MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_CRC 236
#define MAVLINK_MSG_ID_15_CRC 236

#define MAVLINK_MSG_CONFIG_LED_RING_TABLE_PACKET_FIELD_LED_TABLE_LEN 45

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CONFIG_LED_RING_TABLE_PACKET { \
    15, \
    "CONFIG_LED_RING_TABLE_PACKET", \
    5, \
    {  { "packet_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_config_led_ring_table_packet_t, packet_id) }, \
         { "led_rotation_period", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_config_led_ring_table_packet_t, led_rotation_period) }, \
         { "led_zero_point_offset", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_config_led_ring_table_packet_t, led_zero_point_offset) }, \
         { "led_display_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_config_led_ring_table_packet_t, led_display_mode) }, \
         { "led_table", NULL, MAVLINK_TYPE_UINT8_T, 45, 11, offsetof(mavlink_config_led_ring_table_packet_t, led_table) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CONFIG_LED_RING_TABLE_PACKET { \
    "CONFIG_LED_RING_TABLE_PACKET", \
    5, \
    {  { "packet_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_config_led_ring_table_packet_t, packet_id) }, \
         { "led_rotation_period", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_config_led_ring_table_packet_t, led_rotation_period) }, \
         { "led_zero_point_offset", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_config_led_ring_table_packet_t, led_zero_point_offset) }, \
         { "led_display_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_config_led_ring_table_packet_t, led_display_mode) }, \
         { "led_table", NULL, MAVLINK_TYPE_UINT8_T, 45, 11, offsetof(mavlink_config_led_ring_table_packet_t, led_table) }, \
         } \
}
#endif

/**
 * @brief Pack a config_led_ring_table_packet message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param packet_id  Data packet ID.
 * @param led_rotation_period  Rotation period.
 * @param led_zero_point_offset  Zero offset unit in milliseconds.
 * @param led_display_mode  LED display mode selection.
 * @param led_table  LED display field data packet, 45 bytes represent the status of 360 LEDs bit by bit.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_config_led_ring_table_packet_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t packet_id, uint32_t led_rotation_period, uint32_t led_zero_point_offset, uint8_t led_display_mode, const uint8_t *led_table)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_LEN];
    _mav_put_uint32_t(buf, 0, led_rotation_period);
    _mav_put_uint32_t(buf, 4, led_zero_point_offset);
    _mav_put_uint16_t(buf, 8, packet_id);
    _mav_put_uint8_t(buf, 10, led_display_mode);
    _mav_put_uint8_t_array(buf, 11, led_table, 45);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_LEN);
#else
    mavlink_config_led_ring_table_packet_t packet;
    packet.led_rotation_period = led_rotation_period;
    packet.led_zero_point_offset = led_zero_point_offset;
    packet.packet_id = packet_id;
    packet.led_display_mode = led_display_mode;
    mav_array_memcpy(packet.led_table, led_table, sizeof(uint8_t)*45);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_MIN_LEN, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_LEN, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_CRC);
}

/**
 * @brief Pack a config_led_ring_table_packet message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param packet_id  Data packet ID.
 * @param led_rotation_period  Rotation period.
 * @param led_zero_point_offset  Zero offset unit in milliseconds.
 * @param led_display_mode  LED display mode selection.
 * @param led_table  LED display field data packet, 45 bytes represent the status of 360 LEDs bit by bit.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_config_led_ring_table_packet_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t packet_id,uint32_t led_rotation_period,uint32_t led_zero_point_offset,uint8_t led_display_mode,const uint8_t *led_table)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_LEN];
    _mav_put_uint32_t(buf, 0, led_rotation_period);
    _mav_put_uint32_t(buf, 4, led_zero_point_offset);
    _mav_put_uint16_t(buf, 8, packet_id);
    _mav_put_uint8_t(buf, 10, led_display_mode);
    _mav_put_uint8_t_array(buf, 11, led_table, 45);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_LEN);
#else
    mavlink_config_led_ring_table_packet_t packet;
    packet.led_rotation_period = led_rotation_period;
    packet.led_zero_point_offset = led_zero_point_offset;
    packet.packet_id = packet_id;
    packet.led_display_mode = led_display_mode;
    mav_array_memcpy(packet.led_table, led_table, sizeof(uint8_t)*45);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_MIN_LEN, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_LEN, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_CRC);
}

/**
 * @brief Encode a config_led_ring_table_packet struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param config_led_ring_table_packet C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_config_led_ring_table_packet_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_config_led_ring_table_packet_t* config_led_ring_table_packet)
{
    return mavlink_msg_config_led_ring_table_packet_pack(system_id, component_id, msg, config_led_ring_table_packet->packet_id, config_led_ring_table_packet->led_rotation_period, config_led_ring_table_packet->led_zero_point_offset, config_led_ring_table_packet->led_display_mode, config_led_ring_table_packet->led_table);
}

/**
 * @brief Encode a config_led_ring_table_packet struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param config_led_ring_table_packet C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_config_led_ring_table_packet_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_config_led_ring_table_packet_t* config_led_ring_table_packet)
{
    return mavlink_msg_config_led_ring_table_packet_pack_chan(system_id, component_id, chan, msg, config_led_ring_table_packet->packet_id, config_led_ring_table_packet->led_rotation_period, config_led_ring_table_packet->led_zero_point_offset, config_led_ring_table_packet->led_display_mode, config_led_ring_table_packet->led_table);
}

/**
 * @brief Send a config_led_ring_table_packet message
 * @param chan MAVLink channel to send the message
 *
 * @param packet_id  Data packet ID.
 * @param led_rotation_period  Rotation period.
 * @param led_zero_point_offset  Zero offset unit in milliseconds.
 * @param led_display_mode  LED display mode selection.
 * @param led_table  LED display field data packet, 45 bytes represent the status of 360 LEDs bit by bit.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_config_led_ring_table_packet_send(mavlink_channel_t chan, uint16_t packet_id, uint32_t led_rotation_period, uint32_t led_zero_point_offset, uint8_t led_display_mode, const uint8_t *led_table)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_LEN];
    _mav_put_uint32_t(buf, 0, led_rotation_period);
    _mav_put_uint32_t(buf, 4, led_zero_point_offset);
    _mav_put_uint16_t(buf, 8, packet_id);
    _mav_put_uint8_t(buf, 10, led_display_mode);
    _mav_put_uint8_t_array(buf, 11, led_table, 45);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET, buf, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_MIN_LEN, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_LEN, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_CRC);
#else
    mavlink_config_led_ring_table_packet_t packet;
    packet.led_rotation_period = led_rotation_period;
    packet.led_zero_point_offset = led_zero_point_offset;
    packet.packet_id = packet_id;
    packet.led_display_mode = led_display_mode;
    mav_array_memcpy(packet.led_table, led_table, sizeof(uint8_t)*45);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET, (const char *)&packet, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_MIN_LEN, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_LEN, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_CRC);
#endif
}

/**
 * @brief Send a config_led_ring_table_packet message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_config_led_ring_table_packet_send_struct(mavlink_channel_t chan, const mavlink_config_led_ring_table_packet_t* config_led_ring_table_packet)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_config_led_ring_table_packet_send(chan, config_led_ring_table_packet->packet_id, config_led_ring_table_packet->led_rotation_period, config_led_ring_table_packet->led_zero_point_offset, config_led_ring_table_packet->led_display_mode, config_led_ring_table_packet->led_table);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET, (const char *)config_led_ring_table_packet, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_MIN_LEN, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_LEN, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_CRC);
#endif
}

#if MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_config_led_ring_table_packet_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t packet_id, uint32_t led_rotation_period, uint32_t led_zero_point_offset, uint8_t led_display_mode, const uint8_t *led_table)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, led_rotation_period);
    _mav_put_uint32_t(buf, 4, led_zero_point_offset);
    _mav_put_uint16_t(buf, 8, packet_id);
    _mav_put_uint8_t(buf, 10, led_display_mode);
    _mav_put_uint8_t_array(buf, 11, led_table, 45);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET, buf, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_MIN_LEN, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_LEN, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_CRC);
#else
    mavlink_config_led_ring_table_packet_t *packet = (mavlink_config_led_ring_table_packet_t *)msgbuf;
    packet->led_rotation_period = led_rotation_period;
    packet->led_zero_point_offset = led_zero_point_offset;
    packet->packet_id = packet_id;
    packet->led_display_mode = led_display_mode;
    mav_array_memcpy(packet->led_table, led_table, sizeof(uint8_t)*45);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET, (const char *)packet, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_MIN_LEN, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_LEN, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_CRC);
#endif
}
#endif

#endif

// MESSAGE CONFIG_LED_RING_TABLE_PACKET UNPACKING


/**
 * @brief Get field packet_id from config_led_ring_table_packet message
 *
 * @return  Data packet ID.
 */
static inline uint16_t mavlink_msg_config_led_ring_table_packet_get_packet_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field led_rotation_period from config_led_ring_table_packet message
 *
 * @return  Rotation period.
 */
static inline uint32_t mavlink_msg_config_led_ring_table_packet_get_led_rotation_period(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field led_zero_point_offset from config_led_ring_table_packet message
 *
 * @return  Zero offset unit in milliseconds.
 */
static inline uint32_t mavlink_msg_config_led_ring_table_packet_get_led_zero_point_offset(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field led_display_mode from config_led_ring_table_packet message
 *
 * @return  LED display mode selection.
 */
static inline uint8_t mavlink_msg_config_led_ring_table_packet_get_led_display_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field led_table from config_led_ring_table_packet message
 *
 * @return  LED display field data packet, 45 bytes represent the status of 360 LEDs bit by bit.
 */
static inline uint16_t mavlink_msg_config_led_ring_table_packet_get_led_table(const mavlink_message_t* msg, uint8_t *led_table)
{
    return _MAV_RETURN_uint8_t_array(msg, led_table, 45,  11);
}

/**
 * @brief Decode a config_led_ring_table_packet message into a struct
 *
 * @param msg The message to decode
 * @param config_led_ring_table_packet C-struct to decode the message contents into
 */
static inline void mavlink_msg_config_led_ring_table_packet_decode(const mavlink_message_t* msg, mavlink_config_led_ring_table_packet_t* config_led_ring_table_packet)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    config_led_ring_table_packet->led_rotation_period = mavlink_msg_config_led_ring_table_packet_get_led_rotation_period(msg);
    config_led_ring_table_packet->led_zero_point_offset = mavlink_msg_config_led_ring_table_packet_get_led_zero_point_offset(msg);
    config_led_ring_table_packet->packet_id = mavlink_msg_config_led_ring_table_packet_get_packet_id(msg);
    config_led_ring_table_packet->led_display_mode = mavlink_msg_config_led_ring_table_packet_get_led_display_mode(msg);
    mavlink_msg_config_led_ring_table_packet_get_led_table(msg, config_led_ring_table_packet->led_table);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_LEN? msg->len : MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_LEN;
        memset(config_led_ring_table_packet, 0, MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_LEN);
    memcpy(config_led_ring_table_packet, _MAV_PAYLOAD(msg), len);
#endif
}
