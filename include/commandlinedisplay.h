#ifndef COMMANDLINEDISPLAY_H
#define COMMANDLINEDISPLAY_H

#include "position.h"
#include "tabletop.h"
#include "direction.h"
#include <iostream>
#include <string>
#include <list>

/**
 * @class CommandLineDisplay
 * @brief Displays program options, the robot's location, and a graphical representation of the tabletop.
 */
class CommandLineDisplay {
public:
    /**
     * @brief Displays the main program options
     */
    static void displayMainMenu();

    /**
     * @brief Displays retry options after an action
     */
    static void displayRetryMenu();

    /**
     * @brief welcomes the use on the console screen
     */
    static void displayWelcome();

    /**
     * @brief prompts a goodbye on the console screen
     */
    static void displayGoodbye();

    /**
     * @brief displays set of moves console screen
     * @param moves a list of strings
     */
    static void displayMoveset(const std::list<std::string>& moves);

    /**
     * @brief Clears the console screen
     */
    static void clearScreen();

    /**
     * @brief Displays a graphical representation of the robot's location and direction on the tabletop
     * @param position The current position of the robot
     * @param direction The current direction where the robot is facing
     * @param tableSizeX The width of the tabletop
     * @param tableSizeY The length of the tabletop
     */
    static void displayRobotLocationGraphically(const Position& position, const Direction& direction, int tableSizeX, int tableSizeY);
};

#endif // COMMANDLINEDISPLAY_H
