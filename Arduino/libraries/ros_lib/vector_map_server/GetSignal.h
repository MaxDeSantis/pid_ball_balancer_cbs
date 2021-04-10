#ifndef _ROS_SERVICE_GetSignal_h
#define _ROS_SERVICE_GetSignal_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "autoware_msgs/Lane.h"
#include "vector_map_msgs/SignalArray.h"

namespace vector_map_server
{

static const char GETSIGNAL[] = "vector_map_server/GetSignal";

  class GetSignalRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _pose_type;
      _pose_type pose;
      typedef autoware_msgs::Lane _waypoints_type;
      _waypoints_type waypoints;

    GetSignalRequest():
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

    const char * getType(){ return GETSIGNAL; };
    const char * getMD5(){ return "d1f64bdec952e41012fc8c13f57fef77"; };

  };

  class GetSignalResponse : public ros::Msg
  {
    public:
      typedef vector_map_msgs::SignalArray _objects_type;
      _objects_type objects;

    GetSignalResponse():
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

    const char * getType(){ return GETSIGNAL; };
    const char * getMD5(){ return "0ca09edef892e41c0efa106b26ce82cc"; };

  };

  class GetSignal {
    public:
    typedef GetSignalRequest Request;
    typedef GetSignalResponse Response;
  };

}
#endif
