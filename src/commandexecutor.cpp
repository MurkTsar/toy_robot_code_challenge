#include "commandexecutor.h"
#include "commandlinedisplay.h"
#include "direction.h"
#include <iostream>
#include <regex>

void CommandExecutor::execute(std::list<std::string> commands, TableTop& tabletop) {
    if(commands.empty()){
        LOG_ACTION("Empty command list");
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
            LOG_ACTION("Ignored invalid command: " + command);
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
        
        LOG_ACTION("Robot placed at default position (0,0,NORTH)");
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
                    LOG_ACTION("Robot placed at (" + std::to_string(x) + "," + std::to_string(y) + "," + dir + ")");
                } else {
                    tabletop.selectRobot()->pickPlace(Position(x,y),direction);
                    LOG_ACTION("Robot placed at (" + std::to_string(x) + "," + std::to_string(y) + "," + dir + ")");
                }

            } else {
                LOG_ACTION("Invalid placement: (" + std::to_string(x) + "," + std::to_string(y) + ") is out of bounds");
            }
        } else {
            LOG_ACTION("Invalid PLACE command format: " + command);
        }
    }
}

void CommandExecutor::executeMove(TableTop& tabletop) {
    if(tabletop.isTableEmpty()) {
        LOG_ACTION("Invalid MOVE command: No robot on table");
        return;
    }

    Position nextPosition = tabletop.selectRobot()->nextPosition();

    if (tabletop.isValidPosition(nextPosition.x, nextPosition.y)) {
        tabletop.selectRobot()->move();
        LOG_ACTION("Robot moved to (" + std::to_string(nextPosition.x) + "," + std::to_string(nextPosition.y) + ")");
    } else {
        LOG_ACTION("Invalid MOVE command: Moving out of bounds");
    }
}

void CommandExecutor::executeTurnRight(TableTop& tabletop) {
    if(tabletop.isTableEmpty()){
        LOG_ACTION("Invalid RIGHT command: No robot on table");
        return;
    }

    tabletop.selectRobot()->turnRight();
    LOG_ACTION("Robot turned right");
}

void CommandExecutor::executeTurnLeft(TableTop& tabletop) {
    if(tabletop.isTableEmpty()){
        LOG_ACTION("Invalid LEFT command: No robot on table");
        return;
    }

    tabletop.selectRobot()->turnLeft();
    LOG_ACTION("Robot turned left");
}

void CommandExecutor::executeReport(TableTop& tabletop) {
    if(tabletop.isTableEmpty()){
        LOG_ACTION("Invalid REPORT command: No robot on table");
        return;
    }

    std::string report = tabletop.selectRobot()->toStringReport();

    std::cout << report << std::endl;
    LOG_ACTION("Robot sent a report " + report);
}