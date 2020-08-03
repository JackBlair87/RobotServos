// -----
// RobotServos.h
// This class is implemented for use with the Arduino environment.
// Created by Jack Blair
// -----

#include "Arduino.h"
#include "RobotServos.h"
#include "Servo.h"

// ----- Initialization and Default Values -----

RobotServos::RobotServos(int rightPin, int leftPin) {
  //set private fields to arguments
  rightServoPin = rightPin;
  leftServoPin = leftPin;
  
  //currentState set to stop as default
  currentState = State::STOP;
  currentIntState = 0;
} 

int RobotServos::getState() {
  return currentIntState;
  //just returns the current state
}

void RobotServos::setState(int newPosition) {
  if(newPosition > -1 && newPosition < numTotalStates){ //make sure newPosition is in range
    if(newPosition != currentIntState){ //only change if state is different
      currentIntState = newPosition;
      switch (newPosition) {
        case 0:
          currentState = State::STOP;
          rServo.detach();
          lServo.detach();
          Serial.println("Vehicle Stopped");
          break;
        case 1:
          currentState = State::FORWARD;
          rServo.attach(rightServoPin);
          lServo.attach(leftServoPin);
          lServo.write(maxBackward);
          rServo.write(maxForward);
          Serial.println("Vehicle Forward");
          break;
        case 2:
          currentState = State::REVERSE;
          rServo.attach(rightServoPin);
          lServo.attach(leftServoPin);
          lServo.write(maxForward);
          rServo.write(maxBackward);
          Serial.println("Vehicle Backward");
          break;
        case 3:
          currentState = State::LEFT;
          rServo.attach(rightServoPin);
          lServo.attach(leftServoPin);
          lServo.write(maxForward);
          rServo.write(maxForward);
          Serial.println("Vehicle Turning Left");
          break;
        case 4:
          currentState = State::RIGHT;
          rServo.attach(rightServoPin);
          lServo.attach(leftServoPin);
          lServo.write(maxBackward);
          rServo.write(maxBackward);
          Serial.println("Vehicle Turning Right");
          break;
        }
    }
  }
  else{
    currentState = State::ERROR;
    currentIntState = -1;
    rServo.detach();
    lServo.detach();
    Serial.println("Invalid State");
  }
}

  void RobotServos::inverse() {
    int x = maxBackward;
    maxBackward = maxForward;
    maxForward = x;
    Serial.println("Servo direction inversed");
  }
