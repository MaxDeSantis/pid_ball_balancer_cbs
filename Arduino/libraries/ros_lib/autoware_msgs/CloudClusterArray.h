#ifndef _ROS_autoware_msgs_CloudClusterArray_h
#define _ROS_autoware_msgs_CloudClusterArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_msgs/CloudCluster.h"

namespace autoware_msgs
{

  class CloudClusterArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t clusters_length;
      typedef autoware_msgs::CloudCluster _clusters_type;
      _clusters_type st_clusters;
      _clusters_type * clusters;

    CloudClusterArray():
      header(),
      clusters_length(0), clusters(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->clusters_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->clusters_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->clusters_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->clusters_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->clusters_length);
      for( uint32_t i = 0; i < clusters_length; i++){
      offset += this->clusters[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t clusters_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      clusters_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      clusters_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      clusters_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->clusters_length);
      if(clusters_lengthT > clusters_length)
        this->clusters = (autoware_msgs::CloudCluster*)realloc(this->clusters, clusters_lengthT * sizeof(autoware_msgs::CloudCluster));
      clusters_length = clusters_lengthT;
      for( uint32_t i = 0; i < clusters_length; i++){
      offset += this->st_clusters.deserialize(inbuffer + offset);
        memcpy( &(this->clusters[i]), &(this->st_clusters), sizeof(autoware_msgs::CloudCluster));
      }
     return offset;
    }

    const char * getType(){ return "autoware_msgs/CloudClusterArray"; };
    const char * getMD5(){ return "5bdd7c958335da845b88351aab5141d4"; };

  };

}
#endif