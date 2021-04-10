#ifndef _ROS_pacmod_msgs_MotorRpt2_h
#define _ROS_pacmod_msgs_MotorRpt2_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class MotorRpt2 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _encoder_temp_type;
      _encoder_temp_type encoder_temp;
      typedef float _motor_temp_type;
      _motor_temp_type motor_temp;
      typedef float _angular_velocity_type;
      _angular_velocity_type angular_velocity;

    MotorRpt2():
      header(),
      encoder_temp(0),
      motor_temp(0),
      angular_velocity(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->encoder_temp);
      offset += serializeAvrFloat64(outbuffer + offset, this->motor_temp);
      offset += serializeAvrFloat64(outbuffer + offset, this->angular_velocity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->encoder_temp));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->motor_temp));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angular_velocity));
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/MotorRpt2"; };
    const char * getMD5(){ return "d757953b36f8ffe8db6389da9ff787a1"; };

  };

}
#endif