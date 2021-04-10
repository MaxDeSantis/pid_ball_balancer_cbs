#ifndef _ROS_vector_map_msgs_Line_h
#define _ROS_vector_map_msgs_Line_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_map_msgs
{

  class Line : public ros::Msg
  {
    public:
      typedef int32_t _lid_type;
      _lid_type lid;
      typedef int32_t _bpid_type;
      _bpid_type bpid;
      typedef int32_t _fpid_type;
      _fpid_type fpid;
      typedef int32_t _blid_type;
      _blid_type blid;
      typedef int32_t _flid_type;
      _flid_type flid;

    Line():
      lid(0),
      bpid(0),
      fpid(0),
      blid(0),
      flid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_lid;
      u_lid.real = this->lid;
      *(outbuffer + offset + 0) = (u_lid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lid);
      union {
        int32_t real;
        uint32_t base;
      } u_bpid;
      u_bpid.real = this->bpid;
      *(outbuffer + offset + 0) = (u_bpid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bpid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bpid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bpid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bpid);
      union {
        int32_t real;
        uint32_t base;
      } u_fpid;
      u_fpid.real = this->fpid;
      *(outbuffer + offset + 0) = (u_fpid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fpid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fpid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fpid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fpid);
      union {
        int32_t real;
        uint32_t base;
      } u_blid;
      u_blid.real = this->blid;
      *(outbuffer + offset + 0) = (u_blid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_blid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_blid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_blid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->blid);
      union {
        int32_t real;
        uint32_t base;
      } u_flid;
      u_flid.real = this->flid;
      *(outbuffer + offset + 0) = (u_flid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_flid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_flid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_flid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_lid;
      u_lid.base = 0;
      u_lid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lid = u_lid.real;
      offset += sizeof(this->lid);
      union {
        int32_t real;
        uint32_t base;
      } u_bpid;
      u_bpid.base = 0;
      u_bpid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bpid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bpid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bpid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bpid = u_bpid.real;
      offset += sizeof(this->bpid);
      union {
        int32_t real;
        uint32_t base;
      } u_fpid;
      u_fpid.base = 0;
      u_fpid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fpid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fpid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fpid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fpid = u_fpid.real;
      offset += sizeof(this->fpid);
      union {
        int32_t real;
        uint32_t base;
      } u_blid;
      u_blid.base = 0;
      u_blid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_blid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_blid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_blid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->blid = u_blid.real;
      offset += sizeof(this->blid);
      union {
        int32_t real;
        uint32_t base;
      } u_flid;
      u_flid.base = 0;
      u_flid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_flid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_flid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_flid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->flid = u_flid.real;
      offset += sizeof(this->flid);
     return offset;
    }

    const char * getType(){ return "vector_map_msgs/Line"; };
    const char * getMD5(){ return "6f019727ac91c69fd42d5922bf464911"; };

  };

}
#endif