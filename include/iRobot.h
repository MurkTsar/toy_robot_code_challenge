#ifndef IROBOT_H
#define IROBOT_H

#include <string>
#include "position.h"
#include "direction.h"

class iRobot {
public:
    virtual ~iRobot() = default;
    
    // Movement commands
    virtual void move() = 0;
    virtual void turnLeft() = 0;
    virtual void turnRight() = 0;

    // Reports
    virtual Position reportPosition() = 0;
    virtual Direction reportDirection() = 0;

    // Changes
    virtual void pickPlace(Position p, Direction f) = 0;
};

#endif // IROBOT_H