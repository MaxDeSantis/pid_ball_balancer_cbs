#ifndef _ROS_autoware_msgs_ImageRectRanged_h
#define _ROS_autoware_msgs_ImageRectRanged_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autoware_msgs/ImageRect.h"

namespace autoware_msgs
{

  class ImageRectRanged : public ros::Msg
  {
    public:
      typedef autoware_msgs::ImageRect _rect_type;
      _rect_type rect;
      typedef float _range_type;
      _range_type range;
      typedef float _min_height_type;
      _min_height_type min_height;
      typedef float _max_height_type;
      _max_height_type max_height;

    ImageRectRanged():
      rect(),
      range(0),
      min_height(0),
      max_height(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->rect.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_range;
      u_range.real = this->range;
      *(outbuffer + offset + 0) = (u_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->range);
      union {
        float real;
        uint32_t base;
      } u_min_height;
      u_min_height.real = this->min_height;
      *(outbuffer + offset + 0) = (u_min_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_height);
      union {
        float real;
        uint32_t base;
      } u_max_height;
      u_max_height.real = this->max_height;
      *(outbuffer + offset + 0) = (u_max_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_height);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->rect.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_range;
      u_range.base = 0;
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->range = u_range.real;
      offset += sizeof(this->range);
      union {
        float real;
        uint32_t base;
      } u_min_height;
      u_min_height.base = 0;
      u_min_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_height = u_min_height.real;
      offset += sizeof(this->min_height);
      union {
        float real;
        uint32_t base;
      } u_max_height;
      u_max_height.base = 0;
      u_max_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_height = u_max_height.real;
      offset += sizeof(this->max_height);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/ImageRectRanged"; };
    const char * getMD5(){ return "3781b4778925185f71f990932766044c"; };

  };

}
#endif