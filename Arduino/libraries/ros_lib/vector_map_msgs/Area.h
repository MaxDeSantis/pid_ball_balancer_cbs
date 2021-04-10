#ifndef _ROS_vector_map_msgs_Area_h
#define _ROS_vector_map_msgs_Area_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_map_msgs
{

  class Area : public ros::Msg
  {
    public:
      typedef int32_t _aid_type;
      _aid_type aid;
      typedef int32_t _slid_type;
      _slid_type slid;
      typedef int32_t _elid_type;
      _elid_type elid;

    Area():
      aid(0),
      slid(0),
      elid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_aid;
      u_aid.real = this->aid;
      *(outbuffer + offset + 0) = (u_aid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_aid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_aid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_aid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->aid);
      union {
        int32_t real;
        uint32_t base;
      } u_slid;
      u_slid.real = this->slid;
      *(outbuffer + offset + 0) = (u_slid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_slid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_slid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_slid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->slid);
      union {
        int32_t real;
        uint32_t base;
      } u_elid;
      u_elid.real = this->elid;
      *(outbuffer + offset + 0) = (u_elid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_elid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_elid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_elid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->elid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_aid;
      u_aid.base = 0;
      u_aid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_aid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_aid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_aid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->aid = u_aid.real;
      offset += sizeof(this->aid);
      union {
        int32_t real;
        uint32_t base;
      } u_slid;
      u_slid.base = 0;
      u_slid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_slid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_slid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_slid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->slid = u_slid.real;
      offset += sizeof(this->slid);
      union {
        int32_t real;
        uint32_t base;
      } u_elid;
      u_elid.base = 0;
      u_elid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_elid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_elid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_elid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->elid = u_elid.real;
      offset += sizeof(this->elid);
     return offset;
    }

    const char * getType(){ return "vector_map_msgs/Area"; };
    const char * getMD5(){ return "54e3c8d0cac454f97de72b3d7d888691"; };

  };

}
#endif