#ifndef _ROS_SERVICE_GetRoadMark_h
#define _ROS_SERVICE_GetRoadMark_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "autoware_msgs/Lane.h"
#include "vector_map_msgs/RoadMarkArray.h"

namespace vector_map_server
{

static const char GETROADMARK[] = "vector_map_server/GetRoadMark";

  class GetRoadMarkRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _pose_type;
      _pose_type pose;
      typedef autoware_msgs::Lane _waypoints_type;
      _waypoints_type waypoints;

    GetRoadMarkRequest():
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

    const char * getType(){ return GETROADMARK; };
    const char * getMD5(){ return "d1f64bdec952e41012fc8c13f57fef77"; };

  };

  class GetRoadMarkResponse : public ros::Msg
  {
    public:
      typedef vector_map_msgs::RoadMarkArray _objects_type;
      _objects_type objects;

    GetRoadMarkResponse():
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

    const char * getType(){ return GETROADMARK; };
    const char * getMD5(){ return "940ffa72a3b35e28520d814d5291ea3f"; };

  };

  class GetRoadMark {
    public:
    typedef GetRoadMarkRequest Request;
    typedef GetRoadMarkResponse Response;
  };

}
#endif
