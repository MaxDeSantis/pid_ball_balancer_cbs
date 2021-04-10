#ifndef _ROS_pacmod_msgs_MotorRpt3_h
#define _ROS_pacmod_msgs_MotorRpt3_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class MotorRpt3 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _torque_output_type;
      _torque_output_type torque_output;
      typedef float _torque_input_type;
      _torque_input_type torque_input;

    MotorRpt3():
      header(),
      torque_output(0),
      torque_input(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->torque_output);
      offset += serializeAvrFloat64(outbuffer + offset, this->torque_input);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->torque_output));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->torque_input));
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/MotorRpt3"; };
    const char * getMD5(){ return "1640bb8a85b4353a76a6e6a5df503313"; };

  };

}
#endif