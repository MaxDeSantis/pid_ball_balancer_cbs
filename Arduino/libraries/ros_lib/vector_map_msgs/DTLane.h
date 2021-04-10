#ifndef _ROS_vector_map_msgs_DTLane_h
#define _ROS_vector_map_msgs_DTLane_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_map_msgs
{

  class DTLane : public ros::Msg
  {
    public:
      typedef int32_t _did_type;
      _did_type did;
      typedef float _dist_type;
      _dist_type dist;
      typedef int32_t _pid_type;
      _pid_type pid;
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
      did(0),
      dist(0),
      pid(0),
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
      union {
        int32_t real;
        uint32_t base;
      } u_did;
      u_did.real = this->did;
      *(outbuffer + offset + 0) = (u_did.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_did.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_did.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_did.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->did);
      offset += serializeAvrFloat64(outbuffer + offset, this->dist);
      union {
        int32_t real;
        uint32_t base;
      } u_pid;
      u_pid.real = this->pid;
      *(outbuffer + offset + 0) = (u_pid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pid);
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
      union {
        int32_t real;
        uint32_t base;
      } u_did;
      u_did.base = 0;
      u_did.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_did.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_did.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_did.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->did = u_did.real;
      offset += sizeof(this->did);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->dist));
      union {
        int32_t real;
        uint32_t base;
      } u_pid;
      u_pid.base = 0;
      u_pid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pid = u_pid.real;
      offset += sizeof(this->pid);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->dir));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->apara));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->r));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->slope));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->cant));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->lw));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rw));
     return offset;
    }

    const char * getType(){ return "vector_map_msgs/DTLane"; };
    const char * getMD5(){ return "50d83078491bca58f98774489d1f1ac9"; };

  };

}
#endif