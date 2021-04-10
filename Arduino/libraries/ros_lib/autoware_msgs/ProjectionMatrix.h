#ifndef _ROS_autoware_msgs_ProjectionMatrix_h
#define _ROS_autoware_msgs_ProjectionMatrix_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_msgs
{

  class ProjectionMatrix : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      float projection_matrix[16];

    ProjectionMatrix():
      header(),
      projection_matrix()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 16; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->projection_matrix[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 16; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->projection_matrix[i]));
      }
     return offset;
    }

    const char * getType(){ return "autoware_msgs/ProjectionMatrix"; };
    const char * getMD5(){ return "383fdce8566145c0d8ee5731cf4d6531"; };

  };

}
#endif