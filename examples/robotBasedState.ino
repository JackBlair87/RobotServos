#include <RobotServos.h>

RobotServos servos(11, 12);
int robotState = 0;

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  robotState = random(0, 5);
  Serial.println("Robot State changed to: " + robotState);
  
  if(servos.getState() != robotState){
    servos.setState(robotState);
  }
  
  delay(2000);
}
