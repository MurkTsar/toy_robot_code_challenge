# Toy Robot Challenge

This project is a solution to the Toy Robot Challenge. The program simulates a robot moving on a tabletop and executes a series of commands provided by the user or from a file.

## Features

- **User-Friendly**: The program is case-insensitive and includes error handling for invalid commands.
- **Default Values**: The `PLACE` command assigns a default position of `0,0,NORTH` if no parameters are provided.
- **Simple UI**: The program can run with a simple interactive UI
- **Command Input**: The program can read commands from:
  - User input through the console (using Simple UI).
  - A specified text file (Simple UI and -f flag).
- **Graphical Display**: The program displays a graphical representation of the table and finaly position and direction of the robot at the end of each entry of movesets.

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

### 1. Command Line Help Menu

A guide can be view with a -h flag:

```bash
.\ToyRobotApp.exe -h
```

### 2. From Command Line with Manual Input

To execute the program with a set of manually inputted commands, use the following command:

```bash
.\ToyRobotApp.exe -m <set of moves with new line delimeters>
```

Example:

```bash
.\ToyRobotApp.exe -m "PLACE 2,4,WEST
MOVE
LEFT
MOVE
LEFT
MOVE
REPORT"
```

### 3. From Command Line with File Input

To execute the program with a set of commands from a file, use the following command:

```bash
.\ToyRobotApp.exe -f path\to\sample_moveset.txt
```

Example:

```bash
.\ToyRobotApp.exe -f "..\..\sample_messy_moveset.txt"
```

### 4. Interactive Simple UI

If you prefer to use the Simple UI, simply run the program without flags:

```bash
.\ToyRobotApp.exe
```

You will then be prompted to enter commands directly in the console with an interactive simple UI.

### Command Format

The commands can include:
- `PLACE x,y,NORTH|EAST|SOUTH|WEST` to place the robot.
- `PLACE` to place the robot on default spot `0,0,NORTH`.
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

### Example Output

Here’s an example of how the output would look:

```bash
Output: 0, 1, WEST
 --- --- --- --- ---
|   |   |   |   |   |
 --- --- --- --- ---
|   |   |   |   |   |
 --- --- --- --- ---
|   |   |   |   |   |
 --- --- --- --- ---
| < |   |   |   |   |
 --- --- --- --- ---
|   |   |   |   |   |
 --- --- --- --- ---
```

### Termination

While using manual input through Simple UI, terminate your command sequence with `;` or `.`.

```bash
PLACE 0,0,SOUTH
LEFT
MOVE
MOVE
REPORT;
```

```bash
PLACE 0,0,EAST
MOVE
RIGHT
MOVE
REPORT
;
```

### Running Tests

To run the unit tests, first, build the project in Debug mode:

```bash
cmake --build build --config Debug
```

Once built, navigate to the `UnitTests` directory in your build folder and run the executable:

```bash
.\UnitTests.exe
```