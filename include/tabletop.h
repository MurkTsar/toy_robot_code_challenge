#ifndef TABLETOP_H
#define TABLETOP_H

#include "position.h"
#include "iRobot.h"
#include <list>
#include <memory>

/**
 * @class TableTop
 * @brief Represents a tabletop on which robots can be placed and moved.
 *
 * The TableTop class defines a rectangular surface where multiple robots can be placed,
 * restricted by a population capacity (popCap). It validates robot positions to prevent 
 * placement or movement beyond the boundaries of the tabletop. Additionally, it supports
 * future extensibility by allowing different types of robots that implement the iRobot interface.
 */

class TableTop {
public:
    /**
     * @brief Construct a new TableTop object with default population cap
     * @param width Width of the tabletop
     * @param length Length of the tabletop
     */
    TableTop(int width, int length, unsigned int popCap = 1);  // popCap defaults to 1
    
    ~TableTop();

    /**
     * @brief Places a robot on the tabletop if population cap allows
     * @param robot A pointer to an iRobot object
     * @return true if the robot was placed successfully
     * @return false if the robot couldn't be placed (e.g., over popCap)
     */
    bool placeRobot(std::unique_ptr<iRobot> robot);

    /**
     * @todo UNIMPLEMENTED - This is a nice to have feature
     * @brief removes a robot on the tabletop
     * @param robot A pointer to an iRobot object
     * @return true if the robot was removed successfully
     * @return false if the robot does not exist
     */
    bool removeRobot(std::unique_ptr<iRobot> robot);

    /**
     * @todo UNIMPLEMENTED - This is a nice to have feature
     * @brief removes a robot on the tabletop at a position
     * @param position where the robot stands
     * @return true if the robot was removed successfully
     * @return false if the robot does not exist or removal failed
     */
    bool removeRobotAt(Position position);

    /**
     * @brief removes all robots on the tabletop
     * @return true if all robots were removed successfully
     * @return false if no robot exists
     */
    bool clearTableTop();

    /**
     * @brief Checks if a specific position is valid on the tabletop
     * @param x X coordinate of the position
     * @param y Y coordinate of the position
     * @return true if valid
     */
    bool isValidPosition(int x, int y);

    /**
     * @brief Checks if a given position is valid on the tabletop
     * @param position Position object to check
     * @return true if valid
     */
    bool isValidPosition(Position position);

    /**
     * @brief Checks if tabletop is at full capacity
     * @return true if full
     */
    bool isTableFull();

private:
    int width, length;                        // Dimensions of the tabletop
    unsigned int popCap;                      // Population capacity of robots
    std::list<std::unique_ptr<iRobot>> robots; // List to hold robot pointers
};

#endif // TABLETOP_H
