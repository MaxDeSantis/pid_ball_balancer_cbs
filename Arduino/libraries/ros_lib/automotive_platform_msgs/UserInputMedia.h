#ifndef _ROS_automotive_platform_msgs_UserInputMedia_h
#define _ROS_automotive_platform_msgs_UserInputMedia_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_platform_msgs
{

  class UserInputMedia : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _btn_vol_up_type;
      _btn_vol_up_type btn_vol_up;
      typedef bool _btn_vol_down_type;
      _btn_vol_down_type btn_vol_down;
      typedef bool _btn_mute_type;
      _btn_mute_type btn_mute;
      typedef bool _btn_next_type;
      _btn_next_type btn_next;
      typedef bool _btn_prev_type;
      _btn_prev_type btn_prev;
      typedef bool _btn_next_hang_up_type;
      _btn_next_hang_up_type btn_next_hang_up;
      typedef bool _btn_prev_answer_type;
      _btn_prev_answer_type btn_prev_answer;
      typedef bool _btn_hang_up_type;
      _btn_hang_up_type btn_hang_up;
      typedef bool _btn_answer_type;
      _btn_answer_type btn_answer;
      typedef bool _btn_play_type;
      _btn_play_type btn_play;
      typedef bool _btn_pause_type;
      _btn_pause_type btn_pause;
      typedef bool _btn_play_pause_type;
      _btn_play_pause_type btn_play_pause;
      typedef bool _btn_mode_type;
      _btn_mode_type btn_mode;

    UserInputMedia():
      header(),
      btn_vol_up(0),
      btn_vol_down(0),
      btn_mute(0),
      btn_next(0),
      btn_prev(0),
      btn_next_hang_up(0),
      btn_prev_answer(0),
      btn_hang_up(0),
      btn_answer(0),
      btn_play(0),
      btn_pause(0),
      btn_play_pause(0),
      btn_mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_btn_vol_up;
      u_btn_vol_up.real = this->btn_vol_up;
      *(outbuffer + offset + 0) = (u_btn_vol_up.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_vol_up);
      union {
        bool real;
        uint8_t base;
      } u_btn_vol_down;
      u_btn_vol_down.real = this->btn_vol_down;
      *(outbuffer + offset + 0) = (u_btn_vol_down.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_vol_down);
      union {
        bool real;
        uint8_t base;
      } u_btn_mute;
      u_btn_mute.real = this->btn_mute;
      *(outbuffer + offset + 0) = (u_btn_mute.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_mute);
      union {
        bool real;
        uint8_t base;
      } u_btn_next;
      u_btn_next.real = this->btn_next;
      *(outbuffer + offset + 0) = (u_btn_next.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_next);
      union {
        bool real;
        uint8_t base;
      } u_btn_prev;
      u_btn_prev.real = this->btn_prev;
      *(outbuffer + offset + 0) = (u_btn_prev.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_prev);
      union {
        bool real;
        uint8_t base;
      } u_btn_next_hang_up;
      u_btn_next_hang_up.real = this->btn_next_hang_up;
      *(outbuffer + offset + 0) = (u_btn_next_hang_up.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_next_hang_up);
      union {
        bool real;
        uint8_t base;
      } u_btn_prev_answer;
      u_btn_prev_answer.real = this->btn_prev_answer;
      *(outbuffer + offset + 0) = (u_btn_prev_answer.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_prev_answer);
      union {
        bool real;
        uint8_t base;
      } u_btn_hang_up;
      u_btn_hang_up.real = this->btn_hang_up;
      *(outbuffer + offset + 0) = (u_btn_hang_up.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_hang_up);
      union {
        bool real;
        uint8_t base;
      } u_btn_answer;
      u_btn_answer.real = this->btn_answer;
      *(outbuffer + offset + 0) = (u_btn_answer.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_answer);
      union {
        bool real;
        uint8_t base;
      } u_btn_play;
      u_btn_play.real = this->btn_play;
      *(outbuffer + offset + 0) = (u_btn_play.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_play);
      union {
        bool real;
        uint8_t base;
      } u_btn_pause;
      u_btn_pause.real = this->btn_pause;
      *(outbuffer + offset + 0) = (u_btn_pause.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_pause);
      union {
        bool real;
        uint8_t base;
      } u_btn_play_pause;
      u_btn_play_pause.real = this->btn_play_pause;
      *(outbuffer + offset + 0) = (u_btn_play_pause.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_play_pause);
      union {
        bool real;
        uint8_t base;
      } u_btn_mode;
      u_btn_mode.real = this->btn_mode;
      *(outbuffer + offset + 0) = (u_btn_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_btn_vol_up;
      u_btn_vol_up.base = 0;
      u_btn_vol_up.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_vol_up = u_btn_vol_up.real;
      offset += sizeof(this->btn_vol_up);
      union {
        bool real;
        uint8_t base;
      } u_btn_vol_down;
      u_btn_vol_down.base = 0;
      u_btn_vol_down.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_vol_down = u_btn_vol_down.real;
      offset += sizeof(this->btn_vol_down);
      union {
        bool real;
        uint8_t base;
      } u_btn_mute;
      u_btn_mute.base = 0;
      u_btn_mute.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_mute = u_btn_mute.real;
      offset += sizeof(this->btn_mute);
      union {
        bool real;
        uint8_t base;
      } u_btn_next;
      u_btn_next.base = 0;
      u_btn_next.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_next = u_btn_next.real;
      offset += sizeof(this->btn_next);
      union {
        bool real;
        uint8_t base;
      } u_btn_prev;
      u_btn_prev.base = 0;
      u_btn_prev.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_prev = u_btn_prev.real;
      offset += sizeof(this->btn_prev);
      union {
        bool real;
        uint8_t base;
      } u_btn_next_hang_up;
      u_btn_next_hang_up.base = 0;
      u_btn_next_hang_up.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_next_hang_up = u_btn_next_hang_up.real;
      offset += sizeof(this->btn_next_hang_up);
      union {
        bool real;
        uint8_t base;
      } u_btn_prev_answer;
      u_btn_prev_answer.base = 0;
      u_btn_prev_answer.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_prev_answer = u_btn_prev_answer.real;
      offset += sizeof(this->btn_prev_answer);
      union {
        bool real;
        uint8_t base;
      } u_btn_hang_up;
      u_btn_hang_up.base = 0;
      u_btn_hang_up.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_hang_up = u_btn_hang_up.real;
      offset += sizeof(this->btn_hang_up);
      union {
        bool real;
        uint8_t base;
      } u_btn_answer;
      u_btn_answer.base = 0;
      u_btn_answer.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_answer = u_btn_answer.real;
      offset += sizeof(this->btn_answer);
      union {
        bool real;
        uint8_t base;
      } u_btn_play;
      u_btn_play.base = 0;
      u_btn_play.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_play = u_btn_play.real;
      offset += sizeof(this->btn_play);
      union {
        bool real;
        uint8_t base;
      } u_btn_pause;
      u_btn_pause.base = 0;
      u_btn_pause.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_pause = u_btn_pause.real;
      offset += sizeof(this->btn_pause);
      union {
        bool real;
        uint8_t base;
      } u_btn_play_pause;
      u_btn_play_pause.base = 0;
      u_btn_play_pause.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_play_pause = u_btn_play_pause.real;
      offset += sizeof(this->btn_play_pause);
      union {
        bool real;
        uint8_t base;
      } u_btn_mode;
      u_btn_mode.base = 0;
      u_btn_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_mode = u_btn_mode.real;
      offset += sizeof(this->btn_mode);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/UserInputMedia"; };
    const char * getMD5(){ return "cc8e2078d79a82d9d486b8f55a126c7f"; };

  };

}
#endif