#!/bin/bash
LABDIR=`dirname $(readlink -f $0)`
echo $LABDIR

for i in data data/processed docs
    do
        mkdir $LABDIR;
done     