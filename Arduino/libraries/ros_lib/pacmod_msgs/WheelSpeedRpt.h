#ifndef _ROS_pacmod_msgs_WheelSpeedRpt_h
#define _ROS_pacmod_msgs_WheelSpeedRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class WheelSpeedRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _front_left_wheel_speed_type;
      _front_left_wheel_speed_type front_left_wheel_speed;
      typedef float _front_right_wheel_speed_type;
      _front_right_wheel_speed_type front_right_wheel_speed;
      typedef float _rear_left_wheel_speed_type;
      _rear_left_wheel_speed_type rear_left_wheel_speed;
      typedef float _rear_right_wheel_speed_type;
      _rear_right_wheel_speed_type rear_right_wheel_speed;

    WheelSpeedRpt():
      header(),
      front_left_wheel_speed(0),
      front_right_wheel_speed(0),
      rear_left_wheel_speed(0),
      rear_right_wheel_speed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->front_left_wheel_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->front_right_wheel_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->rear_left_wheel_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->rear_right_wheel_speed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->front_left_wheel_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->front_right_wheel_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rear_left_wheel_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rear_right_wheel_speed));
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/WheelSpeedRpt"; };
    const char * getMD5(){ return "0ade552ffaaff87eca01c4d9b49bb8ae"; };

  };

}
#endif