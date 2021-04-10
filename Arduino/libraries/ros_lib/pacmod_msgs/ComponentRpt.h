#ifndef _ROS_pacmod_msgs_ComponentRpt_h
#define _ROS_pacmod_msgs_ComponentRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class ComponentRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _component_type_type;
      _component_type_type component_type;
      typedef uint8_t _component_func_type;
      _component_func_type component_func;
      typedef uint8_t _counter_type;
      _counter_type counter;
      typedef uint8_t _complement_type;
      _complement_type complement;
      typedef bool _config_fault_type;
      _config_fault_type config_fault;
      enum { COMPONENT_TYPE_PACMOD =  0 };
      enum { COMPONENT_TYPE_PACMINI =  1 };
      enum { COMPONENT_TYPE_PACMICRO =  2 };
      enum { COMPONENT_FUNC_PACMOD =  0 };
      enum { COMPONENT_FUNC_STEERING_AND_STEERING_COLUMN =  1 };
      enum { COMPONENT_FUNC_ACCELERATOR_AND_BRAKING =  2 };
      enum { COMPONENT_FUNC_BRAKING =  3 };
      enum { COMPONENT_FUNC_SHIFTING =  4 };
      enum { COMPONENT_FUNC_STEERING =  5 };
      enum { COMPONENT_FUNC_E_SHIFTER =  6 };
      enum { COMPONENT_FUNC_WATCHDOG =  7 };

    ComponentRpt():
      header(),
      component_type(0),
      component_func(0),
      counter(0),
      complement(0),
      config_fault(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->component_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->component_type);
      *(outbuffer + offset + 0) = (this->component_func >> (8 * 0)) & 0xFF;
      offset += sizeof(this->component_func);
      *(outbuffer + offset + 0) = (this->counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->counter);
      *(outbuffer + offset + 0) = (this->complement >> (8 * 0)) & 0xFF;
      offset += sizeof(this->complement);
      union {
        bool real;
        uint8_t base;
      } u_config_fault;
      u_config_fault.real = this->config_fault;
      *(outbuffer + offset + 0) = (u_config_fault.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->config_fault);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->component_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->component_type);
      this->component_func =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->component_func);
      this->counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->counter);
      this->complement =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->complement);
      union {
        bool real;
        uint8_t base;
      } u_config_fault;
      u_config_fault.base = 0;
      u_config_fault.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->config_fault = u_config_fault.real;
      offset += sizeof(this->config_fault);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/ComponentRpt"; };
    const char * getMD5(){ return "1d5b5cb01195437dc5e2f534206c1017"; };

  };

}
#endif