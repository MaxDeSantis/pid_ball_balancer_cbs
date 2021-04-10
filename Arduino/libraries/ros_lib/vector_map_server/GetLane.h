#ifndef _ROS_SERVICE_GetLane_h
#define _ROS_SERVICE_GetLane_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "vector_map_msgs/LaneArray.h"
#include "autoware_msgs/Lane.h"

namespace vector_map_server
{

static const char GETLANE[] = "vector_map_server/GetLane";

  class GetLaneRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _pose_type;
      _pose_type pose;
      typedef autoware_msgs::Lane _waypoints_type;
      _waypoints_type waypoints;

    GetLaneRequest():
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

    const char * getType(){ return GETLANE; };
    const char * getMD5(){ return "d1f64bdec952e41012fc8c13f57fef77"; };

  };

  class GetLaneResponse : public ros::Msg
  {
    public:
      typedef vector_map_msgs::LaneArray _objects_type;
      _objects_type objects;

    GetLaneResponse():
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

    const char * getType(){ return GETLANE; };
    const char * getMD5(){ return "35ee85508b75c3b99d11e09886cc9933"; };

  };

  class GetLane {
    public:
    typedef GetLaneRequest Request;
    typedef GetLaneResponse Response;
  };

}
#endif
