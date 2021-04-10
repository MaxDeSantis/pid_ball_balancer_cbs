#ifndef _ROS_autoware_config_msgs_ConfigPoints2Polygon_h
#define _ROS_autoware_config_msgs_ConfigPoints2Polygon_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigPoints2Polygon : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _k_search_type;
      _k_search_type k_search;
      typedef float _search_radius_type;
      _search_radius_type search_radius;
      typedef float _mu_type;
      _mu_type mu;
      typedef int32_t _maximum_nearest_neighbors_type;
      _maximum_nearest_neighbors_type maximum_nearest_neighbors;
      typedef float _maximum_surface_angle_type;
      _maximum_surface_angle_type maximum_surface_angle;
      typedef float _minimum_angle_type;
      _minimum_angle_type minimum_angle;
      typedef float _maximum_angle_type;
      _maximum_angle_type maximum_angle;
      typedef bool _normal_consistency_type;
      _normal_consistency_type normal_consistency;

    ConfigPoints2Polygon():
      header(),
      k_search(0),
      search_radius(0),
      mu(0),
      maximum_nearest_neighbors(0),
      maximum_surface_angle(0),
      minimum_angle(0),
      maximum_angle(0),
      normal_consistency(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_k_search;
      u_k_search.real = this->k_search;
      *(outbuffer + offset + 0) = (u_k_search.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_k_search.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_k_search.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_k_search.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->k_search);
      union {
        float real;
        uint32_t base;
      } u_search_radius;
      u_search_radius.real = this->search_radius;
      *(outbuffer + offset + 0) = (u_search_radius.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_search_radius.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_search_radius.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_search_radius.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->search_radius);
      union {
        float real;
        uint32_t base;
      } u_mu;
      u_mu.real = this->mu;
      *(outbuffer + offset + 0) = (u_mu.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mu.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mu.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mu.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mu);
      union {
        int32_t real;
        uint32_t base;
      } u_maximum_nearest_neighbors;
      u_maximum_nearest_neighbors.real = this->maximum_nearest_neighbors;
      *(outbuffer + offset + 0) = (u_maximum_nearest_neighbors.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_maximum_nearest_neighbors.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_maximum_nearest_neighbors.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_maximum_nearest_neighbors.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->maximum_nearest_neighbors);
      union {
        float real;
        uint32_t base;
      } u_maximum_surface_angle;
      u_maximum_surface_angle.real = this->maximum_surface_angle;
      *(outbuffer + offset + 0) = (u_maximum_surface_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_maximum_surface_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_maximum_surface_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_maximum_surface_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->maximum_surface_angle);
      union {
        float real;
        uint32_t base;
      } u_minimum_angle;
      u_minimum_angle.real = this->minimum_angle;
      *(outbuffer + offset + 0) = (u_minimum_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_minimum_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_minimum_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_minimum_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->minimum_angle);
      union {
        float real;
        uint32_t base;
      } u_maximum_angle;
      u_maximum_angle.real = this->maximum_angle;
      *(outbuffer + offset + 0) = (u_maximum_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_maximum_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_maximum_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_maximum_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->maximum_angle);
      union {
        bool real;
        uint8_t base;
      } u_normal_consistency;
      u_normal_consistency.real = this->normal_consistency;
      *(outbuffer + offset + 0) = (u_normal_consistency.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->normal_consistency);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_k_search;
      u_k_search.base = 0;
      u_k_search.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_k_search.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_k_search.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_k_search.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->k_search = u_k_search.real;
      offset += sizeof(this->k_search);
      union {
        float real;
        uint32_t base;
      } u_search_radius;
      u_search_radius.base = 0;
      u_search_radius.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_search_radius.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_search_radius.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_search_radius.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->search_radius = u_search_radius.real;
      offset += sizeof(this->search_radius);
      union {
        float real;
        uint32_t base;
      } u_mu;
      u_mu.base = 0;
      u_mu.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mu.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mu.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mu.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mu = u_mu.real;
      offset += sizeof(this->mu);
      union {
        int32_t real;
        uint32_t base;
      } u_maximum_nearest_neighbors;
      u_maximum_nearest_neighbors.base = 0;
      u_maximum_nearest_neighbors.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_maximum_nearest_neighbors.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_maximum_nearest_neighbors.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_maximum_nearest_neighbors.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->maximum_nearest_neighbors = u_maximum_nearest_neighbors.real;
      offset += sizeof(this->maximum_nearest_neighbors);
      union {
        float real;
        uint32_t base;
      } u_maximum_surface_angle;
      u_maximum_surface_angle.base = 0;
      u_maximum_surface_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_maximum_surface_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_maximum_surface_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_maximum_surface_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->maximum_surface_angle = u_maximum_surface_angle.real;
      offset += sizeof(this->maximum_surface_angle);
      union {
        float real;
        uint32_t base;
      } u_minimum_angle;
      u_minimum_angle.base = 0;
      u_minimum_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_minimum_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_minimum_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_minimum_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->minimum_angle = u_minimum_angle.real;
      offset += sizeof(this->minimum_angle);
      union {
        float real;
        uint32_t base;
      } u_maximum_angle;
      u_maximum_angle.base = 0;
      u_maximum_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_maximum_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_maximum_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_maximum_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->maximum_angle = u_maximum_angle.real;
      offset += sizeof(this->maximum_angle);
      union {
        bool real;
        uint8_t base;
      } u_normal_consistency;
      u_normal_consistency.base = 0;
      u_normal_consistency.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->normal_consistency = u_normal_consistency.real;
      offset += sizeof(this->normal_consistency);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigPoints2Polygon"; };
    const char * getMD5(){ return "9b14a69dff1a04a736a3b125792a41bf"; };

  };

}
#endif