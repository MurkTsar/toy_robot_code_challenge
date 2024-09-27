#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H

#include <list>
#include <string>
//#include <memory>

/**
 * @class CommandExecutor
 * @brief This is the core of the whole program
 *
 * This class executes the parsed commands and sets the table,
 * robots, and the movement of the robot
 */

class CommandExecutor {
public:
    void execute(std::list<std::string> commands);
};

#endif // COMMANDEXECUTOR_H