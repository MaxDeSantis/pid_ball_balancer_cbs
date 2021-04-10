#ifndef _ROS_pacmod_msgs_SteeringPIDRpt2_h
#define _ROS_pacmod_msgs_SteeringPIDRpt2_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class SteeringPIDRpt2 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _p_term_type;
      _p_term_type p_term;
      typedef float _i_term_type;
      _i_term_type i_term;
      typedef float _d_term_type;
      _d_term_type d_term;
      typedef float _all_terms_type;
      _all_terms_type all_terms;

    SteeringPIDRpt2():
      header(),
      p_term(0),
      i_term(0),
      d_term(0),
      all_terms(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->p_term);
      offset += serializeAvrFloat64(outbuffer + offset, this->i_term);
      offset += serializeAvrFloat64(outbuffer + offset, this->d_term);
      offset += serializeAvrFloat64(outbuffer + offset, this->all_terms);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->p_term));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->i_term));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->d_term));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->all_terms));
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/SteeringPIDRpt2"; };
    const char * getMD5(){ return "1adfcb7e7b84f38f1763878f5d8e8ff5"; };

  };

}
#endif