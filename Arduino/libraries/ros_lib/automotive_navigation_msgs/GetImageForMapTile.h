#ifndef _ROS_SERVICE_GetImageForMapTile_h
#define _ROS_SERVICE_GetImageForMapTile_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace automotive_navigation_msgs
{

static const char GETIMAGEFORMAPTILE[] = "automotive_navigation_msgs/GetImageForMapTile";

  class GetImageForMapTileRequest : public ros::Msg
  {
    public:
      typedef const char* _tile_id_type;
      _tile_id_type tile_id;

    GetImageForMapTileRequest():
      tile_id("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_tile_id = strlen(this->tile_id);
      varToArr(outbuffer + offset, length_tile_id);
      offset += 4;
      memcpy(outbuffer + offset, this->tile_id, length_tile_id);
      offset += length_tile_id;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_tile_id;
      arrToVar(length_tile_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_tile_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_tile_id-1]=0;
      this->tile_id = (char *)(inbuffer + offset-1);
      offset += length_tile_id;
     return offset;
    }

    const char * getType(){ return GETIMAGEFORMAPTILE; };
    const char * getMD5(){ return "2be2eb8c0f93d54729bfeee9526fd294"; };

  };

  class GetImageForMapTileResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;

    GetImageForMapTileResponse():
      success(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    const char * getType(){ return GETIMAGEFORMAPTILE; };
    const char * getMD5(){ return "937c9679a518e3a18d831e57125ea522"; };

  };

  class GetImageForMapTile {
    public:
    typedef GetImageForMapTileRequest Request;
    typedef GetImageForMapTileResponse Response;
  };

}
#endif
