#ifndef _ROS_automotive_navigation_msgs_PointOfInterestRequest_h
#define _ROS_automotive_navigation_msgs_PointOfInterestRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_navigation_msgs
{

  class PointOfInterestRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _module_name_type;
      _module_name_type module_name;
      typedef uint16_t _request_id_type;
      _request_id_type request_id;
      typedef uint16_t _cancel_type;
      _cancel_type cancel;
      typedef uint16_t _update_num_type;
      _update_num_type update_num;
      typedef uint16_t _guid_valid_type;
      _guid_valid_type guid_valid;
      typedef uint64_t _guid_type;
      _guid_type guid;
      typedef float _tolerance_type;
      _tolerance_type tolerance;

    PointOfInterestRequest():
      header(),
      name(""),
      module_name(""),
      request_id(0),
      cancel(0),
      update_num(0),
      guid_valid(0),
      guid(0),
      tolerance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_module_name = strlen(this->module_name);
      varToArr(outbuffer + offset, length_module_name);
      offset += 4;
      memcpy(outbuffer + offset, this->module_name, length_module_name);
      offset += length_module_name;
      *(outbuffer + offset + 0) = (this->request_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->request_id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->request_id);
      *(outbuffer + offset + 0) = (this->cancel >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cancel >> (8 * 1)) & 0xFF;
      offset += sizeof(this->cancel);
      *(outbuffer + offset + 0) = (this->update_num >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->update_num >> (8 * 1)) & 0xFF;
      offset += sizeof(this->update_num);
      *(outbuffer + offset + 0) = (this->guid_valid >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->guid_valid >> (8 * 1)) & 0xFF;
      offset += sizeof(this->guid_valid);
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
      } u_tolerance;
      u_tolerance.real = this->tolerance;
      *(outbuffer + offset + 0) = (u_tolerance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tolerance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tolerance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tolerance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tolerance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_module_name;
      arrToVar(length_module_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_module_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_module_name-1]=0;
      this->module_name = (char *)(inbuffer + offset-1);
      offset += length_module_name;
      this->request_id =  ((uint16_t) (*(inbuffer + offset)));
      this->request_id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->request_id);
      this->cancel =  ((uint16_t) (*(inbuffer + offset)));
      this->cancel |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->cancel);
      this->update_num =  ((uint16_t) (*(inbuffer + offset)));
      this->update_num |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->update_num);
      this->guid_valid =  ((uint16_t) (*(inbuffer + offset)));
      this->guid_valid |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->guid_valid);
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
      } u_tolerance;
      u_tolerance.base = 0;
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tolerance = u_tolerance.real;
      offset += sizeof(this->tolerance);
     return offset;
    }

    const char * getType(){ return "automotive_navigation_msgs/PointOfInterestRequest"; };
    const char * getMD5(){ return "b55c53f232d0288e56995c132cf04930"; };

  };

}
#endif