#ifndef _ROS_autoware_msgs_ControlCommand_h
#define _ROS_autoware_msgs_ControlCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_msgs
{

  class ControlCommand : public ros::Msg
  {
    public:
      typedef float _linear_velocity_type;
      _linear_velocity_type linear_velocity;
      typedef float _linear_acceleration_type;
      _linear_acceleration_type linear_acceleration;
      typedef float _steering_angle_type;
      _steering_angle_type steering_angle;

    ControlCommand():
      linear_velocity(0),
      linear_acceleration(0),
      steering_angle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->linear_velocity);
      offset += serializeAvrFloat64(outbuffer + offset, this->linear_acceleration);
      offset += serializeAvrFloat64(outbuffer + offset, this->steering_angle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->linear_velocity));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->linear_acceleration));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->steering_angle));
     return offset;
    }

    const char * getType(){ return "autoware_msgs/ControlCommand"; };
    const char * getMD5(){ return "97bdb8c6dda03d6c6f5a1a98c32d26b8"; };

  };

}
#endif