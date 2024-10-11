# Set the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Define the project name and specify C and C++ as required languages
project(MyProject VERSION 1.0 LANGUAGES C CXX)

# Add the first executable for main.c
add_executable(FirstCProgram main.c mem.c array_utils.c callback.c)

# Add the second executable for main.cpp
add_executable(FirstCPPProgram main.cpp fraction.cpp stack.cpp utils.cpp)