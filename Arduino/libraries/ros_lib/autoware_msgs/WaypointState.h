#ifndef _ROS_autoware_msgs_WaypointState_h
#define _ROS_autoware_msgs_WaypointState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_msgs
{

  class WaypointState : public ros::Msg
  {
    public:
      typedef int32_t _aid_type;
      _aid_type aid;
      typedef uint8_t _lanechange_state_type;
      _lanechange_state_type lanechange_state;
      typedef uint8_t _steering_state_type;
      _steering_state_type steering_state;
      typedef uint8_t _accel_state_type;
      _accel_state_type accel_state;
      typedef uint8_t _stop_state_type;
      _stop_state_type stop_state;
      typedef uint8_t _event_state_type;
      _event_state_type event_state;
      enum { NULLSTATE = 0 };
      enum { STR_LEFT = 1 };
      enum { STR_RIGHT = 2 };
      enum { STR_STRAIGHT = 3 };
      enum { STR_BACK = 4 };
      enum { TYPE_STOPLINE = 1 };
      enum { TYPE_STOP = 2 };
      enum { TYPE_EVENT_NULL =  0 };
      enum { TYPE_EVENT_GOAL =  1 };
      enum { TYPE_EVENT_MIDDLE_GOAL =  2 };
      enum { TYPE_EVENT_POSITION_STOP =  3 };
      enum { TYPE_EVENT_BUS_STOP =  4 };
      enum { TYPE_EVENT_PARKING =  5 };

    WaypointState():
      aid(0),
      lanechange_state(0),
      steering_state(0),
      accel_state(0),
      stop_state(0),
      event_state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_aid;
      u_aid.real = this->aid;
      *(outbuffer + offset + 0) = (u_aid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_aid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_aid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_aid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->aid);
      *(outbuffer + offset + 0) = (this->lanechange_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->lanechange_state);
      *(outbuffer + offset + 0) = (this->steering_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->steering_state);
      *(outbuffer + offset + 0) = (this->accel_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->accel_state);
      *(outbuffer + offset + 0) = (this->stop_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->stop_state);
      *(outbuffer + offset + 0) = (this->event_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->event_state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_aid;
      u_aid.base = 0;
      u_aid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_aid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_aid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_aid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->aid = u_aid.real;
      offset += sizeof(this->aid);
      this->lanechange_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->lanechange_state);
      this->steering_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->steering_state);
      this->accel_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->accel_state);
      this->stop_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->stop_state);
      this->event_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->event_state);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/WaypointState"; };
    const char * getMD5(){ return "623a0ffbb0a052490adc981c2a3e8edd"; };

  };

}
#endif