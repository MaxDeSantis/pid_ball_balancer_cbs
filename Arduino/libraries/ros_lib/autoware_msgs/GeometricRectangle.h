#ifndef _ROS_autoware_msgs_GeometricRectangle_h
#define _ROS_autoware_msgs_GeometricRectangle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_msgs
{

  class GeometricRectangle : public ros::Msg
  {
    public:
      typedef float _wl_type;
      _wl_type wl;
      typedef float _wr_type;
      _wr_type wr;
      typedef float _lf_type;
      _lf_type lf;
      typedef float _lb_type;
      _lb_type lb;

    GeometricRectangle():
      wl(0),
      wr(0),
      lf(0),
      lb(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_wl;
      u_wl.real = this->wl;
      *(outbuffer + offset + 0) = (u_wl.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wl.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wl.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wl.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wl);
      union {
        float real;
        uint32_t base;
      } u_wr;
      u_wr.real = this->wr;
      *(outbuffer + offset + 0) = (u_wr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wr);
      union {
        float real;
        uint32_t base;
      } u_lf;
      u_lf.real = this->lf;
      *(outbuffer + offset + 0) = (u_lf.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lf.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lf.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lf.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lf);
      union {
        float real;
        uint32_t base;
      } u_lb;
      u_lb.real = this->lb;
      *(outbuffer + offset + 0) = (u_lb.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lb.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lb.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lb.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lb);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_wl;
      u_wl.base = 0;
      u_wl.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_wl.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_wl.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_wl.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->wl = u_wl.real;
      offset += sizeof(this->wl);
      union {
        float real;
        uint32_t base;
      } u_wr;
      u_wr.base = 0;
      u_wr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_wr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_wr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_wr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->wr = u_wr.real;
      offset += sizeof(this->wr);
      union {
        float real;
        uint32_t base;
      } u_lf;
      u_lf.base = 0;
      u_lf.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lf.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lf.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lf.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lf = u_lf.real;
      offset += sizeof(this->lf);
      union {
        float real;
        uint32_t base;
      } u_lb;
      u_lb.base = 0;
      u_lb.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lb.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lb.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lb.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lb = u_lb.real;
      offset += sizeof(this->lb);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/GeometricRectangle"; };
    const char * getMD5(){ return "b41f6cf3f78cac5a789ad3f178ef94dc"; };

  };

}
#endif