#!/bin/bash

# 3. Write a shell script that it will continously monitor a directory and it will display a message on the 
# screen if for any of the existing files in that directory there was added a word that start and ends with a 
# vowel (will be considered only files from the first level).
D=$1
if [ -z "$D" ]; then
	echo "No directory provided for monitoring"
	exit 1
fi

if [ ! -d "$D" ]; then
	echo "This directory does not exist"
	exit 1
fi
declare -i WC
declare -i nr
declare -i lenS
declare -i lenSTATE
declare S
declare STATE
while true {
do
	nr=$((nr+1))
	lenS=0
	while read P
	do
		if [ -f $P ]; then
			if !(grep -q -c ".swp" "$P"); then
				WC=`grep -o '\b[aeiou].*[aeiou]\b' $P | wc -w`
			fi
		fi
		lenS=$((lenS+WC))
	done <<< "$(find $D)"
	if [ $nr -ge 3 ] && [ $lenS -ne $lenSTATE ]; then
		echo "---------------------A word was added"
	else
		echo "No new words were added"
	fi
	lenSTATE=$lenS
	sleep 5
done
}
