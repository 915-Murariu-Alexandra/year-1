#!/bin/bash

# 3. Write a script that receives as command line arguments pairs consisting of a filename and a word. For each 
# pair, check if the given word appears at least 3 times in the file and print a corresponding message.

if [ $# -lt 2 ]; then
	echo Please provide at least 2 arguments
else	
	
	while [ "$1" != "stop" ]
	do
		echo Testing $1 for word $2:
		awk -v w=$2 'BEGIN{n=0;}{for(i=1;i<=NF;i++){if($i==w){n++;}}}END{if(n>=3){print "The word appears at least 3 times"}else{print "The word does not appear at least 3 times"}}' $1
		shift 2
	done
fi

