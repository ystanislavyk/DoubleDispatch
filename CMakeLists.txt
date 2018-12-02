cmake_minimum_required(VERSION 3.5)

project(DoubleDispatch VERSION 1.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

# Manage dependencies

enable_testing()

# Finding Threads libs
find_package(Threads REQUIRED)

# Setting up Conan
if (NOT EXISTS "${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
    message("Adding the bintray repository (bincrafters)")
    execute_process(COMMAND conan remote add bintray-bincrafters https://api.bintray.com/conan/bincrafters/public-conan)

    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        message(STATUS "Setting up dependencies with Conan (Clang)")
        execute_process(COMMAND conan install ${CMAKE_CURRENT_LIST_DIR} --profile ${CMAKE_CURRENT_LIST_DIR}/tools/conan/profile-clang --build missing)
    elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        message(STATUS "Setting up dependencies with Conan (GCC)")
        execute_process(COMMAND conan install ${CMAKE_CURRENT_LIST_DIR} --profile ${CMAKE_CURRENT_LIST_DIR}/tools/conan/profile-gcc --build missing)
    else()
        message(STATUS "Setting up dependencies with Conan (${CMAKE_CXX_COMPILER_ID})")
        execute_process(COMMAND conan install ${CMAKE_CURRENT_LIST_DIR} --build missing)
    endif()
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include(CTest)

set(SRC_LIST
    "src/Assertion/Assertion.hpp"
    "src/Assertion/Assertion.cpp"
    "src/DoubleDispatch/DoubleDispatch.hpp"
    "src/DoubleDispatch/DoubleDispatch.cpp"
    "src/DoubleDispatch/ConnectionDispatcher.hpp"
    "src/DoubleDispatch/ConnectionDispatcher.cpp"
    "src/TypeStoring/TypeStoring.hpp"
    "src/TypeStoring/TypeStoring.cpp")

add_executable(testrunner
    "${SRC_LIST}"
    "test/AssertionTest.cpp"
    "test/DoubleDispatchTest.cpp"
    "test/TypeStoringTest.cpp")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

target_include_directories(testrunner PRIVATE src test)

target_compile_options(testrunner PRIVATE -Wextra -pedantic -Werror)

target_link_libraries(testrunner PRIVATE ${CONAN_LIBS})

add_test(NAME AllTests COMMAND testrunner)
