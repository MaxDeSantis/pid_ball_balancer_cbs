#ifndef _ROS_autoware_msgs_RemoteCmd_h
#define _ROS_autoware_msgs_RemoteCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_msgs/VehicleCmd.h"

namespace autoware_msgs
{

  class RemoteCmd : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef autoware_msgs::VehicleCmd _vehicle_cmd_type;
      _vehicle_cmd_type vehicle_cmd;
      typedef int32_t _control_mode_type;
      _control_mode_type control_mode;

    RemoteCmd():
      header(),
      vehicle_cmd(),
      control_mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->vehicle_cmd.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_control_mode;
      u_control_mode.real = this->control_mode;
      *(outbuffer + offset + 0) = (u_control_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_control_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_control_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_control_mode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->control_mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->vehicle_cmd.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_control_mode;
      u_control_mode.base = 0;
      u_control_mode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_control_mode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_control_mode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_control_mode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->control_mode = u_control_mode.real;
      offset += sizeof(this->control_mode);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/RemoteCmd"; };
    const char * getMD5(){ return "4ef8b915e5d6977285cb18a9e6793604"; };

  };

}
#endif