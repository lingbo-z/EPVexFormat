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
  // This function runs during the autonomous period
  // You can either use the helper functions from functions.h or control motors directly
  
  // Option 1: Use simple time-based movement (easier for beginners)
  driveForTime(2000, 50);  // Drive forward for 2 seconds at 50% speed
  wait(500, msec);         // Pause for half a second
  turnForTime(1000, 40);   // Turn right for 1 second at 40% speed
  
  // Option 2: Or you can run the example function
  // basicAuton();
  
  // Option 3: Or control motors directly like this:
  // LeftMotor.spin(forward, 50, percent);
  // RightMotor.spin(forward, 50, percent);
  // wait(2000, msec);
  // LeftMotor.stop();
  // RightMotor.stop();
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
  // This is where you control the robot with the controller
  // The code inside this loop runs over and over while the robot is enabled
  
  while (1) {
    // ========== TANK DRIVE CONTROL ==========
    // Get joystick values for tank drive
    // Left joystick Y-axis controls left motor
    // Right joystick Y-axis controls right motor
    int leftSpeed = Controller1.Axis3.position(percent);   // Left Y joystick (-100 to 100)
    int rightSpeed = Controller1.Axis2.position(percent);  // Right Y joystick (-100 to 100)
    
    // Make the motors spin at the joystick speeds
    LeftMotor.spin(forward, leftSpeed, percent);
    RightMotor.spin(forward, rightSpeed, percent);
    
    // ========== ARM CONTROL ==========
    // Use shoulder buttons to control the arm
    if (Controller1.ButtonL1.pressing()) {
      armUp();        // L1 button moves arm up
    } else if (Controller1.ButtonL2.pressing()) {
      armDown();      // L2 button moves arm down  
    } else {
      armStop();      // No button = stop arm
    }
    
    // ========== CLAW CONTROL ==========
    // Use trigger buttons to control the claw
    if (Controller1.ButtonR1.pressing()) {
      clawOpen();     // R1 button opens claw
    } else if (Controller1.ButtonR2.pressing()) {
      clawClose();    // R2 button closes claw
    } else {
      clawStop();     // No button = stop claw
    }
    
    // ========== HELPFUL BUTTON ==========
    // A button resets the motor position counters (useful for autonomous)
    if (Controller1.ButtonA.pressing()) {
      resetDrivePosition();
      Controller1.rumble(".");  // Give feedback that it worked
      wait(200, msec);          // Wait so button press doesn't repeat
    }

    // This small delay prevents the program from using too much processing power
    wait(20, msec);
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