#ifndef _ROS_automotive_platform_msgs_SteerWheel_h
#define _ROS_automotive_platform_msgs_SteerWheel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_platform_msgs
{

  class SteerWheel : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint16_t _mode_type;
      _mode_type mode;
      typedef float _angle_type;
      _angle_type angle;
      typedef float _angle_velocity_type;
      _angle_velocity_type angle_velocity;

    SteerWheel():
      header(),
      mode(0),
      angle(0),
      angle_velocity(0)
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
      } u_angle;
      u_angle.real = this->angle;
      *(outbuffer + offset + 0) = (u_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle);
      union {
        float real;
        uint32_t base;
      } u_angle_velocity;
      u_angle_velocity.real = this->angle_velocity;
      *(outbuffer + offset + 0) = (u_angle_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_velocity);
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
      } u_angle;
      u_angle.base = 0;
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle = u_angle.real;
      offset += sizeof(this->angle);
      union {
        float real;
        uint32_t base;
      } u_angle_velocity;
      u_angle_velocity.base = 0;
      u_angle_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_velocity = u_angle_velocity.real;
      offset += sizeof(this->angle_velocity);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/SteerWheel"; };
    const char * getMD5(){ return "3c61b8a39f0555662752d160f35b72c0"; };

  };

}
#endif