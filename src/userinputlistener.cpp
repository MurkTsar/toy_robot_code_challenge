#include "userinputlistener.h"
#include "commandlinedisplay.h"

/**
 * @brief Listens for the user's first input (1-3).
 * Valid options: 1 - IMPORT FILE, 2 - INPUT ROBOT ACTIONS, 3 - CLOSE PROGRAM.
 * @return int Returns the user's choice for the first set of options.
 */
int UserInputListener::listenInitialInput() {
    char choice = '\0';  // Use char to take one character as input

    while (true) {
        CommandLineDisplay::displayMainMenu();
        std::cin >> choice;

        if (choice >= '1' && choice <= '3') {
            return choice - '0';
        } else {
            std::cout << "Invalid input. Please enter a number between 1 and 3.\n";
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int UserInputListener::listenRetryOrExit() {
    char choice = '\0';  // Use char to take one character as input

    while (true) {
        CommandLineDisplay::displayRetryMenu();
        std::cin >> choice;

        // Check if the input is '1' or '2'
        if (choice == '1' || choice == '2') {
            return choice - '0';  // Convert char to int (e.g., '1' -> 1)
        } else {
            std::cout << "Invalid input. Please enter 1 or 2.\n";
        }

        // Clear any remaining input and reset the input stream
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}