#ifndef _ROS_pacmod_msgs_RearLightsRpt_h
#define _ROS_pacmod_msgs_RearLightsRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class RearLightsRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _brake_lights_on_type;
      _brake_lights_on_type brake_lights_on;
      typedef bool _brake_lights_on_is_valid_type;
      _brake_lights_on_is_valid_type brake_lights_on_is_valid;
      typedef bool _reverse_lights_on_type;
      _reverse_lights_on_type reverse_lights_on;
      typedef bool _reverse_lights_on_is_valid_type;
      _reverse_lights_on_is_valid_type reverse_lights_on_is_valid;

    RearLightsRpt():
      header(),
      brake_lights_on(0),
      brake_lights_on_is_valid(0),
      reverse_lights_on(0),
      reverse_lights_on_is_valid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_brake_lights_on;
      u_brake_lights_on.real = this->brake_lights_on;
      *(outbuffer + offset + 0) = (u_brake_lights_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->brake_lights_on);
      union {
        bool real;
        uint8_t base;
      } u_brake_lights_on_is_valid;
      u_brake_lights_on_is_valid.real = this->brake_lights_on_is_valid;
      *(outbuffer + offset + 0) = (u_brake_lights_on_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->brake_lights_on_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_reverse_lights_on;
      u_reverse_lights_on.real = this->reverse_lights_on;
      *(outbuffer + offset + 0) = (u_reverse_lights_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reverse_lights_on);
      union {
        bool real;
        uint8_t base;
      } u_reverse_lights_on_is_valid;
      u_reverse_lights_on_is_valid.real = this->reverse_lights_on_is_valid;
      *(outbuffer + offset + 0) = (u_reverse_lights_on_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reverse_lights_on_is_valid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_brake_lights_on;
      u_brake_lights_on.base = 0;
      u_brake_lights_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->brake_lights_on = u_brake_lights_on.real;
      offset += sizeof(this->brake_lights_on);
      union {
        bool real;
        uint8_t base;
      } u_brake_lights_on_is_valid;
      u_brake_lights_on_is_valid.base = 0;
      u_brake_lights_on_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->brake_lights_on_is_valid = u_brake_lights_on_is_valid.real;
      offset += sizeof(this->brake_lights_on_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_reverse_lights_on;
      u_reverse_lights_on.base = 0;
      u_reverse_lights_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reverse_lights_on = u_reverse_lights_on.real;
      offset += sizeof(this->reverse_lights_on);
      union {
        bool real;
        uint8_t base;
      } u_reverse_lights_on_is_valid;
      u_reverse_lights_on_is_valid.base = 0;
      u_reverse_lights_on_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reverse_lights_on_is_valid = u_reverse_lights_on_is_valid.real;
      offset += sizeof(this->reverse_lights_on_is_valid);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/RearLightsRpt"; };
    const char * getMD5(){ return "5adfcaa5d9423963ef8c117009d03bbe"; };

  };

}
#endif