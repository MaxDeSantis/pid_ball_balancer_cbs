#ifndef _ROS_automotive_platform_msgs_GearCommand_h
#define _ROS_automotive_platform_msgs_GearCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "automotive_platform_msgs/Gear.h"

namespace automotive_platform_msgs
{

  class GearCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef automotive_platform_msgs::Gear _command_type;
      _command_type command;

    GearCommand():
      header(),
      command()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->command.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->command.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/GearCommand"; };
    const char * getMD5(){ return "a95429508de6e31c2134277c47838158"; };

  };

}
#endif