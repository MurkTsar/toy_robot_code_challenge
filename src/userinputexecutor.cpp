#include "userinputexecutor.h"
#include <string>

void UserInputExecutor::importFile(const std::string& /*ilePath*/) const {}

void UserInputExecutor::inputRobotActions(const std::string& /*robotActions*/) const {}

[[noreturn]] void UserInputExecutor::exitProgram() const {
    std::exit(0);
}
