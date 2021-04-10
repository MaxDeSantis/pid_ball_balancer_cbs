#ifndef _ROS_autoware_config_msgs_ConfigNDTMapping_h
#define _ROS_autoware_config_msgs_ConfigNDTMapping_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigNDTMapping : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _resolution_type;
      _resolution_type resolution;
      typedef float _step_size_type;
      _step_size_type step_size;
      typedef float _trans_epsilon_type;
      _trans_epsilon_type trans_epsilon;
      typedef int32_t _max_iterations_type;
      _max_iterations_type max_iterations;
      typedef float _leaf_size_type;
      _leaf_size_type leaf_size;
      typedef float _min_scan_range_type;
      _min_scan_range_type min_scan_range;
      typedef float _max_scan_range_type;
      _max_scan_range_type max_scan_range;
      typedef float _min_add_scan_shift_type;
      _min_add_scan_shift_type min_add_scan_shift;

    ConfigNDTMapping():
      header(),
      resolution(0),
      step_size(0),
      trans_epsilon(0),
      max_iterations(0),
      leaf_size(0),
      min_scan_range(0),
      max_scan_range(0),
      min_add_scan_shift(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_resolution;
      u_resolution.real = this->resolution;
      *(outbuffer + offset + 0) = (u_resolution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_resolution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_resolution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_resolution.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->resolution);
      union {
        float real;
        uint32_t base;
      } u_step_size;
      u_step_size.real = this->step_size;
      *(outbuffer + offset + 0) = (u_step_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_step_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_step_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_step_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->step_size);
      union {
        float real;
        uint32_t base;
      } u_trans_epsilon;
      u_trans_epsilon.real = this->trans_epsilon;
      *(outbuffer + offset + 0) = (u_trans_epsilon.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_trans_epsilon.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_trans_epsilon.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_trans_epsilon.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trans_epsilon);
      union {
        int32_t real;
        uint32_t base;
      } u_max_iterations;
      u_max_iterations.real = this->max_iterations;
      *(outbuffer + offset + 0) = (u_max_iterations.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_iterations.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_iterations.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_iterations.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_iterations);
      union {
        float real;
        uint32_t base;
      } u_leaf_size;
      u_leaf_size.real = this->leaf_size;
      *(outbuffer + offset + 0) = (u_leaf_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_leaf_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_leaf_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_leaf_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->leaf_size);
      union {
        float real;
        uint32_t base;
      } u_min_scan_range;
      u_min_scan_range.real = this->min_scan_range;
      *(outbuffer + offset + 0) = (u_min_scan_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_scan_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_scan_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_scan_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_scan_range);
      union {
        float real;
        uint32_t base;
      } u_max_scan_range;
      u_max_scan_range.real = this->max_scan_range;
      *(outbuffer + offset + 0) = (u_max_scan_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_scan_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_scan_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_scan_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_scan_range);
      union {
        float real;
        uint32_t base;
      } u_min_add_scan_shift;
      u_min_add_scan_shift.real = this->min_add_scan_shift;
      *(outbuffer + offset + 0) = (u_min_add_scan_shift.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_add_scan_shift.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_add_scan_shift.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_add_scan_shift.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_add_scan_shift);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_resolution;
      u_resolution.base = 0;
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->resolution = u_resolution.real;
      offset += sizeof(this->resolution);
      union {
        float real;
        uint32_t base;
      } u_step_size;
      u_step_size.base = 0;
      u_step_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_step_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_step_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_step_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->step_size = u_step_size.real;
      offset += sizeof(this->step_size);
      union {
        float real;
        uint32_t base;
      } u_trans_epsilon;
      u_trans_epsilon.base = 0;
      u_trans_epsilon.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_trans_epsilon.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_trans_epsilon.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_trans_epsilon.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->trans_epsilon = u_trans_epsilon.real;
      offset += sizeof(this->trans_epsilon);
      union {
        int32_t real;
        uint32_t base;
      } u_max_iterations;
      u_max_iterations.base = 0;
      u_max_iterations.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_iterations.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_iterations.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_iterations.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_iterations = u_max_iterations.real;
      offset += sizeof(this->max_iterations);
      union {
        float real;
        uint32_t base;
      } u_leaf_size;
      u_leaf_size.base = 0;
      u_leaf_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_leaf_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_leaf_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_leaf_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->leaf_size = u_leaf_size.real;
      offset += sizeof(this->leaf_size);
      union {
        float real;
        uint32_t base;
      } u_min_scan_range;
      u_min_scan_range.base = 0;
      u_min_scan_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_scan_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_scan_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_scan_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_scan_range = u_min_scan_range.real;
      offset += sizeof(this->min_scan_range);
      union {
        float real;
        uint32_t base;
      } u_max_scan_range;
      u_max_scan_range.base = 0;
      u_max_scan_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_scan_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_scan_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_scan_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_scan_range = u_max_scan_range.real;
      offset += sizeof(this->max_scan_range);
      union {
        float real;
        uint32_t base;
      } u_min_add_scan_shift;
      u_min_add_scan_shift.base = 0;
      u_min_add_scan_shift.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_add_scan_shift.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_add_scan_shift.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_add_scan_shift.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_add_scan_shift = u_min_add_scan_shift.real;
      offset += sizeof(this->min_add_scan_shift);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigNDTMapping"; };
    const char * getMD5(){ return "009eea81638fe982213cc00d902d0e71"; };

  };

}
#endif