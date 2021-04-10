#ifndef _ROS_pacmod_msgs_PacmodCmd_h
#define _ROS_pacmod_msgs_PacmodCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class PacmodCmd : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _f64_cmd_type;
      _f64_cmd_type f64_cmd;
      typedef uint16_t _ui16_cmd_type;
      _ui16_cmd_type ui16_cmd;
      typedef bool _enable_type;
      _enable_type enable;
      typedef bool _clear_type;
      _clear_type clear;
      typedef bool _ignore_type;
      _ignore_type ignore;
      enum { TURN_RIGHT =  0 };
      enum { TURN_NONE =  1 };
      enum { TURN_LEFT =  2 };
      enum { TURN_HAZARDS =  3 };
      enum { SHIFT_PARK =  0 };
      enum { SHIFT_REVERSE =  1 };
      enum { SHIFT_NEUTRAL =  2 };
      enum { SHIFT_FORWARD =  3 };
      enum { SHIFT_HIGH =  3  };
      enum { SHIFT_LOW =  4 };

    PacmodCmd():
      header(),
      f64_cmd(0),
      ui16_cmd(0),
      enable(0),
      clear(0),
      ignore(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->f64_cmd);
      *(outbuffer + offset + 0) = (this->ui16_cmd >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ui16_cmd >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ui16_cmd);
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
      } u_clear;
      u_clear.real = this->clear;
      *(outbuffer + offset + 0) = (u_clear.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clear);
      union {
        bool real;
        uint8_t base;
      } u_ignore;
      u_ignore.real = this->ignore;
      *(outbuffer + offset + 0) = (u_ignore.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ignore);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->f64_cmd));
      this->ui16_cmd =  ((uint16_t) (*(inbuffer + offset)));
      this->ui16_cmd |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->ui16_cmd);
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
      } u_clear;
      u_clear.base = 0;
      u_clear.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clear = u_clear.real;
      offset += sizeof(this->clear);
      union {
        bool real;
        uint8_t base;
      } u_ignore;
      u_ignore.base = 0;
      u_ignore.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ignore = u_ignore.real;
      offset += sizeof(this->ignore);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/PacmodCmd"; };
    const char * getMD5(){ return "5651e3d1d38e01689421d6d8a4e924f6"; };

  };

}
#endif