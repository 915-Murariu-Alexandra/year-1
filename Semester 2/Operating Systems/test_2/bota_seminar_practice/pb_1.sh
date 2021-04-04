#!/bin/bash

# 1. CalculaČ›i numÄrul mediu de linii ale fiČ™ierelor de tip text dintr-un director dat ca parametru.
# (comenzi: find, file, wc)

D=$1
S=0
NR_FILES=0

find $D -type f -name "*.txt" | { while read F
do
	N=`wc -l $F | awk '{print $1}'`
	S=`expr $S + $N`
	NR_FILES=`expr $NR_FILES + 1`
done
echo `expr $S / $NR_FILES`
}
