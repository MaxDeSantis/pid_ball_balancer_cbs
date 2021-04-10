#ifndef _ROS_automotive_platform_msgs_HillStartAssist_h
#define _ROS_automotive_platform_msgs_HillStartAssist_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_platform_msgs
{

  class HillStartAssist : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _active_type;
      _active_type active;

    HillStartAssist():
      header(),
      active(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_active;
      u_active.real = this->active;
      *(outbuffer + offset + 0) = (u_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->active);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_active;
      u_active.base = 0;
      u_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->active = u_active.real;
      offset += sizeof(this->active);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/HillStartAssist"; };
    const char * getMD5(){ return "c17028b064a3857c9cf5363ecb14febb"; };

  };

}
#endif