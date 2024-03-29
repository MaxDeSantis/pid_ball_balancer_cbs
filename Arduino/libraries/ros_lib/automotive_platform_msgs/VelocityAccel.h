#ifndef _ROS_automotive_platform_msgs_VelocityAccel_h
#define _ROS_automotive_platform_msgs_VelocityAccel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_platform_msgs
{

  class VelocityAccel : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _velocity_type;
      _velocity_type velocity;
      typedef float _accleration_type;
      _accleration_type accleration;

    VelocityAccel():
      header(),
      velocity(0),
      accleration(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.real = this->velocity;
      *(outbuffer + offset + 0) = (u_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity);
      union {
        float real;
        uint32_t base;
      } u_accleration;
      u_accleration.real = this->accleration;
      *(outbuffer + offset + 0) = (u_accleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_accleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_accleration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accleration);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.base = 0;
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity = u_velocity.real;
      offset += sizeof(this->velocity);
      union {
        float real;
        uint32_t base;
      } u_accleration;
      u_accleration.base = 0;
      u_accleration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accleration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_accleration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_accleration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->accleration = u_accleration.real;
      offset += sizeof(this->accleration);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/VelocityAccel"; };
    const char * getMD5(){ return "f9f86d6cc8bf87a22c9bcce69cd571b2"; };

  };

}
#endif