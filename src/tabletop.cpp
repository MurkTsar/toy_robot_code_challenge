#include "./include/tabletop.h"
#include <iostream>

TableTop::TableTop(int width, int length, unsigned int popCap)
    : width(width), length(length), popCap(popCap) { }

TableTop::~TableTop() { }

bool TableTop::placeRobot(std::unique_ptr<iRobot> robot) { return true; }

bool TableTop::isValidPosition(int x, int y) { return false; }

bool TableTop::isValidPosition(Position position) { return false; }

bool TableTop::isTableFull() { return false; }

bool TableTop::removeRobot(std::unique_ptr<iRobot> robot) { return false; }

bool TableTop::removeRobotAt(Position position) { return false; }

bool TableTop::clearTableTop(){ return true; };
