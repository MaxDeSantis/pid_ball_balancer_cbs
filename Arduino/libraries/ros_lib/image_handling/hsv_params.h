#ifndef _ROS_image_handling_hsv_params_h
#define _ROS_image_handling_hsv_params_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace image_handling
{

  class hsv_params : public ros::Msg
  {
    public:
      typedef int64_t _hueLower_type;
      _hueLower_type hueLower;
      typedef int64_t _hueUpper_type;
      _hueUpper_type hueUpper;
      typedef int64_t _satLower_type;
      _satLower_type satLower;
      typedef int64_t _satUpper_type;
      _satUpper_type satUpper;
      typedef int64_t _valLower_type;
      _valLower_type valLower;
      typedef int64_t _valUpper_type;
      _valUpper_type valUpper;

    hsv_params():
      hueLower(0),
      hueUpper(0),
      satLower(0),
      satUpper(0),
      valLower(0),
      valUpper(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_hueLower;
      u_hueLower.real = this->hueLower;
      *(outbuffer + offset + 0) = (u_hueLower.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hueLower.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hueLower.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hueLower.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_hueLower.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_hueLower.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_hueLower.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_hueLower.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->hueLower);
      union {
        int64_t real;
        uint64_t base;
      } u_hueUpper;
      u_hueUpper.real = this->hueUpper;
      *(outbuffer + offset + 0) = (u_hueUpper.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hueUpper.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hueUpper.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hueUpper.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_hueUpper.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_hueUpper.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_hueUpper.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_hueUpper.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->hueUpper);
      union {
        int64_t real;
        uint64_t base;
      } u_satLower;
      u_satLower.real = this->satLower;
      *(outbuffer + offset + 0) = (u_satLower.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_satLower.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_satLower.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_satLower.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_satLower.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_satLower.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_satLower.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_satLower.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->satLower);
      union {
        int64_t real;
        uint64_t base;
      } u_satUpper;
      u_satUpper.real = this->satUpper;
      *(outbuffer + offset + 0) = (u_satUpper.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_satUpper.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_satUpper.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_satUpper.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_satUpper.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_satUpper.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_satUpper.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_satUpper.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->satUpper);
      union {
        int64_t real;
        uint64_t base;
      } u_valLower;
      u_valLower.real = this->valLower;
      *(outbuffer + offset + 0) = (u_valLower.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_valLower.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_valLower.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_valLower.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_valLower.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_valLower.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_valLower.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_valLower.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->valLower);
      union {
        int64_t real;
        uint64_t base;
      } u_valUpper;
      u_valUpper.real = this->valUpper;
      *(outbuffer + offset + 0) = (u_valUpper.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_valUpper.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_valUpper.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_valUpper.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_valUpper.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_valUpper.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_valUpper.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_valUpper.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->valUpper);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_hueLower;
      u_hueLower.base = 0;
      u_hueLower.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hueLower.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hueLower.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hueLower.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_hueLower.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_hueLower.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_hueLower.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_hueLower.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->hueLower = u_hueLower.real;
      offset += sizeof(this->hueLower);
      union {
        int64_t real;
        uint64_t base;
      } u_hueUpper;
      u_hueUpper.base = 0;
      u_hueUpper.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hueUpper.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hueUpper.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hueUpper.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_hueUpper.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_hueUpper.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_hueUpper.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_hueUpper.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->hueUpper = u_hueUpper.real;
      offset += sizeof(this->hueUpper);
      union {
        int64_t real;
        uint64_t base;
      } u_satLower;
      u_satLower.base = 0;
      u_satLower.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_satLower.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_satLower.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_satLower.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_satLower.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_satLower.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_satLower.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_satLower.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->satLower = u_satLower.real;
      offset += sizeof(this->satLower);
      union {
        int64_t real;
        uint64_t base;
      } u_satUpper;
      u_satUpper.base = 0;
      u_satUpper.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_satUpper.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_satUpper.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_satUpper.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_satUpper.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_satUpper.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_satUpper.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_satUpper.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->satUpper = u_satUpper.real;
      offset += sizeof(this->satUpper);
      union {
        int64_t real;
        uint64_t base;
      } u_valLower;
      u_valLower.base = 0;
      u_valLower.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_valLower.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_valLower.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_valLower.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_valLower.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_valLower.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_valLower.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_valLower.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->valLower = u_valLower.real;
      offset += sizeof(this->valLower);
      union {
        int64_t real;
        uint64_t base;
      } u_valUpper;
      u_valUpper.base = 0;
      u_valUpper.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_valUpper.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_valUpper.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_valUpper.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_valUpper.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_valUpper.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_valUpper.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_valUpper.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->valUpper = u_valUpper.real;
      offset += sizeof(this->valUpper);
     return offset;
    }

    const char * getType(){ return "image_handling/hsv_params"; };
    const char * getMD5(){ return "6861bd27ee7eb24c57eaeef1d9207b19"; };

  };

}
#endif