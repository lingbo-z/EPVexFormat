#ifndef MAIN_H
#define MAIN_H

#include "vex.h"

using namespace vex;

// Include subsystem headers
#include "robot-config.h"
#include "autons.h"
#include "functions.h"
#include "arm.h"

// Competition functions
void pre_auton(void);
void autonomous(void);
void usercontrol(void);

#endif