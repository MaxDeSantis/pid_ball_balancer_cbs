#ifndef _ROS_autoware_msgs_BrakeCmd_h
#define _ROS_autoware_msgs_BrakeCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_msgs
{

  class BrakeCmd : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _brake_type;
      _brake_type brake;

    BrakeCmd():
      header(),
      brake(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_brake;
      u_brake.real = this->brake;
      *(outbuffer + offset + 0) = (u_brake.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_brake.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_brake.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_brake.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->brake);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_brake;
      u_brake.base = 0;
      u_brake.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_brake.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_brake.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_brake.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->brake = u_brake.real;
      offset += sizeof(this->brake);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/BrakeCmd"; };
    const char * getMD5(){ return "5705431e779f450d71c11d56d5a2d8ed"; };

  };

}
#endif