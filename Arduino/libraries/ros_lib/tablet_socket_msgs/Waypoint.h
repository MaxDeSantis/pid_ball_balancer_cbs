#ifndef _ROS_tablet_socket_msgs_Waypoint_h
#define _ROS_tablet_socket_msgs_Waypoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tablet_socket_msgs
{

  class Waypoint : public ros::Msg
  {
    public:
      typedef float _lat_type;
      _lat_type lat;
      typedef float _lon_type;
      _lon_type lon;

    Waypoint():
      lat(0),
      lon(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->lat);
      offset += serializeAvrFloat64(outbuffer + offset, this->lon);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->lat));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->lon));
     return offset;
    }

    const char * getType(){ return "tablet_socket_msgs/Waypoint"; };
    const char * getMD5(){ return "deb12644498d4b5511a84dbd9af1e283"; };

  };

}
#endif