#!/bin/bash 
for i in $@; do
    if [[  -d $i ]]; then
        echo "$i:  is a Directory File"
    elif [[  -f $i  ]] ;   then
        echo "$i:  is a regular File"
    elif [[ !  -e $i ]]; then
        echo "$i:  does not exist"
    fi
done    