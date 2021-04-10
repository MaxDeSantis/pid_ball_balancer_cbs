#ifndef _ROS_lgsvl_msgs_CanBusData_h
#define _ROS_lgsvl_msgs_CanBusData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/Vector3.h"

namespace lgsvl_msgs
{

  class CanBusData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _speed_mps_type;
      _speed_mps_type speed_mps;
      typedef float _throttle_pct_type;
      _throttle_pct_type throttle_pct;
      typedef float _brake_pct_type;
      _brake_pct_type brake_pct;
      typedef float _steer_pct_type;
      _steer_pct_type steer_pct;
      typedef bool _parking_brake_active_type;
      _parking_brake_active_type parking_brake_active;
      typedef bool _high_beams_active_type;
      _high_beams_active_type high_beams_active;
      typedef bool _low_beams_active_type;
      _low_beams_active_type low_beams_active;
      typedef bool _hazard_lights_active_type;
      _hazard_lights_active_type hazard_lights_active;
      typedef bool _fog_lights_active_type;
      _fog_lights_active_type fog_lights_active;
      typedef bool _left_turn_signal_active_type;
      _left_turn_signal_active_type left_turn_signal_active;
      typedef bool _right_turn_signal_active_type;
      _right_turn_signal_active_type right_turn_signal_active;
      typedef bool _wipers_active_type;
      _wipers_active_type wipers_active;
      typedef bool _reverse_gear_active_type;
      _reverse_gear_active_type reverse_gear_active;
      typedef int8_t _selected_gear_type;
      _selected_gear_type selected_gear;
      typedef bool _engine_active_type;
      _engine_active_type engine_active;
      typedef float _engine_rpm_type;
      _engine_rpm_type engine_rpm;
      typedef float _gps_latitude_type;
      _gps_latitude_type gps_latitude;
      typedef float _gps_longitude_type;
      _gps_longitude_type gps_longitude;
      typedef float _gps_altitude_type;
      _gps_altitude_type gps_altitude;
      typedef geometry_msgs::Quaternion _orientation_type;
      _orientation_type orientation;
      typedef geometry_msgs::Vector3 _linear_velocities_type;
      _linear_velocities_type linear_velocities;
      enum { GEAR_NEUTRAL =  0 };
      enum { GEAR_DRIVE =  1 };
      enum { GEAR_REVERSE =  2 };
      enum { GEAR_PARKING =  3 };
      enum { GEAR_LOW =  4 };

    CanBusData():
      header(),
      speed_mps(0),
      throttle_pct(0),
      brake_pct(0),
      steer_pct(0),
      parking_brake_active(0),
      high_beams_active(0),
      low_beams_active(0),
      hazard_lights_active(0),
      fog_lights_active(0),
      left_turn_signal_active(0),
      right_turn_signal_active(0),
      wipers_active(0),
      reverse_gear_active(0),
      selected_gear(0),
      engine_active(0),
      engine_rpm(0),
      gps_latitude(0),
      gps_longitude(0),
      gps_altitude(0),
      orientation(),
      linear_velocities()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_speed_mps;
      u_speed_mps.real = this->speed_mps;
      *(outbuffer + offset + 0) = (u_speed_mps.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed_mps.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed_mps.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed_mps.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed_mps);
      union {
        float real;
        uint32_t base;
      } u_throttle_pct;
      u_throttle_pct.real = this->throttle_pct;
      *(outbuffer + offset + 0) = (u_throttle_pct.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_throttle_pct.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_throttle_pct.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_throttle_pct.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->throttle_pct);
      union {
        float real;
        uint32_t base;
      } u_brake_pct;
      u_brake_pct.real = this->brake_pct;
      *(outbuffer + offset + 0) = (u_brake_pct.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_brake_pct.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_brake_pct.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_brake_pct.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->brake_pct);
      union {
        float real;
        uint32_t base;
      } u_steer_pct;
      u_steer_pct.real = this->steer_pct;
      *(outbuffer + offset + 0) = (u_steer_pct.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steer_pct.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steer_pct.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steer_pct.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steer_pct);
      union {
        bool real;
        uint8_t base;
      } u_parking_brake_active;
      u_parking_brake_active.real = this->parking_brake_active;
      *(outbuffer + offset + 0) = (u_parking_brake_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->parking_brake_active);
      union {
        bool real;
        uint8_t base;
      } u_high_beams_active;
      u_high_beams_active.real = this->high_beams_active;
      *(outbuffer + offset + 0) = (u_high_beams_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->high_beams_active);
      union {
        bool real;
        uint8_t base;
      } u_low_beams_active;
      u_low_beams_active.real = this->low_beams_active;
      *(outbuffer + offset + 0) = (u_low_beams_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->low_beams_active);
      union {
        bool real;
        uint8_t base;
      } u_hazard_lights_active;
      u_hazard_lights_active.real = this->hazard_lights_active;
      *(outbuffer + offset + 0) = (u_hazard_lights_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->hazard_lights_active);
      union {
        bool real;
        uint8_t base;
      } u_fog_lights_active;
      u_fog_lights_active.real = this->fog_lights_active;
      *(outbuffer + offset + 0) = (u_fog_lights_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fog_lights_active);
      union {
        bool real;
        uint8_t base;
      } u_left_turn_signal_active;
      u_left_turn_signal_active.real = this->left_turn_signal_active;
      *(outbuffer + offset + 0) = (u_left_turn_signal_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->left_turn_signal_active);
      union {
        bool real;
        uint8_t base;
      } u_right_turn_signal_active;
      u_right_turn_signal_active.real = this->right_turn_signal_active;
      *(outbuffer + offset + 0) = (u_right_turn_signal_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->right_turn_signal_active);
      union {
        bool real;
        uint8_t base;
      } u_wipers_active;
      u_wipers_active.real = this->wipers_active;
      *(outbuffer + offset + 0) = (u_wipers_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wipers_active);
      union {
        bool real;
        uint8_t base;
      } u_reverse_gear_active;
      u_reverse_gear_active.real = this->reverse_gear_active;
      *(outbuffer + offset + 0) = (u_reverse_gear_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reverse_gear_active);
      union {
        int8_t real;
        uint8_t base;
      } u_selected_gear;
      u_selected_gear.real = this->selected_gear;
      *(outbuffer + offset + 0) = (u_selected_gear.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->selected_gear);
      union {
        bool real;
        uint8_t base;
      } u_engine_active;
      u_engine_active.real = this->engine_active;
      *(outbuffer + offset + 0) = (u_engine_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->engine_active);
      union {
        float real;
        uint32_t base;
      } u_engine_rpm;
      u_engine_rpm.real = this->engine_rpm;
      *(outbuffer + offset + 0) = (u_engine_rpm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_engine_rpm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_engine_rpm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_engine_rpm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->engine_rpm);
      offset += serializeAvrFloat64(outbuffer + offset, this->gps_latitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->gps_longitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->gps_altitude);
      offset += this->orientation.serialize(outbuffer + offset);
      offset += this->linear_velocities.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_speed_mps;
      u_speed_mps.base = 0;
      u_speed_mps.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed_mps.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed_mps.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed_mps.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed_mps = u_speed_mps.real;
      offset += sizeof(this->speed_mps);
      union {
        float real;
        uint32_t base;
      } u_throttle_pct;
      u_throttle_pct.base = 0;
      u_throttle_pct.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_throttle_pct.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_throttle_pct.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_throttle_pct.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->throttle_pct = u_throttle_pct.real;
      offset += sizeof(this->throttle_pct);
      union {
        float real;
        uint32_t base;
      } u_brake_pct;
      u_brake_pct.base = 0;
      u_brake_pct.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_brake_pct.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_brake_pct.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_brake_pct.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->brake_pct = u_brake_pct.real;
      offset += sizeof(this->brake_pct);
      union {
        float real;
        uint32_t base;
      } u_steer_pct;
      u_steer_pct.base = 0;
      u_steer_pct.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steer_pct.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steer_pct.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steer_pct.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steer_pct = u_steer_pct.real;
      offset += sizeof(this->steer_pct);
      union {
        bool real;
        uint8_t base;
      } u_parking_brake_active;
      u_parking_brake_active.base = 0;
      u_parking_brake_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->parking_brake_active = u_parking_brake_active.real;
      offset += sizeof(this->parking_brake_active);
      union {
        bool real;
        uint8_t base;
      } u_high_beams_active;
      u_high_beams_active.base = 0;
      u_high_beams_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->high_beams_active = u_high_beams_active.real;
      offset += sizeof(this->high_beams_active);
      union {
        bool real;
        uint8_t base;
      } u_low_beams_active;
      u_low_beams_active.base = 0;
      u_low_beams_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->low_beams_active = u_low_beams_active.real;
      offset += sizeof(this->low_beams_active);
      union {
        bool real;
        uint8_t base;
      } u_hazard_lights_active;
      u_hazard_lights_active.base = 0;
      u_hazard_lights_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->hazard_lights_active = u_hazard_lights_active.real;
      offset += sizeof(this->hazard_lights_active);
      union {
        bool real;
        uint8_t base;
      } u_fog_lights_active;
      u_fog_lights_active.base = 0;
      u_fog_lights_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fog_lights_active = u_fog_lights_active.real;
      offset += sizeof(this->fog_lights_active);
      union {
        bool real;
        uint8_t base;
      } u_left_turn_signal_active;
      u_left_turn_signal_active.base = 0;
      u_left_turn_signal_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->left_turn_signal_active = u_left_turn_signal_active.real;
      offset += sizeof(this->left_turn_signal_active);
      union {
        bool real;
        uint8_t base;
      } u_right_turn_signal_active;
      u_right_turn_signal_active.base = 0;
      u_right_turn_signal_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->right_turn_signal_active = u_right_turn_signal_active.real;
      offset += sizeof(this->right_turn_signal_active);
      union {
        bool real;
        uint8_t base;
      } u_wipers_active;
      u_wipers_active.base = 0;
      u_wipers_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wipers_active = u_wipers_active.real;
      offset += sizeof(this->wipers_active);
      union {
        bool real;
        uint8_t base;
      } u_reverse_gear_active;
      u_reverse_gear_active.base = 0;
      u_reverse_gear_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reverse_gear_active = u_reverse_gear_active.real;
      offset += sizeof(this->reverse_gear_active);
      union {
        int8_t real;
        uint8_t base;
      } u_selected_gear;
      u_selected_gear.base = 0;
      u_selected_gear.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->selected_gear = u_selected_gear.real;
      offset += sizeof(this->selected_gear);
      union {
        bool real;
        uint8_t base;
      } u_engine_active;
      u_engine_active.base = 0;
      u_engine_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->engine_active = u_engine_active.real;
      offset += sizeof(this->engine_active);
      union {
        float real;
        uint32_t base;
      } u_engine_rpm;
      u_engine_rpm.base = 0;
      u_engine_rpm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_engine_rpm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_engine_rpm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_engine_rpm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->engine_rpm = u_engine_rpm.real;
      offset += sizeof(this->engine_rpm);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gps_latitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gps_longitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gps_altitude));
      offset += this->orientation.deserialize(inbuffer + offset);
      offset += this->linear_velocities.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "lgsvl_msgs/CanBusData"; };
    const char * getMD5(){ return "b87b5770e05e57bf8145ee83c4177b03"; };

  };

}
#endif