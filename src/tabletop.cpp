#include "tabletop.h"
#include <iostream>

TableTop::TableTop(int width, int length, unsigned int popCap)
    : width(width), length(length), popCap(popCap) { }

bool TableTop::placeRobot(std::unique_ptr<iRobot> robot) { 
    if(!isTableEmpty()) {
        return false;
    }

    robotOnTheTable = std::move(robot);

    return true; 
}

bool TableTop::isValidPosition(int x, int y) const {
    return (x < width && y < length) && (x >= 0 && y >= 0);
}

bool TableTop::isValidPosition(Position position) const {
    return position < Position(width, length) && position >= Position(0, 0);
}

bool TableTop::isTableEmpty() const { return robotOnTheTable == nullptr; }

iRobot* TableTop::selectRobot() { return robotOnTheTable.get(); }

bool TableTop::removeRobot() {
    if (!this->isTableEmpty()) {
        robotOnTheTable.reset();
        return true;
    }
    return false;
}