#ifndef _ROS_autoware_msgs_ImageObjTracked_h
#define _ROS_autoware_msgs_ImageObjTracked_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_msgs/ImageRectRanged.h"

namespace autoware_msgs
{

  class ImageObjTracked : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _type_type;
      _type_type type;
      typedef uint8_t _total_num_type;
      _total_num_type total_num;
      uint32_t obj_id_length;
      typedef int32_t _obj_id_type;
      _obj_id_type st_obj_id;
      _obj_id_type * obj_id;
      uint32_t rect_ranged_length;
      typedef autoware_msgs::ImageRectRanged _rect_ranged_type;
      _rect_ranged_type st_rect_ranged;
      _rect_ranged_type * rect_ranged;
      uint32_t real_data_length;
      typedef int32_t _real_data_type;
      _real_data_type st_real_data;
      _real_data_type * real_data;
      uint32_t lifespan_length;
      typedef int32_t _lifespan_type;
      _lifespan_type st_lifespan;
      _lifespan_type * lifespan;

    ImageObjTracked():
      header(),
      type(""),
      total_num(0),
      obj_id_length(0), obj_id(NULL),
      rect_ranged_length(0), rect_ranged(NULL),
      real_data_length(0), real_data(NULL),
      lifespan_length(0), lifespan(NULL)
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
      *(outbuffer + offset + 0) = (this->total_num >> (8 * 0)) & 0xFF;
      offset += sizeof(this->total_num);
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
      *(outbuffer + offset + 0) = (this->rect_ranged_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rect_ranged_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rect_ranged_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rect_ranged_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rect_ranged_length);
      for( uint32_t i = 0; i < rect_ranged_length; i++){
      offset += this->rect_ranged[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->real_data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->real_data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->real_data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->real_data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->real_data_length);
      for( uint32_t i = 0; i < real_data_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_real_datai;
      u_real_datai.real = this->real_data[i];
      *(outbuffer + offset + 0) = (u_real_datai.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_real_datai.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_real_datai.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_real_datai.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->real_data[i]);
      }
      *(outbuffer + offset + 0) = (this->lifespan_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lifespan_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lifespan_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lifespan_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lifespan_length);
      for( uint32_t i = 0; i < lifespan_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_lifespani;
      u_lifespani.real = this->lifespan[i];
      *(outbuffer + offset + 0) = (u_lifespani.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lifespani.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lifespani.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lifespani.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lifespan[i]);
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
      this->total_num =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->total_num);
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
      uint32_t rect_ranged_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      rect_ranged_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      rect_ranged_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      rect_ranged_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->rect_ranged_length);
      if(rect_ranged_lengthT > rect_ranged_length)
        this->rect_ranged = (autoware_msgs::ImageRectRanged*)realloc(this->rect_ranged, rect_ranged_lengthT * sizeof(autoware_msgs::ImageRectRanged));
      rect_ranged_length = rect_ranged_lengthT;
      for( uint32_t i = 0; i < rect_ranged_length; i++){
      offset += this->st_rect_ranged.deserialize(inbuffer + offset);
        memcpy( &(this->rect_ranged[i]), &(this->st_rect_ranged), sizeof(autoware_msgs::ImageRectRanged));
      }
      uint32_t real_data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      real_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      real_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      real_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->real_data_length);
      if(real_data_lengthT > real_data_length)
        this->real_data = (int32_t*)realloc(this->real_data, real_data_lengthT * sizeof(int32_t));
      real_data_length = real_data_lengthT;
      for( uint32_t i = 0; i < real_data_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_real_data;
      u_st_real_data.base = 0;
      u_st_real_data.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_real_data.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_real_data.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_real_data.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_real_data = u_st_real_data.real;
      offset += sizeof(this->st_real_data);
        memcpy( &(this->real_data[i]), &(this->st_real_data), sizeof(int32_t));
      }
      uint32_t lifespan_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      lifespan_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      lifespan_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      lifespan_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->lifespan_length);
      if(lifespan_lengthT > lifespan_length)
        this->lifespan = (int32_t*)realloc(this->lifespan, lifespan_lengthT * sizeof(int32_t));
      lifespan_length = lifespan_lengthT;
      for( uint32_t i = 0; i < lifespan_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_lifespan;
      u_st_lifespan.base = 0;
      u_st_lifespan.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_lifespan.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_lifespan.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_lifespan.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_lifespan = u_st_lifespan.real;
      offset += sizeof(this->st_lifespan);
        memcpy( &(this->lifespan[i]), &(this->st_lifespan), sizeof(int32_t));
      }
     return offset;
    }

    const char * getType(){ return "autoware_msgs/ImageObjTracked"; };
    const char * getMD5(){ return "6f3751f77b67bc47fba29cbdd3ea3d56"; };

  };

}
#endif