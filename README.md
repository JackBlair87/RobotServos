Advanced Servo Library for Arduino
-
RobotServos is a Arduino Library used to simplify servo control on basic, two wheeled robots.

To accomplish this, the robot is considered to be in one of several states. 
  STOP = 0, 
  FORWARD = 1, 
  REVERSE = 2, 
  LEFT = 3, 
  RIGHT = 4, 
  ERROR = -1

Both servos are moved at their max speed and will do so until the state is changed to STOP. 
One major advantage of this library is that there is no need for servo stop values because the servos can be detached with each respective state. 
This library is written on top of the native Servo Arduino library.
_
Methods:
1. RobotServos(int rightPin, int leftPin) --> creates a new RobotServos with the pin of the right servo, and pin of the left servo.
2. getState() --> returns the current state of the robot.
3. setState(int newPosition) --> changes the state of the robot.
4. inverse() --> inverts the output of the servos in case they were mounted in the wrong direction.
_____________________________________________
Created by Jack Blair
-
