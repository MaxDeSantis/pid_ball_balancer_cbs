#ifndef _ROS_autoware_msgs_ExtractedPosition_h
#define _ROS_autoware_msgs_ExtractedPosition_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_msgs
{

  class ExtractedPosition : public ros::Msg
  {
    public:
      typedef int32_t _signalId_type;
      _signalId_type signalId;
      typedef int32_t _u_type;
      _u_type u;
      typedef int32_t _v_type;
      _v_type v;
      typedef int32_t _radius_type;
      _radius_type radius;
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _z_type;
      _z_type z;
      typedef float _hang_type;
      _hang_type hang;
      typedef int8_t _type_type;
      _type_type type;
      typedef int32_t _linkId_type;
      _linkId_type linkId;
      typedef int32_t _plId_type;
      _plId_type plId;

    ExtractedPosition():
      signalId(0),
      u(0),
      v(0),
      radius(0),
      x(0),
      y(0),
      z(0),
      hang(0),
      type(0),
      linkId(0),
      plId(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_signalId;
      u_signalId.real = this->signalId;
      *(outbuffer + offset + 0) = (u_signalId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_signalId.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_signalId.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_signalId.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->signalId);
      union {
        int32_t real;
        uint32_t base;
      } u_u;
      u_u.real = this->u;
      *(outbuffer + offset + 0) = (u_u.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_u.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_u.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_u.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->u);
      union {
        int32_t real;
        uint32_t base;
      } u_v;
      u_v.real = this->v;
      *(outbuffer + offset + 0) = (u_v.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v);
      union {
        int32_t real;
        uint32_t base;
      } u_radius;
      u_radius.real = this->radius;
      *(outbuffer + offset + 0) = (u_radius.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_radius.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_radius.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_radius.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->radius);
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->z);
      offset += serializeAvrFloat64(outbuffer + offset, this->hang);
      union {
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_linkId;
      u_linkId.real = this->linkId;
      *(outbuffer + offset + 0) = (u_linkId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_linkId.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_linkId.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_linkId.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->linkId);
      union {
        int32_t real;
        uint32_t base;
      } u_plId;
      u_plId.real = this->plId;
      *(outbuffer + offset + 0) = (u_plId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_plId.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_plId.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_plId.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->plId);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_signalId;
      u_signalId.base = 0;
      u_signalId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_signalId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_signalId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_signalId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->signalId = u_signalId.real;
      offset += sizeof(this->signalId);
      union {
        int32_t real;
        uint32_t base;
      } u_u;
      u_u.base = 0;
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->u = u_u.real;
      offset += sizeof(this->u);
      union {
        int32_t real;
        uint32_t base;
      } u_v;
      u_v.base = 0;
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v = u_v.real;
      offset += sizeof(this->v);
      union {
        int32_t real;
        uint32_t base;
      } u_radius;
      u_radius.base = 0;
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->radius = u_radius.real;
      offset += sizeof(this->radius);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->hang));
      union {
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->type = u_type.real;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_linkId;
      u_linkId.base = 0;
      u_linkId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_linkId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_linkId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_linkId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->linkId = u_linkId.real;
      offset += sizeof(this->linkId);
      union {
        int32_t real;
        uint32_t base;
      } u_plId;
      u_plId.base = 0;
      u_plId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_plId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_plId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_plId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->plId = u_plId.real;
      offset += sizeof(this->plId);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/ExtractedPosition"; };
    const char * getMD5(){ return "0e48067eb51a80d53e09341230ac756f"; };

  };

}
#endif