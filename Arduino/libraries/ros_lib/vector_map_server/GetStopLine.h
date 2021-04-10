#ifndef _ROS_SERVICE_GetStopLine_h
#define _ROS_SERVICE_GetStopLine_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "autoware_msgs/Lane.h"
#include "vector_map_msgs/StopLineArray.h"

namespace vector_map_server
{

static const char GETSTOPLINE[] = "vector_map_server/GetStopLine";

  class GetStopLineRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _pose_type;
      _pose_type pose;
      typedef autoware_msgs::Lane _waypoints_type;
      _waypoints_type waypoints;

    GetStopLineRequest():
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

    const char * getType(){ return GETSTOPLINE; };
    const char * getMD5(){ return "d1f64bdec952e41012fc8c13f57fef77"; };

  };

  class GetStopLineResponse : public ros::Msg
  {
    public:
      typedef vector_map_msgs::StopLineArray _objects_type;
      _objects_type objects;

    GetStopLineResponse():
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

    const char * getType(){ return GETSTOPLINE; };
    const char * getMD5(){ return "174113739c15edc9a40a21167b2f26f5"; };

  };

  class GetStopLine {
    public:
    typedef GetStopLineRequest Request;
    typedef GetStopLineResponse Response;
  };

}
#endif
