#ifndef _ROS_pacmod_msgs_InteriorLightsRpt_h
#define _ROS_pacmod_msgs_InteriorLightsRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class InteriorLightsRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _front_dome_lights_on_type;
      _front_dome_lights_on_type front_dome_lights_on;
      typedef bool _front_dome_lights_on_is_valid_type;
      _front_dome_lights_on_is_valid_type front_dome_lights_on_is_valid;
      typedef bool _rear_dome_lights_on_type;
      _rear_dome_lights_on_type rear_dome_lights_on;
      typedef bool _rear_dome_lights_on_is_valid_type;
      _rear_dome_lights_on_is_valid_type rear_dome_lights_on_is_valid;
      typedef bool _mood_lights_on_type;
      _mood_lights_on_type mood_lights_on;
      typedef bool _mood_lights_on_is_valid_type;
      _mood_lights_on_is_valid_type mood_lights_on_is_valid;
      typedef uint8_t _dim_level_type;
      _dim_level_type dim_level;
      typedef bool _dim_level_is_valid_type;
      _dim_level_is_valid_type dim_level_is_valid;
      enum { DIM_LEVEL_MIN =  0 };
      enum { DIM_LEVEL_1 =  1 };
      enum { DIM_LEVEL_2 =  2 };
      enum { DIM_LEVEL_3 =  3 };
      enum { DIM_LEVEL_4 =  4 };
      enum { DIM_LEVEL_5 =  5 };
      enum { DIM_LEVEL_6 =  6 };
      enum { DIM_LEVEL_7 =  7 };
      enum { DIM_LEVEL_8 =  8 };
      enum { DIM_LEVEL_9 =  9 };
      enum { DIM_LEVEL_10 =  10 };
      enum { DIM_LEVEL_11 =  11 };
      enum { DIM_LEVEL_MAX =  12 };

    InteriorLightsRpt():
      header(),
      front_dome_lights_on(0),
      front_dome_lights_on_is_valid(0),
      rear_dome_lights_on(0),
      rear_dome_lights_on_is_valid(0),
      mood_lights_on(0),
      mood_lights_on_is_valid(0),
      dim_level(0),
      dim_level_is_valid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_front_dome_lights_on;
      u_front_dome_lights_on.real = this->front_dome_lights_on;
      *(outbuffer + offset + 0) = (u_front_dome_lights_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->front_dome_lights_on);
      union {
        bool real;
        uint8_t base;
      } u_front_dome_lights_on_is_valid;
      u_front_dome_lights_on_is_valid.real = this->front_dome_lights_on_is_valid;
      *(outbuffer + offset + 0) = (u_front_dome_lights_on_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->front_dome_lights_on_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_rear_dome_lights_on;
      u_rear_dome_lights_on.real = this->rear_dome_lights_on;
      *(outbuffer + offset + 0) = (u_rear_dome_lights_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rear_dome_lights_on);
      union {
        bool real;
        uint8_t base;
      } u_rear_dome_lights_on_is_valid;
      u_rear_dome_lights_on_is_valid.real = this->rear_dome_lights_on_is_valid;
      *(outbuffer + offset + 0) = (u_rear_dome_lights_on_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rear_dome_lights_on_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_mood_lights_on;
      u_mood_lights_on.real = this->mood_lights_on;
      *(outbuffer + offset + 0) = (u_mood_lights_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mood_lights_on);
      union {
        bool real;
        uint8_t base;
      } u_mood_lights_on_is_valid;
      u_mood_lights_on_is_valid.real = this->mood_lights_on_is_valid;
      *(outbuffer + offset + 0) = (u_mood_lights_on_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mood_lights_on_is_valid);
      *(outbuffer + offset + 0) = (this->dim_level >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dim_level);
      union {
        bool real;
        uint8_t base;
      } u_dim_level_is_valid;
      u_dim_level_is_valid.real = this->dim_level_is_valid;
      *(outbuffer + offset + 0) = (u_dim_level_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dim_level_is_valid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_front_dome_lights_on;
      u_front_dome_lights_on.base = 0;
      u_front_dome_lights_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->front_dome_lights_on = u_front_dome_lights_on.real;
      offset += sizeof(this->front_dome_lights_on);
      union {
        bool real;
        uint8_t base;
      } u_front_dome_lights_on_is_valid;
      u_front_dome_lights_on_is_valid.base = 0;
      u_front_dome_lights_on_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->front_dome_lights_on_is_valid = u_front_dome_lights_on_is_valid.real;
      offset += sizeof(this->front_dome_lights_on_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_rear_dome_lights_on;
      u_rear_dome_lights_on.base = 0;
      u_rear_dome_lights_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rear_dome_lights_on = u_rear_dome_lights_on.real;
      offset += sizeof(this->rear_dome_lights_on);
      union {
        bool real;
        uint8_t base;
      } u_rear_dome_lights_on_is_valid;
      u_rear_dome_lights_on_is_valid.base = 0;
      u_rear_dome_lights_on_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rear_dome_lights_on_is_valid = u_rear_dome_lights_on_is_valid.real;
      offset += sizeof(this->rear_dome_lights_on_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_mood_lights_on;
      u_mood_lights_on.base = 0;
      u_mood_lights_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mood_lights_on = u_mood_lights_on.real;
      offset += sizeof(this->mood_lights_on);
      union {
        bool real;
        uint8_t base;
      } u_mood_lights_on_is_valid;
      u_mood_lights_on_is_valid.base = 0;
      u_mood_lights_on_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mood_lights_on_is_valid = u_mood_lights_on_is_valid.real;
      offset += sizeof(this->mood_lights_on_is_valid);
      this->dim_level =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->dim_level);
      union {
        bool real;
        uint8_t base;
      } u_dim_level_is_valid;
      u_dim_level_is_valid.base = 0;
      u_dim_level_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->dim_level_is_valid = u_dim_level_is_valid.real;
      offset += sizeof(this->dim_level_is_valid);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/InteriorLightsRpt"; };
    const char * getMD5(){ return "edb83c466d141d95fcc059ad99141e5e"; };

  };

}
#endif