#ifndef _ROS_autoware_config_msgs_ConfigLatticeVelocitySet_h
#define _ROS_autoware_config_msgs_ConfigLatticeVelocitySet_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigLatticeVelocitySet : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _others_distance_type;
      _others_distance_type others_distance;
      typedef float _detection_range_type;
      _detection_range_type detection_range;
      typedef int32_t _threshold_points_type;
      _threshold_points_type threshold_points;
      typedef float _detection_height_top_type;
      _detection_height_top_type detection_height_top;
      typedef float _detection_height_bottom_type;
      _detection_height_bottom_type detection_height_bottom;
      typedef float _deceleration_type;
      _deceleration_type deceleration;
      typedef float _velocity_change_limit_type;
      _velocity_change_limit_type velocity_change_limit;
      typedef float _deceleration_range_type;
      _deceleration_range_type deceleration_range;
      typedef float _temporal_waypoints_size_type;
      _temporal_waypoints_size_type temporal_waypoints_size;

    ConfigLatticeVelocitySet():
      header(),
      others_distance(0),
      detection_range(0),
      threshold_points(0),
      detection_height_top(0),
      detection_height_bottom(0),
      deceleration(0),
      velocity_change_limit(0),
      deceleration_range(0),
      temporal_waypoints_size(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_others_distance;
      u_others_distance.real = this->others_distance;
      *(outbuffer + offset + 0) = (u_others_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_others_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_others_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_others_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->others_distance);
      union {
        float real;
        uint32_t base;
      } u_detection_range;
      u_detection_range.real = this->detection_range;
      *(outbuffer + offset + 0) = (u_detection_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_detection_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_detection_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_detection_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->detection_range);
      union {
        int32_t real;
        uint32_t base;
      } u_threshold_points;
      u_threshold_points.real = this->threshold_points;
      *(outbuffer + offset + 0) = (u_threshold_points.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_threshold_points.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_threshold_points.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_threshold_points.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->threshold_points);
      union {
        float real;
        uint32_t base;
      } u_detection_height_top;
      u_detection_height_top.real = this->detection_height_top;
      *(outbuffer + offset + 0) = (u_detection_height_top.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_detection_height_top.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_detection_height_top.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_detection_height_top.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->detection_height_top);
      union {
        float real;
        uint32_t base;
      } u_detection_height_bottom;
      u_detection_height_bottom.real = this->detection_height_bottom;
      *(outbuffer + offset + 0) = (u_detection_height_bottom.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_detection_height_bottom.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_detection_height_bottom.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_detection_height_bottom.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->detection_height_bottom);
      union {
        float real;
        uint32_t base;
      } u_deceleration;
      u_deceleration.real = this->deceleration;
      *(outbuffer + offset + 0) = (u_deceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_deceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_deceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_deceleration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->deceleration);
      union {
        float real;
        uint32_t base;
      } u_velocity_change_limit;
      u_velocity_change_limit.real = this->velocity_change_limit;
      *(outbuffer + offset + 0) = (u_velocity_change_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_change_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_change_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_change_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_change_limit);
      union {
        float real;
        uint32_t base;
      } u_deceleration_range;
      u_deceleration_range.real = this->deceleration_range;
      *(outbuffer + offset + 0) = (u_deceleration_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_deceleration_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_deceleration_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_deceleration_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->deceleration_range);
      union {
        float real;
        uint32_t base;
      } u_temporal_waypoints_size;
      u_temporal_waypoints_size.real = this->temporal_waypoints_size;
      *(outbuffer + offset + 0) = (u_temporal_waypoints_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temporal_waypoints_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temporal_waypoints_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temporal_waypoints_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temporal_waypoints_size);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_others_distance;
      u_others_distance.base = 0;
      u_others_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_others_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_others_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_others_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->others_distance = u_others_distance.real;
      offset += sizeof(this->others_distance);
      union {
        float real;
        uint32_t base;
      } u_detection_range;
      u_detection_range.base = 0;
      u_detection_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_detection_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_detection_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_detection_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->detection_range = u_detection_range.real;
      offset += sizeof(this->detection_range);
      union {
        int32_t real;
        uint32_t base;
      } u_threshold_points;
      u_threshold_points.base = 0;
      u_threshold_points.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_threshold_points.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_threshold_points.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_threshold_points.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->threshold_points = u_threshold_points.real;
      offset += sizeof(this->threshold_points);
      union {
        float real;
        uint32_t base;
      } u_detection_height_top;
      u_detection_height_top.base = 0;
      u_detection_height_top.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_detection_height_top.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_detection_height_top.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_detection_height_top.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->detection_height_top = u_detection_height_top.real;
      offset += sizeof(this->detection_height_top);
      union {
        float real;
        uint32_t base;
      } u_detection_height_bottom;
      u_detection_height_bottom.base = 0;
      u_detection_height_bottom.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_detection_height_bottom.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_detection_height_bottom.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_detection_height_bottom.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->detection_height_bottom = u_detection_height_bottom.real;
      offset += sizeof(this->detection_height_bottom);
      union {
        float real;
        uint32_t base;
      } u_deceleration;
      u_deceleration.base = 0;
      u_deceleration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_deceleration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_deceleration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_deceleration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->deceleration = u_deceleration.real;
      offset += sizeof(this->deceleration);
      union {
        float real;
        uint32_t base;
      } u_velocity_change_limit;
      u_velocity_change_limit.base = 0;
      u_velocity_change_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_change_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_change_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_change_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity_change_limit = u_velocity_change_limit.real;
      offset += sizeof(this->velocity_change_limit);
      union {
        float real;
        uint32_t base;
      } u_deceleration_range;
      u_deceleration_range.base = 0;
      u_deceleration_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_deceleration_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_deceleration_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_deceleration_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->deceleration_range = u_deceleration_range.real;
      offset += sizeof(this->deceleration_range);
      union {
        float real;
        uint32_t base;
      } u_temporal_waypoints_size;
      u_temporal_waypoints_size.base = 0;
      u_temporal_waypoints_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temporal_waypoints_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temporal_waypoints_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temporal_waypoints_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temporal_waypoints_size = u_temporal_waypoints_size.real;
      offset += sizeof(this->temporal_waypoints_size);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigLatticeVelocitySet"; };
    const char * getMD5(){ return "7ef980a10c16f05933cfc170bd574214"; };

  };

}
#endif