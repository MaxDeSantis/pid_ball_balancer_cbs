#ifndef _ROS_autoware_config_msgs_ConfigNDT_h
#define _ROS_autoware_config_msgs_ConfigNDT_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigNDT : public ros::Msg
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
      typedef float _resolution_type;
      _resolution_type resolution;
      typedef float _step_size_type;
      _step_size_type step_size;
      typedef float _trans_epsilon_type;
      _trans_epsilon_type trans_epsilon;
      typedef int32_t _max_iterations_type;
      _max_iterations_type max_iterations;

    ConfigNDT():
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
      resolution(0),
      step_size(0),
      trans_epsilon(0),
      max_iterations(0)
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
        float real;
        uint32_t base;
      } u_resolution;
      u_resolution.real = this->resolution;
      *(outbuffer + offset + 0) = (u_resolution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_resolution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_resolution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_resolution.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->resolution);
      union {
        float real;
        uint32_t base;
      } u_step_size;
      u_step_size.real = this->step_size;
      *(outbuffer + offset + 0) = (u_step_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_step_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_step_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_step_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->step_size);
      union {
        float real;
        uint32_t base;
      } u_trans_epsilon;
      u_trans_epsilon.real = this->trans_epsilon;
      *(outbuffer + offset + 0) = (u_trans_epsilon.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_trans_epsilon.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_trans_epsilon.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_trans_epsilon.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trans_epsilon);
      union {
        int32_t real;
        uint32_t base;
      } u_max_iterations;
      u_max_iterations.real = this->max_iterations;
      *(outbuffer + offset + 0) = (u_max_iterations.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_iterations.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_iterations.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_iterations.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_iterations);
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
        float real;
        uint32_t base;
      } u_resolution;
      u_resolution.base = 0;
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->resolution = u_resolution.real;
      offset += sizeof(this->resolution);
      union {
        float real;
        uint32_t base;
      } u_step_size;
      u_step_size.base = 0;
      u_step_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_step_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_step_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_step_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->step_size = u_step_size.real;
      offset += sizeof(this->step_size);
      union {
        float real;
        uint32_t base;
      } u_trans_epsilon;
      u_trans_epsilon.base = 0;
      u_trans_epsilon.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_trans_epsilon.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_trans_epsilon.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_trans_epsilon.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->trans_epsilon = u_trans_epsilon.real;
      offset += sizeof(this->trans_epsilon);
      union {
        int32_t real;
        uint32_t base;
      } u_max_iterations;
      u_max_iterations.base = 0;
      u_max_iterations.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_iterations.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_iterations.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_iterations.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_iterations = u_max_iterations.real;
      offset += sizeof(this->max_iterations);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigNDT"; };
    const char * getMD5(){ return "0cbb0e4cacb81e2b6991a89a4ad992e8"; };

  };

}
#endif