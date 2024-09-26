#include "movesetparser.h"

MovesetParser::MovesetParser() {}

MovesetParser::~MovesetParser() {}

std::optional<std::list<std::string>> MovesetParser::parseCommands(const std::string& command) {
    std::list<std::string> commandList;

    return commandList;
}

std::optional<std::list<std::string>> MovesetParser::parseCommandsFromFile(const std::string& filePath) {
    std::list<std::string> commandList;

    if (commandList.empty()) {
        return std::nullopt;
    }

    return commandList;
}

std::optional<std::list<std::string>> MovesetParser::parseCommandsFromFile(std::ifstream& file) {
    std::list<std::string> commandList;

    if (commandList.empty()) {
        return std::nullopt;
    }

    return commandList;
}

void MovesetParser::cleanUp(std::list<std::string>& commands) { }
