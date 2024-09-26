#ifndef COMMANDLINEDISPLAY_H
#define COMMANDLINEDISPLAY_H

#include "position.h"
#include "tabletop.h"
#include "direction.h"
#include <iostream>

/**
 * @class CommandLineDisplay
 * @brief Displays program options, the robot's location, and a graphical representation of the tabletop.
 */
class CommandLineDisplay {
public:
    /**
     * @brief Displays the main program options
     */
    void displayMainMenu() const;

    /**
     * @brief Displays retry options after an action
     */
    void displayRetryMenu() const;

    /**
     * @brief Displays the current location of the robot
     * @param position The current position of the robot on the table
     * @param direction The current direction where the robot is facing
     */
    void displayRobotLocation(const Position& position, const Direction& direction) const;

    /**
     * @brief Displays a graphical representation of the robot's location and direction on the tabletop
     * @param position The current position of the robot
     * @param direction The current direction where the robot is facing
     * @param tableSizeX The width of the tabletop
     * @param tableSizeY The length of the tabletop
     */
    void displayRobotLocationGraphically(const Position& position, const Direction& direction, int tableSizeX, int tableSizeY) const;
};

#endif // COMMANDLINEDISPLAY_H
