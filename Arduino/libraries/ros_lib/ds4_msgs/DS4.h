#ifndef _ROS_ds4_msgs_DS4_h
#define _ROS_ds4_msgs_DS4_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace ds4_msgs
{

  class DS4 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _square_type;
      _square_type square;
      typedef bool _cross_type;
      _cross_type cross;
      typedef bool _circle_type;
      _circle_type circle;
      typedef bool _triangle_type;
      _triangle_type triangle;
      typedef bool _up_type;
      _up_type up;
      typedef bool _right_type;
      _right_type right;
      typedef bool _down_type;
      _down_type down;
      typedef bool _left_type;
      _left_type left;
      typedef bool _l1_type;
      _l1_type l1;
      typedef bool _r1_type;
      _r1_type r1;
      typedef float _l2_type;
      _l2_type l2;
      typedef float _r2_type;
      _r2_type r2;
      typedef bool _l3_type;
      _l3_type l3;
      typedef bool _r3_type;
      _r3_type r3;
      typedef float _left_x_type;
      _left_x_type left_x;
      typedef float _left_y_type;
      _left_y_type left_y;
      typedef float _right_x_type;
      _right_x_type right_x;
      typedef float _right_y_type;
      _right_y_type right_y;
      typedef bool _share_type;
      _share_type share;
      typedef bool _option_type;
      _option_type option;
      typedef bool _ps_type;
      _ps_type ps;
      typedef bool _touchpad_type;
      _touchpad_type touchpad;
      typedef float _acc_x_type;
      _acc_x_type acc_x;
      typedef float _acc_y_type;
      _acc_y_type acc_y;
      typedef float _acc_z_type;
      _acc_z_type acc_z;
      typedef float _gyro_rol_type;
      _gyro_rol_type gyro_rol;
      typedef float _gyro_pit_type;
      _gyro_pit_type gyro_pit;
      typedef float _gyro_yaw_type;
      _gyro_yaw_type gyro_yaw;
      typedef bool _connected_type;
      _connected_type connected;

    DS4():
      header(),
      square(0),
      cross(0),
      circle(0),
      triangle(0),
      up(0),
      right(0),
      down(0),
      left(0),
      l1(0),
      r1(0),
      l2(0),
      r2(0),
      l3(0),
      r3(0),
      left_x(0),
      left_y(0),
      right_x(0),
      right_y(0),
      share(0),
      option(0),
      ps(0),
      touchpad(0),
      acc_x(0),
      acc_y(0),
      acc_z(0),
      gyro_rol(0),
      gyro_pit(0),
      gyro_yaw(0),
      connected(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_square;
      u_square.real = this->square;
      *(outbuffer + offset + 0) = (u_square.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->square);
      union {
        bool real;
        uint8_t base;
      } u_cross;
      u_cross.real = this->cross;
      *(outbuffer + offset + 0) = (u_cross.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cross);
      union {
        bool real;
        uint8_t base;
      } u_circle;
      u_circle.real = this->circle;
      *(outbuffer + offset + 0) = (u_circle.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->circle);
      union {
        bool real;
        uint8_t base;
      } u_triangle;
      u_triangle.real = this->triangle;
      *(outbuffer + offset + 0) = (u_triangle.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->triangle);
      union {
        bool real;
        uint8_t base;
      } u_up;
      u_up.real = this->up;
      *(outbuffer + offset + 0) = (u_up.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->up);
      union {
        bool real;
        uint8_t base;
      } u_right;
      u_right.real = this->right;
      *(outbuffer + offset + 0) = (u_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->right);
      union {
        bool real;
        uint8_t base;
      } u_down;
      u_down.real = this->down;
      *(outbuffer + offset + 0) = (u_down.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->down);
      union {
        bool real;
        uint8_t base;
      } u_left;
      u_left.real = this->left;
      *(outbuffer + offset + 0) = (u_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->left);
      union {
        bool real;
        uint8_t base;
      } u_l1;
      u_l1.real = this->l1;
      *(outbuffer + offset + 0) = (u_l1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->l1);
      union {
        bool real;
        uint8_t base;
      } u_r1;
      u_r1.real = this->r1;
      *(outbuffer + offset + 0) = (u_r1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->r1);
      offset += serializeAvrFloat64(outbuffer + offset, this->l2);
      offset += serializeAvrFloat64(outbuffer + offset, this->r2);
      union {
        bool real;
        uint8_t base;
      } u_l3;
      u_l3.real = this->l3;
      *(outbuffer + offset + 0) = (u_l3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->l3);
      union {
        bool real;
        uint8_t base;
      } u_r3;
      u_r3.real = this->r3;
      *(outbuffer + offset + 0) = (u_r3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->r3);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_y);
      union {
        bool real;
        uint8_t base;
      } u_share;
      u_share.real = this->share;
      *(outbuffer + offset + 0) = (u_share.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->share);
      union {
        bool real;
        uint8_t base;
      } u_option;
      u_option.real = this->option;
      *(outbuffer + offset + 0) = (u_option.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->option);
      union {
        bool real;
        uint8_t base;
      } u_ps;
      u_ps.real = this->ps;
      *(outbuffer + offset + 0) = (u_ps.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ps);
      union {
        bool real;
        uint8_t base;
      } u_touchpad;
      u_touchpad.real = this->touchpad;
      *(outbuffer + offset + 0) = (u_touchpad.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->touchpad);
      offset += serializeAvrFloat64(outbuffer + offset, this->acc_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->acc_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->acc_z);
      offset += serializeAvrFloat64(outbuffer + offset, this->gyro_rol);
      offset += serializeAvrFloat64(outbuffer + offset, this->gyro_pit);
      offset += serializeAvrFloat64(outbuffer + offset, this->gyro_yaw);
      union {
        bool real;
        uint8_t base;
      } u_connected;
      u_connected.real = this->connected;
      *(outbuffer + offset + 0) = (u_connected.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->connected);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_square;
      u_square.base = 0;
      u_square.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->square = u_square.real;
      offset += sizeof(this->square);
      union {
        bool real;
        uint8_t base;
      } u_cross;
      u_cross.base = 0;
      u_cross.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cross = u_cross.real;
      offset += sizeof(this->cross);
      union {
        bool real;
        uint8_t base;
      } u_circle;
      u_circle.base = 0;
      u_circle.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->circle = u_circle.real;
      offset += sizeof(this->circle);
      union {
        bool real;
        uint8_t base;
      } u_triangle;
      u_triangle.base = 0;
      u_triangle.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->triangle = u_triangle.real;
      offset += sizeof(this->triangle);
      union {
        bool real;
        uint8_t base;
      } u_up;
      u_up.base = 0;
      u_up.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->up = u_up.real;
      offset += sizeof(this->up);
      union {
        bool real;
        uint8_t base;
      } u_right;
      u_right.base = 0;
      u_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->right = u_right.real;
      offset += sizeof(this->right);
      union {
        bool real;
        uint8_t base;
      } u_down;
      u_down.base = 0;
      u_down.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->down = u_down.real;
      offset += sizeof(this->down);
      union {
        bool real;
        uint8_t base;
      } u_left;
      u_left.base = 0;
      u_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->left = u_left.real;
      offset += sizeof(this->left);
      union {
        bool real;
        uint8_t base;
      } u_l1;
      u_l1.base = 0;
      u_l1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->l1 = u_l1.real;
      offset += sizeof(this->l1);
      union {
        bool real;
        uint8_t base;
      } u_r1;
      u_r1.base = 0;
      u_r1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->r1 = u_r1.real;
      offset += sizeof(this->r1);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->l2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->r2));
      union {
        bool real;
        uint8_t base;
      } u_l3;
      u_l3.base = 0;
      u_l3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->l3 = u_l3.real;
      offset += sizeof(this->l3);
      union {
        bool real;
        uint8_t base;
      } u_r3;
      u_r3.base = 0;
      u_r3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->r3 = u_r3.real;
      offset += sizeof(this->r3);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_y));
      union {
        bool real;
        uint8_t base;
      } u_share;
      u_share.base = 0;
      u_share.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->share = u_share.real;
      offset += sizeof(this->share);
      union {
        bool real;
        uint8_t base;
      } u_option;
      u_option.base = 0;
      u_option.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->option = u_option.real;
      offset += sizeof(this->option);
      union {
        bool real;
        uint8_t base;
      } u_ps;
      u_ps.base = 0;
      u_ps.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ps = u_ps.real;
      offset += sizeof(this->ps);
      union {
        bool real;
        uint8_t base;
      } u_touchpad;
      u_touchpad.base = 0;
      u_touchpad.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->touchpad = u_touchpad.real;
      offset += sizeof(this->touchpad);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->acc_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->acc_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->acc_z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gyro_rol));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gyro_pit));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gyro_yaw));
      union {
        bool real;
        uint8_t base;
      } u_connected;
      u_connected.base = 0;
      u_connected.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->connected = u_connected.real;
      offset += sizeof(this->connected);
     return offset;
    }

    const char * getType(){ return "ds4_msgs/DS4"; };
    const char * getMD5(){ return "9c17d8a8df3d9463ab329c13d2358031"; };

  };

}
#endif