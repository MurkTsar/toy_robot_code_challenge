cmake_minimum_required(VERSION 3.10)

# project name
project(ToyRobot)

# C++ standard
set(CMAKE_CXX_STANDARD 11)

# directories
include_directories(include)

# gtest path
add_subdirectory(lib/googletest)  # Assuming you cloned gtest into the lib directory

# main program
add_executable(toy_robot src/main.cpp)

# enables testing
# enable_testing()