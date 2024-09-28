#include "RobotInputListener.h"

std::string RobotInputListener::listenRobotCommands() {
    std::string input;
    std::string line;
    char terminationChar = '\0';  // To hold the termination character

    std::cout << "Enter robot commands (terminate with ';' or '.'): " << std::endl;

    while (true) {
        std::getline(std::cin, line);

        if (!line.empty() && (line.back() == ';' || line.back() == '.')) {
            terminationChar = line.back();
            line.pop_back();
            input += line;
            break;
        } else {
            input += line + "\n";
        }
    }

    std::cout << "Input session terminated by '" << terminationChar << "'." << std::endl;
    return input;
}