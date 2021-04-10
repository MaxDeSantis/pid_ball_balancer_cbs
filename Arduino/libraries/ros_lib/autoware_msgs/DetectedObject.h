#ifndef _ROS_autoware_msgs_DetectedObject_h
#define _ROS_autoware_msgs_DetectedObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/ColorRGBA.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/PointCloud2.h"
#include "geometry_msgs/PolygonStamped.h"
#include "autoware_msgs/LaneArray.h"
#include "sensor_msgs/Image.h"

namespace autoware_msgs
{

  class DetectedObject : public ros::Msg
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
      typedef std_msgs::ColorRGBA _color_type;
      _color_type color;
      typedef bool _valid_type;
      _valid_type valid;
      typedef const char* _space_frame_type;
      _space_frame_type space_frame;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef geometry_msgs::Vector3 _dimensions_type;
      _dimensions_type dimensions;
      typedef geometry_msgs::Vector3 _variance_type;
      _variance_type variance;
      typedef geometry_msgs::Twist _velocity_type;
      _velocity_type velocity;
      typedef geometry_msgs::Twist _acceleration_type;
      _acceleration_type acceleration;
      typedef sensor_msgs::PointCloud2 _pointcloud_type;
      _pointcloud_type pointcloud;
      typedef geometry_msgs::PolygonStamped _convex_hull_type;
      _convex_hull_type convex_hull;
      typedef autoware_msgs::LaneArray _candidate_trajectories_type;
      _candidate_trajectories_type candidate_trajectories;
      typedef bool _pose_reliable_type;
      _pose_reliable_type pose_reliable;
      typedef bool _velocity_reliable_type;
      _velocity_reliable_type velocity_reliable;
      typedef bool _acceleration_reliable_type;
      _acceleration_reliable_type acceleration_reliable;
      typedef const char* _image_frame_type;
      _image_frame_type image_frame;
      typedef int32_t _x_type;
      _x_type x;
      typedef int32_t _y_type;
      _y_type y;
      typedef int32_t _width_type;
      _width_type width;
      typedef int32_t _height_type;
      _height_type height;
      typedef float _angle_type;
      _angle_type angle;
      typedef sensor_msgs::Image _roi_image_type;
      _roi_image_type roi_image;
      typedef uint8_t _indicator_state_type;
      _indicator_state_type indicator_state;
      typedef uint8_t _behavior_state_type;
      _behavior_state_type behavior_state;
      uint32_t user_defined_info_length;
      typedef char* _user_defined_info_type;
      _user_defined_info_type st_user_defined_info;
      _user_defined_info_type * user_defined_info;

    DetectedObject():
      header(),
      id(0),
      label(""),
      score(0),
      color(),
      valid(0),
      space_frame(""),
      pose(),
      dimensions(),
      variance(),
      velocity(),
      acceleration(),
      pointcloud(),
      convex_hull(),
      candidate_trajectories(),
      pose_reliable(0),
      velocity_reliable(0),
      acceleration_reliable(0),
      image_frame(""),
      x(0),
      y(0),
      width(0),
      height(0),
      angle(0),
      roi_image(),
      indicator_state(0),
      behavior_state(0),
      user_defined_info_length(0), user_defined_info(NULL)
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
      union {
        float real;
        uint32_t base;
      } u_score;
      u_score.real = this->score;
      *(outbuffer + offset + 0) = (u_score.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_score.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_score.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_score.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->score);
      offset += this->color.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_valid;
      u_valid.real = this->valid;
      *(outbuffer + offset + 0) = (u_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->valid);
      uint32_t length_space_frame = strlen(this->space_frame);
      varToArr(outbuffer + offset, length_space_frame);
      offset += 4;
      memcpy(outbuffer + offset, this->space_frame, length_space_frame);
      offset += length_space_frame;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->dimensions.serialize(outbuffer + offset);
      offset += this->variance.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      offset += this->acceleration.serialize(outbuffer + offset);
      offset += this->pointcloud.serialize(outbuffer + offset);
      offset += this->convex_hull.serialize(outbuffer + offset);
      offset += this->candidate_trajectories.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_pose_reliable;
      u_pose_reliable.real = this->pose_reliable;
      *(outbuffer + offset + 0) = (u_pose_reliable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pose_reliable);
      union {
        bool real;
        uint8_t base;
      } u_velocity_reliable;
      u_velocity_reliable.real = this->velocity_reliable;
      *(outbuffer + offset + 0) = (u_velocity_reliable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->velocity_reliable);
      union {
        bool real;
        uint8_t base;
      } u_acceleration_reliable;
      u_acceleration_reliable.real = this->acceleration_reliable;
      *(outbuffer + offset + 0) = (u_acceleration_reliable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->acceleration_reliable);
      uint32_t length_image_frame = strlen(this->image_frame);
      varToArr(outbuffer + offset, length_image_frame);
      offset += 4;
      memcpy(outbuffer + offset, this->image_frame, length_image_frame);
      offset += length_image_frame;
      union {
        int32_t real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        int32_t real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      union {
        int32_t real;
        uint32_t base;
      } u_width;
      u_width.real = this->width;
      *(outbuffer + offset + 0) = (u_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      union {
        int32_t real;
        uint32_t base;
      } u_height;
      u_height.real = this->height;
      *(outbuffer + offset + 0) = (u_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.real = this->angle;
      *(outbuffer + offset + 0) = (u_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle);
      offset += this->roi_image.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->indicator_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->indicator_state);
      *(outbuffer + offset + 0) = (this->behavior_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->behavior_state);
      *(outbuffer + offset + 0) = (this->user_defined_info_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->user_defined_info_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->user_defined_info_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->user_defined_info_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->user_defined_info_length);
      for( uint32_t i = 0; i < user_defined_info_length; i++){
      uint32_t length_user_defined_infoi = strlen(this->user_defined_info[i]);
      varToArr(outbuffer + offset, length_user_defined_infoi);
      offset += 4;
      memcpy(outbuffer + offset, this->user_defined_info[i], length_user_defined_infoi);
      offset += length_user_defined_infoi;
      }
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
      union {
        float real;
        uint32_t base;
      } u_score;
      u_score.base = 0;
      u_score.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_score.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_score.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_score.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->score = u_score.real;
      offset += sizeof(this->score);
      offset += this->color.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_valid;
      u_valid.base = 0;
      u_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->valid = u_valid.real;
      offset += sizeof(this->valid);
      uint32_t length_space_frame;
      arrToVar(length_space_frame, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_space_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_space_frame-1]=0;
      this->space_frame = (char *)(inbuffer + offset-1);
      offset += length_space_frame;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->dimensions.deserialize(inbuffer + offset);
      offset += this->variance.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
      offset += this->acceleration.deserialize(inbuffer + offset);
      offset += this->pointcloud.deserialize(inbuffer + offset);
      offset += this->convex_hull.deserialize(inbuffer + offset);
      offset += this->candidate_trajectories.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_pose_reliable;
      u_pose_reliable.base = 0;
      u_pose_reliable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pose_reliable = u_pose_reliable.real;
      offset += sizeof(this->pose_reliable);
      union {
        bool real;
        uint8_t base;
      } u_velocity_reliable;
      u_velocity_reliable.base = 0;
      u_velocity_reliable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->velocity_reliable = u_velocity_reliable.real;
      offset += sizeof(this->velocity_reliable);
      union {
        bool real;
        uint8_t base;
      } u_acceleration_reliable;
      u_acceleration_reliable.base = 0;
      u_acceleration_reliable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->acceleration_reliable = u_acceleration_reliable.real;
      offset += sizeof(this->acceleration_reliable);
      uint32_t length_image_frame;
      arrToVar(length_image_frame, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_image_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_image_frame-1]=0;
      this->image_frame = (char *)(inbuffer + offset-1);
      offset += length_image_frame;
      union {
        int32_t real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        int32_t real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        int32_t real;
        uint32_t base;
      } u_width;
      u_width.base = 0;
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->width = u_width.real;
      offset += sizeof(this->width);
      union {
        int32_t real;
        uint32_t base;
      } u_height;
      u_height.base = 0;
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->height = u_height.real;
      offset += sizeof(this->height);
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.base = 0;
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle = u_angle.real;
      offset += sizeof(this->angle);
      offset += this->roi_image.deserialize(inbuffer + offset);
      this->indicator_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->indicator_state);
      this->behavior_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->behavior_state);
      uint32_t user_defined_info_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      user_defined_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      user_defined_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      user_defined_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->user_defined_info_length);
      if(user_defined_info_lengthT > user_defined_info_length)
        this->user_defined_info = (char**)realloc(this->user_defined_info, user_defined_info_lengthT * sizeof(char*));
      user_defined_info_length = user_defined_info_lengthT;
      for( uint32_t i = 0; i < user_defined_info_length; i++){
      uint32_t length_st_user_defined_info;
      arrToVar(length_st_user_defined_info, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_user_defined_info; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_user_defined_info-1]=0;
      this->st_user_defined_info = (char *)(inbuffer + offset-1);
      offset += length_st_user_defined_info;
        memcpy( &(this->user_defined_info[i]), &(this->st_user_defined_info), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "autoware_msgs/DetectedObject"; };
    const char * getMD5(){ return "536ff0bbdaac3ef3a57a314f80b8ed04"; };

  };

}
#endif