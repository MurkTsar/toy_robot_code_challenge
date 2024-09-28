#ifndef MOVESETPARSER_H
#define MOVESETPARSER_H

#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <optional>
#include <fstream>
#include <cctype>
#include <regex>

/**
 * @class MovesetParser
 * @brief Parses movement commands for the robot, from either a string or a file.
 */
class MovesetParser {
public:
    MovesetParser();
    ~MovesetParser();

    /**
     * @brief Parse a string of commands and return a list of commands
     * @param command A string containing commands
     * @return Parsed list of commands or nullopt if parsing fails
     */
    std::optional<std::list<std::string>> parseCommands(const std::string& command);
    
    /**
     * @brief Parse commands from a text file and return a list of commands
     * @param filePath The path to the .txt file containing commands
     * @return std::optional<std::list<std::string>> Parsed list of commands or nullopt if parsing fails
     */
    std::optional<std::list<std::string>> parseCommandsFromFile(const std::string& filePath);

    /**
     * @brief Parse commands directly from a file stream
     * @param file An open std::ifstream object representing the file
     * @return std::optional<std::list<std::string>> Parsed list of commands or nullopt if parsing fails
     */
    std::optional<std::list<std::string>> parseCommandsFromFile(std::ifstream& file);

    /**
     * @brief Cleans up the list of commands, removing invalid entries or whitespace
     * @param commands List of commands to clean up
     */
    void cleanUp(std::list<std::string>& commands);

private:
    void cleanUpWhitespace(std::string& str);
    void makeCaseInsensitive(std::string& str);
    bool isValidCommand(const std::string& command);
    bool isValidPlaceCommand(const std::string& command);
};

#endif // MOVESETPARSER_H