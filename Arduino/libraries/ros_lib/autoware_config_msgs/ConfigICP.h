#ifndef _ROS_autoware_config_msgs_ConfigICP_h
#define _ROS_autoware_config_msgs_ConfigICP_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigICP : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _init_pos_gnss_type;
      _init_pos_gnss_type init_pos_gnss;
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _z_type;
      _z_type z;
      typedef float _roll_type;
      _roll_type roll;
      typedef float _pitch_type;
      _pitch_type pitch;
      typedef float _yaw_type;
      _yaw_type yaw;
      typedef int32_t _use_predict_pose_type;
      _use_predict_pose_type use_predict_pose;
      typedef float _error_threshold_type;
      _error_threshold_type error_threshold;
      typedef int32_t _maximum_iterations_type;
      _maximum_iterations_type maximum_iterations;
      typedef float _transformation_epsilon_type;
      _transformation_epsilon_type transformation_epsilon;
      typedef float _max_correspondence_distance_type;
      _max_correspondence_distance_type max_correspondence_distance;
      typedef float _euclidean_fitness_epsilon_type;
      _euclidean_fitness_epsilon_type euclidean_fitness_epsilon;
      typedef float _ransac_outlier_rejection_threshold_type;
      _ransac_outlier_rejection_threshold_type ransac_outlier_rejection_threshold;

    ConfigICP():
      header(),
      init_pos_gnss(0),
      x(0),
      y(0),
      z(0),
      roll(0),
      pitch(0),
      yaw(0),
      use_predict_pose(0),
      error_threshold(0),
      maximum_iterations(0),
      transformation_epsilon(0),
      max_correspondence_distance(0),
      euclidean_fitness_epsilon(0),
      ransac_outlier_rejection_threshold(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_init_pos_gnss;
      u_init_pos_gnss.real = this->init_pos_gnss;
      *(outbuffer + offset + 0) = (u_init_pos_gnss.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_init_pos_gnss.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_init_pos_gnss.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_init_pos_gnss.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->init_pos_gnss);
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_roll;
      u_roll.real = this->roll;
      *(outbuffer + offset + 0) = (u_roll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roll.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roll.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roll);
      union {
        float real;
        uint32_t base;
      } u_pitch;
      u_pitch.real = this->pitch;
      *(outbuffer + offset + 0) = (u_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pitch);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.real = this->yaw;
      *(outbuffer + offset + 0) = (u_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw);
      union {
        int32_t real;
        uint32_t base;
      } u_use_predict_pose;
      u_use_predict_pose.real = this->use_predict_pose;
      *(outbuffer + offset + 0) = (u_use_predict_pose.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_use_predict_pose.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_use_predict_pose.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_use_predict_pose.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->use_predict_pose);
      union {
        float real;
        uint32_t base;
      } u_error_threshold;
      u_error_threshold.real = this->error_threshold;
      *(outbuffer + offset + 0) = (u_error_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error_threshold.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->error_threshold);
      union {
        int32_t real;
        uint32_t base;
      } u_maximum_iterations;
      u_maximum_iterations.real = this->maximum_iterations;
      *(outbuffer + offset + 0) = (u_maximum_iterations.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_maximum_iterations.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_maximum_iterations.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_maximum_iterations.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->maximum_iterations);
      union {
        float real;
        uint32_t base;
      } u_transformation_epsilon;
      u_transformation_epsilon.real = this->transformation_epsilon;
      *(outbuffer + offset + 0) = (u_transformation_epsilon.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_transformation_epsilon.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_transformation_epsilon.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_transformation_epsilon.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->transformation_epsilon);
      union {
        float real;
        uint32_t base;
      } u_max_correspondence_distance;
      u_max_correspondence_distance.real = this->max_correspondence_distance;
      *(outbuffer + offset + 0) = (u_max_correspondence_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_correspondence_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_correspondence_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_correspondence_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_correspondence_distance);
      union {
        float real;
        uint32_t base;
      } u_euclidean_fitness_epsilon;
      u_euclidean_fitness_epsilon.real = this->euclidean_fitness_epsilon;
      *(outbuffer + offset + 0) = (u_euclidean_fitness_epsilon.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_euclidean_fitness_epsilon.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_euclidean_fitness_epsilon.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_euclidean_fitness_epsilon.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->euclidean_fitness_epsilon);
      union {
        float real;
        uint32_t base;
      } u_ransac_outlier_rejection_threshold;
      u_ransac_outlier_rejection_threshold.real = this->ransac_outlier_rejection_threshold;
      *(outbuffer + offset + 0) = (u_ransac_outlier_rejection_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ransac_outlier_rejection_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ransac_outlier_rejection_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ransac_outlier_rejection_threshold.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ransac_outlier_rejection_threshold);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_init_pos_gnss;
      u_init_pos_gnss.base = 0;
      u_init_pos_gnss.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_init_pos_gnss.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_init_pos_gnss.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_init_pos_gnss.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->init_pos_gnss = u_init_pos_gnss.real;
      offset += sizeof(this->init_pos_gnss);
      union {
        float real;
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
        float real;
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
        float real;
        uint32_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z = u_z.real;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_roll;
      u_roll.base = 0;
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->roll = u_roll.real;
      offset += sizeof(this->roll);
      union {
        float real;
        uint32_t base;
      } u_pitch;
      u_pitch.base = 0;
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pitch = u_pitch.real;
      offset += sizeof(this->pitch);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.base = 0;
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw = u_yaw.real;
      offset += sizeof(this->yaw);
      union {
        int32_t real;
        uint32_t base;
      } u_use_predict_pose;
      u_use_predict_pose.base = 0;
      u_use_predict_pose.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_use_predict_pose.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_use_predict_pose.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_use_predict_pose.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->use_predict_pose = u_use_predict_pose.real;
      offset += sizeof(this->use_predict_pose);
      union {
        float real;
        uint32_t base;
      } u_error_threshold;
      u_error_threshold.base = 0;
      u_error_threshold.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error_threshold.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error_threshold.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error_threshold.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->error_threshold = u_error_threshold.real;
      offset += sizeof(this->error_threshold);
      union {
        int32_t real;
        uint32_t base;
      } u_maximum_iterations;
      u_maximum_iterations.base = 0;
      u_maximum_iterations.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_maximum_iterations.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_maximum_iterations.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_maximum_iterations.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->maximum_iterations = u_maximum_iterations.real;
      offset += sizeof(this->maximum_iterations);
      union {
        float real;
        uint32_t base;
      } u_transformation_epsilon;
      u_transformation_epsilon.base = 0;
      u_transformation_epsilon.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_transformation_epsilon.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_transformation_epsilon.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_transformation_epsilon.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->transformation_epsilon = u_transformation_epsilon.real;
      offset += sizeof(this->transformation_epsilon);
      union {
        float real;
        uint32_t base;
      } u_max_correspondence_distance;
      u_max_correspondence_distance.base = 0;
      u_max_correspondence_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_correspondence_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_correspondence_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_correspondence_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_correspondence_distance = u_max_correspondence_distance.real;
      offset += sizeof(this->max_correspondence_distance);
      union {
        float real;
        uint32_t base;
      } u_euclidean_fitness_epsilon;
      u_euclidean_fitness_epsilon.base = 0;
      u_euclidean_fitness_epsilon.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_euclidean_fitness_epsilon.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_euclidean_fitness_epsilon.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_euclidean_fitness_epsilon.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->euclidean_fitness_epsilon = u_euclidean_fitness_epsilon.real;
      offset += sizeof(this->euclidean_fitness_epsilon);
      union {
        float real;
        uint32_t base;
      } u_ransac_outlier_rejection_threshold;
      u_ransac_outlier_rejection_threshold.base = 0;
      u_ransac_outlier_rejection_threshold.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ransac_outlier_rejection_threshold.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ransac_outlier_rejection_threshold.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ransac_outlier_rejection_threshold.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ransac_outlier_rejection_threshold = u_ransac_outlier_rejection_threshold.real;
      offset += sizeof(this->ransac_outlier_rejection_threshold);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigICP"; };
    const char * getMD5(){ return "5447e477cc209f1aaba7597ea7741dc8"; };

  };

}
#endif