#ifndef _ROS_vector_map_msgs_StopLine_h
#define _ROS_vector_map_msgs_StopLine_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_map_msgs
{

  class StopLine : public ros::Msg
  {
    public:
      typedef int32_t _id_type;
      _id_type id;
      typedef int32_t _lid_type;
      _lid_type lid;
      typedef int32_t _tlid_type;
      _tlid_type tlid;
      typedef int32_t _signid_type;
      _signid_type signid;
      typedef int32_t _linkid_type;
      _linkid_type linkid;

    StopLine():
      id(0),
      lid(0),
      tlid(0),
      signid(0),
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
      union {
        int32_t real;
        uint32_t base;
      } u_tlid;
      u_tlid.real = this->tlid;
      *(outbuffer + offset + 0) = (u_tlid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tlid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tlid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tlid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tlid);
      union {
        int32_t real;
        uint32_t base;
      } u_signid;
      u_signid.real = this->signid;
      *(outbuffer + offset + 0) = (u_signid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_signid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_signid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_signid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->signid);
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
      union {
        int32_t real;
        uint32_t base;
      } u_tlid;
      u_tlid.base = 0;
      u_tlid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tlid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tlid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tlid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tlid = u_tlid.real;
      offset += sizeof(this->tlid);
      union {
        int32_t real;
        uint32_t base;
      } u_signid;
      u_signid.base = 0;
      u_signid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_signid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_signid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_signid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->signid = u_signid.real;
      offset += sizeof(this->signid);
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

    const char * getType(){ return "vector_map_msgs/StopLine"; };
    const char * getMD5(){ return "aa335822262e59a11032c9939a75e473"; };

  };

}
#endif