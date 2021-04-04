#!/bin/bash

# 8. Write a bash script that receives a folder name as argument. Find recursively in the folder the number of 
# times each file name is repeated.

if [ $# -lt 1 ]; then
	echo Not enough arguments were given

elif [ ! -d "$1" ];then
	echo The directory does not exist
else
	find "$1" -type f | sed 's@.*/@@' | sort | uniq -c | sort -n
fi

