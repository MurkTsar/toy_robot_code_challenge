#ifndef INPUTFILELISTENER_H
#define INPUTFILELISTENER_H

#include <string>
#include <optional>

/**
 * @class InputFileListener
 * @brief Listens for file path and file name input from the user
 *
 * The InputFileListener class provides a method to listen for user input,
 * specifically the file path and name of a robot move set file. The listener
 * will terminate upon receiving an "Enter" key.
 */
class InputFileListener {
public:
    InputFileListener();
    ~InputFileListener();

    /**
     * @brief Listen for input, expecting a file path and file name
     * @return std::optional<std::string> Returns a valid file path if provided, or std::nullopt if terminated
     */
    std::optional<std::string> listenForFilePath();

private:
    /**
     * @brief Helper function to clean up and validate the input file path
     * @param filePath The input file path
     * @return std::string The cleaned-up file path
     */
    std::string cleanUpFilePath(const std::string& filePath);

    /**
     * @brief Helper function to check if file exists
     * @param filePath The path of the file
     * @return bool True if the file exists, false otherwise
     */
    bool fileExists(const std::string& filePath) const;
};

#endif // INPUTFILELISTENER_H
