# Copyright (c) 2018, Carlos Gomes Martinho
# SPDX-License-Identifier:	BSL-1.0

# This script finds files (C/C++ & Proto) in the subdirectories and checks if the format is correct 
# Needs a .clang-format file somewhere in the current of parent directory
# Returns 1 if there is at least one file that is not well formatted

FAILED=0
echo "Script name: $0"
work_dir=$(pwd) 
echo "Working directory is: $work_dir"
echo ""
echo ""

for i in `
find "$work_dir"/ \
    -not \( -path "*/build/*" -prune \) \
    -not \( -path "*/_build/*" -prune \) \
    -not \( -path "*/cmake/*" -prune \) \
    -not \( -path "*/config/*" -prune \) \
    -not \( -path "*/scripts/*" -prune \) \
    -not \( -path "*/.vscode/*" -prune \) \
    -not \( -path "*/third_party/*" -prune \) \
    -not \( -path "*/www/*" -prune \) \
    -not \( -path "*/doc/*" -prune \) \
    \( -name *.h -o -name *.hpp -o -name *.c -o -name *.cc -o -name *.cpp -o -name *.proto \)`
do
	clang-format -style=file -output-replacements-xml "$i" | grep "<replacement " >/dev/null &&
    {
      echo "$i is not correctly formatted"
	  FAILED=1
	}
done
if [ "$FAILED" -eq "1" ] ; then exit 1 ; fi
