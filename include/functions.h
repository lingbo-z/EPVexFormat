#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "vex.h"

using namespace vex;

// Clawbot Utility Functions
double inchesToDegrees(double inches);
void driveForward(double distance, double speed);
void driveBackward(double distance, double speed);
void turnLeft(double degrees, double speed);
void turnRight(double degrees, double speed);
void stopDrive();
void resetDrivePosition();

#endif