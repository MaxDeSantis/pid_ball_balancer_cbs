#ifndef _ROS_autoware_msgs_SteerCmd_h
#define _ROS_autoware_msgs_SteerCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_msgs
{

  class SteerCmd : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _steer_type;
      _steer_type steer;

    SteerCmd():
      header(),
      steer(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_steer;
      u_steer.real = this->steer;
      *(outbuffer + offset + 0) = (u_steer.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steer.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steer.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steer.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steer);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_steer;
      u_steer.base = 0;
      u_steer.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steer.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steer.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steer.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steer = u_steer.real;
      offset += sizeof(this->steer);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/SteerCmd"; };
    const char * getMD5(){ return "a78f3e86a2d39111b18378b6ff89a1a1"; };

  };

}
#endif