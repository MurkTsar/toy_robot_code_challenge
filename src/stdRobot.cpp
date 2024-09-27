#include "stdRobot.h"

// Constructor implementations
stdRobot::stdRobot() 
    : currentPosition{0, 0}, currentDirection(Direction::NORTH) {}

stdRobot::stdRobot(Position position, Direction direction) 
    : currentPosition(position), currentDirection(direction) {}

stdRobot::stdRobot(int xPos, int yPos, Direction direction) 
    : currentPosition{xPos, yPos}, currentDirection(direction) {}

stdRobot::~stdRobot() {}

bool stdRobot::move() { return true; }

void stdRobot::turnLeft() { }

void stdRobot::turnRight() {}

Position stdRobot::reportPosition() {
    return currentPosition;
}

Direction stdRobot::reportDirection() {
    return currentDirection;
}

void stdRobot::pickPlace(Position p, Direction f) {
    currentPosition = p;
    currentDirection = f;
}
