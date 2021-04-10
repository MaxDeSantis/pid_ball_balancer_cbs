#ifndef _ROS_custom_msgs_ImuSensorSample_h
#define _ROS_custom_msgs_ImuSensorSample_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "custom_msgs/XsensQuaternion.h"
#include "geometry_msgs/Vector3.h"

namespace custom_msgs
{

  class ImuSensorSample : public ros::Msg
  {
    public:
      typedef custom_msgs::XsensQuaternion _dq_type;
      _dq_type dq;
      typedef geometry_msgs::Vector3 _dv_type;
      _dv_type dv;
      typedef geometry_msgs::Vector3 _bGyr_type;
      _bGyr_type bGyr;

    ImuSensorSample():
      dq(),
      dv(),
      bGyr()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->dq.serialize(outbuffer + offset);
      offset += this->dv.serialize(outbuffer + offset);
      offset += this->bGyr.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->dq.deserialize(inbuffer + offset);
      offset += this->dv.deserialize(inbuffer + offset);
      offset += this->bGyr.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "custom_msgs/ImuSensorSample"; };
    const char * getMD5(){ return "4cafe678792d03390e2d87979096a4f3"; };

  };

}
#endif