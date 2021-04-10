#ifndef _ROS_lgsvl_msgs_SignalArray_h
#define _ROS_lgsvl_msgs_SignalArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "lgsvl_msgs/Signal.h"

namespace lgsvl_msgs
{

  class SignalArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t signals_length;
      typedef lgsvl_msgs::Signal _signals_type;
      _signals_type st_signals;
      _signals_type * signals;

    SignalArray():
      header(),
      signals_length(0), signals(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->signals_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->signals_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->signals_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->signals_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->signals_length);
      for( uint32_t i = 0; i < signals_length; i++){
      offset += this->signals[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t signals_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      signals_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      signals_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      signals_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->signals_length);
      if(signals_lengthT > signals_length)
        this->signals = (lgsvl_msgs::Signal*)realloc(this->signals, signals_lengthT * sizeof(lgsvl_msgs::Signal));
      signals_length = signals_lengthT;
      for( uint32_t i = 0; i < signals_length; i++){
      offset += this->st_signals.deserialize(inbuffer + offset);
        memcpy( &(this->signals[i]), &(this->st_signals), sizeof(lgsvl_msgs::Signal));
      }
     return offset;
    }

    const char * getType(){ return "lgsvl_msgs/SignalArray"; };
    const char * getMD5(){ return "393df759551aab912558e66c169902cd"; };

  };

}
#endif