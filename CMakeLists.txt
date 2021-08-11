# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.16.0)

# Set the CMAKE Executable/Lib output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

# Set the project properties
project(Deque LANGUAGES CXX VERSION 1.0 DESCRIPTION "Deque implementation in C++.")

# Set source files
set(SRC src/deque_a.cpp 
        src/deque_ll.cpp)

# Add executable targets to be built by CMake
add_library(deque src/main.cpp)

# CMake page 2