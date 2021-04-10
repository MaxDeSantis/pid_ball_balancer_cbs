#ifndef _ROS_pacmod_msgs_VehicleDynamicsRpt_h
#define _ROS_pacmod_msgs_VehicleDynamicsRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class VehicleDynamicsRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _brake_torque_type;
      _brake_torque_type brake_torque;
      typedef uint8_t _g_forces_type;
      _g_forces_type g_forces;

    VehicleDynamicsRpt():
      header(),
      brake_torque(0),
      g_forces(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->brake_torque);
      *(outbuffer + offset + 0) = (this->g_forces >> (8 * 0)) & 0xFF;
      offset += sizeof(this->g_forces);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->brake_torque));
      this->g_forces =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->g_forces);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/VehicleDynamicsRpt"; };
    const char * getMD5(){ return "76c5ee0fb5b1065da372a973e2ffdd31"; };

  };

}
#endif