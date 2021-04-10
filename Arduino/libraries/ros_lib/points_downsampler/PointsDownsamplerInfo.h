#ifndef _ROS_points_downsampler_PointsDownsamplerInfo_h
#define _ROS_points_downsampler_PointsDownsamplerInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace points_downsampler
{

  class PointsDownsamplerInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _filter_name_type;
      _filter_name_type filter_name;
      typedef float _measurement_range_type;
      _measurement_range_type measurement_range;
      typedef int32_t _original_points_size_type;
      _original_points_size_type original_points_size;
      typedef int32_t _filtered_points_size_type;
      _filtered_points_size_type filtered_points_size;
      typedef int32_t _original_ring_size_type;
      _original_ring_size_type original_ring_size;
      typedef int32_t _filtered_ring_size_type;
      _filtered_ring_size_type filtered_ring_size;
      typedef float _exe_time_type;
      _exe_time_type exe_time;

    PointsDownsamplerInfo():
      header(),
      filter_name(""),
      measurement_range(0),
      original_points_size(0),
      filtered_points_size(0),
      original_ring_size(0),
      filtered_ring_size(0),
      exe_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_filter_name = strlen(this->filter_name);
      varToArr(outbuffer + offset, length_filter_name);
      offset += 4;
      memcpy(outbuffer + offset, this->filter_name, length_filter_name);
      offset += length_filter_name;
      union {
        float real;
        uint32_t base;
      } u_measurement_range;
      u_measurement_range.real = this->measurement_range;
      *(outbuffer + offset + 0) = (u_measurement_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_measurement_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_measurement_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_measurement_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->measurement_range);
      union {
        int32_t real;
        uint32_t base;
      } u_original_points_size;
      u_original_points_size.real = this->original_points_size;
      *(outbuffer + offset + 0) = (u_original_points_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_original_points_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_original_points_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_original_points_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->original_points_size);
      union {
        int32_t real;
        uint32_t base;
      } u_filtered_points_size;
      u_filtered_points_size.real = this->filtered_points_size;
      *(outbuffer + offset + 0) = (u_filtered_points_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_points_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_points_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_points_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->filtered_points_size);
      union {
        int32_t real;
        uint32_t base;
      } u_original_ring_size;
      u_original_ring_size.real = this->original_ring_size;
      *(outbuffer + offset + 0) = (u_original_ring_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_original_ring_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_original_ring_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_original_ring_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->original_ring_size);
      union {
        int32_t real;
        uint32_t base;
      } u_filtered_ring_size;
      u_filtered_ring_size.real = this->filtered_ring_size;
      *(outbuffer + offset + 0) = (u_filtered_ring_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_ring_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_ring_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_ring_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->filtered_ring_size);
      union {
        float real;
        uint32_t base;
      } u_exe_time;
      u_exe_time.real = this->exe_time;
      *(outbuffer + offset + 0) = (u_exe_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_exe_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_exe_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_exe_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->exe_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_filter_name;
      arrToVar(length_filter_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_filter_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_filter_name-1]=0;
      this->filter_name = (char *)(inbuffer + offset-1);
      offset += length_filter_name;
      union {
        float real;
        uint32_t base;
      } u_measurement_range;
      u_measurement_range.base = 0;
      u_measurement_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_measurement_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_measurement_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_measurement_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->measurement_range = u_measurement_range.real;
      offset += sizeof(this->measurement_range);
      union {
        int32_t real;
        uint32_t base;
      } u_original_points_size;
      u_original_points_size.base = 0;
      u_original_points_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_original_points_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_original_points_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_original_points_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->original_points_size = u_original_points_size.real;
      offset += sizeof(this->original_points_size);
      union {
        int32_t real;
        uint32_t base;
      } u_filtered_points_size;
      u_filtered_points_size.base = 0;
      u_filtered_points_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_points_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_points_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_points_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->filtered_points_size = u_filtered_points_size.real;
      offset += sizeof(this->filtered_points_size);
      union {
        int32_t real;
        uint32_t base;
      } u_original_ring_size;
      u_original_ring_size.base = 0;
      u_original_ring_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_original_ring_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_original_ring_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_original_ring_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->original_ring_size = u_original_ring_size.real;
      offset += sizeof(this->original_ring_size);
      union {
        int32_t real;
        uint32_t base;
      } u_filtered_ring_size;
      u_filtered_ring_size.base = 0;
      u_filtered_ring_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_ring_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_ring_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_ring_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->filtered_ring_size = u_filtered_ring_size.real;
      offset += sizeof(this->filtered_ring_size);
      union {
        float real;
        uint32_t base;
      } u_exe_time;
      u_exe_time.base = 0;
      u_exe_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_exe_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_exe_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_exe_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->exe_time = u_exe_time.real;
      offset += sizeof(this->exe_time);
     return offset;
    }

    const char * getType(){ return "points_downsampler/PointsDownsamplerInfo"; };
    const char * getMD5(){ return "a6fc8411fcff551ab66c7910e08a8d14"; };

  };

}
#endif