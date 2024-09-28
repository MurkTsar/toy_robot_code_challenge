#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>
#include <algorithm>

enum class Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

inline std::string directionToString(Direction direction) {
    switch (direction) {
        case Direction::NORTH:
            return "NORTH";
        case Direction::EAST:
            return "EAST";
        case Direction::SOUTH:
            return "SOUTH";
        case Direction::WEST:
            return "WEST";
        default:
            return "UNKNOWN";
    }
}

inline Direction stringToDirection(const std::string& str) {
    std::string upperStr = str;
    std::transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper); // Make case insensitive

    if (upperStr == "NORTH") {
        return Direction::NORTH;
    } else if (upperStr == "EAST") {
        return Direction::EAST;
    } else if (upperStr == "SOUTH") {
        return Direction::SOUTH;
    } else if (upperStr == "WEST") {
        return Direction::WEST;
    } else {
        return Direction::NORTH;
    }
}

#endif // DIRECTION_H