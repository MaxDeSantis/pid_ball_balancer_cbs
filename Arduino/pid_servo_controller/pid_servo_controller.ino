#include "ros.h"
#include "std_msgs/Float64.h"
#include <Servo.h>

int control = 0;
volatile float error = 0;
int umax = 90;
int umin = 55;

void errorCallback(const std_msgs::Float64& errorMsg) {
  error = errorMsg.data;
}

ros::NodeHandle nh;
ros::Subscriber<std_msgs::Float64> sub_error("/llc/error", &errorCallback);


Servo armServo;
int servoPin = 3;
int pos = 55;
float kp = 1;
float kd = 0;
float ki = 0;

void setup() {
  armServo.attach(servoPin);
  armServo.write(90);

  nh.initNode();
  nh.subscribe(sub_error);
  
}

void loop() {
  nh.spinOnce();
  int u = calculateControl();
  armServo.write(u);
  delay(1000);
  
  /*
  for(pos = 55; pos <= 100; pos++) {
    armServo.write(pos);
    delay(20);
  }
  delay(1000);
  for(pos = 100; pos >= 55; pos--) {
    armServo.write(pos);
    delay(20);
  }
  delay(1000);
  */

}

int calculateControl() {
  
  control = error * kp;

  //control = max(umin, min(umax, control));
  if(control > 100) {
    control = 100;
  }
  else if(control < 55) {
    control = 55;
  }
  
  return control;
}
