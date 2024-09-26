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

void CommandLineDisplay::displayMainMenu() const {
    std::cout << mainMenuOptions;
}

void CommandLineDisplay::displayRetryMenu() const {
    std::cout << retryMenuOptions;
}

void CommandLineDisplay::displayRobotLocation(const Position& position, const Direction& direction) const {
    std::cout << "Current Robot Location: ";
}

void CommandLineDisplay::displayRobotLocationGraphically(const Position& position, const Direction& direction, int tableSizeX, int tableSizeY) const {
    // @todo display table
}
