# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.16.0)

# Set the project properties
project(Deque LANGUAGES CXX VERSION 1.0 DESCRIPTION "Deque implementation in C++.")

# Enable unit test project to be added as target and built
enable_testing()

# include tst subdirectory and gtest subdirectory
add_subdirectory(DequeTests_Unit)
add_subdirectory(DequeLib)

