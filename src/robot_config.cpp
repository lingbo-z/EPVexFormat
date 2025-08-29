#include "vex.h"

using namespace vex;

// Robot configuration
brain Brain;

// Controller
controller Controller1 = controller(primary);

// Motors - VEX Clawbot Configuration (Official Port Assignments)
motor LeftMotor = motor(PORT1, ratio18_1, false);     // Left drive motor
motor RightMotor = motor(PORT10, ratio18_1, true);    // Right drive motor (reversed)
motor ArmMotor = motor(PORT8, ratio18_1, false);      // Arm motor
motor ClawMotor = motor(PORT3, ratio18_1, false);     // Claw motor

// Drivetrain - 2-motor tank drive, no gyro (VEX Clawbot standard)
drivetrain Drivetrain = drivetrain(LeftMotor, RightMotor, 319.19, 295, 40, mm, 1);

// Initialize robot hardware
void vexcodeInit(void) {
  // Reset motor encoders
  LeftMotor.resetPosition();
  RightMotor.resetPosition();
  ArmMotor.resetPosition();
  ClawMotor.resetPosition();
  
  // Set motor brake modes
  LeftMotor.setBrake(brake);
  RightMotor.setBrake(brake);
  ArmMotor.setBrake(hold);      // Hold position for arm
  ClawMotor.setBrake(hold);     // Hold position for claw
  
  // Display initialization message
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1, 1);
  Brain.Screen.print("VEX Clawbot Template");
  Brain.Screen.newLine();
}