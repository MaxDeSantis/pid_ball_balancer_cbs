#ifndef _ROS_autoware_msgs_ImageLaneObjects_h
#define _ROS_autoware_msgs_ImageLaneObjects_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_msgs
{

  class ImageLaneObjects : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _lane_l_x1_type;
      _lane_l_x1_type lane_l_x1;
      typedef int32_t _lane_l_y1_type;
      _lane_l_y1_type lane_l_y1;
      typedef int32_t _lane_l_x2_type;
      _lane_l_x2_type lane_l_x2;
      typedef int32_t _lane_l_y2_type;
      _lane_l_y2_type lane_l_y2;
      typedef int32_t _lane_r_x1_type;
      _lane_r_x1_type lane_r_x1;
      typedef int32_t _lane_r_y1_type;
      _lane_r_y1_type lane_r_y1;
      typedef int32_t _lane_r_x2_type;
      _lane_r_x2_type lane_r_x2;
      typedef int32_t _lane_r_y2_type;
      _lane_r_y2_type lane_r_y2;

    ImageLaneObjects():
      header(),
      lane_l_x1(0),
      lane_l_y1(0),
      lane_l_x2(0),
      lane_l_y2(0),
      lane_r_x1(0),
      lane_r_y1(0),
      lane_r_x2(0),
      lane_r_y2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_l_x1;
      u_lane_l_x1.real = this->lane_l_x1;
      *(outbuffer + offset + 0) = (u_lane_l_x1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_l_x1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_l_x1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_l_x1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_l_x1);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_l_y1;
      u_lane_l_y1.real = this->lane_l_y1;
      *(outbuffer + offset + 0) = (u_lane_l_y1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_l_y1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_l_y1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_l_y1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_l_y1);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_l_x2;
      u_lane_l_x2.real = this->lane_l_x2;
      *(outbuffer + offset + 0) = (u_lane_l_x2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_l_x2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_l_x2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_l_x2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_l_x2);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_l_y2;
      u_lane_l_y2.real = this->lane_l_y2;
      *(outbuffer + offset + 0) = (u_lane_l_y2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_l_y2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_l_y2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_l_y2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_l_y2);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_r_x1;
      u_lane_r_x1.real = this->lane_r_x1;
      *(outbuffer + offset + 0) = (u_lane_r_x1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_r_x1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_r_x1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_r_x1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_r_x1);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_r_y1;
      u_lane_r_y1.real = this->lane_r_y1;
      *(outbuffer + offset + 0) = (u_lane_r_y1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_r_y1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_r_y1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_r_y1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_r_y1);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_r_x2;
      u_lane_r_x2.real = this->lane_r_x2;
      *(outbuffer + offset + 0) = (u_lane_r_x2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_r_x2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_r_x2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_r_x2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_r_x2);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_r_y2;
      u_lane_r_y2.real = this->lane_r_y2;
      *(outbuffer + offset + 0) = (u_lane_r_y2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_r_y2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_r_y2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_r_y2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_r_y2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_l_x1;
      u_lane_l_x1.base = 0;
      u_lane_l_x1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_l_x1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lane_l_x1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lane_l_x1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lane_l_x1 = u_lane_l_x1.real;
      offset += sizeof(this->lane_l_x1);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_l_y1;
      u_lane_l_y1.base = 0;
      u_lane_l_y1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_l_y1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lane_l_y1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lane_l_y1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lane_l_y1 = u_lane_l_y1.real;
      offset += sizeof(this->lane_l_y1);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_l_x2;
      u_lane_l_x2.base = 0;
      u_lane_l_x2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_l_x2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lane_l_x2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lane_l_x2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lane_l_x2 = u_lane_l_x2.real;
      offset += sizeof(this->lane_l_x2);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_l_y2;
      u_lane_l_y2.base = 0;
      u_lane_l_y2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_l_y2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lane_l_y2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lane_l_y2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lane_l_y2 = u_lane_l_y2.real;
      offset += sizeof(this->lane_l_y2);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_r_x1;
      u_lane_r_x1.base = 0;
      u_lane_r_x1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_r_x1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lane_r_x1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lane_r_x1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lane_r_x1 = u_lane_r_x1.real;
      offset += sizeof(this->lane_r_x1);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_r_y1;
      u_lane_r_y1.base = 0;
      u_lane_r_y1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_r_y1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lane_r_y1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lane_r_y1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lane_r_y1 = u_lane_r_y1.real;
      offset += sizeof(this->lane_r_y1);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_r_x2;
      u_lane_r_x2.base = 0;
      u_lane_r_x2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_r_x2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lane_r_x2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lane_r_x2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lane_r_x2 = u_lane_r_x2.real;
      offset += sizeof(this->lane_r_x2);
      union {
        int32_t real;
        uint32_t base;
      } u_lane_r_y2;
      u_lane_r_y2.base = 0;
      u_lane_r_y2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_r_y2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lane_r_y2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lane_r_y2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lane_r_y2 = u_lane_r_y2.real;
      offset += sizeof(this->lane_r_y2);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/ImageLaneObjects"; };
    const char * getMD5(){ return "851175a106269dc1f4c64f0c36bafb05"; };

  };

}
#endif