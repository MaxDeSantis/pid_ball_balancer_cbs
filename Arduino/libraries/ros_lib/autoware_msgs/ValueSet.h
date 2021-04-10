#ifndef _ROS_autoware_msgs_ValueSet_h
#define _ROS_autoware_msgs_ValueSet_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_msgs
{

  class ValueSet : public ros::Msg
  {
    public:
      typedef int32_t _center_type;
      _center_type center;
      typedef int32_t _range_type;
      _range_type range;

    ValueSet():
      center(0),
      range(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_center;
      u_center.real = this->center;
      *(outbuffer + offset + 0) = (u_center.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_center.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_center.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_center.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->center);
      union {
        int32_t real;
        uint32_t base;
      } u_range;
      u_range.real = this->range;
      *(outbuffer + offset + 0) = (u_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->range);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_center;
      u_center.base = 0;
      u_center.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_center.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_center.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_center.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->center = u_center.real;
      offset += sizeof(this->center);
      union {
        int32_t real;
        uint32_t base;
      } u_range;
      u_range.base = 0;
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->range = u_range.real;
      offset += sizeof(this->range);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/ValueSet"; };
    const char * getMD5(){ return "281ab05df668dd70c6f78f89e9a412a0"; };

  };

}
#endif