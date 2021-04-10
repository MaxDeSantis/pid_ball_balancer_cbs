#ifndef _ROS_custom_msgs_baroSample_h
#define _ROS_custom_msgs_baroSample_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace custom_msgs
{

  class baroSample : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _height_type;
      _height_type height;

    baroSample():
      header(),
      height(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->height);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->height));
     return offset;
    }

    const char * getType(){ return "custom_msgs/baroSample"; };
    const char * getMD5(){ return "1b96bb17a3786a696442a57cb0232657"; };

  };

}
#endif