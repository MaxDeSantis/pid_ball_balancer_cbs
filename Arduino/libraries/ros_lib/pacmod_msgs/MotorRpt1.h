#ifndef _ROS_pacmod_msgs_MotorRpt1_h
#define _ROS_pacmod_msgs_MotorRpt1_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class MotorRpt1 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _current_type;
      _current_type current;
      typedef float _position_type;
      _position_type position;

    MotorRpt1():
      header(),
      current(0),
      position(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->current);
      offset += serializeAvrFloat64(outbuffer + offset, this->position);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->current));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position));
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/MotorRpt1"; };
    const char * getMD5(){ return "bc762724eccc08e26b60b6284460fe26"; };

  };

}
#endif