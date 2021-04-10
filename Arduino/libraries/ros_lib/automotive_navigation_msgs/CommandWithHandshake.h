#ifndef _ROS_automotive_navigation_msgs_CommandWithHandshake_h
#define _ROS_automotive_navigation_msgs_CommandWithHandshake_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_navigation_msgs
{

  class CommandWithHandshake : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _msg_counter_type;
      _msg_counter_type msg_counter;
      typedef int16_t _command_type;
      _command_type command;

    CommandWithHandshake():
      header(),
      msg_counter(0),
      command(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->msg_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->msg_counter);
      union {
        int16_t real;
        uint16_t base;
      } u_command;
      u_command.real = this->command;
      *(outbuffer + offset + 0) = (u_command.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_command.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->command);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->msg_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->msg_counter);
      union {
        int16_t real;
        uint16_t base;
      } u_command;
      u_command.base = 0;
      u_command.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_command.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->command = u_command.real;
      offset += sizeof(this->command);
     return offset;
    }

    const char * getType(){ return "automotive_navigation_msgs/CommandWithHandshake"; };
    const char * getMD5(){ return "0bc28bf48c6bf23450157ae0aab75d4e"; };

  };

}
#endif