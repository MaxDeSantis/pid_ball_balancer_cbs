#ifndef _ROS_vector_map_msgs_Curb_h
#define _ROS_vector_map_msgs_Curb_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_map_msgs
{

  class Curb : public ros::Msg
  {
    public:
      typedef int32_t _id_type;
      _id_type id;
      typedef int32_t _lid_type;
      _lid_type lid;
      typedef float _height_type;
      _height_type height;
      typedef float _width_type;
      _width_type width;
      typedef int32_t _dir_type;
      _dir_type dir;
      typedef int32_t _linkid_type;
      _linkid_type linkid;
      enum { RIGHT = 0 };
      enum { LEFT = 1 };

    Curb():
      id(0),
      lid(0),
      height(0),
      width(0),
      dir(0),
      linkid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
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
      offset += serializeAvrFloat64(outbuffer + offset, this->height);
      offset += serializeAvrFloat64(outbuffer + offset, this->width);
      union {
        int32_t real;
        uint32_t base;
      } u_dir;
      u_dir.real = this->dir;
      *(outbuffer + offset + 0) = (u_dir.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dir.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dir.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dir.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dir);
      union {
        int32_t real;
        uint32_t base;
      } u_linkid;
      u_linkid.real = this->linkid;
      *(outbuffer + offset + 0) = (u_linkid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_linkid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_linkid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_linkid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->linkid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->height));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->width));
      union {
        int32_t real;
        uint32_t base;
      } u_dir;
      u_dir.base = 0;
      u_dir.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dir.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dir.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dir.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dir = u_dir.real;
      offset += sizeof(this->dir);
      union {
        int32_t real;
        uint32_t base;
      } u_linkid;
      u_linkid.base = 0;
      u_linkid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_linkid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_linkid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_linkid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->linkid = u_linkid.real;
      offset += sizeof(this->linkid);
     return offset;
    }

    const char * getType(){ return "vector_map_msgs/Curb"; };
    const char * getMD5(){ return "7d06e56ec0e640d50ee97b6e7c75f16f"; };

  };

}
#endif