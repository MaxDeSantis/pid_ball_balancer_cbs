#ifndef _ROS_autoware_msgs_SyncTimeMonitor_h
#define _ROS_autoware_msgs_SyncTimeMonitor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_msgs
{

  class SyncTimeMonitor : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _image_raw_type;
      _image_raw_type image_raw;
      typedef float _points_raw_type;
      _points_raw_type points_raw;
      typedef float _points_image_type;
      _points_image_type points_image;
      typedef float _vscan_points_type;
      _vscan_points_type vscan_points;
      typedef float _vscan_image_type;
      _vscan_image_type vscan_image;
      typedef float _image_obj_type;
      _image_obj_type image_obj;
      typedef float _image_obj_ranged_type;
      _image_obj_ranged_type image_obj_ranged;
      typedef float _image_obj_tracked_type;
      _image_obj_tracked_type image_obj_tracked;
      typedef float _current_pose_type;
      _current_pose_type current_pose;
      typedef float _obj_label_type;
      _obj_label_type obj_label;
      typedef float _cluster_centroids_type;
      _cluster_centroids_type cluster_centroids;
      typedef float _obj_pose_type;
      _obj_pose_type obj_pose;
      typedef float _execution_time_type;
      _execution_time_type execution_time;
      typedef float _cycle_time_type;
      _cycle_time_type cycle_time;
      typedef float _time_diff_type;
      _time_diff_type time_diff;

    SyncTimeMonitor():
      header(),
      image_raw(0),
      points_raw(0),
      points_image(0),
      vscan_points(0),
      vscan_image(0),
      image_obj(0),
      image_obj_ranged(0),
      image_obj_tracked(0),
      current_pose(0),
      obj_label(0),
      cluster_centroids(0),
      obj_pose(0),
      execution_time(0),
      cycle_time(0),
      time_diff(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->image_raw);
      offset += serializeAvrFloat64(outbuffer + offset, this->points_raw);
      offset += serializeAvrFloat64(outbuffer + offset, this->points_image);
      offset += serializeAvrFloat64(outbuffer + offset, this->vscan_points);
      offset += serializeAvrFloat64(outbuffer + offset, this->vscan_image);
      offset += serializeAvrFloat64(outbuffer + offset, this->image_obj);
      offset += serializeAvrFloat64(outbuffer + offset, this->image_obj_ranged);
      offset += serializeAvrFloat64(outbuffer + offset, this->image_obj_tracked);
      offset += serializeAvrFloat64(outbuffer + offset, this->current_pose);
      offset += serializeAvrFloat64(outbuffer + offset, this->obj_label);
      offset += serializeAvrFloat64(outbuffer + offset, this->cluster_centroids);
      offset += serializeAvrFloat64(outbuffer + offset, this->obj_pose);
      offset += serializeAvrFloat64(outbuffer + offset, this->execution_time);
      offset += serializeAvrFloat64(outbuffer + offset, this->cycle_time);
      offset += serializeAvrFloat64(outbuffer + offset, this->time_diff);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->image_raw));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->points_raw));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->points_image));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vscan_points));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vscan_image));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->image_obj));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->image_obj_ranged));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->image_obj_tracked));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->current_pose));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->obj_label));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->cluster_centroids));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->obj_pose));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->execution_time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->cycle_time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time_diff));
     return offset;
    }

    const char * getType(){ return "autoware_msgs/SyncTimeMonitor"; };
    const char * getMD5(){ return "8c6a4dd195d4ccc31d38fad617327689"; };

  };

}
#endif