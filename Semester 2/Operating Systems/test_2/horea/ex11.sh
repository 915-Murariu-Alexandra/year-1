#!/bin/bash

# 11. Write a script that receives a directory as a command line argument. The script will delete all the C source 
# files from the directory and will display all other text files sorted alphabetically.

find $1 -type f | { while read F
do
	if file "$F" | grep -q -c ": C source,"; then
		rm $F
	fi
done
ls -l | awk '{if(NF>2){print $NF}}' | sort
}
