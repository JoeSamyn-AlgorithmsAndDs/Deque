# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.16.0)

# Set the CMAKE Executable/Lib output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

# Set the project properties
project(Deque LANGUAGES CXX VERSION 1.0 DESCRIPTION "Deque implementation in C++.")

# Add public header output path variable
set(HDIR ${CMAKE_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME})

# Set compiled lib output path variable
set(LIB ${CMAKE_SOURCE_DIR}/lib/${CMAKE_PROJECT_NAME})

# Set variable for public header files
set(HFILES src/deque_a.h
           src/deque_ll.h)

# Set source files
set(SRCS src/deque_a.cpp 
         src/deque_ll.cpp)

# Add executable targets to be built by CMake
add_library(deque ${SRCS} ${HFILES})

# install the public header files in the public include directory
install(FILES ${HFILES} DESTINATION ${HDIR})


# insall public headers and lib files in proper location for distribution
install(TARGETS deque
        LIBRARY DESTINATION ${LIB}
        ARCHIVE DESTINATION ${LIB})
