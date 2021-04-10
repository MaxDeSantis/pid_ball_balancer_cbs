#ifndef _ROS_pacmod_msgs_SteeringPIDRpt1_h
#define _ROS_pacmod_msgs_SteeringPIDRpt1_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class SteeringPIDRpt1 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _dt_type;
      _dt_type dt;
      typedef float _kp_type;
      _kp_type kp;
      typedef float _ki_type;
      _ki_type ki;
      typedef float _kd_type;
      _kd_type kd;

    SteeringPIDRpt1():
      header(),
      dt(0),
      kp(0),
      ki(0),
      kd(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->dt);
      offset += serializeAvrFloat64(outbuffer + offset, this->kp);
      offset += serializeAvrFloat64(outbuffer + offset, this->ki);
      offset += serializeAvrFloat64(outbuffer + offset, this->kd);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->dt));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->kp));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ki));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->kd));
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/SteeringPIDRpt1"; };
    const char * getMD5(){ return "249e50a60130616c86a15f47dc12d9b9"; };

  };

}
#endif