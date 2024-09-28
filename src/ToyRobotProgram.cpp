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
    bool running = true;
    bool successOp = false;
    int mainmenuInput = 0;
    int tryagainInput = 0;
    UserInputListener userListener;
    CommandExecutor executor;
    InputFileListener fileListener;
    MovesetParser moveParser;
    TableTop squareTable = TableTop(5,5);

    while(running){
        mainmenuInput = userListener.listenInitialInput();

        switch (mainmenuInput)
        {
        case 1:
            if(filePath(executor,moveParser,squareTable)){
                successOp = true;
            }
            break;
        case 2:
            if(inputPath(executor,moveParser,squareTable)){
                successOp = true;
            }
            break;
        case 3:
            running = false;
            break;
        
        default:
            break;
        }

        if(!successOp){
            continue;
        }

        tryagainInput = userListener.listenRetryOrExit();

        if (running && tryagainInput == 1) {
            mainmenuInput = 0;
            (void)squareTable.removeRobot();
            successOp = false;
        } else if (tryagainInput == 2) {
            running = false;
        }
    }
}

bool ToyRobotProgram::filePath(CommandExecutor& executor, MovesetParser& moveParser, TableTop& aTable)
{
    std::optional<std::list<std::string>> setOfMoves;
    std::string stringOfMoves;
    std::optional<std::string> filePath;
    InputFileListener fileListener;

    filePath = fileListener.listenForFilePath();
    if(filePath.has_value()){
        setOfMoves = moveParser.parseCommandsFromFile(filePath.value());
        
        if (setOfMoves.has_value()){
            executor.execute(setOfMoves.value(), aTable);
        } else {
            return false;
        }
    } else {
        return false;
    }

    return true;
}

bool ToyRobotProgram::inputPath(CommandExecutor& executor, MovesetParser& moveParser, TableTop& aTable)
{
    std::optional<std::list<std::string>> setOfMoves;
    std::string stringOfMoves;
    std::optional<std::string> filePath;
    RobotInputListener robotListener;

    stringOfMoves = robotListener.listenRobotCommands();
    if(!stringOfMoves.empty()){
        setOfMoves = moveParser.parseCommands(stringOfMoves);

        if (setOfMoves.has_value()){
            executor.execute(setOfMoves.value(), aTable);
        } else {
            return false;
        }
    } else {
        return false;
    }

    return true;
}

void ToyRobotProgram::stop()
{

}