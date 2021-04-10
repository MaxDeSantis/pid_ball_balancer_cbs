#ifndef _ROS_pacmod_msgs_VinRpt_h
#define _ROS_pacmod_msgs_VinRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class VinRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _mfg_code_type;
      _mfg_code_type mfg_code;
      typedef const char* _mfg_type;
      _mfg_type mfg;
      typedef const char* _model_year_code_type;
      _model_year_code_type model_year_code;
      typedef uint32_t _model_year_type;
      _model_year_type model_year;
      typedef uint32_t _serial_type;
      _serial_type serial;

    VinRpt():
      header(),
      mfg_code(""),
      mfg(""),
      model_year_code(""),
      model_year(0),
      serial(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_mfg_code = strlen(this->mfg_code);
      varToArr(outbuffer + offset, length_mfg_code);
      offset += 4;
      memcpy(outbuffer + offset, this->mfg_code, length_mfg_code);
      offset += length_mfg_code;
      uint32_t length_mfg = strlen(this->mfg);
      varToArr(outbuffer + offset, length_mfg);
      offset += 4;
      memcpy(outbuffer + offset, this->mfg, length_mfg);
      offset += length_mfg;
      uint32_t length_model_year_code = strlen(this->model_year_code);
      varToArr(outbuffer + offset, length_model_year_code);
      offset += 4;
      memcpy(outbuffer + offset, this->model_year_code, length_model_year_code);
      offset += length_model_year_code;
      *(outbuffer + offset + 0) = (this->model_year >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->model_year >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->model_year >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->model_year >> (8 * 3)) & 0xFF;
      offset += sizeof(this->model_year);
      *(outbuffer + offset + 0) = (this->serial >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->serial >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->serial >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->serial >> (8 * 3)) & 0xFF;
      offset += sizeof(this->serial);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_mfg_code;
      arrToVar(length_mfg_code, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mfg_code; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mfg_code-1]=0;
      this->mfg_code = (char *)(inbuffer + offset-1);
      offset += length_mfg_code;
      uint32_t length_mfg;
      arrToVar(length_mfg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mfg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mfg-1]=0;
      this->mfg = (char *)(inbuffer + offset-1);
      offset += length_mfg;
      uint32_t length_model_year_code;
      arrToVar(length_model_year_code, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model_year_code; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model_year_code-1]=0;
      this->model_year_code = (char *)(inbuffer + offset-1);
      offset += length_model_year_code;
      this->model_year =  ((uint32_t) (*(inbuffer + offset)));
      this->model_year |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->model_year |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->model_year |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->model_year);
      this->serial =  ((uint32_t) (*(inbuffer + offset)));
      this->serial |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->serial |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->serial |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->serial);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/VinRpt"; };
    const char * getMD5(){ return "9adca84caaa097b32fc7b71a0ca8da36"; };

  };

}
#endif