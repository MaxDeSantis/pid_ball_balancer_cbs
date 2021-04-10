#ifndef _ROS_SERVICE_GetRoadEdge_h
#define _ROS_SERVICE_GetRoadEdge_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "vector_map_msgs/RoadEdgeArray.h"
#include "autoware_msgs/Lane.h"

namespace vector_map_server
{

static const char GETROADEDGE[] = "vector_map_server/GetRoadEdge";

  class GetRoadEdgeRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _pose_type;
      _pose_type pose;
      typedef autoware_msgs::Lane _waypoints_type;
      _waypoints_type waypoints;

    GetRoadEdgeRequest():
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

    const char * getType(){ return GETROADEDGE; };
    const char * getMD5(){ return "d1f64bdec952e41012fc8c13f57fef77"; };

  };

  class GetRoadEdgeResponse : public ros::Msg
  {
    public:
      typedef vector_map_msgs::RoadEdgeArray _objects_type;
      _objects_type objects;

    GetRoadEdgeResponse():
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

    const char * getType(){ return GETROADEDGE; };
    const char * getMD5(){ return "bd9a2abeb71ea61e315c29d2d466b6cb"; };

  };

  class GetRoadEdge {
    public:
    typedef GetRoadEdgeRequest Request;
    typedef GetRoadEdgeResponse Response;
  };

}
#endif
