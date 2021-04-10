#ifndef _ROS_autoware_config_msgs_ConfigRingGroundFilter_h
#define _ROS_autoware_config_msgs_ConfigRingGroundFilter_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_config_msgs
{

  class ConfigRingGroundFilter : public ros::Msg
  {
    public:
      typedef const char* _sensor_model_type;
      _sensor_model_type sensor_model;
      typedef float _sensor_height_type;
      _sensor_height_type sensor_height;
      typedef float _max_slope_type;
      _max_slope_type max_slope;
      typedef float _vertical_thres_type;
      _vertical_thres_type vertical_thres;

    ConfigRingGroundFilter():
      sensor_model(""),
      sensor_height(0),
      max_slope(0),
      vertical_thres(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_sensor_model = strlen(this->sensor_model);
      varToArr(outbuffer + offset, length_sensor_model);
      offset += 4;
      memcpy(outbuffer + offset, this->sensor_model, length_sensor_model);
      offset += length_sensor_model;
      union {
        float real;
        uint32_t base;
      } u_sensor_height;
      u_sensor_height.real = this->sensor_height;
      *(outbuffer + offset + 0) = (u_sensor_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sensor_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sensor_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sensor_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sensor_height);
      union {
        float real;
        uint32_t base;
      } u_max_slope;
      u_max_slope.real = this->max_slope;
      *(outbuffer + offset + 0) = (u_max_slope.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_slope.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_slope.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_slope.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_slope);
      union {
        float real;
        uint32_t base;
      } u_vertical_thres;
      u_vertical_thres.real = this->vertical_thres;
      *(outbuffer + offset + 0) = (u_vertical_thres.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vertical_thres.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vertical_thres.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vertical_thres.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vertical_thres);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_sensor_model;
      arrToVar(length_sensor_model, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sensor_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sensor_model-1]=0;
      this->sensor_model = (char *)(inbuffer + offset-1);
      offset += length_sensor_model;
      union {
        float real;
        uint32_t base;
      } u_sensor_height;
      u_sensor_height.base = 0;
      u_sensor_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sensor_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sensor_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sensor_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sensor_height = u_sensor_height.real;
      offset += sizeof(this->sensor_height);
      union {
        float real;
        uint32_t base;
      } u_max_slope;
      u_max_slope.base = 0;
      u_max_slope.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_slope.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_slope.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_slope.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_slope = u_max_slope.real;
      offset += sizeof(this->max_slope);
      union {
        float real;
        uint32_t base;
      } u_vertical_thres;
      u_vertical_thres.base = 0;
      u_vertical_thres.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vertical_thres.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vertical_thres.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vertical_thres.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vertical_thres = u_vertical_thres.real;
      offset += sizeof(this->vertical_thres);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigRingGroundFilter"; };
    const char * getMD5(){ return "35af9608c7f7db50fdce10fd09cce39f"; };

  };

}
#endif