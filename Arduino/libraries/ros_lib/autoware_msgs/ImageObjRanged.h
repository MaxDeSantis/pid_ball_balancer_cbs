#ifndef _ROS_autoware_msgs_ImageObjRanged_h
#define _ROS_autoware_msgs_ImageObjRanged_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_msgs/ImageRectRanged.h"

namespace autoware_msgs
{

  class ImageObjRanged : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _type_type;
      _type_type type;
      uint32_t obj_length;
      typedef autoware_msgs::ImageRectRanged _obj_type;
      _obj_type st_obj;
      _obj_type * obj;

    ImageObjRanged():
      header(),
      type(""),
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
      uint32_t obj_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      obj_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      obj_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      obj_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->obj_length);
      if(obj_lengthT > obj_length)
        this->obj = (autoware_msgs::ImageRectRanged*)realloc(this->obj, obj_lengthT * sizeof(autoware_msgs::ImageRectRanged));
      obj_length = obj_lengthT;
      for( uint32_t i = 0; i < obj_length; i++){
      offset += this->st_obj.deserialize(inbuffer + offset);
        memcpy( &(this->obj[i]), &(this->st_obj), sizeof(autoware_msgs::ImageRectRanged));
      }
     return offset;
    }

    const char * getType(){ return "autoware_msgs/ImageObjRanged"; };
    const char * getMD5(){ return "165d0348acd5a3d4df2930a42768b95f"; };

  };

}
#endif