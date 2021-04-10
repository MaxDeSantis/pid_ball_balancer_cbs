#ifndef _ROS_automotive_navigation_msgs_PointOfInterestStatus_h
#define _ROS_automotive_navigation_msgs_PointOfInterestStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace automotive_navigation_msgs
{

  class PointOfInterestStatus : public ros::Msg
  {
    public:
      typedef uint64_t _guid_type;
      _guid_type guid;
      typedef float _distance_type;
      _distance_type distance;
      typedef float _heading_type;
      _heading_type heading;
      typedef float _x_position_type;
      _x_position_type x_position;
      typedef float _y_position_type;
      _y_position_type y_position;
      typedef const char* _params_type;
      _params_type params;

    PointOfInterestStatus():
      guid(0),
      distance(0),
      heading(0),
      x_position(0),
      y_position(0),
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
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.real = this->distance;
      *(outbuffer + offset + 0) = (u_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance);
      union {
        float real;
        uint32_t base;
      } u_heading;
      u_heading.real = this->heading;
      *(outbuffer + offset + 0) = (u_heading.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heading.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heading.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heading.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->heading);
      union {
        float real;
        uint32_t base;
      } u_x_position;
      u_x_position.real = this->x_position;
      *(outbuffer + offset + 0) = (u_x_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_position.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x_position);
      union {
        float real;
        uint32_t base;
      } u_y_position;
      u_y_position.real = this->y_position;
      *(outbuffer + offset + 0) = (u_y_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y_position.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y_position);
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
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.base = 0;
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance = u_distance.real;
      offset += sizeof(this->distance);
      union {
        float real;
        uint32_t base;
      } u_heading;
      u_heading.base = 0;
      u_heading.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heading.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_heading.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_heading.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->heading = u_heading.real;
      offset += sizeof(this->heading);
      union {
        float real;
        uint32_t base;
      } u_x_position;
      u_x_position.base = 0;
      u_x_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x_position = u_x_position.real;
      offset += sizeof(this->x_position);
      union {
        float real;
        uint32_t base;
      } u_y_position;
      u_y_position.base = 0;
      u_y_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y_position = u_y_position.real;
      offset += sizeof(this->y_position);
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

    const char * getType(){ return "automotive_navigation_msgs/PointOfInterestStatus"; };
    const char * getMD5(){ return "3747ebda6c320e19738cf7561a6a689b"; };

  };

}
#endif