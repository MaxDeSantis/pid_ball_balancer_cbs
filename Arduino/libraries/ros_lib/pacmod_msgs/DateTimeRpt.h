#ifndef _ROS_pacmod_msgs_DateTimeRpt_h
#define _ROS_pacmod_msgs_DateTimeRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class DateTimeRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _year_type;
      _year_type year;
      typedef uint8_t _month_type;
      _month_type month;
      typedef uint8_t _day_type;
      _day_type day;
      typedef uint8_t _hour_type;
      _hour_type hour;
      typedef uint8_t _minute_type;
      _minute_type minute;
      typedef uint8_t _second_type;
      _second_type second;

    DateTimeRpt():
      header(),
      year(0),
      month(0),
      day(0),
      hour(0),
      minute(0),
      second(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_year;
      u_year.real = this->year;
      *(outbuffer + offset + 0) = (u_year.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_year.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_year.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_year.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->year);
      *(outbuffer + offset + 0) = (this->month >> (8 * 0)) & 0xFF;
      offset += sizeof(this->month);
      *(outbuffer + offset + 0) = (this->day >> (8 * 0)) & 0xFF;
      offset += sizeof(this->day);
      *(outbuffer + offset + 0) = (this->hour >> (8 * 0)) & 0xFF;
      offset += sizeof(this->hour);
      *(outbuffer + offset + 0) = (this->minute >> (8 * 0)) & 0xFF;
      offset += sizeof(this->minute);
      *(outbuffer + offset + 0) = (this->second >> (8 * 0)) & 0xFF;
      offset += sizeof(this->second);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_year;
      u_year.base = 0;
      u_year.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_year.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_year.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_year.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->year = u_year.real;
      offset += sizeof(this->year);
      this->month =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->month);
      this->day =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->day);
      this->hour =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->hour);
      this->minute =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->minute);
      this->second =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->second);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/DateTimeRpt"; };
    const char * getMD5(){ return "2af1288975789a90586fd2529643798a"; };

  };

}
#endif