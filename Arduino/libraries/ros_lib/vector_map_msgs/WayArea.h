#ifndef _ROS_vector_map_msgs_WayArea_h
#define _ROS_vector_map_msgs_WayArea_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_map_msgs
{

  class WayArea : public ros::Msg
  {
    public:
      typedef int32_t _waid_type;
      _waid_type waid;
      typedef int32_t _aid_type;
      _aid_type aid;

    WayArea():
      waid(0),
      aid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_waid;
      u_waid.real = this->waid;
      *(outbuffer + offset + 0) = (u_waid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_waid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_waid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_waid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->waid);
      union {
        int32_t real;
        uint32_t base;
      } u_aid;
      u_aid.real = this->aid;
      *(outbuffer + offset + 0) = (u_aid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_aid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_aid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_aid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->aid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_waid;
      u_waid.base = 0;
      u_waid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_waid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_waid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_waid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->waid = u_waid.real;
      offset += sizeof(this->waid);
      union {
        int32_t real;
        uint32_t base;
      } u_aid;
      u_aid.base = 0;
      u_aid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_aid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_aid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_aid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->aid = u_aid.real;
      offset += sizeof(this->aid);
     return offset;
    }

    const char * getType(){ return "vector_map_msgs/WayArea"; };
    const char * getMD5(){ return "ac793f4ec70fe037c00e585b4376d809"; };

  };

}
#endif