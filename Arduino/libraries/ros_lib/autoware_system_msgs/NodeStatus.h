#ifndef _ROS_autoware_system_msgs_NodeStatus_h
#define _ROS_autoware_system_msgs_NodeStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_system_msgs/DiagnosticStatusArray.h"

namespace autoware_system_msgs
{

  class NodeStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _node_name_type;
      _node_name_type node_name;
      typedef bool _node_activated_type;
      _node_activated_type node_activated;
      uint32_t status_length;
      typedef autoware_system_msgs::DiagnosticStatusArray _status_type;
      _status_type st_status;
      _status_type * status;

    NodeStatus():
      header(),
      node_name(""),
      node_activated(0),
      status_length(0), status(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_node_name = strlen(this->node_name);
      varToArr(outbuffer + offset, length_node_name);
      offset += 4;
      memcpy(outbuffer + offset, this->node_name, length_node_name);
      offset += length_node_name;
      union {
        bool real;
        uint8_t base;
      } u_node_activated;
      u_node_activated.real = this->node_activated;
      *(outbuffer + offset + 0) = (u_node_activated.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->node_activated);
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
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_node_name;
      arrToVar(length_node_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_node_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_node_name-1]=0;
      this->node_name = (char *)(inbuffer + offset-1);
      offset += length_node_name;
      union {
        bool real;
        uint8_t base;
      } u_node_activated;
      u_node_activated.base = 0;
      u_node_activated.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->node_activated = u_node_activated.real;
      offset += sizeof(this->node_activated);
      uint32_t status_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->status_length);
      if(status_lengthT > status_length)
        this->status = (autoware_system_msgs::DiagnosticStatusArray*)realloc(this->status, status_lengthT * sizeof(autoware_system_msgs::DiagnosticStatusArray));
      status_length = status_lengthT;
      for( uint32_t i = 0; i < status_length; i++){
      offset += this->st_status.deserialize(inbuffer + offset);
        memcpy( &(this->status[i]), &(this->st_status), sizeof(autoware_system_msgs::DiagnosticStatusArray));
      }
     return offset;
    }

    const char * getType(){ return "autoware_system_msgs/NodeStatus"; };
    const char * getMD5(){ return "43e5a8f8ce6c88feffeaea7f4a97abd5"; };

  };

}
#endif