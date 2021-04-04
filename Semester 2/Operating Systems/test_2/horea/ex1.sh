#!/bin/bash

# 1. Write a bash script that calculates the sum of the sizes (in bytes) of all regular files in a folder given as 
# a parameter.(use test to check if the folder exists and if a given file is a regular file)

D=$1

if [ ! -d "$D" ]; then
	echo "Directory doesn't exist"
else
	find $D -type f |  { while read F
	do
		N=`ls -l $F | awk '{print $5}'`
		sum=`expr $sum + $N`
	done
	echo The sum of sizes is $sum 
}
fi


