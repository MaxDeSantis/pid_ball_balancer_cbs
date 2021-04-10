#ifndef _ROS_autoware_msgs_Waypoint_h
#define _ROS_autoware_msgs_Waypoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/TwistStamped.h"
#include "autoware_msgs/DTLane.h"
#include "autoware_msgs/WaypointState.h"

namespace autoware_msgs
{

  class Waypoint : public ros::Msg
  {
    public:
      typedef int32_t _gid_type;
      _gid_type gid;
      typedef int32_t _lid_type;
      _lid_type lid;
      typedef geometry_msgs::PoseStamped _pose_type;
      _pose_type pose;
      typedef geometry_msgs::TwistStamped _twist_type;
      _twist_type twist;
      typedef autoware_msgs::DTLane _dtlane_type;
      _dtlane_type dtlane;
      typedef int32_t _change_flag_type;
      _change_flag_type change_flag;
      typedef autoware_msgs::WaypointState _wpstate_type;
      _wpstate_type wpstate;
      typedef uint32_t _lane_id_type;
      _lane_id_type lane_id;
      typedef uint32_t _left_lane_id_type;
      _left_lane_id_type left_lane_id;
      typedef uint32_t _right_lane_id_type;
      _right_lane_id_type right_lane_id;
      typedef uint32_t _stop_line_id_type;
      _stop_line_id_type stop_line_id;
      typedef float _cost_type;
      _cost_type cost;
      typedef float _time_cost_type;
      _time_cost_type time_cost;
      typedef uint32_t _direction_type;
      _direction_type direction;

    Waypoint():
      gid(0),
      lid(0),
      pose(),
      twist(),
      dtlane(),
      change_flag(0),
      wpstate(),
      lane_id(0),
      left_lane_id(0),
      right_lane_id(0),
      stop_line_id(0),
      cost(0),
      time_cost(0),
      direction(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_gid;
      u_gid.real = this->gid;
      *(outbuffer + offset + 0) = (u_gid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gid);
      union {
        int32_t real;
        uint32_t base;
      } u_lid;
      u_lid.real = this->lid;
      *(outbuffer + offset + 0) = (u_lid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lid);
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->twist.serialize(outbuffer + offset);
      offset += this->dtlane.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_change_flag;
      u_change_flag.real = this->change_flag;
      *(outbuffer + offset + 0) = (u_change_flag.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_change_flag.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_change_flag.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_change_flag.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->change_flag);
      offset += this->wpstate.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->lane_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lane_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lane_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lane_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_id);
      *(outbuffer + offset + 0) = (this->left_lane_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->left_lane_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->left_lane_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->left_lane_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_lane_id);
      *(outbuffer + offset + 0) = (this->right_lane_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->right_lane_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->right_lane_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->right_lane_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_lane_id);
      *(outbuffer + offset + 0) = (this->stop_line_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stop_line_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stop_line_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stop_line_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stop_line_id);
      union {
        float real;
        uint32_t base;
      } u_cost;
      u_cost.real = this->cost;
      *(outbuffer + offset + 0) = (u_cost.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cost.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cost.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cost.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cost);
      union {
        float real;
        uint32_t base;
      } u_time_cost;
      u_time_cost.real = this->time_cost;
      *(outbuffer + offset + 0) = (u_time_cost.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time_cost.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time_cost.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time_cost.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_cost);
      *(outbuffer + offset + 0) = (this->direction >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->direction >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->direction >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->direction >> (8 * 3)) & 0xFF;
      offset += sizeof(this->direction);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_gid;
      u_gid.base = 0;
      u_gid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gid = u_gid.real;
      offset += sizeof(this->gid);
      union {
        int32_t real;
        uint32_t base;
      } u_lid;
      u_lid.base = 0;
      u_lid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lid = u_lid.real;
      offset += sizeof(this->lid);
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->twist.deserialize(inbuffer + offset);
      offset += this->dtlane.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_change_flag;
      u_change_flag.base = 0;
      u_change_flag.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_change_flag.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_change_flag.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_change_flag.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->change_flag = u_change_flag.real;
      offset += sizeof(this->change_flag);
      offset += this->wpstate.deserialize(inbuffer + offset);
      this->lane_id =  ((uint32_t) (*(inbuffer + offset)));
      this->lane_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->lane_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->lane_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->lane_id);
      this->left_lane_id =  ((uint32_t) (*(inbuffer + offset)));
      this->left_lane_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->left_lane_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->left_lane_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->left_lane_id);
      this->right_lane_id =  ((uint32_t) (*(inbuffer + offset)));
      this->right_lane_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->right_lane_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->right_lane_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->right_lane_id);
      this->stop_line_id =  ((uint32_t) (*(inbuffer + offset)));
      this->stop_line_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stop_line_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stop_line_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stop_line_id);
      union {
        float real;
        uint32_t base;
      } u_cost;
      u_cost.base = 0;
      u_cost.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cost.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cost.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cost.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cost = u_cost.real;
      offset += sizeof(this->cost);
      union {
        float real;
        uint32_t base;
      } u_time_cost;
      u_time_cost.base = 0;
      u_time_cost.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time_cost.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time_cost.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time_cost.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->time_cost = u_time_cost.real;
      offset += sizeof(this->time_cost);
      this->direction =  ((uint32_t) (*(inbuffer + offset)));
      this->direction |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->direction |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->direction |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->direction);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/Waypoint"; };
    const char * getMD5(){ return "f980f8144ba8190e8db52ab486d506e2"; };

  };

}
#endif