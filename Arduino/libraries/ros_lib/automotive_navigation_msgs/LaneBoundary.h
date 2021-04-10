#ifndef _ROS_automotive_navigation_msgs_LaneBoundary_h
#define _ROS_automotive_navigation_msgs_LaneBoundary_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace automotive_navigation_msgs
{

  class LaneBoundary : public ros::Msg
  {
    public:
      typedef uint8_t _style_type;
      _style_type style;
      typedef uint8_t _color_type;
      _color_type color;
      uint32_t line_length;
      typedef geometry_msgs::Point _line_type;
      _line_type st_line;
      _line_type * line;
      enum { UNKNOWN = 0 };
      enum { SOLID = 1 };
      enum { DASHED = 2 };
      enum { SOLID_DASHED = 3 };
      enum { DASHED_SOLID = 4 };
      enum { SOLID_SOLID = 5 };
      enum { WHITE = 1 };
      enum { YELLOW = 2 };

    LaneBoundary():
      style(0),
      color(0),
      line_length(0), line(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->style >> (8 * 0)) & 0xFF;
      offset += sizeof(this->style);
      *(outbuffer + offset + 0) = (this->color >> (8 * 0)) & 0xFF;
      offset += sizeof(this->color);
      *(outbuffer + offset + 0) = (this->line_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->line_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->line_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->line_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->line_length);
      for( uint32_t i = 0; i < line_length; i++){
      offset += this->line[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->style =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->style);
      this->color =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->color);
      uint32_t line_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      line_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      line_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      line_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->line_length);
      if(line_lengthT > line_length)
        this->line = (geometry_msgs::Point*)realloc(this->line, line_lengthT * sizeof(geometry_msgs::Point));
      line_length = line_lengthT;
      for( uint32_t i = 0; i < line_length; i++){
      offset += this->st_line.deserialize(inbuffer + offset);
        memcpy( &(this->line[i]), &(this->st_line), sizeof(geometry_msgs::Point));
      }
     return offset;
    }

    const char * getType(){ return "automotive_navigation_msgs/LaneBoundary"; };
    const char * getMD5(){ return "abba97913ebab3edef0c7c39a4ea132f"; };

  };

}
#endif