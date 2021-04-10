#ifndef _ROS_autoware_msgs_NDTStat_h
#define _ROS_autoware_msgs_NDTStat_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_msgs
{

  class NDTStat : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _exe_time_type;
      _exe_time_type exe_time;
      typedef int32_t _iteration_type;
      _iteration_type iteration;
      typedef float _score_type;
      _score_type score;
      typedef float _velocity_type;
      _velocity_type velocity;
      typedef float _acceleration_type;
      _acceleration_type acceleration;
      typedef int32_t _use_predict_pose_type;
      _use_predict_pose_type use_predict_pose;

    NDTStat():
      header(),
      exe_time(0),
      iteration(0),
      score(0),
      velocity(0),
      acceleration(0),
      use_predict_pose(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_exe_time;
      u_exe_time.real = this->exe_time;
      *(outbuffer + offset + 0) = (u_exe_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_exe_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_exe_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_exe_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->exe_time);
      union {
        int32_t real;
        uint32_t base;
      } u_iteration;
      u_iteration.real = this->iteration;
      *(outbuffer + offset + 0) = (u_iteration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_iteration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_iteration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_iteration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->iteration);
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
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.real = this->velocity;
      *(outbuffer + offset + 0) = (u_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity);
      union {
        float real;
        uint32_t base;
      } u_acceleration;
      u_acceleration.real = this->acceleration;
      *(outbuffer + offset + 0) = (u_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acceleration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acceleration);
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_exe_time;
      u_exe_time.base = 0;
      u_exe_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_exe_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_exe_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_exe_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->exe_time = u_exe_time.real;
      offset += sizeof(this->exe_time);
      union {
        int32_t real;
        uint32_t base;
      } u_iteration;
      u_iteration.base = 0;
      u_iteration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_iteration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_iteration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_iteration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->iteration = u_iteration.real;
      offset += sizeof(this->iteration);
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
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.base = 0;
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity = u_velocity.real;
      offset += sizeof(this->velocity);
      union {
        float real;
        uint32_t base;
      } u_acceleration;
      u_acceleration.base = 0;
      u_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->acceleration = u_acceleration.real;
      offset += sizeof(this->acceleration);
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
     return offset;
    }

    const char * getType(){ return "autoware_msgs/NDTStat"; };
    const char * getMD5(){ return "3c701a222db65bce735c83faea43bd03"; };

  };

}
#endif