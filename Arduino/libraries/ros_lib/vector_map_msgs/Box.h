#ifndef _ROS_vector_map_msgs_Box_h
#define _ROS_vector_map_msgs_Box_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_map_msgs
{

  class Box : public ros::Msg
  {
    public:
      typedef int32_t _bid_type;
      _bid_type bid;
      typedef int32_t _pid1_type;
      _pid1_type pid1;
      typedef int32_t _pid2_type;
      _pid2_type pid2;
      typedef int32_t _pid3_type;
      _pid3_type pid3;
      typedef int32_t _pid4_type;
      _pid4_type pid4;
      typedef float _height_type;
      _height_type height;

    Box():
      bid(0),
      pid1(0),
      pid2(0),
      pid3(0),
      pid4(0),
      height(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_bid;
      u_bid.real = this->bid;
      *(outbuffer + offset + 0) = (u_bid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bid);
      union {
        int32_t real;
        uint32_t base;
      } u_pid1;
      u_pid1.real = this->pid1;
      *(outbuffer + offset + 0) = (u_pid1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pid1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pid1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pid1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pid1);
      union {
        int32_t real;
        uint32_t base;
      } u_pid2;
      u_pid2.real = this->pid2;
      *(outbuffer + offset + 0) = (u_pid2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pid2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pid2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pid2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pid2);
      union {
        int32_t real;
        uint32_t base;
      } u_pid3;
      u_pid3.real = this->pid3;
      *(outbuffer + offset + 0) = (u_pid3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pid3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pid3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pid3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pid3);
      union {
        int32_t real;
        uint32_t base;
      } u_pid4;
      u_pid4.real = this->pid4;
      *(outbuffer + offset + 0) = (u_pid4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pid4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pid4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pid4.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pid4);
      offset += serializeAvrFloat64(outbuffer + offset, this->height);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_bid;
      u_bid.base = 0;
      u_bid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bid = u_bid.real;
      offset += sizeof(this->bid);
      union {
        int32_t real;
        uint32_t base;
      } u_pid1;
      u_pid1.base = 0;
      u_pid1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pid1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pid1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pid1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pid1 = u_pid1.real;
      offset += sizeof(this->pid1);
      union {
        int32_t real;
        uint32_t base;
      } u_pid2;
      u_pid2.base = 0;
      u_pid2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pid2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pid2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pid2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pid2 = u_pid2.real;
      offset += sizeof(this->pid2);
      union {
        int32_t real;
        uint32_t base;
      } u_pid3;
      u_pid3.base = 0;
      u_pid3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pid3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pid3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pid3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pid3 = u_pid3.real;
      offset += sizeof(this->pid3);
      union {
        int32_t real;
        uint32_t base;
      } u_pid4;
      u_pid4.base = 0;
      u_pid4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pid4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pid4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pid4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pid4 = u_pid4.real;
      offset += sizeof(this->pid4);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->height));
     return offset;
    }

    const char * getType(){ return "vector_map_msgs/Box"; };
    const char * getMD5(){ return "279dc10360643592a62c756918e5d27e"; };

  };

}
#endif