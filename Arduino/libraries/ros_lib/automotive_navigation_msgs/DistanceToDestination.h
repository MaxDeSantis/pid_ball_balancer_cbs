#ifndef _ROS_automotive_navigation_msgs_DistanceToDestination_h
#define _ROS_automotive_navigation_msgs_DistanceToDestination_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_navigation_msgs
{

  class DistanceToDestination : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _msg_counter_type;
      _msg_counter_type msg_counter;
      typedef float _distance_type;
      _distance_type distance;

    DistanceToDestination():
      header(),
      msg_counter(0),
      distance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->msg_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->msg_counter);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.real = this->distance;
      *(outbuffer + offset + 0) = (u_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->msg_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->msg_counter);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.base = 0;
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance = u_distance.real;
      offset += sizeof(this->distance);
     return offset;
    }

    const char * getType(){ return "automotive_navigation_msgs/DistanceToDestination"; };
    const char * getMD5(){ return "5900bd7ec809d5e8d6ec47b8ddef8d1b"; };

  };

}
#endif