#include "iRobot.h"

class TestRobot : public iRobot {
public:
    virtual ~TestRobot() = default;

    void move() override {}
    void turnLeft() override {}
    void turnRight() override {}
    Position nextPosition() override { return Position(0,0); }

    Position reportPosition() override { return Position(0, 0); }
    Direction reportDirection() override { return Direction::NORTH; }
    std::string toStringReport() override { return "output: 0, 0, NORTH";}

    void pickPlace(Position p, Direction f) override {}
};