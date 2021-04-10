#ifndef _ROS_autoware_msgs_ColorSet_h
#define _ROS_autoware_msgs_ColorSet_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autoware_msgs/ValueSet.h"

namespace autoware_msgs
{

  class ColorSet : public ros::Msg
  {
    public:
      typedef autoware_msgs::ValueSet _Hue_type;
      _Hue_type Hue;
      typedef autoware_msgs::ValueSet _Sat_type;
      _Sat_type Sat;
      typedef autoware_msgs::ValueSet _Val_type;
      _Val_type Val;

    ColorSet():
      Hue(),
      Sat(),
      Val()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->Hue.serialize(outbuffer + offset);
      offset += this->Sat.serialize(outbuffer + offset);
      offset += this->Val.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->Hue.deserialize(inbuffer + offset);
      offset += this->Sat.deserialize(inbuffer + offset);
      offset += this->Val.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/ColorSet"; };
    const char * getMD5(){ return "c934ba71e28648240ca7f87de508588d"; };

  };

}
#endif