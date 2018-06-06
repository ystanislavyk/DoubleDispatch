cmake_minimum_required(VERSION 3.10)
project(DoubleDispatch)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wextra")

add_subdirectory(test/lib/googletest)
include_directories(test/lib/googletest/googletest/include)

add_executable(DoubleDispatch src/DBConnection.hpp src/DBConnection.cpp test/DispatchTest.cpp)

target_link_libraries(DoubleDispatch gtest gtest_main)