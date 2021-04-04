#!/bin/bash

# 2. Afisati numele fisierelor dintr-un director dat ca parametru care contin numere de peste 5 cifre.

D=$1

find $D -type f -name "*.txt" | while read F
do
	N=`grep -c ".*[0-9]\{5,\}.*" $F`
	if [ $N -ne 0 ]; then
		echo $F
	fi
done


