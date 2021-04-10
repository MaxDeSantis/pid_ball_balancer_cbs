#ifndef _ROS_autoware_config_msgs_ConfigCompareMapFilter_h
#define _ROS_autoware_config_msgs_ConfigCompareMapFilter_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_config_msgs
{

  class ConfigCompareMapFilter : public ros::Msg
  {
    public:
      typedef float _distance_threshold_type;
      _distance_threshold_type distance_threshold;
      typedef float _min_clipping_height_type;
      _min_clipping_height_type min_clipping_height;
      typedef float _max_clipping_height_type;
      _max_clipping_height_type max_clipping_height;

    ConfigCompareMapFilter():
      distance_threshold(0),
      min_clipping_height(0),
      max_clipping_height(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_distance_threshold;
      u_distance_threshold.real = this->distance_threshold;
      *(outbuffer + offset + 0) = (u_distance_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance_threshold.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance_threshold);
      union {
        float real;
        uint32_t base;
      } u_min_clipping_height;
      u_min_clipping_height.real = this->min_clipping_height;
      *(outbuffer + offset + 0) = (u_min_clipping_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_clipping_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_clipping_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_clipping_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_clipping_height);
      union {
        float real;
        uint32_t base;
      } u_max_clipping_height;
      u_max_clipping_height.real = this->max_clipping_height;
      *(outbuffer + offset + 0) = (u_max_clipping_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_clipping_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_clipping_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_clipping_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_clipping_height);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_distance_threshold;
      u_distance_threshold.base = 0;
      u_distance_threshold.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance_threshold.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance_threshold.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance_threshold.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance_threshold = u_distance_threshold.real;
      offset += sizeof(this->distance_threshold);
      union {
        float real;
        uint32_t base;
      } u_min_clipping_height;
      u_min_clipping_height.base = 0;
      u_min_clipping_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_clipping_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_clipping_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_clipping_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_clipping_height = u_min_clipping_height.real;
      offset += sizeof(this->min_clipping_height);
      union {
        float real;
        uint32_t base;
      } u_max_clipping_height;
      u_max_clipping_height.base = 0;
      u_max_clipping_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_clipping_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_clipping_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_clipping_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_clipping_height = u_max_clipping_height.real;
      offset += sizeof(this->max_clipping_height);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigCompareMapFilter"; };
    const char * getMD5(){ return "09db74a6997527a611ebec850731c83b"; };

  };

}
#endif