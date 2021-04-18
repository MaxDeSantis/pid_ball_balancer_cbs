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
#include <numeric>

using namespace std;
using namespace cv;

void frameCallBack(const sensor_msgs::ImageConstPtr& frame_msg);
void feedback();

std_msgs::Float32 pos_msg;
std_msgs::Float32 midpoint_msg;
Mat newFrame;
sensor_msgs::ImagePtr detectedFrameMsg;
bool midSent = false;

int main(int argc, char** argv) {

    ros::init(argc, argv, "pos_pub_node");
    ros::NodeHandle nh;

    image_transport::ImageTransport it(nh);

    image_transport::Subscriber frame_sub = it.subscribe("/cam/monoframe", 1, frameCallBack);
    image_transport::Publisher  detected_pub = it.advertise("/cam/detectedframe", 1);
    ros::Publisher              pos_pub = nh.advertise<std_msgs::Float32>("/llc/pos", 1);
    ros::Publisher              midpoint_pub = nh.advertise<std_msgs::Float32>("/llc/midpoint", 1);
    ros::Rate loop_rate(60);

    RNG rng(12345);
    Mat canny_output;
    while(ros::ok()) {
        
        midpoint_msg.data = newFrame.cols / 2;
        
        Canny(newFrame, canny_output, 100, 200);

        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;
        findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

        Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
        vector<int> indices(contours.size());
        iota(indices.begin(), indices.end(), 0);

        if(contours.size() > 0) {
            sort(indices.begin(), indices.end(), [&contours](int lhs, int rhs) {
                return contours[lhs].size() > contours[rhs].size();
            });
            drawContours(drawing, contours, indices[0], Scalar(0, 0, 255), 2, LINE_8, hierarchy, 0);
            Point2f center;
            float radius = 0;
            minEnclosingCircle(contours.at(indices[0]), center, radius);
            pos_msg.data = center.x;
            detectedFrameMsg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", drawing).toImageMsg();
            detected_pub.publish(detectedFrameMsg);
            pos_pub.publish(pos_msg);
        }
        
        midpoint_pub.publish(midpoint_msg);
        
        

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}

void feedback() {
    
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