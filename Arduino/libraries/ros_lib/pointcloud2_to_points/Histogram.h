#ifndef _ROS_pointcloud2_to_points_Histogram_h
#define _ROS_pointcloud2_to_points_Histogram_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pointcloud2_to_points
{

  class Histogram : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t binNames_length;
      typedef char* _binNames_type;
      _binNames_type st_binNames;
      _binNames_type * binNames;
      uint32_t bin_length;
      typedef int32_t _bin_type;
      _bin_type st_bin;
      _bin_type * bin;

    Histogram():
      header(),
      binNames_length(0), binNames(NULL),
      bin_length(0), bin(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->binNames_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->binNames_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->binNames_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->binNames_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->binNames_length);
      for( uint32_t i = 0; i < binNames_length; i++){
      uint32_t length_binNamesi = strlen(this->binNames[i]);
      varToArr(outbuffer + offset, length_binNamesi);
      offset += 4;
      memcpy(outbuffer + offset, this->binNames[i], length_binNamesi);
      offset += length_binNamesi;
      }
      *(outbuffer + offset + 0) = (this->bin_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bin_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->bin_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->bin_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bin_length);
      for( uint32_t i = 0; i < bin_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_bini;
      u_bini.real = this->bin[i];
      *(outbuffer + offset + 0) = (u_bini.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bini.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bini.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bini.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bin[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t binNames_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      binNames_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      binNames_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      binNames_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->binNames_length);
      if(binNames_lengthT > binNames_length)
        this->binNames = (char**)realloc(this->binNames, binNames_lengthT * sizeof(char*));
      binNames_length = binNames_lengthT;
      for( uint32_t i = 0; i < binNames_length; i++){
      uint32_t length_st_binNames;
      arrToVar(length_st_binNames, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_binNames; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_binNames-1]=0;
      this->st_binNames = (char *)(inbuffer + offset-1);
      offset += length_st_binNames;
        memcpy( &(this->binNames[i]), &(this->st_binNames), sizeof(char*));
      }
      uint32_t bin_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      bin_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      bin_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      bin_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->bin_length);
      if(bin_lengthT > bin_length)
        this->bin = (int32_t*)realloc(this->bin, bin_lengthT * sizeof(int32_t));
      bin_length = bin_lengthT;
      for( uint32_t i = 0; i < bin_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_bin;
      u_st_bin.base = 0;
      u_st_bin.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_bin.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_bin.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_bin.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_bin = u_st_bin.real;
      offset += sizeof(this->st_bin);
        memcpy( &(this->bin[i]), &(this->st_bin), sizeof(int32_t));
      }
     return offset;
    }

    const char * getType(){ return "pointcloud2_to_points/Histogram"; };
    const char * getMD5(){ return "2a18463dddcaa69e03e011e6398553bf"; };

  };

}
#endif