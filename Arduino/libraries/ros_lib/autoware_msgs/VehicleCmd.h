#ifndef _ROS_autoware_msgs_VehicleCmd_h
#define _ROS_autoware_msgs_VehicleCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_msgs/SteerCmd.h"
#include "autoware_msgs/AccelCmd.h"
#include "autoware_msgs/BrakeCmd.h"
#include "autoware_msgs/LampCmd.h"
#include "geometry_msgs/TwistStamped.h"
#include "autoware_msgs/ControlCommand.h"

namespace autoware_msgs
{

  class VehicleCmd : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef autoware_msgs::SteerCmd _steer_cmd_type;
      _steer_cmd_type steer_cmd;
      typedef autoware_msgs::AccelCmd _accel_cmd_type;
      _accel_cmd_type accel_cmd;
      typedef autoware_msgs::BrakeCmd _brake_cmd_type;
      _brake_cmd_type brake_cmd;
      typedef autoware_msgs::LampCmd _lamp_cmd_type;
      _lamp_cmd_type lamp_cmd;
      typedef int32_t _gear_type;
      _gear_type gear;
      typedef int32_t _mode_type;
      _mode_type mode;
      typedef geometry_msgs::TwistStamped _twist_cmd_type;
      _twist_cmd_type twist_cmd;
      typedef autoware_msgs::ControlCommand _ctrl_cmd_type;
      _ctrl_cmd_type ctrl_cmd;
      typedef int32_t _emergency_type;
      _emergency_type emergency;

    VehicleCmd():
      header(),
      steer_cmd(),
      accel_cmd(),
      brake_cmd(),
      lamp_cmd(),
      gear(0),
      mode(0),
      twist_cmd(),
      ctrl_cmd(),
      emergency(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->steer_cmd.serialize(outbuffer + offset);
      offset += this->accel_cmd.serialize(outbuffer + offset);
      offset += this->brake_cmd.serialize(outbuffer + offset);
      offset += this->lamp_cmd.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_gear;
      u_gear.real = this->gear;
      *(outbuffer + offset + 0) = (u_gear.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gear.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gear.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gear.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gear);
      union {
        int32_t real;
        uint32_t base;
      } u_mode;
      u_mode.real = this->mode;
      *(outbuffer + offset + 0) = (u_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mode);
      offset += this->twist_cmd.serialize(outbuffer + offset);
      offset += this->ctrl_cmd.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_emergency;
      u_emergency.real = this->emergency;
      *(outbuffer + offset + 0) = (u_emergency.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_emergency.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_emergency.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_emergency.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->emergency);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->steer_cmd.deserialize(inbuffer + offset);
      offset += this->accel_cmd.deserialize(inbuffer + offset);
      offset += this->brake_cmd.deserialize(inbuffer + offset);
      offset += this->lamp_cmd.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_gear;
      u_gear.base = 0;
      u_gear.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gear.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gear.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gear.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gear = u_gear.real;
      offset += sizeof(this->gear);
      union {
        int32_t real;
        uint32_t base;
      } u_mode;
      u_mode.base = 0;
      u_mode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mode = u_mode.real;
      offset += sizeof(this->mode);
      offset += this->twist_cmd.deserialize(inbuffer + offset);
      offset += this->ctrl_cmd.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_emergency;
      u_emergency.base = 0;
      u_emergency.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_emergency.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_emergency.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_emergency.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->emergency = u_emergency.real;
      offset += sizeof(this->emergency);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/VehicleCmd"; };
    const char * getMD5(){ return "153301368e83526f24c12f8e8cddf283"; };

  };

}
#endif