#include "vex.h"

using namespace vex;

void basicAuton() {
  // Simple autonomous routine for beginners to learn from
  // This function shows basic robot movements
  
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print("Basic Autonomous");
  
  // Reset drivetrain position
  resetDrivePosition();
  
  // Example 1: Drive forward for 2 seconds
  LeftMotor.spin(forward, 50, percent);
  RightMotor.spin(forward, 50, percent);
  wait(2, sec);
  
  // Stop motors
  LeftMotor.stop();
  RightMotor.stop();
  wait(0.5, sec);
  
  // Example 2: Turn right by spinning motors in opposite directions
  LeftMotor.spin(forward, 40, percent);
  RightMotor.spin(reverse, 40, percent);
  wait(1, sec);
  
  // Stop motors
  LeftMotor.stop();
  RightMotor.stop();
  wait(0.5, sec);
  
  // Example 3: Test arm movement
  armUp();
  wait(1, sec);
  armStop();
  wait(0.5, sec);
  armDown();
  wait(1, sec);
  armStop();
  
  // Example 4: Test claw movement
  clawOpen();
  wait(1, sec);
  clawClose();
  wait(1, sec);
  clawStop();
}