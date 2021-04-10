#ifndef _ROS_autoware_msgs_VscanTracked_h
#define _ROS_autoware_msgs_VscanTracked_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"
#include "autoware_msgs/GeometricRectangle.h"

namespace autoware_msgs
{

  class VscanTracked : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _position_type;
      _position_type position;
      typedef float _orientation_type;
      _orientation_type orientation;
      typedef float _velocity_type;
      _velocity_type velocity;
      typedef autoware_msgs::GeometricRectangle _geo_rect_type;
      _geo_rect_type geo_rect;

    VscanTracked():
      position(),
      orientation(0),
      velocity(0),
      geo_rect()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->position.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_orientation;
      u_orientation.real = this->orientation;
      *(outbuffer + offset + 0) = (u_orientation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_orientation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_orientation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_orientation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->orientation);
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
      offset += this->geo_rect.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->position.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_orientation;
      u_orientation.base = 0;
      u_orientation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_orientation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_orientation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_orientation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->orientation = u_orientation.real;
      offset += sizeof(this->orientation);
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
      offset += this->geo_rect.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/VscanTracked"; };
    const char * getMD5(){ return "bff5c0a61020da26ef210837bea359b1"; };

  };

}
#endif