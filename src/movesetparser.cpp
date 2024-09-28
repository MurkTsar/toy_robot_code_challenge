#include "movesetparser.h"

MovesetParser::MovesetParser() {}

MovesetParser::~MovesetParser() {}

std::optional<std::list<std::string>> MovesetParser::parseCommands(const std::string& command) {
    std::list<std::string> commandList;
    std::stringstream ss(command);
    std::string line;

    while (std::getline(ss, line, '\n')) {
        commandList.push_back(line);
    }

    cleanUp(commandList); // Clean up the commands (remove spaces, invalid commands, etc.)

    return commandList.empty() ? std::nullopt : std::make_optional(commandList);
}

std::optional<std::list<std::string>> MovesetParser::parseCommandsFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        return std::nullopt;
    }
    return parseCommandsFromFile(file);
}

std::optional<std::list<std::string>> MovesetParser::parseCommandsFromFile(std::ifstream& file) {
    std::list<std::string> commandList;
    std::string line;

    while (std::getline(file, line)) {
        commandList.push_back(line);
    }

    cleanUp(commandList);

    return commandList.empty() ? std::nullopt : std::make_optional(commandList);
}

void MovesetParser::cleanUp(std::list<std::string>& commands) {
    for (auto it = commands.begin(); it != commands.end(); ) {
        cleanUpWhitespace(*it);
        makeCaseInsensitive(*it);
        if (!isValidCommand(*it)) {
            it = commands.erase(it);
        } else {
            ++it;
        }
    }
}

void MovesetParser::cleanUpWhitespace(std::string& str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), str.end());
}

void MovesetParser::makeCaseInsensitive(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char ch) {
        return std::toupper(ch);
    });
}

bool MovesetParser::isValidCommand(const std::string& command) {
    if (command.find("PLACE") == 0) {
        return isValidPlaceCommand(command);
    }
    return (command == "MOVE" || command == "LEFT" || command == "RIGHT" || command == "REPORT");
}

bool MovesetParser::isValidPlaceCommand(const std::string& command) {
    std::regex placeRegex(R"(^PLACE\s*(\d+)\s*,\s*(\d+)\s*,\s*(NORTH|EAST|SOUTH|WEST)?$|^PLACE$)");

    return std::regex_match(command, placeRegex);
}