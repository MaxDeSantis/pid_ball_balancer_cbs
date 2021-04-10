#ifndef _ROS_automotive_navigation_msgs_PointOfInterest_h
#define _ROS_automotive_navigation_msgs_PointOfInterest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace automotive_navigation_msgs
{

  class PointOfInterest : public ros::Msg
  {
    public:
      typedef uint64_t _guid_type;
      _guid_type guid;
      typedef float _latitude_type;
      _latitude_type latitude;
      typedef float _longitude_type;
      _longitude_type longitude;
      typedef const char* _params_type;
      _params_type params;

    PointOfInterest():
      guid(0),
      latitude(0),
      longitude(0),
      params("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_guid;
      u_guid.real = this->guid;
      *(outbuffer + offset + 0) = (u_guid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_guid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_guid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_guid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->guid);
      offset += serializeAvrFloat64(outbuffer + offset, this->latitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->longitude);
      uint32_t length_params = strlen(this->params);
      varToArr(outbuffer + offset, length_params);
      offset += 4;
      memcpy(outbuffer + offset, this->params, length_params);
      offset += length_params;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_guid;
      u_guid.base = 0;
      u_guid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_guid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_guid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_guid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->guid = u_guid.real;
      offset += sizeof(this->guid);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->latitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->longitude));
      uint32_t length_params;
      arrToVar(length_params, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_params; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_params-1]=0;
      this->params = (char *)(inbuffer + offset-1);
      offset += length_params;
     return offset;
    }

    const char * getType(){ return "automotive_navigation_msgs/PointOfInterest"; };
    const char * getMD5(){ return "e13bf4b872a022336936c4b575654650"; };

  };

}
#endif