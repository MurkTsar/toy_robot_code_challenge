#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H

#include "tabletop.h"
#include "logger.h"
#include "stdRobot.h"

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
    void CommandExecutor::execute(std::list<std::string> commands, TableTop& tabletop);
    void CommandExecutor::executePlace(const std::string& command, TableTop& tabletop);
    void CommandExecutor::executeMove(TableTop& tabletop);
    void CommandExecutor::executeTurnRight(TableTop& tabletop);
    void CommandExecutor::executeTurnLeft(TableTop& tabletop);
    void CommandExecutor::executeReport(TableTop& tabletop);
};

#endif // COMMANDEXECUTOR_H