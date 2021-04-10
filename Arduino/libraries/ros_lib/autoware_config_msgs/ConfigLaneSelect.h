#ifndef _ROS_autoware_config_msgs_ConfigLaneSelect_h
#define _ROS_autoware_config_msgs_ConfigLaneSelect_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigLaneSelect : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _distance_threshold_neighbor_lanes_type;
      _distance_threshold_neighbor_lanes_type distance_threshold_neighbor_lanes;
      typedef float _lane_change_interval_type;
      _lane_change_interval_type lane_change_interval;
      typedef float _lane_change_target_ratio_type;
      _lane_change_target_ratio_type lane_change_target_ratio;
      typedef float _lane_change_target_minimum_type;
      _lane_change_target_minimum_type lane_change_target_minimum;
      typedef float _vector_length_hermite_curve_type;
      _vector_length_hermite_curve_type vector_length_hermite_curve;

    ConfigLaneSelect():
      header(),
      distance_threshold_neighbor_lanes(0),
      lane_change_interval(0),
      lane_change_target_ratio(0),
      lane_change_target_minimum(0),
      vector_length_hermite_curve(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_distance_threshold_neighbor_lanes;
      u_distance_threshold_neighbor_lanes.real = this->distance_threshold_neighbor_lanes;
      *(outbuffer + offset + 0) = (u_distance_threshold_neighbor_lanes.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance_threshold_neighbor_lanes.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance_threshold_neighbor_lanes.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance_threshold_neighbor_lanes.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance_threshold_neighbor_lanes);
      union {
        float real;
        uint32_t base;
      } u_lane_change_interval;
      u_lane_change_interval.real = this->lane_change_interval;
      *(outbuffer + offset + 0) = (u_lane_change_interval.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_change_interval.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_change_interval.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_change_interval.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_change_interval);
      union {
        float real;
        uint32_t base;
      } u_lane_change_target_ratio;
      u_lane_change_target_ratio.real = this->lane_change_target_ratio;
      *(outbuffer + offset + 0) = (u_lane_change_target_ratio.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_change_target_ratio.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_change_target_ratio.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_change_target_ratio.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_change_target_ratio);
      union {
        float real;
        uint32_t base;
      } u_lane_change_target_minimum;
      u_lane_change_target_minimum.real = this->lane_change_target_minimum;
      *(outbuffer + offset + 0) = (u_lane_change_target_minimum.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_change_target_minimum.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_change_target_minimum.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_change_target_minimum.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_change_target_minimum);
      union {
        float real;
        uint32_t base;
      } u_vector_length_hermite_curve;
      u_vector_length_hermite_curve.real = this->vector_length_hermite_curve;
      *(outbuffer + offset + 0) = (u_vector_length_hermite_curve.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vector_length_hermite_curve.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vector_length_hermite_curve.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vector_length_hermite_curve.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vector_length_hermite_curve);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_distance_threshold_neighbor_lanes;
      u_distance_threshold_neighbor_lanes.base = 0;
      u_distance_threshold_neighbor_lanes.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance_threshold_neighbor_lanes.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance_threshold_neighbor_lanes.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance_threshold_neighbor_lanes.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance_threshold_neighbor_lanes = u_distance_threshold_neighbor_lanes.real;
      offset += sizeof(this->distance_threshold_neighbor_lanes);
      union {
        float real;
        uint32_t base;
      } u_lane_change_interval;
      u_lane_change_interval.base = 0;
      u_lane_change_interval.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_change_interval.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lane_change_interval.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lane_change_interval.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lane_change_interval = u_lane_change_interval.real;
      offset += sizeof(this->lane_change_interval);
      union {
        float real;
        uint32_t base;
      } u_lane_change_target_ratio;
      u_lane_change_target_ratio.base = 0;
      u_lane_change_target_ratio.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_change_target_ratio.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lane_change_target_ratio.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lane_change_target_ratio.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lane_change_target_ratio = u_lane_change_target_ratio.real;
      offset += sizeof(this->lane_change_target_ratio);
      union {
        float real;
        uint32_t base;
      } u_lane_change_target_minimum;
      u_lane_change_target_minimum.base = 0;
      u_lane_change_target_minimum.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_change_target_minimum.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lane_change_target_minimum.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lane_change_target_minimum.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lane_change_target_minimum = u_lane_change_target_minimum.real;
      offset += sizeof(this->lane_change_target_minimum);
      union {
        float real;
        uint32_t base;
      } u_vector_length_hermite_curve;
      u_vector_length_hermite_curve.base = 0;
      u_vector_length_hermite_curve.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vector_length_hermite_curve.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vector_length_hermite_curve.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vector_length_hermite_curve.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vector_length_hermite_curve = u_vector_length_hermite_curve.real;
      offset += sizeof(this->vector_length_hermite_curve);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigLaneSelect"; };
    const char * getMD5(){ return "68a997e92b2cc13c26ae68a329dd0433"; };

  };

}
#endif