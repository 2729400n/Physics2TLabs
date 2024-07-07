#!/bin/bash

# A set of examples demonstrating for loops

# Loop over some values and print them out
for value in "this" "will" "echo" "lots" "of" "values" "this has spaces"
do
    echo $value
done


# Loop through all the files in the working directory
for file in *
do
    # Check if the file is a directory
    if [[ -d $file ]]; then
        echo "$file is a directory."

    # Check if it's a regular file
    elif [[ -f $file ]]; then
        echo "$file is a regular file."

    # It's neither of the above
    else
        echo "$file isn't a file or directory. What is it?!"
    fi
done


# Loop through all the scripts in the working directory
for file in *.sh
do
    # Print some information about the file
    ls -l $file
done
# (This example is the same as running ls -l *.sh)


# {0..10} gets expanded to 0 1 2 3 4 5 6 7 8 9 10
for i in {0..10}
do
    echo "${i}..."
done

# Same as above, except in steps of 2
# You can stick "do" on the same line as the loop declaration by using a semicolon
for i in {0..10..2}; do
    echo "${i}..."
done

exit 0
