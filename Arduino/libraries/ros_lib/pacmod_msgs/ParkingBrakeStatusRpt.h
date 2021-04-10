#ifndef _ROS_pacmod_msgs_ParkingBrakeStatusRpt_h
#define _ROS_pacmod_msgs_ParkingBrakeStatusRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class ParkingBrakeStatusRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _parking_brake_engaged_type;
      _parking_brake_engaged_type parking_brake_engaged;

    ParkingBrakeStatusRpt():
      header(),
      parking_brake_engaged(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_parking_brake_engaged;
      u_parking_brake_engaged.real = this->parking_brake_engaged;
      *(outbuffer + offset + 0) = (u_parking_brake_engaged.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->parking_brake_engaged);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_parking_brake_engaged;
      u_parking_brake_engaged.base = 0;
      u_parking_brake_engaged.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->parking_brake_engaged = u_parking_brake_engaged.real;
      offset += sizeof(this->parking_brake_engaged);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/ParkingBrakeStatusRpt"; };
    const char * getMD5(){ return "28531874ceb48a58d4faa42b130fc228"; };

  };

}
#endif