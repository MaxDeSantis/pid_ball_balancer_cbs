#ifndef _ROS_pacmod_msgs_SystemCmdBool_h
#define _ROS_pacmod_msgs_SystemCmdBool_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class SystemCmdBool : public ros::Msg
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
      typedef bool _command_type;
      _command_type command;

    SystemCmdBool():
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
      union {
        bool real;
        uint8_t base;
      } u_command;
      u_command.real = this->command;
      *(outbuffer + offset + 0) = (u_command.base >> (8 * 0)) & 0xFF;
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
      union {
        bool real;
        uint8_t base;
      } u_command;
      u_command.base = 0;
      u_command.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->command = u_command.real;
      offset += sizeof(this->command);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/SystemCmdBool"; };
    const char * getMD5(){ return "ebee3259c3c8f34dec0d921f3c0fa804"; };

  };

}
#endif