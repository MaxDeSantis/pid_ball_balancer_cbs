/* PID controller for Ball Balancer.
 * Subscribes to position and midpoint topics. Actuates servo to control rail angle.
 */

#include "ros.h"
#include "std_msgs/Float32.h"
#include "VarSpeedServo.h"

// --- Variables
// ---------------------------------------------------------------
// Control Variables
int control = 0;
float pos = 0;
int setpoint;
float prevError = 0;
float integral = 0;

// System Variables
int maxErr = 157;
int minErr = -157;
int umax = 95; int umin = 65;
int umid = (umax + umin) / 2;
int loop_time = 15;

// Servo
VarSpeedServo armServo;
int servoPin = 3;

// PID Gains
float oKp = 0.85; float kp;
float kd = 0.3;
float ki = 0.55;

// Time Variables
unsigned long lastControlTime;
unsigned long lastWriteTime;
// ---------------------------------------------------------------

// --- Callback functions for ROS subscribers
// ---------------------------------------------------------------
void posCallBack(const std_msgs::Float32& pos_msg) {
  pos = pos_msg.data;
}
void midpointCallBack(const std_msgs::Float32& midpoint_msg) {
  setpoint = midpoint_msg.data;
}

void kpCallBack(const std_msgs::Float32& newKP) {
  kp = newKP.data;
}

void kiCallBack(const std_msgs::Float32& newKI) {
  ki = newKI.data;
}

void kdCallBack(const std_msgs::Float32& newKD) {
  kd = newKD.data;
}
// ---------------------------------------------------------------


// --- ROS Setup
// ---------------------------------------------------------------
ros::NodeHandle nh;

ros::Subscriber<std_msgs::Float32> pos_sub("/llc/pos", &posCallBack);
ros::Subscriber<std_msgs::Float32> midpoint_sub("/llc/midpoint", &midpointCallBack);

std_msgs::Float32 error_msg;
std_msgs::Float32 control_msg;

ros::Publisher error_pub("/feedback/error", &error_msg);
ros::Publisher control_pub("/feedback/control", &control_msg);
// ---------------------------------------------------------------

void setup() {

  // --- Initialize ROS and advertise/subscribe to necessary topics.
  nh.initNode();
  nh.subscribe(pos_sub);
  nh.subscribe(midpoint_sub);
  nh.advertise(error_pub);
  nh.advertise(control_pub);

  // --- Setup servo
  armServo.attach(servoPin);
  armServo.write(umid, 255);
  
  delay(1000);
  lastWriteTime = millis();
}

void loop() {

  // --- Calculate new control signal and write it to servo every loop_time milliseconds
  if( (millis() - lastWriteTime) >= loop_time) {
    int u = calculateControl();
    armServo.write(u, 255);
    lastWriteTime = millis();
  }
  
  nh.spinOnce();
}

int calculateControl() {
  
  unsigned long now = millis();
  double timeElapsed = (double)(now - lastControlTime) / 1000;
  double error = pos - setpoint;
  double dError = (error - prevError) / timeElapsed;
  double dintegral = (error * ki) * timeElapsed;
  integral += dintegral;

  if(abs(error) < 15) {
    integral -= dintegral;
  }
  
  if(abs(error) > 140) {
    kp = 1.3;
  }
  else {
    kp = oKp;
  }

  control =  (error * kp) + integral + (dError * kd);

  control = map(control, minErr, maxErr, umin, umax);
  
  if(control > umax) {
    integral -= dintegral;
    control = umax;
  }
  else if(control < umin) {
    integral -= dintegral;
    control = umin;
  }
  
  control_msg.data = control;
  error_msg.data = error;
  
  error_pub.publish(&error_msg);
  control_pub.publish(&control_msg);

  prevError = error;
  lastControlTime = millis();

  return control;
}
