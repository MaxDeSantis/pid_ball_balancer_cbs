#ifndef _ROS_pacmod_msgs_PositionWithSpeed_h
#define _ROS_pacmod_msgs_PositionWithSpeed_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class PositionWithSpeed : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _angular_position_type;
      _angular_position_type angular_position;
      typedef float _angular_velocity_limit_type;
      _angular_velocity_limit_type angular_velocity_limit;

    PositionWithSpeed():
      header(),
      angular_position(0),
      angular_velocity_limit(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->angular_position);
      offset += serializeAvrFloat64(outbuffer + offset, this->angular_velocity_limit);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angular_position));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angular_velocity_limit));
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/PositionWithSpeed"; };
    const char * getMD5(){ return "7e96a8c8cbc8234d4d2c87880ddb7cfe"; };

  };

}
#endif