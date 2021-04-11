/* Publishes processed frames as read by the camera.






*/
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

/*
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
*/

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
    //image_transport::Publisher pub_erode = it.advertise("/cam/erode", 1);
    //ros::Publisher pub_error = nh.advertise<std_msgs::Float64>("/llc/error", 1);
    //ros::Subscriber param_sub = nh.subscribe("/cam/params", 1, paramCallback);
    // --------------------------------------------------------------------------
    ros::Rate loop_rate(30); //Run at 30 FPS

    sensor_msgs::ImagePtr msg;
    //sensor_msgs::ImagePtr msgerode;
    //std_msgs::Float64 error;

    Mat frame;
    Mat hsv;
    Mat mask1;
    Mat keyPointMat;
    /*
    SimpleBlobDetector::Params params;
    params.minThreshold = 10;
    params.maxThreshold = 200;
    params.filterByArea = true;
    params.minArea = 1200;
    params.maxArea = 4000;

    params.filterByColor = true;
    params.blobColor = 255;

    params.filterByCircularity=true;
    params.minCircularity = 0.2;
    params.filterByConvexity=false;
    params.filterByInertia=false;
    
    Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);
    vector<KeyPoint> keypoints;
    float midpoint; */
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

      /*
      detector->detect(mask1, keypoints);
      drawKeypoints(frame, keypoints, keyPointMat, Scalar(0, 0, 255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
      if(keypoints.size() > 0) {
        midpoint = mask1.cols / 2;
        error.data = keypoints.at(0).pt.x - midpoint;
        pub_error.publish(error);
      }*/
      
      msg = cv_bridge::CvImage(std_msgs::Header(), "mono8", mask1).toImageMsg();
      //msgerode = cv_bridge::CvImage(std_msgs::Header(), "bgr8", keyPointMat).toImageMsg();

      pub_frame.publish(msg);
      //pub_erode.publish(msgerode);
      
      cv::waitKey(1); // Display image for 1 millisecond
 
      ros::spinOnce();
      loop_rate.sleep();
    }
 
    // Shutdown the camera
    capture.release();
}