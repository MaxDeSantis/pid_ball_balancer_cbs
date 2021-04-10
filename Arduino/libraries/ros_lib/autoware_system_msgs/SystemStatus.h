#ifndef _ROS_autoware_system_msgs_SystemStatus_h
#define _ROS_autoware_system_msgs_SystemStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_system_msgs/NodeStatus.h"
#include "autoware_system_msgs/HardwareStatus.h"
#include "rosgraph_msgs/TopicStatistics.h"

namespace autoware_system_msgs
{

  class SystemStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t available_nodes_length;
      typedef char* _available_nodes_type;
      _available_nodes_type st_available_nodes;
      _available_nodes_type * available_nodes;
      typedef bool _detect_too_match_warning_type;
      _detect_too_match_warning_type detect_too_match_warning;
      uint32_t node_status_length;
      typedef autoware_system_msgs::NodeStatus _node_status_type;
      _node_status_type st_node_status;
      _node_status_type * node_status;
      uint32_t hardware_status_length;
      typedef autoware_system_msgs::HardwareStatus _hardware_status_type;
      _hardware_status_type st_hardware_status;
      _hardware_status_type * hardware_status;
      uint32_t topic_statistics_length;
      typedef rosgraph_msgs::TopicStatistics _topic_statistics_type;
      _topic_statistics_type st_topic_statistics;
      _topic_statistics_type * topic_statistics;

    SystemStatus():
      header(),
      available_nodes_length(0), available_nodes(NULL),
      detect_too_match_warning(0),
      node_status_length(0), node_status(NULL),
      hardware_status_length(0), hardware_status(NULL),
      topic_statistics_length(0), topic_statistics(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->available_nodes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->available_nodes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->available_nodes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->available_nodes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->available_nodes_length);
      for( uint32_t i = 0; i < available_nodes_length; i++){
      uint32_t length_available_nodesi = strlen(this->available_nodes[i]);
      varToArr(outbuffer + offset, length_available_nodesi);
      offset += 4;
      memcpy(outbuffer + offset, this->available_nodes[i], length_available_nodesi);
      offset += length_available_nodesi;
      }
      union {
        bool real;
        uint8_t base;
      } u_detect_too_match_warning;
      u_detect_too_match_warning.real = this->detect_too_match_warning;
      *(outbuffer + offset + 0) = (u_detect_too_match_warning.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->detect_too_match_warning);
      *(outbuffer + offset + 0) = (this->node_status_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->node_status_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->node_status_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->node_status_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->node_status_length);
      for( uint32_t i = 0; i < node_status_length; i++){
      offset += this->node_status[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->hardware_status_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hardware_status_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hardware_status_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hardware_status_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hardware_status_length);
      for( uint32_t i = 0; i < hardware_status_length; i++){
      offset += this->hardware_status[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->topic_statistics_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->topic_statistics_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->topic_statistics_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->topic_statistics_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->topic_statistics_length);
      for( uint32_t i = 0; i < topic_statistics_length; i++){
      offset += this->topic_statistics[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t available_nodes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      available_nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      available_nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      available_nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->available_nodes_length);
      if(available_nodes_lengthT > available_nodes_length)
        this->available_nodes = (char**)realloc(this->available_nodes, available_nodes_lengthT * sizeof(char*));
      available_nodes_length = available_nodes_lengthT;
      for( uint32_t i = 0; i < available_nodes_length; i++){
      uint32_t length_st_available_nodes;
      arrToVar(length_st_available_nodes, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_available_nodes; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_available_nodes-1]=0;
      this->st_available_nodes = (char *)(inbuffer + offset-1);
      offset += length_st_available_nodes;
        memcpy( &(this->available_nodes[i]), &(this->st_available_nodes), sizeof(char*));
      }
      union {
        bool real;
        uint8_t base;
      } u_detect_too_match_warning;
      u_detect_too_match_warning.base = 0;
      u_detect_too_match_warning.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->detect_too_match_warning = u_detect_too_match_warning.real;
      offset += sizeof(this->detect_too_match_warning);
      uint32_t node_status_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      node_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      node_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      node_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->node_status_length);
      if(node_status_lengthT > node_status_length)
        this->node_status = (autoware_system_msgs::NodeStatus*)realloc(this->node_status, node_status_lengthT * sizeof(autoware_system_msgs::NodeStatus));
      node_status_length = node_status_lengthT;
      for( uint32_t i = 0; i < node_status_length; i++){
      offset += this->st_node_status.deserialize(inbuffer + offset);
        memcpy( &(this->node_status[i]), &(this->st_node_status), sizeof(autoware_system_msgs::NodeStatus));
      }
      uint32_t hardware_status_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      hardware_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      hardware_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      hardware_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->hardware_status_length);
      if(hardware_status_lengthT > hardware_status_length)
        this->hardware_status = (autoware_system_msgs::HardwareStatus*)realloc(this->hardware_status, hardware_status_lengthT * sizeof(autoware_system_msgs::HardwareStatus));
      hardware_status_length = hardware_status_lengthT;
      for( uint32_t i = 0; i < hardware_status_length; i++){
      offset += this->st_hardware_status.deserialize(inbuffer + offset);
        memcpy( &(this->hardware_status[i]), &(this->st_hardware_status), sizeof(autoware_system_msgs::HardwareStatus));
      }
      uint32_t topic_statistics_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      topic_statistics_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      topic_statistics_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      topic_statistics_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->topic_statistics_length);
      if(topic_statistics_lengthT > topic_statistics_length)
        this->topic_statistics = (rosgraph_msgs::TopicStatistics*)realloc(this->topic_statistics, topic_statistics_lengthT * sizeof(rosgraph_msgs::TopicStatistics));
      topic_statistics_length = topic_statistics_lengthT;
      for( uint32_t i = 0; i < topic_statistics_length; i++){
      offset += this->st_topic_statistics.deserialize(inbuffer + offset);
        memcpy( &(this->topic_statistics[i]), &(this->st_topic_statistics), sizeof(rosgraph_msgs::TopicStatistics));
      }
     return offset;
    }

    const char * getType(){ return "autoware_system_msgs/SystemStatus"; };
    const char * getMD5(){ return "4410e98d931508de40c30e12f5aa1ed0"; };

  };

}
#endif