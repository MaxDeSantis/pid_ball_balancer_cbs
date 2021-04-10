#ifndef _ROS_pacmod_msgs_ShiftAuxRpt_h
#define _ROS_pacmod_msgs_ShiftAuxRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class ShiftAuxRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _between_gears_type;
      _between_gears_type between_gears;
      typedef bool _between_gears_is_valid_type;
      _between_gears_is_valid_type between_gears_is_valid;
      typedef bool _stay_in_neutral_mode_type;
      _stay_in_neutral_mode_type stay_in_neutral_mode;
      typedef bool _stay_in_neutral_mode_is_valid_type;
      _stay_in_neutral_mode_is_valid_type stay_in_neutral_mode_is_valid;
      typedef bool _brake_interlock_active_type;
      _brake_interlock_active_type brake_interlock_active;
      typedef bool _brake_interlock_active_is_valid_type;
      _brake_interlock_active_is_valid_type brake_interlock_active_is_valid;
      typedef bool _speed_interlock_active_type;
      _speed_interlock_active_type speed_interlock_active;
      typedef bool _speed_interlock_active_is_valid_type;
      _speed_interlock_active_is_valid_type speed_interlock_active_is_valid;
      typedef bool _gear_number_avail_type;
      _gear_number_avail_type gear_number_avail;
      typedef int8_t _gear_number_type;
      _gear_number_type gear_number;

    ShiftAuxRpt():
      header(),
      between_gears(0),
      between_gears_is_valid(0),
      stay_in_neutral_mode(0),
      stay_in_neutral_mode_is_valid(0),
      brake_interlock_active(0),
      brake_interlock_active_is_valid(0),
      speed_interlock_active(0),
      speed_interlock_active_is_valid(0),
      gear_number_avail(0),
      gear_number(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_between_gears;
      u_between_gears.real = this->between_gears;
      *(outbuffer + offset + 0) = (u_between_gears.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->between_gears);
      union {
        bool real;
        uint8_t base;
      } u_between_gears_is_valid;
      u_between_gears_is_valid.real = this->between_gears_is_valid;
      *(outbuffer + offset + 0) = (u_between_gears_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->between_gears_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_stay_in_neutral_mode;
      u_stay_in_neutral_mode.real = this->stay_in_neutral_mode;
      *(outbuffer + offset + 0) = (u_stay_in_neutral_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->stay_in_neutral_mode);
      union {
        bool real;
        uint8_t base;
      } u_stay_in_neutral_mode_is_valid;
      u_stay_in_neutral_mode_is_valid.real = this->stay_in_neutral_mode_is_valid;
      *(outbuffer + offset + 0) = (u_stay_in_neutral_mode_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->stay_in_neutral_mode_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_brake_interlock_active;
      u_brake_interlock_active.real = this->brake_interlock_active;
      *(outbuffer + offset + 0) = (u_brake_interlock_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->brake_interlock_active);
      union {
        bool real;
        uint8_t base;
      } u_brake_interlock_active_is_valid;
      u_brake_interlock_active_is_valid.real = this->brake_interlock_active_is_valid;
      *(outbuffer + offset + 0) = (u_brake_interlock_active_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->brake_interlock_active_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_speed_interlock_active;
      u_speed_interlock_active.real = this->speed_interlock_active;
      *(outbuffer + offset + 0) = (u_speed_interlock_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->speed_interlock_active);
      union {
        bool real;
        uint8_t base;
      } u_speed_interlock_active_is_valid;
      u_speed_interlock_active_is_valid.real = this->speed_interlock_active_is_valid;
      *(outbuffer + offset + 0) = (u_speed_interlock_active_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->speed_interlock_active_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_gear_number_avail;
      u_gear_number_avail.real = this->gear_number_avail;
      *(outbuffer + offset + 0) = (u_gear_number_avail.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gear_number_avail);
      union {
        int8_t real;
        uint8_t base;
      } u_gear_number;
      u_gear_number.real = this->gear_number;
      *(outbuffer + offset + 0) = (u_gear_number.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gear_number);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_between_gears;
      u_between_gears.base = 0;
      u_between_gears.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->between_gears = u_between_gears.real;
      offset += sizeof(this->between_gears);
      union {
        bool real;
        uint8_t base;
      } u_between_gears_is_valid;
      u_between_gears_is_valid.base = 0;
      u_between_gears_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->between_gears_is_valid = u_between_gears_is_valid.real;
      offset += sizeof(this->between_gears_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_stay_in_neutral_mode;
      u_stay_in_neutral_mode.base = 0;
      u_stay_in_neutral_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->stay_in_neutral_mode = u_stay_in_neutral_mode.real;
      offset += sizeof(this->stay_in_neutral_mode);
      union {
        bool real;
        uint8_t base;
      } u_stay_in_neutral_mode_is_valid;
      u_stay_in_neutral_mode_is_valid.base = 0;
      u_stay_in_neutral_mode_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->stay_in_neutral_mode_is_valid = u_stay_in_neutral_mode_is_valid.real;
      offset += sizeof(this->stay_in_neutral_mode_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_brake_interlock_active;
      u_brake_interlock_active.base = 0;
      u_brake_interlock_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->brake_interlock_active = u_brake_interlock_active.real;
      offset += sizeof(this->brake_interlock_active);
      union {
        bool real;
        uint8_t base;
      } u_brake_interlock_active_is_valid;
      u_brake_interlock_active_is_valid.base = 0;
      u_brake_interlock_active_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->brake_interlock_active_is_valid = u_brake_interlock_active_is_valid.real;
      offset += sizeof(this->brake_interlock_active_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_speed_interlock_active;
      u_speed_interlock_active.base = 0;
      u_speed_interlock_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->speed_interlock_active = u_speed_interlock_active.real;
      offset += sizeof(this->speed_interlock_active);
      union {
        bool real;
        uint8_t base;
      } u_speed_interlock_active_is_valid;
      u_speed_interlock_active_is_valid.base = 0;
      u_speed_interlock_active_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->speed_interlock_active_is_valid = u_speed_interlock_active_is_valid.real;
      offset += sizeof(this->speed_interlock_active_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_gear_number_avail;
      u_gear_number_avail.base = 0;
      u_gear_number_avail.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gear_number_avail = u_gear_number_avail.real;
      offset += sizeof(this->gear_number_avail);
      union {
        int8_t real;
        uint8_t base;
      } u_gear_number;
      u_gear_number.base = 0;
      u_gear_number.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gear_number = u_gear_number.real;
      offset += sizeof(this->gear_number);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/ShiftAuxRpt"; };
    const char * getMD5(){ return "dd3dcb724fff7aa8174cd1060347a710"; };

  };

}
#endif