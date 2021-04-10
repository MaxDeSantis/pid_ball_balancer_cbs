#ifndef _ROS_SERVICE_WaypointAddList_h
#define _ROS_SERVICE_WaypointAddList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"

namespace pathplanning
{

static const char WAYPOINTADDLIST[] = "pathplanning/WaypointAddList";

  class WaypointAddListRequest : public ros::Msg
  {
    public:
      uint32_t new_waypoint_list_length;
      typedef geometry_msgs::Pose2D _new_waypoint_list_type;
      _new_waypoint_list_type st_new_waypoint_list;
      _new_waypoint_list_type * new_waypoint_list;

    WaypointAddListRequest():
      new_waypoint_list_length(0), new_waypoint_list(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->new_waypoint_list_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->new_waypoint_list_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->new_waypoint_list_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->new_waypoint_list_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->new_waypoint_list_length);
      for( uint32_t i = 0; i < new_waypoint_list_length; i++){
      offset += this->new_waypoint_list[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t new_waypoint_list_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      new_waypoint_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      new_waypoint_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      new_waypoint_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->new_waypoint_list_length);
      if(new_waypoint_list_lengthT > new_waypoint_list_length)
        this->new_waypoint_list = (geometry_msgs::Pose2D*)realloc(this->new_waypoint_list, new_waypoint_list_lengthT * sizeof(geometry_msgs::Pose2D));
      new_waypoint_list_length = new_waypoint_list_lengthT;
      for( uint32_t i = 0; i < new_waypoint_list_length; i++){
      offset += this->st_new_waypoint_list.deserialize(inbuffer + offset);
        memcpy( &(this->new_waypoint_list[i]), &(this->st_new_waypoint_list), sizeof(geometry_msgs::Pose2D));
      }
     return offset;
    }

    const char * getType(){ return WAYPOINTADDLIST; };
    const char * getMD5(){ return "5c5ac72d0a3857b5046a8a92d95298c2"; };

  };

  class WaypointAddListResponse : public ros::Msg
  {
    public:

    WaypointAddListResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return WAYPOINTADDLIST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class WaypointAddList {
    public:
    typedef WaypointAddListRequest Request;
    typedef WaypointAddListResponse Response;
  };

}
#endif
