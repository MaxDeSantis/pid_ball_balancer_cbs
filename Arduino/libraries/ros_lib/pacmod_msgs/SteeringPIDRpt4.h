#ifndef _ROS_pacmod_msgs_SteeringPIDRpt4_h
#define _ROS_pacmod_msgs_SteeringPIDRpt4_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class SteeringPIDRpt4 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _angular_velocity_type;
      _angular_velocity_type angular_velocity;
      typedef float _angular_acceleration_type;
      _angular_acceleration_type angular_acceleration;

    SteeringPIDRpt4():
      header(),
      angular_velocity(0),
      angular_acceleration(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->angular_velocity);
      offset += serializeAvrFloat64(outbuffer + offset, this->angular_acceleration);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angular_velocity));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angular_acceleration));
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/SteeringPIDRpt4"; };
    const char * getMD5(){ return "2bc4404ec9df7da4ed993a2081a68002"; };

  };

}
#endif