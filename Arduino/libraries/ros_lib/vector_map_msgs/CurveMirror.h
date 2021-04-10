#ifndef _ROS_vector_map_msgs_CurveMirror_h
#define _ROS_vector_map_msgs_CurveMirror_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_map_msgs
{

  class CurveMirror : public ros::Msg
  {
    public:
      typedef int32_t _id_type;
      _id_type id;
      typedef int32_t _vid_type;
      _vid_type vid;
      typedef int32_t _plid_type;
      _plid_type plid;
      typedef int32_t _type_type;
      _type_type type;
      typedef int32_t _linkid_type;
      _linkid_type linkid;

    CurveMirror():
      id(0),
      vid(0),
      plid(0),
      type(0),
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
      } u_vid;
      u_vid.real = this->vid;
      *(outbuffer + offset + 0) = (u_vid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vid);
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
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
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
      } u_vid;
      u_vid.base = 0;
      u_vid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vid = u_vid.real;
      offset += sizeof(this->vid);
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
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->type = u_type.real;
      offset += sizeof(this->type);
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

    const char * getType(){ return "vector_map_msgs/CurveMirror"; };
    const char * getMD5(){ return "b77ca92f4f478f9746572f6ef94ad9e4"; };

  };

}
#endif