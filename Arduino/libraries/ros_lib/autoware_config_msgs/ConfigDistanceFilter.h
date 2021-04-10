#ifndef _ROS_autoware_config_msgs_ConfigDistanceFilter_h
#define _ROS_autoware_config_msgs_ConfigDistanceFilter_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_config_msgs
{

  class ConfigDistanceFilter : public ros::Msg
  {
    public:
      typedef int32_t _sample_num_type;
      _sample_num_type sample_num;
      typedef float _measurement_range_type;
      _measurement_range_type measurement_range;

    ConfigDistanceFilter():
      sample_num(0),
      measurement_range(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_sample_num;
      u_sample_num.real = this->sample_num;
      *(outbuffer + offset + 0) = (u_sample_num.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sample_num.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sample_num.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sample_num.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sample_num);
      union {
        float real;
        uint32_t base;
      } u_measurement_range;
      u_measurement_range.real = this->measurement_range;
      *(outbuffer + offset + 0) = (u_measurement_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_measurement_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_measurement_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_measurement_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->measurement_range);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_sample_num;
      u_sample_num.base = 0;
      u_sample_num.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sample_num.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sample_num.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sample_num.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sample_num = u_sample_num.real;
      offset += sizeof(this->sample_num);
      union {
        float real;
        uint32_t base;
      } u_measurement_range;
      u_measurement_range.base = 0;
      u_measurement_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_measurement_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_measurement_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_measurement_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->measurement_range = u_measurement_range.real;
      offset += sizeof(this->measurement_range);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigDistanceFilter"; };
    const char * getMD5(){ return "3c62131ed7d7074af43c78ec79a1aa05"; };

  };

}
#endif