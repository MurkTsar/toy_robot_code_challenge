#ifndef STDROBOT_H
#define STDROBOT_H

#include "iRobot.h"
#include "direction.h"
#include "position.h"

/**
 * @class stdRobot
 * @brief Standard implementation of the iRobot interface.
 * 
 * This class represents a standard robot that can move on a tabletop.
 * It contains the robot's position and direction, and provides methods
 * to report its status and handle movements.
 */

class stdRobot : public iRobot {
public:

    /**
     * @brief creates a standard robot, sets position and direction to default 0, 0, NORTH
     */
    stdRobot();
    /**
     * @brief creates a standard robot, sets position and direction
     * @param position the X and Y coordinates using struct Position
     * @param direction where the robot faces, using struc Direction
     */
    stdRobot(Position position, Direction direction);
    /**
     * @brief creates a standard robot, sets position and direction
     * @param xPos the X coordinate position
     * @param yPos  the Y coordinate position
     * @param direction where the robot faces, using struc Direction
     */
    stdRobot(int xPos, int yPos, Direction direction);
    virtual ~stdRobot();

    void move() override;
    void turnLeft() override;
    void turnRight() override;
    Position nextPosition() override;

    /**
     * @brief Reports the robot's current X,Y position.
     * @return struct Position
     */
    Position reportPosition() override;

    /**
     * @brief Reports the robot's current direction.
     * @return struct Direction
     */
    Direction reportDirection() override;

    /**
     * @brief Reports the robot's current position and direction.
     * @return string
     */
    std::string toStringReport() override;

    /**
     * @brief picks robot up and sets the new Position and Direction
     * @param position the X and Y coordinates using struct Position
     * @param direction where the robot faces, using struc Direction
     */
    void pickPlace(Position p, Direction f) override;
private:
    Position currentPosition;
    Direction currentDirection;
};

#endif // STDROBOT_H