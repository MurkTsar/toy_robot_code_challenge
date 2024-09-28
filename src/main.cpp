#include <iostream>
#include "ToyRobotProgram.h"

int main() {
    std::cout << "Hello Robot!" << std::endl;
    ToyRobotProgram::getInstance().run();
    std::cout << "Goodbye Robot!" << std::endl;
    return 0;
}