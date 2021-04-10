#ifndef _ROS_autoware_msgs_ObjLabel_h
#define _ROS_autoware_msgs_ObjLabel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace autoware_msgs
{

  class ObjLabel : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _type_type;
      _type_type type;
      uint32_t obj_id_length;
      typedef int32_t _obj_id_type;
      _obj_id_type st_obj_id;
      _obj_id_type * obj_id;
      uint32_t reprojected_pos_length;
      typedef geometry_msgs::Point _reprojected_pos_type;
      _reprojected_pos_type st_reprojected_pos;
      _reprojected_pos_type * reprojected_pos;

    ObjLabel():
      header(),
      type(""),
      obj_id_length(0), obj_id(NULL),
      reprojected_pos_length(0), reprojected_pos(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      *(outbuffer + offset + 0) = (this->obj_id_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->obj_id_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->obj_id_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->obj_id_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obj_id_length);
      for( uint32_t i = 0; i < obj_id_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_obj_idi;
      u_obj_idi.real = this->obj_id[i];
      *(outbuffer + offset + 0) = (u_obj_idi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_idi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obj_idi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obj_idi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obj_id[i]);
      }
      *(outbuffer + offset + 0) = (this->reprojected_pos_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->reprojected_pos_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->reprojected_pos_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->reprojected_pos_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reprojected_pos_length);
      for( uint32_t i = 0; i < reprojected_pos_length; i++){
      offset += this->reprojected_pos[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      uint32_t obj_id_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      obj_id_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      obj_id_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      obj_id_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->obj_id_length);
      if(obj_id_lengthT > obj_id_length)
        this->obj_id = (int32_t*)realloc(this->obj_id, obj_id_lengthT * sizeof(int32_t));
      obj_id_length = obj_id_lengthT;
      for( uint32_t i = 0; i < obj_id_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_obj_id;
      u_st_obj_id.base = 0;
      u_st_obj_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_obj_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_obj_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_obj_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_obj_id = u_st_obj_id.real;
      offset += sizeof(this->st_obj_id);
        memcpy( &(this->obj_id[i]), &(this->st_obj_id), sizeof(int32_t));
      }
      uint32_t reprojected_pos_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      reprojected_pos_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      reprojected_pos_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      reprojected_pos_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->reprojected_pos_length);
      if(reprojected_pos_lengthT > reprojected_pos_length)
        this->reprojected_pos = (geometry_msgs::Point*)realloc(this->reprojected_pos, reprojected_pos_lengthT * sizeof(geometry_msgs::Point));
      reprojected_pos_length = reprojected_pos_lengthT;
      for( uint32_t i = 0; i < reprojected_pos_length; i++){
      offset += this->st_reprojected_pos.deserialize(inbuffer + offset);
        memcpy( &(this->reprojected_pos[i]), &(this->st_reprojected_pos), sizeof(geometry_msgs::Point));
      }
     return offset;
    }

    const char * getType(){ return "autoware_msgs/ObjLabel"; };
    const char * getMD5(){ return "1908c8a3e1598adc90838e6b6436a771"; };

  };

}
#endif