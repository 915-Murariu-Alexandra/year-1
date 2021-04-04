#!/bin/bash

# 12. Write a script that finds recursively in the current folder and displays all the regular files that have 
# write permisions for everybody (owner, group, other). Then the script removes the write permissions from 
# everybody. Hint: use chmod's symbolic permissions mode (see the manual).

find . -type f | { while read F
do
	if ls -l "$F" | grep -q -c "^-r..r..r.x"; then
		echo $F
		chmod o-r $F
	fi
done
}
