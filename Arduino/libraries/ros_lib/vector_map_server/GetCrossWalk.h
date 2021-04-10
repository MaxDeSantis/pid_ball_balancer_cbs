#ifndef _ROS_SERVICE_GetCrossWalk_h
#define _ROS_SERVICE_GetCrossWalk_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "vector_map_msgs/CrossWalkArray.h"
#include "geometry_msgs/PoseStamped.h"
#include "autoware_msgs/Lane.h"

namespace vector_map_server
{

static const char GETCROSSWALK[] = "vector_map_server/GetCrossWalk";

  class GetCrossWalkRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _pose_type;
      _pose_type pose;
      typedef autoware_msgs::Lane _waypoints_type;
      _waypoints_type waypoints;

    GetCrossWalkRequest():
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

    const char * getType(){ return GETCROSSWALK; };
    const char * getMD5(){ return "d1f64bdec952e41012fc8c13f57fef77"; };

  };

  class GetCrossWalkResponse : public ros::Msg
  {
    public:
      typedef vector_map_msgs::CrossWalkArray _objects_type;
      _objects_type objects;

    GetCrossWalkResponse():
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

    const char * getType(){ return GETCROSSWALK; };
    const char * getMD5(){ return "36a0e37fbe771afc34a2d7c0116919f9"; };

  };

  class GetCrossWalk {
    public:
    typedef GetCrossWalkRequest Request;
    typedef GetCrossWalkResponse Response;
  };

}
#endif
