#!/bin/bash

# 2. Write a shell script that it will iterate over the homedirectories of the users existing in the system and 
# it will display on the screen for each one of them, their username and the sum of the file sizes found in it 
# (files needs to be searched recursively).
declare -i sum
find $D -type d | { while read D
do
	sum=0
	n=0
	find $D -type f | { while read F
	do
		n=`ls -l "$F" 2>/dev/null | awk '{print $5}' 2>/dev/null`
		sum=`expr $sum + $n`
	done
	echo $D has total sum $sum
	}
done
}
