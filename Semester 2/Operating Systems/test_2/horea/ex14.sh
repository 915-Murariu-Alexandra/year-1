#!/bin/bash

# 14. Write a shell script that recieves any number of words as command line arguments, and continuously reads 
# from the keyboard one file name at a time. The program ends when all words received as parameters have been 
# found at least once across the given files.
declare -A arr
declare -i n
read F
n=0
for word in $*
do
	arr[$word]=0
done
while true
do	
	for word in ${!arr[@]}
	do	
		if grep -q -c "$word" "$F"; then
			if [[ 0 -eq ${arr[$word]} ]]; then
				 n=$((n+1))
				 arr[$word]=1
			fi
		fi
	done
	
	if [ $n -eq $# ]; then
		exit 1
	fi
	read F
done
