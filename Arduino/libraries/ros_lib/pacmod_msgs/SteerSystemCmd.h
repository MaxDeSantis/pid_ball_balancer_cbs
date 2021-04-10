#ifndef _ROS_pacmod_msgs_SteerSystemCmd_h
#define _ROS_pacmod_msgs_SteerSystemCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class SteerSystemCmd : public ros::Msg
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
      typedef float _command_type;
      _command_type command;
      typedef float _rotation_rate_type;
      _rotation_rate_type rotation_rate;

    SteerSystemCmd():
      header(),
      enable(0),
      ignore_overrides(0),
      clear_override(0),
      clear_faults(0),
      command(0),
      rotation_rate(0)
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
      offset += serializeAvrFloat64(outbuffer + offset, this->command);
      offset += serializeAvrFloat64(outbuffer + offset, this->rotation_rate);
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->command));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rotation_rate));
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/SteerSystemCmd"; };
    const char * getMD5(){ return "cfa0df9428e1c56b79ca986e115663f7"; };

  };

}
#endif