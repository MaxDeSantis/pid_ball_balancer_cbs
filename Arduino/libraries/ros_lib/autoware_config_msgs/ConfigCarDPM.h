#ifndef _ROS_autoware_config_msgs_ConfigCarDPM_h
#define _ROS_autoware_config_msgs_ConfigCarDPM_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigCarDPM : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _score_threshold_type;
      _score_threshold_type score_threshold;
      typedef float _group_threshold_type;
      _group_threshold_type group_threshold;
      typedef int32_t _Lambda_type;
      _Lambda_type Lambda;
      typedef int32_t _num_cells_type;
      _num_cells_type num_cells;
      typedef int32_t _num_bins_type;
      _num_bins_type num_bins;

    ConfigCarDPM():
      header(),
      score_threshold(0),
      group_threshold(0),
      Lambda(0),
      num_cells(0),
      num_bins(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_score_threshold;
      u_score_threshold.real = this->score_threshold;
      *(outbuffer + offset + 0) = (u_score_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_score_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_score_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_score_threshold.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->score_threshold);
      union {
        float real;
        uint32_t base;
      } u_group_threshold;
      u_group_threshold.real = this->group_threshold;
      *(outbuffer + offset + 0) = (u_group_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_group_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_group_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_group_threshold.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->group_threshold);
      union {
        int32_t real;
        uint32_t base;
      } u_Lambda;
      u_Lambda.real = this->Lambda;
      *(outbuffer + offset + 0) = (u_Lambda.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Lambda.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Lambda.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Lambda.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Lambda);
      union {
        int32_t real;
        uint32_t base;
      } u_num_cells;
      u_num_cells.real = this->num_cells;
      *(outbuffer + offset + 0) = (u_num_cells.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_cells.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_cells.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_cells.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_cells);
      union {
        int32_t real;
        uint32_t base;
      } u_num_bins;
      u_num_bins.real = this->num_bins;
      *(outbuffer + offset + 0) = (u_num_bins.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_bins.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_bins.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_bins.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_bins);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_score_threshold;
      u_score_threshold.base = 0;
      u_score_threshold.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_score_threshold.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_score_threshold.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_score_threshold.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->score_threshold = u_score_threshold.real;
      offset += sizeof(this->score_threshold);
      union {
        float real;
        uint32_t base;
      } u_group_threshold;
      u_group_threshold.base = 0;
      u_group_threshold.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_group_threshold.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_group_threshold.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_group_threshold.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->group_threshold = u_group_threshold.real;
      offset += sizeof(this->group_threshold);
      union {
        int32_t real;
        uint32_t base;
      } u_Lambda;
      u_Lambda.base = 0;
      u_Lambda.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Lambda.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Lambda.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Lambda.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Lambda = u_Lambda.real;
      offset += sizeof(this->Lambda);
      union {
        int32_t real;
        uint32_t base;
      } u_num_cells;
      u_num_cells.base = 0;
      u_num_cells.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_cells.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_cells.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_cells.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_cells = u_num_cells.real;
      offset += sizeof(this->num_cells);
      union {
        int32_t real;
        uint32_t base;
      } u_num_bins;
      u_num_bins.base = 0;
      u_num_bins.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_bins.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_bins.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_bins.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_bins = u_num_bins.real;
      offset += sizeof(this->num_bins);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigCarDPM"; };
    const char * getMD5(){ return "4aad5f13bbefe1a8707af2b040e45167"; };

  };

}
#endif