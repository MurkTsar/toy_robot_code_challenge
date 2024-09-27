#include "iRobot.h"

class TestRobot : public iRobot {
public:
    virtual ~TestRobot() = default;

    // Implement the movement commands
    bool move() override { return true; }
    void turnLeft() override {}
    void turnRight() override {}

    // Implement the reports
    Position reportPosition() override { return Position(0, 0); }
    Direction reportDirection() override { return Direction::NORTH; }

    // Implement the changes
    void pickPlace(Position p, Direction f) override {}
};