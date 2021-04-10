#ifndef _ROS_lgsvl_msgs_VehicleStateData_h
#define _ROS_lgsvl_msgs_VehicleStateData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace lgsvl_msgs
{

  class VehicleStateData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _blinker_state_type;
      _blinker_state_type blinker_state;
      typedef uint8_t _headlight_state_type;
      _headlight_state_type headlight_state;
      typedef uint8_t _wiper_state_type;
      _wiper_state_type wiper_state;
      typedef uint8_t _current_gear_type;
      _current_gear_type current_gear;
      typedef uint8_t _vehicle_mode_type;
      _vehicle_mode_type vehicle_mode;
      typedef bool _hand_brake_active_type;
      _hand_brake_active_type hand_brake_active;
      typedef bool _horn_active_type;
      _horn_active_type horn_active;
      typedef bool _autonomous_mode_active_type;
      _autonomous_mode_active_type autonomous_mode_active;
      enum { BLINKERS_OFF =  0 };
      enum { BLINKERS_LEFT =  1 };
      enum { BLINKERS_RIGHT =  2 };
      enum { BLINKERS_HAZARD =  3 };
      enum { HEADLIGHTS_OFF =  0 };
      enum { HEADLIGHTS_LOW =  1 };
      enum { HEADLIGHTS_HIGH =  2 };
      enum { WIPERS_OFF =  0 };
      enum { WIPERS_LOW =  1 };
      enum { WIPERS_MED =  2 };
      enum { WIPERS_HIGH =  3 };
      enum { GEAR_NEUTRAL =  0 };
      enum { GEAR_DRIVE =  1 };
      enum { GEAR_REVERSE =  2 };
      enum { GEAR_PARKING =  3 };
      enum { GEAR_LOW =  4 };
      enum { VEHICLE_MODE_COMPLETE_MANUAL =  0 };
      enum { VEHICLE_MODE_COMPLETE_AUTO_DRIVE =  1 };
      enum { VEHICLE_MODE_AUTO_STEER_ONLY =  2 };
      enum { VEHICLE_MODE_AUTO_SPEED_ONLY =  3 };
      enum { VEHICLE_MODE_EMERGENCY_MODE =  4 };

    VehicleStateData():
      header(),
      blinker_state(0),
      headlight_state(0),
      wiper_state(0),
      current_gear(0),
      vehicle_mode(0),
      hand_brake_active(0),
      horn_active(0),
      autonomous_mode_active(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->blinker_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->blinker_state);
      *(outbuffer + offset + 0) = (this->headlight_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->headlight_state);
      *(outbuffer + offset + 0) = (this->wiper_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wiper_state);
      *(outbuffer + offset + 0) = (this->current_gear >> (8 * 0)) & 0xFF;
      offset += sizeof(this->current_gear);
      *(outbuffer + offset + 0) = (this->vehicle_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vehicle_mode);
      union {
        bool real;
        uint8_t base;
      } u_hand_brake_active;
      u_hand_brake_active.real = this->hand_brake_active;
      *(outbuffer + offset + 0) = (u_hand_brake_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->hand_brake_active);
      union {
        bool real;
        uint8_t base;
      } u_horn_active;
      u_horn_active.real = this->horn_active;
      *(outbuffer + offset + 0) = (u_horn_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->horn_active);
      union {
        bool real;
        uint8_t base;
      } u_autonomous_mode_active;
      u_autonomous_mode_active.real = this->autonomous_mode_active;
      *(outbuffer + offset + 0) = (u_autonomous_mode_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->autonomous_mode_active);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->blinker_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->blinker_state);
      this->headlight_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->headlight_state);
      this->wiper_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->wiper_state);
      this->current_gear =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->current_gear);
      this->vehicle_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->vehicle_mode);
      union {
        bool real;
        uint8_t base;
      } u_hand_brake_active;
      u_hand_brake_active.base = 0;
      u_hand_brake_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->hand_brake_active = u_hand_brake_active.real;
      offset += sizeof(this->hand_brake_active);
      union {
        bool real;
        uint8_t base;
      } u_horn_active;
      u_horn_active.base = 0;
      u_horn_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->horn_active = u_horn_active.real;
      offset += sizeof(this->horn_active);
      union {
        bool real;
        uint8_t base;
      } u_autonomous_mode_active;
      u_autonomous_mode_active.base = 0;
      u_autonomous_mode_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->autonomous_mode_active = u_autonomous_mode_active.real;
      offset += sizeof(this->autonomous_mode_active);
     return offset;
    }

    const char * getType(){ return "lgsvl_msgs/VehicleStateData"; };
    const char * getMD5(){ return "b4405ea9889445c8f7934126d18f047c"; };

  };

}
#endif