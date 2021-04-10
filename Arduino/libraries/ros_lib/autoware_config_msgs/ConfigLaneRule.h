#ifndef _ROS_autoware_config_msgs_ConfigLaneRule_h
#define _ROS_autoware_config_msgs_ConfigLaneRule_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigLaneRule : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _acceleration_type;
      _acceleration_type acceleration;
      typedef float _stopline_search_radius_type;
      _stopline_search_radius_type stopline_search_radius;
      typedef int32_t _number_of_zeros_ahead_type;
      _number_of_zeros_ahead_type number_of_zeros_ahead;
      typedef int32_t _number_of_zeros_behind_type;
      _number_of_zeros_behind_type number_of_zeros_behind;
      typedef int32_t _number_of_smoothing_count_type;
      _number_of_smoothing_count_type number_of_smoothing_count;

    ConfigLaneRule():
      header(),
      acceleration(0),
      stopline_search_radius(0),
      number_of_zeros_ahead(0),
      number_of_zeros_behind(0),
      number_of_smoothing_count(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_acceleration;
      u_acceleration.real = this->acceleration;
      *(outbuffer + offset + 0) = (u_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acceleration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acceleration);
      union {
        float real;
        uint32_t base;
      } u_stopline_search_radius;
      u_stopline_search_radius.real = this->stopline_search_radius;
      *(outbuffer + offset + 0) = (u_stopline_search_radius.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stopline_search_radius.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stopline_search_radius.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stopline_search_radius.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stopline_search_radius);
      union {
        int32_t real;
        uint32_t base;
      } u_number_of_zeros_ahead;
      u_number_of_zeros_ahead.real = this->number_of_zeros_ahead;
      *(outbuffer + offset + 0) = (u_number_of_zeros_ahead.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_number_of_zeros_ahead.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_number_of_zeros_ahead.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_number_of_zeros_ahead.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->number_of_zeros_ahead);
      union {
        int32_t real;
        uint32_t base;
      } u_number_of_zeros_behind;
      u_number_of_zeros_behind.real = this->number_of_zeros_behind;
      *(outbuffer + offset + 0) = (u_number_of_zeros_behind.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_number_of_zeros_behind.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_number_of_zeros_behind.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_number_of_zeros_behind.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->number_of_zeros_behind);
      union {
        int32_t real;
        uint32_t base;
      } u_number_of_smoothing_count;
      u_number_of_smoothing_count.real = this->number_of_smoothing_count;
      *(outbuffer + offset + 0) = (u_number_of_smoothing_count.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_number_of_smoothing_count.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_number_of_smoothing_count.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_number_of_smoothing_count.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->number_of_smoothing_count);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_acceleration;
      u_acceleration.base = 0;
      u_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->acceleration = u_acceleration.real;
      offset += sizeof(this->acceleration);
      union {
        float real;
        uint32_t base;
      } u_stopline_search_radius;
      u_stopline_search_radius.base = 0;
      u_stopline_search_radius.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stopline_search_radius.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stopline_search_radius.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stopline_search_radius.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->stopline_search_radius = u_stopline_search_radius.real;
      offset += sizeof(this->stopline_search_radius);
      union {
        int32_t real;
        uint32_t base;
      } u_number_of_zeros_ahead;
      u_number_of_zeros_ahead.base = 0;
      u_number_of_zeros_ahead.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_number_of_zeros_ahead.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_number_of_zeros_ahead.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_number_of_zeros_ahead.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->number_of_zeros_ahead = u_number_of_zeros_ahead.real;
      offset += sizeof(this->number_of_zeros_ahead);
      union {
        int32_t real;
        uint32_t base;
      } u_number_of_zeros_behind;
      u_number_of_zeros_behind.base = 0;
      u_number_of_zeros_behind.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_number_of_zeros_behind.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_number_of_zeros_behind.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_number_of_zeros_behind.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->number_of_zeros_behind = u_number_of_zeros_behind.real;
      offset += sizeof(this->number_of_zeros_behind);
      union {
        int32_t real;
        uint32_t base;
      } u_number_of_smoothing_count;
      u_number_of_smoothing_count.base = 0;
      u_number_of_smoothing_count.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_number_of_smoothing_count.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_number_of_smoothing_count.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_number_of_smoothing_count.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->number_of_smoothing_count = u_number_of_smoothing_count.real;
      offset += sizeof(this->number_of_smoothing_count);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigLaneRule"; };
    const char * getMD5(){ return "186844f4cf4fe2d56c23516198932aa0"; };

  };

}
#endif