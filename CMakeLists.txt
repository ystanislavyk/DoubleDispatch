cmake_minimum_required(VERSION 3.5)

include(CTest)

project(DoubleDispatch VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(submodules/gtest)

set(SRC_LIST "src/DBConnection.cpp" 
             "test/TypeConversionTest.cpp")

add_executable(testrunner ${SRC_LIST})

target_include_directories(testrunner PRIVATE src)
target_compile_options(testrunner PRIVATE -Wextra -pedantic)
target_link_libraries(testrunner PRIVATE gtest gtest_main)

add_test(NAME TypeConversionTest COMMAND testrunner)









