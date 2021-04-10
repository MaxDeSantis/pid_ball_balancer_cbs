#ifndef _ROS_autoware_msgs_VehicleStatus_h
#define _ROS_autoware_msgs_VehicleStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_msgs
{

  class VehicleStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _tm_type;
      _tm_type tm;
      typedef int32_t _drivemode_type;
      _drivemode_type drivemode;
      typedef int32_t _steeringmode_type;
      _steeringmode_type steeringmode;
      typedef int32_t _gearshift_type;
      _gearshift_type gearshift;
      typedef float _speed_type;
      _speed_type speed;
      typedef int32_t _drivepedal_type;
      _drivepedal_type drivepedal;
      typedef int32_t _brakepedal_type;
      _brakepedal_type brakepedal;
      typedef float _angle_type;
      _angle_type angle;
      typedef int32_t _lamp_type;
      _lamp_type lamp;
      typedef int32_t _light_type;
      _light_type light;
      enum { MODE_MANUAL = 0 };
      enum { MODE_AUTO = 1 };
      enum { LAMP_LEFT = 1 };
      enum { LAMP_RIGHT = 2 };
      enum { LAMP_HAZARD = 3 };

    VehicleStatus():
      header(),
      tm(""),
      drivemode(0),
      steeringmode(0),
      gearshift(0),
      speed(0),
      drivepedal(0),
      brakepedal(0),
      angle(0),
      lamp(0),
      light(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_tm = strlen(this->tm);
      varToArr(outbuffer + offset, length_tm);
      offset += 4;
      memcpy(outbuffer + offset, this->tm, length_tm);
      offset += length_tm;
      union {
        int32_t real;
        uint32_t base;
      } u_drivemode;
      u_drivemode.real = this->drivemode;
      *(outbuffer + offset + 0) = (u_drivemode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_drivemode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_drivemode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_drivemode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->drivemode);
      union {
        int32_t real;
        uint32_t base;
      } u_steeringmode;
      u_steeringmode.real = this->steeringmode;
      *(outbuffer + offset + 0) = (u_steeringmode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steeringmode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steeringmode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steeringmode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steeringmode);
      union {
        int32_t real;
        uint32_t base;
      } u_gearshift;
      u_gearshift.real = this->gearshift;
      *(outbuffer + offset + 0) = (u_gearshift.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gearshift.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gearshift.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gearshift.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gearshift);
      offset += serializeAvrFloat64(outbuffer + offset, this->speed);
      union {
        int32_t real;
        uint32_t base;
      } u_drivepedal;
      u_drivepedal.real = this->drivepedal;
      *(outbuffer + offset + 0) = (u_drivepedal.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_drivepedal.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_drivepedal.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_drivepedal.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->drivepedal);
      union {
        int32_t real;
        uint32_t base;
      } u_brakepedal;
      u_brakepedal.real = this->brakepedal;
      *(outbuffer + offset + 0) = (u_brakepedal.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_brakepedal.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_brakepedal.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_brakepedal.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->brakepedal);
      offset += serializeAvrFloat64(outbuffer + offset, this->angle);
      union {
        int32_t real;
        uint32_t base;
      } u_lamp;
      u_lamp.real = this->lamp;
      *(outbuffer + offset + 0) = (u_lamp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lamp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lamp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lamp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lamp);
      union {
        int32_t real;
        uint32_t base;
      } u_light;
      u_light.real = this->light;
      *(outbuffer + offset + 0) = (u_light.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_light.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_light.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_light.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->light);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_tm;
      arrToVar(length_tm, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_tm; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_tm-1]=0;
      this->tm = (char *)(inbuffer + offset-1);
      offset += length_tm;
      union {
        int32_t real;
        uint32_t base;
      } u_drivemode;
      u_drivemode.base = 0;
      u_drivemode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_drivemode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_drivemode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_drivemode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->drivemode = u_drivemode.real;
      offset += sizeof(this->drivemode);
      union {
        int32_t real;
        uint32_t base;
      } u_steeringmode;
      u_steeringmode.base = 0;
      u_steeringmode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steeringmode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steeringmode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steeringmode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steeringmode = u_steeringmode.real;
      offset += sizeof(this->steeringmode);
      union {
        int32_t real;
        uint32_t base;
      } u_gearshift;
      u_gearshift.base = 0;
      u_gearshift.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gearshift.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gearshift.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gearshift.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gearshift = u_gearshift.real;
      offset += sizeof(this->gearshift);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->speed));
      union {
        int32_t real;
        uint32_t base;
      } u_drivepedal;
      u_drivepedal.base = 0;
      u_drivepedal.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_drivepedal.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_drivepedal.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_drivepedal.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->drivepedal = u_drivepedal.real;
      offset += sizeof(this->drivepedal);
      union {
        int32_t real;
        uint32_t base;
      } u_brakepedal;
      u_brakepedal.base = 0;
      u_brakepedal.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_brakepedal.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_brakepedal.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_brakepedal.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->brakepedal = u_brakepedal.real;
      offset += sizeof(this->brakepedal);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angle));
      union {
        int32_t real;
        uint32_t base;
      } u_lamp;
      u_lamp.base = 0;
      u_lamp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lamp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lamp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lamp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lamp = u_lamp.real;
      offset += sizeof(this->lamp);
      union {
        int32_t real;
        uint32_t base;
      } u_light;
      u_light.base = 0;
      u_light.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_light.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_light.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_light.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->light = u_light.real;
      offset += sizeof(this->light);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/VehicleStatus"; };
    const char * getMD5(){ return "77768c58b46a9120bd1fae64c52b3a77"; };

  };

}
#endif