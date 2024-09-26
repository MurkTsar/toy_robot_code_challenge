#ifndef USERINPUTEXECUTOR_H
#define USERINPUTEXECUTOR_H

#include <string>

/**
 * @class UserInputExecutor
 * @brief Executes user commands such as importing files or inputting robot actions.
 */
class UserInputExecutor {
public:
    /**
     * @brief Executes file import for robot actions
     * @param filePath The path to the moveset file
     */
    void importFile(const std::string& filePath) const;

    /**
     * @brief Executes manual input of robot actions
     * @param robotActions A string containing the actions to be performed by the robot
     */
    void inputRobotActions(const std::string& robotActions) const;

    /**
     * @brief Exits the program
     */
    [[noreturn]] void exitProgram() const;
};

#endif // USERINPUTEXECUTOR_H
