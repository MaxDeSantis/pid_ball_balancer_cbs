#ifndef _ROS_custom_msgs_velocityEstimate_h
#define _ROS_custom_msgs_velocityEstimate_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace custom_msgs
{

  class velocityEstimate : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _velE_type;
      _velE_type velE;
      typedef float _velN_type;
      _velN_type velN;
      typedef float _velU_type;
      _velU_type velU;

    velocityEstimate():
      header(),
      velE(0),
      velN(0),
      velU(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->velE);
      offset += serializeAvrFloat64(outbuffer + offset, this->velN);
      offset += serializeAvrFloat64(outbuffer + offset, this->velU);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velE));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velN));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velU));
     return offset;
    }

    const char * getType(){ return "custom_msgs/velocityEstimate"; };
    const char * getMD5(){ return "61406b2619738bd0fe334780af479020"; };

  };

}
#endif