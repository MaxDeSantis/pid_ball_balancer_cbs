#ifndef _ROS_autoware_msgs_ControlCommandStamped_h
#define _ROS_autoware_msgs_ControlCommandStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_msgs/ControlCommand.h"

namespace autoware_msgs
{

  class ControlCommandStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef autoware_msgs::ControlCommand _cmd_type;
      _cmd_type cmd;

    ControlCommandStamped():
      header(),
      cmd()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->cmd.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->cmd.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/ControlCommandStamped"; };
    const char * getMD5(){ return "cf8b01a8273bedcf082c4a0007472482"; };

  };

}
#endif