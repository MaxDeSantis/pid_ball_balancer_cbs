#ifndef _ROS_automotive_navigation_msgs_DesiredDestination_h
#define _ROS_automotive_navigation_msgs_DesiredDestination_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_navigation_msgs
{

  class DesiredDestination : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _msg_counter_type;
      _msg_counter_type msg_counter;
      typedef uint16_t _valid_type;
      _valid_type valid;
      typedef float _latitude_type;
      _latitude_type latitude;
      typedef float _longitude_type;
      _longitude_type longitude;

    DesiredDestination():
      header(),
      msg_counter(0),
      valid(0),
      latitude(0),
      longitude(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->msg_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->msg_counter);
      *(outbuffer + offset + 0) = (this->valid >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->valid >> (8 * 1)) & 0xFF;
      offset += sizeof(this->valid);
      offset += serializeAvrFloat64(outbuffer + offset, this->latitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->longitude);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->msg_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->msg_counter);
      this->valid =  ((uint16_t) (*(inbuffer + offset)));
      this->valid |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->valid);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->latitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->longitude));
     return offset;
    }

    const char * getType(){ return "automotive_navigation_msgs/DesiredDestination"; };
    const char * getMD5(){ return "ebb7b7743d8a0ce286cd377c24111c3c"; };

  };

}
#endif