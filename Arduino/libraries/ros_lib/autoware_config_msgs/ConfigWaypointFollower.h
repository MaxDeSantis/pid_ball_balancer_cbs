#ifndef _ROS_autoware_config_msgs_ConfigWaypointFollower_h
#define _ROS_autoware_config_msgs_ConfigWaypointFollower_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigWaypointFollower : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _param_flag_type;
      _param_flag_type param_flag;
      typedef float _velocity_type;
      _velocity_type velocity;
      typedef float _lookahead_distance_type;
      _lookahead_distance_type lookahead_distance;
      typedef float _lookahead_ratio_type;
      _lookahead_ratio_type lookahead_ratio;
      typedef float _minimum_lookahead_distance_type;
      _minimum_lookahead_distance_type minimum_lookahead_distance;
      typedef float _displacement_threshold_type;
      _displacement_threshold_type displacement_threshold;
      typedef float _relative_angle_threshold_type;
      _relative_angle_threshold_type relative_angle_threshold;

    ConfigWaypointFollower():
      header(),
      param_flag(0),
      velocity(0),
      lookahead_distance(0),
      lookahead_ratio(0),
      minimum_lookahead_distance(0),
      displacement_threshold(0),
      relative_angle_threshold(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_param_flag;
      u_param_flag.real = this->param_flag;
      *(outbuffer + offset + 0) = (u_param_flag.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_param_flag.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_param_flag.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_param_flag.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->param_flag);
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.real = this->velocity;
      *(outbuffer + offset + 0) = (u_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity);
      union {
        float real;
        uint32_t base;
      } u_lookahead_distance;
      u_lookahead_distance.real = this->lookahead_distance;
      *(outbuffer + offset + 0) = (u_lookahead_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lookahead_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lookahead_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lookahead_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lookahead_distance);
      union {
        float real;
        uint32_t base;
      } u_lookahead_ratio;
      u_lookahead_ratio.real = this->lookahead_ratio;
      *(outbuffer + offset + 0) = (u_lookahead_ratio.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lookahead_ratio.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lookahead_ratio.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lookahead_ratio.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lookahead_ratio);
      union {
        float real;
        uint32_t base;
      } u_minimum_lookahead_distance;
      u_minimum_lookahead_distance.real = this->minimum_lookahead_distance;
      *(outbuffer + offset + 0) = (u_minimum_lookahead_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_minimum_lookahead_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_minimum_lookahead_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_minimum_lookahead_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->minimum_lookahead_distance);
      union {
        float real;
        uint32_t base;
      } u_displacement_threshold;
      u_displacement_threshold.real = this->displacement_threshold;
      *(outbuffer + offset + 0) = (u_displacement_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_displacement_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_displacement_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_displacement_threshold.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->displacement_threshold);
      union {
        float real;
        uint32_t base;
      } u_relative_angle_threshold;
      u_relative_angle_threshold.real = this->relative_angle_threshold;
      *(outbuffer + offset + 0) = (u_relative_angle_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_relative_angle_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_relative_angle_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_relative_angle_threshold.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->relative_angle_threshold);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_param_flag;
      u_param_flag.base = 0;
      u_param_flag.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_param_flag.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_param_flag.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_param_flag.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->param_flag = u_param_flag.real;
      offset += sizeof(this->param_flag);
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.base = 0;
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity = u_velocity.real;
      offset += sizeof(this->velocity);
      union {
        float real;
        uint32_t base;
      } u_lookahead_distance;
      u_lookahead_distance.base = 0;
      u_lookahead_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lookahead_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lookahead_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lookahead_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lookahead_distance = u_lookahead_distance.real;
      offset += sizeof(this->lookahead_distance);
      union {
        float real;
        uint32_t base;
      } u_lookahead_ratio;
      u_lookahead_ratio.base = 0;
      u_lookahead_ratio.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lookahead_ratio.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lookahead_ratio.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lookahead_ratio.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lookahead_ratio = u_lookahead_ratio.real;
      offset += sizeof(this->lookahead_ratio);
      union {
        float real;
        uint32_t base;
      } u_minimum_lookahead_distance;
      u_minimum_lookahead_distance.base = 0;
      u_minimum_lookahead_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_minimum_lookahead_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_minimum_lookahead_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_minimum_lookahead_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->minimum_lookahead_distance = u_minimum_lookahead_distance.real;
      offset += sizeof(this->minimum_lookahead_distance);
      union {
        float real;
        uint32_t base;
      } u_displacement_threshold;
      u_displacement_threshold.base = 0;
      u_displacement_threshold.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_displacement_threshold.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_displacement_threshold.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_displacement_threshold.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->displacement_threshold = u_displacement_threshold.real;
      offset += sizeof(this->displacement_threshold);
      union {
        float real;
        uint32_t base;
      } u_relative_angle_threshold;
      u_relative_angle_threshold.base = 0;
      u_relative_angle_threshold.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_relative_angle_threshold.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_relative_angle_threshold.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_relative_angle_threshold.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->relative_angle_threshold = u_relative_angle_threshold.real;
      offset += sizeof(this->relative_angle_threshold);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigWaypointFollower"; };
    const char * getMD5(){ return "a96d66ec56e0a5b1d46eff2062a223b3"; };

  };

}
#endif