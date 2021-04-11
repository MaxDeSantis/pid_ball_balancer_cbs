/* Publishes ball position from frames using blob detection




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
#include <std_msgs/Float32.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void frameCallBack(const sensor_msgs::ImageConstPtr& frame_msg);


std_msgs::Float32 pos_msg;
std_msgs::Float32 midpoint_msg;
Mat newFrame;
bool midSent = false;

int main(int argc, char** argv) {

    ros::init(argc, argv, "pos_pub_node");
    ros::NodeHandle nh;

    image_transport::ImageTransport it(nh);

    image_transport::Subscriber frame_sub = it.subscribe("/cam/monoframe", 1, frameCallBack);
    ros::Publisher              pos_pub = nh.advertise<std_msgs::Float32>("/llc/pos", 1);
    ros::Publisher              midpoint_pub = nh.advertise<std_msgs::Float32>("/llc/midpoint", 1);
    ros::Rate loop_rate(30);
    
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

    while(ros::ok()) {

        if(!midSent) {
            midpoint_msg.data = newFrame.cols / 2;
            midpoint_pub.publish(midpoint_msg);
            midSent = true;
        }

        detector->detect(newFrame, keypoints);
        if(keypoints.size() > 0) {
            pos_msg.data = keypoints.at(0).pt.x;
            pos_pub.publish(pos_msg);
        }

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}

// --- Read published gray frame
void frameCallBack(const sensor_msgs::ImageConstPtr& frame_msg) {
    cv_bridge::CvImagePtr cv_ptr;
    try {
        cv_ptr = cv_bridge::toCvCopy(frame_msg, "mono8");
        newFrame = cv_ptr->image;
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("Could not convert from '%s' to 'mono8'.", frame_msg->encoding.c_str());
    }
}