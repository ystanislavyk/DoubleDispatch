#!/usr/bin/env bash

### Functions
function compiler_name_conversion() {
    readonly COMPILER_NAME=$1

    if [[ ${COMPILER_NAME} == "gcc" ]]; then
        echo "g++"
    elif [[ ${COMPILER_NAME}  == "clang" ]]; then
        echo "clang++"
    else
        echo "g++"
    fi
}

### Constants
readonly COMPILER=$1
readonly BUILD_TYPE=$2
readonly BUILD_DIR=build-${COMPILER}-`echo ${BUILD_TYPE} | tr '[:upper:]' '[:lower:]'`
readonly ARGUMENTS="../../ -DCMAKE_CXX_COMPILER=$(compiler_name_conversion $1) -DCMAKE_BUILD_TYPE=${BUILD_TYPE}"

########################################################################################################################

if [[ "$#" -ne 2 ]]; then
    echo "Invalid number of arguments"
    exit
fi

mkdir ${BUILD_DIR} && cd $BUILD_DIR && cmake ${ARGUMENTS} && make -j${nproc}
