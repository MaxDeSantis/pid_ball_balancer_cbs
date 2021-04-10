#ifndef _ROS_pacmod_msgs_SteeringPIDRpt3_h
#define _ROS_pacmod_msgs_SteeringPIDRpt3_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class SteeringPIDRpt3 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _new_torque_type;
      _new_torque_type new_torque;
      typedef float _str_angle_desired_type;
      _str_angle_desired_type str_angle_desired;
      typedef float _str_angle_actual_type;
      _str_angle_actual_type str_angle_actual;
      typedef float _error_type;
      _error_type error;

    SteeringPIDRpt3():
      header(),
      new_torque(0),
      str_angle_desired(0),
      str_angle_actual(0),
      error(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->new_torque);
      offset += serializeAvrFloat64(outbuffer + offset, this->str_angle_desired);
      offset += serializeAvrFloat64(outbuffer + offset, this->str_angle_actual);
      offset += serializeAvrFloat64(outbuffer + offset, this->error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->new_torque));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->str_angle_desired));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->str_angle_actual));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->error));
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/SteeringPIDRpt3"; };
    const char * getMD5(){ return "722f63b47fd2935245656ab58fbec284"; };

  };

}
#endif