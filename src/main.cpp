#include <iostream>
#include "ToyRobotProgram.h"

int main() {
    ToyRobotProgram::getInstance().run();
    std::cout << "Goodbye Robot!" << std::endl;
    return 0;
}