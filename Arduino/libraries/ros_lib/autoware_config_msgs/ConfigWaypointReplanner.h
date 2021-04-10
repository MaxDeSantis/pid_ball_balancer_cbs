#ifndef _ROS_autoware_config_msgs_ConfigWaypointReplanner_h
#define _ROS_autoware_config_msgs_ConfigWaypointReplanner_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_config_msgs
{

  class ConfigWaypointReplanner : public ros::Msg
  {
    public:
      typedef const char* _multi_lane_csv_type;
      _multi_lane_csv_type multi_lane_csv;
      typedef bool _replanning_mode_type;
      _replanning_mode_type replanning_mode;
      typedef float _velocity_max_type;
      _velocity_max_type velocity_max;
      typedef float _velocity_min_type;
      _velocity_min_type velocity_min;
      typedef float _accel_limit_type;
      _accel_limit_type accel_limit;
      typedef float _decel_limit_type;
      _decel_limit_type decel_limit;
      typedef float _radius_thresh_type;
      _radius_thresh_type radius_thresh;
      typedef float _radius_min_type;
      _radius_min_type radius_min;
      typedef bool _resample_mode_type;
      _resample_mode_type resample_mode;
      typedef float _resample_interval_type;
      _resample_interval_type resample_interval;
      typedef int32_t _velocity_offset_type;
      _velocity_offset_type velocity_offset;
      typedef int32_t _end_point_offset_type;
      _end_point_offset_type end_point_offset;
      typedef int32_t _braking_distance_type;
      _braking_distance_type braking_distance;
      typedef bool _replan_curve_mode_type;
      _replan_curve_mode_type replan_curve_mode;
      typedef bool _replan_endpoint_mode_type;
      _replan_endpoint_mode_type replan_endpoint_mode;
      typedef bool _overwrite_vmax_mode_type;
      _overwrite_vmax_mode_type overwrite_vmax_mode;
      typedef bool _realtime_tuning_mode_type;
      _realtime_tuning_mode_type realtime_tuning_mode;

    ConfigWaypointReplanner():
      multi_lane_csv(""),
      replanning_mode(0),
      velocity_max(0),
      velocity_min(0),
      accel_limit(0),
      decel_limit(0),
      radius_thresh(0),
      radius_min(0),
      resample_mode(0),
      resample_interval(0),
      velocity_offset(0),
      end_point_offset(0),
      braking_distance(0),
      replan_curve_mode(0),
      replan_endpoint_mode(0),
      overwrite_vmax_mode(0),
      realtime_tuning_mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_multi_lane_csv = strlen(this->multi_lane_csv);
      varToArr(outbuffer + offset, length_multi_lane_csv);
      offset += 4;
      memcpy(outbuffer + offset, this->multi_lane_csv, length_multi_lane_csv);
      offset += length_multi_lane_csv;
      union {
        bool real;
        uint8_t base;
      } u_replanning_mode;
      u_replanning_mode.real = this->replanning_mode;
      *(outbuffer + offset + 0) = (u_replanning_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->replanning_mode);
      union {
        float real;
        uint32_t base;
      } u_velocity_max;
      u_velocity_max.real = this->velocity_max;
      *(outbuffer + offset + 0) = (u_velocity_max.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_max.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_max.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_max.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_max);
      union {
        float real;
        uint32_t base;
      } u_velocity_min;
      u_velocity_min.real = this->velocity_min;
      *(outbuffer + offset + 0) = (u_velocity_min.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_min.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_min.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_min.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_min);
      union {
        float real;
        uint32_t base;
      } u_accel_limit;
      u_accel_limit.real = this->accel_limit;
      *(outbuffer + offset + 0) = (u_accel_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accel_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_accel_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_accel_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accel_limit);
      union {
        float real;
        uint32_t base;
      } u_decel_limit;
      u_decel_limit.real = this->decel_limit;
      *(outbuffer + offset + 0) = (u_decel_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_decel_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_decel_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_decel_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->decel_limit);
      union {
        float real;
        uint32_t base;
      } u_radius_thresh;
      u_radius_thresh.real = this->radius_thresh;
      *(outbuffer + offset + 0) = (u_radius_thresh.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_radius_thresh.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_radius_thresh.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_radius_thresh.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->radius_thresh);
      union {
        float real;
        uint32_t base;
      } u_radius_min;
      u_radius_min.real = this->radius_min;
      *(outbuffer + offset + 0) = (u_radius_min.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_radius_min.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_radius_min.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_radius_min.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->radius_min);
      union {
        bool real;
        uint8_t base;
      } u_resample_mode;
      u_resample_mode.real = this->resample_mode;
      *(outbuffer + offset + 0) = (u_resample_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->resample_mode);
      union {
        float real;
        uint32_t base;
      } u_resample_interval;
      u_resample_interval.real = this->resample_interval;
      *(outbuffer + offset + 0) = (u_resample_interval.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_resample_interval.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_resample_interval.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_resample_interval.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->resample_interval);
      union {
        int32_t real;
        uint32_t base;
      } u_velocity_offset;
      u_velocity_offset.real = this->velocity_offset;
      *(outbuffer + offset + 0) = (u_velocity_offset.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_offset.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_offset.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_offset.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_offset);
      union {
        int32_t real;
        uint32_t base;
      } u_end_point_offset;
      u_end_point_offset.real = this->end_point_offset;
      *(outbuffer + offset + 0) = (u_end_point_offset.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_end_point_offset.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_end_point_offset.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_end_point_offset.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->end_point_offset);
      union {
        int32_t real;
        uint32_t base;
      } u_braking_distance;
      u_braking_distance.real = this->braking_distance;
      *(outbuffer + offset + 0) = (u_braking_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_braking_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_braking_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_braking_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->braking_distance);
      union {
        bool real;
        uint8_t base;
      } u_replan_curve_mode;
      u_replan_curve_mode.real = this->replan_curve_mode;
      *(outbuffer + offset + 0) = (u_replan_curve_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->replan_curve_mode);
      union {
        bool real;
        uint8_t base;
      } u_replan_endpoint_mode;
      u_replan_endpoint_mode.real = this->replan_endpoint_mode;
      *(outbuffer + offset + 0) = (u_replan_endpoint_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->replan_endpoint_mode);
      union {
        bool real;
        uint8_t base;
      } u_overwrite_vmax_mode;
      u_overwrite_vmax_mode.real = this->overwrite_vmax_mode;
      *(outbuffer + offset + 0) = (u_overwrite_vmax_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->overwrite_vmax_mode);
      union {
        bool real;
        uint8_t base;
      } u_realtime_tuning_mode;
      u_realtime_tuning_mode.real = this->realtime_tuning_mode;
      *(outbuffer + offset + 0) = (u_realtime_tuning_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->realtime_tuning_mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_multi_lane_csv;
      arrToVar(length_multi_lane_csv, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_multi_lane_csv; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_multi_lane_csv-1]=0;
      this->multi_lane_csv = (char *)(inbuffer + offset-1);
      offset += length_multi_lane_csv;
      union {
        bool real;
        uint8_t base;
      } u_replanning_mode;
      u_replanning_mode.base = 0;
      u_replanning_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->replanning_mode = u_replanning_mode.real;
      offset += sizeof(this->replanning_mode);
      union {
        float real;
        uint32_t base;
      } u_velocity_max;
      u_velocity_max.base = 0;
      u_velocity_max.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_max.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_max.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_max.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity_max = u_velocity_max.real;
      offset += sizeof(this->velocity_max);
      union {
        float real;
        uint32_t base;
      } u_velocity_min;
      u_velocity_min.base = 0;
      u_velocity_min.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_min.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_min.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_min.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity_min = u_velocity_min.real;
      offset += sizeof(this->velocity_min);
      union {
        float real;
        uint32_t base;
      } u_accel_limit;
      u_accel_limit.base = 0;
      u_accel_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accel_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_accel_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_accel_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->accel_limit = u_accel_limit.real;
      offset += sizeof(this->accel_limit);
      union {
        float real;
        uint32_t base;
      } u_decel_limit;
      u_decel_limit.base = 0;
      u_decel_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_decel_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_decel_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_decel_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->decel_limit = u_decel_limit.real;
      offset += sizeof(this->decel_limit);
      union {
        float real;
        uint32_t base;
      } u_radius_thresh;
      u_radius_thresh.base = 0;
      u_radius_thresh.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_radius_thresh.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_radius_thresh.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_radius_thresh.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->radius_thresh = u_radius_thresh.real;
      offset += sizeof(this->radius_thresh);
      union {
        float real;
        uint32_t base;
      } u_radius_min;
      u_radius_min.base = 0;
      u_radius_min.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_radius_min.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_radius_min.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_radius_min.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->radius_min = u_radius_min.real;
      offset += sizeof(this->radius_min);
      union {
        bool real;
        uint8_t base;
      } u_resample_mode;
      u_resample_mode.base = 0;
      u_resample_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->resample_mode = u_resample_mode.real;
      offset += sizeof(this->resample_mode);
      union {
        float real;
        uint32_t base;
      } u_resample_interval;
      u_resample_interval.base = 0;
      u_resample_interval.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_resample_interval.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_resample_interval.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_resample_interval.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->resample_interval = u_resample_interval.real;
      offset += sizeof(this->resample_interval);
      union {
        int32_t real;
        uint32_t base;
      } u_velocity_offset;
      u_velocity_offset.base = 0;
      u_velocity_offset.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_offset.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_offset.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_offset.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity_offset = u_velocity_offset.real;
      offset += sizeof(this->velocity_offset);
      union {
        int32_t real;
        uint32_t base;
      } u_end_point_offset;
      u_end_point_offset.base = 0;
      u_end_point_offset.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_end_point_offset.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_end_point_offset.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_end_point_offset.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->end_point_offset = u_end_point_offset.real;
      offset += sizeof(this->end_point_offset);
      union {
        int32_t real;
        uint32_t base;
      } u_braking_distance;
      u_braking_distance.base = 0;
      u_braking_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_braking_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_braking_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_braking_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->braking_distance = u_braking_distance.real;
      offset += sizeof(this->braking_distance);
      union {
        bool real;
        uint8_t base;
      } u_replan_curve_mode;
      u_replan_curve_mode.base = 0;
      u_replan_curve_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->replan_curve_mode = u_replan_curve_mode.real;
      offset += sizeof(this->replan_curve_mode);
      union {
        bool real;
        uint8_t base;
      } u_replan_endpoint_mode;
      u_replan_endpoint_mode.base = 0;
      u_replan_endpoint_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->replan_endpoint_mode = u_replan_endpoint_mode.real;
      offset += sizeof(this->replan_endpoint_mode);
      union {
        bool real;
        uint8_t base;
      } u_overwrite_vmax_mode;
      u_overwrite_vmax_mode.base = 0;
      u_overwrite_vmax_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->overwrite_vmax_mode = u_overwrite_vmax_mode.real;
      offset += sizeof(this->overwrite_vmax_mode);
      union {
        bool real;
        uint8_t base;
      } u_realtime_tuning_mode;
      u_realtime_tuning_mode.base = 0;
      u_realtime_tuning_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->realtime_tuning_mode = u_realtime_tuning_mode.real;
      offset += sizeof(this->realtime_tuning_mode);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigWaypointReplanner"; };
    const char * getMD5(){ return "b977c0671288918d2249913fbdf6a1f8"; };

  };

}
#endif