#ifndef _ROS_autoware_msgs_ObjPose_h
#define _ROS_autoware_msgs_ObjPose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/PoseArray.h"

namespace autoware_msgs
{

  class ObjPose : public ros::Msg
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
      uint32_t obj_length;
      typedef geometry_msgs::PoseArray _obj_type;
      _obj_type st_obj;
      _obj_type * obj;

    ObjPose():
      header(),
      type(""),
      obj_id_length(0), obj_id(NULL),
      obj_length(0), obj(NULL)
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
      *(outbuffer + offset + 0) = (this->obj_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->obj_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->obj_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->obj_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obj_length);
      for( uint32_t i = 0; i < obj_length; i++){
      offset += this->obj[i].serialize(outbuffer + offset);
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
      uint32_t obj_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      obj_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      obj_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      obj_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->obj_length);
      if(obj_lengthT > obj_length)
        this->obj = (geometry_msgs::PoseArray*)realloc(this->obj, obj_lengthT * sizeof(geometry_msgs::PoseArray));
      obj_length = obj_lengthT;
      for( uint32_t i = 0; i < obj_length; i++){
      offset += this->st_obj.deserialize(inbuffer + offset);
        memcpy( &(this->obj[i]), &(this->st_obj), sizeof(geometry_msgs::PoseArray));
      }
     return offset;
    }

    const char * getType(){ return "autoware_msgs/ObjPose"; };
    const char * getMD5(){ return "54a63c36291a0587bc8b4eba25a10459"; };

  };

}
#endif