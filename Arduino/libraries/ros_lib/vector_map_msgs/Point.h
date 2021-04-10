#ifndef _ROS_vector_map_msgs_Point_h
#define _ROS_vector_map_msgs_Point_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_map_msgs
{

  class Point : public ros::Msg
  {
    public:
      typedef int32_t _pid_type;
      _pid_type pid;
      typedef float _b_type;
      _b_type b;
      typedef float _l_type;
      _l_type l;
      typedef float _h_type;
      _h_type h;
      typedef float _bx_type;
      _bx_type bx;
      typedef float _ly_type;
      _ly_type ly;
      typedef int32_t _ref_type;
      _ref_type ref;
      typedef int32_t _mcode1_type;
      _mcode1_type mcode1;
      typedef int32_t _mcode2_type;
      _mcode2_type mcode2;
      typedef int32_t _mcode3_type;
      _mcode3_type mcode3;

    Point():
      pid(0),
      b(0),
      l(0),
      h(0),
      bx(0),
      ly(0),
      ref(0),
      mcode1(0),
      mcode2(0),
      mcode3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      offset += serializeAvrFloat64(outbuffer + offset, this->b);
      offset += serializeAvrFloat64(outbuffer + offset, this->l);
      offset += serializeAvrFloat64(outbuffer + offset, this->h);
      offset += serializeAvrFloat64(outbuffer + offset, this->bx);
      offset += serializeAvrFloat64(outbuffer + offset, this->ly);
      union {
        int32_t real;
        uint32_t base;
      } u_ref;
      u_ref.real = this->ref;
      *(outbuffer + offset + 0) = (u_ref.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ref.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ref.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ref.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ref);
      union {
        int32_t real;
        uint32_t base;
      } u_mcode1;
      u_mcode1.real = this->mcode1;
      *(outbuffer + offset + 0) = (u_mcode1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mcode1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mcode1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mcode1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mcode1);
      union {
        int32_t real;
        uint32_t base;
      } u_mcode2;
      u_mcode2.real = this->mcode2;
      *(outbuffer + offset + 0) = (u_mcode2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mcode2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mcode2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mcode2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mcode2);
      union {
        int32_t real;
        uint32_t base;
      } u_mcode3;
      u_mcode3.real = this->mcode3;
      *(outbuffer + offset + 0) = (u_mcode3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mcode3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mcode3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mcode3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mcode3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->b));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->l));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->h));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bx));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ly));
      union {
        int32_t real;
        uint32_t base;
      } u_ref;
      u_ref.base = 0;
      u_ref.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ref.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ref.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ref.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ref = u_ref.real;
      offset += sizeof(this->ref);
      union {
        int32_t real;
        uint32_t base;
      } u_mcode1;
      u_mcode1.base = 0;
      u_mcode1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mcode1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mcode1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mcode1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mcode1 = u_mcode1.real;
      offset += sizeof(this->mcode1);
      union {
        int32_t real;
        uint32_t base;
      } u_mcode2;
      u_mcode2.base = 0;
      u_mcode2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mcode2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mcode2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mcode2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mcode2 = u_mcode2.real;
      offset += sizeof(this->mcode2);
      union {
        int32_t real;
        uint32_t base;
      } u_mcode3;
      u_mcode3.base = 0;
      u_mcode3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mcode3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mcode3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mcode3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mcode3 = u_mcode3.real;
      offset += sizeof(this->mcode3);
     return offset;
    }

    const char * getType(){ return "vector_map_msgs/Point"; };
    const char * getMD5(){ return "4d106503a62bbb6b76e4aefe8ac868a9"; };

  };

}
#endif