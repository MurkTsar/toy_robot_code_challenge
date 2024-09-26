#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>
#include <fstream>

#define LOG_ACTION(msg) Logger::getInstance().log(__FUNCTION__, msg)

class Logger {
public:
    static Logger& getInstance();
    
    void log(const std::string& function, const std::string& message);
    
private:
    Logger();
    ~Logger();
    
    void saveToFile();

    std::vector<std::string> logs;
    const size_t maxLogSize = 50;
};

#endif // LOGGER_H
