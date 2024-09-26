#include "logger.h"
#include <iostream>
#include <ctime>

Logger::Logger() {}

Logger::~Logger() {
    saveToFile();
}

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::log(const std::string& function, const std::string& message) {
    time_t now = time(0);
    
    char timeBuffer[26];
    ctime_s(timeBuffer, sizeof(timeBuffer), &now);
    
    std::string logEntry = function + " | " + message + " | " + timeBuffer;
    
    logs.push_back(logEntry);
    
    if (logs.size() >= maxLogSize) {
        saveToFile();
        logs.clear();
    }
}

void Logger::saveToFile() {
    std::ofstream outFile("robot.log", std::ios::app);
    if (outFile.is_open()) {
        for (const auto& log : logs) {
            outFile << log << std::endl;
        }
    }
    outFile.close();
}
