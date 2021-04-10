#ifndef _ROS_autoware_msgs_ScanImage_h
#define _ROS_autoware_msgs_ScanImage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_msgs
{

  class ScanImage : public ros::Msg
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
      typedef int32_t _max_y_type;
      _max_y_type max_y;
      typedef int32_t _min_y_type;
      _min_y_type min_y;

    ScanImage():
      header(),
      distance_length(0), distance(NULL),
      intensity_length(0), intensity(NULL),
      max_y(0),
      min_y(0)
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
     return offset;
    }

    const char * getType(){ return "autoware_msgs/ScanImage"; };
    const char * getMD5(){ return "d3276ec225af95b58af799f4633b1f5d"; };

  };

}
#endif