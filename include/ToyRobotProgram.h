#ifndef TOYROBOTPROGRAM_H
#define TOYROBOTPROGRAM_H

#include "commandlinedisplay.h"
#include "userinputlistener.h"
#include "commandexecutor.h"
#include "inputfilelistener.h"
#include "movesetparser.h"
#include "robotinputlistener.h"
#include "tabletop.h"
#include <iostream>

class ToyRobotProgram {
public:
    static ToyRobotProgram& getInstance();
    
    void run(int argc, char* argv[]);
    void stop();
    bool filePath(CommandExecutor& executor, MovesetParser& moveParser, TableTop& squareTable);
    bool inputPath(CommandExecutor& executor, MovesetParser& moveParser, TableTop& squareTable);
    
private:
    ToyRobotProgram();
    ~ToyRobotProgram();

    ToyRobotProgram(const ToyRobotProgram&) = delete;
    ToyRobotProgram& operator=(const ToyRobotProgram&) = delete;
};

#endif // TOYROBOTPROGRAM_H
