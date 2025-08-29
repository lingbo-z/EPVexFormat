#include "vex.h"

using namespace vex;

// Clawbot Arm Control Functions
void armUp() {
  ArmMotor.spin(forward, 30, percent);
}

void armDown() {
  ArmMotor.spin(reverse, 30, percent);
}

void armStop() {
  ArmMotor.stop();
}

// Clawbot Claw Control Functions
void clawOpen() {
  ClawMotor.spin(reverse, 50, percent);
}

void clawClose() {
  ClawMotor.spin(forward, 50, percent);
}

void clawStop() {
  ClawMotor.stop();
}