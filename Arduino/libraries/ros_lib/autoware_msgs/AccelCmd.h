#ifndef _ROS_autoware_msgs_AccelCmd_h
#define _ROS_autoware_msgs_AccelCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_msgs
{

  class AccelCmd : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _accel_type;
      _accel_type accel;

    AccelCmd():
      header(),
      accel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_accel;
      u_accel.real = this->accel;
      *(outbuffer + offset + 0) = (u_accel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_accel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_accel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_accel;
      u_accel.base = 0;
      u_accel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_accel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_accel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->accel = u_accel.real;
      offset += sizeof(this->accel);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/AccelCmd"; };
    const char * getMD5(){ return "a93722f4689381b03f4eb4c0b2c4a748"; };

  };

}
#endif