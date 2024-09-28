#include "stdRobot.h"

// Constructor implementations
stdRobot::stdRobot() 
    : currentPosition{0, 0}, currentDirection(Direction::NORTH) {}

stdRobot::stdRobot(Position position, Direction direction) 
    : currentPosition(position), currentDirection(direction) {}

stdRobot::stdRobot(int xPos, int yPos, Direction direction) 
    : currentPosition{xPos, yPos}, currentDirection(direction) {}

stdRobot::~stdRobot() {}

void stdRobot::move() {
    switch (currentDirection) {
        case Direction::NORTH:
            currentPosition.y += 1;
            break;
        case Direction::EAST:
            currentPosition.x += 1;
            break;
        case Direction::SOUTH:
            currentPosition.y -= 1;
            break;
        case Direction::WEST:
            currentPosition.x -= 1;
            break;
    }
}

void stdRobot::turnLeft() {
    switch (currentDirection) {
        case Direction::NORTH:
            currentDirection = Direction::WEST;
            break;
        case Direction::WEST:
            currentDirection = Direction::SOUTH;
            break;
        case Direction::SOUTH:
            currentDirection = Direction::EAST;
            break;
        case Direction::EAST:
            currentDirection = Direction::NORTH;
            break;
    }
}

void stdRobot::turnRight() {
    switch (currentDirection) {
        case Direction::NORTH:
            currentDirection = Direction::EAST;
            break;
        case Direction::EAST:
            currentDirection = Direction::SOUTH;
            break;
        case Direction::SOUTH:
            currentDirection = Direction::WEST;
            break;
        case Direction::WEST:
            currentDirection = Direction::NORTH;
            break;
    }
}

/* NOTE:
 * These were the implementations that I had in mind, but for readability purposes 
 * and maintainability purposes, I've opted with the switch case style.
 * 
 * Turn Left
 * currentDirection = static_cast<Direction>((static_cast<int>(currentDirection) + 3) % 4);
 * 
 * Turn Right
 * currentDirection = static_cast<Direction>((static_cast<int>(currentDirection) + 1) % 4);
 */

Position stdRobot::nextPosition() {
    Position nextPos = currentPosition;

    switch (currentDirection) {
        case Direction::NORTH:
            nextPos.y += 1;
            break;
        case Direction::EAST:
            nextPos.x += 1;
            break;
        case Direction::SOUTH:
            nextPos.y -= 1;
            break;
        case Direction::WEST:
            nextPos.x -= 1;
            break;
    }

    return nextPos;
}

Position stdRobot::reportPosition() {
    return currentPosition;
}

Direction stdRobot::reportDirection() {
    return currentDirection;
}

std::string stdRobot::toStringReport() {
    return "output: " + std::to_string(currentPosition.x) + ", " 
                      + std::to_string(currentPosition.y) + ", " 
                      + directionToString(currentDirection);
}

void stdRobot::pickPlace(Position p, Direction f) {
    currentPosition = p;
    currentDirection = f;
}
