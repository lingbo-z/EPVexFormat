# VEX V5 Clawbot Template

A simple VEX V5 robot template specifically designed for the **VEX Clawbot starter kit** using best practices for C++ robotics programming with proper project structure and modular design. This template provides a clean foundation for VEX competition programming.

## Project Structure

```
VEX-V5-Clawbot-Template/
├── include/                  # Header files
│   ├── main.h               # Main header with includes
│   ├── vex.h                # VEX library includes
│   ├── robot-config.h       # Clawbot hardware configuration
│   ├── autons.h             # Autonomous routine declarations
│   ├── auton-selector.h     # Interactive autonomous selector
│   ├── functions.h          # Utility functions
│   └── arm.h                # Arm and claw control
├── src/                     # Source files
│   ├── main.cpp             # Main competition template
│   ├── robot-config.cpp     # Hardware initialization
│   ├── autons.cpp           # Autonomous routines
│   ├── auton-selector.cpp   # Autonomous selection system
│   ├── functions.cpp        # Utility functions
│   └── arm.cpp              # Arm and claw control
├── project.pros             # PROS project configuration
├── Makefile                 # Build configuration
└── README.md               # This file
```

## Features

### Hardware Support (VEX Clawbot Specific)
- **2-Motor Tank Drive**: Left and right drive motors (Ports 1 & 10)
- **Robotic Arm**: Single-joint arm motor (Port 8)
- **Claw Mechanism**: Claw motor for gripping (Port 3)
- **Official Port Configuration**: Matches VEX Clawbot build instructions

### Software Features
- **Simple Autonomous Control**: Time and encoder-based movement
- **Interactive Autonomous Selector**: Controller-based menu system
- **Competition Template**: Full VEX competition support
- **Function-Based Design**: Clean, modular code organization
- **Tank Drive Control**: Intuitive joystick control

## Hardware Configuration (VEX Clawbot Standard)

### Motors
- **Port 1**: Left Drive Motor (18:1 gearing, 4" wheels)
- **Port 10**: Right Drive Motor (18:1 gearing, 4" wheels, reversed)
- **Port 8**: Arm Motor (18:1 gearing with external gearing)
- **Port 3**: Claw Motor (18:1 gearing)

### Controller Layout
- **Left Stick Y**: Left drive motor (tank mode)
- **Right Stick Y**: Right drive motor (tank mode)
- **L1**: Arm up
- **L2**: Arm down
- **R1**: Claw open
- **R2**: Claw close
- **A**: Reset drive encoders

## Autonomous Routines

Four autonomous routines specifically designed for Clawbot capabilities:

1. **Clawbot Left**: Grab object, lift, turn around, and score
2. **Clawbot Right**: Grab object, lift, turn left, and score  
3. **Clawbot Skills**: Collect and move multiple objects in sequence
4. **Clawbot Test**: Test all subsystems and basic functions

## Getting Started

### Prerequisites
- VEX V5 Clawbot built according to official instructions
- VEXcode V5 or compatible development environment

### Quick Setup
1. **Download Template**: Clone or download this template
2. **Hardware Check**: Verify your Clawbot uses the standard port configuration
3. **Upload Code**: Deploy to your V5 brain
4. **Select Autonomous**: Use controller buttons to choose autonomous routine
5. **Test Drive**: Use tank drive controls to verify motor directions

## Customization Guide

### Modifying Autonomous Routines
1. Edit routines in `src/autons.cpp`
2. Adjust distances, speeds, and timing as needed
3. Test using the "Clawbot Test" autonomous mode

### Adding Custom Functions
1. Declare functions in appropriate header files
2. Implement in corresponding source files
3. Follow the existing naming conventions

### Controller Mapping Changes
1. Modify button assignments in `src/main.cpp`
2. Update this README to reflect changes

## VEX Resources

- [VEX V5 Clawbot Build Instructions](https://www.vexrobotics.com/v5/downloads/build-instructions)
- [VEXcode V5 Documentation](https://www.vexrobotics.com/vexcode/pro-v5)
- [VEX Robotics Competition](https://www.roboticseducation.org/)

## Technical Specifications

- **Target Robot**: VEX V5 Clawbot (Classroom/Competition Starter Kit)
- **Drive System**: 2-motor tank drive, no sensors
- **Wheel Size**: 4" diameter
- **Track Width**: Approximately 11.5"
- **Programming Language**: C++ with VEX V5 API
- **Control Method**: Encoder-based positioning and time-based movement

## License

This template is provided for educational use with VEX Robotics products. Modify freely for your Clawbot projects and competitions.