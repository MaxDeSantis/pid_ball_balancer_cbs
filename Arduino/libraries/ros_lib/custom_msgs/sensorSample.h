#ifndef _ROS_custom_msgs_sensorSample_h
#define _ROS_custom_msgs_sensorSample_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "custom_msgs/Internal.h"

namespace custom_msgs
{

  class sensorSample : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef custom_msgs::Internal _internal_type;
      _internal_type internal;

    sensorSample():
      header(),
      internal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->internal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->internal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "custom_msgs/sensorSample"; };
    const char * getMD5(){ return "a9ffa9fd1f9a3708555106a69d2bdf58"; };

  };

}
#endif