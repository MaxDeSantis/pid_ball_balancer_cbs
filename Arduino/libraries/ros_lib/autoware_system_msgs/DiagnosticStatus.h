#ifndef _ROS_autoware_system_msgs_DiagnosticStatus_h
#define _ROS_autoware_system_msgs_DiagnosticStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_system_msgs
{

  class DiagnosticStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _key_type;
      _key_type key;
      typedef const char* _value_type;
      _value_type value;
      typedef const char* _description_type;
      _description_type description;
      typedef uint8_t _type_type;
      _type_type type;
      typedef uint8_t _level_type;
      _level_type level;
      enum { UNDEFINED =  0 };
      enum { OUT_OF_RANGE =  1 };
      enum { RATE_IS_SLOW =  2 };
      enum { HARDWARE =  255 };
      enum { OK =  1 };
      enum { WARN =  2 };
      enum { ERROR =  3 };
      enum { FATAL =  4 };

    DiagnosticStatus():
      header(),
      key(""),
      value(""),
      description(""),
      type(0),
      level(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_key = strlen(this->key);
      varToArr(outbuffer + offset, length_key);
      offset += 4;
      memcpy(outbuffer + offset, this->key, length_key);
      offset += length_key;
      uint32_t length_value = strlen(this->value);
      varToArr(outbuffer + offset, length_value);
      offset += 4;
      memcpy(outbuffer + offset, this->value, length_value);
      offset += length_value;
      uint32_t length_description = strlen(this->description);
      varToArr(outbuffer + offset, length_description);
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_description);
      offset += length_description;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->level >> (8 * 0)) & 0xFF;
      offset += sizeof(this->level);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_key;
      arrToVar(length_key, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_key; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_key-1]=0;
      this->key = (char *)(inbuffer + offset-1);
      offset += length_key;
      uint32_t length_value;
      arrToVar(length_value, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_value; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_value-1]=0;
      this->value = (char *)(inbuffer + offset-1);
      offset += length_value;
      uint32_t length_description;
      arrToVar(length_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_description;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      this->level =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->level);
     return offset;
    }

    const char * getType(){ return "autoware_system_msgs/DiagnosticStatus"; };
    const char * getMD5(){ return "6c3db7fb4a3aac47a2b0c51e9b4e3539"; };

  };

}
#endif