#ifndef _ROS_autoware_msgs_StateCmd_h
#define _ROS_autoware_msgs_StateCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_msgs
{

  class StateCmd : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _cmd_type;
      _cmd_type cmd;

    StateCmd():
      header(),
      cmd(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_cmd;
      u_cmd.real = this->cmd;
      *(outbuffer + offset + 0) = (u_cmd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cmd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cmd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cmd.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cmd);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_cmd;
      u_cmd.base = 0;
      u_cmd.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cmd.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cmd.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cmd.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cmd = u_cmd.real;
      offset += sizeof(this->cmd);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/StateCmd"; };
    const char * getMD5(){ return "2d4242eed7fbc359001bdfe40fa0ef73"; };

  };

}
#endif