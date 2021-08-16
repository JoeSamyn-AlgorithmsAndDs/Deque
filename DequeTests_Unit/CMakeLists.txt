# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.16.0)

# set binary variable used to build test project
set(BINARY ${CMAKE_PROJECT_NAME}_test)

# set target name
project(${BINARY} LANGUAGES CXX)

# set source files 
set(SOURCES src/dequea-test.cpp)

# add executable for test project
add_executable(${BINARY} ${SOURCES})

add_subdirectory(lib/Catch2)

# link gtest libraries
target_link_libraries(${BINARY} PRIVATE deque Catch2::Catch2WithMain)

# include header files 
target_include_directories(${BINARY} PRIVATE ${CMAKE_SOURCE_DIR}/DequeLib/src)

# append Catch2 scripts for automatically finding unit tests to CMAKE Module path
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/Catch2/extras) 

# include cmake test, Catch scripts
include(CTest)
include(Catch)

# tell catch to automatically discover tests and report using the console method
catch_discover_tests(${BINARY} REPORTER console)