#ifndef _ROS_pacmod_msgs_OccupancyRpt_h
#define _ROS_pacmod_msgs_OccupancyRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class OccupancyRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _driver_seat_occupied_type;
      _driver_seat_occupied_type driver_seat_occupied;
      typedef bool _driver_seat_occupied_is_valid_type;
      _driver_seat_occupied_is_valid_type driver_seat_occupied_is_valid;
      typedef bool _passenger_seat_occupied_type;
      _passenger_seat_occupied_type passenger_seat_occupied;
      typedef bool _passenger_seat_occupied_is_valid_type;
      _passenger_seat_occupied_is_valid_type passenger_seat_occupied_is_valid;
      typedef bool _rear_seat_occupied_type;
      _rear_seat_occupied_type rear_seat_occupied;
      typedef bool _rear_seat_occupied_is_valid_type;
      _rear_seat_occupied_is_valid_type rear_seat_occupied_is_valid;
      typedef bool _driver_seatbelt_buckled_type;
      _driver_seatbelt_buckled_type driver_seatbelt_buckled;
      typedef bool _driver_seatbelt_buckled_is_valid_type;
      _driver_seatbelt_buckled_is_valid_type driver_seatbelt_buckled_is_valid;
      typedef bool _passenger_seatbelt_buckled_type;
      _passenger_seatbelt_buckled_type passenger_seatbelt_buckled;
      typedef bool _passenger_seatbelt_buckled_is_valid_type;
      _passenger_seatbelt_buckled_is_valid_type passenger_seatbelt_buckled_is_valid;
      typedef bool _rear_seatbelt_buckled_type;
      _rear_seatbelt_buckled_type rear_seatbelt_buckled;
      typedef bool _rear_seatbelt_buckled_is_valid_type;
      _rear_seatbelt_buckled_is_valid_type rear_seatbelt_buckled_is_valid;

    OccupancyRpt():
      header(),
      driver_seat_occupied(0),
      driver_seat_occupied_is_valid(0),
      passenger_seat_occupied(0),
      passenger_seat_occupied_is_valid(0),
      rear_seat_occupied(0),
      rear_seat_occupied_is_valid(0),
      driver_seatbelt_buckled(0),
      driver_seatbelt_buckled_is_valid(0),
      passenger_seatbelt_buckled(0),
      passenger_seatbelt_buckled_is_valid(0),
      rear_seatbelt_buckled(0),
      rear_seatbelt_buckled_is_valid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_driver_seat_occupied;
      u_driver_seat_occupied.real = this->driver_seat_occupied;
      *(outbuffer + offset + 0) = (u_driver_seat_occupied.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->driver_seat_occupied);
      union {
        bool real;
        uint8_t base;
      } u_driver_seat_occupied_is_valid;
      u_driver_seat_occupied_is_valid.real = this->driver_seat_occupied_is_valid;
      *(outbuffer + offset + 0) = (u_driver_seat_occupied_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->driver_seat_occupied_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_passenger_seat_occupied;
      u_passenger_seat_occupied.real = this->passenger_seat_occupied;
      *(outbuffer + offset + 0) = (u_passenger_seat_occupied.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->passenger_seat_occupied);
      union {
        bool real;
        uint8_t base;
      } u_passenger_seat_occupied_is_valid;
      u_passenger_seat_occupied_is_valid.real = this->passenger_seat_occupied_is_valid;
      *(outbuffer + offset + 0) = (u_passenger_seat_occupied_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->passenger_seat_occupied_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_rear_seat_occupied;
      u_rear_seat_occupied.real = this->rear_seat_occupied;
      *(outbuffer + offset + 0) = (u_rear_seat_occupied.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rear_seat_occupied);
      union {
        bool real;
        uint8_t base;
      } u_rear_seat_occupied_is_valid;
      u_rear_seat_occupied_is_valid.real = this->rear_seat_occupied_is_valid;
      *(outbuffer + offset + 0) = (u_rear_seat_occupied_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rear_seat_occupied_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_driver_seatbelt_buckled;
      u_driver_seatbelt_buckled.real = this->driver_seatbelt_buckled;
      *(outbuffer + offset + 0) = (u_driver_seatbelt_buckled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->driver_seatbelt_buckled);
      union {
        bool real;
        uint8_t base;
      } u_driver_seatbelt_buckled_is_valid;
      u_driver_seatbelt_buckled_is_valid.real = this->driver_seatbelt_buckled_is_valid;
      *(outbuffer + offset + 0) = (u_driver_seatbelt_buckled_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->driver_seatbelt_buckled_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_passenger_seatbelt_buckled;
      u_passenger_seatbelt_buckled.real = this->passenger_seatbelt_buckled;
      *(outbuffer + offset + 0) = (u_passenger_seatbelt_buckled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->passenger_seatbelt_buckled);
      union {
        bool real;
        uint8_t base;
      } u_passenger_seatbelt_buckled_is_valid;
      u_passenger_seatbelt_buckled_is_valid.real = this->passenger_seatbelt_buckled_is_valid;
      *(outbuffer + offset + 0) = (u_passenger_seatbelt_buckled_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->passenger_seatbelt_buckled_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_rear_seatbelt_buckled;
      u_rear_seatbelt_buckled.real = this->rear_seatbelt_buckled;
      *(outbuffer + offset + 0) = (u_rear_seatbelt_buckled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rear_seatbelt_buckled);
      union {
        bool real;
        uint8_t base;
      } u_rear_seatbelt_buckled_is_valid;
      u_rear_seatbelt_buckled_is_valid.real = this->rear_seatbelt_buckled_is_valid;
      *(outbuffer + offset + 0) = (u_rear_seatbelt_buckled_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rear_seatbelt_buckled_is_valid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_driver_seat_occupied;
      u_driver_seat_occupied.base = 0;
      u_driver_seat_occupied.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->driver_seat_occupied = u_driver_seat_occupied.real;
      offset += sizeof(this->driver_seat_occupied);
      union {
        bool real;
        uint8_t base;
      } u_driver_seat_occupied_is_valid;
      u_driver_seat_occupied_is_valid.base = 0;
      u_driver_seat_occupied_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->driver_seat_occupied_is_valid = u_driver_seat_occupied_is_valid.real;
      offset += sizeof(this->driver_seat_occupied_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_passenger_seat_occupied;
      u_passenger_seat_occupied.base = 0;
      u_passenger_seat_occupied.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->passenger_seat_occupied = u_passenger_seat_occupied.real;
      offset += sizeof(this->passenger_seat_occupied);
      union {
        bool real;
        uint8_t base;
      } u_passenger_seat_occupied_is_valid;
      u_passenger_seat_occupied_is_valid.base = 0;
      u_passenger_seat_occupied_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->passenger_seat_occupied_is_valid = u_passenger_seat_occupied_is_valid.real;
      offset += sizeof(this->passenger_seat_occupied_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_rear_seat_occupied;
      u_rear_seat_occupied.base = 0;
      u_rear_seat_occupied.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rear_seat_occupied = u_rear_seat_occupied.real;
      offset += sizeof(this->rear_seat_occupied);
      union {
        bool real;
        uint8_t base;
      } u_rear_seat_occupied_is_valid;
      u_rear_seat_occupied_is_valid.base = 0;
      u_rear_seat_occupied_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rear_seat_occupied_is_valid = u_rear_seat_occupied_is_valid.real;
      offset += sizeof(this->rear_seat_occupied_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_driver_seatbelt_buckled;
      u_driver_seatbelt_buckled.base = 0;
      u_driver_seatbelt_buckled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->driver_seatbelt_buckled = u_driver_seatbelt_buckled.real;
      offset += sizeof(this->driver_seatbelt_buckled);
      union {
        bool real;
        uint8_t base;
      } u_driver_seatbelt_buckled_is_valid;
      u_driver_seatbelt_buckled_is_valid.base = 0;
      u_driver_seatbelt_buckled_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->driver_seatbelt_buckled_is_valid = u_driver_seatbelt_buckled_is_valid.real;
      offset += sizeof(this->driver_seatbelt_buckled_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_passenger_seatbelt_buckled;
      u_passenger_seatbelt_buckled.base = 0;
      u_passenger_seatbelt_buckled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->passenger_seatbelt_buckled = u_passenger_seatbelt_buckled.real;
      offset += sizeof(this->passenger_seatbelt_buckled);
      union {
        bool real;
        uint8_t base;
      } u_passenger_seatbelt_buckled_is_valid;
      u_passenger_seatbelt_buckled_is_valid.base = 0;
      u_passenger_seatbelt_buckled_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->passenger_seatbelt_buckled_is_valid = u_passenger_seatbelt_buckled_is_valid.real;
      offset += sizeof(this->passenger_seatbelt_buckled_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_rear_seatbelt_buckled;
      u_rear_seatbelt_buckled.base = 0;
      u_rear_seatbelt_buckled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rear_seatbelt_buckled = u_rear_seatbelt_buckled.real;
      offset += sizeof(this->rear_seatbelt_buckled);
      union {
        bool real;
        uint8_t base;
      } u_rear_seatbelt_buckled_is_valid;
      u_rear_seatbelt_buckled_is_valid.base = 0;
      u_rear_seatbelt_buckled_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rear_seatbelt_buckled_is_valid = u_rear_seatbelt_buckled_is_valid.real;
      offset += sizeof(this->rear_seatbelt_buckled_is_valid);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/OccupancyRpt"; };
    const char * getMD5(){ return "0721e1bb580b55ac7fd96411e39adf3e"; };

  };

}
#endif