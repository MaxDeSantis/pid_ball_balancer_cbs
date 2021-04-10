#ifndef _ROS_pacmod_msgs_DoorRpt_h
#define _ROS_pacmod_msgs_DoorRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class DoorRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _driver_door_open_type;
      _driver_door_open_type driver_door_open;
      typedef bool _driver_door_open_is_valid_type;
      _driver_door_open_is_valid_type driver_door_open_is_valid;
      typedef bool _passenger_door_open_type;
      _passenger_door_open_type passenger_door_open;
      typedef bool _passenger_door_open_is_valid_type;
      _passenger_door_open_is_valid_type passenger_door_open_is_valid;
      typedef bool _rear_driver_door_open_type;
      _rear_driver_door_open_type rear_driver_door_open;
      typedef bool _rear_driver_door_open_is_valid_type;
      _rear_driver_door_open_is_valid_type rear_driver_door_open_is_valid;
      typedef bool _rear_passenger_door_open_type;
      _rear_passenger_door_open_type rear_passenger_door_open;
      typedef bool _rear_passenger_door_open_is_valid_type;
      _rear_passenger_door_open_is_valid_type rear_passenger_door_open_is_valid;
      typedef bool _hood_open_type;
      _hood_open_type hood_open;
      typedef bool _hood_open_is_valid_type;
      _hood_open_is_valid_type hood_open_is_valid;
      typedef bool _trunk_open_type;
      _trunk_open_type trunk_open;
      typedef bool _trunk_open_is_valid_type;
      _trunk_open_is_valid_type trunk_open_is_valid;
      typedef bool _fuel_door_open_type;
      _fuel_door_open_type fuel_door_open;
      typedef bool _fuel_door_open_is_valid_type;
      _fuel_door_open_is_valid_type fuel_door_open_is_valid;

    DoorRpt():
      header(),
      driver_door_open(0),
      driver_door_open_is_valid(0),
      passenger_door_open(0),
      passenger_door_open_is_valid(0),
      rear_driver_door_open(0),
      rear_driver_door_open_is_valid(0),
      rear_passenger_door_open(0),
      rear_passenger_door_open_is_valid(0),
      hood_open(0),
      hood_open_is_valid(0),
      trunk_open(0),
      trunk_open_is_valid(0),
      fuel_door_open(0),
      fuel_door_open_is_valid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_driver_door_open;
      u_driver_door_open.real = this->driver_door_open;
      *(outbuffer + offset + 0) = (u_driver_door_open.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->driver_door_open);
      union {
        bool real;
        uint8_t base;
      } u_driver_door_open_is_valid;
      u_driver_door_open_is_valid.real = this->driver_door_open_is_valid;
      *(outbuffer + offset + 0) = (u_driver_door_open_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->driver_door_open_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_passenger_door_open;
      u_passenger_door_open.real = this->passenger_door_open;
      *(outbuffer + offset + 0) = (u_passenger_door_open.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->passenger_door_open);
      union {
        bool real;
        uint8_t base;
      } u_passenger_door_open_is_valid;
      u_passenger_door_open_is_valid.real = this->passenger_door_open_is_valid;
      *(outbuffer + offset + 0) = (u_passenger_door_open_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->passenger_door_open_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_rear_driver_door_open;
      u_rear_driver_door_open.real = this->rear_driver_door_open;
      *(outbuffer + offset + 0) = (u_rear_driver_door_open.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rear_driver_door_open);
      union {
        bool real;
        uint8_t base;
      } u_rear_driver_door_open_is_valid;
      u_rear_driver_door_open_is_valid.real = this->rear_driver_door_open_is_valid;
      *(outbuffer + offset + 0) = (u_rear_driver_door_open_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rear_driver_door_open_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_rear_passenger_door_open;
      u_rear_passenger_door_open.real = this->rear_passenger_door_open;
      *(outbuffer + offset + 0) = (u_rear_passenger_door_open.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rear_passenger_door_open);
      union {
        bool real;
        uint8_t base;
      } u_rear_passenger_door_open_is_valid;
      u_rear_passenger_door_open_is_valid.real = this->rear_passenger_door_open_is_valid;
      *(outbuffer + offset + 0) = (u_rear_passenger_door_open_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rear_passenger_door_open_is_valid);
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
      } u_hood_open_is_valid;
      u_hood_open_is_valid.real = this->hood_open_is_valid;
      *(outbuffer + offset + 0) = (u_hood_open_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->hood_open_is_valid);
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
      } u_trunk_open_is_valid;
      u_trunk_open_is_valid.real = this->trunk_open_is_valid;
      *(outbuffer + offset + 0) = (u_trunk_open_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->trunk_open_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_fuel_door_open;
      u_fuel_door_open.real = this->fuel_door_open;
      *(outbuffer + offset + 0) = (u_fuel_door_open.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fuel_door_open);
      union {
        bool real;
        uint8_t base;
      } u_fuel_door_open_is_valid;
      u_fuel_door_open_is_valid.real = this->fuel_door_open_is_valid;
      *(outbuffer + offset + 0) = (u_fuel_door_open_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fuel_door_open_is_valid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_driver_door_open;
      u_driver_door_open.base = 0;
      u_driver_door_open.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->driver_door_open = u_driver_door_open.real;
      offset += sizeof(this->driver_door_open);
      union {
        bool real;
        uint8_t base;
      } u_driver_door_open_is_valid;
      u_driver_door_open_is_valid.base = 0;
      u_driver_door_open_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->driver_door_open_is_valid = u_driver_door_open_is_valid.real;
      offset += sizeof(this->driver_door_open_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_passenger_door_open;
      u_passenger_door_open.base = 0;
      u_passenger_door_open.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->passenger_door_open = u_passenger_door_open.real;
      offset += sizeof(this->passenger_door_open);
      union {
        bool real;
        uint8_t base;
      } u_passenger_door_open_is_valid;
      u_passenger_door_open_is_valid.base = 0;
      u_passenger_door_open_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->passenger_door_open_is_valid = u_passenger_door_open_is_valid.real;
      offset += sizeof(this->passenger_door_open_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_rear_driver_door_open;
      u_rear_driver_door_open.base = 0;
      u_rear_driver_door_open.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rear_driver_door_open = u_rear_driver_door_open.real;
      offset += sizeof(this->rear_driver_door_open);
      union {
        bool real;
        uint8_t base;
      } u_rear_driver_door_open_is_valid;
      u_rear_driver_door_open_is_valid.base = 0;
      u_rear_driver_door_open_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rear_driver_door_open_is_valid = u_rear_driver_door_open_is_valid.real;
      offset += sizeof(this->rear_driver_door_open_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_rear_passenger_door_open;
      u_rear_passenger_door_open.base = 0;
      u_rear_passenger_door_open.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rear_passenger_door_open = u_rear_passenger_door_open.real;
      offset += sizeof(this->rear_passenger_door_open);
      union {
        bool real;
        uint8_t base;
      } u_rear_passenger_door_open_is_valid;
      u_rear_passenger_door_open_is_valid.base = 0;
      u_rear_passenger_door_open_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rear_passenger_door_open_is_valid = u_rear_passenger_door_open_is_valid.real;
      offset += sizeof(this->rear_passenger_door_open_is_valid);
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
      } u_hood_open_is_valid;
      u_hood_open_is_valid.base = 0;
      u_hood_open_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->hood_open_is_valid = u_hood_open_is_valid.real;
      offset += sizeof(this->hood_open_is_valid);
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
      } u_trunk_open_is_valid;
      u_trunk_open_is_valid.base = 0;
      u_trunk_open_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->trunk_open_is_valid = u_trunk_open_is_valid.real;
      offset += sizeof(this->trunk_open_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_fuel_door_open;
      u_fuel_door_open.base = 0;
      u_fuel_door_open.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fuel_door_open = u_fuel_door_open.real;
      offset += sizeof(this->fuel_door_open);
      union {
        bool real;
        uint8_t base;
      } u_fuel_door_open_is_valid;
      u_fuel_door_open_is_valid.base = 0;
      u_fuel_door_open_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fuel_door_open_is_valid = u_fuel_door_open_is_valid.real;
      offset += sizeof(this->fuel_door_open_is_valid);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/DoorRpt"; };
    const char * getMD5(){ return "a2ffa235d04f8d5d5e349a5d9caead12"; };

  };

}
#endif