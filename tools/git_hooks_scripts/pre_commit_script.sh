#!/bin/sh

git diff --cached --name-only --diff-filter=ACMRT |
grep -E -i ".*\.(h|hpp|c|cpp)$" |
xargs clang-format-6.0 -style=file -output-replacements-xml |
grep "<replacement " >/dev/null
if [ $? -ne 1 ]; then
	echo "Commit didn't pass clang-format check"
	echo "Please run scripts/apply_clang_format.sh for formatting (run from project dir)"
	echo "If you want to commit anyway use -n flag"
	exit 1
else
	echo "Clang-format check passed"
fi
