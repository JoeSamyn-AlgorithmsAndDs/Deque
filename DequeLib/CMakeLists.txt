# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.16.0)

# Set executable output directory variable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/DequeLib/bin/${CMAKE_BUILD_TYPE})

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

# Set output directories
set_target_properties(deque PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${LIB}
        LIBRARY_OUTPUT_DIRECTORY ${LIB})
