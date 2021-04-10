#ifndef _ROS_autoware_config_msgs_ConfigNDTMappingOutput_h
#define _ROS_autoware_config_msgs_ConfigNDTMappingOutput_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigNDTMappingOutput : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _filename_type;
      _filename_type filename;
      typedef float _filter_res_type;
      _filter_res_type filter_res;

    ConfigNDTMappingOutput():
      header(),
      filename(""),
      filter_res(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_filename = strlen(this->filename);
      varToArr(outbuffer + offset, length_filename);
      offset += 4;
      memcpy(outbuffer + offset, this->filename, length_filename);
      offset += length_filename;
      union {
        float real;
        uint32_t base;
      } u_filter_res;
      u_filter_res.real = this->filter_res;
      *(outbuffer + offset + 0) = (u_filter_res.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filter_res.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filter_res.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filter_res.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->filter_res);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_filename;
      arrToVar(length_filename, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_filename; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_filename-1]=0;
      this->filename = (char *)(inbuffer + offset-1);
      offset += length_filename;
      union {
        float real;
        uint32_t base;
      } u_filter_res;
      u_filter_res.base = 0;
      u_filter_res.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filter_res.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filter_res.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filter_res.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->filter_res = u_filter_res.real;
      offset += sizeof(this->filter_res);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigNDTMappingOutput"; };
    const char * getMD5(){ return "ac31ee963c2f2d01d1d409a7749c20f6"; };

  };

}
#endif