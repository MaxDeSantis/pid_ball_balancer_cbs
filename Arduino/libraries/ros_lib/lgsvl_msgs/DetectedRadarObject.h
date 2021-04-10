#ifndef _ROS_lgsvl_msgs_DetectedRadarObject_h
#define _ROS_lgsvl_msgs_DetectedRadarObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Point.h"

namespace lgsvl_msgs
{

  class DetectedRadarObject : public ros::Msg
  {
    public:
      typedef int32_t _id_type;
      _id_type id;
      typedef geometry_msgs::Vector3 _sensor_aim_type;
      _sensor_aim_type sensor_aim;
      typedef geometry_msgs::Vector3 _sensor_right_type;
      _sensor_right_type sensor_right;
      typedef geometry_msgs::Point _sensor_position_type;
      _sensor_position_type sensor_position;
      typedef geometry_msgs::Vector3 _sensor_velocity_type;
      _sensor_velocity_type sensor_velocity;
      typedef float _sensor_angle_type;
      _sensor_angle_type sensor_angle;
      typedef geometry_msgs::Point _object_position_type;
      _object_position_type object_position;
      typedef geometry_msgs::Vector3 _object_velocity_type;
      _object_velocity_type object_velocity;
      typedef geometry_msgs::Point _object_relative_position_type;
      _object_relative_position_type object_relative_position;
      typedef geometry_msgs::Vector3 _object_relative_velocity_type;
      _object_relative_velocity_type object_relative_velocity;
      typedef geometry_msgs::Vector3 _object_collider_size_type;
      _object_collider_size_type object_collider_size;
      typedef uint8_t _object_state_type;
      _object_state_type object_state;
      typedef bool _new_detection_type;
      _new_detection_type new_detection;
      enum { STATE_MOVING =  0 };
      enum { STATE_STATIONARY =  1 };

    DetectedRadarObject():
      id(0),
      sensor_aim(),
      sensor_right(),
      sensor_position(),
      sensor_velocity(),
      sensor_angle(0),
      object_position(),
      object_velocity(),
      object_relative_position(),
      object_relative_velocity(),
      object_collider_size(),
      object_state(0),
      new_detection(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      offset += this->sensor_aim.serialize(outbuffer + offset);
      offset += this->sensor_right.serialize(outbuffer + offset);
      offset += this->sensor_position.serialize(outbuffer + offset);
      offset += this->sensor_velocity.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->sensor_angle);
      offset += this->object_position.serialize(outbuffer + offset);
      offset += this->object_velocity.serialize(outbuffer + offset);
      offset += this->object_relative_position.serialize(outbuffer + offset);
      offset += this->object_relative_velocity.serialize(outbuffer + offset);
      offset += this->object_collider_size.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->object_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->object_state);
      union {
        bool real;
        uint8_t base;
      } u_new_detection;
      u_new_detection.real = this->new_detection;
      *(outbuffer + offset + 0) = (u_new_detection.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->new_detection);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
      offset += this->sensor_aim.deserialize(inbuffer + offset);
      offset += this->sensor_right.deserialize(inbuffer + offset);
      offset += this->sensor_position.deserialize(inbuffer + offset);
      offset += this->sensor_velocity.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->sensor_angle));
      offset += this->object_position.deserialize(inbuffer + offset);
      offset += this->object_velocity.deserialize(inbuffer + offset);
      offset += this->object_relative_position.deserialize(inbuffer + offset);
      offset += this->object_relative_velocity.deserialize(inbuffer + offset);
      offset += this->object_collider_size.deserialize(inbuffer + offset);
      this->object_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->object_state);
      union {
        bool real;
        uint8_t base;
      } u_new_detection;
      u_new_detection.base = 0;
      u_new_detection.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->new_detection = u_new_detection.real;
      offset += sizeof(this->new_detection);
     return offset;
    }

    const char * getType(){ return "lgsvl_msgs/DetectedRadarObject"; };
    const char * getMD5(){ return "ce4b6b01290125e6b2cd22dde070d1fb"; };

  };

}
#endif