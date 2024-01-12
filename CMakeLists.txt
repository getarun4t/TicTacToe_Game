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

# Get a list of all .cpp files in the src directory
file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Get a list of all .cpp files in the tests directory
file(GLOB TEST_FILES ${CMAKE_SOURCE_DIR}/tests/*.cpp)

# Add the source files
add_executable(TicTacToe ${SRC_FILES})
add_executable(MyGTests ${TEST_FILES})

# Link the test executable with Google Test libraries
target_link_libraries(
	MyGTests 
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(MyGTests)
