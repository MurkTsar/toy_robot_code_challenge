#include "ToyRobotProgram.h"

ToyRobotProgram& ToyRobotProgram::getInstance() {
    static ToyRobotProgram instance;
    return instance;
}

ToyRobotProgram::ToyRobotProgram() {
    std::cout << "ToyRobotProgram created" << std::endl;
}

ToyRobotProgram::~ToyRobotProgram() {
    std::cout << "ToyRobotProgram destroyed" << std::endl;
}

void ToyRobotProgram::run()
{

}

void ToyRobotProgram::stop()
{

}