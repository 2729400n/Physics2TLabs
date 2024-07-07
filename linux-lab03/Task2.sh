#!/bin/bash
LABDIR=`dirname $(readlink -f $0)`
echo $LABDIR

for i in data data/processed docs
    do
    if [[ ! -d "$LABDIR/$i" ]];then
        mkdir "$LABDIR/$i";
    fi    
done     