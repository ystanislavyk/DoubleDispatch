#!/bin/bash

if [[ "$OSTYPE" == "linux-gnu" ]]; then
    find -name "*.h" -o -name "*.hpp" -o -name "*.c" -o -name "*.cpp" |
    xargs clang-format-6.0 -i
elif [[ "$OSTYPE" == "darwin"* ]]; then
    find . -name "*.h" -o -name "*.hpp" -o -name "*.c" -o -name "*.cpp" |
    xargs clang-format -i
fi

echo "Done"
