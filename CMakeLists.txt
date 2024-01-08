cmake_minimum_required(VERSION 3.25)
project(TicTacToe)

# Set the path to the directory where you cloned Google Test
set(GTEST_ROOT "${CMAKE_SOURCE_DIR}/googletest/googletest")

# Include Google Test
include_directories(${GTEST_ROOT}/googletest/include)

# Add the include directory
include_directories(include)

# Get a list of all .cpp files in the src directory
file(GLOB SRC_FILES src/*.cpp)

# Add the source files
add_executable(MyProject ${SRC_FILES})

# Add the test executable
add_executable(MyTests tests/MyTests.cpp)

# Link the test executable with Google Test libraries
target_link_libraries(MyTests gtest gtest_main)
