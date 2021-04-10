#ifndef _ROS_pacmod_msgs_GlobalRpt_h
#define _ROS_pacmod_msgs_GlobalRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class GlobalRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _enabled_type;
      _enabled_type enabled;
      typedef bool _override_active_type;
      _override_active_type override_active;
      typedef bool _fault_active_type;
      _fault_active_type fault_active;
      typedef bool _config_fault_active_type;
      _config_fault_active_type config_fault_active;
      typedef bool _user_can_timeout_type;
      _user_can_timeout_type user_can_timeout;
      typedef bool _brake_can_timeout_type;
      _brake_can_timeout_type brake_can_timeout;
      typedef bool _steering_can_timeout_type;
      _steering_can_timeout_type steering_can_timeout;
      typedef bool _vehicle_can_timeout_type;
      _vehicle_can_timeout_type vehicle_can_timeout;
      typedef bool _subsystem_can_timeout_type;
      _subsystem_can_timeout_type subsystem_can_timeout;
      typedef bool _user_can_read_errors_type;
      _user_can_read_errors_type user_can_read_errors;

    GlobalRpt():
      header(),
      enabled(0),
      override_active(0),
      fault_active(0),
      config_fault_active(0),
      user_can_timeout(0),
      brake_can_timeout(0),
      steering_can_timeout(0),
      vehicle_can_timeout(0),
      subsystem_can_timeout(0),
      user_can_read_errors(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_enabled;
      u_enabled.real = this->enabled;
      *(outbuffer + offset + 0) = (u_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enabled);
      union {
        bool real;
        uint8_t base;
      } u_override_active;
      u_override_active.real = this->override_active;
      *(outbuffer + offset + 0) = (u_override_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->override_active);
      union {
        bool real;
        uint8_t base;
      } u_fault_active;
      u_fault_active.real = this->fault_active;
      *(outbuffer + offset + 0) = (u_fault_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fault_active);
      union {
        bool real;
        uint8_t base;
      } u_config_fault_active;
      u_config_fault_active.real = this->config_fault_active;
      *(outbuffer + offset + 0) = (u_config_fault_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->config_fault_active);
      union {
        bool real;
        uint8_t base;
      } u_user_can_timeout;
      u_user_can_timeout.real = this->user_can_timeout;
      *(outbuffer + offset + 0) = (u_user_can_timeout.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->user_can_timeout);
      union {
        bool real;
        uint8_t base;
      } u_brake_can_timeout;
      u_brake_can_timeout.real = this->brake_can_timeout;
      *(outbuffer + offset + 0) = (u_brake_can_timeout.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->brake_can_timeout);
      union {
        bool real;
        uint8_t base;
      } u_steering_can_timeout;
      u_steering_can_timeout.real = this->steering_can_timeout;
      *(outbuffer + offset + 0) = (u_steering_can_timeout.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->steering_can_timeout);
      union {
        bool real;
        uint8_t base;
      } u_vehicle_can_timeout;
      u_vehicle_can_timeout.real = this->vehicle_can_timeout;
      *(outbuffer + offset + 0) = (u_vehicle_can_timeout.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vehicle_can_timeout);
      union {
        bool real;
        uint8_t base;
      } u_subsystem_can_timeout;
      u_subsystem_can_timeout.real = this->subsystem_can_timeout;
      *(outbuffer + offset + 0) = (u_subsystem_can_timeout.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->subsystem_can_timeout);
      union {
        bool real;
        uint8_t base;
      } u_user_can_read_errors;
      u_user_can_read_errors.real = this->user_can_read_errors;
      *(outbuffer + offset + 0) = (u_user_can_read_errors.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->user_can_read_errors);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_enabled;
      u_enabled.base = 0;
      u_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enabled = u_enabled.real;
      offset += sizeof(this->enabled);
      union {
        bool real;
        uint8_t base;
      } u_override_active;
      u_override_active.base = 0;
      u_override_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->override_active = u_override_active.real;
      offset += sizeof(this->override_active);
      union {
        bool real;
        uint8_t base;
      } u_fault_active;
      u_fault_active.base = 0;
      u_fault_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fault_active = u_fault_active.real;
      offset += sizeof(this->fault_active);
      union {
        bool real;
        uint8_t base;
      } u_config_fault_active;
      u_config_fault_active.base = 0;
      u_config_fault_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->config_fault_active = u_config_fault_active.real;
      offset += sizeof(this->config_fault_active);
      union {
        bool real;
        uint8_t base;
      } u_user_can_timeout;
      u_user_can_timeout.base = 0;
      u_user_can_timeout.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->user_can_timeout = u_user_can_timeout.real;
      offset += sizeof(this->user_can_timeout);
      union {
        bool real;
        uint8_t base;
      } u_brake_can_timeout;
      u_brake_can_timeout.base = 0;
      u_brake_can_timeout.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->brake_can_timeout = u_brake_can_timeout.real;
      offset += sizeof(this->brake_can_timeout);
      union {
        bool real;
        uint8_t base;
      } u_steering_can_timeout;
      u_steering_can_timeout.base = 0;
      u_steering_can_timeout.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->steering_can_timeout = u_steering_can_timeout.real;
      offset += sizeof(this->steering_can_timeout);
      union {
        bool real;
        uint8_t base;
      } u_vehicle_can_timeout;
      u_vehicle_can_timeout.base = 0;
      u_vehicle_can_timeout.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->vehicle_can_timeout = u_vehicle_can_timeout.real;
      offset += sizeof(this->vehicle_can_timeout);
      union {
        bool real;
        uint8_t base;
      } u_subsystem_can_timeout;
      u_subsystem_can_timeout.base = 0;
      u_subsystem_can_timeout.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->subsystem_can_timeout = u_subsystem_can_timeout.real;
      offset += sizeof(this->subsystem_can_timeout);
      union {
        bool real;
        uint8_t base;
      } u_user_can_read_errors;
      u_user_can_read_errors.base = 0;
      u_user_can_read_errors.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->user_can_read_errors = u_user_can_read_errors.real;
      offset += sizeof(this->user_can_read_errors);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/GlobalRpt"; };
    const char * getMD5(){ return "e844957facaf4f6bfdea20a3ffdb048f"; };

  };

}
#endif