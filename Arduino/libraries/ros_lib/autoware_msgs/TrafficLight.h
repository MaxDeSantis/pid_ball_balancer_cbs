#ifndef _ROS_autoware_msgs_TrafficLight_h
#define _ROS_autoware_msgs_TrafficLight_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_msgs
{

  class TrafficLight : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _traffic_light_type;
      _traffic_light_type traffic_light;

    TrafficLight():
      header(),
      traffic_light(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_traffic_light;
      u_traffic_light.real = this->traffic_light;
      *(outbuffer + offset + 0) = (u_traffic_light.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_traffic_light.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_traffic_light.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_traffic_light.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->traffic_light);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_traffic_light;
      u_traffic_light.base = 0;
      u_traffic_light.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_traffic_light.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_traffic_light.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_traffic_light.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->traffic_light = u_traffic_light.real;
      offset += sizeof(this->traffic_light);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/TrafficLight"; };
    const char * getMD5(){ return "a4931ba214a0e37e220dd00b2acca20a"; };

  };

}
#endif