#ifndef _ROS_sick_ldmrs_msgs_Object_h
#define _ROS_sick_ldmrs_msgs_Object_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "geometry_msgs/TwistWithCovariance.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/PoseWithCovariance.h"
#include "geometry_msgs/Point.h"

namespace sick_ldmrs_msgs
{

  class Object : public ros::Msg
  {
    public:
      typedef int32_t _id_type;
      _id_type id;
      typedef ros::Time _tracking_time_type;
      _tracking_time_type tracking_time;
      typedef ros::Time _last_seen_type;
      _last_seen_type last_seen;
      typedef geometry_msgs::TwistWithCovariance _velocity_type;
      _velocity_type velocity;
      typedef geometry_msgs::Pose _bounding_box_center_type;
      _bounding_box_center_type bounding_box_center;
      typedef geometry_msgs::Vector3 _bounding_box_size_type;
      _bounding_box_size_type bounding_box_size;
      typedef geometry_msgs::PoseWithCovariance _object_box_center_type;
      _object_box_center_type object_box_center;
      typedef geometry_msgs::Vector3 _object_box_size_type;
      _object_box_size_type object_box_size;
      uint32_t contour_points_length;
      typedef geometry_msgs::Point _contour_points_type;
      _contour_points_type st_contour_points;
      _contour_points_type * contour_points;

    Object():
      id(0),
      tracking_time(),
      last_seen(),
      velocity(),
      bounding_box_center(),
      bounding_box_size(),
      object_box_center(),
      object_box_size(),
      contour_points_length(0), contour_points(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->tracking_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tracking_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tracking_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tracking_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tracking_time.sec);
      *(outbuffer + offset + 0) = (this->tracking_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tracking_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tracking_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tracking_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tracking_time.nsec);
      *(outbuffer + offset + 0) = (this->last_seen.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_seen.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->last_seen.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->last_seen.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_seen.sec);
      *(outbuffer + offset + 0) = (this->last_seen.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_seen.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->last_seen.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->last_seen.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_seen.nsec);
      offset += this->velocity.serialize(outbuffer + offset);
      offset += this->bounding_box_center.serialize(outbuffer + offset);
      offset += this->bounding_box_size.serialize(outbuffer + offset);
      offset += this->object_box_center.serialize(outbuffer + offset);
      offset += this->object_box_size.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->contour_points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->contour_points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->contour_points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->contour_points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->contour_points_length);
      for( uint32_t i = 0; i < contour_points_length; i++){
      offset += this->contour_points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
      this->tracking_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->tracking_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tracking_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tracking_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tracking_time.sec);
      this->tracking_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->tracking_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tracking_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tracking_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tracking_time.nsec);
      this->last_seen.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->last_seen.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->last_seen.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->last_seen.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->last_seen.sec);
      this->last_seen.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->last_seen.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->last_seen.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->last_seen.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->last_seen.nsec);
      offset += this->velocity.deserialize(inbuffer + offset);
      offset += this->bounding_box_center.deserialize(inbuffer + offset);
      offset += this->bounding_box_size.deserialize(inbuffer + offset);
      offset += this->object_box_center.deserialize(inbuffer + offset);
      offset += this->object_box_size.deserialize(inbuffer + offset);
      uint32_t contour_points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      contour_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      contour_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      contour_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->contour_points_length);
      if(contour_points_lengthT > contour_points_length)
        this->contour_points = (geometry_msgs::Point*)realloc(this->contour_points, contour_points_lengthT * sizeof(geometry_msgs::Point));
      contour_points_length = contour_points_lengthT;
      for( uint32_t i = 0; i < contour_points_length; i++){
      offset += this->st_contour_points.deserialize(inbuffer + offset);
        memcpy( &(this->contour_points[i]), &(this->st_contour_points), sizeof(geometry_msgs::Point));
      }
     return offset;
    }

    const char * getType(){ return "sick_ldmrs_msgs/Object"; };
    const char * getMD5(){ return "a5d0f2d250163ffa0098d0fc8218fc4a"; };

  };

}
#endif