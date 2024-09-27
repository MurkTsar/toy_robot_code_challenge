#include "tabletop.h"
#include <iostream>

TableTop::TableTop(int width, int length, unsigned int popCap)
    : width(width), length(length), popCap(popCap) { }

bool TableTop::placeRobot(std::unique_ptr<iRobot> robot) { return true; }

bool TableTop::isValidPosition(int x, int y) const { return false; }

bool TableTop::isValidPosition(Position position) const { return false; }

bool TableTop::isTableFull() const { return false; }

bool TableTop::isTableEmpty() const { return false; }

iRobot* TableTop::selectRobot() { return nullptr; }

iRobot* TableTop::selectRobotAt(Position position) { return nullptr; }

bool TableTop::removeRobot(const iRobot &robot) { return false; }

bool TableTop::removeRobotAt(Position position) { return false; }

bool TableTop::clearTableTop(){ return true; };
