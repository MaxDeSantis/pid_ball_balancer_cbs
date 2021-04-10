#ifndef _ROS_SERVICE_WaypointRestart_h
#define _ROS_SERVICE_WaypointRestart_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pathplanning
{

static const char WAYPOINTRESTART[] = "pathplanning/WaypointRestart";

  class WaypointRestartRequest : public ros::Msg
  {
    public:

    WaypointRestartRequest()
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

    const char * getType(){ return WAYPOINTRESTART; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class WaypointRestartResponse : public ros::Msg
  {
    public:

    WaypointRestartResponse()
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

    const char * getType(){ return WAYPOINTRESTART; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class WaypointRestart {
    public:
    typedef WaypointRestartRequest Request;
    typedef WaypointRestartResponse Response;
  };

}
#endif
