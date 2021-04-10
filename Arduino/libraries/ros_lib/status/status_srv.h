#ifndef _ROS_SERVICE_status_srv_h
#define _ROS_SERVICE_status_srv_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/UInt16.h"

namespace status
{

static const char STATUS_SRV[] = "status/status_srv";

  class status_srvRequest : public ros::Msg
  {
    public:

    status_srvRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return STATUS_SRV; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class status_srvResponse : public ros::Msg
  {
    public:
      typedef std_msgs::UInt16 _status_type;
      _status_type status;
      enum { HEALTHY = 0 };
      enum { UNSTABLE = 1 };
      enum { CONNECTING = 2 };
      enum { FATAL = 3 };
      enum { DISCONNECTED = 4 };

    status_srvResponse():
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

    const char * getType(){ return STATUS_SRV; };
    const char * getMD5(){ return "0bcfc08d0bc0eefc7607452d08840d09"; };

  };

  class status_srv {
    public:
    typedef status_srvRequest Request;
    typedef status_srvResponse Response;
  };

}
#endif
