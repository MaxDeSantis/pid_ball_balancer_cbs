#ifndef _ROS_autoware_msgs_IndicatorCmd_h
#define _ROS_autoware_msgs_IndicatorCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_msgs
{

  class IndicatorCmd : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _l_type;
      _l_type l;
      typedef int32_t _r_type;
      _r_type r;

    IndicatorCmd():
      header(),
      l(0),
      r(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_l;
      u_l.real = this->l;
      *(outbuffer + offset + 0) = (u_l.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_l.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_l.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_l.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->l);
      union {
        int32_t real;
        uint32_t base;
      } u_r;
      u_r.real = this->r;
      *(outbuffer + offset + 0) = (u_r.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_r.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_r.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_r.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->r);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_l;
      u_l.base = 0;
      u_l.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_l.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_l.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_l.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->l = u_l.real;
      offset += sizeof(this->l);
      union {
        int32_t real;
        uint32_t base;
      } u_r;
      u_r.base = 0;
      u_r.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_r.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_r.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_r.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->r = u_r.real;
      offset += sizeof(this->r);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/IndicatorCmd"; };
    const char * getMD5(){ return "f01795e0c1fa842f366906ad189e0f0a"; };

  };

}
#endif