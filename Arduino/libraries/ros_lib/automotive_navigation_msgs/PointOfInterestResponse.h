#ifndef _ROS_automotive_navigation_msgs_PointOfInterestResponse_h
#define _ROS_automotive_navigation_msgs_PointOfInterestResponse_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "automotive_navigation_msgs/PointOfInterestStatus.h"

namespace automotive_navigation_msgs
{

  class PointOfInterestResponse : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _module_name_type;
      _module_name_type module_name;
      typedef uint16_t _request_id_type;
      _request_id_type request_id;
      typedef uint16_t _update_num_type;
      _update_num_type update_num;
      uint32_t point_statuses_length;
      typedef automotive_navigation_msgs::PointOfInterestStatus _point_statuses_type;
      _point_statuses_type st_point_statuses;
      _point_statuses_type * point_statuses;

    PointOfInterestResponse():
      header(),
      name(""),
      module_name(""),
      request_id(0),
      update_num(0),
      point_statuses_length(0), point_statuses(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_module_name = strlen(this->module_name);
      varToArr(outbuffer + offset, length_module_name);
      offset += 4;
      memcpy(outbuffer + offset, this->module_name, length_module_name);
      offset += length_module_name;
      *(outbuffer + offset + 0) = (this->request_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->request_id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->request_id);
      *(outbuffer + offset + 0) = (this->update_num >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->update_num >> (8 * 1)) & 0xFF;
      offset += sizeof(this->update_num);
      *(outbuffer + offset + 0) = (this->point_statuses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_statuses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_statuses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_statuses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_statuses_length);
      for( uint32_t i = 0; i < point_statuses_length; i++){
      offset += this->point_statuses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_module_name;
      arrToVar(length_module_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_module_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_module_name-1]=0;
      this->module_name = (char *)(inbuffer + offset-1);
      offset += length_module_name;
      this->request_id =  ((uint16_t) (*(inbuffer + offset)));
      this->request_id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->request_id);
      this->update_num =  ((uint16_t) (*(inbuffer + offset)));
      this->update_num |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->update_num);
      uint32_t point_statuses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      point_statuses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      point_statuses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      point_statuses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->point_statuses_length);
      if(point_statuses_lengthT > point_statuses_length)
        this->point_statuses = (automotive_navigation_msgs::PointOfInterestStatus*)realloc(this->point_statuses, point_statuses_lengthT * sizeof(automotive_navigation_msgs::PointOfInterestStatus));
      point_statuses_length = point_statuses_lengthT;
      for( uint32_t i = 0; i < point_statuses_length; i++){
      offset += this->st_point_statuses.deserialize(inbuffer + offset);
        memcpy( &(this->point_statuses[i]), &(this->st_point_statuses), sizeof(automotive_navigation_msgs::PointOfInterestStatus));
      }
     return offset;
    }

    const char * getType(){ return "automotive_navigation_msgs/PointOfInterestResponse"; };
    const char * getMD5(){ return "a741652f87aad929f0e8ded823bc5c90"; };

  };

}
#endif