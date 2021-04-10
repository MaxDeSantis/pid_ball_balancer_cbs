#ifndef _ROS_tablet_socket_msgs_route_cmd_h
#define _ROS_tablet_socket_msgs_route_cmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "tablet_socket_msgs/Waypoint.h"

namespace tablet_socket_msgs
{

  class route_cmd : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t point_length;
      typedef tablet_socket_msgs::Waypoint _point_type;
      _point_type st_point;
      _point_type * point;

    route_cmd():
      header(),
      point_length(0), point(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->point_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_length);
      for( uint32_t i = 0; i < point_length; i++){
      offset += this->point[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t point_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      point_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      point_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      point_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->point_length);
      if(point_lengthT > point_length)
        this->point = (tablet_socket_msgs::Waypoint*)realloc(this->point, point_lengthT * sizeof(tablet_socket_msgs::Waypoint));
      point_length = point_lengthT;
      for( uint32_t i = 0; i < point_length; i++){
      offset += this->st_point.deserialize(inbuffer + offset);
        memcpy( &(this->point[i]), &(this->st_point), sizeof(tablet_socket_msgs::Waypoint));
      }
     return offset;
    }

    const char * getType(){ return "tablet_socket_msgs/route_cmd"; };
    const char * getMD5(){ return "dc6ab221b6d4ddaf64a9f5fb63329e75"; };

  };

}
#endif