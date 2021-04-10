#ifndef _ROS_SERVICE_WaypointAdd_h
#define _ROS_SERVICE_WaypointAdd_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"

namespace pathplanning
{

static const char WAYPOINTADD[] = "pathplanning/WaypointAdd";

  class WaypointAddRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose2D _new_waypoint_type;
      _new_waypoint_type new_waypoint;

    WaypointAddRequest():
      new_waypoint()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->new_waypoint.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->new_waypoint.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return WAYPOINTADD; };
    const char * getMD5(){ return "944ed184610f8f16025c4d1ce469ac66"; };

  };

  class WaypointAddResponse : public ros::Msg
  {
    public:

    WaypointAddResponse()
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

    const char * getType(){ return WAYPOINTADD; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class WaypointAdd {
    public:
    typedef WaypointAddRequest Request;
    typedef WaypointAddResponse Response;
  };

}
#endif
