
//copy pasted from a tutorial as of now
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <ros/ros.h>
#include <ros/console.h>
#include <sensor_msgs/image_encodings.h>
#include <iostream>
#include <vector>
#include <image_handling/hsv_params.h>
#include <std_msgs/String.h>
 
// Author: Addison Sears-Collins
// Website: https://automaticaddison.com
// Description: A basic image publisher for ROS in C++
// Date: June 27, 2020
 
using namespace cv;
using namespace std;

int hueLower = 0;
int hueUpper = 179;
int satLower = 0;
int satUpper = 255;
int valLower = 0;
int valUpper = 255;

// --- Updates variables used for thresholding
// ------------------------------------------------------------
void paramCallback(const image_handling::hsv_paramsPtr& msg) {

    hueLower = msg->hueLower;
    hueUpper = msg->hueUpper;
    satLower = msg->satLower;
    satUpper = msg->satUpper;
    valLower = msg->valLower;
    valUpper = msg->valUpper;
}
// ------------------------------------------------------------

void testCB(const std_msgs::String::ConstPtr& msg) {
  ROS_INFO("I heard: %s", msg->data.c_str());
}
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
    
    // --- Define publishers and subscribers
    // --------------------------------------------------------------------------
    image_transport::Publisher pub_frame = it.advertise("/cam/mono", 1);
    //image_transport::Publisher pub_circle_frame = it.advertise("cam/circle", 1);
    ros::Subscriber param_sub = nh.subscribe("/cam/params", 1, paramCallback);
    ros::Subscriber test_sub = nh.subscribe("/cam/test", 1, testCB);
    // --------------------------------------------------------------------------
    ros::Rate loop_rate(10);

    sensor_msgs::ImagePtr msg;
    //sensor_msgs::ImagePtr circleMsg;

    Mat frame;
    Mat hsv;
    Mat mask1;
    
    
    
    //vector<Vec3f> circles;
    //cv::Mat circleImg;
    //cv::Mat grayFrame;

    while (nh.ok()) {
    
      // --- Load image, check if it has content
      // -----------------------------------------------------------------
      capture >> frame;

      if (frame.empty()) {
        ROS_ERROR_STREAM("Failed to capture image!");
        ros::shutdown();
      }
      // -----------------------------------------------------------------

      // --- Blur image and convert to HSV
      // -----------------------------------------------------------------
      GaussianBlur(frame, frame, Size(3, 3), 0);
      cvtColor(frame, hsv, COLOR_BGR2HSV);
      // -----------------------------------------------------------------

      // --- Threshold image using global parameters
      // -----------------------------------------------------------------
      inRange(hsv, Scalar(hueLower, satLower, valLower), Scalar(hueUpper, satUpper, valUpper), mask1); //attempting to isolate red
      //erode(mask1, mask1, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
      //dilate(mask1, mask1, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
      // -----------------------------------------------------------------

      /*
      inRange(hsv, Scalar(0, 120, 70), Scalar(10, 255, 255), mask2);
      erode(mask2, mask2, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
      dilate(mask2, mask2, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
      */
      //mask1 = mask1 + mask2;

      /*HoughCircles(mask1, circles, HOUGH_GRADIENT, 1, mask1.rows/16, 100, 30, 0, 60);

      for(Vec3i c : circles) {
        Point center = Point(c[0], c[1]);
        circle(frame, center, 1, Scalar(0, 100, 100), 3, LINE_AA);
        int radius = c[2];
        circle(frame, center, radius, Scalar(255, 0, 255), LINE_AA);
      } */

      msg = cv_bridge::CvImage(std_msgs::Header(), "mono8", mask1).toImageMsg();
      //circleMsg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();

      pub_frame.publish(msg);
      //pub_circle_frame.publish(circleMsg);
      cv::waitKey(1); // Display image for 1 millisecond
 
      ros::spinOnce();
      loop_rate.sleep();
    }
 
    // Shutdown the camera
    capture.release();
}