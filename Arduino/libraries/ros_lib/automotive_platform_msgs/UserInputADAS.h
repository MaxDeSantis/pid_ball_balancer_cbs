#ifndef _ROS_automotive_platform_msgs_UserInputADAS_h
#define _ROS_automotive_platform_msgs_UserInputADAS_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace automotive_platform_msgs
{

  class UserInputADAS : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _btn_cc_on_type;
      _btn_cc_on_type btn_cc_on;
      typedef bool _btn_cc_off_type;
      _btn_cc_off_type btn_cc_off;
      typedef bool _btn_cc_on_off_type;
      _btn_cc_on_off_type btn_cc_on_off;
      typedef bool _btn_cc_set_inc_type;
      _btn_cc_set_inc_type btn_cc_set_inc;
      typedef bool _btn_cc_set_dec_type;
      _btn_cc_set_dec_type btn_cc_set_dec;
      typedef bool _btn_cc_res_type;
      _btn_cc_res_type btn_cc_res;
      typedef bool _btn_cc_cncl_type;
      _btn_cc_cncl_type btn_cc_cncl;
      typedef bool _btn_cc_res_cncl_type;
      _btn_cc_res_cncl_type btn_cc_res_cncl;
      typedef bool _btn_acc_gap_inc_type;
      _btn_acc_gap_inc_type btn_acc_gap_inc;
      typedef bool _btn_acc_gap_dec_type;
      _btn_acc_gap_dec_type btn_acc_gap_dec;
      typedef bool _btn_lka_on_type;
      _btn_lka_on_type btn_lka_on;
      typedef bool _btn_lka_off_type;
      _btn_lka_off_type btn_lka_off;
      typedef bool _btn_lka_on_off_type;
      _btn_lka_on_off_type btn_lka_on_off;

    UserInputADAS():
      header(),
      btn_cc_on(0),
      btn_cc_off(0),
      btn_cc_on_off(0),
      btn_cc_set_inc(0),
      btn_cc_set_dec(0),
      btn_cc_res(0),
      btn_cc_cncl(0),
      btn_cc_res_cncl(0),
      btn_acc_gap_inc(0),
      btn_acc_gap_dec(0),
      btn_lka_on(0),
      btn_lka_off(0),
      btn_lka_on_off(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_btn_cc_on;
      u_btn_cc_on.real = this->btn_cc_on;
      *(outbuffer + offset + 0) = (u_btn_cc_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_cc_on);
      union {
        bool real;
        uint8_t base;
      } u_btn_cc_off;
      u_btn_cc_off.real = this->btn_cc_off;
      *(outbuffer + offset + 0) = (u_btn_cc_off.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_cc_off);
      union {
        bool real;
        uint8_t base;
      } u_btn_cc_on_off;
      u_btn_cc_on_off.real = this->btn_cc_on_off;
      *(outbuffer + offset + 0) = (u_btn_cc_on_off.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_cc_on_off);
      union {
        bool real;
        uint8_t base;
      } u_btn_cc_set_inc;
      u_btn_cc_set_inc.real = this->btn_cc_set_inc;
      *(outbuffer + offset + 0) = (u_btn_cc_set_inc.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_cc_set_inc);
      union {
        bool real;
        uint8_t base;
      } u_btn_cc_set_dec;
      u_btn_cc_set_dec.real = this->btn_cc_set_dec;
      *(outbuffer + offset + 0) = (u_btn_cc_set_dec.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_cc_set_dec);
      union {
        bool real;
        uint8_t base;
      } u_btn_cc_res;
      u_btn_cc_res.real = this->btn_cc_res;
      *(outbuffer + offset + 0) = (u_btn_cc_res.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_cc_res);
      union {
        bool real;
        uint8_t base;
      } u_btn_cc_cncl;
      u_btn_cc_cncl.real = this->btn_cc_cncl;
      *(outbuffer + offset + 0) = (u_btn_cc_cncl.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_cc_cncl);
      union {
        bool real;
        uint8_t base;
      } u_btn_cc_res_cncl;
      u_btn_cc_res_cncl.real = this->btn_cc_res_cncl;
      *(outbuffer + offset + 0) = (u_btn_cc_res_cncl.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_cc_res_cncl);
      union {
        bool real;
        uint8_t base;
      } u_btn_acc_gap_inc;
      u_btn_acc_gap_inc.real = this->btn_acc_gap_inc;
      *(outbuffer + offset + 0) = (u_btn_acc_gap_inc.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_acc_gap_inc);
      union {
        bool real;
        uint8_t base;
      } u_btn_acc_gap_dec;
      u_btn_acc_gap_dec.real = this->btn_acc_gap_dec;
      *(outbuffer + offset + 0) = (u_btn_acc_gap_dec.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_acc_gap_dec);
      union {
        bool real;
        uint8_t base;
      } u_btn_lka_on;
      u_btn_lka_on.real = this->btn_lka_on;
      *(outbuffer + offset + 0) = (u_btn_lka_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_lka_on);
      union {
        bool real;
        uint8_t base;
      } u_btn_lka_off;
      u_btn_lka_off.real = this->btn_lka_off;
      *(outbuffer + offset + 0) = (u_btn_lka_off.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_lka_off);
      union {
        bool real;
        uint8_t base;
      } u_btn_lka_on_off;
      u_btn_lka_on_off.real = this->btn_lka_on_off;
      *(outbuffer + offset + 0) = (u_btn_lka_on_off.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn_lka_on_off);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_btn_cc_on;
      u_btn_cc_on.base = 0;
      u_btn_cc_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_cc_on = u_btn_cc_on.real;
      offset += sizeof(this->btn_cc_on);
      union {
        bool real;
        uint8_t base;
      } u_btn_cc_off;
      u_btn_cc_off.base = 0;
      u_btn_cc_off.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_cc_off = u_btn_cc_off.real;
      offset += sizeof(this->btn_cc_off);
      union {
        bool real;
        uint8_t base;
      } u_btn_cc_on_off;
      u_btn_cc_on_off.base = 0;
      u_btn_cc_on_off.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_cc_on_off = u_btn_cc_on_off.real;
      offset += sizeof(this->btn_cc_on_off);
      union {
        bool real;
        uint8_t base;
      } u_btn_cc_set_inc;
      u_btn_cc_set_inc.base = 0;
      u_btn_cc_set_inc.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_cc_set_inc = u_btn_cc_set_inc.real;
      offset += sizeof(this->btn_cc_set_inc);
      union {
        bool real;
        uint8_t base;
      } u_btn_cc_set_dec;
      u_btn_cc_set_dec.base = 0;
      u_btn_cc_set_dec.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_cc_set_dec = u_btn_cc_set_dec.real;
      offset += sizeof(this->btn_cc_set_dec);
      union {
        bool real;
        uint8_t base;
      } u_btn_cc_res;
      u_btn_cc_res.base = 0;
      u_btn_cc_res.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_cc_res = u_btn_cc_res.real;
      offset += sizeof(this->btn_cc_res);
      union {
        bool real;
        uint8_t base;
      } u_btn_cc_cncl;
      u_btn_cc_cncl.base = 0;
      u_btn_cc_cncl.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_cc_cncl = u_btn_cc_cncl.real;
      offset += sizeof(this->btn_cc_cncl);
      union {
        bool real;
        uint8_t base;
      } u_btn_cc_res_cncl;
      u_btn_cc_res_cncl.base = 0;
      u_btn_cc_res_cncl.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_cc_res_cncl = u_btn_cc_res_cncl.real;
      offset += sizeof(this->btn_cc_res_cncl);
      union {
        bool real;
        uint8_t base;
      } u_btn_acc_gap_inc;
      u_btn_acc_gap_inc.base = 0;
      u_btn_acc_gap_inc.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_acc_gap_inc = u_btn_acc_gap_inc.real;
      offset += sizeof(this->btn_acc_gap_inc);
      union {
        bool real;
        uint8_t base;
      } u_btn_acc_gap_dec;
      u_btn_acc_gap_dec.base = 0;
      u_btn_acc_gap_dec.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_acc_gap_dec = u_btn_acc_gap_dec.real;
      offset += sizeof(this->btn_acc_gap_dec);
      union {
        bool real;
        uint8_t base;
      } u_btn_lka_on;
      u_btn_lka_on.base = 0;
      u_btn_lka_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_lka_on = u_btn_lka_on.real;
      offset += sizeof(this->btn_lka_on);
      union {
        bool real;
        uint8_t base;
      } u_btn_lka_off;
      u_btn_lka_off.base = 0;
      u_btn_lka_off.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_lka_off = u_btn_lka_off.real;
      offset += sizeof(this->btn_lka_off);
      union {
        bool real;
        uint8_t base;
      } u_btn_lka_on_off;
      u_btn_lka_on_off.base = 0;
      u_btn_lka_on_off.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn_lka_on_off = u_btn_lka_on_off.real;
      offset += sizeof(this->btn_lka_on_off);
     return offset;
    }

    const char * getType(){ return "automotive_platform_msgs/UserInputADAS"; };
    const char * getMD5(){ return "7e781a180633792b238750d67dd1490f"; };

  };

}
#endif