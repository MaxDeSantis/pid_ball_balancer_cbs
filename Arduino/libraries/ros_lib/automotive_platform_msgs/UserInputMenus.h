#ifndef _ROS_automotive_platform_msgs_UserInputMenus_h
#define _ROS_automotive_platform_msgs_UserInputMenus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_platform_msgs
{

  class UserInputMenus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _str_whl_left_btn_left_type;
      _str_whl_left_btn_left_type str_whl_left_btn_left;
      typedef bool _str_whl_left_btn_down_type;
      _str_whl_left_btn_down_type str_whl_left_btn_down;
      typedef bool _str_whl_left_btn_right_type;
      _str_whl_left_btn_right_type str_whl_left_btn_right;
      typedef bool _str_whl_left_btn_up_type;
      _str_whl_left_btn_up_type str_whl_left_btn_up;
      typedef bool _str_whl_left_btn_ok_type;
      _str_whl_left_btn_ok_type str_whl_left_btn_ok;
      typedef bool _str_whl_right_btn_left_type;
      _str_whl_right_btn_left_type str_whl_right_btn_left;
      typedef bool _str_whl_right_btn_down_type;
      _str_whl_right_btn_down_type str_whl_right_btn_down;
      typedef bool _str_whl_right_btn_right_type;
      _str_whl_right_btn_right_type str_whl_right_btn_right;
      typedef bool _str_whl_right_btn_up_type;
      _str_whl_right_btn_up_type str_whl_right_btn_up;
      typedef bool _str_whl_right_btn_ok_type;
      _str_whl_right_btn_ok_type str_whl_right_btn_ok;
      typedef bool _cntr_cons_btn_left_type;
      _cntr_cons_btn_left_type cntr_cons_btn_left;
      typedef bool _cntr_cons_btn_down_type;
      _cntr_cons_btn_down_type cntr_cons_btn_down;
      typedef bool _cntr_cons_btn_right_type;
      _cntr_cons_btn_right_type cntr_cons_btn_right;
      typedef bool _cntr_cons_btn_up_type;
      _cntr_cons_btn_up_type cntr_cons_btn_up;
      typedef bool _cntr_cons_btn_ok_type;
      _cntr_cons_btn_ok_type cntr_cons_btn_ok;

    UserInputMenus():
      header(),
      str_whl_left_btn_left(0),
      str_whl_left_btn_down(0),
      str_whl_left_btn_right(0),
      str_whl_left_btn_up(0),
      str_whl_left_btn_ok(0),
      str_whl_right_btn_left(0),
      str_whl_right_btn_down(0),
      str_whl_right_btn_right(0),
      str_whl_right_btn_up(0),
      str_whl_right_btn_ok(0),
      cntr_cons_btn_left(0),
      cntr_cons_btn_down(0),
      cntr_cons_btn_right(0),
      cntr_cons_btn_up(0),
      cntr_cons_btn_ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_left_btn_left;
      u_str_whl_left_btn_left.real = this->str_whl_left_btn_left;
      *(outbuffer + offset + 0) = (u_str_whl_left_btn_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->str_whl_left_btn_left);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_left_btn_down;
      u_str_whl_left_btn_down.real = this->str_whl_left_btn_down;
      *(outbuffer + offset + 0) = (u_str_whl_left_btn_down.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->str_whl_left_btn_down);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_left_btn_right;
      u_str_whl_left_btn_right.real = this->str_whl_left_btn_right;
      *(outbuffer + offset + 0) = (u_str_whl_left_btn_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->str_whl_left_btn_right);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_left_btn_up;
      u_str_whl_left_btn_up.real = this->str_whl_left_btn_up;
      *(outbuffer + offset + 0) = (u_str_whl_left_btn_up.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->str_whl_left_btn_up);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_left_btn_ok;
      u_str_whl_left_btn_ok.real = this->str_whl_left_btn_ok;
      *(outbuffer + offset + 0) = (u_str_whl_left_btn_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->str_whl_left_btn_ok);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_right_btn_left;
      u_str_whl_right_btn_left.real = this->str_whl_right_btn_left;
      *(outbuffer + offset + 0) = (u_str_whl_right_btn_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->str_whl_right_btn_left);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_right_btn_down;
      u_str_whl_right_btn_down.real = this->str_whl_right_btn_down;
      *(outbuffer + offset + 0) = (u_str_whl_right_btn_down.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->str_whl_right_btn_down);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_right_btn_right;
      u_str_whl_right_btn_right.real = this->str_whl_right_btn_right;
      *(outbuffer + offset + 0) = (u_str_whl_right_btn_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->str_whl_right_btn_right);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_right_btn_up;
      u_str_whl_right_btn_up.real = this->str_whl_right_btn_up;
      *(outbuffer + offset + 0) = (u_str_whl_right_btn_up.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->str_whl_right_btn_up);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_right_btn_ok;
      u_str_whl_right_btn_ok.real = this->str_whl_right_btn_ok;
      *(outbuffer + offset + 0) = (u_str_whl_right_btn_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->str_whl_right_btn_ok);
      union {
        bool real;
        uint8_t base;
      } u_cntr_cons_btn_left;
      u_cntr_cons_btn_left.real = this->cntr_cons_btn_left;
      *(outbuffer + offset + 0) = (u_cntr_cons_btn_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cntr_cons_btn_left);
      union {
        bool real;
        uint8_t base;
      } u_cntr_cons_btn_down;
      u_cntr_cons_btn_down.real = this->cntr_cons_btn_down;
      *(outbuffer + offset + 0) = (u_cntr_cons_btn_down.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cntr_cons_btn_down);
      union {
        bool real;
        uint8_t base;
      } u_cntr_cons_btn_right;
      u_cntr_cons_btn_right.real = this->cntr_cons_btn_right;
      *(outbuffer + offset + 0) = (u_cntr_cons_btn_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cntr_cons_btn_right);
      union {
        bool real;
        uint8_t base;
      } u_cntr_cons_btn_up;
      u_cntr_cons_btn_up.real = this->cntr_cons_btn_up;
      *(outbuffer + offset + 0) = (u_cntr_cons_btn_up.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cntr_cons_btn_up);
      union {
        bool real;
        uint8_t base;
      } u_cntr_cons_btn_ok;
      u_cntr_cons_btn_ok.real = this->cntr_cons_btn_ok;
      *(outbuffer + offset + 0) = (u_cntr_cons_btn_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cntr_cons_btn_ok);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_left_btn_left;
      u_str_whl_left_btn_left.base = 0;
      u_str_whl_left_btn_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->str_whl_left_btn_left = u_str_whl_left_btn_left.real;
      offset += sizeof(this->str_whl_left_btn_left);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_left_btn_down;
      u_str_whl_left_btn_down.base = 0;
      u_str_whl_left_btn_down.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->str_whl_left_btn_down = u_str_whl_left_btn_down.real;
      offset += sizeof(this->str_whl_left_btn_down);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_left_btn_right;
      u_str_whl_left_btn_right.base = 0;
      u_str_whl_left_btn_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->str_whl_left_btn_right = u_str_whl_left_btn_right.real;
      offset += sizeof(this->str_whl_left_btn_right);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_left_btn_up;
      u_str_whl_left_btn_up.base = 0;
      u_str_whl_left_btn_up.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->str_whl_left_btn_up = u_str_whl_left_btn_up.real;
      offset += sizeof(this->str_whl_left_btn_up);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_left_btn_ok;
      u_str_whl_left_btn_ok.base = 0;
      u_str_whl_left_btn_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->str_whl_left_btn_ok = u_str_whl_left_btn_ok.real;
      offset += sizeof(this->str_whl_left_btn_ok);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_right_btn_left;
      u_str_whl_right_btn_left.base = 0;
      u_str_whl_right_btn_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->str_whl_right_btn_left = u_str_whl_right_btn_left.real;
      offset += sizeof(this->str_whl_right_btn_left);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_right_btn_down;
      u_str_whl_right_btn_down.base = 0;
      u_str_whl_right_btn_down.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->str_whl_right_btn_down = u_str_whl_right_btn_down.real;
      offset += sizeof(this->str_whl_right_btn_down);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_right_btn_right;
      u_str_whl_right_btn_right.base = 0;
      u_str_whl_right_btn_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->str_whl_right_btn_right = u_str_whl_right_btn_right.real;
      offset += sizeof(this->str_whl_right_btn_right);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_right_btn_up;
      u_str_whl_right_btn_up.base = 0;
      u_str_whl_right_btn_up.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->str_whl_right_btn_up = u_str_whl_right_btn_up.real;
      offset += sizeof(this->str_whl_right_btn_up);
      union {
        bool real;
        uint8_t base;
      } u_str_whl_right_btn_ok;
      u_str_whl_right_btn_ok.base = 0;
      u_str_whl_right_btn_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->str_whl_right_btn_ok = u_str_whl_right_btn_ok.real;
      offset += sizeof(this->str_whl_right_btn_ok);
      union {
        bool real;
        uint8_t base;
      } u_cntr_cons_btn_left;
      u_cntr_cons_btn_left.base = 0;
      u_cntr_cons_btn_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cntr_cons_btn_left = u_cntr_cons_btn_left.real;
      offset += sizeof(this->cntr_cons_btn_left);
      union {
        bool real;
        uint8_t base;
      } u_cntr_cons_btn_down;
      u_cntr_cons_btn_down.base = 0;
      u_cntr_cons_btn_down.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cntr_cons_btn_down = u_cntr_cons_btn_down.real;
      offset += sizeof(this->cntr_cons_btn_down);
      union {
        bool real;
        uint8_t base;
      } u_cntr_cons_btn_right;
      u_cntr_cons_btn_right.base = 0;
      u_cntr_cons_btn_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cntr_cons_btn_right = u_cntr_cons_btn_right.real;
      offset += sizeof(this->cntr_cons_btn_right);
      union {
        bool real;
        uint8_t base;
      } u_cntr_cons_btn_up;
      u_cntr_cons_btn_up.base = 0;
      u_cntr_cons_btn_up.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cntr_cons_btn_up = u_cntr_cons_btn_up.real;
      offset += sizeof(this->cntr_cons_btn_up);
      union {
        bool real;
        uint8_t base;
      } u_cntr_cons_btn_ok;
      u_cntr_cons_btn_ok.base = 0;
      u_cntr_cons_btn_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cntr_cons_btn_ok = u_cntr_cons_btn_ok.real;
      offset += sizeof(this->cntr_cons_btn_ok);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/UserInputMenus"; };
    const char * getMD5(){ return "fe6ad02b305fbde3a33fc030612b13da"; };

  };

}
#endif