#include "movesetparser.h"
#include "gtest/gtest.h"

class Test_movesetParser : public ::testing::Test {
protected:
    MovesetParser parser;

    // Helper function to convert a list of commands to a single string
    std::string listToString(const std::list<std::string>& commands) {
        std::ostringstream oss;
        for (const auto& command : commands) {
            oss << command << " ";
        }
        return oss.str();
    }
};