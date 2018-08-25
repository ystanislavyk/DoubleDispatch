cmake_minimum_required(VERSION 3.5)

project(DoubleDispatch VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

# Manage dependencies

enable_testing()

# Finding Threads libs
find_package(Threads REQUIRED)

# Setting up Conan
if (NOT EXISTS "${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        message(STATUS "Setting up dependencies with Conan (Clang)")
        execute_process(COMMAND conan install ${CMAKE_CURRENT_LIST_DIR} --profile ${CMAKE_CURRENT_LIST_DIR}/tools/conan/profile-clang --build missing)
    elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        message(STATUS "Setting up dependencies with Conan (GCC)")
        execute_process(COMMAND conan install ${CMAKE_CURRENT_LIST_DIR} --profile ${CMAKE_CURRENT_LIST_DIR}/tools/conan/profile-gcc --build missing)
    else()
        set(CONAN_INSTALL_CMD "conan install .. <list-of-settings>")
        message(FATAL_ERROR "Dependencies are not configured. Install dependencies first, e.g. running in build dir: ${CONAN_INSTALL_CMD}")
    endif()
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include(CTest)

set(SRC_LIST
    "src/DBConnection.hpp"
    "src/DBConnection.cpp"
    "src/DBConnection2.hpp"
    "src/DBConnection2.cpp"
    "src/ConnectionDispatcher.hpp"
    "src/ConnectionDispatcher.cpp"
    "src/DBConnection3.hpp"
    "src/DBConnection3.cpp")

add_executable(testrunner
    "${SRC_LIST}"
    "test/ConnectionTest.cpp"
    "test/ConnectionTest2.cpp"
    "test/ConnectionTest3.cpp")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

target_include_directories(testrunner PRIVATE src test)

target_compile_options(testrunner PRIVATE -Wextra -pedantic -Werror)

target_link_libraries(testrunner PRIVATE ${CONAN_LIBS})

add_test(NAME AllTests COMMAND testrunner)
