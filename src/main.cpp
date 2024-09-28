#include <iostream>
#include "ToyRobotProgram.h"

int main() {
    Logger::getInstance();
    ToyRobotProgram::getInstance().run();
    Logger::getInstance().stopLogger();
    ToyRobotProgram::getInstance().stop();
    return 0;
}