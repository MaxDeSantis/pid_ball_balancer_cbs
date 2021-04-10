#ifndef _ROS_pacmod_msgs_DetectedObjectRpt_h
#define _ROS_pacmod_msgs_DetectedObjectRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class DetectedObjectRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _front_object_distance_low_res_type;
      _front_object_distance_low_res_type front_object_distance_low_res;
      typedef float _front_object_distance_high_res_type;
      _front_object_distance_high_res_type front_object_distance_high_res;

    DetectedObjectRpt():
      header(),
      front_object_distance_low_res(0),
      front_object_distance_high_res(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->front_object_distance_low_res);
      offset += serializeAvrFloat64(outbuffer + offset, this->front_object_distance_high_res);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->front_object_distance_low_res));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->front_object_distance_high_res));
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/DetectedObjectRpt"; };
    const char * getMD5(){ return "bc712b16be2ea6767f3e682c00a854bc"; };

  };

}
#endif