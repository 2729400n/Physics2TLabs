#!/bin/bash

# A set of examples demonstrating conditionals

# Check for a file called "hello"
if [[ -f hello ]]; then
    echo "File called \"hello\" found"
fi  


# Test whether a string contains text
STRING="Physics 2T"
if [[ -n "$STRING" ]]; then
    echo $STRING
else
    echo "STRING is empty"
fi


# Simple arithmetic comparisons
# Does 1 = 2?
if [[ 1 -eq 2 ]]; then
    echo "Somewhat surprisingly, one equals two"

# Does 1 = 3? (yes, you can include comments here)
elif [[ 1 -eq 3 ]]; then
    echo "Something weird is going on with my maths..."

# None of the above tests were true
else
    echo "One does not equal either two or three (good!)"
fi


# Combining tests
# Check for a file which is a directory and which is also readable
DIRECTORY="answers"
if [[ -d $DIRECTORY && -r $DIRECTORY ]]; then
    echo "You can read all of the answers"
else
    echo "I'm afraid you can't read all of the answers"
fi

exit 0
