#include <iostream>
#include "ToyRobotProgram.h"

int main(int argc, char* argv[]) {
    Logger::getInstance();
    ToyRobotProgram::getInstance().run(argc,argv);
    Logger::getInstance().stopLogger();
    ToyRobotProgram::getInstance().stop();
    return 0;
}