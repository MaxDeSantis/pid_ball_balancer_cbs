#ifndef _ROS_SERVICE_WaypointClear_h
#define _ROS_SERVICE_WaypointClear_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pathplanning
{

static const char WAYPOINTCLEAR[] = "pathplanning/WaypointClear";

  class WaypointClearRequest : public ros::Msg
  {
    public:

    WaypointClearRequest()
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

    const char * getType(){ return WAYPOINTCLEAR; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class WaypointClearResponse : public ros::Msg
  {
    public:

    WaypointClearResponse()
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

    const char * getType(){ return WAYPOINTCLEAR; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class WaypointClear {
    public:
    typedef WaypointClearRequest Request;
    typedef WaypointClearResponse Response;
  };

}
#endif
