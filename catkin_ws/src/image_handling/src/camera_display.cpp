#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <image_handling/hsv_params.h>
#include <iostream>
#include <std_msgs/String.h>

using namespace cv;

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
 
  cv_bridge::CvImagePtr cv_ptr;

  try
  { 
   
    cv_ptr = cv_bridge::toCvCopy(msg, "mono8");

    cv::Mat current_frame = cv_ptr->image;
    Mat newFrame;
    cv::cvtColor(current_frame, newFrame, COLOR_GRAY2BGR);
    imshow("Mono", newFrame);

    cv::waitKey(30);
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("Could not convert from '%s' to 'mono8'.", msg->encoding.c_str());
  }
}
 
int main(int argc, char **argv)
{
  ros::init(argc, argv, "frame_display_node");

  ros::NodeHandle nh;

  image_transport::ImageTransport it(nh);

  image_transport::Subscriber sub = it.subscribe("/cam/monoframe", 1, imageCallback);

  image_handling::hsv_params params = image_handling::hsv_params();
  ros::Rate loop_rate(10);

  while(ros::ok()) {

      ros::spinOnce();
      loop_rate.sleep();
  }

  cv::destroyAllWindows();
}