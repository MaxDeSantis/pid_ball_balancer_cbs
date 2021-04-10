#ifndef _ROS_lgsvl_msgs_Ultrasonic_h
#define _ROS_lgsvl_msgs_Ultrasonic_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace lgsvl_msgs
{

  class Ultrasonic : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _minimum_distance_type;
      _minimum_distance_type minimum_distance;

    Ultrasonic():
      header(),
      minimum_distance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_minimum_distance;
      u_minimum_distance.real = this->minimum_distance;
      *(outbuffer + offset + 0) = (u_minimum_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_minimum_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_minimum_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_minimum_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->minimum_distance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_minimum_distance;
      u_minimum_distance.base = 0;
      u_minimum_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_minimum_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_minimum_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_minimum_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->minimum_distance = u_minimum_distance.real;
      offset += sizeof(this->minimum_distance);
     return offset;
    }

    const char * getType(){ return "lgsvl_msgs/Ultrasonic"; };
    const char * getMD5(){ return "147c0a86645c864fa65cb63dc4af9f2f"; };

  };

}
#endif