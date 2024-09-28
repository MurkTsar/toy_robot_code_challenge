#include "iRobot.h"

class TestRobot : public iRobot {
public:
    virtual ~TestRobot() = default;

    void move() override {}
    void turnLeft() override {}
    void turnRight() override {}

    Position reportPosition() override { return Position(0, 0); }
    Direction reportDirection() override { return Direction::NORTH; }

    void pickPlace(Position p, Direction f) override {}
};