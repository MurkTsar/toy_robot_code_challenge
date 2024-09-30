#include "ToyRobotProgram.h"

ToyRobotProgram& ToyRobotProgram::getInstance() {
    static ToyRobotProgram instance;
    return instance;
}

ToyRobotProgram::ToyRobotProgram() {
    LOG_ACTION("ToyRobotProgram created");
}

ToyRobotProgram::~ToyRobotProgram() {
    LOG_ACTION("ToyRobotProgram destroyed");
}

void ToyRobotProgram::run(int argc, char* argv[])
{
    CommandExecutor executor;
    MovesetParser moveParser;
    TableTop squareTable = TableTop(5,5);

    if (argc == 1) {
        simpleUI(executor, moveParser, squareTable);
    } else if (argc == 3 && std::string(argv[1]) == "-f") {
        std::string filePath = argv[2];
        std::optional<std::list<std::string>> setOfMoves = moveParser.parseCommandsFromFile(filePath);
        
        if (setOfMoves.has_value()) {
            CommandLineDisplay::displayMoveset(setOfMoves.value());
            executor.execute(setOfMoves.value(), squareTable);
        } else {
            std::cerr << "Error: Could not parse commands from file." << std::endl;
            return;
        }
    } else if (argc == 3 && std::string(argv[1]) == "-m") {
        std::string moveString = argv[2];
        std::optional<std::list<std::string>> setOfMoves = moveParser.parseCommands(moveString);

        if (setOfMoves.has_value()) {
            CommandLineDisplay::displayMoveset(setOfMoves.value());
            executor.execute(setOfMoves.value(), squareTable);
        } else {
            std::cerr << "Error: Could not parse commands from string." << std::endl;
            return;
        }
    } else if (argc == 2 && std::string(argv[1]) == "-h") {
        CommandLineDisplay::displayCommandLineMenu();
    }
}

void ToyRobotProgram::simpleUI(CommandExecutor& executor, MovesetParser& moveParser, TableTop& aTable){
    bool running = true;
    bool successOp = false;
    int mainmenuInput = 0;
    int tryagainInput = 0;
    UserInputListener userListener;
    InputFileListener fileListener;
    
    while(running){
        CommandLineDisplay::displayWelcome();
        mainmenuInput = userListener.listenInitialInput();

        switch (mainmenuInput)
        {
        case 1:
            if(fileReadProcess(executor,moveParser,aTable)){
                successOp = true;
            }
            break;
        case 2:
            if(inputReadProcess(executor,moveParser,aTable)){
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
            CommandLineDisplay::clearScreen();
            continue;
        }

        tryagainInput = userListener.listenRetryOrExit();

        if (running && tryagainInput == 1) {
            mainmenuInput = 0;
            (void)aTable.removeRobot();
            successOp = false;
            CommandLineDisplay::clearScreen();
        } else if (tryagainInput == 2) {
            running = false;
        }
    }
    
    CommandLineDisplay::displayGoodbye();
}

bool ToyRobotProgram::fileReadProcess(CommandExecutor& executor, MovesetParser& moveParser, TableTop& aTable)
{
    std::optional<std::list<std::string>> setOfMoves;
    std::string stringOfMoves;
    std::optional<std::string> filePath;
    InputFileListener fileListener;

    filePath = fileListener.listenForFilePath();
    if(filePath.has_value()){
        setOfMoves = moveParser.parseCommandsFromFile(filePath.value());
        
        if (setOfMoves.has_value()){
            CommandLineDisplay::displayMoveset(setOfMoves.value());
            executor.execute(setOfMoves.value(), aTable);
        } else {
            return false;
        }
    } else {
        return false;
    }

    return true;
}

bool ToyRobotProgram::inputReadProcess(CommandExecutor& executor, MovesetParser& moveParser, TableTop& aTable)
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