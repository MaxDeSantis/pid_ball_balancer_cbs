#ifndef _ROS_automotive_platform_msgs_CurvatureFeedback_h
#define _ROS_automotive_platform_msgs_CurvatureFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_platform_msgs
{

  class CurvatureFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _curvature_type;
      _curvature_type curvature;

    CurvatureFeedback():
      header(),
      curvature(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_curvature;
      u_curvature.real = this->curvature;
      *(outbuffer + offset + 0) = (u_curvature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_curvature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_curvature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_curvature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->curvature);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_curvature;
      u_curvature.base = 0;
      u_curvature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_curvature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_curvature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_curvature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->curvature = u_curvature.real;
      offset += sizeof(this->curvature);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/CurvatureFeedback"; };
    const char * getMD5(){ return "5c011af0547a17c89a2ebf5e6e57bd57"; };

  };

}
#endif