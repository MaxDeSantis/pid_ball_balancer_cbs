#ifndef _ROS_pacmod_msgs_EngineRpt_h
#define _ROS_pacmod_msgs_EngineRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class EngineRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _engine_speed_type;
      _engine_speed_type engine_speed;
      typedef float _engine_torque_type;
      _engine_torque_type engine_torque;
      typedef int16_t _engine_coolant_temp_type;
      _engine_coolant_temp_type engine_coolant_temp;
      typedef bool _engine_speed_avail_type;
      _engine_speed_avail_type engine_speed_avail;
      typedef bool _engine_torque_avail_type;
      _engine_torque_avail_type engine_torque_avail;
      typedef bool _engine_coolant_temp_avail_type;
      _engine_coolant_temp_avail_type engine_coolant_temp_avail;

    EngineRpt():
      header(),
      engine_speed(0),
      engine_torque(0),
      engine_coolant_temp(0),
      engine_speed_avail(0),
      engine_torque_avail(0),
      engine_coolant_temp_avail(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->engine_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->engine_torque);
      union {
        int16_t real;
        uint16_t base;
      } u_engine_coolant_temp;
      u_engine_coolant_temp.real = this->engine_coolant_temp;
      *(outbuffer + offset + 0) = (u_engine_coolant_temp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_engine_coolant_temp.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->engine_coolant_temp);
      union {
        bool real;
        uint8_t base;
      } u_engine_speed_avail;
      u_engine_speed_avail.real = this->engine_speed_avail;
      *(outbuffer + offset + 0) = (u_engine_speed_avail.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->engine_speed_avail);
      union {
        bool real;
        uint8_t base;
      } u_engine_torque_avail;
      u_engine_torque_avail.real = this->engine_torque_avail;
      *(outbuffer + offset + 0) = (u_engine_torque_avail.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->engine_torque_avail);
      union {
        bool real;
        uint8_t base;
      } u_engine_coolant_temp_avail;
      u_engine_coolant_temp_avail.real = this->engine_coolant_temp_avail;
      *(outbuffer + offset + 0) = (u_engine_coolant_temp_avail.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->engine_coolant_temp_avail);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->engine_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->engine_torque));
      union {
        int16_t real;
        uint16_t base;
      } u_engine_coolant_temp;
      u_engine_coolant_temp.base = 0;
      u_engine_coolant_temp.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_engine_coolant_temp.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->engine_coolant_temp = u_engine_coolant_temp.real;
      offset += sizeof(this->engine_coolant_temp);
      union {
        bool real;
        uint8_t base;
      } u_engine_speed_avail;
      u_engine_speed_avail.base = 0;
      u_engine_speed_avail.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->engine_speed_avail = u_engine_speed_avail.real;
      offset += sizeof(this->engine_speed_avail);
      union {
        bool real;
        uint8_t base;
      } u_engine_torque_avail;
      u_engine_torque_avail.base = 0;
      u_engine_torque_avail.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->engine_torque_avail = u_engine_torque_avail.real;
      offset += sizeof(this->engine_torque_avail);
      union {
        bool real;
        uint8_t base;
      } u_engine_coolant_temp_avail;
      u_engine_coolant_temp_avail.base = 0;
      u_engine_coolant_temp_avail.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->engine_coolant_temp_avail = u_engine_coolant_temp_avail.real;
      offset += sizeof(this->engine_coolant_temp_avail);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/EngineRpt"; };
    const char * getMD5(){ return "ce4743585f6b90cb725120aba6ddfafc"; };

  };

}
#endif