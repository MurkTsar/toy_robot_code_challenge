#include "commandexecutor.h"
#include "commandlinedisplay.h"
#include "direction.h"
#include <iostream>
#include <regex>

void CommandExecutor::execute(std::list<std::string> commands, TableTop& tabletop) {
    if(commands.empty()){
        Logger::getInstance().log(__FUNCTION__, "Empty command list");
        return;
    }
    
    for (const auto& command : commands) {
        if (command == "MOVE") {
            executeMove(tabletop);
        } else if (command == "LEFT") {
            executeTurnLeft(tabletop);
        } else if (command == "RIGHT") {
            executeTurnRight(tabletop);
        } else if (command.rfind("PLACE", 0) == 0) {
            executePlace(command, tabletop);
        } else if (command == "REPORT") {
            executeReport(tabletop);
        } else {
            Logger::getInstance().log(__FUNCTION__, "Ignored invalid command: " + command);
        }
    }

    CommandLineDisplay::displayRobotLocationGraphically(tabletop.selectRobot()->reportPosition(), tabletop.selectRobot()->reportDirection(), tabletop.tableWidth(), tabletop.tableLength());
}

void CommandExecutor::executePlace(const std::string& command, TableTop& tabletop) {
    if (command == "PLACE") {
        if(tabletop.isTableEmpty()){
            std::unique_ptr<stdRobot> newRobot = std::make_unique<stdRobot>();
            tabletop.placeRobot(std::move(newRobot));
        } else {
            tabletop.selectRobot()->pickPlace(Position(0,0),Direction::NORTH);
        }
        
        Logger::getInstance().log(__FUNCTION__, "Robot placed at default position (0,0,NORTH)");
    } else {
        std::smatch match;
        std::regex placeRegex(R"(^PLACE\s*(-?\d+)\s*,\s*(-?\d+)\s*,\s*(NORTH|EAST|SOUTH|WEST)$)");

        if (std::regex_match(command, match, placeRegex)) {
            int x = std::stoi(match[1]);
            int y = std::stoi(match[2]);
            std::string dir = match[3];

            Direction direction = stringToDirection(dir);

            if (tabletop.isValidPosition(x, y)) {
                if(tabletop.isTableEmpty()){
                    std::unique_ptr<stdRobot> newRobot = std::make_unique<stdRobot>(x, y, direction);
                    tabletop.placeRobot(std::move(newRobot));
                    Logger::getInstance().log(__FUNCTION__, "Robot placed at (" + std::to_string(x) + "," + std::to_string(y) + "," + dir + ")");
                } else {
                    tabletop.selectRobot()->pickPlace(Position(x,y),direction);
                    Logger::getInstance().log(__FUNCTION__, "Robot placed at (" + std::to_string(x) + "," + std::to_string(y) + "," + dir + ")");
                }

            } else {
                Logger::getInstance().log(__FUNCTION__, "Invalid placement: (" + std::to_string(x) + "," + std::to_string(y) + ") is out of bounds");
            }
        } else {
            Logger::getInstance().log(__FUNCTION__, "Invalid PLACE command format: " + command);
        }
    }
}

void CommandExecutor::executeMove(TableTop& tabletop) {
    if(tabletop.isTableEmpty()) {
        Logger::getInstance().log(__FUNCTION__, "Invalid MOVE command: No robot on table");
        return;
    }

    Position nextPosition = tabletop.selectRobot()->nextPosition();

    if (tabletop.isValidPosition(nextPosition.x, nextPosition.y)) {
        tabletop.selectRobot()->move();
        Logger::getInstance().log(__FUNCTION__, "Robot moved to (" + std::to_string(nextPosition.x) + "," + std::to_string(nextPosition.y) + ")");
    } else {
        Logger::getInstance().log(__FUNCTION__, "Invalid MOVE command: Moving out of bounds");
    }
}

void CommandExecutor::executeTurnRight(TableTop& tabletop) {
    if(tabletop.isTableEmpty()){
        Logger::getInstance().log(__FUNCTION__, "Invalid RIGHT command: No robot on table");
        return;
    }

    tabletop.selectRobot()->turnRight();
    Logger::getInstance().log(__FUNCTION__, "Robot turned right");
}

void CommandExecutor::executeTurnLeft(TableTop& tabletop) {
    if(tabletop.isTableEmpty()){
        Logger::getInstance().log(__FUNCTION__, "Invalid LEFT command: No robot on table");
        return;
    }

    tabletop.selectRobot()->turnLeft();
    Logger::getInstance().log(__FUNCTION__, "Robot turned left");
}

void CommandExecutor::executeReport(TableTop& tabletop) {
    if(tabletop.isTableEmpty()){
        Logger::getInstance().log(__FUNCTION__, "Invalid REPORT command: No robot on table");
        return;
    }

    std::string report = tabletop.selectRobot()->toStringReport();

    std::cout << report << std::endl;
    Logger::getInstance().log(__FUNCTION__, "Robot sent a report " + report);
}