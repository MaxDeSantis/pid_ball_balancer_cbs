#ifndef _ROS_autoware_msgs_CloudCluster_h
#define _ROS_autoware_msgs_CloudCluster_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/PointCloud2.h"
#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/Vector3.h"
#include "std_msgs/Float32MultiArray.h"
#include "jsk_recognition_msgs/BoundingBox.h"
#include "geometry_msgs/PolygonStamped.h"

namespace autoware_msgs
{

  class CloudCluster : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _id_type;
      _id_type id;
      typedef const char* _label_type;
      _label_type label;
      typedef float _score_type;
      _score_type score;
      typedef sensor_msgs::PointCloud2 _cloud_type;
      _cloud_type cloud;
      typedef geometry_msgs::PointStamped _min_point_type;
      _min_point_type min_point;
      typedef geometry_msgs::PointStamped _max_point_type;
      _max_point_type max_point;
      typedef geometry_msgs::PointStamped _avg_point_type;
      _avg_point_type avg_point;
      typedef geometry_msgs::PointStamped _centroid_point_type;
      _centroid_point_type centroid_point;
      typedef float _estimated_angle_type;
      _estimated_angle_type estimated_angle;
      typedef geometry_msgs::Vector3 _dimensions_type;
      _dimensions_type dimensions;
      typedef geometry_msgs::Vector3 _eigen_values_type;
      _eigen_values_type eigen_values;
      uint32_t eigen_vectors_length;
      typedef geometry_msgs::Vector3 _eigen_vectors_type;
      _eigen_vectors_type st_eigen_vectors;
      _eigen_vectors_type * eigen_vectors;
      typedef std_msgs::Float32MultiArray _fpfh_descriptor_type;
      _fpfh_descriptor_type fpfh_descriptor;
      typedef jsk_recognition_msgs::BoundingBox _bounding_box_type;
      _bounding_box_type bounding_box;
      typedef geometry_msgs::PolygonStamped _convex_hull_type;
      _convex_hull_type convex_hull;
      typedef uint32_t _indicator_state_type;
      _indicator_state_type indicator_state;

    CloudCluster():
      header(),
      id(0),
      label(""),
      score(0),
      cloud(),
      min_point(),
      max_point(),
      avg_point(),
      centroid_point(),
      estimated_angle(0),
      dimensions(),
      eigen_values(),
      eigen_vectors_length(0), eigen_vectors(NULL),
      fpfh_descriptor(),
      bounding_box(),
      convex_hull(),
      indicator_state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      uint32_t length_label = strlen(this->label);
      varToArr(outbuffer + offset, length_label);
      offset += 4;
      memcpy(outbuffer + offset, this->label, length_label);
      offset += length_label;
      offset += serializeAvrFloat64(outbuffer + offset, this->score);
      offset += this->cloud.serialize(outbuffer + offset);
      offset += this->min_point.serialize(outbuffer + offset);
      offset += this->max_point.serialize(outbuffer + offset);
      offset += this->avg_point.serialize(outbuffer + offset);
      offset += this->centroid_point.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->estimated_angle);
      offset += this->dimensions.serialize(outbuffer + offset);
      offset += this->eigen_values.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->eigen_vectors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->eigen_vectors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->eigen_vectors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->eigen_vectors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->eigen_vectors_length);
      for( uint32_t i = 0; i < eigen_vectors_length; i++){
      offset += this->eigen_vectors[i].serialize(outbuffer + offset);
      }
      offset += this->fpfh_descriptor.serialize(outbuffer + offset);
      offset += this->bounding_box.serialize(outbuffer + offset);
      offset += this->convex_hull.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->indicator_state >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->indicator_state >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->indicator_state >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->indicator_state >> (8 * 3)) & 0xFF;
      offset += sizeof(this->indicator_state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      uint32_t length_label;
      arrToVar(length_label, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_label-1]=0;
      this->label = (char *)(inbuffer + offset-1);
      offset += length_label;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->score));
      offset += this->cloud.deserialize(inbuffer + offset);
      offset += this->min_point.deserialize(inbuffer + offset);
      offset += this->max_point.deserialize(inbuffer + offset);
      offset += this->avg_point.deserialize(inbuffer + offset);
      offset += this->centroid_point.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->estimated_angle));
      offset += this->dimensions.deserialize(inbuffer + offset);
      offset += this->eigen_values.deserialize(inbuffer + offset);
      uint32_t eigen_vectors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      eigen_vectors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      eigen_vectors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      eigen_vectors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->eigen_vectors_length);
      if(eigen_vectors_lengthT > eigen_vectors_length)
        this->eigen_vectors = (geometry_msgs::Vector3*)realloc(this->eigen_vectors, eigen_vectors_lengthT * sizeof(geometry_msgs::Vector3));
      eigen_vectors_length = eigen_vectors_lengthT;
      for( uint32_t i = 0; i < eigen_vectors_length; i++){
      offset += this->st_eigen_vectors.deserialize(inbuffer + offset);
        memcpy( &(this->eigen_vectors[i]), &(this->st_eigen_vectors), sizeof(geometry_msgs::Vector3));
      }
      offset += this->fpfh_descriptor.deserialize(inbuffer + offset);
      offset += this->bounding_box.deserialize(inbuffer + offset);
      offset += this->convex_hull.deserialize(inbuffer + offset);
      this->indicator_state =  ((uint32_t) (*(inbuffer + offset)));
      this->indicator_state |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->indicator_state |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->indicator_state |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->indicator_state);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/CloudCluster"; };
    const char * getMD5(){ return "ee7b21b447ceefba70710356a4b6162b"; };

  };

}
#endif