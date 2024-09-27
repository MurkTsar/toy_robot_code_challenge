#ifndef TABLETOP_H
#define TABLETOP_H

#include "position.h"
#include "iRobot.h"
#include <list>
#include <memory>

/**
 * @class TableTop
 * @brief Represents a tabletop on which robots can be placed and moved
 *
 * The TableTop class defines a rectangular surface where multiple robots can be placed,
 * restricted by a population capacity (popCap). It validates robot positions to prevent 
 * placement or movement beyond the boundaries of the tabletop.
 */
class TableTop {
public:
    /**
     * @brief Construct a new TableTop object with default population cap
     * @param width Width of the tabletop
     * @param length Length of the tabletop
     * @param popCap Maximum number of robots that can be placed (default is 1)
     */
    TableTop(int width, int length, unsigned int popCap = 1);
    
    ~TableTop() = default;

    /**
     * @brief Places a robot on the tabletop if population cap allows
     * @param robot A unique pointer to an iRobot object to place
     * @return true if the robot was placed successfully
     * @return false if the robot couldn't be placed (e.g., over popCap)
     */
    bool placeRobot(std::unique_ptr<iRobot> robot);

    /**
     * @brief Selects the only robot on the table
     * @return Pointer to iRobot if the robot exists on the table
     * @return nullptr if there is no robot on the table
     */
    iRobot* selectRobot();

    /**
     * @brief Selects a robot at a specific position on the tabletop
     * @param position The position where the robot is located
     * @return Pointer to the robot if one exists at the given position
     * @return nullptr if no robot is found at the given position
     */
    iRobot* selectRobotAt(Position position);

    /**
     * @brief Provides read-only access to the list of all robots on the tabletop
     * @return A const reference to the list of unique pointers to robots
     */
    const std::list<std::unique_ptr<iRobot>>& provideListOfRobots() const {
        return robots;
    }

    /**
     * @brief Removes a robot from the tabletop
     * @param robot A reference to the iRobot object to remove
     * @return true if the robot was successfully removed
     * @return false if the robot does not exist
     */
    bool removeRobot(const iRobot& robot);

    /**
     * @brief Removes a robot at a specific position
     * @param position The position where the robot is located
     * @return true if the robot was successfully removed
     * @return false if no robot is found at the given position
     */
    bool removeRobotAt(Position position);

    /**
     * @brief Removes all robots from the tabletop
     * @return true if all robots were successfully removed
     * @return false if no robots were on the table
     */
    bool clearTableTop();

    /**
     * @brief Checks if a specific position is valid on the tabletop
     * @param x X coordinate of the position
     * @param y Y coordinate of the position
     * @return true if valid, false otherwise
     */
    bool isValidPosition(int x, int y) const;

    /**
     * @brief Checks if a given position is valid on the tabletop
     * @param position Position object to check
     * @return true if valid, false otherwise
     */
    bool isValidPosition(Position position) const;

    /**
     * @brief Checks if the tabletop is at full capacity
     * @return true if the tabletop is full, false otherwise
     */
    bool isTableFull() const;

    /**
     * @brief Checks if the tabletop is empty
     * @return true if the tabletop is empty, false otherwise
     */
    bool isTableEmpty() const;

private:
    int width;                               // Width of the tabletop
    int length;                              // Length of the tabletop
    unsigned int popCap;                     // Population capacity for robots
    std::list<std::unique_ptr<iRobot>> robots; // List to hold unique pointers to robot objects
};

#endif // TABLETOP_H