cmake_minimum_required(VERSION 3.5)

project(DoubleDispatch VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

set(GTEST_MAIN_LIBRARY /usr/lib)

enable_testing()
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include(CTest)

set(SRC_LIST "src/DBConnection.cpp" "src/DBConnection.hpp")

add_executable(testrunner "${SRC_LIST}" test/ConnectionTest.cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

target_include_directories(testrunner PRIVATE src test)

target_compile_options(testrunner PRIVATE -Wextra -pedantic)

target_link_libraries(testrunner PRIVATE gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME TypeConversionTest COMMAND testrunner)
