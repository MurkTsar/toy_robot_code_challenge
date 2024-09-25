#include "stdRobot.h"

stdRobot::stdRobot() {}

stdRobot::stdRobot(Position p, Direction f) {}
stdRobot::~stdRobot() {}

bool stdRobot::move() { return false; }
void stdRobot::turnLeft() {}
void stdRobot::turnRight() {}

Position reportPosition() { return Position(0, 0); }
Direction reportDirection() { return Direction::NORTH; }
void pickPlace(Position p, Direction f) {}