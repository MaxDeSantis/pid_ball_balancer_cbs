#ifndef _ROS_SERVICE_GetDTLane_h
#define _ROS_SERVICE_GetDTLane_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "vector_map_msgs/DTLaneArray.h"
#include "geometry_msgs/PoseStamped.h"
#include "autoware_msgs/Lane.h"

namespace vector_map_server
{

static const char GETDTLANE[] = "vector_map_server/GetDTLane";

  class GetDTLaneRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _pose_type;
      _pose_type pose;
      typedef autoware_msgs::Lane _waypoints_type;
      _waypoints_type waypoints;

    GetDTLaneRequest():
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

    const char * getType(){ return GETDTLANE; };
    const char * getMD5(){ return "d1f64bdec952e41012fc8c13f57fef77"; };

  };

  class GetDTLaneResponse : public ros::Msg
  {
    public:
      typedef vector_map_msgs::DTLaneArray _objects_type;
      _objects_type objects;

    GetDTLaneResponse():
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

    const char * getType(){ return GETDTLANE; };
    const char * getMD5(){ return "d8d90427357d4b8c8ade256226853bb6"; };

  };

  class GetDTLane {
    public:
    typedef GetDTLaneRequest Request;
    typedef GetDTLaneResponse Response;
  };

}
#endif
