# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.16.0)

# Set the project properties
project(Deque LANGUAGES CXX VERSION 1.0 DESCRIPTION "Deque implementation in C++")

# Add executable targets to be built by CMake
add_executable(deque src/main.cpp)

# CMake page 25