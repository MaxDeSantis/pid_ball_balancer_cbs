#ifndef _ROS_automotive_platform_msgs_Speed_h
#define _ROS_automotive_platform_msgs_Speed_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_platform_msgs
{

  class Speed : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _module_name_type;
      _module_name_type module_name;
      typedef float _speed_type;
      _speed_type speed;
      typedef float _acceleration_limit_type;
      _acceleration_limit_type acceleration_limit;
      typedef float _deceleration_limit_type;
      _deceleration_limit_type deceleration_limit;

    Speed():
      header(),
      module_name(""),
      speed(0),
      acceleration_limit(0),
      deceleration_limit(0)
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
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed);
      union {
        float real;
        uint32_t base;
      } u_acceleration_limit;
      u_acceleration_limit.real = this->acceleration_limit;
      *(outbuffer + offset + 0) = (u_acceleration_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acceleration_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acceleration_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acceleration_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acceleration_limit);
      union {
        float real;
        uint32_t base;
      } u_deceleration_limit;
      u_deceleration_limit.real = this->deceleration_limit;
      *(outbuffer + offset + 0) = (u_deceleration_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_deceleration_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_deceleration_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_deceleration_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->deceleration_limit);
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
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
      union {
        float real;
        uint32_t base;
      } u_acceleration_limit;
      u_acceleration_limit.base = 0;
      u_acceleration_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acceleration_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acceleration_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acceleration_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->acceleration_limit = u_acceleration_limit.real;
      offset += sizeof(this->acceleration_limit);
      union {
        float real;
        uint32_t base;
      } u_deceleration_limit;
      u_deceleration_limit.base = 0;
      u_deceleration_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_deceleration_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_deceleration_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_deceleration_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->deceleration_limit = u_deceleration_limit.real;
      offset += sizeof(this->deceleration_limit);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/Speed"; };
    const char * getMD5(){ return "19e5d1450bb352242868b04367a49847"; };

  };

}
#endif