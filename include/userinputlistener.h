#ifndef USERINPUTLISTENER_H
#define USERINPUTLISTENER_H

#include <iostream>

/**
 * @class UserInputListener
 * @brief Listens for user input to control the flow of the ToyRobot program
 *
 * This class listens to user input twice:
 * 1. The first listen waits for input from 1 to 3, representing the options to import a file,
 *    input robot actions, or close the program
 * 2. The second listen waits for input from 1 to 2, representing either to try again or close the program
 */
class UserInputListener {
public:
    /**
     * @brief Listens for the user's first input (1-3)
     * @return int Returns the user's choice for the first set of options
     */
    int listenInitialInput();

    /**
     * @brief Listens for the user's second input (1-2)
     * @return int Returns the user's choice for the second set of options
     */
    int listenRetryOrExit();
};

#endif // USERINPUTLISTENER_H
