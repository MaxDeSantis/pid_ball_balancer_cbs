#ifndef _ROS_autoware_config_msgs_ConfigSSD_h
#define _ROS_autoware_config_msgs_ConfigSSD_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigSSD : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _score_threshold_type;
      _score_threshold_type score_threshold;

    ConfigSSD():
      header(),
      score_threshold(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_score_threshold;
      u_score_threshold.real = this->score_threshold;
      *(outbuffer + offset + 0) = (u_score_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_score_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_score_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_score_threshold.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->score_threshold);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_score_threshold;
      u_score_threshold.base = 0;
      u_score_threshold.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_score_threshold.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_score_threshold.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_score_threshold.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->score_threshold = u_score_threshold.real;
      offset += sizeof(this->score_threshold);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigSSD"; };
    const char * getMD5(){ return "9c20d382dda6d21d4020d239679f6abd"; };

  };

}
#endif