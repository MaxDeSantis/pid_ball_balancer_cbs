#ifndef _ROS_SERVICE_GetWayArea_h
#define _ROS_SERVICE_GetWayArea_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "autoware_msgs/Lane.h"
#include "vector_map_msgs/WayAreaArray.h"

namespace vector_map_server
{

static const char GETWAYAREA[] = "vector_map_server/GetWayArea";

  class GetWayAreaRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _pose_type;
      _pose_type pose;
      typedef autoware_msgs::Lane _waypoints_type;
      _waypoints_type waypoints;

    GetWayAreaRequest():
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

    const char * getType(){ return GETWAYAREA; };
    const char * getMD5(){ return "d1f64bdec952e41012fc8c13f57fef77"; };

  };

  class GetWayAreaResponse : public ros::Msg
  {
    public:
      typedef vector_map_msgs::WayAreaArray _objects_type;
      _objects_type objects;

    GetWayAreaResponse():
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

    const char * getType(){ return GETWAYAREA; };
    const char * getMD5(){ return "5f38f4a841033375db12c79fae0e32bb"; };

  };

  class GetWayArea {
    public:
    typedef GetWayAreaRequest Request;
    typedef GetWayAreaResponse Response;
  };

}
#endif
