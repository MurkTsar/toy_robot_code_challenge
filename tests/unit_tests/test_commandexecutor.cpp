#include "gtest/gtest.h"
#include "fixture_testCommandexecutor.h"

TEST_F(Test_CommandExecutor, ExecutesCommandsWithoutErrors) {
    std::list<std::string> commands = {"PLACE 0,0,NORTH", "MOVE", "REPORT"};
    ASSERT_NO_THROW(executor.execute(commands, *tabletop));
}

TEST_F(Test_CommandExecutor, ExecutesEmptyCommandList) {
    std::list<std::string> emptyCommands;
    ASSERT_NO_THROW(executor.execute(emptyCommands, *tabletop));
}

TEST_F(Test_CommandExecutor, PlacesRobotAtDefaultPosition) {
    std::list<std::string> commands = {"PLACE"};
    ASSERT_NO_THROW(executor.execute(commands, *tabletop));

    ASSERT_TRUE(tabletop->selectRobot()->reportPosition() == Position(0, 0));
    ASSERT_EQ(tabletop->selectRobot()->reportDirection(), Direction::NORTH);
}

TEST_F(Test_CommandExecutor, PlacesRobotAtGivenPosition) {
    std::list<std::string> commands = {"PLACE 2,2,NORTH", "REPORT"};
    ASSERT_NO_THROW(executor.execute(commands, *tabletop));
    ASSERT_TRUE(tabletop->selectRobot()->reportPosition() == Position(2, 2));
    ASSERT_EQ(tabletop->selectRobot()->reportDirection(), Direction::NORTH);
}

TEST_F(Test_CommandExecutor, IgnoresInvalidCommands) {
    std::list<std::string> commands = {"PLACE 2,2,NORTH", "INVALID_COMMAND", "REPORT"};
    ASSERT_NO_THROW(executor.execute(commands, *tabletop));
    ASSERT_TRUE(tabletop->selectRobot()->reportPosition() == Position(2, 2));
}

TEST_F(Test_CommandExecutor, MovesRobot) {
    std::list<std::string> commands = {"PLACE 0,0,NORTH", "MOVE", "REPORT"};
    executor.execute(commands, *tabletop);
    ASSERT_TRUE(tabletop->selectRobot()->reportPosition() == Position(0, 1));
}

TEST_F(Test_CommandExecutor, IgnoresMoveOutOfBounds) {
    std::list<std::string> commands = {"PLACE 0,4,NORTH", "MOVE"};
    executor.execute(commands, *tabletop);

    ASSERT_TRUE(tabletop->selectRobot()->reportPosition() == Position(0, 4));
    ASSERT_TRUE(tabletop->selectRobot()->reportDirection() == Direction::NORTH);
}

TEST_F(Test_CommandExecutor, IgnoresMoveOutOfBoundsSouthBound) {
    std::list<std::string> commands = {"PLACE 0,0,SOUTH", "MOVE"};
    executor.execute(commands, *tabletop);

    ASSERT_TRUE(tabletop->selectRobot()->reportPosition() == Position(0, 0));
    ASSERT_TRUE(tabletop->selectRobot()->reportDirection() == Direction::SOUTH);
}

TEST_F(Test_CommandExecutor, TurnsRobotLeftAndRight) {
    std::list<std::string> commands = {"PLACE 0,0,NORTH", "LEFT"};
    executor.execute(commands, *tabletop);
    ASSERT_EQ(tabletop->selectRobot()->reportDirection(), Direction::WEST);

    commands = {"PLACE 0,0,NORTH", "RIGHT"};
    executor.execute(commands, *tabletop);
    ASSERT_EQ(tabletop->selectRobot()->reportDirection(), Direction::EAST);
}