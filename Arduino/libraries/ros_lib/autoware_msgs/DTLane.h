#ifndef _ROS_autoware_msgs_DTLane_h
#define _ROS_autoware_msgs_DTLane_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_msgs
{

  class DTLane : public ros::Msg
  {
    public:
      typedef float _dist_type;
      _dist_type dist;
      typedef float _dir_type;
      _dir_type dir;
      typedef float _apara_type;
      _apara_type apara;
      typedef float _r_type;
      _r_type r;
      typedef float _slope_type;
      _slope_type slope;
      typedef float _cant_type;
      _cant_type cant;
      typedef float _lw_type;
      _lw_type lw;
      typedef float _rw_type;
      _rw_type rw;

    DTLane():
      dist(0),
      dir(0),
      apara(0),
      r(0),
      slope(0),
      cant(0),
      lw(0),
      rw(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->dist);
      offset += serializeAvrFloat64(outbuffer + offset, this->dir);
      offset += serializeAvrFloat64(outbuffer + offset, this->apara);
      offset += serializeAvrFloat64(outbuffer + offset, this->r);
      offset += serializeAvrFloat64(outbuffer + offset, this->slope);
      offset += serializeAvrFloat64(outbuffer + offset, this->cant);
      offset += serializeAvrFloat64(outbuffer + offset, this->lw);
      offset += serializeAvrFloat64(outbuffer + offset, this->rw);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->dist));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->dir));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->apara));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->r));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->slope));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->cant));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->lw));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rw));
     return offset;
    }

    const char * getType(){ return "autoware_msgs/DTLane"; };
    const char * getMD5(){ return "1e60021b42021278e47be71f881d31aa"; };

  };

}
#endif