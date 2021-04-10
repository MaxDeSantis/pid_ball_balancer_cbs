#ifndef _ROS_automotive_navigation_msgs_RoadNetworkBoundaries_h
#define _ROS_automotive_navigation_msgs_RoadNetworkBoundaries_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "automotive_navigation_msgs/LaneBoundaryArray.h"

namespace automotive_navigation_msgs
{

  class RoadNetworkBoundaries : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t road_network_boundaries_length;
      typedef automotive_navigation_msgs::LaneBoundaryArray _road_network_boundaries_type;
      _road_network_boundaries_type st_road_network_boundaries;
      _road_network_boundaries_type * road_network_boundaries;

    RoadNetworkBoundaries():
      header(),
      road_network_boundaries_length(0), road_network_boundaries(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->road_network_boundaries_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->road_network_boundaries_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->road_network_boundaries_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->road_network_boundaries_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->road_network_boundaries_length);
      for( uint32_t i = 0; i < road_network_boundaries_length; i++){
      offset += this->road_network_boundaries[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t road_network_boundaries_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      road_network_boundaries_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      road_network_boundaries_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      road_network_boundaries_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->road_network_boundaries_length);
      if(road_network_boundaries_lengthT > road_network_boundaries_length)
        this->road_network_boundaries = (automotive_navigation_msgs::LaneBoundaryArray*)realloc(this->road_network_boundaries, road_network_boundaries_lengthT * sizeof(automotive_navigation_msgs::LaneBoundaryArray));
      road_network_boundaries_length = road_network_boundaries_lengthT;
      for( uint32_t i = 0; i < road_network_boundaries_length; i++){
      offset += this->st_road_network_boundaries.deserialize(inbuffer + offset);
        memcpy( &(this->road_network_boundaries[i]), &(this->st_road_network_boundaries), sizeof(automotive_navigation_msgs::LaneBoundaryArray));
      }
     return offset;
    }

    const char * getType(){ return "automotive_navigation_msgs/RoadNetworkBoundaries"; };
    const char * getMD5(){ return "1401bcf0d0f7367848bb50e6ad210a4b"; };

  };

}
#endif