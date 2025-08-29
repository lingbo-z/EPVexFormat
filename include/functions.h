#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "vex.h"

using namespace vex;

// Basic Robot Movement Functions for Beginners
// These functions help new programmers control the robot easily

// Helper function to convert inches to motor degrees
double inchesToDegrees(double inches);

// Drive Functions - Make the robot move
void driveForward(double distance, double speed);    // Move forward (distance in inches, speed 0-100%)
void driveBackward(double distance, double speed);   // Move backward
void turnLeft(double degrees, double speed);         // Turn left (degrees 0-360, speed 0-100%)  
void turnRight(double degrees, double speed);        // Turn right
void stopDrive();                                    // Stop all drive motors
void resetDrivePosition();                           // Reset motor position counters

// Simple Movement Functions for Learning
void driveForTime(int milliseconds, int speed);      // Drive forward for specific time
void turnForTime(int milliseconds, int speed);       // Turn right for specific time

#endif