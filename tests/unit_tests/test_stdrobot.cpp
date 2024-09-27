#include <gtest/gtest.h>
#include "stdRobot.h"

TEST(RobotTest, InitialPosition) {
    stdRobot robot;
    Position pos = robot.reportPosition();
    EXPECT_EQ(pos.x, 0);
    EXPECT_EQ(pos.y, 0);
    EXPECT_EQ(robot.reportDirection(), Direction::NORTH);
    //EXPECT_EQ(0, 0);
}
