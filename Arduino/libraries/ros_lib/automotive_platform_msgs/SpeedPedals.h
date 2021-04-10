#ifndef _ROS_automotive_platform_msgs_SpeedPedals_h
#define _ROS_automotive_platform_msgs_SpeedPedals_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_platform_msgs
{

  class SpeedPedals : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint16_t _mode_type;
      _mode_type mode;
      typedef float _throttle_type;
      _throttle_type throttle;
      typedef float _brake_type;
      _brake_type brake;

    SpeedPedals():
      header(),
      mode(0),
      throttle(0),
      brake(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mode >> (8 * 1)) & 0xFF;
      offset += sizeof(this->mode);
      union {
        float real;
        uint32_t base;
      } u_throttle;
      u_throttle.real = this->throttle;
      *(outbuffer + offset + 0) = (u_throttle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_throttle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_throttle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_throttle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->throttle);
      union {
        float real;
        uint32_t base;
      } u_brake;
      u_brake.real = this->brake;
      *(outbuffer + offset + 0) = (u_brake.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_brake.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_brake.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_brake.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->brake);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->mode =  ((uint16_t) (*(inbuffer + offset)));
      this->mode |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->mode);
      union {
        float real;
        uint32_t base;
      } u_throttle;
      u_throttle.base = 0;
      u_throttle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_throttle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_throttle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_throttle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->throttle = u_throttle.real;
      offset += sizeof(this->throttle);
      union {
        float real;
        uint32_t base;
      } u_brake;
      u_brake.base = 0;
      u_brake.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_brake.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_brake.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_brake.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->brake = u_brake.real;
      offset += sizeof(this->brake);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/SpeedPedals"; };
    const char * getMD5(){ return "85ba8dc36f9790f861deedfe03109b15"; };

  };

}
#endif