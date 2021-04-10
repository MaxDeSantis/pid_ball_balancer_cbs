#ifndef _ROS_lgsvl_msgs_BoundingBox3D_h
#define _ROS_lgsvl_msgs_BoundingBox3D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Vector3.h"

namespace lgsvl_msgs
{

  class BoundingBox3D : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _position_type;
      _position_type position;
      typedef geometry_msgs::Vector3 _size_type;
      _size_type size;

    BoundingBox3D():
      position(),
      size()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->position.serialize(outbuffer + offset);
      offset += this->size.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->size.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "lgsvl_msgs/BoundingBox3D"; };
    const char * getMD5(){ return "0afc39928ba33aad299a6acabb48fd7d"; };

  };

}
#endif