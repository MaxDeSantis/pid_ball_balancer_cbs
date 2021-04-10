#ifndef _ROS_pacmod_msgs_HeadlightAuxRpt_h
#define _ROS_pacmod_msgs_HeadlightAuxRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class HeadlightAuxRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _headlights_on_type;
      _headlights_on_type headlights_on;
      typedef bool _headlights_on_is_valid_type;
      _headlights_on_is_valid_type headlights_on_is_valid;
      typedef bool _headlights_on_bright_type;
      _headlights_on_bright_type headlights_on_bright;
      typedef bool _headlights_on_bright_is_valid_type;
      _headlights_on_bright_is_valid_type headlights_on_bright_is_valid;
      typedef bool _fog_lights_on_type;
      _fog_lights_on_type fog_lights_on;
      typedef bool _fog_lights_on_is_valid_type;
      _fog_lights_on_is_valid_type fog_lights_on_is_valid;
      typedef uint8_t _headlights_mode_type;
      _headlights_mode_type headlights_mode;
      typedef bool _headlights_mode_is_valid_type;
      _headlights_mode_is_valid_type headlights_mode_is_valid;
      enum { HEADLIGHTS_OFF =  0 };
      enum { HEADLIGHTS_PARKING =  1 };
      enum { HEADLIGHTS_MANUAL =  2 };
      enum { HEADLIGHTS_AUTO =  3 };

    HeadlightAuxRpt():
      header(),
      headlights_on(0),
      headlights_on_is_valid(0),
      headlights_on_bright(0),
      headlights_on_bright_is_valid(0),
      fog_lights_on(0),
      fog_lights_on_is_valid(0),
      headlights_mode(0),
      headlights_mode_is_valid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_headlights_on;
      u_headlights_on.real = this->headlights_on;
      *(outbuffer + offset + 0) = (u_headlights_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->headlights_on);
      union {
        bool real;
        uint8_t base;
      } u_headlights_on_is_valid;
      u_headlights_on_is_valid.real = this->headlights_on_is_valid;
      *(outbuffer + offset + 0) = (u_headlights_on_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->headlights_on_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_headlights_on_bright;
      u_headlights_on_bright.real = this->headlights_on_bright;
      *(outbuffer + offset + 0) = (u_headlights_on_bright.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->headlights_on_bright);
      union {
        bool real;
        uint8_t base;
      } u_headlights_on_bright_is_valid;
      u_headlights_on_bright_is_valid.real = this->headlights_on_bright_is_valid;
      *(outbuffer + offset + 0) = (u_headlights_on_bright_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->headlights_on_bright_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_fog_lights_on;
      u_fog_lights_on.real = this->fog_lights_on;
      *(outbuffer + offset + 0) = (u_fog_lights_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fog_lights_on);
      union {
        bool real;
        uint8_t base;
      } u_fog_lights_on_is_valid;
      u_fog_lights_on_is_valid.real = this->fog_lights_on_is_valid;
      *(outbuffer + offset + 0) = (u_fog_lights_on_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fog_lights_on_is_valid);
      *(outbuffer + offset + 0) = (this->headlights_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->headlights_mode);
      union {
        bool real;
        uint8_t base;
      } u_headlights_mode_is_valid;
      u_headlights_mode_is_valid.real = this->headlights_mode_is_valid;
      *(outbuffer + offset + 0) = (u_headlights_mode_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->headlights_mode_is_valid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_headlights_on;
      u_headlights_on.base = 0;
      u_headlights_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->headlights_on = u_headlights_on.real;
      offset += sizeof(this->headlights_on);
      union {
        bool real;
        uint8_t base;
      } u_headlights_on_is_valid;
      u_headlights_on_is_valid.base = 0;
      u_headlights_on_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->headlights_on_is_valid = u_headlights_on_is_valid.real;
      offset += sizeof(this->headlights_on_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_headlights_on_bright;
      u_headlights_on_bright.base = 0;
      u_headlights_on_bright.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->headlights_on_bright = u_headlights_on_bright.real;
      offset += sizeof(this->headlights_on_bright);
      union {
        bool real;
        uint8_t base;
      } u_headlights_on_bright_is_valid;
      u_headlights_on_bright_is_valid.base = 0;
      u_headlights_on_bright_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->headlights_on_bright_is_valid = u_headlights_on_bright_is_valid.real;
      offset += sizeof(this->headlights_on_bright_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_fog_lights_on;
      u_fog_lights_on.base = 0;
      u_fog_lights_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fog_lights_on = u_fog_lights_on.real;
      offset += sizeof(this->fog_lights_on);
      union {
        bool real;
        uint8_t base;
      } u_fog_lights_on_is_valid;
      u_fog_lights_on_is_valid.base = 0;
      u_fog_lights_on_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fog_lights_on_is_valid = u_fog_lights_on_is_valid.real;
      offset += sizeof(this->fog_lights_on_is_valid);
      this->headlights_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->headlights_mode);
      union {
        bool real;
        uint8_t base;
      } u_headlights_mode_is_valid;
      u_headlights_mode_is_valid.base = 0;
      u_headlights_mode_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->headlights_mode_is_valid = u_headlights_mode_is_valid.real;
      offset += sizeof(this->headlights_mode_is_valid);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/HeadlightAuxRpt"; };
    const char * getMD5(){ return "512cf6494650979b84da331a515edaf9"; };

  };

}
#endif