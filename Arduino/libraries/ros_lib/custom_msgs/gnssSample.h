#ifndef _ROS_custom_msgs_gnssSample_h
#define _ROS_custom_msgs_gnssSample_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"

namespace custom_msgs
{

  class gnssSample : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _itow_type;
      _itow_type itow;
      typedef float _fix_type;
      _fix_type fix;
      typedef float _latitude_type;
      _latitude_type latitude;
      typedef float _longitude_type;
      _longitude_type longitude;
      typedef float _hEll_type;
      _hEll_type hEll;
      typedef float _hMsl_type;
      _hMsl_type hMsl;
      typedef geometry_msgs::Vector3 _vel_type;
      _vel_type vel;
      typedef float _hAcc_type;
      _hAcc_type hAcc;
      typedef float _vAcc_type;
      _vAcc_type vAcc;
      typedef float _sAcc_type;
      _sAcc_type sAcc;
      typedef float _pDop_type;
      _pDop_type pDop;
      typedef float _hDop_type;
      _hDop_type hDop;
      typedef float _vDop_type;
      _vDop_type vDop;
      typedef float _numSat_type;
      _numSat_type numSat;
      typedef float _heading_type;
      _heading_type heading;
      typedef float _headingAcc_type;
      _headingAcc_type headingAcc;

    gnssSample():
      header(),
      itow(0),
      fix(0),
      latitude(0),
      longitude(0),
      hEll(0),
      hMsl(0),
      vel(),
      hAcc(0),
      vAcc(0),
      sAcc(0),
      pDop(0),
      hDop(0),
      vDop(0),
      numSat(0),
      heading(0),
      headingAcc(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->itow);
      offset += serializeAvrFloat64(outbuffer + offset, this->fix);
      offset += serializeAvrFloat64(outbuffer + offset, this->latitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->longitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->hEll);
      offset += serializeAvrFloat64(outbuffer + offset, this->hMsl);
      offset += this->vel.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->hAcc);
      offset += serializeAvrFloat64(outbuffer + offset, this->vAcc);
      offset += serializeAvrFloat64(outbuffer + offset, this->sAcc);
      offset += serializeAvrFloat64(outbuffer + offset, this->pDop);
      offset += serializeAvrFloat64(outbuffer + offset, this->hDop);
      offset += serializeAvrFloat64(outbuffer + offset, this->vDop);
      offset += serializeAvrFloat64(outbuffer + offset, this->numSat);
      offset += serializeAvrFloat64(outbuffer + offset, this->heading);
      offset += serializeAvrFloat64(outbuffer + offset, this->headingAcc);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->itow));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->fix));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->latitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->longitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->hEll));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->hMsl));
      offset += this->vel.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->hAcc));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vAcc));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->sAcc));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pDop));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->hDop));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vDop));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->numSat));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->heading));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->headingAcc));
     return offset;
    }

    const char * getType(){ return "custom_msgs/gnssSample"; };
    const char * getMD5(){ return "d0573311aa10335e691a2e99fd2b6d50"; };

  };

}
#endif