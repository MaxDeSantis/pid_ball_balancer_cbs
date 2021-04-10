#ifndef _ROS_autoware_config_msgs_ConfigRayGroundFilter_h
#define _ROS_autoware_config_msgs_ConfigRayGroundFilter_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigRayGroundFilter : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _sensor_height_type;
      _sensor_height_type sensor_height;
      typedef float _clipping_height_type;
      _clipping_height_type clipping_height;
      typedef float _min_point_distance_type;
      _min_point_distance_type min_point_distance;
      typedef float _radial_divider_angle_type;
      _radial_divider_angle_type radial_divider_angle;
      typedef float _concentric_divider_distance_type;
      _concentric_divider_distance_type concentric_divider_distance;
      typedef float _local_max_slope_type;
      _local_max_slope_type local_max_slope;
      typedef float _general_max_slope_type;
      _general_max_slope_type general_max_slope;
      typedef float _min_height_threshold_type;
      _min_height_threshold_type min_height_threshold;
      typedef float _reclass_distance_threshold_type;
      _reclass_distance_threshold_type reclass_distance_threshold;

    ConfigRayGroundFilter():
      header(),
      sensor_height(0),
      clipping_height(0),
      min_point_distance(0),
      radial_divider_angle(0),
      concentric_divider_distance(0),
      local_max_slope(0),
      general_max_slope(0),
      min_height_threshold(0),
      reclass_distance_threshold(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->sensor_height);
      offset += serializeAvrFloat64(outbuffer + offset, this->clipping_height);
      offset += serializeAvrFloat64(outbuffer + offset, this->min_point_distance);
      offset += serializeAvrFloat64(outbuffer + offset, this->radial_divider_angle);
      offset += serializeAvrFloat64(outbuffer + offset, this->concentric_divider_distance);
      offset += serializeAvrFloat64(outbuffer + offset, this->local_max_slope);
      offset += serializeAvrFloat64(outbuffer + offset, this->general_max_slope);
      offset += serializeAvrFloat64(outbuffer + offset, this->min_height_threshold);
      offset += serializeAvrFloat64(outbuffer + offset, this->reclass_distance_threshold);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->sensor_height));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->clipping_height));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_point_distance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->radial_divider_angle));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->concentric_divider_distance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->local_max_slope));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->general_max_slope));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_height_threshold));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->reclass_distance_threshold));
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigRayGroundFilter"; };
    const char * getMD5(){ return "1b9a20593709b07932fff996671d4ed6"; };

  };

}
#endif