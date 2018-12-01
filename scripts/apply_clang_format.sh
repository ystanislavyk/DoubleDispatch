#!/usr/bin/env bash

### Constants
readonly ARGUMENTS="-name "*.h" -o -name "*.hpp" -o -name "*.c" -o -name "*.cpp""

########################################################################################################################

if [[ "$OSTYPE" == "linux-gnu" ]]; then
    find ${ARGUMENTS} |
    xargs clang-format-6.0 -i
elif [[ "$OSTYPE" == "darwin"* ]]; then
    find . ${ARGUMENTS} |
    xargs clang-format -i
fi

echo "Clang format has been applied"
