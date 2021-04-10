#ifndef _ROS_autoware_system_msgs_DiagnosticStatusArray_h
#define _ROS_autoware_system_msgs_DiagnosticStatusArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autoware_system_msgs/DiagnosticStatus.h"

namespace autoware_system_msgs
{

  class DiagnosticStatusArray : public ros::Msg
  {
    public:
      uint32_t status_length;
      typedef autoware_system_msgs::DiagnosticStatus _status_type;
      _status_type st_status;
      _status_type * status;

    DiagnosticStatusArray():
      status_length(0), status(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->status_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->status_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->status_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->status_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->status_length);
      for( uint32_t i = 0; i < status_length; i++){
      offset += this->status[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t status_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->status_length);
      if(status_lengthT > status_length)
        this->status = (autoware_system_msgs::DiagnosticStatus*)realloc(this->status, status_lengthT * sizeof(autoware_system_msgs::DiagnosticStatus));
      status_length = status_lengthT;
      for( uint32_t i = 0; i < status_length; i++){
      offset += this->st_status.deserialize(inbuffer + offset);
        memcpy( &(this->status[i]), &(this->st_status), sizeof(autoware_system_msgs::DiagnosticStatus));
      }
     return offset;
    }

    const char * getType(){ return "autoware_system_msgs/DiagnosticStatusArray"; };
    const char * getMD5(){ return "a4ef80ae8a892c5fadc6e00f2bdc84d0"; };

  };

}
#endif