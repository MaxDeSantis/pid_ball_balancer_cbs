#include "ros.h"
#include "std_msgs/Float32.h"
#include "VarSpeedServo.h"

int control = 0;
volatile float pos = 0;
int midpoint;
float previousError = 0;
float integral = 0;
int minError = -160;
int maxError = 150;
int umax = 96;
int umin = 67;
int umid = (umax + umin) / 2;

void posCallBack(const std_msgs::Float32& pos_msg) {
  pos = pos_msg.data;
}
void midpointCallBack(const std_msgs::Float32& midpoint_msg) {
  midpoint = midpoint_msg.data;
}


ros::NodeHandle nh;
ros::Subscriber<std_msgs::Float32> pos_sub("/llc/pos", &posCallBack);
ros::Subscriber<std_msgs::Float32> midpoint_sub("/llc/midpoint", &midpointCallBack);

std_msgs::Float32 error_msg;
std_msgs::Float32 control_msg;
std_msgs::Float32 midpoint_msg;
std_msgs::Float32 unbound_control_msg;
ros::Publisher error_pub("/feedback/error", &error_msg);
ros::Publisher control_pub("/feedback/control", &control_msg);
ros::Publisher midpoint_pub("/feedback/midpoint", &midpoint_msg);
ros::Publisher unbound_control_pub("/feedback/integral", &unbound_control_msg);

VarSpeedServo armServo;
int servoPin = 3;
float kp = 1.3;
float kd = 3000;
float ki = 0.2;

void setup() {

  nh.initNode();
  nh.subscribe(pos_sub);
  nh.subscribe(midpoint_sub);
  nh.advertise(error_pub);
  nh.advertise(control_pub);
  nh.advertise(midpoint_pub);
  nh.advertise(unbound_control_pub);

  armServo.attach(servoPin);
  armServo.write(umid, 255);
  delay(1000);
}

void loop() {
  midpoint_msg.data = midpoint;
  midpoint_pub.publish(&midpoint_msg);
  nh.spinOnce();
  int u = calculateControl();
 
  armServo.write(u, 255);
  delay(15);
}

int calculateControl() {
  float error = pos - midpoint;
  float derivative = (error - previousError) / 15;
  float dintegral = (error - previousError) * 15;
  integral += dintegral;
  error_msg.data = error;
  
  control =  (error * kp) + (integral * ki) + (derivative * kd);
  unbound_control_msg.data = integral;

  if(control > umax || control < umin) {
    control -= ki * integral;
    integral -= dintegral;
  }
  control = map(control, minError, maxError, umin, umax);
  control = max(umin, min(umax, control));
  
  control_msg.data = control;
  
  error_pub.publish(&error_msg);
  unbound_control_pub.publish(&unbound_control_msg);
  control_pub.publish(&control_msg);

  previousError = error;
  
  return control;
}
