#!/bin/bash

file=$1

grep -o "this" $file
while read line
do
	echo Line is: $line
	echo Word by word:
	for w in $line
	do
		if [ $w = "this" ]
		then
			echo $w
		fi
	done
done < $file
