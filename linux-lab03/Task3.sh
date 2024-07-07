#!/bin/bash 

RANDOMFILE="./random.txt"
echo "">$RANDOMFILE
for i in {0..100}; do
    echo $RANDOM >> $RANDOMFILE
done     