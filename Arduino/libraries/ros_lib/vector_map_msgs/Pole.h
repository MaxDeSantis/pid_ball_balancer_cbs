#ifndef _ROS_vector_map_msgs_Pole_h
#define _ROS_vector_map_msgs_Pole_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_map_msgs
{

  class Pole : public ros::Msg
  {
    public:
      typedef int32_t _plid_type;
      _plid_type plid;
      typedef int32_t _vid_type;
      _vid_type vid;
      typedef float _length_type;
      _length_type length;
      typedef float _dim_type;
      _dim_type dim;

    Pole():
      plid(0),
      vid(0),
      length(0),
      dim(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_plid;
      u_plid.real = this->plid;
      *(outbuffer + offset + 0) = (u_plid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_plid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_plid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_plid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->plid);
      union {
        int32_t real;
        uint32_t base;
      } u_vid;
      u_vid.real = this->vid;
      *(outbuffer + offset + 0) = (u_vid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vid);
      offset += serializeAvrFloat64(outbuffer + offset, this->length);
      offset += serializeAvrFloat64(outbuffer + offset, this->dim);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_plid;
      u_plid.base = 0;
      u_plid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_plid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_plid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_plid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->plid = u_plid.real;
      offset += sizeof(this->plid);
      union {
        int32_t real;
        uint32_t base;
      } u_vid;
      u_vid.base = 0;
      u_vid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vid = u_vid.real;
      offset += sizeof(this->vid);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->length));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->dim));
     return offset;
    }

    const char * getType(){ return "vector_map_msgs/Pole"; };
    const char * getMD5(){ return "d9d65404b5e1f838856c9aeaa9d94be8"; };

  };

}
#endif