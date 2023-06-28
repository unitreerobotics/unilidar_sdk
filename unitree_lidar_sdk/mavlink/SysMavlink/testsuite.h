/** @file
 *    @brief MAVLink comm protocol testsuite generated from SysMavlink.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef SYSMAVLINK_TESTSUITE_H
#define SYSMAVLINK_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_SysMavlink(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

    mavlink_test_SysMavlink(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_device_request_answer(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DEVICE_REQUEST_ANSWER >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_device_request_answer_t packet_in = {
        5
    };
    mavlink_device_request_answer_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.command_return_ok = packet_in.command_return_ok;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DEVICE_REQUEST_ANSWER_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DEVICE_REQUEST_ANSWER_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_request_answer_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_device_request_answer_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_request_answer_pack(system_id, component_id, &msg , packet1.command_return_ok );
    mavlink_msg_device_request_answer_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_request_answer_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.command_return_ok );
    mavlink_msg_device_request_answer_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_device_request_answer_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_request_answer_send(MAVLINK_COMM_1 , packet1.command_return_ok );
    mavlink_msg_device_request_answer_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("DEVICE_REQUEST_ANSWER") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_DEVICE_REQUEST_ANSWER) != NULL);
#endif
}

static void mavlink_test_device_debug_mode_params(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DEVICE_DEBUG_MODE_PARAMS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_device_debug_mode_params_t packet_in = {
        17.0,45.0,17651,17755,17859,17963,53,120,187,254
    };
    mavlink_device_debug_mode_params_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.debug_param_value = packet_in.debug_param_value;
        packet1.debug_float_reserve = packet_in.debug_float_reserve;
        packet1.debug_pos = packet_in.debug_pos;
        packet1.debug_count = packet_in.debug_count;
        packet1.debug_laser_cycle = packet_in.debug_laser_cycle;
        packet1.debug_uin16_t_reserve = packet_in.debug_uin16_t_reserve;
        packet1.debug_mode = packet_in.debug_mode;
        packet1.debug_needed = packet_in.debug_needed;
        packet1.debug_first_test_flag = packet_in.debug_first_test_flag;
        packet1.debug_uin8_t_reserve = packet_in.debug_uin8_t_reserve;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DEVICE_DEBUG_MODE_PARAMS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DEVICE_DEBUG_MODE_PARAMS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_debug_mode_params_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_device_debug_mode_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_debug_mode_params_pack(system_id, component_id, &msg , packet1.debug_mode , packet1.debug_needed , packet1.debug_first_test_flag , packet1.debug_uin8_t_reserve , packet1.debug_pos , packet1.debug_count , packet1.debug_laser_cycle , packet1.debug_uin16_t_reserve , packet1.debug_param_value , packet1.debug_float_reserve );
    mavlink_msg_device_debug_mode_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_debug_mode_params_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.debug_mode , packet1.debug_needed , packet1.debug_first_test_flag , packet1.debug_uin8_t_reserve , packet1.debug_pos , packet1.debug_count , packet1.debug_laser_cycle , packet1.debug_uin16_t_reserve , packet1.debug_param_value , packet1.debug_float_reserve );
    mavlink_msg_device_debug_mode_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_device_debug_mode_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_debug_mode_params_send(MAVLINK_COMM_1 , packet1.debug_mode , packet1.debug_needed , packet1.debug_first_test_flag , packet1.debug_uin8_t_reserve , packet1.debug_pos , packet1.debug_count , packet1.debug_laser_cycle , packet1.debug_uin16_t_reserve , packet1.debug_param_value , packet1.debug_float_reserve );
    mavlink_msg_device_debug_mode_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("DEVICE_DEBUG_MODE_PARAMS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_DEVICE_DEBUG_MODE_PARAMS) != NULL);
#endif
}

static void mavlink_test_set_com_necessary_measure_parameter(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SET_COM_NECESSARY_MEASURE_PARAMETER >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_set_com_necessary_measure_parameter_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,963498920,963499128,963499336,963499544,963499752,963499960,19939,20043,20147,20251,185
    };
    mavlink_set_com_necessary_measure_parameter_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.moto_target_speed = packet_in.moto_target_speed;
        packet1.moto_control_coef = packet_in.moto_control_coef;
        packet1.moto_speed_threshold = packet_in.moto_speed_threshold;
        packet1.imu_target_tempe = packet_in.imu_target_tempe;
        packet1.imu_x_axis_error = packet_in.imu_x_axis_error;
        packet1.imu_y_axis_error = packet_in.imu_y_axis_error;
        packet1.imu_z_axis_error = packet_in.imu_z_axis_error;
        packet1.imu_acc_bias_x = packet_in.imu_acc_bias_x;
        packet1.imu_acc_bias_y = packet_in.imu_acc_bias_y;
        packet1.imu_acc_bias_z = packet_in.imu_acc_bias_z;
        packet1.imu_gyro_bias_x = packet_in.imu_gyro_bias_x;
        packet1.imu_gyro_bias_y = packet_in.imu_gyro_bias_y;
        packet1.imu_gyro_bias_z = packet_in.imu_gyro_bias_z;
        packet1.flash_ok_flag = packet_in.flash_ok_flag;
        packet1.led_mode_config = packet_in.led_mode_config;
        packet1.imu_work_mode_select = packet_in.imu_work_mode_select;
        packet1.moto_pwm_duty = packet_in.moto_pwm_duty;
        packet1.factory_mode_en = packet_in.factory_mode_en;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SET_COM_NECESSARY_MEASURE_PARAMETER_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SET_COM_NECESSARY_MEASURE_PARAMETER_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_com_necessary_measure_parameter_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_set_com_necessary_measure_parameter_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_com_necessary_measure_parameter_pack(system_id, component_id, &msg , packet1.factory_mode_en , packet1.flash_ok_flag , packet1.led_mode_config , packet1.imu_work_mode_select , packet1.moto_pwm_duty , packet1.moto_target_speed , packet1.moto_control_coef , packet1.moto_speed_threshold , packet1.imu_target_tempe , packet1.imu_x_axis_error , packet1.imu_y_axis_error , packet1.imu_z_axis_error , packet1.imu_acc_bias_x , packet1.imu_acc_bias_y , packet1.imu_acc_bias_z , packet1.imu_gyro_bias_x , packet1.imu_gyro_bias_y , packet1.imu_gyro_bias_z );
    mavlink_msg_set_com_necessary_measure_parameter_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_com_necessary_measure_parameter_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.factory_mode_en , packet1.flash_ok_flag , packet1.led_mode_config , packet1.imu_work_mode_select , packet1.moto_pwm_duty , packet1.moto_target_speed , packet1.moto_control_coef , packet1.moto_speed_threshold , packet1.imu_target_tempe , packet1.imu_x_axis_error , packet1.imu_y_axis_error , packet1.imu_z_axis_error , packet1.imu_acc_bias_x , packet1.imu_acc_bias_y , packet1.imu_acc_bias_z , packet1.imu_gyro_bias_x , packet1.imu_gyro_bias_y , packet1.imu_gyro_bias_z );
    mavlink_msg_set_com_necessary_measure_parameter_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_set_com_necessary_measure_parameter_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_com_necessary_measure_parameter_send(MAVLINK_COMM_1 , packet1.factory_mode_en , packet1.flash_ok_flag , packet1.led_mode_config , packet1.imu_work_mode_select , packet1.moto_pwm_duty , packet1.moto_target_speed , packet1.moto_control_coef , packet1.moto_speed_threshold , packet1.imu_target_tempe , packet1.imu_x_axis_error , packet1.imu_y_axis_error , packet1.imu_z_axis_error , packet1.imu_acc_bias_x , packet1.imu_acc_bias_y , packet1.imu_acc_bias_z , packet1.imu_gyro_bias_x , packet1.imu_gyro_bias_y , packet1.imu_gyro_bias_z );
    mavlink_msg_set_com_necessary_measure_parameter_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("SET_COM_NECESSARY_MEASURE_PARAMETER") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_SET_COM_NECESSARY_MEASURE_PARAMETER) != NULL);
#endif
}

static void mavlink_test_set_sys_necessary_measure_parameter(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SET_SYS_NECESSARY_MEASURE_PARAMETER >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_set_sys_necessary_measure_parameter_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,213.0,241.0,19107,19211,19315,3,70
    };
    mavlink_set_sys_necessary_measure_parameter_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.tdc_bin_length = packet_in.tdc_bin_length;
        packet1.apd_temp_param = packet_in.apd_temp_param;
        packet1.gray_param_a = packet_in.gray_param_a;
        packet1.gray_param_b = packet_in.gray_param_b;
        packet1.gray_param_c = packet_in.gray_param_c;
        packet1.reflect_param = packet_in.reflect_param;
        packet1.b_axis_dist = packet_in.b_axis_dist;
        packet1.theta_angle = packet_in.theta_angle;
        packet1.ksi_angle = packet_in.ksi_angle;
        packet1.comparator_voltage = packet_in.comparator_voltage;
        packet1.zero_offset_bin = packet_in.zero_offset_bin;
        packet1.flash_ok_flag = packet_in.flash_ok_flag;
        packet1.start_offset = packet_in.start_offset;
        packet1.gray_calibration_en = packet_in.gray_calibration_en;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SET_SYS_NECESSARY_MEASURE_PARAMETER_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SET_SYS_NECESSARY_MEASURE_PARAMETER_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_sys_necessary_measure_parameter_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_set_sys_necessary_measure_parameter_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_sys_necessary_measure_parameter_pack(system_id, component_id, &msg , packet1.start_offset , packet1.gray_calibration_en , packet1.comparator_voltage , packet1.zero_offset_bin , packet1.flash_ok_flag , packet1.tdc_bin_length , packet1.apd_temp_param , packet1.gray_param_a , packet1.gray_param_b , packet1.gray_param_c , packet1.reflect_param , packet1.b_axis_dist , packet1.theta_angle , packet1.ksi_angle );
    mavlink_msg_set_sys_necessary_measure_parameter_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_sys_necessary_measure_parameter_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.start_offset , packet1.gray_calibration_en , packet1.comparator_voltage , packet1.zero_offset_bin , packet1.flash_ok_flag , packet1.tdc_bin_length , packet1.apd_temp_param , packet1.gray_param_a , packet1.gray_param_b , packet1.gray_param_c , packet1.reflect_param , packet1.b_axis_dist , packet1.theta_angle , packet1.ksi_angle );
    mavlink_msg_set_sys_necessary_measure_parameter_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_set_sys_necessary_measure_parameter_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_sys_necessary_measure_parameter_send(MAVLINK_COMM_1 , packet1.start_offset , packet1.gray_calibration_en , packet1.comparator_voltage , packet1.zero_offset_bin , packet1.flash_ok_flag , packet1.tdc_bin_length , packet1.apd_temp_param , packet1.gray_param_a , packet1.gray_param_b , packet1.gray_param_c , packet1.reflect_param , packet1.b_axis_dist , packet1.theta_angle , packet1.ksi_angle );
    mavlink_msg_set_sys_necessary_measure_parameter_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("SET_SYS_NECESSARY_MEASURE_PARAMETER") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_SET_SYS_NECESSARY_MEASURE_PARAMETER) != NULL);
#endif
}

static void mavlink_test_ret_tdc_point_debug_packet(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RET_TDC_POINT_DEBUG_PACKET >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ret_tdc_point_debug_packet_t packet_in = {
        17.0,45.0,73.0,101.0,18067,18171,18275,18379,18483,18587,18691,18795,18899,235,46
    };
    mavlink_ret_tdc_point_debug_packet_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.width_correction_diff = packet_in.width_correction_diff;
        packet1.apd_temperature = packet_in.apd_temperature;
        packet1.imu_temperature = packet_in.imu_temperature;
        packet1.apd_voltage = packet_in.apd_voltage;
        packet1.start = packet_in.start;
        packet1.width = packet_in.width;
        packet1.spec_start = packet_in.spec_start;
        packet1.spec_width = packet_in.spec_width;
        packet1.dist = packet_in.dist;
        packet1.point_index = packet_in.point_index;
        packet1.reserve_2 = packet_in.reserve_2;
        packet1.reserve_3 = packet_in.reserve_3;
        packet1.reserve_4 = packet_in.reserve_4;
        packet1.spec_reflectivity = packet_in.spec_reflectivity;
        packet1.packet_index = packet_in.packet_index;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RET_TDC_POINT_DEBUG_PACKET_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RET_TDC_POINT_DEBUG_PACKET_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_tdc_point_debug_packet_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ret_tdc_point_debug_packet_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_tdc_point_debug_packet_pack(system_id, component_id, &msg , packet1.spec_reflectivity , packet1.packet_index , packet1.start , packet1.width , packet1.spec_start , packet1.spec_width , packet1.dist , packet1.point_index , packet1.reserve_2 , packet1.reserve_3 , packet1.reserve_4 , packet1.width_correction_diff , packet1.apd_temperature , packet1.imu_temperature , packet1.apd_voltage );
    mavlink_msg_ret_tdc_point_debug_packet_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_tdc_point_debug_packet_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.spec_reflectivity , packet1.packet_index , packet1.start , packet1.width , packet1.spec_start , packet1.spec_width , packet1.dist , packet1.point_index , packet1.reserve_2 , packet1.reserve_3 , packet1.reserve_4 , packet1.width_correction_diff , packet1.apd_temperature , packet1.imu_temperature , packet1.apd_voltage );
    mavlink_msg_ret_tdc_point_debug_packet_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ret_tdc_point_debug_packet_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_tdc_point_debug_packet_send(MAVLINK_COMM_1 , packet1.spec_reflectivity , packet1.packet_index , packet1.start , packet1.width , packet1.spec_start , packet1.spec_width , packet1.dist , packet1.point_index , packet1.reserve_2 , packet1.reserve_3 , packet1.reserve_4 , packet1.width_correction_diff , packet1.apd_temperature , packet1.imu_temperature , packet1.apd_voltage );
    mavlink_msg_ret_tdc_point_debug_packet_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("RET_TDC_POINT_DEBUG_PACKET") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_RET_TDC_POINT_DEBUG_PACKET) != NULL);
#endif
}

static void mavlink_test_device_request_internal_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DEVICE_REQUEST_INTERNAL_DATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_device_request_internal_data_t packet_in = {
        5
    };
    mavlink_device_request_internal_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.request_type = packet_in.request_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DEVICE_REQUEST_INTERNAL_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DEVICE_REQUEST_INTERNAL_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_request_internal_data_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_device_request_internal_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_request_internal_data_pack(system_id, component_id, &msg , packet1.request_type );
    mavlink_msg_device_request_internal_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_request_internal_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.request_type );
    mavlink_msg_device_request_internal_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_device_request_internal_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_request_internal_data_send(MAVLINK_COMM_1 , packet1.request_type );
    mavlink_msg_device_request_internal_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("DEVICE_REQUEST_INTERNAL_DATA") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_DEVICE_REQUEST_INTERNAL_DATA) != NULL);
#endif
}

static void mavlink_test_device_request_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DEVICE_REQUEST_DATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_device_request_data_t packet_in = {
        5
    };
    mavlink_device_request_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.request_type = packet_in.request_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DEVICE_REQUEST_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_request_data_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_device_request_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_request_data_pack(system_id, component_id, &msg , packet1.request_type );
    mavlink_msg_device_request_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_request_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.request_type );
    mavlink_msg_device_request_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_device_request_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_request_data_send(MAVLINK_COMM_1 , packet1.request_type );
    mavlink_msg_device_request_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("DEVICE_REQUEST_DATA") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_DEVICE_REQUEST_DATA) != NULL);
#endif
}

static void mavlink_test_device_command(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DEVICE_COMMAND >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_device_command_t packet_in = {
        5
    };
    mavlink_device_command_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.cmd_type = packet_in.cmd_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DEVICE_COMMAND_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DEVICE_COMMAND_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_command_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_device_command_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_command_pack(system_id, component_id, &msg , packet1.cmd_type );
    mavlink_msg_device_command_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_command_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.cmd_type );
    mavlink_msg_device_command_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_device_command_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_command_send(MAVLINK_COMM_1 , packet1.cmd_type );
    mavlink_msg_device_command_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("DEVICE_COMMAND") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_DEVICE_COMMAND) != NULL);
#endif
}

static void mavlink_test_ret_lidar_version(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RET_LIDAR_VERSION >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ret_lidar_version_t packet_in = {
        { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 },{ 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120 },{ 211, 212, 213, 214, 215, 216 },{ 101, 102, 103, 104, 105, 106 }
    };
    mavlink_ret_lidar_version_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        mav_array_memcpy(packet1.sys_soft_version, packet_in.sys_soft_version, sizeof(uint8_t)*13);
        mav_array_memcpy(packet1.com_soft_version, packet_in.com_soft_version, sizeof(uint8_t)*13);
        mav_array_memcpy(packet1.sys_hard_version, packet_in.sys_hard_version, sizeof(uint8_t)*6);
        mav_array_memcpy(packet1.com_hard_version, packet_in.com_hard_version, sizeof(uint8_t)*6);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RET_LIDAR_VERSION_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RET_LIDAR_VERSION_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_lidar_version_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ret_lidar_version_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_lidar_version_pack(system_id, component_id, &msg , packet1.sys_soft_version , packet1.com_soft_version , packet1.sys_hard_version , packet1.com_hard_version );
    mavlink_msg_ret_lidar_version_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_lidar_version_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.sys_soft_version , packet1.com_soft_version , packet1.sys_hard_version , packet1.com_hard_version );
    mavlink_msg_ret_lidar_version_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ret_lidar_version_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_lidar_version_send(MAVLINK_COMM_1 , packet1.sys_soft_version , packet1.com_soft_version , packet1.sys_hard_version , packet1.com_hard_version );
    mavlink_msg_ret_lidar_version_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("RET_LIDAR_VERSION") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_RET_LIDAR_VERSION) != NULL);
#endif
}

static void mavlink_test_config_lidar_working_mode(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_config_lidar_working_mode_t packet_in = {
        5
    };
    mavlink_config_lidar_working_mode_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.request_type = packet_in.request_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_config_lidar_working_mode_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_config_lidar_working_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_config_lidar_working_mode_pack(system_id, component_id, &msg , packet1.request_type );
    mavlink_msg_config_lidar_working_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_config_lidar_working_mode_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.request_type );
    mavlink_msg_config_lidar_working_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_config_lidar_working_mode_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_config_lidar_working_mode_send(MAVLINK_COMM_1 , packet1.request_type );
    mavlink_msg_config_lidar_working_mode_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("CONFIG_LIDAR_WORKING_MODE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_CONFIG_LIDAR_WORKING_MODE) != NULL);
#endif
}

static void mavlink_test_config_led_ring_table_packet(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_config_led_ring_table_packet_t packet_in = {
        963497464,963497672,17651,163,{ 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 }
    };
    mavlink_config_led_ring_table_packet_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.led_rotation_period = packet_in.led_rotation_period;
        packet1.led_zero_point_offset = packet_in.led_zero_point_offset;
        packet1.packet_id = packet_in.packet_id;
        packet1.led_display_mode = packet_in.led_display_mode;
        
        mav_array_memcpy(packet1.led_table, packet_in.led_table, sizeof(uint8_t)*45);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_config_led_ring_table_packet_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_config_led_ring_table_packet_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_config_led_ring_table_packet_pack(system_id, component_id, &msg , packet1.packet_id , packet1.led_rotation_period , packet1.led_zero_point_offset , packet1.led_display_mode , packet1.led_table );
    mavlink_msg_config_led_ring_table_packet_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_config_led_ring_table_packet_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.packet_id , packet1.led_rotation_period , packet1.led_zero_point_offset , packet1.led_display_mode , packet1.led_table );
    mavlink_msg_config_led_ring_table_packet_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_config_led_ring_table_packet_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_config_led_ring_table_packet_send(MAVLINK_COMM_1 , packet1.packet_id , packet1.led_rotation_period , packet1.led_zero_point_offset , packet1.led_display_mode , packet1.led_table );
    mavlink_msg_config_led_ring_table_packet_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("CONFIG_LED_RING_TABLE_PACKET") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_CONFIG_LED_RING_TABLE_PACKET) != NULL);
#endif
}

static void mavlink_test_ret_lidar_distance_data_packet(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ret_lidar_distance_data_packet_t packet_in = {
        17235,17339,17443,{ 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134 }
    };
    mavlink_ret_lidar_distance_data_packet_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.packet_id = packet_in.packet_id;
        packet1.packet_cnt = packet_in.packet_cnt;
        packet1.payload_size = packet_in.payload_size;
        
        mav_array_memcpy(packet1.point_data, packet_in.point_data, sizeof(uint8_t)*240);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_lidar_distance_data_packet_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ret_lidar_distance_data_packet_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_lidar_distance_data_packet_pack(system_id, component_id, &msg , packet1.packet_id , packet1.packet_cnt , packet1.payload_size , packet1.point_data );
    mavlink_msg_ret_lidar_distance_data_packet_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_lidar_distance_data_packet_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.packet_id , packet1.packet_cnt , packet1.payload_size , packet1.point_data );
    mavlink_msg_ret_lidar_distance_data_packet_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ret_lidar_distance_data_packet_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_lidar_distance_data_packet_send(MAVLINK_COMM_1 , packet1.packet_id , packet1.packet_cnt , packet1.payload_size , packet1.point_data );
    mavlink_msg_ret_lidar_distance_data_packet_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("RET_LIDAR_DISTANCE_DATA_PACKET") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_RET_LIDAR_DISTANCE_DATA_PACKET) != NULL);
#endif
}

static void mavlink_test_ret_lidar_auxiliary_data_packet(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ret_lidar_auxiliary_data_packet_t packet_in = {
        963497464,963497672,963497880,963498088,963498296,157.0,185.0,213.0,241.0,269.0,297.0,325.0,353.0,381.0,409.0,437.0,465.0,493.0,521.0,549.0,577.0,21603,21707,13,{ 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199 }
    };
    mavlink_ret_lidar_auxiliary_data_packet_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lidar_sync_delay_time = packet_in.lidar_sync_delay_time;
        packet1.time_stamp_s_step = packet_in.time_stamp_s_step;
        packet1.time_stamp_us_step = packet_in.time_stamp_us_step;
        packet1.sys_rotation_period = packet_in.sys_rotation_period;
        packet1.com_rotation_period = packet_in.com_rotation_period;
        packet1.com_horizontal_angle_start = packet_in.com_horizontal_angle_start;
        packet1.com_horizontal_angle_step = packet_in.com_horizontal_angle_step;
        packet1.sys_vertical_angle_start = packet_in.sys_vertical_angle_start;
        packet1.sys_vertical_angle_span = packet_in.sys_vertical_angle_span;
        packet1.apd_temperature = packet_in.apd_temperature;
        packet1.dirty_index = packet_in.dirty_index;
        packet1.imu_temperature = packet_in.imu_temperature;
        packet1.up_optical_q = packet_in.up_optical_q;
        packet1.down_optical_q = packet_in.down_optical_q;
        packet1.apd_voltage = packet_in.apd_voltage;
        packet1.imu_angle_x_offset = packet_in.imu_angle_x_offset;
        packet1.imu_angle_y_offset = packet_in.imu_angle_y_offset;
        packet1.imu_angle_z_offset = packet_in.imu_angle_z_offset;
        packet1.b_axis_dist = packet_in.b_axis_dist;
        packet1.theta_angle = packet_in.theta_angle;
        packet1.ksi_angle = packet_in.ksi_angle;
        packet1.packet_id = packet_in.packet_id;
        packet1.payload_size = packet_in.payload_size;
        packet1.lidar_work_status = packet_in.lidar_work_status;
        
        mav_array_memcpy(packet1.reflect_data, packet_in.reflect_data, sizeof(uint8_t)*120);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_lidar_auxiliary_data_packet_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ret_lidar_auxiliary_data_packet_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_lidar_auxiliary_data_packet_pack(system_id, component_id, &msg , packet1.lidar_work_status , packet1.packet_id , packet1.payload_size , packet1.lidar_sync_delay_time , packet1.time_stamp_s_step , packet1.time_stamp_us_step , packet1.sys_rotation_period , packet1.com_rotation_period , packet1.com_horizontal_angle_start , packet1.com_horizontal_angle_step , packet1.sys_vertical_angle_start , packet1.sys_vertical_angle_span , packet1.apd_temperature , packet1.dirty_index , packet1.imu_temperature , packet1.up_optical_q , packet1.down_optical_q , packet1.apd_voltage , packet1.imu_angle_x_offset , packet1.imu_angle_y_offset , packet1.imu_angle_z_offset , packet1.b_axis_dist , packet1.theta_angle , packet1.ksi_angle , packet1.reflect_data );
    mavlink_msg_ret_lidar_auxiliary_data_packet_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_lidar_auxiliary_data_packet_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.lidar_work_status , packet1.packet_id , packet1.payload_size , packet1.lidar_sync_delay_time , packet1.time_stamp_s_step , packet1.time_stamp_us_step , packet1.sys_rotation_period , packet1.com_rotation_period , packet1.com_horizontal_angle_start , packet1.com_horizontal_angle_step , packet1.sys_vertical_angle_start , packet1.sys_vertical_angle_span , packet1.apd_temperature , packet1.dirty_index , packet1.imu_temperature , packet1.up_optical_q , packet1.down_optical_q , packet1.apd_voltage , packet1.imu_angle_x_offset , packet1.imu_angle_y_offset , packet1.imu_angle_z_offset , packet1.b_axis_dist , packet1.theta_angle , packet1.ksi_angle , packet1.reflect_data );
    mavlink_msg_ret_lidar_auxiliary_data_packet_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ret_lidar_auxiliary_data_packet_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_lidar_auxiliary_data_packet_send(MAVLINK_COMM_1 , packet1.lidar_work_status , packet1.packet_id , packet1.payload_size , packet1.lidar_sync_delay_time , packet1.time_stamp_s_step , packet1.time_stamp_us_step , packet1.sys_rotation_period , packet1.com_rotation_period , packet1.com_horizontal_angle_start , packet1.com_horizontal_angle_step , packet1.sys_vertical_angle_start , packet1.sys_vertical_angle_span , packet1.apd_temperature , packet1.dirty_index , packet1.imu_temperature , packet1.up_optical_q , packet1.down_optical_q , packet1.apd_voltage , packet1.imu_angle_x_offset , packet1.imu_angle_y_offset , packet1.imu_angle_z_offset , packet1.b_axis_dist , packet1.theta_angle , packet1.ksi_angle , packet1.reflect_data );
    mavlink_msg_ret_lidar_auxiliary_data_packet_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("RET_LIDAR_AUXILIARY_DATA_PACKET") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_RET_LIDAR_AUXILIARY_DATA_PACKET) != NULL);
#endif
}

static void mavlink_test_ret_lidar_time_sync_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ret_lidar_time_sync_data_t packet_in = {
        963497464,17
    };
    mavlink_ret_lidar_time_sync_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lidar_sync_count = packet_in.lidar_sync_count;
        packet1.lidar_sync_type = packet_in.lidar_sync_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_lidar_time_sync_data_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ret_lidar_time_sync_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_lidar_time_sync_data_pack(system_id, component_id, &msg , packet1.lidar_sync_type , packet1.lidar_sync_count );
    mavlink_msg_ret_lidar_time_sync_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_lidar_time_sync_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.lidar_sync_type , packet1.lidar_sync_count );
    mavlink_msg_ret_lidar_time_sync_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ret_lidar_time_sync_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_lidar_time_sync_data_send(MAVLINK_COMM_1 , packet1.lidar_sync_type , packet1.lidar_sync_count );
    mavlink_msg_ret_lidar_time_sync_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("RET_LIDAR_TIME_SYNC_DATA") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_RET_LIDAR_TIME_SYNC_DATA) != NULL);
#endif
}

static void mavlink_test_ret_imu_attitude_data_packet(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ret_imu_attitude_data_packet_t packet_in = {
        { 17.0, 18.0, 19.0, 20.0 },{ 129.0, 130.0, 131.0 },{ 213.0, 214.0, 215.0 },19315
    };
    mavlink_ret_imu_attitude_data_packet_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.packet_id = packet_in.packet_id;
        
        mav_array_memcpy(packet1.quaternion, packet_in.quaternion, sizeof(float)*4);
        mav_array_memcpy(packet1.angular_velocity, packet_in.angular_velocity, sizeof(float)*3);
        mav_array_memcpy(packet1.linear_acceleration, packet_in.linear_acceleration, sizeof(float)*3);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_imu_attitude_data_packet_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ret_imu_attitude_data_packet_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_imu_attitude_data_packet_pack(system_id, component_id, &msg , packet1.packet_id , packet1.quaternion , packet1.angular_velocity , packet1.linear_acceleration );
    mavlink_msg_ret_imu_attitude_data_packet_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_imu_attitude_data_packet_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.packet_id , packet1.quaternion , packet1.angular_velocity , packet1.linear_acceleration );
    mavlink_msg_ret_imu_attitude_data_packet_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ret_imu_attitude_data_packet_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ret_imu_attitude_data_packet_send(MAVLINK_COMM_1 , packet1.packet_id , packet1.quaternion , packet1.angular_velocity , packet1.linear_acceleration );
    mavlink_msg_ret_imu_attitude_data_packet_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("RET_IMU_ATTITUDE_DATA_PACKET") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_RET_IMU_ATTITUDE_DATA_PACKET) != NULL);
#endif
}

static void mavlink_test_SysMavlink(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_device_request_answer(system_id, component_id, last_msg);
    mavlink_test_device_debug_mode_params(system_id, component_id, last_msg);
    mavlink_test_set_com_necessary_measure_parameter(system_id, component_id, last_msg);
    mavlink_test_set_sys_necessary_measure_parameter(system_id, component_id, last_msg);
    mavlink_test_ret_tdc_point_debug_packet(system_id, component_id, last_msg);
    mavlink_test_device_request_internal_data(system_id, component_id, last_msg);
    mavlink_test_device_request_data(system_id, component_id, last_msg);
    mavlink_test_device_command(system_id, component_id, last_msg);
    mavlink_test_ret_lidar_version(system_id, component_id, last_msg);
    mavlink_test_config_lidar_working_mode(system_id, component_id, last_msg);
    mavlink_test_config_led_ring_table_packet(system_id, component_id, last_msg);
    mavlink_test_ret_lidar_distance_data_packet(system_id, component_id, last_msg);
    mavlink_test_ret_lidar_auxiliary_data_packet(system_id, component_id, last_msg);
    mavlink_test_ret_lidar_time_sync_data(system_id, component_id, last_msg);
    mavlink_test_ret_imu_attitude_data_packet(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // SYSMAVLINK_TESTSUITE_H
