// -----
// RobotServos.h
// This class is implemented for use with the Arduino environment.
// Created by Jack Blair
// -----

#ifndef RobotServos_h
#define RobotServos_h

#include "Arduino.h"
#include "Servo.h"

class RobotServos
{
public:
  enum class State { STOP = 0, FORWARD = 1, REVERSE = 2, LEFT = 3, RIGHT = 4, ERROR = -1};

  // ----- Constructor -----
  RobotServos(int rightPin, int leftPin);
  //Accepts two arguments; first for the Arduino pin which is wired to the right servo, and the other for the left
  
  // simple retrieve of the state; will return -1 through 4 (Corresponding to the State enum)
  int getState();

  // adjust the current state; can change to 0 through 4, according to the State enum
  void setState(int newPosition);

  //will inverse servo output if servos are moving in the opposite direction than desired (Moving backward when "Forward", etc.)
  void inverse();

private:
  int rightServoPin, leftServoPin; // Arduino pins used for the servos. 

  int maxForward = 180, maxBackward = 0; //Set to the max speeds for continuous rotation servos; 
  //Changing these will change servo movement speed 

  State currentState; //Keeps track of current state in State and int form
  int currentIntState;

  int numTotalStates = 5; //This can be changed if the number of states wants to be expanded upon

  Servo rServo, lServo; //Servo objects for the left and right servos
};

#endif
