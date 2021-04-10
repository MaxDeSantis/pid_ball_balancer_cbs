#ifndef _ROS_automotive_navigation_msgs_LaneBoundaryArray_h
#define _ROS_automotive_navigation_msgs_LaneBoundaryArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "automotive_navigation_msgs/LaneBoundary.h"

namespace automotive_navigation_msgs
{

  class LaneBoundaryArray : public ros::Msg
  {
    public:
      uint32_t boundaries_length;
      typedef automotive_navigation_msgs::LaneBoundary _boundaries_type;
      _boundaries_type st_boundaries;
      _boundaries_type * boundaries;

    LaneBoundaryArray():
      boundaries_length(0), boundaries(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->boundaries_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->boundaries_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->boundaries_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->boundaries_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->boundaries_length);
      for( uint32_t i = 0; i < boundaries_length; i++){
      offset += this->boundaries[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t boundaries_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      boundaries_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      boundaries_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      boundaries_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->boundaries_length);
      if(boundaries_lengthT > boundaries_length)
        this->boundaries = (automotive_navigation_msgs::LaneBoundary*)realloc(this->boundaries, boundaries_lengthT * sizeof(automotive_navigation_msgs::LaneBoundary));
      boundaries_length = boundaries_lengthT;
      for( uint32_t i = 0; i < boundaries_length; i++){
      offset += this->st_boundaries.deserialize(inbuffer + offset);
        memcpy( &(this->boundaries[i]), &(this->st_boundaries), sizeof(automotive_navigation_msgs::LaneBoundary));
      }
     return offset;
    }

    const char * getType(){ return "automotive_navigation_msgs/LaneBoundaryArray"; };
    const char * getMD5(){ return "e9f7b0fe081428eb62b95139882c4d89"; };

  };

}
#endif