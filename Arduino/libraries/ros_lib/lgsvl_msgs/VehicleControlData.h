#ifndef _ROS_lgsvl_msgs_VehicleControlData_h
#define _ROS_lgsvl_msgs_VehicleControlData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace lgsvl_msgs
{

  class VehicleControlData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _acceleration_pct_type;
      _acceleration_pct_type acceleration_pct;
      typedef float _braking_pct_type;
      _braking_pct_type braking_pct;
      typedef float _target_wheel_angle_type;
      _target_wheel_angle_type target_wheel_angle;
      typedef float _target_wheel_angular_rate_type;
      _target_wheel_angular_rate_type target_wheel_angular_rate;
      typedef uint8_t _target_gear_type;
      _target_gear_type target_gear;
      enum { GEAR_NEUTRAL =  0 };
      enum { GEAR_DRIVE =  1 };
      enum { GEAR_REVERSE =  2 };
      enum { GEAR_PARKING =  3 };
      enum { GEAR_LOW =  4 };

    VehicleControlData():
      header(),
      acceleration_pct(0),
      braking_pct(0),
      target_wheel_angle(0),
      target_wheel_angular_rate(0),
      target_gear(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_acceleration_pct;
      u_acceleration_pct.real = this->acceleration_pct;
      *(outbuffer + offset + 0) = (u_acceleration_pct.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acceleration_pct.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acceleration_pct.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acceleration_pct.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acceleration_pct);
      union {
        float real;
        uint32_t base;
      } u_braking_pct;
      u_braking_pct.real = this->braking_pct;
      *(outbuffer + offset + 0) = (u_braking_pct.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_braking_pct.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_braking_pct.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_braking_pct.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->braking_pct);
      union {
        float real;
        uint32_t base;
      } u_target_wheel_angle;
      u_target_wheel_angle.real = this->target_wheel_angle;
      *(outbuffer + offset + 0) = (u_target_wheel_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_wheel_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_target_wheel_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_target_wheel_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_wheel_angle);
      union {
        float real;
        uint32_t base;
      } u_target_wheel_angular_rate;
      u_target_wheel_angular_rate.real = this->target_wheel_angular_rate;
      *(outbuffer + offset + 0) = (u_target_wheel_angular_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_wheel_angular_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_target_wheel_angular_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_target_wheel_angular_rate.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_wheel_angular_rate);
      *(outbuffer + offset + 0) = (this->target_gear >> (8 * 0)) & 0xFF;
      offset += sizeof(this->target_gear);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_acceleration_pct;
      u_acceleration_pct.base = 0;
      u_acceleration_pct.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acceleration_pct.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acceleration_pct.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acceleration_pct.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->acceleration_pct = u_acceleration_pct.real;
      offset += sizeof(this->acceleration_pct);
      union {
        float real;
        uint32_t base;
      } u_braking_pct;
      u_braking_pct.base = 0;
      u_braking_pct.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_braking_pct.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_braking_pct.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_braking_pct.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->braking_pct = u_braking_pct.real;
      offset += sizeof(this->braking_pct);
      union {
        float real;
        uint32_t base;
      } u_target_wheel_angle;
      u_target_wheel_angle.base = 0;
      u_target_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_target_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_target_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->target_wheel_angle = u_target_wheel_angle.real;
      offset += sizeof(this->target_wheel_angle);
      union {
        float real;
        uint32_t base;
      } u_target_wheel_angular_rate;
      u_target_wheel_angular_rate.base = 0;
      u_target_wheel_angular_rate.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_wheel_angular_rate.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_target_wheel_angular_rate.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_target_wheel_angular_rate.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->target_wheel_angular_rate = u_target_wheel_angular_rate.real;
      offset += sizeof(this->target_wheel_angular_rate);
      this->target_gear =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->target_gear);
     return offset;
    }

    const char * getType(){ return "lgsvl_msgs/VehicleControlData"; };
    const char * getMD5(){ return "d20f5929de67f38ac323dce02f59b3d4"; };

  };

}
#endif