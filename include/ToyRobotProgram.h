#ifndef TOYROBOTPROGRAM_H
#define TOYROBOTPROGRAM_H

#include <iostream>

class ToyRobotProgram {
public:
    static ToyRobotProgram& getInstance();
    
    void run();
    void stop();
    
private:
    ToyRobotProgram();
    ~ToyRobotProgram();

    ToyRobotProgram(const ToyRobotProgram&) = delete;
    ToyRobotProgram& operator=(const ToyRobotProgram&) = delete;
};

#endif // TOYROBOTPROGRAM_H
