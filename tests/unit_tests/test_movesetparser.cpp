#include "fixture_testMovesetparser.h"
#include <optional>
#include <list>
#include <string>
#include <fstream>

TEST_F(Test_movesetParser, ParseValidCommandsDefaultPlace) {
    std::string commandString = "PLACE MOVE LEFT RIGHT REPORT";
    std::optional<std::list<std::string>> result = parser.parseCommands(commandString);

    ASSERT_TRUE(result.has_value());
    std::list<std::string> expectedCommands = { "PLACE", "MOVE", "LEFT", "RIGHT", "REPORT" };
    EXPECT_EQ(result.value(), expectedCommands);
}

TEST_F(Test_movesetParser, ParseValidCommands) {
    std::string commandString = "PLACE 0, 1, NORTH MOVE LEFT RIGHT REPORT";
    std::optional<std::list<std::string>> result = parser.parseCommands(commandString);

    ASSERT_TRUE(result.has_value());
    std::list<std::string> expectedCommands = { "PLACE 0, 1, NORTH", "MOVE", "LEFT", "RIGHT", "REPORT" };
    EXPECT_EQ(result.value(), expectedCommands);
}

TEST_F(Test_movesetParser, ParseInvalidCommands) {
    std::string invalidCommandString = "";
    std::optional<std::list<std::string>> result = parser.parseCommands(invalidCommandString);

    EXPECT_FALSE(result.has_value());
}

TEST_F(Test_movesetParser, ParseCommandsFromFile) {
    std::ofstream file("test_commands.txt");
    file << "\nPLACE 1, 1, EAST\nMOVE\nLEFT\nRIGHT\nREPORT\n";
    file.close();

    std::optional<std::list<std::string>> result = parser.parseCommandsFromFile("test_commands.txt");

    ASSERT_TRUE(result.has_value());
    std::list<std::string> expectedCommands = { "PLACE 1, 1, EAST", "MOVE", "LEFT", "RIGHT", "REPORT" };
    EXPECT_EQ(result.value(), expectedCommands);

    std::remove("test_commands.txt");
}

TEST_F(Test_movesetParser, ParseCommandsFromFile_FileNotFound) {
    std::optional<std::list<std::string>> result = parser.parseCommandsFromFile("nonexistent.txt");
    EXPECT_FALSE(result.has_value());
}

TEST_F(Test_movesetParser, ParseCommandsFromFileStream) {
    std::string ss("MOVE\nLEFT\nRIGHT\nPLACE");
    std::optional<std::list<std::string>> result = parser.parseCommandsFromFile(ss);

    ASSERT_TRUE(result.has_value());
    std::list<std::string> expectedCommands = { "MOVE", "LEFT", "RIGHT", "PLACE" };
    EXPECT_EQ(result.value(), expectedCommands);
}

TEST_F(Test_movesetParser, CleanUpRemovesWhitespaceAndInvalidCommands) {
    std::list<std::string> commands = { "LOREMIPSUM", "MOVE", "", "LEFT", "  ", "RIGHT", "INVALID" };
    parser.cleanUp(commands);

    std::list<std::string> expectedCommands = { "MOVE", "LEFT", "RIGHT" };
    EXPECT_EQ(commands, expectedCommands);
}
