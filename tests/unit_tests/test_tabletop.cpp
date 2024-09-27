#include <gtest/gtest.h>
#include "tabletop.h"
#include "stdRobot.h"
#include "fixture_testRobot.h"

#define SIZE 5
#define VALID_COOR 2
#define INVALID_NEGATIVE -2
#define INVALID_OOB 7       //invalid out of bounds

TableTop squareTable = TableTop(SIZE,SIZE);
std::unique_ptr<iRobot> robot_1 = std::make_unique<TestRobot>();
std::unique_ptr<iRobot> robot_2 = std::make_unique<TestRobot>();

TEST(Test_tabletop, validPosition) {
    EXPECT_TRUE(squareTable.isValidPosition(VALID_COOR,VALID_COOR));
}

TEST(Test_tabletop, invalidPosition_outOfBoundsY) {
    EXPECT_FALSE(squareTable.isValidPosition(VALID_COOR,INVALID_OOB));
}

TEST(Test_tabletop, invalidPosition_outOfBoundsX) {
    EXPECT_FALSE(squareTable.isValidPosition(INVALID_OOB,VALID_COOR));
}

TEST(Test_tabletop, invalidPosition_outOfBoundsNegativeY) {
    EXPECT_FALSE(squareTable.isValidPosition(VALID_COOR,INVALID_NEGATIVE));
}

TEST(Test_tabletop, invalidPosition_outOfBoundsNegativeX) {
    EXPECT_FALSE(squareTable.isValidPosition(INVALID_NEGATIVE,VALID_COOR));
}

TEST(Test_tabletop, selectRobotNoRobot) {
    ASSERT_EQ(squareTable.selectRobot(), nullptr);
}

TEST(Test_tabletop, isTableFull_tableNotFull) {
    EXPECT_FALSE(squareTable.isTableFull());
}

TEST(Test_tabletop, placeRobotSuccess) {
    squareTable.placeRobot(std::move(robot_1));

    EXPECT_FALSE(squareTable.isTableEmpty());
    EXPECT_TRUE(squareTable.isTableFull());
}

TEST(Test_tabletop, placeRobotFail) {
    EXPECT_TRUE(squareTable.isTableFull());
    EXPECT_FALSE(squareTable.placeRobot(std::move(robot_2)));
}

TEST(Test_tabletop, selectRobotOneRobot) {
    ASSERT_NE(squareTable.selectRobot(), nullptr);
}

TEST(Test_tabletop, clearTableTop) {
    ASSERT_TRUE(squareTable.clearTableTop());
    EXPECT_TRUE(squareTable.isTableEmpty());
    ASSERT_EQ(squareTable.selectRobot(), nullptr);
}