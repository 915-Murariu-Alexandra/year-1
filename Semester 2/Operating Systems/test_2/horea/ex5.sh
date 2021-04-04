#!/bin/bash

# 5. Write a script that extracts from all the C source files given as command line arguments the included 
# libraries and saves them in a file.(use the file command to check if a file is a C source file)

for F in $*
do
	if file $F | grep -q -c ": C source";then
		grep "^#include" $F >> new_file.txt
	fi
done
