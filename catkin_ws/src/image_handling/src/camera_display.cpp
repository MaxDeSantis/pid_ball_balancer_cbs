#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
 
// Author: Addison Sears-Collins
// Website: https://automaticaddison.com
// Description: A basic image subscriber for ROS in C++
// Date: June 27, 2020
 
//using namespace cv;

using namespace cv;
void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
 
  // Pointer used for the conversion from a ROS message to 
  // an OpenCV-compatible image
  cv_bridge::CvImagePtr cv_ptr;

  try
  { 
   
    // Convert the ROS message  
    cv_ptr = cv_bridge::toCvCopy(msg, "mono8");
    // Store the values of the OpenCV-compatible image
    // into the current_frame variable
    cv::Mat current_frame = cv_ptr->image;
    Mat newFrame;
    cv::cvtColor(current_frame, newFrame, COLOR_GRAY2BGR);
    imshow("Mono", newFrame);
    // Display frame for 30 milliseconds
    cv::waitKey(30);
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("Could not convert from '%s' to 'mono8'.", msg->encoding.c_str());
  }
}

void imageCircleCallback(const sensor_msgs::ImageConstPtr& msg) {

  cv_bridge::CvImagePtr cv_circle_ptr;
  try {
    cv_circle_ptr = cv_bridge::toCvCopy(msg, "bgr8");
    Mat frame = cv_circle_ptr->image;
    imshow("Circle", frame);
    cv::waitKey(30);
  }
  catch (cv_bridge::Exception& e) {
    ROS_ERROR("problem with circle '%s' to 'bgr8'", msg->encoding.c_str());
  }
}
 
int main(int argc, char **argv)
{
  // The name of the node
  ros::init(argc, argv, "frame_listener");
   
  // Default handler for nodes in ROS
  ros::NodeHandle nh;
   
  // Used to publish and subscribe to images
  image_transport::ImageTransport it(nh);
   
  // Subscribe to the /camera topic
  image_transport::Subscriber sub = it.subscribe("cam/mono", 1, imageCallback);
  image_transport::Subscriber subCircle = it.subscribe("cam/circle", 1, imageCircleCallback);
  // Make sure we keep reading new video frames by calling the imageCallback function
  ros::spin();
   
  // Close down OpenCV
  cv::destroyAllWindows();
}