#ifndef _ROS_automotive_platform_msgs_TurnSignalCommand_h
#define _ROS_automotive_platform_msgs_TurnSignalCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_platform_msgs
{

  class TurnSignalCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint16_t _mode_type;
      _mode_type mode;
      typedef uint8_t _turn_signal_type;
      _turn_signal_type turn_signal;
      enum { NONE = 0 };
      enum { LEFT = 1 };
      enum { RIGHT = 2 };

    TurnSignalCommand():
      header(),
      mode(0),
      turn_signal(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mode >> (8 * 1)) & 0xFF;
      offset += sizeof(this->mode);
      *(outbuffer + offset + 0) = (this->turn_signal >> (8 * 0)) & 0xFF;
      offset += sizeof(this->turn_signal);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->mode =  ((uint16_t) (*(inbuffer + offset)));
      this->mode |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->mode);
      this->turn_signal =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->turn_signal);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/TurnSignalCommand"; };
    const char * getMD5(){ return "dfcc072c40d13a25c7a88dcc60473ed5"; };

  };

}
#endif