#ifndef _ROS_automotive_platform_msgs_ThrottleFeedback_h
#define _ROS_automotive_platform_msgs_ThrottleFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_platform_msgs
{

  class ThrottleFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _throttle_pedal_type;
      _throttle_pedal_type throttle_pedal;

    ThrottleFeedback():
      header(),
      throttle_pedal(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_throttle_pedal;
      u_throttle_pedal.real = this->throttle_pedal;
      *(outbuffer + offset + 0) = (u_throttle_pedal.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_throttle_pedal.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_throttle_pedal.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_throttle_pedal.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->throttle_pedal);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_throttle_pedal;
      u_throttle_pedal.base = 0;
      u_throttle_pedal.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_throttle_pedal.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_throttle_pedal.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_throttle_pedal.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->throttle_pedal = u_throttle_pedal.real;
      offset += sizeof(this->throttle_pedal);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/ThrottleFeedback"; };
    const char * getMD5(){ return "e5121b671d09b4686521aac007acd4bd"; };

  };

}
#endif