#ifndef _ROS_autoware_msgs_VehicleLocation_h
#define _ROS_autoware_msgs_VehicleLocation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_msgs
{

  class VehicleLocation : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _lane_array_id_type;
      _lane_array_id_type lane_array_id;
      typedef int32_t _waypoint_index_type;
      _waypoint_index_type waypoint_index;

    VehicleLocation():
      header(),
      lane_array_id(0),
      waypoint_index(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_array_id;
      u_lane_array_id.real = this->lane_array_id;
      *(outbuffer + offset + 0) = (u_lane_array_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_array_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_array_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_array_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_array_id);
      union {
        int32_t real;
        uint32_t base;
      } u_waypoint_index;
      u_waypoint_index.real = this->waypoint_index;
      *(outbuffer + offset + 0) = (u_waypoint_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_waypoint_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_waypoint_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_waypoint_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->waypoint_index);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_array_id;
      u_lane_array_id.base = 0;
      u_lane_array_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_array_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lane_array_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lane_array_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lane_array_id = u_lane_array_id.real;
      offset += sizeof(this->lane_array_id);
      union {
        int32_t real;
        uint32_t base;
      } u_waypoint_index;
      u_waypoint_index.base = 0;
      u_waypoint_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_waypoint_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_waypoint_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_waypoint_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->waypoint_index = u_waypoint_index.real;
      offset += sizeof(this->waypoint_index);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/VehicleLocation"; };
    const char * getMD5(){ return "cba3770fc8eb8557ac8c63f4c0d3155b"; };

  };

}
#endif