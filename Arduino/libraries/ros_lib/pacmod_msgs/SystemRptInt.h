#ifndef _ROS_pacmod_msgs_SystemRptInt_h
#define _ROS_pacmod_msgs_SystemRptInt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class SystemRptInt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _enabled_type;
      _enabled_type enabled;
      typedef bool _override_active_type;
      _override_active_type override_active;
      typedef bool _command_output_fault_type;
      _command_output_fault_type command_output_fault;
      typedef bool _input_output_fault_type;
      _input_output_fault_type input_output_fault;
      typedef bool _output_reported_fault_type;
      _output_reported_fault_type output_reported_fault;
      typedef bool _pacmod_fault_type;
      _pacmod_fault_type pacmod_fault;
      typedef bool _vehicle_fault_type;
      _vehicle_fault_type vehicle_fault;
      typedef uint16_t _manual_input_type;
      _manual_input_type manual_input;
      typedef uint16_t _command_type;
      _command_type command;
      typedef uint16_t _output_type;
      _output_type output;
      enum { CRUISE_CONTROL_NONE =  0 };
      enum { CRUISE_CONTROL_CNCL =  1 };
      enum { CRUISE_CONTROL_ACC_FURTHER =  2 };
      enum { CRUISE_CONTROL_ACC_CLOSER =  3 };
      enum { CRUISE_CONTROL_SET_DEC =  4 };
      enum { CRUISE_CONTROL_RES_INC =  5 };
      enum { DASH_CONTROL_NONE =  0 };
      enum { DASH_CONTROL_OK =  1 };
      enum { DASH_CONTROL_LEFT =  2 };
      enum { DASH_CONTROL_RIGHT =  3 };
      enum { DASH_CONTROL_UP =  4 };
      enum { DASH_CONTROL_DOWN =  5 };
      enum { HEADLIGHTS_OFF =  0 };
      enum { HEADLIGHTS_PARKING_ONLY =  1 };
      enum { HEADLIGHTS_MANUAL_LOW =  2 };
      enum { HEADLIGHTS_MANUAL_HIGH =  3 };
      enum { HEADLIGHTS_AUTO_LOW =  4 };
      enum { HEADLIGHTS_AUTO_HIGH =  5 };
      enum { MEDIA_CONTROL_NONE =  0 };
      enum { MEDIA_CONTROL_VOICE_COMMAND =  1 };
      enum { MEDIA_CONTROL_MUTE =  2 };
      enum { MEDIA_CONTROL_PREV_TRACK_ANSWER =  3 };
      enum { MEDIA_CONTROL_NEXT_TRACK_HANG_UP =  4 };
      enum { MEDIA_CONTROL_VOL_UP =  5 };
      enum { MEDIA_CONTROL_VOL_DOWN =  6 };
      enum { SHIFT_PARK =  0 };
      enum { SHIFT_REVERSE =  1 };
      enum { SHIFT_NEUTRAL =  2 };
      enum { SHIFT_HIGH =  3 };
      enum { SHIFT_FORWARD =  3 };
      enum { SHIFT_LOW =  4 };
      enum { SHIFT_BETWEEN_GEARS =  5 };
      enum { SHIFT_ERROR =  6 };
      enum { SHIFT_NONE =  7 };
      enum { TURN_RIGHT =  0 };
      enum { TURN_NONE =  1 };
      enum { TURN_LEFT =  2 };
      enum { TURN_HAZARDS =  3 };
      enum { DOOR_NEUTRAL =  0 };
      enum { DOOR_OPEN =  1 };
      enum { DOOR_CLOSE =  2 };
      enum { WIPERS_OFF =  0 };
      enum { WIPERS_INT_1 =  1 };
      enum { WIPERS_INT_2 =  2 };
      enum { WIPERS_INT_3 =  3 };
      enum { WIPERS_INT_4 =  4 };
      enum { WIPERS_INT_5 =  5 };
      enum { WIPERS_INT_6 =  6 };
      enum { WIPERS_MEDIUM =  7 };
      enum { WIPERS_HIGH =  8 };

    SystemRptInt():
      header(),
      enabled(0),
      override_active(0),
      command_output_fault(0),
      input_output_fault(0),
      output_reported_fault(0),
      pacmod_fault(0),
      vehicle_fault(0),
      manual_input(0),
      command(0),
      output(0)
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
      } u_command_output_fault;
      u_command_output_fault.real = this->command_output_fault;
      *(outbuffer + offset + 0) = (u_command_output_fault.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command_output_fault);
      union {
        bool real;
        uint8_t base;
      } u_input_output_fault;
      u_input_output_fault.real = this->input_output_fault;
      *(outbuffer + offset + 0) = (u_input_output_fault.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->input_output_fault);
      union {
        bool real;
        uint8_t base;
      } u_output_reported_fault;
      u_output_reported_fault.real = this->output_reported_fault;
      *(outbuffer + offset + 0) = (u_output_reported_fault.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->output_reported_fault);
      union {
        bool real;
        uint8_t base;
      } u_pacmod_fault;
      u_pacmod_fault.real = this->pacmod_fault;
      *(outbuffer + offset + 0) = (u_pacmod_fault.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pacmod_fault);
      union {
        bool real;
        uint8_t base;
      } u_vehicle_fault;
      u_vehicle_fault.real = this->vehicle_fault;
      *(outbuffer + offset + 0) = (u_vehicle_fault.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vehicle_fault);
      *(outbuffer + offset + 0) = (this->manual_input >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->manual_input >> (8 * 1)) & 0xFF;
      offset += sizeof(this->manual_input);
      *(outbuffer + offset + 0) = (this->command >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->command >> (8 * 1)) & 0xFF;
      offset += sizeof(this->command);
      *(outbuffer + offset + 0) = (this->output >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->output >> (8 * 1)) & 0xFF;
      offset += sizeof(this->output);
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
      } u_command_output_fault;
      u_command_output_fault.base = 0;
      u_command_output_fault.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->command_output_fault = u_command_output_fault.real;
      offset += sizeof(this->command_output_fault);
      union {
        bool real;
        uint8_t base;
      } u_input_output_fault;
      u_input_output_fault.base = 0;
      u_input_output_fault.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->input_output_fault = u_input_output_fault.real;
      offset += sizeof(this->input_output_fault);
      union {
        bool real;
        uint8_t base;
      } u_output_reported_fault;
      u_output_reported_fault.base = 0;
      u_output_reported_fault.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->output_reported_fault = u_output_reported_fault.real;
      offset += sizeof(this->output_reported_fault);
      union {
        bool real;
        uint8_t base;
      } u_pacmod_fault;
      u_pacmod_fault.base = 0;
      u_pacmod_fault.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pacmod_fault = u_pacmod_fault.real;
      offset += sizeof(this->pacmod_fault);
      union {
        bool real;
        uint8_t base;
      } u_vehicle_fault;
      u_vehicle_fault.base = 0;
      u_vehicle_fault.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->vehicle_fault = u_vehicle_fault.real;
      offset += sizeof(this->vehicle_fault);
      this->manual_input =  ((uint16_t) (*(inbuffer + offset)));
      this->manual_input |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->manual_input);
      this->command =  ((uint16_t) (*(inbuffer + offset)));
      this->command |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->command);
      this->output =  ((uint16_t) (*(inbuffer + offset)));
      this->output |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->output);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/SystemRptInt"; };
    const char * getMD5(){ return "da718c3df94de6df3ce729dd13078d8a"; };

  };

}
#endif