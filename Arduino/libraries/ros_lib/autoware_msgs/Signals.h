#ifndef _ROS_autoware_msgs_Signals_h
#define _ROS_autoware_msgs_Signals_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_msgs/ExtractedPosition.h"

namespace autoware_msgs
{

  class Signals : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t Signals_length;
      typedef autoware_msgs::ExtractedPosition _Signals_type;
      _Signals_type st_Signals;
      _Signals_type * Signals;

    Signals():
      header(),
      Signals_length(0), Signals(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->Signals_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->Signals_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->Signals_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->Signals_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Signals_length);
      for( uint32_t i = 0; i < Signals_length; i++){
      offset += this->Signals[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t Signals_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      Signals_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      Signals_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      Signals_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->Signals_length);
      if(Signals_lengthT > Signals_length)
        this->Signals = (autoware_msgs::ExtractedPosition*)realloc(this->Signals, Signals_lengthT * sizeof(autoware_msgs::ExtractedPosition));
      Signals_length = Signals_lengthT;
      for( uint32_t i = 0; i < Signals_length; i++){
      offset += this->st_Signals.deserialize(inbuffer + offset);
        memcpy( &(this->Signals[i]), &(this->st_Signals), sizeof(autoware_msgs::ExtractedPosition));
      }
     return offset;
    }

    const char * getType(){ return "autoware_msgs/Signals"; };
    const char * getMD5(){ return "a8533304c9ae882ac02a5af0bd7a8dcd"; };

  };

}
#endif