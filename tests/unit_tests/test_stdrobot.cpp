#include <gtest/gtest.h>
#include "stdRobot.h"

stdRobot robot;

TEST(Test_stdRobot, DefaultPosition) {
    Position pos = robot.reportPosition();

    EXPECT_EQ(pos.x, 0);
    EXPECT_EQ(pos.y, 0);
    EXPECT_EQ(robot.reportDirection(), Direction::NORTH);
}

TEST(Test_stdRobot, pick_up_robot_place_new_location) {
    int x = 10, y = 3;
    Direction newFace = Direction::SOUTH;
    robot.pickPlace(Position(x,y), newFace);
    Position pos = robot.reportPosition();

    EXPECT_EQ(pos.x, x);
    EXPECT_EQ(pos.y, y);
    EXPECT_EQ(robot.reportDirection(), newFace);
}

TEST(Test_stdRobot, Move_positive_Y_twice) {
    int y = 2;
    robot.pickPlace(Position(2,y), Direction::NORTH);
    robot.move();
    robot.move();
    Position pos = robot.reportPosition();

    EXPECT_EQ(pos.y, y+2);
}

TEST(Test_stdRobot, Move_positive_X_twice) {
    int x = 1;
    robot.pickPlace(Position(x,3), Direction::EAST);
    robot.move();
    robot.move();
    Position pos = robot.reportPosition();

    EXPECT_EQ(pos.x, x+2);
}

TEST(Test_stdRobot, Move_negative_Y_twice) {
    int y = 3;
    robot.pickPlace(Position(2,y), Direction::SOUTH);
    robot.move();
    robot.move();
    Position pos = robot.reportPosition();

    EXPECT_EQ(pos.y, y-2);
}

TEST(Test_stdRobot, Move_negativee_X_twice) {
    int x = 3;
    robot.pickPlace(Position(x,3), Direction::WEST);
    robot.move();
    robot.move();
    Position pos = robot.reportPosition();

    EXPECT_EQ(pos.x, x-2);
}

TEST(Test_stdRobot, turnRight) {
    robot.pickPlace(Position(2,2), Direction::SOUTH);
    robot.turnRight();

    EXPECT_EQ(robot.reportDirection(), Direction::WEST);
}

TEST(Test_stdRobot, turnLeft) {
    robot.pickPlace(Position(2,2), Direction::SOUTH);
    robot.turnLeft();

    EXPECT_EQ(robot.reportDirection(), Direction::EAST);
}

TEST(Test_stdRobot, turnRight_180) {
    robot.pickPlace(Position(2,2), Direction::SOUTH);
    robot.turnRight();
    robot.turnRight();

    EXPECT_EQ(robot.reportDirection(), Direction::NORTH);
}

TEST(Test_stdRobot, turnLeft_180) {
    robot.pickPlace(Position(2,2), Direction::SOUTH);
    robot.turnLeft();
    robot.turnLeft();

    EXPECT_EQ(robot.reportDirection(), Direction::NORTH);
}

TEST(Test_stdRobot, turnRight_360) {
    robot.pickPlace(Position(2,2), Direction::SOUTH);
    robot.turnRight();
    robot.turnRight();
    robot.turnRight();
    robot.turnRight();

    EXPECT_EQ(robot.reportDirection(), Direction::SOUTH);
}

TEST(Test_stdRobot, turnLeft_360) {
    robot.pickPlace(Position(2,2), Direction::NORTH);
    robot.turnLeft();
    robot.turnLeft();
    robot.turnLeft();
    robot.turnLeft();

    EXPECT_EQ(robot.reportDirection(), Direction::NORTH);
}

TEST(Test_stdRobot, toStringReport) {
    robot.pickPlace(Position(2,2), Direction::NORTH);
    robot.turnLeft();
    robot.move();

    EXPECT_EQ(robot.toStringReport(), "output: 1, 2, WEST");
}