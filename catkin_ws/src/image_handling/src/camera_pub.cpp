
//copy pasted from a tutorial as of now
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <ros/ros.h>
#include <ros/console.h>
#include <sensor_msgs/image_encodings.h>
#include <iostream>
 
// Author: Addison Sears-Collins
// Website: https://automaticaddison.com
// Description: A basic image publisher for ROS in C++
// Date: June 27, 2020
 
using namespace cv;
int main(int argc, char** argv)
{
    ros::init(argc, argv, "video_pub_cpp");
    ros::NodeHandle nh;  // Default handler for nodes in ROS
 
    // 0 reads from your default camera
    const int CAMERA_INDEX = 0;
    cv::VideoCapture capture(CAMERA_INDEX); 
    if (!capture.isOpened()) {
      ROS_ERROR_STREAM("Failed to open camera with index " << CAMERA_INDEX << "!");
      ros::shutdown();
    }
     
    // Image_transport is responsible for publishing and subscribing to Images
    image_transport::ImageTransport it(nh);
     
    // Publish to the /camera topic
    image_transport::Publisher pub_frame = it.advertise("camera", 1);
    //image_transport::Publisher pub_frame_mask = it.advertise("hsv", 1);
     
    cv::Mat frame;//Mat is the image class defined in OpenCV
    sensor_msgs::ImagePtr msg;
 
    ros::Rate loop_rate(10);
    cv::Mat hsv;


    while (nh.ok()) {
 
      // Load image
      capture >> frame; 
    
      // Check if grabbed frame has content
      if (frame.empty()) {
        ROS_ERROR_STREAM("Failed to capture image!");
        ros::shutdown();
      }
      Mat mask1, mask2;
      // Convert image from cv::Mat (OpenCV) type to sensor_msgs/Image (ROS) type and publish
      cvtColor(frame, hsv, COLOR_BGR2HSV);

      inRange(hsv, Scalar(170, 120, 70), Scalar(180, 255, 255), mask1); //attempting to isolate red
      //erode(mask1, mask1, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
      //dilate(mask1, mask1, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

      inRange(hsv, Scalar(0, 120, 70), Scalar(10, 255, 255), mask2);
      //erode(mask2, mask2, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
      //dilate(mask2, mask2, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

      mask1 = mask1 + mask2;
      msg = cv_bridge::CvImage(std_msgs::Header(), "mono8", mask1).toImageMsg();
      
      pub_frame.publish(msg);
      cv::waitKey(1); // Display image for 1 millisecond
 
      ros::spinOnce();
      loop_rate.sleep();
    }  
 
    // Shutdown the camera
    capture.release();
}