#include "gtest/gtest.h"
#include "fixture_testCommandexecutor.h"

TEST_F(Test_CommandExecutor, ExecutesCommandsWithoutErrors) {
    ASSERT_NO_THROW(executor.execute(commands));
}

TEST_F(Test_CommandExecutor, ExecutesEmptyCommandList) {
    std::list<std::string> emptyCommands;
    ASSERT_NO_THROW(executor.execute(emptyCommands));
}