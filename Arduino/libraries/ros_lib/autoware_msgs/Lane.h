#ifndef _ROS_autoware_msgs_Lane_h
#define _ROS_autoware_msgs_Lane_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_msgs/Waypoint.h"

namespace autoware_msgs
{

  class Lane : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _increment_type;
      _increment_type increment;
      typedef int32_t _lane_id_type;
      _lane_id_type lane_id;
      uint32_t waypoints_length;
      typedef autoware_msgs::Waypoint _waypoints_type;
      _waypoints_type st_waypoints;
      _waypoints_type * waypoints;
      typedef uint32_t _lane_index_type;
      _lane_index_type lane_index;
      typedef float _cost_type;
      _cost_type cost;
      typedef float _closest_object_distance_type;
      _closest_object_distance_type closest_object_distance;
      typedef float _closest_object_velocity_type;
      _closest_object_velocity_type closest_object_velocity;
      typedef bool _is_blocked_type;
      _is_blocked_type is_blocked;

    Lane():
      header(),
      increment(0),
      lane_id(0),
      waypoints_length(0), waypoints(NULL),
      lane_index(0),
      cost(0),
      closest_object_distance(0),
      closest_object_velocity(0),
      is_blocked(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_increment;
      u_increment.real = this->increment;
      *(outbuffer + offset + 0) = (u_increment.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_increment.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_increment.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_increment.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->increment);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_id;
      u_lane_id.real = this->lane_id;
      *(outbuffer + offset + 0) = (u_lane_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_id);
      *(outbuffer + offset + 0) = (this->waypoints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->waypoints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->waypoints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->waypoints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->waypoints_length);
      for( uint32_t i = 0; i < waypoints_length; i++){
      offset += this->waypoints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->lane_index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lane_index >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lane_index >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lane_index >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_index);
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
      } u_closest_object_distance;
      u_closest_object_distance.real = this->closest_object_distance;
      *(outbuffer + offset + 0) = (u_closest_object_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_closest_object_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_closest_object_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_closest_object_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->closest_object_distance);
      union {
        float real;
        uint32_t base;
      } u_closest_object_velocity;
      u_closest_object_velocity.real = this->closest_object_velocity;
      *(outbuffer + offset + 0) = (u_closest_object_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_closest_object_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_closest_object_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_closest_object_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->closest_object_velocity);
      union {
        bool real;
        uint8_t base;
      } u_is_blocked;
      u_is_blocked.real = this->is_blocked;
      *(outbuffer + offset + 0) = (u_is_blocked.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_blocked);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_increment;
      u_increment.base = 0;
      u_increment.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_increment.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_increment.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_increment.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->increment = u_increment.real;
      offset += sizeof(this->increment);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_id;
      u_lane_id.base = 0;
      u_lane_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lane_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lane_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lane_id = u_lane_id.real;
      offset += sizeof(this->lane_id);
      uint32_t waypoints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      waypoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      waypoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      waypoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->waypoints_length);
      if(waypoints_lengthT > waypoints_length)
        this->waypoints = (autoware_msgs::Waypoint*)realloc(this->waypoints, waypoints_lengthT * sizeof(autoware_msgs::Waypoint));
      waypoints_length = waypoints_lengthT;
      for( uint32_t i = 0; i < waypoints_length; i++){
      offset += this->st_waypoints.deserialize(inbuffer + offset);
        memcpy( &(this->waypoints[i]), &(this->st_waypoints), sizeof(autoware_msgs::Waypoint));
      }
      this->lane_index =  ((uint32_t) (*(inbuffer + offset)));
      this->lane_index |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->lane_index |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->lane_index |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->lane_index);
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
      } u_closest_object_distance;
      u_closest_object_distance.base = 0;
      u_closest_object_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_closest_object_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_closest_object_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_closest_object_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->closest_object_distance = u_closest_object_distance.real;
      offset += sizeof(this->closest_object_distance);
      union {
        float real;
        uint32_t base;
      } u_closest_object_velocity;
      u_closest_object_velocity.base = 0;
      u_closest_object_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_closest_object_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_closest_object_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_closest_object_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->closest_object_velocity = u_closest_object_velocity.real;
      offset += sizeof(this->closest_object_velocity);
      union {
        bool real;
        uint8_t base;
      } u_is_blocked;
      u_is_blocked.base = 0;
      u_is_blocked.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_blocked = u_is_blocked.real;
      offset += sizeof(this->is_blocked);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/Lane"; };
    const char * getMD5(){ return "40bde126fe5f348ef74699a32398ac74"; };

  };

}
#endif