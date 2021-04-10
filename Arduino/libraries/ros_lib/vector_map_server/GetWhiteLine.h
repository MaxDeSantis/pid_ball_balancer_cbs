#ifndef _ROS_SERVICE_GetWhiteLine_h
#define _ROS_SERVICE_GetWhiteLine_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "vector_map_msgs/WhiteLineArray.h"
#include "geometry_msgs/PoseStamped.h"
#include "autoware_msgs/Lane.h"

namespace vector_map_server
{

static const char GETWHITELINE[] = "vector_map_server/GetWhiteLine";

  class GetWhiteLineRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _pose_type;
      _pose_type pose;
      typedef autoware_msgs::Lane _waypoints_type;
      _waypoints_type waypoints;

    GetWhiteLineRequest():
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

    const char * getType(){ return GETWHITELINE; };
    const char * getMD5(){ return "d1f64bdec952e41012fc8c13f57fef77"; };

  };

  class GetWhiteLineResponse : public ros::Msg
  {
    public:
      typedef vector_map_msgs::WhiteLineArray _objects_type;
      _objects_type objects;

    GetWhiteLineResponse():
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

    const char * getType(){ return GETWHITELINE; };
    const char * getMD5(){ return "9b4863e7d009c1ea19e7b6fbcc92b0bd"; };

  };

  class GetWhiteLine {
    public:
    typedef GetWhiteLineRequest Request;
    typedef GetWhiteLineResponse Response;
  };

}
#endif
