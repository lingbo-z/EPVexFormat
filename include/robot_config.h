#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H

#include "vex.h"

using namespace vex;

// Robot configuration
extern brain Brain;

// Controller
extern controller Controller1;

// Motors - VEX Clawbot Configuration
extern motor LeftMotor;     // Port 1
extern motor RightMotor;    // Port 10
extern motor ArmMotor;      // Port 8
extern motor ClawMotor;     // Port 3

// Drivetrain - 2-motor tank drive (no gyro)
extern drivetrain Drivetrain;

// Initialize robot hardware
void vexcodeInit(void);

#endif