#ifndef _ROS_custom_msgs_BaroSensorSample_h
#define _ROS_custom_msgs_BaroSensorSample_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace custom_msgs
{

  class BaroSensorSample : public ros::Msg
  {
    public:
      typedef float _height_type;
      _height_type height;

    BaroSensorSample():
      height(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->height);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->height));
     return offset;
    }

    const char * getType(){ return "custom_msgs/BaroSensorSample"; };
    const char * getMD5(){ return "689e59833d9760375d61a82ed395adaf"; };

  };

}
#endif