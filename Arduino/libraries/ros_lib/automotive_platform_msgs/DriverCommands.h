#ifndef _ROS_automotive_platform_msgs_DriverCommands_h
#define _ROS_automotive_platform_msgs_DriverCommands_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace automotive_platform_msgs
{

  class DriverCommands : public ros::Msg
  {
    public:
      typedef uint8_t _msg_counter_type;
      _msg_counter_type msg_counter;
      typedef uint16_t _engage_type;
      _engage_type engage;
      typedef uint16_t _disengage_type;
      _disengage_type disengage;
      typedef uint16_t _speed_up_type;
      _speed_up_type speed_up;
      typedef uint16_t _slow_down_type;
      _slow_down_type slow_down;
      typedef uint16_t _further_type;
      _further_type further;
      typedef uint16_t _closer_type;
      _closer_type closer;
      typedef uint16_t _right_turn_type;
      _right_turn_type right_turn;
      typedef uint16_t _left_turn_type;
      _left_turn_type left_turn;

    DriverCommands():
      msg_counter(0),
      engage(0),
      disengage(0),
      speed_up(0),
      slow_down(0),
      further(0),
      closer(0),
      right_turn(0),
      left_turn(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->msg_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->msg_counter);
      *(outbuffer + offset + 0) = (this->engage >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->engage >> (8 * 1)) & 0xFF;
      offset += sizeof(this->engage);
      *(outbuffer + offset + 0) = (this->disengage >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->disengage >> (8 * 1)) & 0xFF;
      offset += sizeof(this->disengage);
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
      *(outbuffer + offset + 0) = (this->right_turn >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->right_turn >> (8 * 1)) & 0xFF;
      offset += sizeof(this->right_turn);
      *(outbuffer + offset + 0) = (this->left_turn >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->left_turn >> (8 * 1)) & 0xFF;
      offset += sizeof(this->left_turn);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->msg_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->msg_counter);
      this->engage =  ((uint16_t) (*(inbuffer + offset)));
      this->engage |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->engage);
      this->disengage =  ((uint16_t) (*(inbuffer + offset)));
      this->disengage |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->disengage);
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
      this->right_turn =  ((uint16_t) (*(inbuffer + offset)));
      this->right_turn |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->right_turn);
      this->left_turn =  ((uint16_t) (*(inbuffer + offset)));
      this->left_turn |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->left_turn);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/DriverCommands"; };
    const char * getMD5(){ return "612c1e59d97aa5ea3be1c2ad2b26dbc7"; };

  };

}
#endif