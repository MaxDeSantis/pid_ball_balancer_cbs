#ifndef _ROS_autoware_msgs_LaneArray_h
#define _ROS_autoware_msgs_LaneArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autoware_msgs/Lane.h"

namespace autoware_msgs
{

  class LaneArray : public ros::Msg
  {
    public:
      typedef int32_t _id_type;
      _id_type id;
      uint32_t lanes_length;
      typedef autoware_msgs::Lane _lanes_type;
      _lanes_type st_lanes;
      _lanes_type * lanes;

    LaneArray():
      id(0),
      lanes_length(0), lanes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->lanes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lanes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lanes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lanes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lanes_length);
      for( uint32_t i = 0; i < lanes_length; i++){
      offset += this->lanes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
      uint32_t lanes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      lanes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      lanes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      lanes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->lanes_length);
      if(lanes_lengthT > lanes_length)
        this->lanes = (autoware_msgs::Lane*)realloc(this->lanes, lanes_lengthT * sizeof(autoware_msgs::Lane));
      lanes_length = lanes_lengthT;
      for( uint32_t i = 0; i < lanes_length; i++){
      offset += this->st_lanes.deserialize(inbuffer + offset);
        memcpy( &(this->lanes[i]), &(this->st_lanes), sizeof(autoware_msgs::Lane));
      }
     return offset;
    }

    const char * getType(){ return "autoware_msgs/LaneArray"; };
    const char * getMD5(){ return "23abb100bdfa4ee58530bb628c974c2a"; };

  };

}
#endif