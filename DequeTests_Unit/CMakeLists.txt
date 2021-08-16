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

# add cmake test
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/Catch2/extras) 
include(CTest)
include(Catch)
catch_discover_tests(${BINARY} REPORTER console)