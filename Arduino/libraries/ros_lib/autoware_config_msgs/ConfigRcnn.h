#ifndef _ROS_autoware_config_msgs_ConfigRcnn_h
#define _ROS_autoware_config_msgs_ConfigRcnn_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigRcnn : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _score_threshold_type;
      _score_threshold_type score_threshold;
      typedef float _group_threshold_type;
      _group_threshold_type group_threshold;
      typedef float _slices_overlap_type;
      _slices_overlap_type slices_overlap;
      typedef float _b_mean_type;
      _b_mean_type b_mean;
      typedef float _g_mean_type;
      _g_mean_type g_mean;
      typedef float _r_mean_type;
      _r_mean_type r_mean;
      typedef uint8_t _image_slices_type;
      _image_slices_type image_slices;
      typedef uint8_t _use_gpu_type;
      _use_gpu_type use_gpu;
      typedef uint8_t _gpu_device_id_type;
      _gpu_device_id_type gpu_device_id;

    ConfigRcnn():
      header(),
      score_threshold(0),
      group_threshold(0),
      slices_overlap(0),
      b_mean(0),
      g_mean(0),
      r_mean(0),
      image_slices(0),
      use_gpu(0),
      gpu_device_id(0)
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
        float real;
        uint32_t base;
      } u_slices_overlap;
      u_slices_overlap.real = this->slices_overlap;
      *(outbuffer + offset + 0) = (u_slices_overlap.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_slices_overlap.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_slices_overlap.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_slices_overlap.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->slices_overlap);
      union {
        float real;
        uint32_t base;
      } u_b_mean;
      u_b_mean.real = this->b_mean;
      *(outbuffer + offset + 0) = (u_b_mean.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_b_mean.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_b_mean.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_b_mean.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->b_mean);
      union {
        float real;
        uint32_t base;
      } u_g_mean;
      u_g_mean.real = this->g_mean;
      *(outbuffer + offset + 0) = (u_g_mean.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_g_mean.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_g_mean.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_g_mean.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->g_mean);
      union {
        float real;
        uint32_t base;
      } u_r_mean;
      u_r_mean.real = this->r_mean;
      *(outbuffer + offset + 0) = (u_r_mean.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_r_mean.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_r_mean.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_r_mean.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->r_mean);
      *(outbuffer + offset + 0) = (this->image_slices >> (8 * 0)) & 0xFF;
      offset += sizeof(this->image_slices);
      *(outbuffer + offset + 0) = (this->use_gpu >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_gpu);
      *(outbuffer + offset + 0) = (this->gpu_device_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gpu_device_id);
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
        float real;
        uint32_t base;
      } u_slices_overlap;
      u_slices_overlap.base = 0;
      u_slices_overlap.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_slices_overlap.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_slices_overlap.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_slices_overlap.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->slices_overlap = u_slices_overlap.real;
      offset += sizeof(this->slices_overlap);
      union {
        float real;
        uint32_t base;
      } u_b_mean;
      u_b_mean.base = 0;
      u_b_mean.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_b_mean.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_b_mean.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_b_mean.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->b_mean = u_b_mean.real;
      offset += sizeof(this->b_mean);
      union {
        float real;
        uint32_t base;
      } u_g_mean;
      u_g_mean.base = 0;
      u_g_mean.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_g_mean.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_g_mean.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_g_mean.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->g_mean = u_g_mean.real;
      offset += sizeof(this->g_mean);
      union {
        float real;
        uint32_t base;
      } u_r_mean;
      u_r_mean.base = 0;
      u_r_mean.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_r_mean.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_r_mean.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_r_mean.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->r_mean = u_r_mean.real;
      offset += sizeof(this->r_mean);
      this->image_slices =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->image_slices);
      this->use_gpu =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->use_gpu);
      this->gpu_device_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gpu_device_id);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigRcnn"; };
    const char * getMD5(){ return "f51f68bdedfbe5da5d10ace3c7a60ff0"; };

  };

}
#endif