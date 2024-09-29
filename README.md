# Toy Robot Challenge

This project is a solution to the Toy Robot Challenge. The program simulates a robot moving on a tabletop and executes a series of commands provided by the user or from a file.

## Features

- **C++17 or above**: The project is developed using modern C++ features.
- **Command Input**: The program can read commands from:
  - User input through the console.
  - A specified text file.
- **User-Friendly**: The program is case-insensitive and includes error handling for invalid commands.
- **Default Values**: The `PLACE` command assigns a default position of `0,0,NORTH` if no parameters are provided.
- **Command Termination**: User input can be terminated with a `;` or `.`.

## Requirements

- CMake version: Ensure you have the same version of CMake as used in this project.
- C++17 or above.

## Build Instructions

To build the project, navigate to the root directory and use the following commands:

### Release Build

```bash
cmake --build build --config Release
```

### Debug Build

```bash
cmake --build build --config Debug
```

## Usage

You can run the program in two ways:

### 1. From Command Line with File Input

To execute the program with a set of commands from a file, use the following command:

```bash
.\ToyRobotApp.exe -f path\to\sample_moveset.txt
```

Example:

```bash
.\ToyRobotApp.exe -f ..\..\sample_messy_moveset.txt
```

### 2. Interactive Robot Program

If you prefer to use the simple commandline UI, simply run the program without the `-f` flag:

```bash
.\ToyRobotApp.exe
```

You will then be prompted to enter commands directly in the console, with an interactive UI.

### Command Format

The commands can include:
- `PLACE x,y,NORTH|EAST|SOUTH|WEST` to place the robot.
- `PLACE` to place the robot on default spot 0,0,NORTH.
- `MOVE` to move the robot one unit in the current direction.
- `LEFT` to turn the robot left 90 degrees.
- `RIGHT` to turn the robot right 90 degrees.
- `REPORT` to display the robot's current position and direction.

### Example Input

Here’s an example of how the commands would look in the console:

```bash
PLACE 0,0,NORTH
MOVE
LEFT
MOVE
REPORT
```

### Termination

While using manual input, terminate your command sequence with `;` or `.`.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Inspired by the Toy Robot Challenge.
```

### Notes:
- This README provides a clear structure for potential users or contributors, detailing how to build and use your Toy Robot application.
- Ensure that the paths in the examples match your directory structure when you deploy the README.

Feel free to modify any sections as needed!