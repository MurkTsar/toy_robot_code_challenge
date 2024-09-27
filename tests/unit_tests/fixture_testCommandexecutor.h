#include "commandexecutor.h"
#include "fixture_testTable.h"
#include "fixture_testRobot.h"

class Test_CommandExecutor : public ::testing::Test {
protected:
    CommandExecutor executor;
    std::list<std::string> commands;

    void SetUp() override {
        commands.push_back("PLACE 0,0,NORTH");
        commands.push_back("MOVE");
        commands.push_back("LEFT");
        commands.push_back("REPORT");
    }

    void TearDown() override {
        commands.clear();
    }
};