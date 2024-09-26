#include "userinputlistener.h"

/**
 * @brief Listens for the user's first input (1-3).
 * Valid options: 1 - IMPORT FILE, 2 - INPUT ROBOT ACTIONS, 3 - CLOSE PROGRAM.
 * @return int Returns the user's choice for the first set of options.
 */
int UserInputListener::listenInitialInput() {
    int choice = 0;

    while (true) {
        std::cout << "Please choose an option:\n";
        std::cout << "1 - IMPORT FILE\n";
        std::cout << "2 - INPUT ROBOT ACTIONS\n";
        std::cout << "3 - CLOSE PROGRAM\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Validate input: Should be between 1 and 3
        if (choice >= 1 && choice <= 3) {
            break; // Valid input, break the loop
        } else {
            std::cout << "Invalid input. Please enter a number between 1 and 3.\n";
        }
    }

    return choice;
}

/**
 * @brief Listens for the user's second input (1-2).
 * Valid options: 1 - TRY AGAIN, 2 - CLOSE PROGRAM.
 * @return int Returns the user's choice for the second set of options.
 */
int UserInputListener::listenRetryOrExit() {
    int choice = 0;

    while (true) {
        std::cout << "Please choose an option:\n";
        std::cout << "1 - TRY AGAIN\n";
        std::cout << "2 - CLOSE PROGRAM\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Validate input: Should be either 1 or 2
        if (choice == 1 || choice == 2) {
            break; // Valid input, break the loop
        } else {
            std::cout << "Invalid input. Please enter 1 or 2.\n";
        }
    }

    return choice;
}
