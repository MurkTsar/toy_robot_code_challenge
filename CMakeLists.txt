cmake_minimum_required(VERSION 3.14)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project name
project(toy_robot VERSION 1.0)

# Include directories
include_directories(include)

# Source and header files for the main library
set(SOURCES
    src/tabletop.cpp
    src/stdRobot.cpp
    src/commandlinedisplay.cpp
    src/commandexecutor.cpp
    src/userinputlistener.cpp
    src/userinputexecutor.cpp
    src/movesetparser.cpp
    src/robotinputlistener.cpp
    src/logger.cpp
    src/ToyRobotProgram.cpp
    src/inputfilelistener.cpp
)

set(HEADERS
    include/iRobot.h
    include/tabletop.h
    include/stdRobot.h
    include/commandexecutor.h
    include/commandlinedisplay.h
    include/userinputlistener.h
    include/userinputexecutor.h
    include/movesetparser.h
    include/robotinputlistener.h
    include/logger.h
    include/position.h
    include/direction.h
    include/ToyRobotProgram.h
    include/inputfilelistener.h
)

# library for the ToyRobot
add_library(ToyRobot STATIC ${SOURCES} ${HEADERS})

# Include directories for the library
target_include_directories(ToyRobot
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# main executable
add_executable(ToyRobotApp src/main.cpp)

# Link ToyRobot library to main executable
target_link_libraries(ToyRobotApp ToyRobot)

# Compile unit tests
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE  # Suppress warning
)

# Force shared CRT for GoogleTest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Define source files for tests
set(TESTING
    tests/unit_tests/test_stdrobot.cpp
    tests/unit_tests/test_tabletop.cpp
    tests/unit_tests/test_commandexecutor.cpp
    tests/unit_tests/test_movesetparser.cpp
)

# Create the test executable
add_executable(UnitTests ${TESTING})

# Link GoogleTest and the ToyRobot library to the test executable
target_link_libraries(UnitTests gtest_main ToyRobot)

# Use GoogleTest's helper function to discover tests
include(GoogleTest)
gtest_discover_tests(UnitTests)
