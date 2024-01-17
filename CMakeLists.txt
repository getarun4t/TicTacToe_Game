cmake_minimum_required(VERSION 3.25)
project(TicTacToe)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add the include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Define source files for the main executable
set(SRC_FILES 
    ${CMAKE_SOURCE_DIR}/src/play.cpp
    ${CMAKE_SOURCE_DIR}/src/player.cpp
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)

# Define source files for the test executable
set(TEST_FILES 
    ${CMAKE_SOURCE_DIR}/tests/MyTests.cpp
    ${CMAKE_SOURCE_DIR}/src/play.cpp
    ${CMAKE_SOURCE_DIR}/src/player.cpp  # Add player.cpp to the test executable
)

# Define the main executable
add_executable(TicTacToe ${SRC_FILES})

# Define the test executable
add_executable(MyGTests ${TEST_FILES})

# Link the main executable with Google Test libraries
target_link_libraries(TicTacToe gtest_main)

# Link the test executable with Google Test libraries
target_link_libraries(my_executable gtest_main)
target_link_libraries(
    MyGTests 
    GTest::gtest_main
    gtest
)

include(GoogleTest)
gtest_discover_tests(MyGTests)
