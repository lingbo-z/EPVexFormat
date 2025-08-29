#include "vex.h"

using namespace vex;

double inchesToDegrees(double inches) {
  // Convert inches to degrees based on wheel diameter
  // VEX Clawbot uses 4" wheels
  return inches * (360.0 / (4.0 * M_PI));
}

void driveForward(double distance, double speed) {
  double targetDegrees = inchesToDegrees(distance);
  LeftMotor.spinFor(forward, targetDegrees, degrees, speed, velocityUnits::pct, false);
  RightMotor.spinFor(forward, targetDegrees, degrees, speed, velocityUnits::pct, true);
}

void driveBackward(double distance, double speed) {
  double targetDegrees = inchesToDegrees(distance);
  LeftMotor.spinFor(reverse, targetDegrees, degrees, speed, velocityUnits::pct, false);
  RightMotor.spinFor(reverse, targetDegrees, degrees, speed, velocityUnits::pct, true);
}

void turnLeft(double degrees, double speed) {
  // Calculate turn distance based on Clawbot track width (approximately 11.5")
  double turnDistance = (degrees / 360.0) * (11.5 * M_PI);
  double targetDegrees = inchesToDegrees(turnDistance);
  LeftMotor.spinFor(reverse, targetDegrees, degrees, speed, velocityUnits::pct, false);
  RightMotor.spinFor(forward, targetDegrees, degrees, speed, velocityUnits::pct, true);
}

void turnRight(double degrees, double speed) {
  // Calculate turn distance based on Clawbot track width (approximately 11.5")
  double turnDistance = (degrees / 360.0) * (11.5 * M_PI);
  double targetDegrees = inchesToDegrees(turnDistance);
  LeftMotor.spinFor(forward, targetDegrees, degrees, speed, velocityUnits::pct, false);
  RightMotor.spinFor(reverse, targetDegrees, degrees, speed, velocityUnits::pct, true);
}

void stopDrive() {
  LeftMotor.stop();
  RightMotor.stop();
}

void resetDrivePosition() {
  LeftMotor.resetPosition();
  RightMotor.resetPosition();
}