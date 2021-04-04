#!/bin/bash

# 1. Write a script shell that gets as an input (arguments) 3 directories followed by a list of files. The script 
# will copy the files that contain at least 10 lines with more than 5 words in directory 1, 
# and the files that contain at least 10 lines with less than 5 words in directory 2. For the files that do not 
# match any criteria, it will move them to directory 3.

if [ $# -le 3 ]; then
	echo "Not enough arguments were given"

elif [ ! -d $1 ]; then
	echo "Not a directory"
elif [ ! -d $2 ]; then
	echo "Not a directory"
elif [ ! -d $3 ]; then
	echo "Not a directory"
else
	shift 3
	for file in $*
	do
		n=`wc -l $file | awk '{print $1}'`
		if [ $n -le 10 ]; then
			mv $file ./dir3/$file
		else
			nr_words=`wc -w $file | awk '{print $1}'`
			if [ $nr_words -le 5 ]; then
				mv $file ./dir2/$file
			else
				mv $file ./dir1/$file
			fi
		fi
	done
fi
