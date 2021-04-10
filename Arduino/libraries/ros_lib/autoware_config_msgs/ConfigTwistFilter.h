#ifndef _ROS_autoware_config_msgs_ConfigTwistFilter_h
#define _ROS_autoware_config_msgs_ConfigTwistFilter_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigTwistFilter : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _lateral_accel_limit_type;
      _lateral_accel_limit_type lateral_accel_limit;
      typedef float _lowpass_gain_linear_x_type;
      _lowpass_gain_linear_x_type lowpass_gain_linear_x;
      typedef float _lowpass_gain_angular_z_type;
      _lowpass_gain_angular_z_type lowpass_gain_angular_z;

    ConfigTwistFilter():
      header(),
      lateral_accel_limit(0),
      lowpass_gain_linear_x(0),
      lowpass_gain_angular_z(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_lateral_accel_limit;
      u_lateral_accel_limit.real = this->lateral_accel_limit;
      *(outbuffer + offset + 0) = (u_lateral_accel_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lateral_accel_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lateral_accel_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lateral_accel_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lateral_accel_limit);
      union {
        float real;
        uint32_t base;
      } u_lowpass_gain_linear_x;
      u_lowpass_gain_linear_x.real = this->lowpass_gain_linear_x;
      *(outbuffer + offset + 0) = (u_lowpass_gain_linear_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lowpass_gain_linear_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lowpass_gain_linear_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lowpass_gain_linear_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lowpass_gain_linear_x);
      union {
        float real;
        uint32_t base;
      } u_lowpass_gain_angular_z;
      u_lowpass_gain_angular_z.real = this->lowpass_gain_angular_z;
      *(outbuffer + offset + 0) = (u_lowpass_gain_angular_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lowpass_gain_angular_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lowpass_gain_angular_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lowpass_gain_angular_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lowpass_gain_angular_z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_lateral_accel_limit;
      u_lateral_accel_limit.base = 0;
      u_lateral_accel_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lateral_accel_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lateral_accel_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lateral_accel_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lateral_accel_limit = u_lateral_accel_limit.real;
      offset += sizeof(this->lateral_accel_limit);
      union {
        float real;
        uint32_t base;
      } u_lowpass_gain_linear_x;
      u_lowpass_gain_linear_x.base = 0;
      u_lowpass_gain_linear_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lowpass_gain_linear_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lowpass_gain_linear_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lowpass_gain_linear_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lowpass_gain_linear_x = u_lowpass_gain_linear_x.real;
      offset += sizeof(this->lowpass_gain_linear_x);
      union {
        float real;
        uint32_t base;
      } u_lowpass_gain_angular_z;
      u_lowpass_gain_angular_z.base = 0;
      u_lowpass_gain_angular_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lowpass_gain_angular_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lowpass_gain_angular_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lowpass_gain_angular_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lowpass_gain_angular_z = u_lowpass_gain_angular_z.real;
      offset += sizeof(this->lowpass_gain_angular_z);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigTwistFilter"; };
    const char * getMD5(){ return "335a86e776e694c10602a1ee3d9a09de"; };

  };

}
#endif