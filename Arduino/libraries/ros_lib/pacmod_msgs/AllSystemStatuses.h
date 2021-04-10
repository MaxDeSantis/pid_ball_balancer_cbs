#ifndef _ROS_pacmod_msgs_AllSystemStatuses_h
#define _ROS_pacmod_msgs_AllSystemStatuses_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pacmod_msgs/KeyValuePair.h"

namespace pacmod_msgs
{

  class AllSystemStatuses : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t enabled_status_length;
      typedef pacmod_msgs::KeyValuePair _enabled_status_type;
      _enabled_status_type st_enabled_status;
      _enabled_status_type * enabled_status;
      uint32_t overridden_status_length;
      typedef pacmod_msgs::KeyValuePair _overridden_status_type;
      _overridden_status_type st_overridden_status;
      _overridden_status_type * overridden_status;
      uint32_t fault_status_length;
      typedef pacmod_msgs::KeyValuePair _fault_status_type;
      _fault_status_type st_fault_status;
      _fault_status_type * fault_status;

    AllSystemStatuses():
      header(),
      enabled_status_length(0), enabled_status(NULL),
      overridden_status_length(0), overridden_status(NULL),
      fault_status_length(0), fault_status(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->enabled_status_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->enabled_status_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->enabled_status_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->enabled_status_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->enabled_status_length);
      for( uint32_t i = 0; i < enabled_status_length; i++){
      offset += this->enabled_status[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->overridden_status_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->overridden_status_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->overridden_status_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->overridden_status_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->overridden_status_length);
      for( uint32_t i = 0; i < overridden_status_length; i++){
      offset += this->overridden_status[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->fault_status_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fault_status_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fault_status_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fault_status_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fault_status_length);
      for( uint32_t i = 0; i < fault_status_length; i++){
      offset += this->fault_status[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t enabled_status_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      enabled_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      enabled_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      enabled_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->enabled_status_length);
      if(enabled_status_lengthT > enabled_status_length)
        this->enabled_status = (pacmod_msgs::KeyValuePair*)realloc(this->enabled_status, enabled_status_lengthT * sizeof(pacmod_msgs::KeyValuePair));
      enabled_status_length = enabled_status_lengthT;
      for( uint32_t i = 0; i < enabled_status_length; i++){
      offset += this->st_enabled_status.deserialize(inbuffer + offset);
        memcpy( &(this->enabled_status[i]), &(this->st_enabled_status), sizeof(pacmod_msgs::KeyValuePair));
      }
      uint32_t overridden_status_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      overridden_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      overridden_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      overridden_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->overridden_status_length);
      if(overridden_status_lengthT > overridden_status_length)
        this->overridden_status = (pacmod_msgs::KeyValuePair*)realloc(this->overridden_status, overridden_status_lengthT * sizeof(pacmod_msgs::KeyValuePair));
      overridden_status_length = overridden_status_lengthT;
      for( uint32_t i = 0; i < overridden_status_length; i++){
      offset += this->st_overridden_status.deserialize(inbuffer + offset);
        memcpy( &(this->overridden_status[i]), &(this->st_overridden_status), sizeof(pacmod_msgs::KeyValuePair));
      }
      uint32_t fault_status_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fault_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fault_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fault_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->fault_status_length);
      if(fault_status_lengthT > fault_status_length)
        this->fault_status = (pacmod_msgs::KeyValuePair*)realloc(this->fault_status, fault_status_lengthT * sizeof(pacmod_msgs::KeyValuePair));
      fault_status_length = fault_status_lengthT;
      for( uint32_t i = 0; i < fault_status_length; i++){
      offset += this->st_fault_status.deserialize(inbuffer + offset);
        memcpy( &(this->fault_status[i]), &(this->st_fault_status), sizeof(pacmod_msgs::KeyValuePair));
      }
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/AllSystemStatuses"; };
    const char * getMD5(){ return "c02f347061ed74b0bef510eb7368d90a"; };

  };

}
#endif