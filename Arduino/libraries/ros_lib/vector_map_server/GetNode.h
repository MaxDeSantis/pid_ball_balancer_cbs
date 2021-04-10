#ifndef _ROS_SERVICE_GetNode_h
#define _ROS_SERVICE_GetNode_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "vector_map_msgs/NodeArray.h"
#include "geometry_msgs/PoseStamped.h"
#include "autoware_msgs/Lane.h"

namespace vector_map_server
{

static const char GETNODE[] = "vector_map_server/GetNode";

  class GetNodeRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _pose_type;
      _pose_type pose;
      typedef autoware_msgs::Lane _waypoints_type;
      _waypoints_type waypoints;

    GetNodeRequest():
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

    const char * getType(){ return GETNODE; };
    const char * getMD5(){ return "d1f64bdec952e41012fc8c13f57fef77"; };

  };

  class GetNodeResponse : public ros::Msg
  {
    public:
      typedef vector_map_msgs::NodeArray _objects_type;
      _objects_type objects;

    GetNodeResponse():
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

    const char * getType(){ return GETNODE; };
    const char * getMD5(){ return "8948a4f88cd78eafaa373398537426d7"; };

  };

  class GetNode {
    public:
    typedef GetNodeRequest Request;
    typedef GetNodeResponse Response;
  };

}
#endif
