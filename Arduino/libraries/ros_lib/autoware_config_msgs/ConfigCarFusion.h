#ifndef _ROS_autoware_config_msgs_ConfigCarFusion_h
#define _ROS_autoware_config_msgs_ConfigCarFusion_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigCarFusion : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _min_low_height_type;
      _min_low_height_type min_low_height;
      typedef float _max_low_height_type;
      _max_low_height_type max_low_height;
      typedef float _max_height_type;
      _max_height_type max_height;
      typedef int32_t _min_points_type;
      _min_points_type min_points;
      typedef float _dispersion_type;
      _dispersion_type dispersion;

    ConfigCarFusion():
      header(),
      min_low_height(0),
      max_low_height(0),
      max_height(0),
      min_points(0),
      dispersion(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_min_low_height;
      u_min_low_height.real = this->min_low_height;
      *(outbuffer + offset + 0) = (u_min_low_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_low_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_low_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_low_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_low_height);
      union {
        float real;
        uint32_t base;
      } u_max_low_height;
      u_max_low_height.real = this->max_low_height;
      *(outbuffer + offset + 0) = (u_max_low_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_low_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_low_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_low_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_low_height);
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
      union {
        int32_t real;
        uint32_t base;
      } u_min_points;
      u_min_points.real = this->min_points;
      *(outbuffer + offset + 0) = (u_min_points.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_points.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_points.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_points.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_points);
      union {
        float real;
        uint32_t base;
      } u_dispersion;
      u_dispersion.real = this->dispersion;
      *(outbuffer + offset + 0) = (u_dispersion.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dispersion.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dispersion.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dispersion.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dispersion);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_min_low_height;
      u_min_low_height.base = 0;
      u_min_low_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_low_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_low_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_low_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_low_height = u_min_low_height.real;
      offset += sizeof(this->min_low_height);
      union {
        float real;
        uint32_t base;
      } u_max_low_height;
      u_max_low_height.base = 0;
      u_max_low_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_low_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_low_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_low_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_low_height = u_max_low_height.real;
      offset += sizeof(this->max_low_height);
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
      union {
        int32_t real;
        uint32_t base;
      } u_min_points;
      u_min_points.base = 0;
      u_min_points.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_points.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_points.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_points.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_points = u_min_points.real;
      offset += sizeof(this->min_points);
      union {
        float real;
        uint32_t base;
      } u_dispersion;
      u_dispersion.base = 0;
      u_dispersion.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dispersion.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dispersion.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dispersion.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dispersion = u_dispersion.real;
      offset += sizeof(this->dispersion);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigCarFusion"; };
    const char * getMD5(){ return "959429b5ed2bcbb4ff76d523d3a8cebd"; };

  };

}
#endif