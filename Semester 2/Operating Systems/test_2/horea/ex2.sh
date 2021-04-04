#!/bin/bash
# 2. Write a script that reads filenames until the word "stop" is entered. For each filename, check if it is a 
# text file and if it is, print the number of words on the first line.(Hint: test command to check if regular file; 
# file command to check if text file)

read file_name

while [ "$file_name" != "stop" ]
do
	if test -f $file_name; then
		sed -n '1p' $file_name | wc -w
	fi
	read file_name
done
