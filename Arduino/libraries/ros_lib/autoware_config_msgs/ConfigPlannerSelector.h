#ifndef _ROS_autoware_config_msgs_ConfigPlannerSelector_h
#define _ROS_autoware_config_msgs_ConfigPlannerSelector_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigPlannerSelector : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _latency_num_type;
      _latency_num_type latency_num;
      typedef int32_t _waypoints_num_type;
      _waypoints_num_type waypoints_num;
      typedef float _convergence_num_type;
      _convergence_num_type convergence_num;

    ConfigPlannerSelector():
      header(),
      latency_num(0),
      waypoints_num(0),
      convergence_num(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_latency_num;
      u_latency_num.real = this->latency_num;
      *(outbuffer + offset + 0) = (u_latency_num.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latency_num.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latency_num.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latency_num.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latency_num);
      union {
        int32_t real;
        uint32_t base;
      } u_waypoints_num;
      u_waypoints_num.real = this->waypoints_num;
      *(outbuffer + offset + 0) = (u_waypoints_num.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_waypoints_num.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_waypoints_num.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_waypoints_num.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->waypoints_num);
      union {
        float real;
        uint32_t base;
      } u_convergence_num;
      u_convergence_num.real = this->convergence_num;
      *(outbuffer + offset + 0) = (u_convergence_num.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_convergence_num.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_convergence_num.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_convergence_num.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->convergence_num);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_latency_num;
      u_latency_num.base = 0;
      u_latency_num.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latency_num.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latency_num.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latency_num.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latency_num = u_latency_num.real;
      offset += sizeof(this->latency_num);
      union {
        int32_t real;
        uint32_t base;
      } u_waypoints_num;
      u_waypoints_num.base = 0;
      u_waypoints_num.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_waypoints_num.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_waypoints_num.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_waypoints_num.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->waypoints_num = u_waypoints_num.real;
      offset += sizeof(this->waypoints_num);
      union {
        float real;
        uint32_t base;
      } u_convergence_num;
      u_convergence_num.base = 0;
      u_convergence_num.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_convergence_num.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_convergence_num.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_convergence_num.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->convergence_num = u_convergence_num.real;
      offset += sizeof(this->convergence_num);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigPlannerSelector"; };
    const char * getMD5(){ return "8e965eeadefa5a9fa6612f06efadfa23"; };

  };

}
#endif