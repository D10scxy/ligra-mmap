#!/bin/bash

# cd apps && make TestAll
BFS_RT=0
SUFFIX=_dump

YM=/home/cxy/ligra-mmap/inputs/rMatGraph_J_5_100

for data in $YM
do
    echo "Data: $data"
    echo "-------original version---------"
    ./apps/TestAll -r $BFS_RT $data
    wait
    echo "---------mmap version-----------"
    ./apps/TestAll -map -r $BFS_RT "$data$SUFFIX"
    wait
done