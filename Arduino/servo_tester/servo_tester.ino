//#include <Servo.h>
#include "VarSpeedServo.h"

int pos = 0;
int umax = 90;
int umin = 55;
//Servo armServo;

VarSpeedServo armServo;
int servoPin = 3;

void setup() {
  armServo.attach(servoPin);
  armServo.write(90, 20);
  delay(3000);
}

void loop() {
  
  
  for(pos = 50; pos <= 100; pos += 10) {
    armServo.write(pos, 20);
    delay(2000);
  }
  
  delay(4000);
  
  for(pos = 100; pos >= 50; pos -= 10) {
    armServo.write(pos, 20);
    delay(2000);
  }
  
  delay(4000);
  

}
