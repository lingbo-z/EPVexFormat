#include "vex.h"

using namespace vex;

// Autonomous selection variables
int autonSelection = 0;
const int numAutons = 4;
const char* autonNames[] = {
  "Clawbot Left",
  "Clawbot Right", 
  "Clawbot Skills",
  "Clawbot Test"
};

void displayAutonSelector() {
  // Display current selection on controller screen
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print("Clawbot Auton:");
  Controller1.Screen.setCursor(2, 1);
  Controller1.Screen.print("< %s >", autonNames[autonSelection]);
  Controller1.Screen.setCursor(3, 1);
  Controller1.Screen.print("A=Select L/R=Change");
  
  // Also display on brain screen
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1, 1);
  Brain.Screen.print("VEX Clawbot Template");
  Brain.Screen.setCursor(3, 1);
  Brain.Screen.print("Autonomous: %s", autonNames[autonSelection]);
  Brain.Screen.setCursor(5, 1);
  Brain.Screen.print("Use controller buttons");
}

void selectAuton() {
  // Display initial selection
  displayAutonSelector();
  
  while (true) {
    // Check for selection change
    if (Controller1.ButtonLeft.pressing()) {
      autonSelection = (autonSelection - 1 + numAutons) % numAutons;
      displayAutonSelector();
      Controller1.rumble(".");
      wait(200, msec); // Debounce
    }
    
    if (Controller1.ButtonRight.pressing()) {
      autonSelection = (autonSelection + 1) % numAutons;
      displayAutonSelector(); 
      Controller1.rumble(".");
      wait(200, msec); // Debounce
    }
    
    // Confirm selection
    if (Controller1.ButtonA.pressing()) {
      Controller1.Screen.clearScreen();
      Controller1.Screen.setCursor(1, 1);
      Controller1.Screen.print("Clawbot Ready!");
      Controller1.Screen.setCursor(2, 1);
      Controller1.Screen.print("Mode: %s", autonNames[autonSelection]);
      Controller1.rumble("--");
      break;
    }
    
    wait(20, msec);
  }
}

int getAutonSelection() {
  return autonSelection;
}