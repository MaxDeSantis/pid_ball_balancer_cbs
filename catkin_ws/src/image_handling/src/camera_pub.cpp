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
#include <std_msgs/Float64.h>
#include <opencv2/opencv.hpp>
 
 
using namespace cv;
using namespace std;

// Values used to color mask the image.
int hueLower = 165;
int hueUpper = 179;
int satLower = 120;
int satUpper = 255;
int valLower = 80;
int valUpper = 255;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "frame_pub_node");
    ros::NodeHandle nh;  // Default handler for nodes in ROS
 
    //Attempt to access default camera
    const int CAMERA_INDEX = 0;
    cv::VideoCapture capture(CAMERA_INDEX); 
    if (!capture.isOpened()) {
      ROS_ERROR_STREAM("Failed to open camera with index " << CAMERA_INDEX << "!");
      ros::shutdown();
    }
     
    image_transport::ImageTransport it(nh);
    
    // --- Define publishers and subscribers
    // --------------------------------------------------------------------------
    image_transport::Publisher pub_frame = it.advertise("/cam/monoframe", 1);
    image_transport::Publisher pub_original_frame = it.advertise("/cam/frame", 1);
    ros::Rate loop_rate(60); //Run at 30 FPS

    sensor_msgs::ImagePtr msg;
    sensor_msgs::ImagePtr originalMsg;

    Mat frame;
    Mat hsv;
    Mat mask1;
    Mat keyPointMat;
    int scaleFactor = 2;
    
    while (nh.ok()) {
    
      // --- Load image, check if it has content
      // -----------------------------------------------------------------
      capture >> frame;
      if (frame.empty()) {
        ROS_ERROR_STREAM("Failed to capture image!");
        ros::shutdown();
      }
      originalMsg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();
      // -----------------------------------------------------------------

      // --- Blur image and convert to HSV
      // -----------------------------------------------------------------
      resize(frame, frame, Size(frame.size().width / scaleFactor, frame.size().height / scaleFactor));
      GaussianBlur(frame, frame, Size(3, 3), 0);
      cvtColor(frame, hsv, COLOR_BGR2HSV);
      // -----------------------------------------------------------------

      // --- Threshold image using global parameters and erode noise
      // -----------------------------------------------------------------
      inRange(hsv, Scalar(hueLower, satLower, valLower), Scalar(hueUpper, satUpper, valUpper), mask1); //attempting to isolate red
      erode(mask1, mask1, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
      dilate(mask1, mask1, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
      // -----------------------------------------------------------------

      
      msg = cv_bridge::CvImage(std_msgs::Header(), "mono8", mask1).toImageMsg();

      pub_frame.publish(msg);
      pub_original_frame.publish(originalMsg);
      ros::spinOnce();
      loop_rate.sleep();
    }
 
    // Shutdown the camera
    capture.release();
}