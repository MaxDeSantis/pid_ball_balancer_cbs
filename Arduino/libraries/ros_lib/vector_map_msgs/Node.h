#ifndef _ROS_vector_map_msgs_Node_h
#define _ROS_vector_map_msgs_Node_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_map_msgs
{

  class Node : public ros::Msg
  {
    public:
      typedef int32_t _nid_type;
      _nid_type nid;
      typedef int32_t _pid_type;
      _pid_type pid;

    Node():
      nid(0),
      pid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_nid;
      u_nid.real = this->nid;
      *(outbuffer + offset + 0) = (u_nid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nid);
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_nid;
      u_nid.base = 0;
      u_nid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nid = u_nid.real;
      offset += sizeof(this->nid);
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
     return offset;
    }

    const char * getType(){ return "vector_map_msgs/Node"; };
    const char * getMD5(){ return "94c8d91d18880679a8ed9b4a81985380"; };

  };

}
#endif