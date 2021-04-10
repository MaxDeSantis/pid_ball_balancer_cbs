#ifndef _ROS_pointcloud2_to_points_OccGrid_h
#define _ROS_pointcloud2_to_points_OccGrid_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pointcloud2_to_points/BoolArray.h"

namespace pointcloud2_to_points
{

  class OccGrid : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _size_type;
      _size_type size;
      typedef int32_t _total_points_type;
      _total_points_type total_points;
      typedef float _resolution_type;
      _resolution_type resolution;
      uint32_t data_length;
      typedef pointcloud2_to_points::BoolArray _data_type;
      _data_type st_data;
      _data_type * data;

    OccGrid():
      header(),
      size(0),
      total_points(0),
      resolution(0),
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->size >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->size >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->size >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->size >> (8 * 3)) & 0xFF;
      offset += sizeof(this->size);
      union {
        int32_t real;
        uint32_t base;
      } u_total_points;
      u_total_points.real = this->total_points;
      *(outbuffer + offset + 0) = (u_total_points.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_total_points.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_total_points.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_total_points.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->total_points);
      union {
        float real;
        uint32_t base;
      } u_resolution;
      u_resolution.real = this->resolution;
      *(outbuffer + offset + 0) = (u_resolution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_resolution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_resolution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_resolution.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->resolution);
      *(outbuffer + offset + 0) = (this->data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_length);
      for( uint32_t i = 0; i < data_length; i++){
      offset += this->data[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->size =  ((uint32_t) (*(inbuffer + offset)));
      this->size |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->size |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->size |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->size);
      union {
        int32_t real;
        uint32_t base;
      } u_total_points;
      u_total_points.base = 0;
      u_total_points.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_total_points.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_total_points.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_total_points.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->total_points = u_total_points.real;
      offset += sizeof(this->total_points);
      union {
        float real;
        uint32_t base;
      } u_resolution;
      u_resolution.base = 0;
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->resolution = u_resolution.real;
      offset += sizeof(this->resolution);
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (pointcloud2_to_points::BoolArray*)realloc(this->data, data_lengthT * sizeof(pointcloud2_to_points::BoolArray));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++){
      offset += this->st_data.deserialize(inbuffer + offset);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(pointcloud2_to_points::BoolArray));
      }
     return offset;
    }

    const char * getType(){ return "pointcloud2_to_points/OccGrid"; };
    const char * getMD5(){ return "22abcd65316a984d2055619b21bdf8db"; };

  };

}
#endif