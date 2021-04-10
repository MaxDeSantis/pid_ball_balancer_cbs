#ifndef _ROS_automotive_platform_msgs_Steer_h
#define _ROS_automotive_platform_msgs_Steer_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_platform_msgs
{

  class Steer : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _module_name_type;
      _module_name_type module_name;
      typedef float _curvature_type;
      _curvature_type curvature;
      typedef float _max_curvature_rate_type;
      _max_curvature_rate_type max_curvature_rate;

    Steer():
      header(),
      module_name(""),
      curvature(0),
      max_curvature_rate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_module_name = strlen(this->module_name);
      varToArr(outbuffer + offset, length_module_name);
      offset += 4;
      memcpy(outbuffer + offset, this->module_name, length_module_name);
      offset += length_module_name;
      union {
        float real;
        uint32_t base;
      } u_curvature;
      u_curvature.real = this->curvature;
      *(outbuffer + offset + 0) = (u_curvature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_curvature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_curvature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_curvature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->curvature);
      union {
        float real;
        uint32_t base;
      } u_max_curvature_rate;
      u_max_curvature_rate.real = this->max_curvature_rate;
      *(outbuffer + offset + 0) = (u_max_curvature_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_curvature_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_curvature_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_curvature_rate.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_curvature_rate);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_module_name;
      arrToVar(length_module_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_module_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_module_name-1]=0;
      this->module_name = (char *)(inbuffer + offset-1);
      offset += length_module_name;
      union {
        float real;
        uint32_t base;
      } u_curvature;
      u_curvature.base = 0;
      u_curvature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_curvature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_curvature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_curvature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->curvature = u_curvature.real;
      offset += sizeof(this->curvature);
      union {
        float real;
        uint32_t base;
      } u_max_curvature_rate;
      u_max_curvature_rate.base = 0;
      u_max_curvature_rate.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_curvature_rate.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_curvature_rate.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_curvature_rate.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_curvature_rate = u_max_curvature_rate.real;
      offset += sizeof(this->max_curvature_rate);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/Steer"; };
    const char * getMD5(){ return "707dbbe00e6de0f2a6ed7a28a1389dc7"; };

  };

}
#endif