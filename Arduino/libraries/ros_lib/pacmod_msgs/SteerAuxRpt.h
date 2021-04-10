#ifndef _ROS_pacmod_msgs_SteerAuxRpt_h
#define _ROS_pacmod_msgs_SteerAuxRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class SteerAuxRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _raw_position_type;
      _raw_position_type raw_position;
      typedef bool _raw_position_is_valid_type;
      _raw_position_is_valid_type raw_position_is_valid;
      typedef float _raw_torque_type;
      _raw_torque_type raw_torque;
      typedef bool _raw_torque_is_valid_type;
      _raw_torque_is_valid_type raw_torque_is_valid;
      typedef float _rotation_rate_type;
      _rotation_rate_type rotation_rate;
      typedef bool _rotation_rate_is_valid_type;
      _rotation_rate_is_valid_type rotation_rate_is_valid;
      typedef bool _user_interaction_type;
      _user_interaction_type user_interaction;
      typedef bool _user_interaction_is_valid_type;
      _user_interaction_is_valid_type user_interaction_is_valid;

    SteerAuxRpt():
      header(),
      raw_position(0),
      raw_position_is_valid(0),
      raw_torque(0),
      raw_torque_is_valid(0),
      rotation_rate(0),
      rotation_rate_is_valid(0),
      user_interaction(0),
      user_interaction_is_valid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->raw_position);
      union {
        bool real;
        uint8_t base;
      } u_raw_position_is_valid;
      u_raw_position_is_valid.real = this->raw_position_is_valid;
      *(outbuffer + offset + 0) = (u_raw_position_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->raw_position_is_valid);
      offset += serializeAvrFloat64(outbuffer + offset, this->raw_torque);
      union {
        bool real;
        uint8_t base;
      } u_raw_torque_is_valid;
      u_raw_torque_is_valid.real = this->raw_torque_is_valid;
      *(outbuffer + offset + 0) = (u_raw_torque_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->raw_torque_is_valid);
      offset += serializeAvrFloat64(outbuffer + offset, this->rotation_rate);
      union {
        bool real;
        uint8_t base;
      } u_rotation_rate_is_valid;
      u_rotation_rate_is_valid.real = this->rotation_rate_is_valid;
      *(outbuffer + offset + 0) = (u_rotation_rate_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rotation_rate_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_user_interaction;
      u_user_interaction.real = this->user_interaction;
      *(outbuffer + offset + 0) = (u_user_interaction.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->user_interaction);
      union {
        bool real;
        uint8_t base;
      } u_user_interaction_is_valid;
      u_user_interaction_is_valid.real = this->user_interaction_is_valid;
      *(outbuffer + offset + 0) = (u_user_interaction_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->user_interaction_is_valid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->raw_position));
      union {
        bool real;
        uint8_t base;
      } u_raw_position_is_valid;
      u_raw_position_is_valid.base = 0;
      u_raw_position_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->raw_position_is_valid = u_raw_position_is_valid.real;
      offset += sizeof(this->raw_position_is_valid);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->raw_torque));
      union {
        bool real;
        uint8_t base;
      } u_raw_torque_is_valid;
      u_raw_torque_is_valid.base = 0;
      u_raw_torque_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->raw_torque_is_valid = u_raw_torque_is_valid.real;
      offset += sizeof(this->raw_torque_is_valid);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rotation_rate));
      union {
        bool real;
        uint8_t base;
      } u_rotation_rate_is_valid;
      u_rotation_rate_is_valid.base = 0;
      u_rotation_rate_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rotation_rate_is_valid = u_rotation_rate_is_valid.real;
      offset += sizeof(this->rotation_rate_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_user_interaction;
      u_user_interaction.base = 0;
      u_user_interaction.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->user_interaction = u_user_interaction.real;
      offset += sizeof(this->user_interaction);
      union {
        bool real;
        uint8_t base;
      } u_user_interaction_is_valid;
      u_user_interaction_is_valid.base = 0;
      u_user_interaction_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->user_interaction_is_valid = u_user_interaction_is_valid.real;
      offset += sizeof(this->user_interaction_is_valid);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/SteerAuxRpt"; };
    const char * getMD5(){ return "64ab1937ad919cdc25271e7f81c721e2"; };

  };

}
#endif