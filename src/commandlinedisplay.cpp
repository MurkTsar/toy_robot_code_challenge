#include "commandlinedisplay.h"

// Constants for menu options
constexpr const char* mainMenuOptions = 
    "Program Options: \n"
    "1 - IMPORT FILE\n"
    "2 - INPUT ROBOT ACTIONS\n"
    "3 - CLOSE PROGRAM\n"
    "Enter your choice: ";

constexpr const char* retryMenuOptions = 
    "Options: \n"
    "1 - TRY AGAIN\n"
    "2 - CLOSE PROGRAM\n"
    "Enter your choice: ";

void CommandLineDisplay::displayMainMenu() {
    std::cout << mainMenuOptions;
}

void CommandLineDisplay::displayRetryMenu() {
    std::cout << retryMenuOptions;
}

void CommandLineDisplay::displayRobotLocation(const Position& position, const Direction& direction) {
    std::cout << "Current Robot Location: ";
}

void CommandLineDisplay::displayRobotLocationGraphically(const Position& position, const Direction& direction, int tableSizeX, int tableSizeY) {
    char robotChar;
    switch (direction) {
        case Direction::NORTH:
            robotChar = '^';
            break;
        case Direction::EAST:
            robotChar = '>';
            break;
        case Direction::SOUTH:
            robotChar = 'v';
            break;
        case Direction::WEST:
            robotChar = '<';
            break;
        default:
            robotChar = '?';
            break;
    }

    for (int y = tableSizeY - 1; y >= 0; --y) {
        // Draw the top part of the row (underscores)
        for (int x = 0; x < tableSizeX; ++x) {
            std::cout << " ---";  // Add three underscores for better alignment
        }
        std::cout << '\n';

        // Draw the vertical bars and spaces, inserting the robot in the correct position
        for (int x = 0; x < tableSizeX; ++x) {
            if (x == position.x && y == position.y) {
                // Place the robot character in the correct cell
                std::cout << "| " << robotChar << " ";
            } else {
                std::cout << "|   "; // Empty cell with padding for alignment
            }
        }
        std::cout << "|\n"; // Close the row with a final vertical bar
    }

    // Draw the bottom part of the final row (underscores)
    for (int x = 0; x < tableSizeX; ++x) {
        std::cout << " ---";  // Add underscores for the bottom border
    }
    std::cout << '\n';
}
