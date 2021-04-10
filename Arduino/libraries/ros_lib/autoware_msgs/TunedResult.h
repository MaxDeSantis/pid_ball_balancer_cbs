#ifndef _ROS_autoware_msgs_TunedResult_h
#define _ROS_autoware_msgs_TunedResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_msgs/ColorSet.h"

namespace autoware_msgs
{

  class TunedResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef autoware_msgs::ColorSet _Red_type;
      _Red_type Red;
      typedef autoware_msgs::ColorSet _Yellow_type;
      _Yellow_type Yellow;
      typedef autoware_msgs::ColorSet _Green_type;
      _Green_type Green;

    TunedResult():
      header(),
      Red(),
      Yellow(),
      Green()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->Red.serialize(outbuffer + offset);
      offset += this->Yellow.serialize(outbuffer + offset);
      offset += this->Green.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->Red.deserialize(inbuffer + offset);
      offset += this->Yellow.deserialize(inbuffer + offset);
      offset += this->Green.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/TunedResult"; };
    const char * getMD5(){ return "ddef3f42dffa20afab285bb50468c18e"; };

  };

}
#endif