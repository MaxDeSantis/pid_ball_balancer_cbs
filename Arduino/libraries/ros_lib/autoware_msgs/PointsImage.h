#ifndef _ROS_autoware_msgs_PointsImage_h
#define _ROS_autoware_msgs_PointsImage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_msgs
{

  class PointsImage : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t distance_length;
      typedef float _distance_type;
      _distance_type st_distance;
      _distance_type * distance;
      uint32_t intensity_length;
      typedef float _intensity_type;
      _intensity_type st_intensity;
      _intensity_type * intensity;
      uint32_t min_height_length;
      typedef float _min_height_type;
      _min_height_type st_min_height;
      _min_height_type * min_height;
      uint32_t max_height_length;
      typedef float _max_height_type;
      _max_height_type st_max_height;
      _max_height_type * max_height;
      typedef int32_t _max_y_type;
      _max_y_type max_y;
      typedef int32_t _min_y_type;
      _min_y_type min_y;
      typedef int32_t _image_height_type;
      _image_height_type image_height;
      typedef int32_t _image_width_type;
      _image_width_type image_width;

    PointsImage():
      header(),
      distance_length(0), distance(NULL),
      intensity_length(0), intensity(NULL),
      min_height_length(0), min_height(NULL),
      max_height_length(0), max_height(NULL),
      max_y(0),
      min_y(0),
      image_height(0),
      image_width(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->distance_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->distance_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->distance_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->distance_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance_length);
      for( uint32_t i = 0; i < distance_length; i++){
      union {
        float real;
        uint32_t base;
      } u_distancei;
      u_distancei.real = this->distance[i];
      *(outbuffer + offset + 0) = (u_distancei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distancei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distancei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distancei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance[i]);
      }
      *(outbuffer + offset + 0) = (this->intensity_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->intensity_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->intensity_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->intensity_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->intensity_length);
      for( uint32_t i = 0; i < intensity_length; i++){
      union {
        float real;
        uint32_t base;
      } u_intensityi;
      u_intensityi.real = this->intensity[i];
      *(outbuffer + offset + 0) = (u_intensityi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_intensityi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_intensityi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_intensityi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->intensity[i]);
      }
      *(outbuffer + offset + 0) = (this->min_height_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->min_height_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->min_height_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->min_height_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_height_length);
      for( uint32_t i = 0; i < min_height_length; i++){
      union {
        float real;
        uint32_t base;
      } u_min_heighti;
      u_min_heighti.real = this->min_height[i];
      *(outbuffer + offset + 0) = (u_min_heighti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_heighti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_heighti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_heighti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_height[i]);
      }
      *(outbuffer + offset + 0) = (this->max_height_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->max_height_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->max_height_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->max_height_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_height_length);
      for( uint32_t i = 0; i < max_height_length; i++){
      union {
        float real;
        uint32_t base;
      } u_max_heighti;
      u_max_heighti.real = this->max_height[i];
      *(outbuffer + offset + 0) = (u_max_heighti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_heighti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_heighti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_heighti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_height[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_max_y;
      u_max_y.real = this->max_y;
      *(outbuffer + offset + 0) = (u_max_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_y);
      union {
        int32_t real;
        uint32_t base;
      } u_min_y;
      u_min_y.real = this->min_y;
      *(outbuffer + offset + 0) = (u_min_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_y);
      union {
        int32_t real;
        uint32_t base;
      } u_image_height;
      u_image_height.real = this->image_height;
      *(outbuffer + offset + 0) = (u_image_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_image_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_image_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_image_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->image_height);
      union {
        int32_t real;
        uint32_t base;
      } u_image_width;
      u_image_width.real = this->image_width;
      *(outbuffer + offset + 0) = (u_image_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_image_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_image_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_image_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->image_width);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t distance_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      distance_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      distance_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      distance_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->distance_length);
      if(distance_lengthT > distance_length)
        this->distance = (float*)realloc(this->distance, distance_lengthT * sizeof(float));
      distance_length = distance_lengthT;
      for( uint32_t i = 0; i < distance_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_distance;
      u_st_distance.base = 0;
      u_st_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_distance = u_st_distance.real;
      offset += sizeof(this->st_distance);
        memcpy( &(this->distance[i]), &(this->st_distance), sizeof(float));
      }
      uint32_t intensity_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      intensity_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      intensity_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      intensity_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->intensity_length);
      if(intensity_lengthT > intensity_length)
        this->intensity = (float*)realloc(this->intensity, intensity_lengthT * sizeof(float));
      intensity_length = intensity_lengthT;
      for( uint32_t i = 0; i < intensity_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_intensity;
      u_st_intensity.base = 0;
      u_st_intensity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_intensity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_intensity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_intensity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_intensity = u_st_intensity.real;
      offset += sizeof(this->st_intensity);
        memcpy( &(this->intensity[i]), &(this->st_intensity), sizeof(float));
      }
      uint32_t min_height_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      min_height_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      min_height_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      min_height_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->min_height_length);
      if(min_height_lengthT > min_height_length)
        this->min_height = (float*)realloc(this->min_height, min_height_lengthT * sizeof(float));
      min_height_length = min_height_lengthT;
      for( uint32_t i = 0; i < min_height_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_min_height;
      u_st_min_height.base = 0;
      u_st_min_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_min_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_min_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_min_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_min_height = u_st_min_height.real;
      offset += sizeof(this->st_min_height);
        memcpy( &(this->min_height[i]), &(this->st_min_height), sizeof(float));
      }
      uint32_t max_height_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      max_height_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      max_height_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      max_height_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->max_height_length);
      if(max_height_lengthT > max_height_length)
        this->max_height = (float*)realloc(this->max_height, max_height_lengthT * sizeof(float));
      max_height_length = max_height_lengthT;
      for( uint32_t i = 0; i < max_height_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_max_height;
      u_st_max_height.base = 0;
      u_st_max_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_max_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_max_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_max_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_max_height = u_st_max_height.real;
      offset += sizeof(this->st_max_height);
        memcpy( &(this->max_height[i]), &(this->st_max_height), sizeof(float));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_max_y;
      u_max_y.base = 0;
      u_max_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_y = u_max_y.real;
      offset += sizeof(this->max_y);
      union {
        int32_t real;
        uint32_t base;
      } u_min_y;
      u_min_y.base = 0;
      u_min_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_y = u_min_y.real;
      offset += sizeof(this->min_y);
      union {
        int32_t real;
        uint32_t base;
      } u_image_height;
      u_image_height.base = 0;
      u_image_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_image_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_image_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_image_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->image_height = u_image_height.real;
      offset += sizeof(this->image_height);
      union {
        int32_t real;
        uint32_t base;
      } u_image_width;
      u_image_width.base = 0;
      u_image_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_image_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_image_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_image_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->image_width = u_image_width.real;
      offset += sizeof(this->image_width);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/PointsImage"; };
    const char * getMD5(){ return "15d4a81152c2787f78cf14a957d8135e"; };

  };

}
#endif