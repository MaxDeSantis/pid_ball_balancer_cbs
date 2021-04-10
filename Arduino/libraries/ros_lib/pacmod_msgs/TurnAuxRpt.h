#ifndef _ROS_pacmod_msgs_TurnAuxRpt_h
#define _ROS_pacmod_msgs_TurnAuxRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class TurnAuxRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _driver_blinker_bulb_on_type;
      _driver_blinker_bulb_on_type driver_blinker_bulb_on;
      typedef bool _driver_blinker_bulb_on_is_valid_type;
      _driver_blinker_bulb_on_is_valid_type driver_blinker_bulb_on_is_valid;
      typedef bool _passenger_blinker_bulb_on_type;
      _passenger_blinker_bulb_on_type passenger_blinker_bulb_on;
      typedef bool _passenger_blinker_bulb_on_is_valid_type;
      _passenger_blinker_bulb_on_is_valid_type passenger_blinker_bulb_on_is_valid;

    TurnAuxRpt():
      header(),
      driver_blinker_bulb_on(0),
      driver_blinker_bulb_on_is_valid(0),
      passenger_blinker_bulb_on(0),
      passenger_blinker_bulb_on_is_valid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_driver_blinker_bulb_on;
      u_driver_blinker_bulb_on.real = this->driver_blinker_bulb_on;
      *(outbuffer + offset + 0) = (u_driver_blinker_bulb_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->driver_blinker_bulb_on);
      union {
        bool real;
        uint8_t base;
      } u_driver_blinker_bulb_on_is_valid;
      u_driver_blinker_bulb_on_is_valid.real = this->driver_blinker_bulb_on_is_valid;
      *(outbuffer + offset + 0) = (u_driver_blinker_bulb_on_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->driver_blinker_bulb_on_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_passenger_blinker_bulb_on;
      u_passenger_blinker_bulb_on.real = this->passenger_blinker_bulb_on;
      *(outbuffer + offset + 0) = (u_passenger_blinker_bulb_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->passenger_blinker_bulb_on);
      union {
        bool real;
        uint8_t base;
      } u_passenger_blinker_bulb_on_is_valid;
      u_passenger_blinker_bulb_on_is_valid.real = this->passenger_blinker_bulb_on_is_valid;
      *(outbuffer + offset + 0) = (u_passenger_blinker_bulb_on_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->passenger_blinker_bulb_on_is_valid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_driver_blinker_bulb_on;
      u_driver_blinker_bulb_on.base = 0;
      u_driver_blinker_bulb_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->driver_blinker_bulb_on = u_driver_blinker_bulb_on.real;
      offset += sizeof(this->driver_blinker_bulb_on);
      union {
        bool real;
        uint8_t base;
      } u_driver_blinker_bulb_on_is_valid;
      u_driver_blinker_bulb_on_is_valid.base = 0;
      u_driver_blinker_bulb_on_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->driver_blinker_bulb_on_is_valid = u_driver_blinker_bulb_on_is_valid.real;
      offset += sizeof(this->driver_blinker_bulb_on_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_passenger_blinker_bulb_on;
      u_passenger_blinker_bulb_on.base = 0;
      u_passenger_blinker_bulb_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->passenger_blinker_bulb_on = u_passenger_blinker_bulb_on.real;
      offset += sizeof(this->passenger_blinker_bulb_on);
      union {
        bool real;
        uint8_t base;
      } u_passenger_blinker_bulb_on_is_valid;
      u_passenger_blinker_bulb_on_is_valid.base = 0;
      u_passenger_blinker_bulb_on_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->passenger_blinker_bulb_on_is_valid = u_passenger_blinker_bulb_on_is_valid.real;
      offset += sizeof(this->passenger_blinker_bulb_on_is_valid);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/TurnAuxRpt"; };
    const char * getMD5(){ return "c04dad80913279be4de094443dc50dca"; };

  };

}
#endif