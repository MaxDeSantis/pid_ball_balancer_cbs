#ifndef _ROS_autoware_config_msgs_ConfigPedestrianKF_h
#define _ROS_autoware_config_msgs_ConfigPedestrianKF_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigPedestrianKF : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _initial_lifespan_type;
      _initial_lifespan_type initial_lifespan;
      typedef int32_t _default_lifespan_type;
      _default_lifespan_type default_lifespan;
      typedef float _noise_covariance_type;
      _noise_covariance_type noise_covariance;
      typedef float _measurement_noise_covariance_type;
      _measurement_noise_covariance_type measurement_noise_covariance;
      typedef float _error_estimate_covariance_type;
      _error_estimate_covariance_type error_estimate_covariance;
      typedef float _percentage_of_overlapping_type;
      _percentage_of_overlapping_type percentage_of_overlapping;
      typedef int32_t _orb_features_type;
      _orb_features_type orb_features;
      typedef int32_t _use_orb_type;
      _use_orb_type use_orb;

    ConfigPedestrianKF():
      header(),
      initial_lifespan(0),
      default_lifespan(0),
      noise_covariance(0),
      measurement_noise_covariance(0),
      error_estimate_covariance(0),
      percentage_of_overlapping(0),
      orb_features(0),
      use_orb(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_initial_lifespan;
      u_initial_lifespan.real = this->initial_lifespan;
      *(outbuffer + offset + 0) = (u_initial_lifespan.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_initial_lifespan.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_initial_lifespan.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_initial_lifespan.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->initial_lifespan);
      union {
        int32_t real;
        uint32_t base;
      } u_default_lifespan;
      u_default_lifespan.real = this->default_lifespan;
      *(outbuffer + offset + 0) = (u_default_lifespan.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_default_lifespan.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_default_lifespan.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_default_lifespan.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->default_lifespan);
      union {
        float real;
        uint32_t base;
      } u_noise_covariance;
      u_noise_covariance.real = this->noise_covariance;
      *(outbuffer + offset + 0) = (u_noise_covariance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_noise_covariance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_noise_covariance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_noise_covariance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->noise_covariance);
      union {
        float real;
        uint32_t base;
      } u_measurement_noise_covariance;
      u_measurement_noise_covariance.real = this->measurement_noise_covariance;
      *(outbuffer + offset + 0) = (u_measurement_noise_covariance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_measurement_noise_covariance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_measurement_noise_covariance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_measurement_noise_covariance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->measurement_noise_covariance);
      union {
        float real;
        uint32_t base;
      } u_error_estimate_covariance;
      u_error_estimate_covariance.real = this->error_estimate_covariance;
      *(outbuffer + offset + 0) = (u_error_estimate_covariance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error_estimate_covariance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error_estimate_covariance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error_estimate_covariance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->error_estimate_covariance);
      union {
        float real;
        uint32_t base;
      } u_percentage_of_overlapping;
      u_percentage_of_overlapping.real = this->percentage_of_overlapping;
      *(outbuffer + offset + 0) = (u_percentage_of_overlapping.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_percentage_of_overlapping.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_percentage_of_overlapping.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_percentage_of_overlapping.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->percentage_of_overlapping);
      union {
        int32_t real;
        uint32_t base;
      } u_orb_features;
      u_orb_features.real = this->orb_features;
      *(outbuffer + offset + 0) = (u_orb_features.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_orb_features.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_orb_features.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_orb_features.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->orb_features);
      union {
        int32_t real;
        uint32_t base;
      } u_use_orb;
      u_use_orb.real = this->use_orb;
      *(outbuffer + offset + 0) = (u_use_orb.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_use_orb.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_use_orb.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_use_orb.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->use_orb);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_initial_lifespan;
      u_initial_lifespan.base = 0;
      u_initial_lifespan.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_initial_lifespan.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_initial_lifespan.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_initial_lifespan.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->initial_lifespan = u_initial_lifespan.real;
      offset += sizeof(this->initial_lifespan);
      union {
        int32_t real;
        uint32_t base;
      } u_default_lifespan;
      u_default_lifespan.base = 0;
      u_default_lifespan.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_default_lifespan.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_default_lifespan.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_default_lifespan.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->default_lifespan = u_default_lifespan.real;
      offset += sizeof(this->default_lifespan);
      union {
        float real;
        uint32_t base;
      } u_noise_covariance;
      u_noise_covariance.base = 0;
      u_noise_covariance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_noise_covariance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_noise_covariance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_noise_covariance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->noise_covariance = u_noise_covariance.real;
      offset += sizeof(this->noise_covariance);
      union {
        float real;
        uint32_t base;
      } u_measurement_noise_covariance;
      u_measurement_noise_covariance.base = 0;
      u_measurement_noise_covariance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_measurement_noise_covariance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_measurement_noise_covariance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_measurement_noise_covariance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->measurement_noise_covariance = u_measurement_noise_covariance.real;
      offset += sizeof(this->measurement_noise_covariance);
      union {
        float real;
        uint32_t base;
      } u_error_estimate_covariance;
      u_error_estimate_covariance.base = 0;
      u_error_estimate_covariance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error_estimate_covariance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error_estimate_covariance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error_estimate_covariance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->error_estimate_covariance = u_error_estimate_covariance.real;
      offset += sizeof(this->error_estimate_covariance);
      union {
        float real;
        uint32_t base;
      } u_percentage_of_overlapping;
      u_percentage_of_overlapping.base = 0;
      u_percentage_of_overlapping.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_percentage_of_overlapping.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_percentage_of_overlapping.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_percentage_of_overlapping.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->percentage_of_overlapping = u_percentage_of_overlapping.real;
      offset += sizeof(this->percentage_of_overlapping);
      union {
        int32_t real;
        uint32_t base;
      } u_orb_features;
      u_orb_features.base = 0;
      u_orb_features.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_orb_features.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_orb_features.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_orb_features.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->orb_features = u_orb_features.real;
      offset += sizeof(this->orb_features);
      union {
        int32_t real;
        uint32_t base;
      } u_use_orb;
      u_use_orb.base = 0;
      u_use_orb.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_use_orb.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_use_orb.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_use_orb.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->use_orb = u_use_orb.real;
      offset += sizeof(this->use_orb);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigPedestrianKF"; };
    const char * getMD5(){ return "35fb5980cbba7f237457ede929c58aa9"; };

  };

}
#endif