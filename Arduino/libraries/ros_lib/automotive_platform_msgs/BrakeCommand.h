#ifndef _ROS_automotive_platform_msgs_BrakeCommand_h
#define _ROS_automotive_platform_msgs_BrakeCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_platform_msgs
{

  class BrakeCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _brake_pedal_type;
      _brake_pedal_type brake_pedal;

    BrakeCommand():
      header(),
      brake_pedal(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_brake_pedal;
      u_brake_pedal.real = this->brake_pedal;
      *(outbuffer + offset + 0) = (u_brake_pedal.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_brake_pedal.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_brake_pedal.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_brake_pedal.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->brake_pedal);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_brake_pedal;
      u_brake_pedal.base = 0;
      u_brake_pedal.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_brake_pedal.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_brake_pedal.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_brake_pedal.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->brake_pedal = u_brake_pedal.real;
      offset += sizeof(this->brake_pedal);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/BrakeCommand"; };
    const char * getMD5(){ return "2e19ae4283bff8e4baca0a8af4d4961e"; };

  };

}
#endif