#!/bin/bash

# A set of examples demonstrating variables

echo "This script is called $0"
echo "It had $# parameter(s) passed."
echo "Its process ID is ${$}."
echo "The first parameter was $1"
echo "The eighth parameter was ${8}"
echo "My random number is ${RANDOM}."

animal="rabbit"
echo "The braces around ${animal} here are optional because the variable name is followed by spaces.  $animal works just as well."
echo "The braces around ${animal}s here are required, in order to separate the variabale name from the characters which follow.  Compare: $animals"


# Set the files variable to the output of "ls *.sh"
files=$(ls *.sh)

# Print all the files stored in the "files" variable
for script in $files
do
    echo $script
done


# NOTE: Important note on older syntax
#
# As discussed in the lab 3 script, there are several forms of syntax used for tests,
# including [ and [[.  We recommend [[ in P2T.

empty=""
if [[ $empty = "" ]]; then
    echo "This works"
fi

# The [ syntax is more fragile.  It's important that you always quote variables:

if [ "$empty" = "" ]; then
    echo "This works"
fi

# This will give an error because it will be evaluated as [ = "" ]
if [ $empty = "" ]; then
    echo "This doesn't work :("
fi

# Sticking to [[ makes life easier!  ;-)

exit 0
