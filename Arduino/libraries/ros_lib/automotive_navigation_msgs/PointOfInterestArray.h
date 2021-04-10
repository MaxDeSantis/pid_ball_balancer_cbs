#ifndef _ROS_automotive_navigation_msgs_PointOfInterestArray_h
#define _ROS_automotive_navigation_msgs_PointOfInterestArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "automotive_navigation_msgs/PointOfInterest.h"

namespace automotive_navigation_msgs
{

  class PointOfInterestArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint16_t _update_num_type;
      _update_num_type update_num;
      uint32_t point_list_length;
      typedef automotive_navigation_msgs::PointOfInterest _point_list_type;
      _point_list_type st_point_list;
      _point_list_type * point_list;

    PointOfInterestArray():
      header(),
      update_num(0),
      point_list_length(0), point_list(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->update_num >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->update_num >> (8 * 1)) & 0xFF;
      offset += sizeof(this->update_num);
      *(outbuffer + offset + 0) = (this->point_list_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_list_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_list_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_list_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_list_length);
      for( uint32_t i = 0; i < point_list_length; i++){
      offset += this->point_list[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->update_num =  ((uint16_t) (*(inbuffer + offset)));
      this->update_num |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->update_num);
      uint32_t point_list_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      point_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      point_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      point_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->point_list_length);
      if(point_list_lengthT > point_list_length)
        this->point_list = (automotive_navigation_msgs::PointOfInterest*)realloc(this->point_list, point_list_lengthT * sizeof(automotive_navigation_msgs::PointOfInterest));
      point_list_length = point_list_lengthT;
      for( uint32_t i = 0; i < point_list_length; i++){
      offset += this->st_point_list.deserialize(inbuffer + offset);
        memcpy( &(this->point_list[i]), &(this->st_point_list), sizeof(automotive_navigation_msgs::PointOfInterest));
      }
     return offset;
    }

    const char * getType(){ return "automotive_navigation_msgs/PointOfInterestArray"; };
    const char * getMD5(){ return "23d123c6723540d685425f0f725601ab"; };

  };

}
#endif