#!/bin/bash

if [[ "$OSTYPE" == "linux-gnu" ]]; then
    find -name "*.h" -o -name "*.hpp" -o -name "*.c" -o -name "*.cpp" |
    xargs clang-format-6.0 -style=file -output-replacements-xml
elif [[ "$OSTYPE" == "darwin"* ]]; then
    find . -name "*.h" -o -name "*.hpp" -o -name "*.c" -o -name "*.cpp" |
    xargs clang-format -style=file -output-replacements-xml
fi

grep "<replacement " >/dev/null
if [ $? -ne 1 ]; then
	echo "Commit didn't pass clang-format check"
	echo "Please run scripts/apply_clang_format.sh for formatting (run from project dir)"
	exit 1
fi

exit
