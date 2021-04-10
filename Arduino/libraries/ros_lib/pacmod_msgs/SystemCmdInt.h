#ifndef _ROS_pacmod_msgs_SystemCmdInt_h
#define _ROS_pacmod_msgs_SystemCmdInt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class SystemCmdInt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _enable_type;
      _enable_type enable;
      typedef bool _ignore_overrides_type;
      _ignore_overrides_type ignore_overrides;
      typedef bool _clear_override_type;
      _clear_override_type clear_override;
      typedef bool _clear_faults_type;
      _clear_faults_type clear_faults;
      typedef uint16_t _command_type;
      _command_type command;
      enum { CRUISE_CONTROL_NONE =  0 };
      enum { CRUISE_CONTROL_CNCL =  1 };
      enum { CRUISE_CONTROL_ACC_FURTHER =  2 };
      enum { CRUISE_CONTROL_ACC_CLOSER =  3 };
      enum { CRUISE_CONTROL_SET_DEC =  4 };
      enum { CRUISE_CONTROL_RES_INC =  5 };
      enum { DASH_CONTROL_NONE =  0 };
      enum { DASH_CONTROL_OK =  1 };
      enum { DASH_CONTROL_LEFT =  2 };
      enum { DASH_CONTROL_RIGHT =  3 };
      enum { DASH_CONTROL_UP =  4 };
      enum { DASH_CONTROL_DOWN =  5 };
      enum { HEADLIGHTS_OFF =  0 };
      enum { HEADLIGHTS_PARKING_ONLY =  1 };
      enum { HEADLIGHTS_MANUAL_LOW =  2 };
      enum { HEADLIGHTS_MANUAL_HIGH =  3 };
      enum { HEADLIGHTS_AUTO_LOW =  4 };
      enum { HEADLIGHTS_AUTO_HIGH =  5 };
      enum { MEDIA_CONTROL_NONE =  0 };
      enum { MEDIA_CONTROL_VOICE_COMMAND =  1 };
      enum { MEDIA_CONTROL_MUTE =  2 };
      enum { MEDIA_CONTROL_PREV_TRACK_ANSWER =  3 };
      enum { MEDIA_CONTROL_NEXT_TRACK_HANG_UP =  4 };
      enum { MEDIA_CONTROL_VOL_UP =  5 };
      enum { MEDIA_CONTROL_VOL_DOWN =  6 };
      enum { SHIFT_PARK =  0 };
      enum { SHIFT_REVERSE =  1 };
      enum { SHIFT_NEUTRAL =  2 };
      enum { SHIFT_HIGH =  3 };
      enum { SHIFT_FORWARD =  3 };
      enum { SHIFT_LOW =  4 };
      enum { SHIFT_NONE =  7 };
      enum { TURN_RIGHT =  0 };
      enum { TURN_NONE =  1 };
      enum { TURN_LEFT =  2 };
      enum { TURN_HAZARDS =  3 };
      enum { DOOR_NEUTRAL =  0 };
      enum { DOOR_OPEN =  1 };
      enum { DOOR_CLOSE =  2 };
      enum { WIPERS_OFF =  0 };
      enum { WIPERS_INT_1 =  1 };
      enum { WIPERS_INT_2 =  2 };
      enum { WIPERS_INT_3 =  3 };
      enum { WIPERS_INT_4 =  4 };
      enum { WIPERS_INT_5 =  5 };
      enum { WIPERS_INT_6 =  6 };
      enum { WIPERS_MEDIUM =  7 };
      enum { WIPERS_HIGH =  8 };

    SystemCmdInt():
      header(),
      enable(0),
      ignore_overrides(0),
      clear_override(0),
      clear_faults(0),
      command(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_enable;
      u_enable.real = this->enable;
      *(outbuffer + offset + 0) = (u_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable);
      union {
        bool real;
        uint8_t base;
      } u_ignore_overrides;
      u_ignore_overrides.real = this->ignore_overrides;
      *(outbuffer + offset + 0) = (u_ignore_overrides.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ignore_overrides);
      union {
        bool real;
        uint8_t base;
      } u_clear_override;
      u_clear_override.real = this->clear_override;
      *(outbuffer + offset + 0) = (u_clear_override.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clear_override);
      union {
        bool real;
        uint8_t base;
      } u_clear_faults;
      u_clear_faults.real = this->clear_faults;
      *(outbuffer + offset + 0) = (u_clear_faults.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clear_faults);
      *(outbuffer + offset + 0) = (this->command >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->command >> (8 * 1)) & 0xFF;
      offset += sizeof(this->command);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_enable;
      u_enable.base = 0;
      u_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable = u_enable.real;
      offset += sizeof(this->enable);
      union {
        bool real;
        uint8_t base;
      } u_ignore_overrides;
      u_ignore_overrides.base = 0;
      u_ignore_overrides.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ignore_overrides = u_ignore_overrides.real;
      offset += sizeof(this->ignore_overrides);
      union {
        bool real;
        uint8_t base;
      } u_clear_override;
      u_clear_override.base = 0;
      u_clear_override.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clear_override = u_clear_override.real;
      offset += sizeof(this->clear_override);
      union {
        bool real;
        uint8_t base;
      } u_clear_faults;
      u_clear_faults.base = 0;
      u_clear_faults.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clear_faults = u_clear_faults.real;
      offset += sizeof(this->clear_faults);
      this->command =  ((uint16_t) (*(inbuffer + offset)));
      this->command |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->command);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/SystemCmdInt"; };
    const char * getMD5(){ return "843586c2df7a468d7cc89fb9df7fa2c2"; };

  };

}
#endif