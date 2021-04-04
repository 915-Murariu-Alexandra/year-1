#!/bin/bash

read file_name

while [ "$file_name" != "end" ] 
do
	if [ -f "$file_name" ]; then
		N=`sed -n '1p' $file_name | wc -w`
		echo The first line of the file has $N words
		SIZE_FILE=`ls -l $file_name | awk '{print $5}'`
		echo The size of the file is $SIZE_FILE
	else
		echo The file does not exist
	fi
	read file_name
done 
