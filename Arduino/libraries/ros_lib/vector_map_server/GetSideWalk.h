#ifndef _ROS_SERVICE_GetSideWalk_h
#define _ROS_SERVICE_GetSideWalk_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "autoware_msgs/Lane.h"
#include "vector_map_msgs/SideWalkArray.h"

namespace vector_map_server
{

static const char GETSIDEWALK[] = "vector_map_server/GetSideWalk";

  class GetSideWalkRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _pose_type;
      _pose_type pose;
      typedef autoware_msgs::Lane _waypoints_type;
      _waypoints_type waypoints;

    GetSideWalkRequest():
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

    const char * getType(){ return GETSIDEWALK; };
    const char * getMD5(){ return "d1f64bdec952e41012fc8c13f57fef77"; };

  };

  class GetSideWalkResponse : public ros::Msg
  {
    public:
      typedef vector_map_msgs::SideWalkArray _objects_type;
      _objects_type objects;

    GetSideWalkResponse():
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

    const char * getType(){ return GETSIDEWALK; };
    const char * getMD5(){ return "3e2316da16f47f9b9b59ab373d7ae8a5"; };

  };

  class GetSideWalk {
    public:
    typedef GetSideWalkRequest Request;
    typedef GetSideWalkResponse Response;
  };

}
#endif
