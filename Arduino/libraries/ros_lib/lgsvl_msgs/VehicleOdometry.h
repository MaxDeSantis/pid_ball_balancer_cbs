#ifndef _ROS_lgsvl_msgs_VehicleOdometry_h
#define _ROS_lgsvl_msgs_VehicleOdometry_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace lgsvl_msgs
{

  class VehicleOdometry : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _velocity_type;
      _velocity_type velocity;
      typedef float _front_wheel_angle_type;
      _front_wheel_angle_type front_wheel_angle;
      typedef float _rear_wheel_angle_type;
      _rear_wheel_angle_type rear_wheel_angle;

    VehicleOdometry():
      header(),
      velocity(0),
      front_wheel_angle(0),
      rear_wheel_angle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.real = this->velocity;
      *(outbuffer + offset + 0) = (u_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity);
      union {
        float real;
        uint32_t base;
      } u_front_wheel_angle;
      u_front_wheel_angle.real = this->front_wheel_angle;
      *(outbuffer + offset + 0) = (u_front_wheel_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_front_wheel_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_front_wheel_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_front_wheel_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->front_wheel_angle);
      union {
        float real;
        uint32_t base;
      } u_rear_wheel_angle;
      u_rear_wheel_angle.real = this->rear_wheel_angle;
      *(outbuffer + offset + 0) = (u_rear_wheel_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rear_wheel_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rear_wheel_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rear_wheel_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rear_wheel_angle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.base = 0;
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity = u_velocity.real;
      offset += sizeof(this->velocity);
      union {
        float real;
        uint32_t base;
      } u_front_wheel_angle;
      u_front_wheel_angle.base = 0;
      u_front_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_front_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_front_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_front_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->front_wheel_angle = u_front_wheel_angle.real;
      offset += sizeof(this->front_wheel_angle);
      union {
        float real;
        uint32_t base;
      } u_rear_wheel_angle;
      u_rear_wheel_angle.base = 0;
      u_rear_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rear_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rear_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rear_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rear_wheel_angle = u_rear_wheel_angle.real;
      offset += sizeof(this->rear_wheel_angle);
     return offset;
    }

    const char * getType(){ return "lgsvl_msgs/VehicleOdometry"; };
    const char * getMD5(){ return "c14a75cb62b0432c46bae4f9370e8916"; };

  };

}
#endif