cmake_minimum_required(VERSION 3.10)

# project name
project(toy_robot)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# gtest path
add_subdirectory(lib/googletest)  # Assuming you cloned gtest into the lib directory

# main program
add_executable(${PROJECT_NAME} 
    src/main.cpp 
    src/tabletop.cpp 
    src/robot.cpp 
    src/commandlinedisplay.cpp 
    #src/userinputlistener.cpp 
    src/userinputexecutor.cpp 
    src/movesetparser.cpp 
)

# directories
target_include_directories(${PROJECT_NAME} 
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

# enables testing
# enable_testing()

# Optionally add compiler flags
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

# Add pthread if on a system where it's required (shouldn't be on Windows)
if (UNIX)
    find_package(Threads REQUIRED)
    target_link_libraries(${PROJECT_NAME} Threads::Threads)
endif()