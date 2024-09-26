#ifndef ROBOTINPUTLISTENER_H
#define ROBOTINPUTLISTENER_H

#include <iostream>
#include <string>

/**
 * @class RobotInputListener
 * @brief Listens for user input and returns the whole command as a string
 * 
 * The listener captures all inputs including whitespace and newline
 * Listening stops when either ';' or '~' is pressed
 */
class RobotInputListener {
public:
    /**
     * @brief Listens to user input and stops when ';' or '~' is encountered
     * @return std::string The entire user input string excluding the termination character
     */
    std::string listenRobotCommands();
};

#endif // ROBOTINPUTLISTENER_H
