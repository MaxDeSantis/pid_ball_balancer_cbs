#ifndef _ROS_SERVICE_GetRoadPole_h
#define _ROS_SERVICE_GetRoadPole_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "vector_map_msgs/RoadPoleArray.h"
#include "geometry_msgs/PoseStamped.h"
#include "autoware_msgs/Lane.h"

namespace vector_map_server
{

static const char GETROADPOLE[] = "vector_map_server/GetRoadPole";

  class GetRoadPoleRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _pose_type;
      _pose_type pose;
      typedef autoware_msgs::Lane _waypoints_type;
      _waypoints_type waypoints;

    GetRoadPoleRequest():
      pose(),
      waypoints()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->waypoints.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->waypoints.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETROADPOLE; };
    const char * getMD5(){ return "d1f64bdec952e41012fc8c13f57fef77"; };

  };

  class GetRoadPoleResponse : public ros::Msg
  {
    public:
      typedef vector_map_msgs::RoadPoleArray _objects_type;
      _objects_type objects;

    GetRoadPoleResponse():
      objects()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->objects.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->objects.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETROADPOLE; };
    const char * getMD5(){ return "38d3858578c73c6b13fdf06be65fa9aa"; };

  };

  class GetRoadPole {
    public:
    typedef GetRoadPoleRequest Request;
    typedef GetRoadPoleResponse Response;
  };

}
#endif
