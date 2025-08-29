#include "vex.h"

using namespace vex;

void autonLeft() {
  // Clawbot left side autonomous routine
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print("Clawbot Left Auto");
  
  // Reset drivetrain position
  resetDrivePosition();
  
  // Open claw to prepare for grabbing
  clawOpen();
  wait(0.5, sec);
  clawStop();
  
  // Drive forward to object
  driveForward(18, 60);
  
  // Close claw to grab object
  clawClose();
  wait(1, sec);
  clawStop();
  
  // Lift arm with object
  armUp();
  wait(1.5, sec);
  armStop();
  
  // Turn around
  turnRight(180, 50);
  
  // Drive to scoring position
  driveForward(12, 60);
  
  // Lower arm to score
  armDown();
  wait(1, sec);
  armStop();
  
  // Release object
  clawOpen();
  wait(0.5, sec);
  clawStop();
}

void autonRight() {
  // Clawbot right side autonomous routine
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print("Clawbot Right Auto");
  
  // Reset drivetrain position
  resetDrivePosition();
  
  // Open claw to prepare for grabbing
  clawOpen();
  wait(0.5, sec);
  clawStop();
  
  // Drive forward to object
  driveForward(18, 60);
  
  // Close claw to grab object
  clawClose();
  wait(1, sec);
  clawStop();
  
  // Lift arm with object
  armUp();
  wait(1.5, sec);
  armStop();
  
  // Turn left to scoring position
  turnLeft(90, 50);
  
  // Drive to scoring position
  driveForward(15, 60);
  
  // Lower arm to score
  armDown();
  wait(1, sec);
  armStop();
  
  // Release object
  clawOpen();
  wait(0.5, sec);
  clawStop();
}

void autonSkills() {
  // Clawbot skills autonomous routine
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print("Clawbot Skills");
  
  // Reset drivetrain position
  resetDrivePosition();
  
  // Simple skills routine - collect and move objects
  for (int i = 0; i < 3; i++) {
    // Open claw
    clawOpen();
    wait(0.5, sec);
    clawStop();
    
    // Drive to object
    driveForward(12, 50);
    
    // Close claw
    clawClose();
    wait(1, sec);
    clawStop();
    
    // Lift object
    armUp();
    wait(1, sec);
    armStop();
    
    // Turn towards scoring area
    turnRight(90, 50);
    
    // Drive to scoring area
    driveForward(8, 50);
    
    // Lower arm
    armDown();
    wait(0.8, sec);
    armStop();
    
    // Release object
    clawOpen();
    wait(0.5, sec);
    clawStop();
    
    // Return to collect next object
    driveBackward(8, 50);
    turnLeft(90, 50);
  }
}

void autonTest() {
  // Simple Clawbot test routine
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print("Clawbot Test");
  
  // Reset position
  resetDrivePosition();
  
  // Test basic drive movements
  driveForward(12, 50);
  wait(1, sec);
  
  // Test turning
  turnRight(90, 50);
  wait(1, sec);
  
  // Test arm movement
  armUp();
  wait(1, sec);
  armStop();
  wait(0.5, sec);
  armDown();
  wait(1, sec);
  armStop();
  
  // Test claw movement
  clawOpen();
  wait(1, sec);
  clawClose();
  wait(1, sec);
  clawStop();
  
  // Drive back
  driveBackward(12, 50);
}