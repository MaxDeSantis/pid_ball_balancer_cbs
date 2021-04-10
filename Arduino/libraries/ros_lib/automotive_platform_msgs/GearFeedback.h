#ifndef _ROS_automotive_platform_msgs_GearFeedback_h
#define _ROS_automotive_platform_msgs_GearFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "automotive_platform_msgs/Gear.h"

namespace automotive_platform_msgs
{

  class GearFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef automotive_platform_msgs::Gear _current_gear_type;
      _current_gear_type current_gear;

    GearFeedback():
      header(),
      current_gear()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->current_gear.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->current_gear.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/GearFeedback"; };
    const char * getMD5(){ return "328d639d4b37a5731de132f4aeb55699"; };

  };

}
#endif