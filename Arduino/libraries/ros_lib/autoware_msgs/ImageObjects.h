#ifndef _ROS_autoware_msgs_ImageObjects_h
#define _ROS_autoware_msgs_ImageObjects_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_msgs
{

  class ImageObjects : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _car_num_type;
      _car_num_type car_num;
      uint32_t car_type_length;
      typedef int32_t _car_type_type;
      _car_type_type st_car_type;
      _car_type_type * car_type;
      uint32_t score_length;
      typedef float _score_type;
      _score_type st_score;
      _score_type * score;
      uint32_t corner_point_length;
      typedef int32_t _corner_point_type;
      _corner_point_type st_corner_point;
      _corner_point_type * corner_point;

    ImageObjects():
      header(),
      car_num(0),
      car_type_length(0), car_type(NULL),
      score_length(0), score(NULL),
      corner_point_length(0), corner_point(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->car_num >> (8 * 0)) & 0xFF;
      offset += sizeof(this->car_num);
      *(outbuffer + offset + 0) = (this->car_type_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->car_type_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->car_type_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->car_type_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->car_type_length);
      for( uint32_t i = 0; i < car_type_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_car_typei;
      u_car_typei.real = this->car_type[i];
      *(outbuffer + offset + 0) = (u_car_typei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_car_typei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_car_typei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_car_typei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->car_type[i]);
      }
      *(outbuffer + offset + 0) = (this->score_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->score_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->score_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->score_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->score_length);
      for( uint32_t i = 0; i < score_length; i++){
      union {
        float real;
        uint32_t base;
      } u_scorei;
      u_scorei.real = this->score[i];
      *(outbuffer + offset + 0) = (u_scorei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_scorei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_scorei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_scorei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->score[i]);
      }
      *(outbuffer + offset + 0) = (this->corner_point_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->corner_point_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->corner_point_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->corner_point_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->corner_point_length);
      for( uint32_t i = 0; i < corner_point_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_corner_pointi;
      u_corner_pointi.real = this->corner_point[i];
      *(outbuffer + offset + 0) = (u_corner_pointi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_corner_pointi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_corner_pointi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_corner_pointi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->corner_point[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->car_num =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->car_num);
      uint32_t car_type_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      car_type_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      car_type_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      car_type_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->car_type_length);
      if(car_type_lengthT > car_type_length)
        this->car_type = (int32_t*)realloc(this->car_type, car_type_lengthT * sizeof(int32_t));
      car_type_length = car_type_lengthT;
      for( uint32_t i = 0; i < car_type_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_car_type;
      u_st_car_type.base = 0;
      u_st_car_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_car_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_car_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_car_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_car_type = u_st_car_type.real;
      offset += sizeof(this->st_car_type);
        memcpy( &(this->car_type[i]), &(this->st_car_type), sizeof(int32_t));
      }
      uint32_t score_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      score_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      score_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      score_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->score_length);
      if(score_lengthT > score_length)
        this->score = (float*)realloc(this->score, score_lengthT * sizeof(float));
      score_length = score_lengthT;
      for( uint32_t i = 0; i < score_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_score;
      u_st_score.base = 0;
      u_st_score.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_score.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_score.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_score.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_score = u_st_score.real;
      offset += sizeof(this->st_score);
        memcpy( &(this->score[i]), &(this->st_score), sizeof(float));
      }
      uint32_t corner_point_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      corner_point_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      corner_point_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      corner_point_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->corner_point_length);
      if(corner_point_lengthT > corner_point_length)
        this->corner_point = (int32_t*)realloc(this->corner_point, corner_point_lengthT * sizeof(int32_t));
      corner_point_length = corner_point_lengthT;
      for( uint32_t i = 0; i < corner_point_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_corner_point;
      u_st_corner_point.base = 0;
      u_st_corner_point.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_corner_point.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_corner_point.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_corner_point.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_corner_point = u_st_corner_point.real;
      offset += sizeof(this->st_corner_point);
        memcpy( &(this->corner_point[i]), &(this->st_corner_point), sizeof(int32_t));
      }
     return offset;
    }

    const char * getType(){ return "autoware_msgs/ImageObjects"; };
    const char * getMD5(){ return "693d2720746a58dc044320f50196df81"; };

  };

}
#endif