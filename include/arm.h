#ifndef ARM_H
#define ARM_H

#include "vex.h"

using namespace vex;

// Clawbot Arm Control Functions
void armUp();
void armDown();
void armStop();

// Clawbot Claw Control Functions
void clawOpen();
void clawClose();
void clawStop();

#endif