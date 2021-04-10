#ifndef _ROS_autoware_msgs_TrafficLightResult_h
#define _ROS_autoware_msgs_TrafficLightResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_msgs
{

  class TrafficLightResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _light_id_type;
      _light_id_type light_id;
      typedef int32_t _recognition_result_type;
      _recognition_result_type recognition_result;
      typedef const char* _recognition_result_str_type;
      _recognition_result_str_type recognition_result_str;
      typedef int32_t _lane_id_type;
      _lane_id_type lane_id;

    TrafficLightResult():
      header(),
      light_id(0),
      recognition_result(0),
      recognition_result_str(""),
      lane_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_light_id;
      u_light_id.real = this->light_id;
      *(outbuffer + offset + 0) = (u_light_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_light_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_light_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_light_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->light_id);
      union {
        int32_t real;
        uint32_t base;
      } u_recognition_result;
      u_recognition_result.real = this->recognition_result;
      *(outbuffer + offset + 0) = (u_recognition_result.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_recognition_result.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_recognition_result.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_recognition_result.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->recognition_result);
      uint32_t length_recognition_result_str = strlen(this->recognition_result_str);
      varToArr(outbuffer + offset, length_recognition_result_str);
      offset += 4;
      memcpy(outbuffer + offset, this->recognition_result_str, length_recognition_result_str);
      offset += length_recognition_result_str;
      union {
        int32_t real;
        uint32_t base;
      } u_lane_id;
      u_lane_id.real = this->lane_id;
      *(outbuffer + offset + 0) = (u_lane_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_light_id;
      u_light_id.base = 0;
      u_light_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_light_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_light_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_light_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->light_id = u_light_id.real;
      offset += sizeof(this->light_id);
      union {
        int32_t real;
        uint32_t base;
      } u_recognition_result;
      u_recognition_result.base = 0;
      u_recognition_result.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_recognition_result.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_recognition_result.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_recognition_result.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->recognition_result = u_recognition_result.real;
      offset += sizeof(this->recognition_result);
      uint32_t length_recognition_result_str;
      arrToVar(length_recognition_result_str, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_recognition_result_str; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_recognition_result_str-1]=0;
      this->recognition_result_str = (char *)(inbuffer + offset-1);
      offset += length_recognition_result_str;
      union {
        int32_t real;
        uint32_t base;
      } u_lane_id;
      u_lane_id.base = 0;
      u_lane_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lane_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lane_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lane_id = u_lane_id.real;
      offset += sizeof(this->lane_id);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/TrafficLightResult"; };
    const char * getMD5(){ return "e09c50b47f3c14abf01fe3d89587b0eb"; };

  };

}
#endif