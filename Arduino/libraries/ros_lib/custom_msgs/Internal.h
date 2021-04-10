#ifndef _ROS_custom_msgs_Internal_h
#define _ROS_custom_msgs_Internal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "custom_msgs/ImuSensorSample.h"
#include "geometry_msgs/Vector3.h"
#include "custom_msgs/BaroSensorSample.h"
#include "custom_msgs/GnssSensorSample.h"

namespace custom_msgs
{

  class Internal : public ros::Msg
  {
    public:
      typedef custom_msgs::ImuSensorSample _imu_type;
      _imu_type imu;
      typedef geometry_msgs::Vector3 _mag_type;
      _mag_type mag;
      typedef custom_msgs::BaroSensorSample _baro_type;
      _baro_type baro;
      typedef custom_msgs::GnssSensorSample _gnss_type;
      _gnss_type gnss;

    Internal():
      imu(),
      mag(),
      baro(),
      gnss()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->imu.serialize(outbuffer + offset);
      offset += this->mag.serialize(outbuffer + offset);
      offset += this->baro.serialize(outbuffer + offset);
      offset += this->gnss.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->imu.deserialize(inbuffer + offset);
      offset += this->mag.deserialize(inbuffer + offset);
      offset += this->baro.deserialize(inbuffer + offset);
      offset += this->gnss.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "custom_msgs/Internal"; };
    const char * getMD5(){ return "e17159f7355766bfcea833fefb15620b"; };

  };

}
#endif