#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
  // Display autonomous selector
  selectAuton();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                        */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // Run selected autonomous routine
  int selection = getAutonSelection();
  
  switch(selection) {
    case 0:
      autonLeft();
      break;
    case 1:
      autonRight(); 
      break;
    case 2:
      autonSkills();
      break;
    case 3:
      autonTest();
      break;
    default:
      autonTest();
      break;
  }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                        */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // ========== CLAWBOT DRIVETRAIN CONTROL ==========
    // Tank drive: Left stick Y controls left motor, Right stick Y controls right motor
    int leftSpeed = Controller1.Axis3.position(percent);
    int rightSpeed = Controller1.Axis2.position(percent);
    
    // Apply tank drive control
    LeftMotor.spin(forward, leftSpeed, percent);
    RightMotor.spin(forward, rightSpeed, percent);
    
    // ========== CLAWBOT ARM CONTROL ==========
    // L1 and L2 buttons control arm up/down
    if (Controller1.ButtonL1.pressing()) {
      armUp();
    } else if (Controller1.ButtonL2.pressing()) {
      armDown();
    } else {
      armStop();
    }
    
    // ========== CLAWBOT CLAW CONTROL ==========
    // R1 and R2 buttons control claw open/close
    if (Controller1.ButtonR1.pressing()) {
      clawOpen();
    } else if (Controller1.ButtonR2.pressing()) {
      clawClose();
    } else {
      clawStop();
    }
    
    // ========== UTILITY FUNCTIONS ==========
    // A button resets drive encoders
    if (Controller1.ButtonA.pressing()) {
      resetDrivePosition();
      Controller1.rumble(".");
      wait(200, msec); // Debounce
    }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}