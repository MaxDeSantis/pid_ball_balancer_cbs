#ifndef _ROS_custom_msgs_positionEstimate_h
#define _ROS_custom_msgs_positionEstimate_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace custom_msgs
{

  class positionEstimate : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _latitude_type;
      _latitude_type latitude;
      typedef float _longitude_type;
      _longitude_type longitude;
      typedef float _hEll_type;
      _hEll_type hEll;

    positionEstimate():
      header(),
      latitude(0),
      longitude(0),
      hEll(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->latitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->longitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->hEll);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->latitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->longitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->hEll));
     return offset;
    }

    const char * getType(){ return "custom_msgs/positionEstimate"; };
    const char * getMD5(){ return "3684d34dfe30f7d6456bbd35381e6d7a"; };

  };

}
#endif