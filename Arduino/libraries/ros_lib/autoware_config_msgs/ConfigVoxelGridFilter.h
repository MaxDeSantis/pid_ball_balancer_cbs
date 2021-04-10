#ifndef _ROS_autoware_config_msgs_ConfigVoxelGridFilter_h
#define _ROS_autoware_config_msgs_ConfigVoxelGridFilter_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_config_msgs
{

  class ConfigVoxelGridFilter : public ros::Msg
  {
    public:
      typedef float _voxel_leaf_size_type;
      _voxel_leaf_size_type voxel_leaf_size;
      typedef float _measurement_range_type;
      _measurement_range_type measurement_range;

    ConfigVoxelGridFilter():
      voxel_leaf_size(0),
      measurement_range(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_voxel_leaf_size;
      u_voxel_leaf_size.real = this->voxel_leaf_size;
      *(outbuffer + offset + 0) = (u_voxel_leaf_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voxel_leaf_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voxel_leaf_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voxel_leaf_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voxel_leaf_size);
      union {
        float real;
        uint32_t base;
      } u_measurement_range;
      u_measurement_range.real = this->measurement_range;
      *(outbuffer + offset + 0) = (u_measurement_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_measurement_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_measurement_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_measurement_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->measurement_range);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_voxel_leaf_size;
      u_voxel_leaf_size.base = 0;
      u_voxel_leaf_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voxel_leaf_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voxel_leaf_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voxel_leaf_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->voxel_leaf_size = u_voxel_leaf_size.real;
      offset += sizeof(this->voxel_leaf_size);
      union {
        float real;
        uint32_t base;
      } u_measurement_range;
      u_measurement_range.base = 0;
      u_measurement_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_measurement_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_measurement_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_measurement_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->measurement_range = u_measurement_range.real;
      offset += sizeof(this->measurement_range);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigVoxelGridFilter"; };
    const char * getMD5(){ return "66366259bef07d6d7826a63b83ed5b70"; };

  };

}
#endif