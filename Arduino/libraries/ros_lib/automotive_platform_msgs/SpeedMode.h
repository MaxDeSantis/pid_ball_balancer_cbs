#ifndef _ROS_automotive_platform_msgs_SpeedMode_h
#define _ROS_automotive_platform_msgs_SpeedMode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_platform_msgs
{

  class SpeedMode : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint16_t _mode_type;
      _mode_type mode;
      typedef float _speed_type;
      _speed_type speed;
      typedef float _acceleration_limit_type;
      _acceleration_limit_type acceleration_limit;
      typedef float _deceleration_limit_type;
      _deceleration_limit_type deceleration_limit;

    SpeedMode():
      header(),
      mode(0),
      speed(0),
      acceleration_limit(0),
      deceleration_limit(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mode >> (8 * 1)) & 0xFF;
      offset += sizeof(this->mode);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed);
      union {
        float real;
        uint32_t base;
      } u_acceleration_limit;
      u_acceleration_limit.real = this->acceleration_limit;
      *(outbuffer + offset + 0) = (u_acceleration_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acceleration_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acceleration_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acceleration_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acceleration_limit);
      union {
        float real;
        uint32_t base;
      } u_deceleration_limit;
      u_deceleration_limit.real = this->deceleration_limit;
      *(outbuffer + offset + 0) = (u_deceleration_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_deceleration_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_deceleration_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_deceleration_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->deceleration_limit);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->mode =  ((uint16_t) (*(inbuffer + offset)));
      this->mode |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->mode);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
      union {
        float real;
        uint32_t base;
      } u_acceleration_limit;
      u_acceleration_limit.base = 0;
      u_acceleration_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acceleration_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acceleration_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acceleration_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->acceleration_limit = u_acceleration_limit.real;
      offset += sizeof(this->acceleration_limit);
      union {
        float real;
        uint32_t base;
      } u_deceleration_limit;
      u_deceleration_limit.base = 0;
      u_deceleration_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_deceleration_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_deceleration_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_deceleration_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->deceleration_limit = u_deceleration_limit.real;
      offset += sizeof(this->deceleration_limit);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/SpeedMode"; };
    const char * getMD5(){ return "69d5c38e10a2546093c0ed4d98df906b"; };

  };

}
#endif