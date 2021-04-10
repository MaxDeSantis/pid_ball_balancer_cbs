#ifndef _ROS_pacmod_msgs_VehicleSpecificRpt1_h
#define _ROS_pacmod_msgs_VehicleSpecificRpt1_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class VehicleSpecificRpt1 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _shift_pos_1_type;
      _shift_pos_1_type shift_pos_1;
      typedef uint8_t _shift_pos_2_type;
      _shift_pos_2_type shift_pos_2;

    VehicleSpecificRpt1():
      header(),
      shift_pos_1(0),
      shift_pos_2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->shift_pos_1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->shift_pos_1);
      *(outbuffer + offset + 0) = (this->shift_pos_2 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->shift_pos_2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->shift_pos_1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->shift_pos_1);
      this->shift_pos_2 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->shift_pos_2);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/VehicleSpecificRpt1"; };
    const char * getMD5(){ return "e61481747bb1386c6b9f8ef5c5adad62"; };

  };

}
#endif