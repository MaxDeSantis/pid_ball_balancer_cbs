#ifndef _ROS_automotive_platform_msgs_AdaptiveCruiseControlSettings_h
#define _ROS_automotive_platform_msgs_AdaptiveCruiseControlSettings_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_platform_msgs
{

  class AdaptiveCruiseControlSettings : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _set_speed_type;
      _set_speed_type set_speed;
      typedef uint16_t _following_spot_type;
      _following_spot_type following_spot;
      typedef float _min_percent_type;
      _min_percent_type min_percent;
      typedef float _step_percent_type;
      _step_percent_type step_percent;
      typedef float _cipv_percent_type;
      _cipv_percent_type cipv_percent;
      typedef float _max_distance_type;
      _max_distance_type max_distance;

    AdaptiveCruiseControlSettings():
      header(),
      set_speed(0),
      following_spot(0),
      min_percent(0),
      step_percent(0),
      cipv_percent(0),
      max_distance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_set_speed;
      u_set_speed.real = this->set_speed;
      *(outbuffer + offset + 0) = (u_set_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_set_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_set_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_set_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->set_speed);
      *(outbuffer + offset + 0) = (this->following_spot >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->following_spot >> (8 * 1)) & 0xFF;
      offset += sizeof(this->following_spot);
      union {
        float real;
        uint32_t base;
      } u_min_percent;
      u_min_percent.real = this->min_percent;
      *(outbuffer + offset + 0) = (u_min_percent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_percent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_percent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_percent.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_percent);
      union {
        float real;
        uint32_t base;
      } u_step_percent;
      u_step_percent.real = this->step_percent;
      *(outbuffer + offset + 0) = (u_step_percent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_step_percent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_step_percent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_step_percent.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->step_percent);
      union {
        float real;
        uint32_t base;
      } u_cipv_percent;
      u_cipv_percent.real = this->cipv_percent;
      *(outbuffer + offset + 0) = (u_cipv_percent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cipv_percent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cipv_percent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cipv_percent.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cipv_percent);
      union {
        float real;
        uint32_t base;
      } u_max_distance;
      u_max_distance.real = this->max_distance;
      *(outbuffer + offset + 0) = (u_max_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_distance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_set_speed;
      u_set_speed.base = 0;
      u_set_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_set_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_set_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_set_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->set_speed = u_set_speed.real;
      offset += sizeof(this->set_speed);
      this->following_spot =  ((uint16_t) (*(inbuffer + offset)));
      this->following_spot |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->following_spot);
      union {
        float real;
        uint32_t base;
      } u_min_percent;
      u_min_percent.base = 0;
      u_min_percent.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_percent.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_percent.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_percent.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_percent = u_min_percent.real;
      offset += sizeof(this->min_percent);
      union {
        float real;
        uint32_t base;
      } u_step_percent;
      u_step_percent.base = 0;
      u_step_percent.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_step_percent.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_step_percent.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_step_percent.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->step_percent = u_step_percent.real;
      offset += sizeof(this->step_percent);
      union {
        float real;
        uint32_t base;
      } u_cipv_percent;
      u_cipv_percent.base = 0;
      u_cipv_percent.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cipv_percent.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cipv_percent.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cipv_percent.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cipv_percent = u_cipv_percent.real;
      offset += sizeof(this->cipv_percent);
      union {
        float real;
        uint32_t base;
      } u_max_distance;
      u_max_distance.base = 0;
      u_max_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_distance = u_max_distance.real;
      offset += sizeof(this->max_distance);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/AdaptiveCruiseControlSettings"; };
    const char * getMD5(){ return "0b4d1a2cc78ca8e10ffb5792b0e4db08"; };

  };

}
#endif