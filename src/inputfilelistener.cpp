#include "inputfilelistener.h"
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <cctype>

InputFileListener::InputFileListener() {}

InputFileListener::~InputFileListener() {}

std::optional<std::string> InputFileListener::listenForFilePath() {
    std::string filePath;

    std::cout << "Enter the file path and file name containing the robot move sets (or press Enter to terminate): ";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::getline(std::cin, filePath);

    if (filePath.empty()) {
        return std::nullopt;
    }

    filePath = cleanUpFilePath(filePath);

    if (fileExists(filePath)) {
        return filePath;
    } else {
        std::cerr << "Error: File does not exist at path: " << filePath << std::endl;
        return std::nullopt;
    }
}

std::string InputFileListener::cleanUpFilePath(const std::string& filePath) {
    std::string cleanedPath = filePath;

    cleanedPath.erase(cleanedPath.begin(), std::find_if(cleanedPath.begin(), cleanedPath.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    cleanedPath.erase(std::find_if(cleanedPath.rbegin(), cleanedPath.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), cleanedPath.end());

    return cleanedPath;
}

bool InputFileListener::fileExists(const std::string& filePath) const {
    return std::filesystem::exists(filePath);
}
