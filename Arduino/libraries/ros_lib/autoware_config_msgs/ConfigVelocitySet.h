#ifndef _ROS_autoware_config_msgs_ConfigVelocitySet_h
#define _ROS_autoware_config_msgs_ConfigVelocitySet_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigVelocitySet : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _stop_distance_obstacle_type;
      _stop_distance_obstacle_type stop_distance_obstacle;
      typedef float _stop_distance_stopline_type;
      _stop_distance_stopline_type stop_distance_stopline;
      typedef float _detection_range_type;
      _detection_range_type detection_range;
      typedef int32_t _threshold_points_type;
      _threshold_points_type threshold_points;
      typedef float _detection_height_top_type;
      _detection_height_top_type detection_height_top;
      typedef float _detection_height_bottom_type;
      _detection_height_bottom_type detection_height_bottom;
      typedef float _deceleration_obstacle_type;
      _deceleration_obstacle_type deceleration_obstacle;
      typedef float _deceleration_stopline_type;
      _deceleration_stopline_type deceleration_stopline;
      typedef float _velocity_change_limit_type;
      _velocity_change_limit_type velocity_change_limit;
      typedef float _deceleration_range_type;
      _deceleration_range_type deceleration_range;
      typedef float _temporal_waypoints_size_type;
      _temporal_waypoints_size_type temporal_waypoints_size;

    ConfigVelocitySet():
      header(),
      stop_distance_obstacle(0),
      stop_distance_stopline(0),
      detection_range(0),
      threshold_points(0),
      detection_height_top(0),
      detection_height_bottom(0),
      deceleration_obstacle(0),
      deceleration_stopline(0),
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
      } u_stop_distance_obstacle;
      u_stop_distance_obstacle.real = this->stop_distance_obstacle;
      *(outbuffer + offset + 0) = (u_stop_distance_obstacle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stop_distance_obstacle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stop_distance_obstacle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stop_distance_obstacle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stop_distance_obstacle);
      union {
        float real;
        uint32_t base;
      } u_stop_distance_stopline;
      u_stop_distance_stopline.real = this->stop_distance_stopline;
      *(outbuffer + offset + 0) = (u_stop_distance_stopline.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stop_distance_stopline.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stop_distance_stopline.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stop_distance_stopline.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stop_distance_stopline);
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
      } u_deceleration_obstacle;
      u_deceleration_obstacle.real = this->deceleration_obstacle;
      *(outbuffer + offset + 0) = (u_deceleration_obstacle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_deceleration_obstacle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_deceleration_obstacle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_deceleration_obstacle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->deceleration_obstacle);
      union {
        float real;
        uint32_t base;
      } u_deceleration_stopline;
      u_deceleration_stopline.real = this->deceleration_stopline;
      *(outbuffer + offset + 0) = (u_deceleration_stopline.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_deceleration_stopline.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_deceleration_stopline.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_deceleration_stopline.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->deceleration_stopline);
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
      } u_stop_distance_obstacle;
      u_stop_distance_obstacle.base = 0;
      u_stop_distance_obstacle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stop_distance_obstacle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stop_distance_obstacle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stop_distance_obstacle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->stop_distance_obstacle = u_stop_distance_obstacle.real;
      offset += sizeof(this->stop_distance_obstacle);
      union {
        float real;
        uint32_t base;
      } u_stop_distance_stopline;
      u_stop_distance_stopline.base = 0;
      u_stop_distance_stopline.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stop_distance_stopline.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stop_distance_stopline.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stop_distance_stopline.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->stop_distance_stopline = u_stop_distance_stopline.real;
      offset += sizeof(this->stop_distance_stopline);
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
      } u_deceleration_obstacle;
      u_deceleration_obstacle.base = 0;
      u_deceleration_obstacle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_deceleration_obstacle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_deceleration_obstacle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_deceleration_obstacle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->deceleration_obstacle = u_deceleration_obstacle.real;
      offset += sizeof(this->deceleration_obstacle);
      union {
        float real;
        uint32_t base;
      } u_deceleration_stopline;
      u_deceleration_stopline.base = 0;
      u_deceleration_stopline.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_deceleration_stopline.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_deceleration_stopline.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_deceleration_stopline.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->deceleration_stopline = u_deceleration_stopline.real;
      offset += sizeof(this->deceleration_stopline);
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

    const char * getType(){ return "autoware_config_msgs/ConfigVelocitySet"; };
    const char * getMD5(){ return "8ff27cdafa62bc9e7b03bb94912cfaf3"; };

  };

}
#endif