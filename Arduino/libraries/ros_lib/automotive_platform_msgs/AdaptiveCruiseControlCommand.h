#ifndef _ROS_automotive_platform_msgs_AdaptiveCruiseControlCommand_h
#define _ROS_automotive_platform_msgs_AdaptiveCruiseControlCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_platform_msgs
{

  class AdaptiveCruiseControlCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _msg_counter_type;
      _msg_counter_type msg_counter;
      typedef float _set_speed_type;
      _set_speed_type set_speed;
      typedef uint16_t _set_type;
      _set_type set;
      typedef uint16_t _resume_type;
      _resume_type resume;
      typedef uint16_t _cancel_type;
      _cancel_type cancel;
      typedef uint16_t _speed_up_type;
      _speed_up_type speed_up;
      typedef uint16_t _slow_down_type;
      _slow_down_type slow_down;
      typedef uint16_t _further_type;
      _further_type further;
      typedef uint16_t _closer_type;
      _closer_type closer;

    AdaptiveCruiseControlCommand():
      header(),
      msg_counter(0),
      set_speed(0),
      set(0),
      resume(0),
      cancel(0),
      speed_up(0),
      slow_down(0),
      further(0),
      closer(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->msg_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->msg_counter);
      union {
        float real;
        uint32_t base;
      } u_set_speed;
      u_set_speed.real = this->set_speed;
      *(outbuffer + offset + 0) = (u_set_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_set_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_set_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_set_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->set_speed);
      *(outbuffer + offset + 0) = (this->set >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->set >> (8 * 1)) & 0xFF;
      offset += sizeof(this->set);
      *(outbuffer + offset + 0) = (this->resume >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->resume >> (8 * 1)) & 0xFF;
      offset += sizeof(this->resume);
      *(outbuffer + offset + 0) = (this->cancel >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cancel >> (8 * 1)) & 0xFF;
      offset += sizeof(this->cancel);
      *(outbuffer + offset + 0) = (this->speed_up >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->speed_up >> (8 * 1)) & 0xFF;
      offset += sizeof(this->speed_up);
      *(outbuffer + offset + 0) = (this->slow_down >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->slow_down >> (8 * 1)) & 0xFF;
      offset += sizeof(this->slow_down);
      *(outbuffer + offset + 0) = (this->further >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->further >> (8 * 1)) & 0xFF;
      offset += sizeof(this->further);
      *(outbuffer + offset + 0) = (this->closer >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->closer >> (8 * 1)) & 0xFF;
      offset += sizeof(this->closer);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->msg_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->msg_counter);
      union {
        float real;
        uint32_t base;
      } u_set_speed;
      u_set_speed.base = 0;
      u_set_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_set_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_set_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_set_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->set_speed = u_set_speed.real;
      offset += sizeof(this->set_speed);
      this->set =  ((uint16_t) (*(inbuffer + offset)));
      this->set |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->set);
      this->resume =  ((uint16_t) (*(inbuffer + offset)));
      this->resume |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->resume);
      this->cancel =  ((uint16_t) (*(inbuffer + offset)));
      this->cancel |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->cancel);
      this->speed_up =  ((uint16_t) (*(inbuffer + offset)));
      this->speed_up |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->speed_up);
      this->slow_down =  ((uint16_t) (*(inbuffer + offset)));
      this->slow_down |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->slow_down);
      this->further =  ((uint16_t) (*(inbuffer + offset)));
      this->further |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->further);
      this->closer =  ((uint16_t) (*(inbuffer + offset)));
      this->closer |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->closer);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/AdaptiveCruiseControlCommand"; };
    const char * getMD5(){ return "45cb31c55c795766905c8d3ddf401e18"; };

  };

}
#endif