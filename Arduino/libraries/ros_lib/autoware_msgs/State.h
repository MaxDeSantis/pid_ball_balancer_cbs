#ifndef _ROS_autoware_msgs_State_h
#define _ROS_autoware_msgs_State_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_msgs
{

  class State : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _vehicle_state_type;
      _vehicle_state_type vehicle_state;
      typedef const char* _mission_state_type;
      _mission_state_type mission_state;
      typedef const char* _behavior_state_type;
      _behavior_state_type behavior_state;
      typedef const char* _motion_state_type;
      _motion_state_type motion_state;

    State():
      header(),
      vehicle_state(""),
      mission_state(""),
      behavior_state(""),
      motion_state("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_vehicle_state = strlen(this->vehicle_state);
      varToArr(outbuffer + offset, length_vehicle_state);
      offset += 4;
      memcpy(outbuffer + offset, this->vehicle_state, length_vehicle_state);
      offset += length_vehicle_state;
      uint32_t length_mission_state = strlen(this->mission_state);
      varToArr(outbuffer + offset, length_mission_state);
      offset += 4;
      memcpy(outbuffer + offset, this->mission_state, length_mission_state);
      offset += length_mission_state;
      uint32_t length_behavior_state = strlen(this->behavior_state);
      varToArr(outbuffer + offset, length_behavior_state);
      offset += 4;
      memcpy(outbuffer + offset, this->behavior_state, length_behavior_state);
      offset += length_behavior_state;
      uint32_t length_motion_state = strlen(this->motion_state);
      varToArr(outbuffer + offset, length_motion_state);
      offset += 4;
      memcpy(outbuffer + offset, this->motion_state, length_motion_state);
      offset += length_motion_state;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_vehicle_state;
      arrToVar(length_vehicle_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_vehicle_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_vehicle_state-1]=0;
      this->vehicle_state = (char *)(inbuffer + offset-1);
      offset += length_vehicle_state;
      uint32_t length_mission_state;
      arrToVar(length_mission_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mission_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mission_state-1]=0;
      this->mission_state = (char *)(inbuffer + offset-1);
      offset += length_mission_state;
      uint32_t length_behavior_state;
      arrToVar(length_behavior_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_behavior_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_behavior_state-1]=0;
      this->behavior_state = (char *)(inbuffer + offset-1);
      offset += length_behavior_state;
      uint32_t length_motion_state;
      arrToVar(length_motion_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_motion_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_motion_state-1]=0;
      this->motion_state = (char *)(inbuffer + offset-1);
      offset += length_motion_state;
     return offset;
    }

    const char * getType(){ return "autoware_msgs/State"; };
    const char * getMD5(){ return "937d7a6d5eba6aee9608f59553aebbe8"; };

  };

}
#endif