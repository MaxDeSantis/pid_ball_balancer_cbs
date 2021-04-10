#ifndef _ROS_autoware_msgs_VscanTrackedArray_h
#define _ROS_autoware_msgs_VscanTrackedArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_msgs/VscanTracked.h"

namespace autoware_msgs
{

  class VscanTrackedArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t obj_tracked_length;
      typedef autoware_msgs::VscanTracked _obj_tracked_type;
      _obj_tracked_type st_obj_tracked;
      _obj_tracked_type * obj_tracked;

    VscanTrackedArray():
      header(),
      obj_tracked_length(0), obj_tracked(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->obj_tracked_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->obj_tracked_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->obj_tracked_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->obj_tracked_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obj_tracked_length);
      for( uint32_t i = 0; i < obj_tracked_length; i++){
      offset += this->obj_tracked[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t obj_tracked_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      obj_tracked_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      obj_tracked_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      obj_tracked_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->obj_tracked_length);
      if(obj_tracked_lengthT > obj_tracked_length)
        this->obj_tracked = (autoware_msgs::VscanTracked*)realloc(this->obj_tracked, obj_tracked_lengthT * sizeof(autoware_msgs::VscanTracked));
      obj_tracked_length = obj_tracked_lengthT;
      for( uint32_t i = 0; i < obj_tracked_length; i++){
      offset += this->st_obj_tracked.deserialize(inbuffer + offset);
        memcpy( &(this->obj_tracked[i]), &(this->st_obj_tracked), sizeof(autoware_msgs::VscanTracked));
      }
     return offset;
    }

    const char * getType(){ return "autoware_msgs/VscanTrackedArray"; };
    const char * getMD5(){ return "6452543c0811934ca1329c54d19f5c59"; };

  };

}
#endif