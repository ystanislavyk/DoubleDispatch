# DoubleDispatch #

Example of use "Double Dispatch" pattern to avoid `static_cast` restrictions

## Platform ##

* Linux

## Requirements ##

* GNU-compatible Make
* POSIX-standard shell
* A C++11-standard-compliant compiler

## Build ##

### Build commands ###

By default used clang compiler and debug mode.

Run in project root to build debug version with clang

`mkdir build-clang-debug && cd build-clang-debug && cmake .. && make -j$(nproc)`

To build release version with gcc run the following command

`RUN mkdir build-gcc-release && cd build-gcc-release && cmake -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release .. && make -j$(nproc)`