#ifndef _ROS_status_status_msg_h
#define _ROS_status_status_msg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/UInt16.h"

namespace status
{

  class status_msg : public ros::Msg
  {
    public:
      typedef std_msgs::UInt16 _status_type;
      _status_type status;
      enum { HEALTHY = 0 };
      enum { UNSTABLE = 1 };
      enum { CONNECTING = 2 };
      enum { FATAL = 3 };
      enum { DISCONNECTED = 4 };

    status_msg():
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "status/status_msg"; };
    const char * getMD5(){ return "0bcfc08d0bc0eefc7607452d08840d09"; };

  };

}
#endif