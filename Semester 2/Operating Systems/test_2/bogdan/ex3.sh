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
STATE=""
while true
do
	nr=$((nr+1))
	S=""
	find $D | while read P
	do
		if [ -f $P ]; then
			if !(grep -c ".swp" "$P"); then
				WC=`grep -o '\b[aeiou].*[aeiou]\b' $P | wc -w`
				echo wc for $P is $WC
			fi
		fi
		S="$S $WC"
		echo $P
		echo S is $S
	done
	len1=${#S}
	echo len1 is $len1
	len2=${#STATE}
	echo len2 is $len2
	if [ "$STATE" != "" ] && [ "$S" != "$STATE" ] && [ $nr -ge 4 ] && [ $len1 -eq $len2 ]; then
		echo S issssssss $S
		echo State issssssssss $STATE
		echo "A word was added"
	fi
	STATE=$S
	#echo state is $STATE
	sleep 5
done 
