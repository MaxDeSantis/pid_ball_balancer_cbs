#ifndef _ROS_SERVICE_PositionState_h
#define _ROS_SERVICE_PositionState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace vector_map_server
{

static const char POSITIONSTATE[] = "vector_map_server/PositionState";

  class PositionStateRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _position_type;
      _position_type position;

    PositionStateRequest():
      position()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->position.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->position.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return POSITIONSTATE; };
    const char * getMD5(){ return "e7bb0ef028c744b081acdc57743b11d8"; };

  };

  class PositionStateResponse : public ros::Msg
  {
    public:
      typedef bool _state_type;
      _state_type state;

    PositionStateResponse():
      state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_state;
      u_state.real = this->state;
      *(outbuffer + offset + 0) = (u_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_state;
      u_state.base = 0;
      u_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->state = u_state.real;
      offset += sizeof(this->state);
     return offset;
    }

    const char * getType(){ return POSITIONSTATE; };
    const char * getMD5(){ return "001fde3cab9e313a150416ff09c08ee4"; };

  };

  class PositionState {
    public:
    typedef PositionStateRequest Request;
    typedef PositionStateResponse Response;
  };

}
#endif
