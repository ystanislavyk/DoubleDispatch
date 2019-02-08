[![Build Status](https://travis-ci.org/Morheit/DoubleDispatch.svg?branch=master)](https://travis-ci.org/Morheit/DoubleDispatch)

# DoubleDispatch #

## Problem ##

There is an interface with some count of the implementations. Need to use these implementations through the interface with 
one limitation - without [RTTI](https://en.wikibooks.org/wiki/C%2B%2B_Programming/RTTI) mechanism in the "release".

In this repository considered a three ways of solving such case using `static_cast` and the
[Double Dispatch](https://en.wikipedia.org/wiki/Double_dispatch) pattern in particular.

## Platform ##

* Linux (Ubuntu is pref)
* macOS

## System Requirements ##

**macOS**

To build for macOS, you need [Xcode](https://developer.apple.com/xcode/downloads/).
You will also need [CMake](https://cmake.org/) and [Conan](https://conan.io).

[**Homebrew**](https://brew.sh/)

```
brew install cmake conan
```

**Linux**

For Ubuntu, you'll need the following dependencies:

```
sudo apt-get install g++ cmake clang clang-format clang-tidy libclang-dev python-pip conan 
```

## Build ##

### Build commands ###

By default used **GCC** compiler and **Debug** mode. **Clang** is also supported

Run one of the following commands to build project

`make` or `make gcc-debug` -  build project with **GCC** in **Debug** mode

`make gcc-release` - build project with **GCC** in **Release** mode

`make clang-debug` - build project with **Clang** in **Debug** mode

`make clang-release` - build project with **Clang** in **Release** mode

`make all` - build project with **GCC** and **Clang** in **Debug** and **Release** modes

`make clean` - removes the build folder

## Run ##

Run from build directory

`ctest`

or

`ctest AllTests`
