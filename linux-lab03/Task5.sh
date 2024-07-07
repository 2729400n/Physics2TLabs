#!/bin/bash 

for i in ./data/*.data ; do
    if [[ ! -f $i.bak ]] ;then
        cp $i $i.bak
    fi
done    