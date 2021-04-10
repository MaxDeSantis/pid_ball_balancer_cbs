#ifndef _ROS_vector_map_msgs_DriveOnPortion_h
#define _ROS_vector_map_msgs_DriveOnPortion_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_map_msgs
{

  class DriveOnPortion : public ros::Msg
  {
    public:
      typedef int32_t _id_type;
      _id_type id;
      typedef int32_t _aid_type;
      _aid_type aid;
      typedef int32_t _linkid_type;
      _linkid_type linkid;

    DriveOnPortion():
      id(0),
      aid(0),
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

    const char * getType(){ return "vector_map_msgs/DriveOnPortion"; };
    const char * getMD5(){ return "3ef3d04c25adcf0d8438f724188daa69"; };

  };

}
#endif