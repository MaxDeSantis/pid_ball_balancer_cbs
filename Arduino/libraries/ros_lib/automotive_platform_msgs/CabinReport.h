#ifndef _ROS_automotive_platform_msgs_CabinReport_h
#define _ROS_automotive_platform_msgs_CabinReport_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_platform_msgs
{

  class CabinReport : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _door_open_front_right_type;
      _door_open_front_right_type door_open_front_right;
      typedef bool _door_open_front_left_type;
      _door_open_front_left_type door_open_front_left;
      typedef bool _door_open_rear_right_type;
      _door_open_rear_right_type door_open_rear_right;
      typedef bool _door_open_rear_left_type;
      _door_open_rear_left_type door_open_rear_left;
      typedef bool _hood_open_type;
      _hood_open_type hood_open;
      typedef bool _trunk_open_type;
      _trunk_open_type trunk_open;
      typedef bool _passenger_present_type;
      _passenger_present_type passenger_present;
      typedef bool _passenger_airbag_enabled_type;
      _passenger_airbag_enabled_type passenger_airbag_enabled;
      typedef bool _seatbelt_engaged_driver_type;
      _seatbelt_engaged_driver_type seatbelt_engaged_driver;
      typedef bool _seatbelt_engaged_passenger_type;
      _seatbelt_engaged_passenger_type seatbelt_engaged_passenger;

    CabinReport():
      header(),
      door_open_front_right(0),
      door_open_front_left(0),
      door_open_rear_right(0),
      door_open_rear_left(0),
      hood_open(0),
      trunk_open(0),
      passenger_present(0),
      passenger_airbag_enabled(0),
      seatbelt_engaged_driver(0),
      seatbelt_engaged_passenger(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_door_open_front_right;
      u_door_open_front_right.real = this->door_open_front_right;
      *(outbuffer + offset + 0) = (u_door_open_front_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->door_open_front_right);
      union {
        bool real;
        uint8_t base;
      } u_door_open_front_left;
      u_door_open_front_left.real = this->door_open_front_left;
      *(outbuffer + offset + 0) = (u_door_open_front_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->door_open_front_left);
      union {
        bool real;
        uint8_t base;
      } u_door_open_rear_right;
      u_door_open_rear_right.real = this->door_open_rear_right;
      *(outbuffer + offset + 0) = (u_door_open_rear_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->door_open_rear_right);
      union {
        bool real;
        uint8_t base;
      } u_door_open_rear_left;
      u_door_open_rear_left.real = this->door_open_rear_left;
      *(outbuffer + offset + 0) = (u_door_open_rear_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->door_open_rear_left);
      union {
        bool real;
        uint8_t base;
      } u_hood_open;
      u_hood_open.real = this->hood_open;
      *(outbuffer + offset + 0) = (u_hood_open.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->hood_open);
      union {
        bool real;
        uint8_t base;
      } u_trunk_open;
      u_trunk_open.real = this->trunk_open;
      *(outbuffer + offset + 0) = (u_trunk_open.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->trunk_open);
      union {
        bool real;
        uint8_t base;
      } u_passenger_present;
      u_passenger_present.real = this->passenger_present;
      *(outbuffer + offset + 0) = (u_passenger_present.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->passenger_present);
      union {
        bool real;
        uint8_t base;
      } u_passenger_airbag_enabled;
      u_passenger_airbag_enabled.real = this->passenger_airbag_enabled;
      *(outbuffer + offset + 0) = (u_passenger_airbag_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->passenger_airbag_enabled);
      union {
        bool real;
        uint8_t base;
      } u_seatbelt_engaged_driver;
      u_seatbelt_engaged_driver.real = this->seatbelt_engaged_driver;
      *(outbuffer + offset + 0) = (u_seatbelt_engaged_driver.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->seatbelt_engaged_driver);
      union {
        bool real;
        uint8_t base;
      } u_seatbelt_engaged_passenger;
      u_seatbelt_engaged_passenger.real = this->seatbelt_engaged_passenger;
      *(outbuffer + offset + 0) = (u_seatbelt_engaged_passenger.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->seatbelt_engaged_passenger);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_door_open_front_right;
      u_door_open_front_right.base = 0;
      u_door_open_front_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->door_open_front_right = u_door_open_front_right.real;
      offset += sizeof(this->door_open_front_right);
      union {
        bool real;
        uint8_t base;
      } u_door_open_front_left;
      u_door_open_front_left.base = 0;
      u_door_open_front_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->door_open_front_left = u_door_open_front_left.real;
      offset += sizeof(this->door_open_front_left);
      union {
        bool real;
        uint8_t base;
      } u_door_open_rear_right;
      u_door_open_rear_right.base = 0;
      u_door_open_rear_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->door_open_rear_right = u_door_open_rear_right.real;
      offset += sizeof(this->door_open_rear_right);
      union {
        bool real;
        uint8_t base;
      } u_door_open_rear_left;
      u_door_open_rear_left.base = 0;
      u_door_open_rear_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->door_open_rear_left = u_door_open_rear_left.real;
      offset += sizeof(this->door_open_rear_left);
      union {
        bool real;
        uint8_t base;
      } u_hood_open;
      u_hood_open.base = 0;
      u_hood_open.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->hood_open = u_hood_open.real;
      offset += sizeof(this->hood_open);
      union {
        bool real;
        uint8_t base;
      } u_trunk_open;
      u_trunk_open.base = 0;
      u_trunk_open.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->trunk_open = u_trunk_open.real;
      offset += sizeof(this->trunk_open);
      union {
        bool real;
        uint8_t base;
      } u_passenger_present;
      u_passenger_present.base = 0;
      u_passenger_present.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->passenger_present = u_passenger_present.real;
      offset += sizeof(this->passenger_present);
      union {
        bool real;
        uint8_t base;
      } u_passenger_airbag_enabled;
      u_passenger_airbag_enabled.base = 0;
      u_passenger_airbag_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->passenger_airbag_enabled = u_passenger_airbag_enabled.real;
      offset += sizeof(this->passenger_airbag_enabled);
      union {
        bool real;
        uint8_t base;
      } u_seatbelt_engaged_driver;
      u_seatbelt_engaged_driver.base = 0;
      u_seatbelt_engaged_driver.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->seatbelt_engaged_driver = u_seatbelt_engaged_driver.real;
      offset += sizeof(this->seatbelt_engaged_driver);
      union {
        bool real;
        uint8_t base;
      } u_seatbelt_engaged_passenger;
      u_seatbelt_engaged_passenger.base = 0;
      u_seatbelt_engaged_passenger.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->seatbelt_engaged_passenger = u_seatbelt_engaged_passenger.real;
      offset += sizeof(this->seatbelt_engaged_passenger);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/CabinReport"; };
    const char * getMD5(){ return "63611b37cea8020053088e5a34aead53"; };

  };

}
#endif