#ifndef _ROS_autoware_config_msgs_ConfigLaneStop_h
#define _ROS_autoware_config_msgs_ConfigLaneStop_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigLaneStop : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _manual_detection_type;
      _manual_detection_type manual_detection;

    ConfigLaneStop():
      header(),
      manual_detection(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_manual_detection;
      u_manual_detection.real = this->manual_detection;
      *(outbuffer + offset + 0) = (u_manual_detection.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->manual_detection);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_manual_detection;
      u_manual_detection.base = 0;
      u_manual_detection.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->manual_detection = u_manual_detection.real;
      offset += sizeof(this->manual_detection);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigLaneStop"; };
    const char * getMD5(){ return "3b7e045a50c80411a1e64d2f61b1a0b3"; };

  };

}
#endif