#ifndef _ROS_SERVICE_WaypointRequest_h
#define _ROS_SERVICE_WaypointRequest_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"
#include "std_msgs/Bool.h"

namespace pathplanning
{

static const char WAYPOINTREQUEST[] = "pathplanning/WaypointRequest";

  class WaypointRequestRequest : public ros::Msg
  {
    public:

    WaypointRequestRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return WAYPOINTREQUEST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class WaypointRequestResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose2D _waypoint_type;
      _waypoint_type waypoint;
      typedef std_msgs::Bool _finished_type;
      _finished_type finished;

    WaypointRequestResponse():
      waypoint(),
      finished()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->waypoint.serialize(outbuffer + offset);
      offset += this->finished.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->waypoint.deserialize(inbuffer + offset);
      offset += this->finished.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return WAYPOINTREQUEST; };
    const char * getMD5(){ return "7fe680a570dcfc41f78f8601ab5da97f"; };

  };

  class WaypointRequest {
    public:
    typedef WaypointRequestRequest Request;
    typedef WaypointRequestResponse Response;
  };

}
#endif
