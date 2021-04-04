
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
#include <opencv2/opencv.hpp>
 
// Author: Addison Sears-Collins
// Website: https://automaticaddison.com
// Description: A basic image publisher for ROS in C++
// Date: June 27, 2020
 
using namespace cv;
using namespace std;

int hueLower = 165;
int hueUpper = 179;
int satLower = 80;
int satUpper = 255;
int valLower = 80;
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
    image_transport::Publisher pub_erode = it.advertise("/cam/erode", 1);
    //image_transport::Publisher pub_circle_frame = it.advertise("cam/circle", 1);
    ros::Subscriber param_sub = nh.subscribe("/cam/params", 1, paramCallback);
    // --------------------------------------------------------------------------
    ros::Rate loop_rate(10);

    sensor_msgs::ImagePtr msg;
    sensor_msgs::ImagePtr msgerode;
    //sensor_msgs::ImagePtr circleMsg;

    Mat frame;
    Mat hsv;
    Mat mask1;
    Mat keyPointMat;
    
    SimpleBlobDetector::Params params;
    params.filterByArea = true;
    params.minArea = 50;
    Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);
    vector<KeyPoint> keypoints;
    
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

      // --- Threshold image using global parameters and erode noise
      // -----------------------------------------------------------------
      inRange(hsv, Scalar(hueLower, satLower, valLower), Scalar(hueUpper, satUpper, valUpper), mask1); //attempting to isolate red
      erode(mask1, mask1, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
      dilate(mask1, mask1, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
      // -----------------------------------------------------------------

      detector->detect(mask1, keypoints);
      drawKeypoints(frame, keypoints, keyPointMat, Scalar(0, 0, 255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

      /*HoughCircles(mask1, circles, HOUGH_GRADIENT, 1, mask1.rows/16, 100, 30, 0, 60);

      for(Vec3i c : circles) {
        Point center = Point(c[0], c[1]);
        circle(frame, center, 1, Scalar(0, 100, 100), 3, LINE_AA);
        int radius = c[2];
        circle(frame, center, radius, Scalar(255, 0, 255), LINE_AA);
      } */

      msg = cv_bridge::CvImage(std_msgs::Header(), "mono8", mask1).toImageMsg();
      //circleMsg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();
      msgerode = cv_bridge::CvImage(std_msgs::Header(), "bgr8", keyPointMat).toImageMsg();

      pub_frame.publish(msg);
      pub_erode.publish(msgerode);
      //pub_circle_frame.publish(circleMsg);
      cv::waitKey(1); // Display image for 1 millisecond
 
      ros::spinOnce();
      loop_rate.sleep();
    }
 
    // Shutdown the camera
    capture.release();
}