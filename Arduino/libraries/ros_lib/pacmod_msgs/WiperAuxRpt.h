#ifndef _ROS_pacmod_msgs_WiperAuxRpt_h
#define _ROS_pacmod_msgs_WiperAuxRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class WiperAuxRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _front_wiping_type;
      _front_wiping_type front_wiping;
      typedef bool _front_wiping_is_valid_type;
      _front_wiping_is_valid_type front_wiping_is_valid;
      typedef bool _front_spraying_type;
      _front_spraying_type front_spraying;
      typedef bool _front_spraying_is_valid_type;
      _front_spraying_is_valid_type front_spraying_is_valid;
      typedef bool _rear_wiping_type;
      _rear_wiping_type rear_wiping;
      typedef bool _rear_wiping_is_valid_type;
      _rear_wiping_is_valid_type rear_wiping_is_valid;
      typedef bool _rear_spraying_type;
      _rear_spraying_type rear_spraying;
      typedef bool _rear_spraying_is_valid_type;
      _rear_spraying_is_valid_type rear_spraying_is_valid;
      typedef bool _spray_near_empty_type;
      _spray_near_empty_type spray_near_empty;
      typedef bool _spray_near_empty_is_valid_type;
      _spray_near_empty_is_valid_type spray_near_empty_is_valid;
      typedef bool _spray_empty_type;
      _spray_empty_type spray_empty;
      typedef bool _spray_empty_is_valid_type;
      _spray_empty_is_valid_type spray_empty_is_valid;

    WiperAuxRpt():
      header(),
      front_wiping(0),
      front_wiping_is_valid(0),
      front_spraying(0),
      front_spraying_is_valid(0),
      rear_wiping(0),
      rear_wiping_is_valid(0),
      rear_spraying(0),
      rear_spraying_is_valid(0),
      spray_near_empty(0),
      spray_near_empty_is_valid(0),
      spray_empty(0),
      spray_empty_is_valid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_front_wiping;
      u_front_wiping.real = this->front_wiping;
      *(outbuffer + offset + 0) = (u_front_wiping.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->front_wiping);
      union {
        bool real;
        uint8_t base;
      } u_front_wiping_is_valid;
      u_front_wiping_is_valid.real = this->front_wiping_is_valid;
      *(outbuffer + offset + 0) = (u_front_wiping_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->front_wiping_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_front_spraying;
      u_front_spraying.real = this->front_spraying;
      *(outbuffer + offset + 0) = (u_front_spraying.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->front_spraying);
      union {
        bool real;
        uint8_t base;
      } u_front_spraying_is_valid;
      u_front_spraying_is_valid.real = this->front_spraying_is_valid;
      *(outbuffer + offset + 0) = (u_front_spraying_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->front_spraying_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_rear_wiping;
      u_rear_wiping.real = this->rear_wiping;
      *(outbuffer + offset + 0) = (u_rear_wiping.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rear_wiping);
      union {
        bool real;
        uint8_t base;
      } u_rear_wiping_is_valid;
      u_rear_wiping_is_valid.real = this->rear_wiping_is_valid;
      *(outbuffer + offset + 0) = (u_rear_wiping_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rear_wiping_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_rear_spraying;
      u_rear_spraying.real = this->rear_spraying;
      *(outbuffer + offset + 0) = (u_rear_spraying.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rear_spraying);
      union {
        bool real;
        uint8_t base;
      } u_rear_spraying_is_valid;
      u_rear_spraying_is_valid.real = this->rear_spraying_is_valid;
      *(outbuffer + offset + 0) = (u_rear_spraying_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rear_spraying_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_spray_near_empty;
      u_spray_near_empty.real = this->spray_near_empty;
      *(outbuffer + offset + 0) = (u_spray_near_empty.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->spray_near_empty);
      union {
        bool real;
        uint8_t base;
      } u_spray_near_empty_is_valid;
      u_spray_near_empty_is_valid.real = this->spray_near_empty_is_valid;
      *(outbuffer + offset + 0) = (u_spray_near_empty_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->spray_near_empty_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_spray_empty;
      u_spray_empty.real = this->spray_empty;
      *(outbuffer + offset + 0) = (u_spray_empty.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->spray_empty);
      union {
        bool real;
        uint8_t base;
      } u_spray_empty_is_valid;
      u_spray_empty_is_valid.real = this->spray_empty_is_valid;
      *(outbuffer + offset + 0) = (u_spray_empty_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->spray_empty_is_valid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_front_wiping;
      u_front_wiping.base = 0;
      u_front_wiping.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->front_wiping = u_front_wiping.real;
      offset += sizeof(this->front_wiping);
      union {
        bool real;
        uint8_t base;
      } u_front_wiping_is_valid;
      u_front_wiping_is_valid.base = 0;
      u_front_wiping_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->front_wiping_is_valid = u_front_wiping_is_valid.real;
      offset += sizeof(this->front_wiping_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_front_spraying;
      u_front_spraying.base = 0;
      u_front_spraying.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->front_spraying = u_front_spraying.real;
      offset += sizeof(this->front_spraying);
      union {
        bool real;
        uint8_t base;
      } u_front_spraying_is_valid;
      u_front_spraying_is_valid.base = 0;
      u_front_spraying_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->front_spraying_is_valid = u_front_spraying_is_valid.real;
      offset += sizeof(this->front_spraying_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_rear_wiping;
      u_rear_wiping.base = 0;
      u_rear_wiping.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rear_wiping = u_rear_wiping.real;
      offset += sizeof(this->rear_wiping);
      union {
        bool real;
        uint8_t base;
      } u_rear_wiping_is_valid;
      u_rear_wiping_is_valid.base = 0;
      u_rear_wiping_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rear_wiping_is_valid = u_rear_wiping_is_valid.real;
      offset += sizeof(this->rear_wiping_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_rear_spraying;
      u_rear_spraying.base = 0;
      u_rear_spraying.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rear_spraying = u_rear_spraying.real;
      offset += sizeof(this->rear_spraying);
      union {
        bool real;
        uint8_t base;
      } u_rear_spraying_is_valid;
      u_rear_spraying_is_valid.base = 0;
      u_rear_spraying_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rear_spraying_is_valid = u_rear_spraying_is_valid.real;
      offset += sizeof(this->rear_spraying_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_spray_near_empty;
      u_spray_near_empty.base = 0;
      u_spray_near_empty.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->spray_near_empty = u_spray_near_empty.real;
      offset += sizeof(this->spray_near_empty);
      union {
        bool real;
        uint8_t base;
      } u_spray_near_empty_is_valid;
      u_spray_near_empty_is_valid.base = 0;
      u_spray_near_empty_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->spray_near_empty_is_valid = u_spray_near_empty_is_valid.real;
      offset += sizeof(this->spray_near_empty_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_spray_empty;
      u_spray_empty.base = 0;
      u_spray_empty.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->spray_empty = u_spray_empty.real;
      offset += sizeof(this->spray_empty);
      union {
        bool real;
        uint8_t base;
      } u_spray_empty_is_valid;
      u_spray_empty_is_valid.base = 0;
      u_spray_empty_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->spray_empty_is_valid = u_spray_empty_is_valid.real;
      offset += sizeof(this->spray_empty_is_valid);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/WiperAuxRpt"; };
    const char * getMD5(){ return "663ea0989c9628effd21f08690caa7d1"; };

  };

}
#endif