#ifndef _ROS_pacmod_msgs_YawRateRpt_h
#define _ROS_pacmod_msgs_YawRateRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class YawRateRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _yaw_rate_type;
      _yaw_rate_type yaw_rate;

    YawRateRpt():
      header(),
      yaw_rate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->yaw_rate);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->yaw_rate));
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/YawRateRpt"; };
    const char * getMD5(){ return "8bdabba36ff5a4751eb3ad99f74991ca"; };

  };

}
#endif