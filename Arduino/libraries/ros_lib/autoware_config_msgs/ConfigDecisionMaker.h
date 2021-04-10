#ifndef _ROS_autoware_config_msgs_ConfigDecisionMaker_h
#define _ROS_autoware_config_msgs_ConfigDecisionMaker_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigDecisionMaker : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _auto_mission_reload_type;
      _auto_mission_reload_type auto_mission_reload;
      typedef bool _auto_engage_type;
      _auto_engage_type auto_engage;
      typedef bool _auto_mission_change_type;
      _auto_mission_change_type auto_mission_change;
      typedef bool _use_fms_type;
      _use_fms_type use_fms;
      typedef bool _disuse_vector_map_type;
      _disuse_vector_map_type disuse_vector_map;
      typedef uint32_t _num_of_steer_behind_type;
      _num_of_steer_behind_type num_of_steer_behind;
      typedef float _change_threshold_dist_type;
      _change_threshold_dist_type change_threshold_dist;
      typedef float _change_threshold_angle_type;
      _change_threshold_angle_type change_threshold_angle;
      typedef float _goal_threshold_dist_type;
      _goal_threshold_dist_type goal_threshold_dist;
      typedef float _goal_threshold_vel_type;
      _goal_threshold_vel_type goal_threshold_vel;
      typedef float _stopped_vel_type;
      _stopped_vel_type stopped_vel;

    ConfigDecisionMaker():
      header(),
      auto_mission_reload(0),
      auto_engage(0),
      auto_mission_change(0),
      use_fms(0),
      disuse_vector_map(0),
      num_of_steer_behind(0),
      change_threshold_dist(0),
      change_threshold_angle(0),
      goal_threshold_dist(0),
      goal_threshold_vel(0),
      stopped_vel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_auto_mission_reload;
      u_auto_mission_reload.real = this->auto_mission_reload;
      *(outbuffer + offset + 0) = (u_auto_mission_reload.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->auto_mission_reload);
      union {
        bool real;
        uint8_t base;
      } u_auto_engage;
      u_auto_engage.real = this->auto_engage;
      *(outbuffer + offset + 0) = (u_auto_engage.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->auto_engage);
      union {
        bool real;
        uint8_t base;
      } u_auto_mission_change;
      u_auto_mission_change.real = this->auto_mission_change;
      *(outbuffer + offset + 0) = (u_auto_mission_change.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->auto_mission_change);
      union {
        bool real;
        uint8_t base;
      } u_use_fms;
      u_use_fms.real = this->use_fms;
      *(outbuffer + offset + 0) = (u_use_fms.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_fms);
      union {
        bool real;
        uint8_t base;
      } u_disuse_vector_map;
      u_disuse_vector_map.real = this->disuse_vector_map;
      *(outbuffer + offset + 0) = (u_disuse_vector_map.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->disuse_vector_map);
      *(outbuffer + offset + 0) = (this->num_of_steer_behind >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_of_steer_behind >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->num_of_steer_behind >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->num_of_steer_behind >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_of_steer_behind);
      offset += serializeAvrFloat64(outbuffer + offset, this->change_threshold_dist);
      offset += serializeAvrFloat64(outbuffer + offset, this->change_threshold_angle);
      offset += serializeAvrFloat64(outbuffer + offset, this->goal_threshold_dist);
      offset += serializeAvrFloat64(outbuffer + offset, this->goal_threshold_vel);
      offset += serializeAvrFloat64(outbuffer + offset, this->stopped_vel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_auto_mission_reload;
      u_auto_mission_reload.base = 0;
      u_auto_mission_reload.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->auto_mission_reload = u_auto_mission_reload.real;
      offset += sizeof(this->auto_mission_reload);
      union {
        bool real;
        uint8_t base;
      } u_auto_engage;
      u_auto_engage.base = 0;
      u_auto_engage.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->auto_engage = u_auto_engage.real;
      offset += sizeof(this->auto_engage);
      union {
        bool real;
        uint8_t base;
      } u_auto_mission_change;
      u_auto_mission_change.base = 0;
      u_auto_mission_change.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->auto_mission_change = u_auto_mission_change.real;
      offset += sizeof(this->auto_mission_change);
      union {
        bool real;
        uint8_t base;
      } u_use_fms;
      u_use_fms.base = 0;
      u_use_fms.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_fms = u_use_fms.real;
      offset += sizeof(this->use_fms);
      union {
        bool real;
        uint8_t base;
      } u_disuse_vector_map;
      u_disuse_vector_map.base = 0;
      u_disuse_vector_map.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->disuse_vector_map = u_disuse_vector_map.real;
      offset += sizeof(this->disuse_vector_map);
      this->num_of_steer_behind =  ((uint32_t) (*(inbuffer + offset)));
      this->num_of_steer_behind |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->num_of_steer_behind |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->num_of_steer_behind |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->num_of_steer_behind);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->change_threshold_dist));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->change_threshold_angle));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->goal_threshold_dist));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->goal_threshold_vel));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->stopped_vel));
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigDecisionMaker"; };
    const char * getMD5(){ return "adfaf802f5ca35bf03b4eb5191ba9782"; };

  };

}
#endif